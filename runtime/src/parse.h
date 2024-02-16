#ifndef PARSE_H
#define PARSE_H

#include "data_struct.h"
#include "stdio.h"
#include "ostarnn.h"

#include "model_reader.h"

#undef ns
#define ns(x) FLATBUFFERS_WRAP_NAMESPACE(Ostar, x)

static inline char* get_string(const char* in) {
    if (!in)
        return NULL;
    int len = strlen(in) + 1;
    char* ret = (char*)ostarnn_malloc(len + 1);
    strcpy(ret, in);
    return ret;
}

OstarNNStatus parse_tensor(Tensor* tensor, ns(Tensor_table_t) fbs_tensor, int tensor_id);

OstarNNStatus parse_weight(
        Tensor* weight, ns(Weight_table_t) fbs_weight, Device* host_dev);

OstarNNStatus parse_device_model(
        DeviceModel* model, CombineModel* c_model,
        ns(DeviceModel_table_t) device_model);

OstarNNStatus parse_model(
        void* buffer, size_t size, int is_own_buffer, CombineModel* model,
        int share_weights);

#endif