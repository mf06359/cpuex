// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfadd.h for the primary calling header

#include "Vfadd__pch.h"
#include "Vfadd___024root.h"

VL_ATTR_COLD void Vfadd___024root___eval_static(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfadd___024root___eval_initial(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vfadd___024root___eval_final(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__stl(Vfadd___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfadd___024root___eval_phase__stl(Vfadd___024root* vlSelf);

VL_ATTR_COLD void Vfadd___024root___eval_settle(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_settle\n"); );
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
            Vfadd___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fadd.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfadd___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__stl(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfadd___024root___stl_sequent__TOP__0(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ fadd__DOT__c1_diff;
    fadd__DOT__c1_diff = 0;
    IData/*26:0*/ fadd__DOT__c1_mant_small;
    fadd__DOT__c1_mant_small = 0;
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
}

VL_ATTR_COLD void Vfadd___024root___eval_stl(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfadd___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfadd___024root___eval_triggers__stl(Vfadd___024root* vlSelf);

VL_ATTR_COLD bool Vfadd___024root___eval_phase__stl(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfadd___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfadd___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfadd___024root___dump_triggers__ico(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfadd___024root___dump_triggers__act(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vfadd___024root___dump_triggers__nba(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfadd___024root___ctor_var_reset(Vfadd___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfadd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfadd___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->input_a = VL_RAND_RESET_I(32);
    vlSelf->input_b = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c1_large = VL_RAND_RESET_I(32);
    vlSelf->fadd__DOT__c1_small = VL_RAND_RESET_I(32);
    vlSelf->fadd__DOT__c1_mant_large = VL_RAND_RESET_I(27);
    vlSelf->fadd__DOT__c1_mant_small_shifted = VL_RAND_RESET_I(27);
    vlSelf->fadd__DOT__c1_sticky = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c1_effective_op = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c1_sign_res = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c1_exp_res = VL_RAND_RESET_I(8);
    vlSelf->fadd__DOT__s1_mant_large_reg = VL_RAND_RESET_I(27);
    vlSelf->fadd__DOT__s1_mant_small_shifted_reg = VL_RAND_RESET_I(27);
    vlSelf->fadd__DOT__s1_effective_op_reg = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__s1_sign_res_reg = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__s1_exp_res_reg = VL_RAND_RESET_I(8);
    vlSelf->fadd__DOT__s1_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c2_zlc = VL_RAND_RESET_I(5);
    vlSelf->fadd__DOT__c2_mant_shifted_1 = VL_RAND_RESET_I(28);
    vlSelf->fadd__DOT__c2_exp_adjusted = VL_RAND_RESET_I(8);
    vlSelf->fadd__DOT__c2_shift_remain = VL_RAND_RESET_I(3);
    vlSelf->fadd__DOT__s2_mant_reg = VL_RAND_RESET_I(28);
    vlSelf->fadd__DOT__s2_shift_remain_reg = VL_RAND_RESET_I(3);
    vlSelf->fadd__DOT__s2_exp_reg = VL_RAND_RESET_I(8);
    vlSelf->fadd__DOT__s2_sign_reg = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__s2_valid_reg = VL_RAND_RESET_I(1);
    vlSelf->fadd__DOT__c3_result_comb = VL_RAND_RESET_I(32);
    vlSelf->fadd__DOT__unnamedblk1__DOT__frac_final = VL_RAND_RESET_I(23);
    vlSelf->fadd__DOT__unnamedblk1__DOT__unnamedblk2__DOT__frac_rounded = VL_RAND_RESET_I(24);
    vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__Vfuncout = VL_RAND_RESET_I(5);
    vlSelf->__Vfunc_fadd__DOT__count_leading_zeros__0__val = VL_RAND_RESET_I(28);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
