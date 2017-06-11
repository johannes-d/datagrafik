#include "openglwindow.h"

#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

using namespace std;

OpenGLWindow::OpenGLWindow(QWindow *parent)
    : QWindow(parent)
    , context_(0)
    , device_(0)
{
    setSurfaceType(QWindow::OpenGLSurface);
}

OpenGLWindow::~OpenGLWindow()
{
    delete context_;
    delete device_;
}

void OpenGLWindow::display(QPainter *painter)
{
    Q_UNUSED(painter);
}

// Initialize OpenGL context and viewport.
void OpenGLWindow::initialize()
{
    context_ = new QOpenGLContext(this);

    context_->setFormat(requestedFormat());
    if (!context_->create()) {
        cerr << "Could not initialize OpenGL context." << endl;
        exit(EXIT_FAILURE);
    }

    context_->makeCurrent(this);

    initializeOpenGLFunctions();

    /* Set graphics attributes */
    glPointSize(5.0);
    glLineWidth(1.0);
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // To handle high DPI screens
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);
}

// Initialize OpenGL shader program
QOpenGLShaderProgram* OpenGLWindow::initProgram(QObject *parent, const QString &vShaderFile, const QString &fShaderFile) const
{
    // Create a shader program
    // Corresponds to the GL call glCreateProgram()
    QOpenGLShaderProgram *program = new QOpenGLShaderProgram(parent);

    // Load vertex shader
    if (!program->addShaderFromSourceFile(QOpenGLShader::Vertex, vShaderFile)) {
        cerr << "Failed to compile " << vShaderFile.toStdString() << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    // Load fragment shader
    if (!program->addShaderFromSourceFile(QOpenGLShader::Fragment, fShaderFile)) {
        cerr << "Failed to compile " << fShaderFile.toStdString() << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    // Link and error check
    if (!program->link()) {
        cerr << "Shader program failed to link:" << endl;
        cerr << program->log().toStdString() << endl;
        exit(EXIT_FAILURE);
    }

    return program;
}

// Render the scene.
void OpenGLWindow::display()
{
    if (!device_)
        device_ = new QOpenGLPaintDevice;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    device_->setSize(size());

    QPainter painter(device_);
    display(&painter);
}

// The window event handler
bool OpenGLWindow::event(QEvent *event)
{
    switch (event->type()) {
    case QEvent::Close:
        // Terminate application if window is closed
        qApp->quit();
    default:
        return QWindow::event(event);
    }
}

// Called when the window is exposed
void OpenGLWindow::exposeEvent(QExposeEvent *event)
{
    Q_UNUSED(event);

    if (isExposed())
        displayNow();
}

// Render the scene if the window is exposed (shown)
void OpenGLWindow::displayNow()
{
    if (!isExposed() || !context_)
        return;

    context_->makeCurrent(this);

    display();

    context_->swapBuffers(this);

}
