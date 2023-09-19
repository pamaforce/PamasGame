#include "namedialog.h"
#include "ui_namedialog.h"

NameDialog::NameDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NameDialog)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint|windowFlags());
    this->setWindowTitle("Pama'sGame 昵称设置");
    ui->label0->setPixmap(QPixmap(":/res/pic/namepic.jpg"));
    ui->label0->setScaledContents(true);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        emit senddata(ui->lineEdit->text());
        this->close();
    });

}

NameDialog::~NameDialog()
{
    delete ui;
}
