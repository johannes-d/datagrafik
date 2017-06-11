#include "geometryrender.h"

GeometryRender::GeometryRender()
    : program_(0)
    , vao_(0)
    , vBuffer_(QOpenGLBuffer::VertexBuffer)
    , iBuffer_(QOpenGLBuffer::IndexBuffer)
    , n_(0)
    , nf_(0)
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

    // Create index buffer in the shared display list space and
    // bind it as IndexBuffer (GL_ELEMENT_ARRAY_BUFFER)
    iBuffer_.create();
    iBuffer_.setUsagePattern(QOpenGLBuffer::StaticDraw);
    iBuffer_.bind();


    // Get locations of the attributes in the shader
    // Corresponds to the GL calls glGetAttribLocation() and
    // glGetUniformLocation()
    locColor_=program_->attributeLocation("vColor");
    locVertices_ = program_->attributeLocation("vPosition");
    locModel_ = program_->uniformLocation("M");

    vao_.release();
    program_->release();

    loadGeometry();
    loadModelMatrix();

}

void GeometryRender::loadGeometry(void)
{
    n_ = 4;
    nf_ = 2;

    // Define vertices in array
    vertices_.push_back(QVector3D(-1.0f, 0.0f, 0.0f));
    vertices_.push_back(QVector3D( 1.0f, 0.0f, 0.0f));
    vertices_.push_back(QVector3D( 0.0f, 1.0f, 0.0f));
    vertices_.push_back(QVector3D(1.0f, 1.0f, 0.0f));

    //Color definitions
    color_.push_back(QVector4D(1.0f,0.0f,0.0f,1.0f));
    color_.push_back(QVector4D(0.0f,1.0f,0.0f,1.0f));
    color_.push_back(QVector4D(0.0f,0.0f,1.0f,1.0f));
    color_.push_back(QVector4D(0.0f,1.0f,1.0f,1.0f));

    // Triangle 1
    indices_.push_back(0);
    indices_.push_back(1);
    indices_.push_back(2);
    // Triangle 2
    indices_.push_back(1);
    indices_.push_back(2);
    indices_.push_back(3);

    program_->bind();
    vao_.bind();

    // Load data to the array buffer
    // Corresponds to the GL call glBufferSubData() or glBufferData()
    size_t vSize = vertices_.size()*sizeof(QVector3D);
    size_t cSize = color_.size()*sizeof(QVector4D);
    vBuffer_.allocate(vSize+cSize);
    vBuffer_.write(0, vertices_.constData(), vSize);
    vBuffer_.write(vSize,color_.constData(),cSize);

    // Load indices to index array
    size_t iSize = indices_.size()*sizeof(unsigned int);
    iBuffer_.allocate(iSize);
    iBuffer_.write(0, indices_.constData(), iSize);

    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized
    glVertexAttribPointer(locVertices_, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(locColor_,4,GL_FLOAT,GL_FALSE,0,BUFFER_OFFSET(vertices_.size()*sizeof(QVector3D)));

    vao_.release();
    program_->release();
}

void GeometryRender::loadModelMatrix(void)
{

    program_->bind();
    // Load model matrix to GPU
    matModel_.scale(0.1f,0.1f,1.0f);
    // Correspons to the GL call glUniformMatrix4fv()
    program_->setUniformValue(locModel_, matModel_);
    program_->release();
}


// Render object
void GeometryRender::display()
{

    program_->bind();
    vao_.bind();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnableVertexAttribArray(locVertices_);
    glEnableVertexAttribArray(locColor_);

    glDrawElements(GL_TRIANGLES, nf_*3, GL_UNSIGNED_INT, BUFFER_OFFSET(0));

    glDisableVertexAttribArray(locVertices_);
    glDisableVertexAttribArray(locColor_);
    vao_.release();
    program_->release();

}
