#ifndef ESP32MANAGER_H
#define ESP32MANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QString>

class ESP32Manager : public QObject
{
    Q_OBJECT

public:
    explicit ESP32Manager(QObject *parent = nullptr);
    ~ESP32Manager();

    bool conectar(const QString &porta);
    bool conectarAutomatico();
    bool estaConectado() const;
    QString portaAtual() const;

    void enviarSenha(const QString &senha);
    void enviarPing();
    void desconectar();

signals:
    void conectado(QString porta);
    void desconectado();
    void senhaConfirmada(QString senha);
    void mensagemRecebida(QString mensagem);
    void erro(QString mensagem);

private slots:
    void lerDados();

private:
    QSerialPort serial;
    QByteArray buffer;

    void processarLinha(const QString &linha);
};

#endif // ESP32MANAGER_H
