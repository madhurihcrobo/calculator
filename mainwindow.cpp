#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QString>
#include <QLineEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);  

    waitingForOperand = true;
    firstOperand = 0;
    currentText = "";
    pendingOperator.clear();


    for (int i = 1; i <= 9; ++i) {
        QPushButton* button = findChild<QPushButton*>("integer_" + QString::number(i));
        if (button) {
            connect(button, &QPushButton::clicked, this, [this, i]() { on_integer_clicked(i); });
        }
    }

   
    connect(ui->pushButton_21, &QPushButton::clicked, this, &MainWindow::on_zero_clicked);
    connect(ui->addition, &QPushButton::clicked, this, &MainWindow::on_operator_clicked);
    connect(ui->subtraction, &QPushButton::clicked, this, &MainWindow::on_operator_clicked);
    connect(ui->multiplication, &QPushButton::clicked, this, &MainWindow::on_operator_clicked);
    connect(ui->division, &QPushButton::clicked, this, &MainWindow::on_operator_clicked);
    connect(ui->backspace, &QPushButton::clicked, this, &MainWindow::on_backspace_clicked);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::on_clear_clicked);
    connect(ui->result, &QPushButton::clicked, this, &MainWindow::on_result_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_integer_clicked(int number)
{
    if (waitingForOperand) {
        currentText = QString::number(number);  
    } else {
        currentText += QString::number(number);  
    }

    ui->display->setText(currentText);
    waitingForOperand = false;
}


void MainWindow::on_zero_clicked()
{
    if (waitingForOperand) {
        currentText = "0";
    } else {
        currentText += "0";
    }

    ui->display->setText(currentText);
    waitingForOperand = false;
}

void MainWindow::on_operator_clicked()
{
    QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
    if (!waitingForOperand && senderButton) {
        firstOperand = currentText.toInt();
        pendingOperator = senderButton->text(); 
        currentText += " " + pendingOperator + " ";  
        ui->display->setText(currentText);
        waitingForOperand = false;  
    }
}


void MainWindow::on_result_clicked()
{
    if (!waitingForOperand) {
        int secondOperand = currentText.section(' ', -1, -1).toInt();
        int result = 0;

        if (pendingOperator == "+") {
            result = firstOperand + secondOperand;
        } else if (pendingOperator == "-") {
            result = firstOperand - secondOperand;
        } else if (pendingOperator == "*") {
            result = firstOperand * secondOperand;
        } else if (pendingOperator == "/") {
            if (secondOperand != 0) {
                result = firstOperand / secondOperand;
            } else {
                ui->display->setText("Error");
                return;
            }
        }

        currentText = QString::number(result);
        ui->display->setText(currentText);
        pendingOperator.clear();
        waitingForOperand = true;
    }
}


void MainWindow::on_backspace_clicked()
{
    currentText.chop(1);  
    ui->display->setText(currentText);
}


void MainWindow::on_clear_clicked()
{
    currentText.clear();
    ui->display->clear();
    firstOperand = 0;
    pendingOperator.clear();
    waitingForOperand = true;
}
