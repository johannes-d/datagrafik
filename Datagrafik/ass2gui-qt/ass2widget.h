#pragma once

#include <iostream>
#include <QWidget>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>

namespace Ui {
class Ass2Widget;
}

class Ass2Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Ass2Widget(QWidget *parent = 0);
    ~Ass2Widget();

    void gui_set_projection_parallel();
    void gui_set_projection_perspective();

    void gui_set_option_top(double value);
    void gui_set_option_far(double value);
    void gui_set_option_fov(double value);
    void gui_set_option_oblique_angle(double value);
    void gui_set_option_oblique_scale(double value);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_btn_parallel_clicked(bool checked);

    void on_btn_perspective_clicked(bool checked);

    void on_spin_top_valueChanged(double top);

    void on_spin_plfar_valueChanged(int plfar);

    void on_spin_oblscale_valueChanged(double scale);

    void on_spin_oblangle_valueChanged(double angle);

    void on_spin_fov_valueChanged(int fov);

    void on_spin_pefar_valueChanged(int pefar);

    void on_push_file_clicked();

private:
    Ui::Ass2Widget *ui_;
};

