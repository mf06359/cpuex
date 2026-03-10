// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_fmul_sqrt.h for the primary calling header

#include "Vtop_fmul_sqrt__pch.h"
#include "Vtop_fmul_sqrt___024root.h"

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_static(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_initial__TOP(Vtop_fmul_sqrt___024root* vlSelf);

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_initial(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_initial\n"); );
    // Body
    Vtop_fmul_sqrt___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_initial__TOP(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e6d656dU;
    __Vtemp_1[1U] = 0x61626c65U;
    __Vtemp_1[2U] = 0x72745f74U;
    __Vtemp_1[3U] = 0x667371U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 24, 1024, 0, std::string{"zero.mem"}
                 ,  &(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut_sq)
                 , 0, ~0ULL);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_final(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__stl(Vtop_fmul_sqrt___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_fmul_sqrt___024root___eval_phase__stl(Vtop_fmul_sqrt___024root* vlSelf);

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_settle(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtop_fmul_sqrt___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("top_fmul_sqrt.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtop_fmul_sqrt___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__stl(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___stl_sequent__TOP__0(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((1U & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                       >> 0x2fU)))) {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm 
            = (0x7ffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                                     >> 0x14U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky 
            = (0U != (0xfffffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg)));
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm 
            = (0x7ffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                                     >> 0x13U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky 
            = (0U != (0x7ffffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted 
            = (0x3ffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg));
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a 
        = (vlSelf->a >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b 
        = (vlSelf->top_fmul_sqrt__DOT__sqrt_res >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a) 
           ^ (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg;
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult 
        = (0x7ffffffffffULL & VL_MULS_QQQ(43, (0x7ffffffffffULL 
                                               & VL_EXTENDS_QI(43,25, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed)), 
                                          (0x7ffffffffffULL 
                                           & VL_EXTENDS_QI(43,18, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg))));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out 
        = (0xffffffffffffULL & ((0x200000ULL | ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg)) 
                                                << 0x17U)) 
                                + VL_EXTENDS_QQ(48,43, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult)));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner 
        = (0xffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out 
                                >> 0x16U)));
    if ((0x800000U & vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner)) {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final 
            = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final 
            = (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner);
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final 
            = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final 
            = (0x7ffffeU & (vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner 
                            << 1U));
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a 
        = (0xffU & (vlSelf->a >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b 
        = (0xffU & (vlSelf->top_fmul_sqrt__DOT__sqrt_res 
                    >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a))
            ? (0x7fffffU & vlSelf->a) : (0x800000U 
                                         | (0x7fffffU 
                                            & vlSelf->a)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b))
            ? (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)
            : (0x800000U | (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a)) 
           | (0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp 
        = (0x3ffU & (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a) 
                      + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)) 
                     - (IData)(0x7fU)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod 
        = (0xffffffffffffULL & ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a)) 
                                * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b))));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 3U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 2U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg) 
           | (0U != (3U & vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 4U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard) 
           & (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round) 
               | (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky)) 
              | (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb)));
    if (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up) {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & ((IData)(1U) + (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                                           >> 4U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked 
            = (0x3ffU & ((0U == vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final)
                          ? ((IData)(1U) + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg))
                          : (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg)));
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                            >> 4U));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg;
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb 
        = (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg) 
            | ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked) 
               >> 9U)) ? ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                          << 0x1fU) : ((0xffU <= (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked))
                                        ? (0x7f800000U 
                                           | ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                                              << 0x1fU))
                                        : (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                                            << 0x1fU) 
                                           | ((0x7f800000U 
                                               & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked) 
                                                  << 0x17U)) 
                                              | vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final))));
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_stl(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtop_fmul_sqrt___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___eval_triggers__stl(Vtop_fmul_sqrt___024root* vlSelf);

VL_ATTR_COLD bool Vtop_fmul_sqrt___024root___eval_phase__stl(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtop_fmul_sqrt___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtop_fmul_sqrt___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__ico(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__act(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__nba(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_fmul_sqrt___024root___ctor_var_reset(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->a = VL_RAND_RESET_I(32);
    vlSelf->b = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__sqrt_res = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut[__Vi0] = VL_RAND_RESET_I(24);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut_sq[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg = VL_RAND_RESET_I(3);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg = VL_RAND_RESET_I(3);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out = VL_RAND_RESET_Q(48);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__double_x1 = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg = VL_RAND_RESET_I(3);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0 = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0 = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg = VL_RAND_RESET_I(18);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed = VL_RAND_RESET_I(25);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult = VL_RAND_RESET_Q(43);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final = VL_RAND_RESET_I(23);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b = VL_RAND_RESET_I(8);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b = VL_RAND_RESET_I(24);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp = VL_RAND_RESET_I(10);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod = VL_RAND_RESET_Q(48);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg = VL_RAND_RESET_I(10);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg = VL_RAND_RESET_Q(48);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted = VL_RAND_RESET_I(10);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm = VL_RAND_RESET_I(27);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg = VL_RAND_RESET_I(10);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg = VL_RAND_RESET_I(27);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb = VL_RAND_RESET_I(32);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up = VL_RAND_RESET_I(1);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final = VL_RAND_RESET_I(23);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
