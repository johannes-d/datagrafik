#include <QApplication>
#include <QSurfaceFormat>
#include <iostream>
#include "geometryrender.h"
#include "ass2widget.h"
using namespace std;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Create the OpenGL window
    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    // Create the widget window
    Ass2Widget widgets;
    widgets.show();

    GeometryRender window;
    window.setFormat(format);
    window.resize(1024, 768);
    window.setTitle("Workshop 1");
    window.show();
    window.initialize();

    return app.exec();
}
