#pragma once

#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <QVector2D>
#include <QMatrix4x4>
#include <QtCore/qmath.h>

#include "openglwindow.h"

using VertVec = QVector2D;

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

    // OpenGL attribute locations
    GLuint locVertices_;

    // Geometry data
    QVector<VertVec> vertices_;

    void loadGeometry(void);
};

