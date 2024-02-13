#ifndef OSTARNN_H
#define OSTARNN_H

#include "stddef.h"
#include "stdint.h"

#define MAX_DIM (7)

typedef enum {
    Ostar_SUCCESS = 0,
    Ostar_ERROR_NULL_PTR = 1,
    Ostar_ERROR_STANDER = 2,
    Ostar_ERROR_RUNTIME = 3,
    Ostar_ERROR_OUT_OF_RANGE = 4,
    Ostar_ERROR_NO_FOUND = 5,
    Ostar_ERROR_NO_IMPLEMENT = 6,
    Ostar_ERROR_MODEL_PARSE = 7,
    Ostar_ERROR_OPEN_FILE_ERROR = 8,
    Ostar_ERROR_MEMORY_MALLOC = 9,
    Ostar_ERROR_UNSUPPORTED_INSTRUCTION_TYPE = 10,
    Ostar_ERROR_UNSUPPORTED_DTYPE_TYPE = 11,
    Ostar_ERROR_INVALID_LAYOUT = 12,
    Ostar_ERROR = 13,
} OstarStatus;

typedef enum {
    Ostar_FLOAT = 0,
    Ostar_FLOAT16 = 1,
    Ostar_INT = 2,
    Ostar_INT8 = 3,
    Ostar_INT16 = 4,
    Ostar_UINT8 = 5,
    Ostar_QINT8 = 100,
    Ostar_QINT32 = 101,
    Ostar_QUINT8 = 102,
} OstarDType;

typedef enum {
    Ostar_NCHW = 0,
    Ostar_NHWC,
    Ostar_NCHW4,
    Ostar_NCHW8,
    Ostar_OIHW,
} OstarFormat;

typedef enum {
    OstarNN_BARE_METAL = 0,
    OstarNN_ARM64,
    OstarNN_ARM32,
    OstarNN_ARM64_V82,
    OstarNN_ARM32_V82,
    OstarNN_OPENCL_MALI,
} OstarNNDevice;

const char* dtype2string(OstarNNDType type);
const char* format2string(OstarNNFormat format);

#endif