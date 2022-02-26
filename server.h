#ifndef SERVER_H
#define SERVER_H

#include "worker.h"
#include <QThreadPool>
#include <QTcpServer>
//#include <QTcpSocket>
#include <QDebug>
#include "jsonhelper.h"
#include "sendinglogic.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Server: public QTcpServer
{
    Q_OBJECT

    JSONhelper json;
    SendingLogic *send;
    QThreadPool *threadPool;


    size_t m_threadCount;

    QVector<QThread*> m_threads;
    QVector<Worker*> m_workers;
    size_t m_rrcounter;
public:
    Server(size_t threads = 4, QObject * parent = nullptr);
    ~Server();

    //QTcpSocket *socket;
    QByteArray Data;

    QString *msgServer;

private:
    void initThreads();


public slots:
    void StartSetver();

    void sockReady();
    void sockDisc();

protected:
    void incomingConnection(qintptr socketDescriptor) ;

};

#endif // SERVER_H
