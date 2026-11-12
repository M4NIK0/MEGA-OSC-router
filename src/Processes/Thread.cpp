/*
** EPITECH PROJECT, 2026
** Thread.cpp
** File description:
** MEGA-OSC-router
*/

#include "Thread.hpp"

Thread::Thread(std::function<void()> task) : _task(std::move(task)), _stop(true) {}

Thread::~Thread() = default;

void Thread::start()
{
    if (!this->_task)
        return;

    this->_stop.store(false);

    // Start thread with loop looking for stop
    this->_thread = std::thread([this]() {
        while (!this->_stop.load()) {
            this->_task();
        }
    });
}

void Thread::stop()
{
    this->_stop.store(true);
    if (this->_thread.joinable()) {
        this->_thread.join();
    }
}
