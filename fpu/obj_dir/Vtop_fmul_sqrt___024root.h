// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_fmul_sqrt.h for the primary calling header

#ifndef VERILATED_VTOP_FMUL_SQRT___024ROOT_H_
#define VERILATED_VTOP_FMUL_SQRT___024ROOT_H_  // guard

#include "verilated.h"


class Vtop_fmul_sqrt__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_fmul_sqrt___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst_n,0,0);
        VL_IN8(input_valid,0,0);
        VL_OUT8(out_valid,0,0);
        CData/*2:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg;
        CData/*2:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus;
        CData/*2:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a;
        CData/*7:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb;
        CData/*0:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp;
        SData/*9:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg;
        SData/*9:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted;
        SData/*9:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg;
        SData/*9:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked;
        VL_IN(a,31,0);
        VL_IN(b,31,0);
        VL_OUT(result,31,0);
        IData/*31:0*/ top_fmul_sqrt__DOT__sqrt_res;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__double_x1;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg;
        IData/*17:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg;
        IData/*24:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner;
        IData/*22:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a;
        IData/*23:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b;
        IData/*26:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm;
        IData/*26:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg;
        IData/*31:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb;
        IData/*22:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final;
        IData/*31:0*/ __VactIterCount;
        QData/*47:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out;
        QData/*42:0*/ top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult;
    };
    struct {
        QData/*47:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod;
        QData/*47:0*/ top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg;
        VlUnpacked<IData/*23:0*/, 1024> top_fmul_sqrt__DOT__u_fsqrt__DOT__lut;
        VlUnpacked<IData/*23:0*/, 1024> top_fmul_sqrt__DOT__u_fsqrt__DOT__lut_sq;
        VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_fmul_sqrt__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop_fmul_sqrt___024root(Vtop_fmul_sqrt__Syms* symsp, const char* v__name);
    ~Vtop_fmul_sqrt___024root();
    VL_UNCOPYABLE(Vtop_fmul_sqrt___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
