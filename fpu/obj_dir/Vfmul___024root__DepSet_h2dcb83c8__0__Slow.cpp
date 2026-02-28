// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfmul.h for the primary calling header

#include "Vfmul__pch.h"
#include "Vfmul___024root.h"

VL_ATTR_COLD void Vfmul___024root___eval_static(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfmul___024root___eval_initial(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vfmul___024root___eval_final(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__stl(Vfmul___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfmul___024root___eval_phase__stl(Vfmul___024root* vlSelf);

VL_ATTR_COLD void Vfmul___024root___eval_settle(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_settle\n"); );
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
            Vfmul___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fmul.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfmul___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__stl(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfmul___024root___stl_sequent__TOP__0(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ fmul__DOT__s1_sign_a;
    fmul__DOT__s1_sign_a = 0;
    CData/*0:0*/ fmul__DOT__s1_sign_b;
    fmul__DOT__s1_sign_b = 0;
    CData/*7:0*/ fmul__DOT__s1_exp_a;
    fmul__DOT__s1_exp_a = 0;
    CData/*7:0*/ fmul__DOT__s1_exp_b;
    fmul__DOT__s1_exp_b = 0;
    IData/*23:0*/ fmul__DOT__s1_mant_a;
    fmul__DOT__s1_mant_a = 0;
    IData/*23:0*/ fmul__DOT__s1_mant_b;
    fmul__DOT__s1_mant_b = 0;
    CData/*0:0*/ fmul__DOT__unnamedblk1__DOT__guard;
    fmul__DOT__unnamedblk1__DOT__guard = 0;
    CData/*0:0*/ fmul__DOT__unnamedblk1__DOT__round;
    fmul__DOT__unnamedblk1__DOT__round = 0;
    CData/*0:0*/ fmul__DOT__unnamedblk1__DOT__sticky;
    fmul__DOT__unnamedblk1__DOT__sticky = 0;
    CData/*0:0*/ fmul__DOT__unnamedblk1__DOT__lsb;
    fmul__DOT__unnamedblk1__DOT__lsb = 0;
    CData/*0:0*/ fmul__DOT__unnamedblk1__DOT__round_up;
    fmul__DOT__unnamedblk1__DOT__round_up = 0;
    // Body
    if ((1U & (IData)((vlSelf->fmul__DOT__s1_prod_reg 
                       >> 0x2fU)))) {
        vlSelf->fmul__DOT__c2_mant_norm = (0x7ffffffU 
                                           & (IData)(
                                                     (vlSelf->fmul__DOT__s1_prod_reg 
                                                      >> 0x14U)));
        vlSelf->fmul__DOT__c2_sticky = (0U != (0xfffffU 
                                               & (IData)(vlSelf->fmul__DOT__s1_prod_reg)));
        vlSelf->fmul__DOT__c2_exp_adjusted = (0x3ffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->fmul__DOT__s1_exp_reg)));
    } else {
        vlSelf->fmul__DOT__c2_mant_norm = (0x7ffffffU 
                                           & (IData)(
                                                     (vlSelf->fmul__DOT__s1_prod_reg 
                                                      >> 0x13U)));
        vlSelf->fmul__DOT__c2_sticky = (0U != (0x7ffffU 
                                               & (IData)(vlSelf->fmul__DOT__s1_prod_reg)));
        vlSelf->fmul__DOT__c2_exp_adjusted = (0x3ffU 
                                              & (IData)(vlSelf->fmul__DOT__s1_exp_reg));
    }
    fmul__DOT__s1_sign_a = (vlSelf->input_a >> 0x1fU);
    fmul__DOT__s1_sign_b = (vlSelf->input_b >> 0x1fU);
    vlSelf->fmul__DOT__c1_sign_res = ((IData)(fmul__DOT__s1_sign_a) 
                                      ^ (IData)(fmul__DOT__s1_sign_b));
    fmul__DOT__s1_exp_a = (0xffU & (vlSelf->input_a 
                                    >> 0x17U));
    fmul__DOT__s1_exp_b = (0xffU & (vlSelf->input_b 
                                    >> 0x17U));
    fmul__DOT__s1_mant_a = ((0U == (IData)(fmul__DOT__s1_exp_a))
                             ? (0x7fffffU & vlSelf->input_a)
                             : (0x800000U | (0x7fffffU 
                                             & vlSelf->input_a)));
    fmul__DOT__s1_mant_b = ((0U == (IData)(fmul__DOT__s1_exp_b))
                             ? (0x7fffffU & vlSelf->input_b)
                             : (0x800000U | (0x7fffffU 
                                             & vlSelf->input_b)));
    vlSelf->fmul__DOT__c1_is_zero_or_sub = ((0U == (IData)(fmul__DOT__s1_exp_a)) 
                                            | (0U == (IData)(fmul__DOT__s1_exp_b)));
    vlSelf->fmul__DOT__c1_exp_temp = (0x3ffU & (((IData)(fmul__DOT__s1_exp_a) 
                                                 + (IData)(fmul__DOT__s1_exp_b)) 
                                                - (IData)(0x7fU)));
    vlSelf->fmul__DOT__c1_mant_prod = (0xffffffffffffULL 
                                       & ((QData)((IData)(fmul__DOT__s1_mant_a)) 
                                          * (QData)((IData)(fmul__DOT__s1_mant_b))));
    fmul__DOT__unnamedblk1__DOT__guard = (1U & (vlSelf->fmul__DOT__s2_mant_reg 
                                                >> 3U));
    fmul__DOT__unnamedblk1__DOT__round = (1U & (vlSelf->fmul__DOT__s2_mant_reg 
                                                >> 2U));
    fmul__DOT__unnamedblk1__DOT__sticky = ((IData)(vlSelf->fmul__DOT__s2_sticky_reg) 
                                           | (0U != 
                                              (3U & vlSelf->fmul__DOT__s2_mant_reg)));
    fmul__DOT__unnamedblk1__DOT__lsb = (1U & (vlSelf->fmul__DOT__s2_mant_reg 
                                              >> 4U));
    fmul__DOT__unnamedblk1__DOT__round_up = ((IData)(fmul__DOT__unnamedblk1__DOT__guard) 
                                             & (((IData)(fmul__DOT__unnamedblk1__DOT__round) 
                                                 | (IData)(fmul__DOT__unnamedblk1__DOT__sticky)) 
                                                | (IData)(fmul__DOT__unnamedblk1__DOT__lsb)));
    if (fmul__DOT__unnamedblk1__DOT__round_up) {
        vlSelf->fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & ((IData)(1U) + (vlSelf->fmul__DOT__s2_mant_reg 
                                           >> 4U)));
        vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked 
            = (0x3ffU & ((0U == vlSelf->fmul__DOT__unnamedblk1__DOT__frac_final)
                          ? ((IData)(1U) + (IData)(vlSelf->fmul__DOT__s2_exp_reg))
                          : (IData)(vlSelf->fmul__DOT__s2_exp_reg)));
    } else {
        vlSelf->fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & (vlSelf->fmul__DOT__s2_mant_reg 
                            >> 4U));
        vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked 
            = vlSelf->fmul__DOT__s2_exp_reg;
    }
    vlSelf->fmul__DOT__c3_result_comb = (((IData)(vlSelf->fmul__DOT__s2_zero_reg) 
                                          | ((IData)(vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked) 
                                             >> 9U))
                                          ? ((IData)(vlSelf->fmul__DOT__s2_sign_reg) 
                                             << 0x1fU)
                                          : ((0xffU 
                                              <= (IData)(vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked))
                                              ? (0x7f800000U 
                                                 | ((IData)(vlSelf->fmul__DOT__s2_sign_reg) 
                                                    << 0x1fU))
                                              : (((IData)(vlSelf->fmul__DOT__s2_sign_reg) 
                                                  << 0x1fU) 
                                                 | ((0x7f800000U 
                                                     & ((IData)(vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked) 
                                                        << 0x17U)) 
                                                    | vlSelf->fmul__DOT__unnamedblk1__DOT__frac_final))));
}

VL_ATTR_COLD void Vfmul___024root___eval_stl(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfmul___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfmul___024root___eval_triggers__stl(Vfmul___024root* vlSelf);

VL_ATTR_COLD bool Vfmul___024root___eval_phase__stl(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfmul___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfmul___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__ico(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfmul___024root___dump_triggers__act(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vfmul___024root___dump_triggers__nba(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfmul___024root___ctor_var_reset(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->input_a = VL_RAND_RESET_I(32);
    vlSelf->input_b = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__c1_sign_res = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__c1_exp_temp = VL_RAND_RESET_I(10);
    vlSelf->fmul__DOT__c1_mant_prod = VL_RAND_RESET_Q(48);
    vlSelf->fmul__DOT__c1_is_zero_or_sub = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s1_sign_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s1_exp_reg = VL_RAND_RESET_I(10);
    vlSelf->fmul__DOT__s1_prod_reg = VL_RAND_RESET_Q(48);
    vlSelf->fmul__DOT__s1_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s1_zero_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__c2_exp_adjusted = VL_RAND_RESET_I(10);
    vlSelf->fmul__DOT__c2_sticky = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__c2_mant_norm = VL_RAND_RESET_I(27);
    vlSelf->fmul__DOT__s2_sign_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s2_exp_reg = VL_RAND_RESET_I(10);
    vlSelf->fmul__DOT__s2_mant_reg = VL_RAND_RESET_I(27);
    vlSelf->fmul__DOT__s2_sticky_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s2_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__s2_zero_reg = VL_RAND_RESET_I(1);
    vlSelf->fmul__DOT__c3_result_comb = VL_RAND_RESET_I(32);
    vlSelf->fmul__DOT__unnamedblk1__DOT__frac_final = VL_RAND_RESET_I(23);
    vlSelf->fmul__DOT__unnamedblk1__DOT__exp_checked = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
