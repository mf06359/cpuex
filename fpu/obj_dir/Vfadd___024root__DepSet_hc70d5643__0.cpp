// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfadd.h for the primary calling header

#include "Vfadd__pch.h"
#include "Vfadd___024root.h"

VL_INLINE_OPT void Vfadd___024root___ico_sequent__TOP__0(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ fadd__DOT__c1_diff;
    fadd__DOT__c1_diff = 0;
    IData/*26:0*/ fadd__DOT__c1_mant_small;
    fadd__DOT__c1_mant_small = 0;
    // Body
    if (((0x7fffffffU & vlSelf->input_a) < (0x7fffffffU 
                                            & vlSelf->input_b))) {
        vlSelf->fadd__DOT__c1_large = vlSelf->input_b;
        vlSelf->fadd__DOT__c1_small = vlSelf->input_a;
    } else {
        vlSelf->fadd__DOT__c1_large = vlSelf->input_a;
        vlSelf->fadd__DOT__c1_small = vlSelf->input_b;
    }
    vlSelf->fadd__DOT__c1_mant_large = ((0U == (0xffU 
                                                & (vlSelf->fadd__DOT__c1_large 
                                                   >> 0x17U)))
                                         ? (0x3fffff8U 
                                            & (vlSelf->fadd__DOT__c1_large 
                                               << 3U))
                                         : (0x4000000U 
                                            | (0x3fffff8U 
                                               & (vlSelf->fadd__DOT__c1_large 
                                                  << 3U))));
    fadd__DOT__c1_mant_small = ((0U == (0xffU & (vlSelf->fadd__DOT__c1_small 
                                                 >> 0x17U)))
                                 ? (0x3fffff8U & (vlSelf->fadd__DOT__c1_small 
                                                  << 3U))
                                 : (0x4000000U | (0x3fffff8U 
                                                  & (vlSelf->fadd__DOT__c1_small 
                                                     << 3U))));
    fadd__DOT__c1_diff = (0xffU & ((vlSelf->fadd__DOT__c1_large 
                                    >> 0x17U) - (vlSelf->fadd__DOT__c1_small 
                                                 >> 0x17U)));
    if ((0x1bU <= (IData)(fadd__DOT__c1_diff))) {
        vlSelf->fadd__DOT__c1_mant_small_shifted = 0U;
        vlSelf->fadd__DOT__c1_sticky = (0U != fadd__DOT__c1_mant_small);
    } else {
        vlSelf->fadd__DOT__c1_mant_small_shifted = 
            (0x7ffffffU & VL_SHIFTR_III(27,27,8, fadd__DOT__c1_mant_small, (IData)(fadd__DOT__c1_diff)));
        vlSelf->fadd__DOT__c1_sticky = (0U != (fadd__DOT__c1_mant_small 
                                               & (~ 
                                                  VL_SHIFTL_III(27,27,8, (IData)(0x7ffffffU), (IData)(fadd__DOT__c1_diff)))));
    }
    vlSelf->fadd__DOT__c1_mant_small_shifted = ((0x7fffffeU 
                                                 & vlSelf->fadd__DOT__c1_mant_small_shifted) 
                                                | (1U 
                                                   & (vlSelf->fadd__DOT__c1_mant_small_shifted 
                                                      | (IData)(vlSelf->fadd__DOT__c1_sticky))));
    vlSelf->fadd__DOT__c1_effective_op = ((vlSelf->fadd__DOT__c1_large 
                                           ^ vlSelf->fadd__DOT__c1_small) 
                                          >> 0x1fU);
    vlSelf->fadd__DOT__c1_sign_res = (vlSelf->fadd__DOT__c1_large 
                                      >> 0x1fU);
    vlSelf->fadd__DOT__c1_exp_res = (0xffU & (vlSelf->fadd__DOT__c1_large 
                                              >> 0x17U));
}

void Vfadd___024root___eval_ico(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfadd___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfadd___024root___eval_triggers__ico(Vfadd___024root* vlSelf);

bool Vfadd___024root___eval_phase__ico(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfadd___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfadd___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfadd___024root___eval_act(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfadd___024root___nba_sequent__TOP__0(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*27:0*/ fadd__DOT__c2_mant_res;
    fadd__DOT__c2_mant_res = 0;
    IData/*27:0*/ fadd__DOT__unnamedblk1__DOT__mant_final_shifted;
    fadd__DOT__unnamedblk1__DOT__mant_final_shifted = 0;
    CData/*7:0*/ fadd__DOT__unnamedblk1__DOT__exp_final;
    fadd__DOT__unnamedblk1__DOT__exp_final = 0;
    CData/*0:0*/ fadd__DOT__unnamedblk1__DOT__round_up;
    fadd__DOT__unnamedblk1__DOT__round_up = 0;
    CData/*0:0*/ fadd__DOT__unnamedblk1__DOT__guard;
    fadd__DOT__unnamedblk1__DOT__guard = 0;
    CData/*0:0*/ fadd__DOT__unnamedblk1__DOT__round;
    fadd__DOT__unnamedblk1__DOT__round = 0;
    CData/*0:0*/ fadd__DOT__unnamedblk1__DOT__sticky;
    fadd__DOT__unnamedblk1__DOT__sticky = 0;
    CData/*0:0*/ fadd__DOT__unnamedblk1__DOT__lsb;
    fadd__DOT__unnamedblk1__DOT__lsb = 0;
    // Body
    if (vlSelf->rst_n) {
        vlSelf->result = vlSelf->fadd__DOT__c3_result_comb;
        vlSelf->fadd__DOT__s1_exp_res_reg = vlSelf->fadd__DOT__c1_exp_res;
        vlSelf->fadd__DOT__s1_mant_small_shifted_reg 
            = vlSelf->fadd__DOT__c1_mant_small_shifted;
        vlSelf->fadd__DOT__s1_mant_large_reg = vlSelf->fadd__DOT__c1_mant_large;
        vlSelf->fadd__DOT__s2_exp_reg = vlSelf->fadd__DOT__c2_exp_adjusted;
        vlSelf->fadd__DOT__s2_shift_remain_reg = vlSelf->fadd__DOT__c2_shift_remain;
        vlSelf->fadd__DOT__s2_mant_reg = vlSelf->fadd__DOT__c2_mant_shifted_1;
    } else {
        vlSelf->result = 0U;
        vlSelf->fadd__DOT__s1_exp_res_reg = 0U;
        vlSelf->fadd__DOT__s1_mant_small_shifted_reg = 0U;
        vlSelf->fadd__DOT__s1_mant_large_reg = 0U;
        vlSelf->fadd__DOT__s2_exp_reg = 0U;
        vlSelf->fadd__DOT__s2_shift_remain_reg = 0U;
        vlSelf->fadd__DOT__s2_mant_reg = 0U;
    }
    vlSelf->fadd__DOT__s1_effective_op_reg = ((IData)(vlSelf->rst_n) 
                                              && (IData)(vlSelf->fadd__DOT__c1_effective_op));
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->fadd__DOT__s2_valid_reg));
    vlSelf->fadd__DOT__s2_sign_reg = ((IData)(vlSelf->rst_n) 
                                      && (IData)(vlSelf->fadd__DOT__s1_sign_res_reg));
    fadd__DOT__c2_mant_res = (0xfffffffU & ((IData)(vlSelf->fadd__DOT__s1_effective_op_reg)
                                             ? (vlSelf->fadd__DOT__s1_mant_large_reg 
                                                - vlSelf->fadd__DOT__s1_mant_small_shifted_reg)
                                             : (vlSelf->fadd__DOT__s1_mant_large_reg 
                                                + vlSelf->fadd__DOT__s1_mant_small_shifted_reg)));
    if ((0U == fadd__DOT__c2_mant_res)) {
        vlSelf->fadd__DOT__c2_exp_adjusted = 0U;
        vlSelf->fadd__DOT__c2_mant_shifted_1 = 0U;
        vlSelf->fadd__DOT__c2_shift_remain = 0U;
        vlSelf->fadd__DOT__c2_exp_adjusted = 0U;
    } else if ((0x8000000U & fadd__DOT__c2_mant_res)) {
        vlSelf->fadd__DOT__c2_mant_shifted_1 = (0xfffffffU 
                                                & VL_SHIFTR_III(28,28,32, fadd__DOT__c2_mant_res, 1U));
        vlSelf->fadd__DOT__c2_shift_remain = 0U;
        vlSelf->fadd__DOT__c2_exp_adjusted = (0xffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlSelf->fadd__DOT__s1_exp_res_reg)));
    } else {
        vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val 
            = fadd__DOT__c2_mant_res;
        {
            if ((0x4000000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
            if ((0x2000000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 1U;
                goto __Vlabel1;
            }
            if ((0x1000000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 2U;
                goto __Vlabel1;
            }
            if ((0x800000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 3U;
                goto __Vlabel1;
            }
            if ((0x400000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 4U;
                goto __Vlabel1;
            }
            if ((0x200000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 5U;
                goto __Vlabel1;
            }
            if ((0x100000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 6U;
                goto __Vlabel1;
            }
            if ((0x80000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 7U;
                goto __Vlabel1;
            }
            if ((0x40000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 8U;
                goto __Vlabel1;
            }
            if ((0x20000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 9U;
                goto __Vlabel1;
            }
            if ((0x10000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xaU;
                goto __Vlabel1;
            }
            if ((0x8000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xbU;
                goto __Vlabel1;
            }
            if ((0x4000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xcU;
                goto __Vlabel1;
            }
            if ((0x2000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xdU;
                goto __Vlabel1;
            }
            if ((0x1000U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xeU;
                goto __Vlabel1;
            }
            if ((0x800U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0xfU;
                goto __Vlabel1;
            }
            if ((0x400U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x10U;
                goto __Vlabel1;
            }
            if ((0x200U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x11U;
                goto __Vlabel1;
            }
            if ((0x100U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x12U;
                goto __Vlabel1;
            }
            if ((0x80U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x13U;
                goto __Vlabel1;
            }
            if ((0x40U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x14U;
                goto __Vlabel1;
            }
            if ((0x20U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x15U;
                goto __Vlabel1;
            }
            if ((0x10U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x16U;
                goto __Vlabel1;
            }
            if ((8U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x17U;
                goto __Vlabel1;
            }
            if ((4U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x18U;
                goto __Vlabel1;
            }
            if ((2U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x19U;
                goto __Vlabel1;
            }
            if ((1U & vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val)) {
                vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x1aU;
                goto __Vlabel1;
            }
            vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = 0x1bU;
            __Vlabel1: ;
        }
        vlSelf->fadd__DOT__c2_zlc = vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout;
        vlSelf->fadd__DOT__c2_exp_adjusted = (((IData)(vlSelf->fadd__DOT__s1_exp_res_reg) 
                                               < (IData)(vlSelf->fadd__DOT__c2_zlc))
                                               ? 0U
                                               : (0xffU 
                                                  & ((IData)(vlSelf->fadd__DOT__s1_exp_res_reg) 
                                                     - (IData)(vlSelf->fadd__DOT__c2_zlc))));
        vlSelf->fadd__DOT__c2_mant_shifted_1 = (0xfffffffU 
                                                & (fadd__DOT__c2_mant_res 
                                                   << 
                                                   (3U 
                                                    & (IData)(vlSelf->fadd__DOT__c2_zlc))));
        vlSelf->fadd__DOT__c2_shift_remain = (7U & 
                                              ((IData)(vlSelf->fadd__DOT__c2_zlc) 
                                               >> 2U));
    }
    vlSelf->fadd__DOT__s2_valid_reg = ((IData)(vlSelf->rst_n) 
                                       && (IData)(vlSelf->fadd__DOT__s1_valid_reg));
    fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
        = (0xfffffffU & (vlSelf->fadd__DOT__s2_mant_reg 
                         << ((IData)(vlSelf->fadd__DOT__s2_shift_remain_reg) 
                             << 2U)));
    fadd__DOT__unnamedblk1__DOT__guard = (1U & (fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
                                                >> 2U));
    fadd__DOT__unnamedblk1__DOT__round = (1U & (fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
                                                >> 1U));
    fadd__DOT__unnamedblk1__DOT__sticky = (1U & fadd__DOT__unnamedblk1__DOT__mant_final_shifted);
    fadd__DOT__unnamedblk1__DOT__lsb = (1U & (fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
                                              >> 3U));
    fadd__DOT__unnamedblk1__DOT__round_up = ((IData)(fadd__DOT__unnamedblk1__DOT__guard) 
                                             & (((IData)(fadd__DOT__unnamedblk1__DOT__round) 
                                                 | (IData)(fadd__DOT__unnamedblk1__DOT__sticky)) 
                                                | (IData)(fadd__DOT__unnamedblk1__DOT__lsb)));
    fadd__DOT__unnamedblk1__DOT__exp_final = vlSelf->fadd__DOT__s2_exp_reg;
    if ((0U == (IData)(vlSelf->fadd__DOT__s2_exp_reg))) {
        vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final = 0U;
        fadd__DOT__unnamedblk1__DOT__exp_final = 0U;
    } else if (fadd__DOT__unnamedblk1__DOT__round_up) {
        vlSelf->fadd__DOT__unnamedblk1__DOT__unnamedblk2__DOT__frac_rounded 
            = (0xffffffU & ((IData)(1U) + (0x7fffffU 
                                           & (fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
                                              >> 3U))));
        if ((0x800000U & vlSelf->fadd__DOT__unnamedblk1__DOT__unnamedblk2__DOT__frac_rounded)) {
            vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final = 0U;
            fadd__DOT__unnamedblk1__DOT__exp_final 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->fadd__DOT__s2_exp_reg)));
        } else {
            vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final 
                = (0x7fffffU & vlSelf->fadd__DOT__unnamedblk1__DOT__unnamedblk2__DOT__frac_rounded);
        }
    } else {
        vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & (fadd__DOT__unnamedblk1__DOT__mant_final_shifted 
                            >> 3U));
    }
    vlSelf->fadd__DOT__c3_result_comb = (((IData)(vlSelf->fadd__DOT__s2_sign_reg) 
                                          << 0x1fU) 
                                         | (((IData)(fadd__DOT__unnamedblk1__DOT__exp_final) 
                                             << 0x17U) 
                                            | vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final));
    vlSelf->fadd__DOT__s1_sign_res_reg = ((IData)(vlSelf->rst_n) 
                                          && (IData)(vlSelf->fadd__DOT__c1_sign_res));
    vlSelf->fadd__DOT__s1_valid_reg = ((IData)(vlSelf->rst_n) 
                                       && (IData)(vlSelf->input_valid));
}

void Vfadd___024root___eval_nba(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfadd___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfadd___024root___eval_triggers__act(Vfadd___024root* vlSelf);

bool Vfadd___024root___eval_phase__act(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfadd___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfadd___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfadd___024root___eval_phase__nba(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfadd___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__ico(Vfadd___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__nba(Vfadd___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__act(Vfadd___024root* vlSelf);
#endif  // VL_DEBUG

void Vfadd___024root___eval(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval\n"); );
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
            Vfadd___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fadd.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfadd___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfadd___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fadd.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfadd___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fadd.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfadd___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfadd___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfadd___024root___eval_debug_assertions(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
