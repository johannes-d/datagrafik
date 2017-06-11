#include "ass2widget.h"
#include "ui_ass2widget.h"

using namespace std;

Ass2Widget::Ass2Widget(QWidget *parent) :
    QWidget(parent),
    ui_(new Ui::Ass2Widget)
{
    ui_->setupUi(this);
}

Ass2Widget::~Ass2Widget()
{
    delete ui_;
}

//  Set projection to orthographic
void Ass2Widget::gui_set_projection_parallel()
{
    ui_->btn_parallel->setChecked(true);
}

//  Set projection to perspective
void Ass2Widget::gui_set_projection_perspective()
{
    ui_->btn_perspective->setChecked(true);
}

//  Set option value of top
void Ass2Widget::gui_set_option_top(double value)
{
    ui_->spin_top->setValue(value);
}

//  Set option value of far
void Ass2Widget::gui_set_option_far(double value)
{
    ui_->spin_pefar->setValue(value);
    ui_->spin_plfar->setValue(value);
}

//  Set option value of oblique scale
void Ass2Widget::gui_set_option_oblique_scale(double value)
{
    ui_->spin_oblscale->setValue(value);
}

//  Set option value of oblique angle
void Ass2Widget::gui_set_option_oblique_angle(double value)
{
    ui_->spin_oblangle->setValue(value);
}

//  Set option value of field of view
void Ass2Widget::gui_set_option_fov(double value)
{
    ui_->spin_fov->setValue(value);
}


// Called when parallel-button is clicked
void Ass2Widget::on_btn_parallel_clicked(bool checked)
{
    cout << "Parallel projection: " << checked << endl;
}

// Called when perspective-button is clicked
void Ass2Widget::on_btn_perspective_clicked(bool checked)
{
    cout << "Perspective projection: " << checked << endl;
}

// Called when top value changes value
void Ass2Widget::on_spin_top_valueChanged(double top)
{
    cout << "Top: " << top << endl;
}

// Called when parallel far value changes value
void Ass2Widget::on_spin_plfar_valueChanged(int plfar)
{
    cout << "Far: " << plfar << endl;
}

// Called when oblique scale value changes value
void Ass2Widget::on_spin_oblscale_valueChanged(double scale)
{
    cout << "Scale: " << scale << endl;
}

// Called when oblique angle value changes value
void Ass2Widget::on_spin_oblangle_valueChanged(double angle)
{
    cout << "Angle: " << angle << endl;
}

// Called when field of view value changes value
void Ass2Widget::on_spin_fov_valueChanged(int fov)
{
    cout << "Field of view: " << fov << endl;
}

// Called when perspective far value changes value
void Ass2Widget::on_spin_pefar_valueChanged(int pefar)
{
    cout << "Far: " << pefar << endl;
}

// Terminate application if window is closed
void Ass2Widget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    qApp->quit();
}

// Called when open file button is clicked
void Ass2Widget::on_push_file_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open OBJ File"), QString(),
            tr("OBJ files (*.obj)"));

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        // Get only file name (truncate path)
        QString fname = fileName.section('/', -1);
        ui_->label_obj_filename->setText(fname);

        cout << "OBJ file to open: " << fileName.toStdString() << endl;
        //QTextStream in(&file);
        // Read the object file...
        file.close();
    }
}
