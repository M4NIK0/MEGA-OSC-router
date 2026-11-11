#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);
    qInfo() << "MEGA OSC router";
    return 0;
}
