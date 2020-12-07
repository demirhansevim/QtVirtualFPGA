#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QThread>
#include <QProcess>
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTemporaryDir>

#include <iostream>

class Model : public QObject
{
    Q_OBJECT

public:
    Model(QString tmpDir,AbstractProcess process);
    ~Model();
    void initSocket();

private:
    bool modelRunning = 0;
    QString dataSent = "0 0";
    QUdpSocket *socket;
    QProcess model;
    QString tmpDir;
    AbstractProcess& process;



private slots:
    void recvData();

signals:
    void parseDataReceived(QString);

public slots:
    void stopModel();
    void setDataToSend(QString data);
    void compile(QStringList inputFileNames, QString simDelay, QString itPerCycle);
    void runModel();

};

#endif // MODEL_H
