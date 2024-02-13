#ifndef DATA_H
#define DATA_H

#include "device.h"
#include "stdio.h"
#include "stdlib.h"
#include "ostarnn.h"
#include "utils.h"

struct Instruction;

typedef struct {
    float scale;
    uint8_t zero_point;
} DTypeParam;

typedef struct {
    OstarDType type_enum;
    DTypeParam param;
} DType;

typedef struct {
    int nr_dim;
    uint32_t dims[MAX_DIM];
    int stride[MAX_DIM];
    OstarFormat format;
} Layout;

typedef struct {
    void* ptr;
    size_t length_in_byte;
} Memory;

typedef struct Tensor {
    char* name;
    DType dtype;
    Layout layout;
    void* ptr;
    size_t offset;
    int use_count;

    int is_weight;
    int is_dynamic;
    uint32_t checksum;
    size_t size;
    int is_shared;
    int is_input;
} Tensor;

typedef struct {
    void* ptr;
    size_t size;
    size_t offset;
} Workspace;

typedef struct {
    Tensor* tensors;
    int nr_tensor;

    Tensor* processed_weights;
    int nr_processed_weight;

    struct Instruction* instructions;
    int nr_instruction;

    Tensor** inputs;
    int nr_input;
    Tensor** outputs;
    int nr_output;

    int nr_threads;
    int have_init;
    Device device;
    RuntimeOpt opt;
} DeviceModel;

struct ComboIOTensorS;

typedef struct {
    Memory* max_tensor_memroy;
    int is_own_tensor_memory;
    Tensor* weights;
    int nr_origin_weight;

    DeviceModel** device_models;
    int nr_device_model;
    int active_device_model_idx;

    int have_init;
    char* name;
    int const_shape;
    size_t model_id;
    Device host_dev;

    void* model_ptr;
    size_t model_len;
    struct ComboIOTensorS* combo_iotensor;
    void* vm;
} CombineModel;

typedef struct ComboIOTensorS {
    Tensor** tensors;

    CombineModel* model;

    struct ComboIOTensorS* next;
} ComboIOTensor;

typedef OstarStatus (*KernelFunc)(
        Tensor** inputs, int nr_input, Tensor** outputs, int nr_output,
        const Workspace* workspace, const RuntimeOpt* opt);


typedef OstarStatus (*InitFunc)(
        Tensor** inputs, int nr_input, Tensor* out_weights, int* nr_out_weight,
        const RuntimeOpt* opt);

typedef OstarStatus (*WorkspaceFunc)(
        Tensor** inputs, int nr_input, int nr_thread, size_t* workspace);

typedef OstarStatus (*DeduceFunc)(
        Tensor** inputs, int nr_input, Tensor** outputs, int nr_output);
#endif