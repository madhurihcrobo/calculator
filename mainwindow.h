// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include "ui_mainwindow.h"
// #include <QMainWindow>
// #include<QDebug>


// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private slots:
//     void on_integer_1_clicked();
//     void on_integer_clicked();
//     void on_integer_2_clicked();
//     void on_integer_3_clicked();
//     void on_integer_4_clicked();
//     void on_integer_5_clicked();
//     void on_integer_6_clicked();
//     void on_integer_7_clicked();
//     void on_integer_8_clicked();
//     void on_integer_9_clicked();
//     void on_pushButton_21_clicked(); 
//     void on_backspace_clicked();
//     void on_clear_clicked();
//     void on_addition_clicked();
//     void on_subtraction_clicked();
//     void on_multiplication_clicked();
//     void on_division_clicked();
//     void on_result_clicked();

// private:
//     Ui::MainWindow *ui;
//     QString currentText;
//     QString pendingOperator;
//     double firstOperand;
//     QString none;  
//     bool waitingForOperand;
// };
// #endif 

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots for handling button clicks
    void on_integer_clicked(int number);
    void on_zero_clicked();
    void on_operator_clicked();
    void on_result_clicked();
    void on_backspace_clicked();
    void on_clear_clicked();

private:
    Ui::MainWindow *ui;

    bool waitingForOperand;  // Flag to check if we are waiting for an operand
    int firstOperand;        // Store the first operand for calculations
    QString currentText;     // The current display text
    QString pendingOperator; // Store the pending operator (+, -, *, /)
};

#endif // MAINWINDOW_H
