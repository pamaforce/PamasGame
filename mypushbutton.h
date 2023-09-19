#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QString img);
    void btnup();
    void btndown();
signals:

public slots:
};

#endif // MYPUSHBUTTON_H
