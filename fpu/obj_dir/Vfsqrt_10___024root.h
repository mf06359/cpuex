// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfsqrt_10.h for the primary calling header

#ifndef VERILATED_VFSQRT_10___024ROOT_H_
#define VERILATED_VFSQRT_10___024ROOT_H_  // guard

#include "verilated.h"


class Vfsqrt_10__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfsqrt_10___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(input_valid,0,0);
    VL_OUT8(out_valid,0,0);
    CData/*7:0*/ fsqrt__DOT____Vlvbound_h3937421c__0;
    CData/*0:0*/ fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
    CData/*0:0*/ fsqrt__DOT____Vlvbound_h5f9d1add__0;
    CData/*0:0*/ fsqrt__DOT____Vlvbound_hd515fe4c__0;
    CData/*0:0*/ fsqrt__DOT____Vlvbound_hd7d92583__0;
    CData/*0:0*/ fsqrt__DOT____Vlvbound_hae105176__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(input_a,31,0);
    VL_OUT(result,31,0);
    IData/*31:0*/ fsqrt__DOT__final_result_comb;
    IData/*27:0*/ fsqrt__DOT____Vlvbound_hc6f81eba__0;
    IData/*31:0*/ __VactIterCount;
    QData/*53:0*/ fsqrt__DOT__unnamedblk1__DOT__term;
    QData/*54:0*/ fsqrt__DOT__unnamedblk1__DOT__diff;
    QData/*53:0*/ fsqrt__DOT____Vlvbound_h18df1d37__0;
    VlUnpacked<QData/*53:0*/, 10> fsqrt__DOT__pipe_rem;
    VlUnpacked<IData/*27:0*/, 10> fsqrt__DOT__pipe_root;
    VlUnpacked<CData/*7:0*/, 10> fsqrt__DOT__pipe_exp;
    VlUnpacked<CData/*0:0*/, 10> fsqrt__DOT__pipe_sign;
    VlUnpacked<CData/*0:0*/, 10> fsqrt__DOT__pipe_valid;
    VlUnpacked<CData/*0:0*/, 10> fsqrt__DOT__pipe_zero;
    VlUnpacked<CData/*0:0*/, 10> fsqrt__DOT__pipe_nan;
    VlUnpacked<CData/*0:0*/, 10> fsqrt__DOT__pipe_neg;
    VlUnpacked<QData/*53:0*/, 10> fsqrt__DOT__next_rem;
    VlUnpacked<IData/*27:0*/, 10> fsqrt__DOT__next_root;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfsqrt_10__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfsqrt_10___024root(Vfsqrt_10__Syms* symsp, const char* v__name);
    ~Vfsqrt_10___024root();
    VL_UNCOPYABLE(Vfsqrt_10___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
