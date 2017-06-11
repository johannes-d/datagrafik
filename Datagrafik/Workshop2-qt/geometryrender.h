#pragma once

#include <iostream>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

#include <QtCore/qmath.h>

#include "openglwindow.h"

class GeometryRender : public OpenGLWindow
{
public:
    GeometryRender();
    ~GeometryRender();

    void initialize() Q_DECL_OVERRIDE;
    void display() Q_DECL_OVERRIDE;

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

    // Geometry attributes
    GLuint n_;    // # vertices
    GLuint nf_;   // # faces

    QVector<QVector3D> vertices_;
    QVector<unsigned int> indices_;
    QVector<QVector4D> color_;

    // All matrices initialized to the identity matrix
    QMatrix4x4 matModel_;

    void loadGeometry(void);
    void loadModelMatrix(void) ;

};
