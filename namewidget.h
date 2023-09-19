#ifndef NAMEWIDGET_H
#define NAMEWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class NameWidget;
}

class NameWidget : public QWidget
{
    Q_OBJECT

public:

    explicit NameWidget(QWidget *parent = 0);
    ~NameWidget();

signals:
    void senddata(QString);
private slots:


private:
    Ui::NameWidget *ui;
};

#endif // NAMEWIDGET_H
