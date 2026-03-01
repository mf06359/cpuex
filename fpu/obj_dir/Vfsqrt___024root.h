// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfsqrt.h for the primary calling header

#ifndef VERILATED_VFSQRT___024ROOT_H_
#define VERILATED_VFSQRT___024ROOT_H_  // guard

#include "verilated.h"


class Vfsqrt__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfsqrt___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(input_valid,0,0);
    VL_OUT8(out_valid,0,0);
    CData/*3:0*/ fsqrt__DOT__valid_reg;
    CData/*2:0*/ fsqrt__DOT__is_zero_reg;
    CData/*2:0*/ fsqrt__DOT__is_abnormal_reg;
    CData/*7:0*/ fsqrt__DOT__exp_out;
    CData/*0:0*/ fsqrt__DOT__sign_out;
    CData/*7:0*/ fsqrt__DOT__exp_reg;
    CData/*0:0*/ fsqrt__DOT__sign_reg;
    CData/*7:0*/ fsqrt__DOT__exp_final;
    CData/*7:0*/ fsqrt__DOT__exp_final_reg;
    CData/*0:0*/ fsqrt__DOT__sign_final_reg;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(input_a,31,0);
    VL_OUT(result,31,0);
    IData/*23:0*/ fsqrt__DOT__a_fixed;
    IData/*23:0*/ fsqrt__DOT__x_0;
    IData/*23:0*/ fsqrt__DOT__x0_x0;
    IData/*23:0*/ fsqrt__DOT__double_x1;
    IData/*23:0*/ fsqrt__DOT__a_x0_reg;
    IData/*22:0*/ fsqrt__DOT__mant_final;
    IData/*31:0*/ __VactIterCount;
    QData/*47:0*/ fsqrt__DOT__mul_reg;
    VlUnpacked<IData/*23:0*/, 1024> fsqrt__DOT__lut;
    VlUnpacked<IData/*23:0*/, 1024> fsqrt__DOT__lut_sq;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfsqrt__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfsqrt___024root(Vfsqrt__Syms* symsp, const char* v__name);
    ~Vfsqrt___024root();
    VL_UNCOPYABLE(Vfsqrt___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
