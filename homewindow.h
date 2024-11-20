#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QDialog>
#include <QString>

namespace Ui {
class homewindow;
}

class homewindow : public QDialog
{
    Q_OBJECT

public:
    explicit homewindow(QString *username, QString *Password, QWidget *parent = nullptr);
    ~homewindow();

private:
    Ui::homewindow *ui;
    QString *username;
    QString *Password;
};

#endif // HOMEWINDOW_H
