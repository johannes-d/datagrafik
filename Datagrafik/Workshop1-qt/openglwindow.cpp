#include "openglwindow.h"
using namespace std;

bool Opressed=false;
float Jcount = 0;
float Lcount = 0;
float Icount = 0;
float Kcount = 0;
float Leftcount = 0;
float Rightcount = 0;
float Ocount = 0;
float Upcount = 0;
float Downcount = 0;
float Wcount = 0;
float Acount = 0;
float Scount = 0;
float Dcount = 0;

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

void OpenGLWindow::reshape(int w, int h){
    glViewport(0, 0, w, h);
    displayNow();
}

bool OpenGLWindow::eventFilter(QEvent* event){
  char whatKey;
  float count;
  if (event->type()==QEvent::KeyPress){
    QKeyEvent* key=static_cast<QKeyEvent*>(event);
    switch (key->key()){

    case Qt::Key_O:
      whatKey='O';
      count=0;
      loadOBJ();
      break;

    case Qt::Key_J:
      whatKey='J';
      count=Jcount+1;
      break;
    case Qt::Key_K:
      whatKey='K';
      count=Kcount+1;
      break;
    case Qt::Key_L:
      whatKey='L';
      count=Lcount+1;
      break;
    case Qt::Key_I:
      whatKey='I';
      count=Icount+1;
      break;
    case Qt::Key_Up:
      whatKey='3';
      count=Upcount+1;
      break;
    case Qt::Key_Down:
      whatKey='4';
      count=Downcount+1;
      break;
    case Qt::Key_Left:
      whatKey='1';
      count=Leftcount+1;
      break;
    case Qt::Key_Right:
      whatKey='2';
      count=Rightcount+1;
      break;
    case Qt::Key_W:
      whatKey='W';
      count=Wcount+1;
      break;
    case Qt::Key_A:
      whatKey='A';
      count=Acount+1;
      break;
    case Qt::Key_S:
      whatKey='S';
      count=Scount+1;
      break;
    case Qt::Key_D:
      whatKey='D';
      count=Dcount+1;
      break;

    default:
      return false;
    }
  }
  loadModelMatrix(&whatKey, &count);
  return false;
}
// The window event handler
bool OpenGLWindow::event(QEvent *event){
    switch (event->type()) {
    case QEvent::Close:
        // Terminate application if window is closed
      qApp->quit();
    case QEvent::Resize:
      // Window resize event
      reshape(width(),height());
    case QEvent::KeyPress:
      eventFilter(event);

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
