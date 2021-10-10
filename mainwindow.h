#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDate>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_checkBox_customDays_toggled(bool checked);

    void on_comboBox_Months_currentIndexChanged(const QString &arg1);

    void on_spinBox_Days_valueChanged(int arg1);

    void on_buttonBox_rejected();

    void on_spinBox_dataValue_valueChanged(int arg1);

    void on_comboBox_dataBytes_currentIndexChanged(const QString &arg1);

    void on_checkBox_fullNumber_toggled(bool checked);

    void on_pushButton_Calculate_clicked();

    void on_pushButton_getDate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
