#ifndef DEVICE_H
#define DEVICE_H

#include "stdio.h"
#include "stdlib.h"
#include "ostarnn.h"

typedef struct {
    int alignment;
    OstarDevice device_type;
    void* (*malloc)(size_t length);
    void (*free)(void* ptr);

} Device;

typedef struct RuntimeOpt {
    const Device* device;
} RuntimeOpt;

OstarStatus init_device(Device* device);

RuntimeOpt create_runtime_opt(Device* device);

#endif