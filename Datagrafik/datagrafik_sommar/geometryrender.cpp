#include "geometryrender.h"

GeometryRender::GeometryRender()
    : program_(0)
    , vao_(0)
    , vBuffer_(QOpenGLBuffer::VertexBuffer)
{
}

GeometryRender::~GeometryRender()
{
    delete program_;
}

// Initialize OpenGL
void GeometryRender::initialize()
{
    OpenGLWindow::initialize();

    // Enable depth test
    glEnable(GL_DEPTH_TEST);

    // Create and initialize a program object with shaders
    program_ = initProgram(this, "vshader.glsl", "fshader.glsl");
    // Installs the program object as part of current rendering state
    // Corresponds to the GL call glUseProgram()
    program_->bind();

    // Creat a vertex array object
    // Corresponds to the GL calls glGenVertexArrays() and glBindVertexArray()
    vao_.create();
    vao_.bind();

    // Create vertex buffer in the shared display list space and
    // bind it as VertexBuffer (GL_ARRAY_BUFFER)
    // Corresponds to the GL calls glGenBuffers() and glBindBuffer()
    vBuffer_.create();
    vBuffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vBuffer_.bind();

    // Get locations of the attributes in the shader
    // Corresponds to the GL calls glGetAttribLocation() and
    // glGetUniformLocation()
    locVertices_ = program_->attributeLocation("vPosition");

    vao_.release();
    program_->release();

    loadGeometry();
}

void GeometryRender::loadGeometry(void)
{
    // Define vertices in array
    vertices_.push_back(VertVec(-0.5f, -0.75f));
    vertices_.push_back(VertVec( 0.0f,  0.75f));
    vertices_.push_back(VertVec( 0.5f, -0.75f));

    program_->bind();
    vao_.bind();

    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices_, 2, GL_FLOAT, GL_TRUE, 0, BUFFER_OFFSET(0));

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices_.size()*sizeof(VertVec);
    vBuffer_.allocate(vSize);
    vBuffer_.write(0, vertices_.constData(), vSize);

    vao_.release();
    program_->release();
}

// Render object
void GeometryRender::display()
{
    program_->bind();
    vao_.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableVertexAttribArray(locVertices_);
    glDrawArrays(GL_TRIANGLES, 0, vertices_.size());
    glFlush();
    glDisableVertexAttribArray(locVertices_);

    vao_.release();
    program_->release();

}
