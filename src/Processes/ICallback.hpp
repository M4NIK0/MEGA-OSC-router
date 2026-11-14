/*
** EPITECH PROJECT, 2026
** ICallback.hpp
** File description:
** MEGA-OSC-router
*/

#pragma once

#include <functional>
#include <hash_map>

class ICallback
{
    public:
        virtual ~ICallback() = default;

        virtual void *getData() = 0;
        virtual void setData(void *data) = 0;
        virtual std::function<void *()> getDataFunction() = 0;

    private:
};
