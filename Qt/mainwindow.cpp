#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lblSenha->setText("Senha Atual: ---");
    ui->lblStatus->setText("Status: Aguardando selecao...");
    ui->lblESP32->setText("ESP32: conectando...");
    ui->lblPainelEquipe->setText("Painel da Equipe: ---");

    connect(ui->btnSenha, &QPushButton::clicked, this, &MainWindow::gerarSenha);
    connect(ui->btnConfirmar, &QPushButton::clicked, this, &MainWindow::gerarSenha);

    connect(ui->btnInfo, &QPushButton::clicked, this, [this]() {
        ui->lblStatus->setText("Status: Sistema de autoatendimento sem toque.");
    });

    connect(ui->btnEncerrar, &QPushButton::clicked, this, [this]() {
        close();
    });

    connect(&esp32, &ESP32Manager::conectado, this, [this](const QString &porta) {
        ui->lblESP32->setText("ESP32: conectado em " + porta);
    });

    connect(&esp32, &ESP32Manager::desconectado, this, [this]() {
        ui->lblESP32->setText("ESP32: desconectado");
    });

    connect(&esp32, &ESP32Manager::senhaConfirmada, this, &MainWindow::onSenhaConfirmada);
    connect(&esp32, &ESP32Manager::mensagemRecebida, this, &MainWindow::onMensagemESP32);
    connect(&esp32, &ESP32Manager::erro, this, &MainWindow::onErroESP32);

    esp32.conectarAutomatico();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::gerarSenha()
{
    const QString senha = QString("A%1").arg(contadorSenha, 3, 10, QChar('0'));
    contadorSenha++;
    senhaPendente = senha;

    ui->lblSenha->setText("Senha Atual: " + senha);
    ui->lblStatus->setText("Status: senha gerada. Aguardando confirmacao do ESP32...");
    ui->lblESP32->setText("ESP32: enviando " + senha + "...");

    if (esp32.estaConectado()) {
        esp32.enviarSenha(senha);
    } else {
        ui->lblESP32->setText("ESP32: nao conectado");
        ui->lblStatus->setText("Status: senha gerada, mas o ESP32 nao confirmou.");
    }
}

void MainWindow::onSenhaConfirmada(const QString &senha)
{
    ui->lblESP32->setText("ESP32: confirmacao recebida para " + senha);
    ui->lblStatus->setText("Status: senha confirmada com sucesso.");
    ui->lblPainelEquipe->setText("Painel da Equipe: " + senha);
    senhaPendente.clear();
}

void MainWindow::onMensagemESP32(const QString &mensagem)
{
    if (mensagem == "PONG") {
        ui->lblESP32->setText("ESP32: conectado em " + esp32.portaAtual());
    } else if (mensagem.startsWith("ERRO:")) {
        ui->lblESP32->setText("ESP32: " + mensagem);
    }
}

void MainWindow::onErroESP32(const QString &mensagem)
{
    ui->lblESP32->setText("ESP32: erro - " + mensagem);
}
