/********************************************************************************
** Form generated from reading UI file 'ass2widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASS2WIDGET_H
#define UI_ASS2WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ass2Widget
{
public:
    QGroupBox *group_projection;
    QRadioButton *btn_parallel;
    QRadioButton *btn_perspective;
    QDoubleSpinBox *spin_top;
    QDoubleSpinBox *spin_oblscale;
    QSpinBox *spin_fov;
    QSpinBox *spin_pefar;
    QSpinBox *spin_plfar;
    QDoubleSpinBox *spin_oblangle;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_obj_filename;
    QPushButton *push_file;
    QLabel *label_file;

    void setupUi(QWidget *Ass2Widget)
    {
        if (Ass2Widget->objectName().isEmpty())
            Ass2Widget->setObjectName(QStringLiteral("Ass2Widget"));
        Ass2Widget->resize(371, 310);
        group_projection = new QGroupBox(Ass2Widget);
        group_projection->setObjectName(QStringLiteral("group_projection"));
        group_projection->setGeometry(QRect(10, 60, 191, 251));
        btn_parallel = new QRadioButton(group_projection);
        btn_parallel->setObjectName(QStringLiteral("btn_parallel"));
        btn_parallel->setGeometry(QRect(10, 20, 107, 20));
        btn_parallel->setChecked(true);
        btn_perspective = new QRadioButton(group_projection);
        btn_perspective->setObjectName(QStringLiteral("btn_perspective"));
        btn_perspective->setGeometry(QRect(10, 160, 107, 20));
        spin_top = new QDoubleSpinBox(group_projection);
        spin_top->setObjectName(QStringLiteral("spin_top"));
        spin_top->setGeometry(QRect(100, 40, 81, 25));
        spin_top->setAutoFillBackground(true);
        spin_top->setDecimals(1);
        spin_top->setMinimum(1);
        spin_top->setSingleStep(0.5);
        spin_top->setValue(1);
        spin_oblscale = new QDoubleSpinBox(group_projection);
        spin_oblscale->setObjectName(QStringLiteral("spin_oblscale"));
        spin_oblscale->setGeometry(QRect(100, 100, 81, 25));
        spin_oblscale->setAutoFillBackground(true);
        spin_oblscale->setMaximum(1);
        spin_oblscale->setSingleStep(0.25);
        spin_fov = new QSpinBox(group_projection);
        spin_fov->setObjectName(QStringLiteral("spin_fov"));
        spin_fov->setEnabled(false);
        spin_fov->setGeometry(QRect(100, 180, 81, 25));
        spin_fov->setMinimum(20);
        spin_fov->setMaximum(160);
        spin_fov->setValue(90);
        spin_pefar = new QSpinBox(group_projection);
        spin_pefar->setObjectName(QStringLiteral("spin_pefar"));
        spin_pefar->setEnabled(false);
        spin_pefar->setGeometry(QRect(100, 210, 81, 25));
        spin_pefar->setMinimum(1);
        spin_pefar->setMaximum(10000);
        spin_pefar->setSingleStep(10);
        spin_pefar->setValue(500);
        spin_plfar = new QSpinBox(group_projection);
        spin_plfar->setObjectName(QStringLiteral("spin_plfar"));
        spin_plfar->setGeometry(QRect(100, 70, 81, 25));
        spin_plfar->setMinimum(1);
        spin_plfar->setMaximum(10000);
        spin_plfar->setSingleStep(10);
        spin_plfar->setValue(500);
        spin_oblangle = new QDoubleSpinBox(group_projection);
        spin_oblangle->setObjectName(QStringLiteral("spin_oblangle"));
        spin_oblangle->setGeometry(QRect(100, 130, 81, 25));
        spin_oblangle->setMinimum(15);
        spin_oblangle->setMaximum(75);
        spin_oblangle->setSingleStep(15);
        spin_oblangle->setValue(45);
        label = new QLabel(group_projection);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 40, 31, 21));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(group_projection);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 31, 21));
        label_3 = new QLabel(group_projection);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 100, 91, 21));
        label_4 = new QLabel(group_projection);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 91, 21));
        label_5 = new QLabel(group_projection);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 180, 91, 21));
        label_6 = new QLabel(group_projection);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 210, 31, 21));
        label_obj_filename = new QLabel(Ass2Widget);
        label_obj_filename->setObjectName(QStringLiteral("label_obj_filename"));
        label_obj_filename->setGeometry(QRect(20, 30, 300, 20));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_obj_filename->sizePolicy().hasHeightForWidth());
        label_obj_filename->setSizePolicy(sizePolicy);
        label_obj_filename->setFocusPolicy(Qt::ClickFocus);
        label_obj_filename->setAutoFillBackground(true);
        label_obj_filename->setFrameShape(QFrame::Panel);
        label_obj_filename->setFrameShadow(QFrame::Sunken);
        label_obj_filename->setLineWidth(1);
        label_obj_filename->setScaledContents(false);
        label_obj_filename->setTextInteractionFlags(Qt::LinksAccessibleByMouse|Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        push_file = new QPushButton(Ass2Widget);
        push_file->setObjectName(QStringLiteral("push_file"));
        push_file->setGeometry(QRect(330, 30, 31, 21));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(push_file->sizePolicy().hasHeightForWidth());
        push_file->setSizePolicy(sizePolicy1);
        label_file = new QLabel(Ass2Widget);
        label_file->setObjectName(QStringLiteral("label_file"));
        label_file->setGeometry(QRect(10, 10, 61, 15));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_file->setFont(font);
        QWidget::setTabOrder(push_file, btn_parallel);
        QWidget::setTabOrder(btn_parallel, spin_top);
        QWidget::setTabOrder(spin_top, spin_plfar);
        QWidget::setTabOrder(spin_plfar, spin_oblscale);
        QWidget::setTabOrder(spin_oblscale, spin_oblangle);
        QWidget::setTabOrder(spin_oblangle, btn_perspective);
        QWidget::setTabOrder(btn_perspective, spin_fov);
        QWidget::setTabOrder(spin_fov, spin_pefar);

        retranslateUi(Ass2Widget);
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_top, SLOT(setEnabled(bool)));
        QObject::connect(btn_perspective, SIGNAL(toggled(bool)), spin_fov, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_plfar, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_oblscale, SLOT(setEnabled(bool)));
        QObject::connect(btn_parallel, SIGNAL(toggled(bool)), spin_oblangle, SLOT(setEnabled(bool)));
        QObject::connect(btn_perspective, SIGNAL(toggled(bool)), spin_pefar, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Ass2Widget);
    } // setupUi

    void retranslateUi(QWidget *Ass2Widget)
    {
        Ass2Widget->setWindowTitle(QApplication::translate("Ass2Widget", "3D Studio", 0));
        group_projection->setTitle(QApplication::translate("Ass2Widget", "Projection", 0));
        btn_parallel->setText(QApplication::translate("Ass2Widget", "Parallel", 0));
        btn_perspective->setText(QApplication::translate("Ass2Widget", "Perspective", 0));
        label->setText(QApplication::translate("Ass2Widget", "Top", 0));
        label_2->setText(QApplication::translate("Ass2Widget", "Far", 0));
        label_3->setText(QApplication::translate("Ass2Widget", "Oblique scale", 0));
        label_4->setText(QApplication::translate("Ass2Widget", "Oblique angle", 0));
        label_5->setText(QApplication::translate("Ass2Widget", "Field of view", 0));
        label_6->setText(QApplication::translate("Ass2Widget", "Far", 0));
        label_obj_filename->setText(QApplication::translate("Ass2Widget", "(none)", 0));
        push_file->setText(QApplication::translate("Ass2Widget", "...", 0));
        label_file->setText(QApplication::translate("Ass2Widget", "OBJ File", 0));
    } // retranslateUi

};

namespace Ui {
    class Ass2Widget: public Ui_Ass2Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASS2WIDGET_H
