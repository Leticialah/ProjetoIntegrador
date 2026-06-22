#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include "ESP32Manager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void gerarSenha();
    void onSenhaConfirmada(const QString &senha);
    void onMensagemESP32(const QString &mensagem);
    void onErroESP32(const QString &mensagem);

private:
    Ui::MainWindow *ui;
    ESP32Manager esp32;
    int contadorSenha = 1;
    QString senhaPendente;
};

#endif // MAINWINDOW_H
