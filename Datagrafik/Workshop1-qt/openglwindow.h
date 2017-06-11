#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include <QKeyEvent>
#include <QtCore/QCoreApplication>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLPaintDevice>
#include <QtGui/QPainter>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow : public QWindow,  protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();
    float Jcount, Lcount, Icount;
    float Kcount, Leftcount, Rightcount;
    float Ocount, Upcount, Downcount;

    virtual void display(QPainter *painter);
    virtual void display();
    virtual void loadOBJ()=0;
  //  virtual void loadViewMatrix(char *whatKey,float *counter)=0;
    virtual void loadModelMatrix(char *whatKey,float *counter)=0;
    virtual void initialize();

public slots:
    void displayNow();

protected:
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void reshape(int w, int h);
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;
    bool eventFilter(QEvent *event);

    QOpenGLShaderProgram *initProgram(QObject *parent, const QString &vShaderFile, const QString &fShaderFile) const;

private:

    QOpenGLContext *context_;
    QOpenGLPaintDevice *device_;
};
