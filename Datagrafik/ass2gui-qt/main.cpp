#include <QApplication>

#include "ass2widget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Create the widget window
    Ass2Widget widgets;
    widgets.show();

    return app.exec();
}

