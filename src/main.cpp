#include <QCoreApplication>
#include <QDebug>

#include <boost/log/trivial.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication application(argc, argv);
    BOOST_LOG_TRIVIAL(info) << "MEGA OSC router";
    return 0;
}
