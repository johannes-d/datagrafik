#include <QApplication>
#include <QSurfaceFormat>

#include "geometryrender.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Create the OpenGL window
    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);

    GeometryRender window;
    window.setFormat(format);
    window.resize(1024, 768);
    window.setTitle("Datagrafik sommarprojekt");
    window.show();
    window.initialize();

    return app.exec();
}
