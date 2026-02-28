// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vfdiv.h for the primary calling header

#ifndef VERILATED_VFDIV___024ROOT_H_
#define VERILATED_VFDIV___024ROOT_H_  // guard

#include "verilated.h"


class Vfdiv__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vfdiv___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(input_valid,0,0);
    VL_OUT8(out_valid,0,0);
    CData/*0:0*/ fdiv__DOT__a_is_nan;
    CData/*0:0*/ fdiv__DOT__b_is_nan;
    CData/*0:0*/ fdiv__DOT__a_is_inf;
    CData/*0:0*/ fdiv__DOT__b_is_inf;
    CData/*0:0*/ fdiv__DOT____Vlvbound_h228b8c1b__0;
    CData/*0:0*/ fdiv__DOT____Vlvbound_h1c8d4e6c__0;
    CData/*0:0*/ fdiv__DOT____Vlvbound_h04aaabe8__0;
    CData/*0:0*/ fdiv__DOT____Vlvbound_hcf786d1a__0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*9:0*/ fdiv__DOT__pipe_sign;
    SData/*9:0*/ fdiv__DOT__pipe_nan;
    SData/*9:0*/ fdiv__DOT__pipe_zero;
    SData/*9:0*/ fdiv__DOT__pipe_inf;
    SData/*9:0*/ fdiv__DOT__temp_exp;
    SData/*9:0*/ fdiv__DOT__unnamedblk1__DOT__calc_exp;
    SData/*9:0*/ fdiv__DOT____Vlvbound_h28476e50__0;
    SData/*9:0*/ fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val;
    VL_IN(input_a,31,0);
    VL_IN(input_b,31,0);
    VL_OUT(result,31,0);
    IData/*25:0*/ fdiv__DOT__temp_mantissa;
    IData/*24:0*/ fdiv__DOT__mantissa_rounded;
    IData/*25:0*/ fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
    IData/*25:0*/ fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
    IData/*23:0*/ fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
    IData/*25:0*/ fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
    IData/*25:0*/ fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
    IData/*25:0*/ fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
    IData/*23:0*/ fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*9:0*/, 10> fdiv__DOT__pipe_exponent;
    VlUnpacked<IData/*25:0*/, 10> fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem;
    VlUnpacked<IData/*25:0*/, 10> fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo;
    VlUnpacked<IData/*23:0*/, 10> fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vfdiv__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vfdiv___024root(Vfdiv__Syms* symsp, const char* v__name);
    ~Vfdiv___024root();
    VL_UNCOPYABLE(Vfdiv___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
