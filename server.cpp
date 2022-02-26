#include "server.h"


Server::Server(size_t threads, QObject * parent) :
    QTcpServer(parent),
    m_threadCount(threads),
    m_rrcounter(0)
{
    initThreads();
}

Server::~Server()
{
for(QThread* thread: m_threads)
{
    thread->quit();
    thread->wait();
}
}

void Server::initThreads()
{
    for (size_t i = 0; i < m_threadCount; ++i)
        {
            QThread* thread = new QThread(this);

            Worker* worker = new Worker();
            worker->moveToThread(thread);
            connect(thread, &QThread::finished,
                    worker, &QObject::deleteLater);

            m_threads.push_back(thread);
            m_workers.push_back(worker);

            thread->start();
        }
}

void Server::StartSetver()
{
    if (this->listen(QHostAddress::Any, 5555))
    {
        qDebug()<<"Ok";
    }
    else
    {
        qDebug()<<"Error";
    }


}

void Server::incomingConnection(qintptr socketDescriptor)
{
    Worker* worker = m_workers[m_rrcounter % m_threadCount];
       ++m_rrcounter;

       QMetaObject::invokeMethod(worker, "addClient",
               Qt::QueuedConnection,
               Q_ARG(qintptr, socketDescriptor));

//    socket=new QTcpSocket(this);
//    socket->setSocketDescriptor(socketDescriptor);

//    connect(socket, SIGNAL(readyRead()), this, SLOT(sockReady()));
//    connect(socket, SIGNAL(disconnected()), this, SLOT(sockDisc()));

//    qDebug()<<socketDescriptor<<"Client connected";

//    QJsonObject msgClient{
//      {"id",socketDescriptor},
//      {"msg","You are connected"},
//    };

//    auto msg=json.JsonInByteArr(msgClient);
//    socket->write(msg);

//    qDebug()<<"Send client connect status - YES";


}

void Server::sockReady()
{
//    QString str=socket->readAll();

//    send = new SendingLogic();
//    json.Read(str);
//    auto Code=json.Key("code").toString();

//    if(Code=="msg")
//    {
//        socket->write(str.toLatin1());
//    }
//    if(Code=="profile")
//    {
//        socket->write(send->CheckLogin(str));
//    }
//    if(Code=="msgForPerson")
//    {

//        socket->write(send->CheckLogin(str));
//    }
}

void Server::sockDisc()
{
    qDebug()<<"Disconnect";
    //socket->deleteLater();
}
