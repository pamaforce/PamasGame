#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QString>
#include <windows.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString qstrpath = QDir::currentPath();
    QString mydata = qstrpath + QString("/mydata");
    // 这个文件夹需要隐藏
    QDir dir_path_hide(mydata);
    if (!dir_path_hide.exists())
    {
        dir_path_hide.mkdir(mydata);
    }
    // windows API需要将 QString 转化为 LPCWSTR
    // 将文件夹设置为隐藏
    SetFileAttributes((LPCWSTR)mydata.unicode(),FILE_ATTRIBUTE_HIDDEN);
    MainWindow w;
    w.show();


    return a.exec();
}
