#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void updateClock(); // evento que vai ser disparado pelo clock

    void on_btnIniciar_clicked();
    void on_btnReset_clicked();
    void on_btnPausar_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    QTimer *clock; //cria um clock que vai disparar um evento
    int remainingTime;
    bool f_rest;
};
#endif // MAINWINDOW_H
