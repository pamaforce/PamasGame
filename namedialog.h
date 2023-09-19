#ifndef NAMEDIALOG_H
#define NAMEDIALOG_H

#include <QDialog>

namespace Ui {
class NameDialog;
}

class NameDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NameDialog(QWidget *parent = 0);
    ~NameDialog();
signals:
    void senddata(QString);
private:
    Ui::NameDialog *ui;
};

#endif // NAMEDIALOG_H
