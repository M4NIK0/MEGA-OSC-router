/*
** EPITECH PROJECT, 2026
** Thread.hpp
** File description:
** MEGA-OSC-router
*/

#pragma once

#include <thread>
#include <atomic>
#include <functional>
#include <utility>

// Thread
class Thread
{
    public:
        Thread(std::function<void()> task);
        ~Thread();

        void start();
        void stop();

    private:
        std::function<void()> _task;
        std::atomic<bool> _stop;
        std::thread _thread;
};
