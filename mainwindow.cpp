#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // REMAINING TIME É EM SEGUNDOS, pra ficar na mesma unidade do clock (que é ms, mas botamos um clock de 1000ms = 1 segundo)
    remainingTime = 25 * 60; // 25 minutos
    // remainingTime = 5;          // 5 segundo
    clock = new QTimer(this);   //instancia o timer
    f_rest = 0;

    // Conecta o timer à uma função, sempre que o timer esgotar, ele vai lançar essa função, e o SO vai executar ela.
    // Ela pode fazer qualquer coisa, nesse caso, atualiza o label do timer
    connect(clock, &QTimer::timeout, this, &MainWindow::updateClock);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnIniciar_clicked()
{
    // Quando o botão de iniciar o timer for clicado, inicializa-se o QTimer com um passo de 1000ms (1s)
    // A cada 1s ele dispara o timeout e executa a função updateClock()
    ui->labelStatus->setText("Foco!");
    remainingTime = 25 * 60;
    clock->start(1000);
}


void MainWindow::on_btnPausar_clicked(bool checked) {
    if (checked) {
        clock->stop();
        ui->labelStatus->setText("PAUSADO");
    } else {
        clock->start(1000);
        ui->labelStatus->setText("Foco!");
    }
}

void MainWindow::on_btnReset_clicked() {
    ui->labelStatus->setText("Pomodoro 25:5");
    ui->labelTempo->setText("");
    clock->stop();
}

void MainWindow::updateClock() {
    int minutes, seconds;
    if (remainingTime >= 60) { //se tem pelo menos 1 minuto
        minutes = remainingTime / 60;
        seconds = remainingTime % 60;
    } else {
        minutes = 0;
        seconds = remainingTime;
    }

    if (remainingTime > 0) { //tem que bater com o tanto de minutos escritos em label.
        --remainingTime;

        ui->labelTempo->setText(QString("%1:%2") //%1 parametro 1 da QString :%2 parametro 2 da QString
                                .arg(minutes, 2, 10, QChar('0')) //.arg coloca no parametro da QString oq botar nos parâmetros dele
                                .arg(seconds, 2, 10, QChar('0')) //.arg(variavel, número de caracteres, base numérica, carcter de preenchimento)
                                );

    } else if (f_rest == 1){
        clock->stop(); //para o QTimer, ele não dispara mais o evento
        ui->labelStatus->setText(" ");
    } else if (f_rest == 0) {
        remainingTime = 5 * 60;
        f_rest = 1;
        ui->labelStatus->setText("Descansando...");

        ui->labelTempo->setText(QString("%1:%2")
                                    .arg(minutes, 2, 10, QChar('0'))
                                    .arg(seconds, 2, 10, QChar('0'))
                                );
    }
}


