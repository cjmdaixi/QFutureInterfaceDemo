#ifndef FLUXHUB_H
#define FLUXHUB_H

#include <QObject>
#include <QRunnable>
#include <QThreadPool>
#include <QFutureInterface>
#include <QFuture>
#include <QtDebug>

class MyRunable : public QRunnable
{
public:
    MyRunable(QFutureInterface<QString> futureInterface)
        : m_futureInterface(futureInterface)
    {}
    MyRunable()
    {}
    QFuture<QString> future(){
        return m_futureInterface.future();
    }
    virtual void run() override;
private:
    QFutureInterface<QString> m_futureInterface;
    QString m_str;
};

class FluxHub : public QObject
{
    Q_OBJECT
public:
    explicit FluxHub(QObject *parent = nullptr);

signals:

public slots:
    void test();
};

#endif // FLUXHUB_H
