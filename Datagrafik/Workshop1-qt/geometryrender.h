#pragma once

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QVector4D>
#include <QMatrix4x4>
#include <QtCore/qmath.h>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <QGenericMatrix>
#include <math.h>
#include "openglwindow.h"
#include "ass2widget.h"
#include "ui_ass2widget.h"

#define PI 3.14159265

using VertVec = QVector4D;
class GeometryRender : public OpenGLWindow
{
public:
	GeometryRender();
	~GeometryRender();

	void initialize() Q_DECL_OVERRIDE;
	void display() Q_DECL_OVERRIDE;
	void loadOBJ();

private:
	QOpenGLShaderProgram *program_;
	// OpenGL buffers
	QOpenGLVertexArrayObject vao_;
	QOpenGLBuffer vBuffer_;
	QOpenGLBuffer iBuffer_;

	// OpenGL attribute locations
	GLuint locVertices_;
	GLuint locColor_;
	GLuint locModel_;
	GLuint locCamera_;
	GLuint locProjection_;

	GLuint n_;    // # vertices
	GLuint nf_;   // # faces
	GLuint vn_;   // # normals

	// Geometry data
	QVector<VertVec> vertices_;
	QVector<unsigned int> indices_;
	QVector<QVector4D> color_;


	//Adding a model matrix
	QMatrix4x4 matModel,projModel,viewModel;
	void Proj(void);
	void loadGeometry(void);
//	void loadViewMatrix(char *whatKey,float *counter);
	void loadModelMatrix(char *whatKey,float *counter);

};
