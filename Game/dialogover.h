#ifndef DIALOGOVER_H
#define DIALOGOVER_H

#include <QDialog>

namespace Ui {
class DialogOver;
}

class DialogOver : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOver(QWidget *parent = nullptr);
    ~DialogOver();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogOver *ui;
};

#endif // DIALOGOVER_H
