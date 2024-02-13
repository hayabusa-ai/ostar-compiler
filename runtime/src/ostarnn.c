#include "ostarnn.h"

#define Enum2String(ENUM) \
    case ENUM:            \
        return #ENUM;

const char* dtype2string(OstarDType type){
    switch(type){
        Enum2String(Ostar_FLOAT)
        Enum2String(Ostar_FLOAT16)
        Enum2String(Ostar_INT)
        Enum2String(Ostar_INT8)
        Enum2String(Ostar_INT16)
        Enum2String(Ostar_UINT8)
        Enum2String(Ostar_QINT8)
        Enum2String(Ostar_QINT32)
        Enum2String(Ostar_QUINT8)
        default: return "UNKNOW";
    }
}

const char* format2string(OstarFormat format){
    switch(format){
        Enum2String(Ostar_NCHW)
        Enum2String(Ostar_NHWC)
        Enum2String(Ostar_NCHW4)
        Enum2String(Ostar_NCHW8)
        Enum2String(Ostar_OIHW)
        default: return "UNKNOW";
    }
}