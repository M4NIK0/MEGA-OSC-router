#include <iostream>
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <oscpp/client.hpp>

#include <boost/log/trivial.hpp>

#include "Processes/Thread.hpp"

int main(int argc, char *argv[])
{
    // QApplication application(argc, argv);
    // application.setApplicationName("MEGA OSC router");
    // application.setApplicationVersion("0.1.0");
    //
    // BOOST_LOG_TRIVIAL(info) << "MEGA OSC router";
    //
    // QWidget window;
    // window.setWindowTitle("MEGA OSC router");
    // window.resize(640, 360);
    //
    // auto *label = new QLabel("MEGA OSC router", &window);
    // label->setAlignment(Qt::AlignCenter);
    // label->setStyleSheet("font-size: 24px;");
    //
    // window.show();
    // return application.exec();

    Thread testThread([]() {
        std::cout << "Test thread" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });

    Thread testThread2([]() {
        std::cout << "Test thread 2" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });

    testThread.start();
    testThread2.start();
    for (auto i: {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}) {
        std::cout << "Main thread: " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    testThread.stop();
    testThread2.stop();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Test thread 2 stopped" << std::endl;
}
