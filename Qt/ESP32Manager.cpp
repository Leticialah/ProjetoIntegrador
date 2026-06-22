#include "ESP32Manager.h"

#include <QSerialPortInfo>

ESP32Manager::ESP32Manager(QObject *parent)
    : QObject(parent)
{
    connect(&serial, &QSerialPort::readyRead, this, &ESP32Manager::lerDados);

    connect(&serial, &QSerialPort::errorOccurred, this, [this](QSerialPort::SerialPortError serialError) {
        if (serialError != QSerialPort::NoError) {
            emit erro(serial.errorString());
        }
    });
}

ESP32Manager::~ESP32Manager()
{
    desconectar();
}

bool ESP32Manager::conectar(const QString &porta)
{
    if (serial.isOpen()) {
        serial.close();
    }

    serial.setPortName(porta);
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (!serial.open(QIODevice::ReadWrite)) {
        emit erro("Nao foi possivel conectar na porta " + porta + ": " + serial.errorString());
        return false;
    }

    emit conectado(porta);
    enviarPing();
    return true;
}

bool ESP32Manager::conectarAutomatico()
{
#ifdef Q_OS_WIN
    // Primeiro tenta a porta usada nos testes do ESP32.
    if (conectar("COM12")) {
        return true;
    }
#endif

    const auto portas = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : portas) {
        const QString nome = info.portName();
        const QString descricao = info.description().toLower();
        const QString fabricante = info.manufacturer().toLower();

        const bool pareceESP32 = descricao.contains("usb") ||
                                 descricao.contains("serial") ||
                                 descricao.contains("jtag") ||
                                 fabricante.contains("espressif") ||
                                 fabricante.contains("wch") ||
                                 fabricante.contains("silicon") ||
                                 fabricante.contains("arduino");

        if (pareceESP32 && conectar(nome)) {
            return true;
        }
    }

    emit erro("ESP32 nao encontrado. Verifique a porta serial e tente novamente.");
    return false;
}

bool ESP32Manager::estaConectado() const
{
    return serial.isOpen();
}

QString ESP32Manager::portaAtual() const
{
    return serial.portName();
}

void ESP32Manager::enviarSenha(const QString &senha)
{
    if (!serial.isOpen()) {
        emit erro("ESP32 nao conectado.");
        return;
    }

    const QString comando = "SENHA:" + senha + "\n";
    serial.write(comando.toUtf8());
    serial.flush();
}

void ESP32Manager::enviarPing()
{
    if (!serial.isOpen()) {
        return;
    }

    serial.write("PING\n");
    serial.flush();
}

void ESP32Manager::desconectar()
{
    if (serial.isOpen()) {
        serial.close();
        emit desconectado();
    }
}

void ESP32Manager::lerDados()
{
    buffer.append(serial.readAll());

    while (buffer.contains('\n')) {
        const int pos = buffer.indexOf('\n');
        const QByteArray linhaBytes = buffer.left(pos);
        buffer.remove(0, pos + 1);

        const QString linha = QString::fromUtf8(linhaBytes).trimmed();
        if (!linha.isEmpty()) {
            processarLinha(linha);
        }
    }
}

void ESP32Manager::processarLinha(const QString &linha)
{
    emit mensagemRecebida(linha);

    if (linha.startsWith("OK:")) {
        emit senhaConfirmada(linha.mid(3));
    }
}
