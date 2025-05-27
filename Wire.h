#ifndef WIRE_H
#define WIRE_H

#include <stdint.h>

class WireClass
{
public:
    void begin()
    {
        // pretend to start I2C (no real hardware)
    }

    void beginTransmission(uint8_t address)
    {
        // pretend to start communication to device at 'address'
    }

    void write(uint8_t data)
    {
        // pretend to send data byte
    }

    void endTransmission()
    {
        // pretend to end communication
    }
};

// Create one global Wire object like Arduino does
extern WireClass Wire;

#endif

