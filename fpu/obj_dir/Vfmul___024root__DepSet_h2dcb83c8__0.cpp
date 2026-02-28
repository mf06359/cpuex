// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfmul.h for the primary calling header

#include "Vfmul__pch.h"
#include "Vfmul___024root.h"

VL_INLINE_OPT void Vfmul___024root___ico_sequent__TOP__0(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___ico_sequent__TOP__0\n"); );
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
    // Body
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
}

void Vfmul___024root___eval_ico(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfmul___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfmul___024root___eval_triggers__ico(Vfmul___024root* vlSelf);

bool Vfmul___024root___eval_phase__ico(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfmul___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfmul___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfmul___024root___eval_act(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfmul___024root___nba_sequent__TOP__0(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___nba_sequent__TOP__0\n"); );
    // Init
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
    if (vlSelf->rst_n) {
        vlSelf->result = vlSelf->fmul__DOT__c3_result_comb;
        vlSelf->fmul__DOT__s1_exp_reg = vlSelf->fmul__DOT__c1_exp_temp;
        vlSelf->fmul__DOT__s1_prod_reg = vlSelf->fmul__DOT__c1_mant_prod;
        vlSelf->fmul__DOT__s2_mant_reg = vlSelf->fmul__DOT__c2_mant_norm;
        vlSelf->fmul__DOT__s2_exp_reg = vlSelf->fmul__DOT__c2_exp_adjusted;
    } else {
        vlSelf->result = 0U;
        vlSelf->fmul__DOT__s1_exp_reg = 0U;
        vlSelf->fmul__DOT__s1_prod_reg = 0ULL;
        vlSelf->fmul__DOT__s2_mant_reg = 0U;
        vlSelf->fmul__DOT__s2_exp_reg = 0U;
    }
    vlSelf->fmul__DOT__s2_sticky_reg = ((IData)(vlSelf->rst_n) 
                                        && (IData)(vlSelf->fmul__DOT__c2_sticky));
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->fmul__DOT__s2_valid_reg));
    vlSelf->fmul__DOT__s2_sign_reg = ((IData)(vlSelf->rst_n) 
                                      && (IData)(vlSelf->fmul__DOT__s1_sign_reg));
    vlSelf->fmul__DOT__s2_zero_reg = ((IData)(vlSelf->rst_n) 
                                      && (IData)(vlSelf->fmul__DOT__s1_zero_reg));
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
    vlSelf->fmul__DOT__s2_valid_reg = ((IData)(vlSelf->rst_n) 
                                       && (IData)(vlSelf->fmul__DOT__s1_valid_reg));
    vlSelf->fmul__DOT__s1_sign_reg = ((IData)(vlSelf->rst_n) 
                                      && (IData)(vlSelf->fmul__DOT__c1_sign_res));
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
    vlSelf->fmul__DOT__s1_zero_reg = ((IData)(vlSelf->rst_n) 
                                      && (IData)(vlSelf->fmul__DOT__c1_is_zero_or_sub));
    vlSelf->fmul__DOT__s1_valid_reg = ((IData)(vlSelf->rst_n) 
                                       && (IData)(vlSelf->input_valid));
}

void Vfmul___024root___eval_nba(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfmul___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfmul___024root___eval_triggers__act(Vfmul___024root* vlSelf);

bool Vfmul___024root___eval_phase__act(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfmul___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfmul___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfmul___024root___eval_phase__nba(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfmul___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__ico(Vfmul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__nba(Vfmul___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__act(Vfmul___024root* vlSelf);
#endif  // VL_DEBUG

void Vfmul___024root___eval(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vfmul___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fmul.sv", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfmul___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfmul___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fmul.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfmul___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fmul.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfmul___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfmul___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfmul___024root___eval_debug_assertions(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
