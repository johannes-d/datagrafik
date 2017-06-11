#include "geometryrender.h"
#include "ass2widget.h"
#include "ui_ass2widget.h"
#include <glm/glm.hpp>

using namespace std;

//////////////////////////////////
bool paCheck(true);
bool peCheck(false);
int PLFAR(500);
int PEFAR(0);
int FOV(80);
double TOP;
double SCALE;
double ANGLE;

QVector4D p_0(0.0f, 1.0f, 0.0f,0.0f);
QVector4D p_ref(0.0f, 0.0f, 0.0f,1.0f);
QVector4D eye_(0.0f, 0.0f, 2.0f,1.0f);

//////////////////////////////////


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

    // Create a vertex array object
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
    locProjection_ = program_->uniformLocation("P");

    vao_.release();
    program_->release();
}

void GeometryRender::loadOBJ(){

  //NAME INITIALIZATION AND ALLOCATION
  //lOADER
  ifstream source;
  source.open("vert.obj");
  if(!source.is_open()){
    cout<<"ERROR: Cannot open file";
  }

  char shapename[128];
  float x,y,z;
  n_=0;
  nf_=0;
  vn_=0;
  //
  int nrOfSlash=0;
  int a=0,b=0,c=0,an=0,bn=0,cn=0;

  do{

    source>>shapename;

    if (strcmp(shapename,"#")==0){};

    if (strcmp(shapename, "v")==0){
      n_=n_+1;
      source >> x >> y >> z;
      if (source.fail()){
        loadGeometry();
        break;
      }
      VertVec *tempVec= new VertVec(x,y,z,1.0f);
      tempVec->normalize();

      vertices_.push_back(*tempVec);
      nrOfSlash=1;
    }
    else if(strcmp(shapename, "vn")==0){
      vn_=vn_+1;
      source >> x >> y >> z;
      if (source.fail()){
        loadGeometry();
        break;
      }
      VertVec *tempVecNormal= new VertVec(x,y,z,1.0f);
      tempVecNormal->normalize();
      nrOfSlash=2;
    }
        //////////////////////////
    else if(strcmp(shapename, "f")==0){

        if(!source.eof()){
          if (nrOfSlash==1){
            int x=0,y=0,z=0;
            source >> x >> y >> z;
            if (source.fail()){
              loadGeometry();
              break;
            }
            indices_.push_back(x-1);
            indices_.push_back(y-1);
            indices_.push_back(z-1);
          }

          if (nrOfSlash==2){
            string line;
            getline(source,line);

            string subline;
            string subline_n;
            string Vx,Vy,Vz;
            string Vn_x,Vn_y,Vn_z;

            //Used to obtain the integer values
            //////////////////////////////

            subline=line;
            Vx=subline.substr(0,subline.find("//"));
            stringstream convert_x(Vx);
            convert_x>>a;

            subline.erase(0,subline.find("//")+4);
            Vy=subline.substr(0,subline.find("//"));
            stringstream convert_y(Vy);
            convert_y>>b;

            subline.erase(0,subline.find("//")+4);
            Vz=subline.substr(0,subline.find("//"));
            stringstream convert_z(Vz);
            convert_z>>c;

            indices_.push_back(a-1);
            indices_.push_back(b-1);
            indices_.push_back(c-1);
            //////////////////////////////
            subline_n=line;
            subline_n.erase(0,subline_n.find("//")+2);
            Vn_x=subline_n.substr(0,subline_n.find(" "));
            stringstream convert_nx(Vn_x);
            convert_nx>>an;

            subline_n.erase(0,subline_n.find("//")+2);
            Vn_y=subline_n.substr(0,subline_n.find(" "));
            stringstream convert_ny(Vn_y);
            convert_ny>>bn;

            subline_n.erase(0,subline_n.find("//")+2);
            Vn_z=subline_n.substr(0,subline_n.find(" "));
            stringstream convert_nz(Vn_z);
            convert_nz>>cn;

            //////////////////////////////
        }
    /*   */
        nf_=nf_+1;
        }
        else if (source.fail()){
             //Color definitions
             color_.push_back(QVector4D(0.0f,1.0f,1.0f,0.0f));
             color_.push_back(QVector4D(1.0f,1.0f,1.0f,0.0f));
             color_.push_back(QVector4D(1.0f,1.0f,1.0f,0.0f));

             loadGeometry();
             displayNow();
             break;
        }
      }
      else
        break;
    }while(!source.fail());
}

void GeometryRender::loadGeometry(void)
{
    vao_.bind();
    // Set the pointers of locVertices_ to the right places
    // Can also call program_->setAttributeBuffer() but then the values are normalized

    // Load data to the array buffer
    // Corresponds to the GL call glBufferData()
    size_t vSize = vertices_.size()*sizeof(VertVec);
    size_t cSize = color_.size()*sizeof(QVector4D);

    vBuffer_.allocate(vSize+cSize);
    vBuffer_.write(0, vertices_.constData(), vSize);
    vBuffer_.write(vSize,color_.constData(),cSize);


        // Load indices to index array
    size_t iSize = indices_.size()*sizeof(unsigned int);
    iBuffer_.allocate(iSize);
    iBuffer_.write(0, indices_.constData(), iSize);

    glVertexAttribPointer(locVertices_, 4, GL_FLOAT,
       GL_TRUE, 0, BUFFER_OFFSET(0));
    glVertexAttribPointer(locColor_,4,GL_FLOAT,
      GL_FALSE,0,BUFFER_OFFSET(vertices_.size()*sizeof(QVector3D)));
    vao_.release();
}

void GeometryRender::loadModelMatrix(char *whatKey,float *counter)
{

    QMatrix4x4 cameraTransformation;
    QMatrix4x4 tempM;
    bool tempPA=paCheck, tempPE=peCheck;
    int tempPLFAR=PLFAR,tempPEFAR=PEFAR, tempFOV=FOV;
    double tempTOP=TOP, tempSCALE=SCALE, tempANGLE=ANGLE;
    //FIRST TRANSFORM POSITION SO THAT REF IS AT 0 0 0

    program_->bind();
    // Load model matrix to GPU
    if(*whatKey=='J'){
      tempM.translate(0.0f-0.1*(*counter),0.0f,0.0f);
    }
    else if(*whatKey=='K'){
      tempM.translate(0.0f,0.0f-0.1*(*counter),0.0f);
    }
    else if(*whatKey=='L'){
      tempM.translate(0.0f+0.1*(*counter),0.0f,0.0f);
    }
    else if(*whatKey=='I'){
      tempM.translate(0.0f,0.0f+0.1*(*counter),0.0f);
    }
    else if(*whatKey=='1'){
      tempM.rotate(10*(*counter),0.0f,1.0f,0.0f);
    }
    else if(*whatKey=='2'){
      tempM.rotate(-10*(*counter),0.0f,1.0f,0.0f);
    }
    else if(*whatKey=='3'){
      tempM.rotate(10*(*counter),1.0f,0.0f,0.0f);
    }//0.0f-1.0*(*counter)
    else if(*whatKey=='4'){
      tempM.rotate(-10*(*counter),1.0f,0.0f,0.0f);
    }
    else if(*whatKey='O'){
      tempM.scale(1.0f,1.0f,1.0f);
    }
    else if(*whatKey=='A'){
      cameraTransformation.translate(0.0f,0.0f,-1.0f);
      cameraTransformation.rotate(10*(*counter),0.0f,0.0f);
      cameraTransformation.translate(0.0f,0.0f,1.0f);
    }
    else if(*whatKey=='D'){
      cameraTransformation.translate(0.0f,0.0f,-1.0f);
      cameraTransformation.rotate(10*(*counter),0.0f,0.0f);
      cameraTransformation.translate(0.0f,0.0f,1.0f);
    }
    else if(*whatKey=='W'){
      cameraTransformation.translate(0.0f,0.0f,-1.0f);
      cameraTransformation.rotate(10*(*counter),0.0f,0.0f);
      cameraTransformation.translate(0.0f,0.0f,1.0f);
    }
    else if(*whatKey=='S'){
      cameraTransformation.translate(0.0f,-0.1f,0.0f);
      cameraTransformation.rotate(10*(*counter),0.0f,0.0f);
      cameraTransformation.translate(0.0f,0.2f,0.0f);
    }
    else{
      tempM.scale(1.0f,1.0f,1.0f);
      cameraTransformation.scale(1.0f,1.0f,1.0f);
    }
    p_ref= cameraTransformation * p_ref ;
    p_0= cameraTransformation * p_0 ;

    QVector3D up=p_0.toVector3DAffine();
    QVector3D pref=p_ref.toVector3DAffine();
    QVector3D camera=eye_.toVector3DAffine();
    cout<<up.y();

    up.normalize();
    pref.normalize();
    camera.normalize();
    cout<<up.y();

    //viewModel.inverted();
    viewModel.lookAt(camera,pref,up);

    //viewModel.normalMatrix();
    //matModel = tempM * matModel;
    matModel =  viewModel * tempM * matModel;
    //matModel= viewModel * matModel;

    //matModel.inverted();
    program_->setUniformValue(locModel_, matModel);
    program_->setUniformValue(locProjection_, projModel);

    program_->release();
    displayNow();

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
    //
    glFlush();
    glDisableVertexAttribArray(locVertices_);
    glDisableVertexAttribArray(locColor_);

    vao_.release();
    program_->release();
}
