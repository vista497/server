#ifndef SENDINGLOGIC_H
#define SENDINGLOGIC_H

#include <QByteArray>
#include <QString>
#include "repository.h"
#include "jsonhelper.h"

class SendingLogic
{
    repository *connection;
public:
    SendingLogic();

    void SendMsg(QByteArray &msg);
    void SendMsg(QString &msg);

    QByteArray CheckLogin(QString &msg);
    QByteArray SendMsgToPerson(QString &msg);

};

#endif // SENDINGLOGIC_H
