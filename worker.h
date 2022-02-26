#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include <client.h>

class Worker: public QObject
{
    Q_OBJECT
public:

    Q_INVOKABLE void addClient(qintptr socketDescriptor);
};

#endif // WORKER_H
