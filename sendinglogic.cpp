#include "sendinglogic.h"

SendingLogic::SendingLogic()
{

}

void SendingLogic::SendMsg(QByteArray &msg)
{

}

void SendingLogic::SendMsg(QString &msg)
{
    //socket->write(str.toLatin1());
}

QByteArray SendingLogic::CheckLogin(QString &msg)
{
    connection=new repository;

    if(!connection )
    {
        //return false;
    }
    JSONhelper json;
    if (connection->CheckUniqLogin(json.Key("login").toString())){
        QJsonObject msgClientQ  {
                                {"code","CheckUniqLogin"},
                                {"msg","login used"},
                                };

        QJsonArray jsarrayq {msgClientQ};
        QJsonDocument jsDocQ(jsarrayq);

        return QString::fromLatin1(jsDocQ.toJson()).toLatin1();
}


}

QByteArray SendingLogic::SendMsgToPerson(QString &msg)
{

}
