#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

#define Coffee_fee  100
#define Tea_fee     150
#define Cola_fee    200

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff) {
    money += diff;
    ui->lcdNumber->display(money);
    if(diff > 0)    moneyState();
    else            productState();
    /**  instead of moneyState() & productState()
     * checkState();
     **/
}

void Widget::checkState() {
    if(money / Cola_fee) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCola->setEnabled(true);
    } else if(money / Tea_fee) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCola->setEnabled(false);
    } else if(money / Coffee_fee) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
    } else {
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCola->setEnabled(false);
    }
    /*
    switch(money/10) {
        case 19: case 18: case 17: case 16: case 15:
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(false);
            break;
        case 14: case 13: case 12: case 11: case 10:
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(false);
            ui->pbCola->setEnabled(false);
            break;
        case 9: case 8: case 7: case 6: case 5:
        case 4: case 3: case 2: case 1: case 0:
            ui->pbCoffee->setEnabled(false);
            ui->pbTea->setEnabled(false);
            ui->pbCola->setEnabled(false);
            break;
        default:
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(true);
    }
    */
}

void Widget::moneyState() {
    if(money / Cola_fee) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCola->setEnabled(true);
    } else if(money / Tea_fee) {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
    } else if(money / Coffee_fee) {
        ui->pbCoffee->setEnabled(true);
    }
    /*
    switch(money/10) {
        case 19: case 18: case 17: case 16: case 15:
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            break;
        case 14: case 13: case 12: case 11: case 10:
            ui->pbCoffee->setEnabled(true);
            break;
        case 9: case 8: case 7: case 6: case 5:
        case 4: case 3: case 2: case 1: case 0:
            break;
        default:
            ui->pbCoffee->setEnabled(true);
            ui->pbTea->setEnabled(true);
            ui->pbCola->setEnabled(true);
    }
    */
}

void Widget::productState() {
    if(money < Coffee_fee)
        ui->pbCoffee->setEnabled(false);
    if(money < Tea_fee)
        ui->pbTea->setEnabled(false);
    if(money < Cola_fee)
        ui->pbCola->setEnabled(false);
    /*
    switch(money/10) {
        case 0: case 1: case 2: case 3: case 4:
        case 5: case 6: case 7: case 8: case 9:
            ui->pbCoffee->setEnabled(false);
            [[clang::fallthrough]];
        case 10: case 11: case 12: case 13: case 14:
            ui->pbTea->setEnabled(false);
            [[clang::fallthrough]];
        case 15: case 16: case 17: case 18: case 19:
            ui->pbCola->setEnabled(false);
            break;
    }
    */
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(Coffee_fee * -1);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(Tea_fee * -1);
}

void Widget::on_pbCola_clicked()
{
    changeMoney(Cola_fee * -1);
}