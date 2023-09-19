#include "namewidget.h"
#include "mypushbutton.h"
#include "ui_namewidget.h"
#include <Qpixmap>
#include <QString>

NameWidget::NameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameWidget)
{
    setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    ui->setupUi(this);
    ui->label0->setPixmap(QPixmap(":/res/pic/nameback.jpg"));
    ui->label0->setScaledContents(true);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit senddata(ui->lineEdit->text());
        this->close();
    });
}


NameWidget::~NameWidget()
{
    delete ui;
}
