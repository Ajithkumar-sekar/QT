#include <QApplication>
#include<QHBoxLayout>
#include<Qslider>
#include<QSpinBox>
#include<QPushButton>

int main(int argc, char *argv[])
{
    QApplication prog(argc, argv);

    QWidget *mainwindow=new QWidget;
    mainwindow->setWindowTitle("Choose the range!!");

    QSlider *slider=new QSlider(Qt::Horizontal);
    QSpinBox *spin=new QSpinBox();
    spin->setRange(0,50);
    slider->setRange(0,50);

    QObject::connect(spin,SIGNAL(valueChanged(int)),slider,SLOT(setValue(int)));
    QObject::connect(slider,SIGNAL(valueChanged(int)),spin,SLOT(setValue(int)));
    slider->setValue(5);

    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(slider);
    layout->addWidget(spin);
    mainwindow->setLayout(layout);

    QPushButton *button=new QPushButton("Quit");
    QObject::connect(button,SIGNAL(clicked(bool)),&prog,SLOT(quit()));
    layout->addWidget(button);

    mainwindow->show();

    return prog.exec();
}
