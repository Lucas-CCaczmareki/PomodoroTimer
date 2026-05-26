#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    remainingTime = 25 * 60; // 25 minutos
    clock = new QTimer(this);

    connect(clock, &QTimer::timeout, this, &MainWindow::updateClock);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPausar_clicked()
{
    ui->labelStatus->setText("Foco !!!");
    clock->start();
}

void MainWindow::updateClock() {
    if (remainingTime > 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --remainingTime;

        int minutes = remainingTime / 60;
        int seconds = remainingTime % 60;

        ui->labelTempo->setText(QString("%1:%2")
                                .arg(minutes, 2, 10, QChar('0'))
                                .arg(seconds, 2, 10, QChar('0'))
                                );

    } else {
        clock->stop();
        ui->labelStatus->setText("Pausa...");
    }
}

