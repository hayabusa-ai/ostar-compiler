#pragma once
#include "AutoKernelFunc.h"

namespace ostar {
namespace codegen {

struct MatmulKernel : public AutoKernelFuncInternal {
    bool IsAvailable(TContext* context) const override;
    std::string GetKernelSymbol(TContext* context) const override;
    void CreateCompute(
            mlir::Block* entryBlock, mlir::OpBuilder& op_builder,
            mlir::MLIRContext* ctx, TContext* context) const override;
    void CreatePass(mlir::PassManager& pm, mlir::MLIRContext* ctx, TContext* context)
            const override;
};

} 
}  