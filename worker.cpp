#include "worker.h"

void Worker::addClient(qintptr socketDescriptor)
{
    new Client(socketDescriptor, this);
}
