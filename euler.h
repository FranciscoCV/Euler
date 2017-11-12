#ifndef EULER_H
#define EULER_H

#include <QMainWindow>

namespace Ui {
class Euler;
}

class Euler : public QMainWindow
{
    Q_OBJECT

public:
    explicit Euler(QWidget *parent = 0);
    ~Euler();
    double funcion(double c);  //Functions used in the program//
    double funcion1(double c1);
private:
    Ui::Euler *ui;
public slots:
    void metodo(); //Slot that performs the method
    void borrar(); //Slot that erases the contents of the spinbox and the text
};

#endif // EULER_H
