#include "stdio.h"
#include "stdlib.h"

#include "data.h"
#include "device.h"

#define CPU_ALIGNMENT (16)

static void* cpu_aligned_malloc(size_t size) {
    if (size == 0) {
        return NULL;
    }
    void* raw_ptr = ostar_malloc(size + sizeof(void*) + CPU_ALIGNMENT);
    if (!raw_ptr) {
        LOG_ERROR("malloc memory fail.\n");
        return NULL;
    }
    void** ptr =
            (void**)(((size_t)raw_ptr + sizeof(void*) + CPU_ALIGNMENT - 1) & (-CPU_ALIGNMENT));
    ptr[-1] = raw_ptr;
    return ptr;
}

static void cpu_aligned_free(void* ptr) {
    void** raw_ptr = ((void**)(ptr))[-1];
    ostar_free(raw_ptr);
}

OstarStatus init_device(Device* device) {
    if (!device) {
        return Ostar_ERROR_NULL_PTR;
    }
    if (device->device_type == Ostar_ARM64 || device->device_type == Ostar_ARM32 ||
        device->device_type == Ostar_BARE_METAL) {
        device->alignment = CPU_ALIGNMENT;
        device->malloc = cpu_aligned_malloc;
        device->free = cpu_aligned_free;
    } else {
        LOG_ERROR("not support device.\n");
        return Ostar_ERROR_NO_IMPLEMENT;
    }
    return Ostar_SUCCESS;
}

RuntimeOpt create_runtime_opt(Device* device) {
    if (!device) {
        LOG_ERROR("not support device.\n");
    }
    RuntimeOpt opt;
    opt.device = device;
    return opt;
}