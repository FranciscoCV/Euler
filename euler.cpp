#include "euler.h"
#include "ui_euler.h"
#include "math.h"

Euler::Euler(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Euler)
{
    ui->setupUi(this);
    // Conexiones
    connect(ui->Metodo,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));
}

Euler::~Euler()
{
    delete ui;
}


double Euler::funcion(double c){
    return (-2*(c*c*c))+(12*(c*c))-(20*c)+8.5; //returns the derived function
}


double Euler::funcion1(double c1){
    return -(0.5*(c1*c1*c1*c1))+(4*(c1*c1*c1))-(10*(c1*c1))+(8.5*c1)+1; //returns the original function
}
void Euler::metodo(){
    QString temp, temp1, temp2, temp3, temp4; //The value of the Spinbox is recovered and saved in variables
    double x0=ui->X0->value();
    double xn=ui->Xn->value();
    double h=ui->H->value();
    int rango=0;
    int i;
    double xi0=0, error=0, yi=0, yi1=0;

    rango=(xn-x0)/h;  //We obtain the number of iterations for the for cycle

    for(i=0;i<rango;i++){

    yi1=funcion1(xi0)+(funcion(xi0)*h);  //We obtain the formula of the method

    xi0=(xi0+h);

    yi=funcion1(xi0);//We get the real value of the function

    error=100*std::abs(yi1-yi)/yi1;  //We obtain the percentage error

    temp.append("\n\ny(").append(temp1.setNum(xi0)).append(")=").append(temp2.setNum(yi1)).append("\t\tYreal=").append(temp3.setNum(yi)).append("\nError=").append(temp4.setNum(error)).append("%");
    yi1=0;yi=0;error=0; //We clean the variables
    }

    ui->texto->setText(temp);  //The text is presented
    }

void Euler::borrar(){
    ui->X0->setValue(0.0);  //The spinboxes are deleted
    ui->Xn->setValue(0.0);
    ui->H->setValue(0.0);
    ui->texto->clear();
}


