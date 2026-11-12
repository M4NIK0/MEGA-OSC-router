/*
** EPITECH PROJECT, 2026
** Packets.h
** File description:
** MEGA-OSC-router
*/

#pragma once
#include <cstddef>

class PacketData
{
    public:
        PacketData();
        ~PacketData();

        void *getData() const;
        std::size_t getSize() const;

    private:
        void *data;
        std::size_t size;
};

