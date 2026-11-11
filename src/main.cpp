#include <QApplication>
#include <QLabel>
#include <QWidget>

#include <boost/log/trivial.hpp>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    application.setApplicationName("MEGA OSC router");
    application.setApplicationVersion("0.1.0");

    BOOST_LOG_TRIVIAL(info) << "MEGA OSC router";

    QWidget window;
    window.setWindowTitle("MEGA OSC router");
    window.resize(640, 360);

    auto *label = new QLabel("MEGA OSC router", &window);
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 24px;");

    window.show();
    return application.exec();
}
