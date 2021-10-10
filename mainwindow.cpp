#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

bool customDays;
bool sfn;

QString months = "January";
int days = 30;
int minusDays = 0;

int month;
int day;
int monthIndex;

float planSize = 1024;
float countedSize;
float currentDaysU;
float currentDays;
float currentSize;

char str[40];
QString convertedSize;

QString megaGigaBytes;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    month = QDate::currentDate().month();
    day = QDate::currentDate().day();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonBox_rejected()
{
    QApplication::quit();
}

void MainWindow::on_checkBox_customDays_toggled(bool checked)
{
    customDays = checked;

    if (customDays == true) {
        ui->comboBox_Months->setEnabled(false);
        ui->label_Month->setEnabled(false);
        ui->label_Days->setText("Days");
        ui->spinBox_Days->setValue(days);

        ui->spinBox_Days->setEnabled(true);
        ui->label_Days->setEnabled(true);
    } else {
        ui->comboBox_Months->setEnabled(true);
        ui->label_Month->setEnabled(true);
        ui->label_Days->setText("-Days");
        ui->spinBox_Days->setValue(minusDays);
    }
}

void MainWindow::on_comboBox_Months_currentIndexChanged(const QString &arg1)
{
    months = arg1;
}

void MainWindow::on_spinBox_Days_valueChanged(int arg1)
{
    if (customDays == true) {
        days = arg1;
    } else {
        minusDays = arg1;
    }
}

void MainWindow::on_spinBox_dataValue_valueChanged(int arg1)
{
    planSize = arg1;
}

void MainWindow::on_comboBox_dataBytes_currentIndexChanged(const QString &arg1)
{
    megaGigaBytes = arg1;
//    ui->lineEdit_resultBytes->setText(arg1);
}

void MainWindow::on_checkBox_fullNumber_toggled(bool checked)
{
    sfn = checked;
}

void MainWindow::on_pushButton_Calculate_clicked()
{

    if (megaGigaBytes == "GB") {
        currentSize = planSize * 1024;
    } else {
        currentSize = planSize;
    }
    if (customDays == false) {
        if (months == "January") {
            currentDaysU = 31;
        } else if (months == "February") {
            currentDaysU = 28;
        } else if (months == "March") {
            currentDaysU = 31;
        } else if (months == "April") {
            currentDaysU = 30;
        } else if (months == "May") {
            currentDaysU = 31;
        } else if (months == "June") {
            currentDaysU = 30;
        } else if (months == "July") {
            currentDaysU = 31;
        } else if (months == "August") {
            currentDaysU = 31;
        } else if (months == "September") {
            currentDaysU = 30;
        } else if (months == "October") {
            currentDaysU = 31;
        } else if (months == "November") {
            currentDaysU = 30;
        } else {
            currentDaysU = 31;
        }
        currentDays = currentDaysU - minusDays;
        countedSize = currentSize / currentDays;
    } else {
        countedSize = currentSize / days;
    }


    if (sfn == true) {
        convertedSize = QString::number(countedSize);
    } else {
        sprintf(str, "%.1f", countedSize);
        sscanf(str, "%f", &countedSize);
        convertedSize = str;;
    }
    if (convertedSize == "inf") {convertedSize = "0";}
    ui->lineEdit_result->setText(convertedSize + " MB");
}

void MainWindow::on_pushButton_getDate_clicked()
{
    month = QDate::currentDate().month();
    day = QDate::currentDate().day();

    int currMonthDays;
    int daysLeft;

    if (month == 1) {
        currMonthDays = 31;
    } else if (month == 2) {
        currMonthDays = 28;
    } else if (month == 3) {
        currMonthDays = 31;
    } else if (month == 4) {
        currMonthDays = 30;
    } else if (month == 5) {
        currMonthDays = 31;
    } else if (month == 6) {
        currMonthDays = 30;
    } else if (month == 7) {
        currMonthDays = 31;
    } else if (month == 8) {
        currMonthDays = 31;
    } else if (month == 9) {
        currMonthDays = 30;
    } else if (month == 10) {
        currMonthDays = 31;
    } else if (month == 11) {
        currMonthDays = 30;
    } else {
        currMonthDays = 31;
    }

    daysLeft = currMonthDays - day;
    monthIndex = month - 1;
    ui->comboBox_Months->setCurrentIndex(monthIndex);

    days = daysLeft;

    minusDays = day;

    if (customDays == true) {
        ui->spinBox_Days->setValue(days);
    } else {
        ui->spinBox_Days->setValue(minusDays);
    }
}
