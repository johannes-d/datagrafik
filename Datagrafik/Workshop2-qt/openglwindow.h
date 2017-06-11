#pragma once

#include <iostream>

#include <QtGui/QWindow>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QOpenGLShaderProgram>
#include <QResizeEvent>

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

class QPainter;
class QOpenGLContext;
class QOpenGLPaintDevice;

class OpenGLWindow : public QWindow, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWindow *parent = 0);
    ~OpenGLWindow();

    virtual void display(QPainter *painter);
    virtual void display();

    virtual void initialize();

public slots:
    void displayNow();

protected:
    void reshape(void);
    bool event(QEvent *event) Q_DECL_OVERRIDE;
    void exposeEvent(QExposeEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    QOpenGLShaderProgram *initProgram(QObject *parent, const QString &vShaderFile, const QString &fShaderFile) const;

private:
    QOpenGLContext *context_;
    QOpenGLPaintDevice *device_;
};