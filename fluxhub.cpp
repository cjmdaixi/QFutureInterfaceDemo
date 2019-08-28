#include "fluxhub.h"

void MyRunable::run()
{
    m_futureInterface.reportStarted();
    qDebug()<<"myrunnable begin running...";
    QThread::currentThread()->msleep(5000);
    qDebug()<<"myrunnable finish running...";
    m_str = "HelloWorld";
    m_futureInterface.reportResult(&m_str);
    m_futureInterface.reportFinished();
}

FluxHub::FluxHub(QObject *parent) : QObject(parent)
{

}

void FluxHub::test()
{
    auto myRunnable = new MyRunable();
    auto future = myRunnable->future();
    myRunnable->setAutoDelete(true);
    QThreadPool::globalInstance()->start(myRunnable);

    qDebug()<<"myrunner thread started...";
    future.waitForFinished();
    qDebug()<<"my future finished with value:"<<future.result();
}


