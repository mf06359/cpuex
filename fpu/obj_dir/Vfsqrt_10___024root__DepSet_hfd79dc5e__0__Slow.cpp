// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_10.h for the primary calling header

#include "Vfsqrt_10__pch.h"
#include "Vfsqrt_10___024root.h"

VL_ATTR_COLD void Vfsqrt_10___024root___eval_static(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfsqrt_10___024root___eval_initial(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vfsqrt_10___024root___eval_final(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__stl(Vfsqrt_10___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfsqrt_10___024root___eval_phase__stl(Vfsqrt_10___024root* vlSelf);

VL_ATTR_COLD void Vfsqrt_10___024root___eval_settle(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_settle\n"); );
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
            Vfsqrt_10___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fsqrt_10.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfsqrt_10___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__stl(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsqrt_10___024root___stl_sequent__TOP__0(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ fsqrt__DOT__unnamedblk1__DOT__j;
    fsqrt__DOT__unnamedblk1__DOT__j = 0;
    IData/*31:0*/ fsqrt__DOT__unnamedblk1__DOT__k_curr;
    fsqrt__DOT__unnamedblk1__DOT__k_curr = 0;
    IData/*31:0*/ fsqrt__DOT__unnamedblk1__DOT__loop_count;
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 0;
    QData/*53:0*/ fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = 0;
    IData/*27:0*/ fsqrt__DOT__unnamedblk1__DOT__cur_root;
    fsqrt__DOT__unnamedblk1__DOT__cur_root = 0;
    IData/*31:0*/ fsqrt__DOT__unnamedblk1__DOT__in_data;
    fsqrt__DOT__unnamedblk1__DOT__in_data = 0;
    CData/*7:0*/ fsqrt__DOT__unnamedblk1__DOT__in_exp;
    fsqrt__DOT__unnamedblk1__DOT__in_exp = 0;
    IData/*22:0*/ fsqrt__DOT__unnamedblk1__DOT__in_mant;
    fsqrt__DOT__unnamedblk1__DOT__in_mant = 0;
    QData/*53:0*/ fsqrt__DOT__unnamedblk1__DOT__mant_shifted;
    fsqrt__DOT__unnamedblk1__DOT__mant_shifted = 0;
    CData/*0:0*/ fsqrt__DOT__unnamedblk4__DOT__guard_bit;
    fsqrt__DOT__unnamedblk4__DOT__guard_bit = 0;
    CData/*0:0*/ fsqrt__DOT__unnamedblk4__DOT__round_bit;
    fsqrt__DOT__unnamedblk4__DOT__round_bit = 0;
    CData/*0:0*/ fsqrt__DOT__unnamedblk4__DOT__sticky_bit;
    fsqrt__DOT__unnamedblk4__DOT__sticky_bit = 0;
    CData/*0:0*/ fsqrt__DOT__unnamedblk4__DOT__lsb_bit;
    fsqrt__DOT__unnamedblk4__DOT__lsb_bit = 0;
    CData/*0:0*/ fsqrt__DOT__unnamedblk4__DOT__round_up;
    fsqrt__DOT__unnamedblk4__DOT__round_up = 0;
    IData/*22:0*/ fsqrt__DOT__unnamedblk4__DOT__frac_final;
    fsqrt__DOT__unnamedblk4__DOT__frac_final = 0;
    IData/*27:0*/ fsqrt__DOT__unnamedblk4__DOT__root_last;
    fsqrt__DOT__unnamedblk4__DOT__root_last = 0;
    QData/*53:0*/ fsqrt__DOT__unnamedblk4__DOT__rem_last;
    fsqrt__DOT__unnamedblk4__DOT__rem_last = 0;
    QData/*53:0*/ fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h183cc360__0 = 0;
    IData/*27:0*/ fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = 0;
    // Body
    fsqrt__DOT__unnamedblk4__DOT__root_last = vlSelf->fsqrt__DOT__pipe_root
        [9U];
    fsqrt__DOT__unnamedblk4__DOT__rem_last = vlSelf->fsqrt__DOT__pipe_rem
        [9U];
    fsqrt__DOT__unnamedblk4__DOT__guard_bit = (1U & 
                                               (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                >> 2U));
    fsqrt__DOT__unnamedblk4__DOT__round_bit = (1U & 
                                               (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                >> 1U));
    fsqrt__DOT__unnamedblk4__DOT__sticky_bit = (1U 
                                                & (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                   | (0ULL 
                                                      != fsqrt__DOT__unnamedblk4__DOT__rem_last)));
    fsqrt__DOT__unnamedblk4__DOT__lsb_bit = (1U & (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                   >> 3U));
    fsqrt__DOT__unnamedblk4__DOT__round_up = ((IData)(fsqrt__DOT__unnamedblk4__DOT__guard_bit) 
                                              & (((IData)(fsqrt__DOT__unnamedblk4__DOT__round_bit) 
                                                  | (IData)(fsqrt__DOT__unnamedblk4__DOT__sticky_bit)) 
                                                 | (IData)(fsqrt__DOT__unnamedblk4__DOT__lsb_bit)));
    fsqrt__DOT__unnamedblk4__DOT__frac_final = (0x7fffffU 
                                                & ((IData)(fsqrt__DOT__unnamedblk4__DOT__round_up)
                                                    ? 
                                                   ((IData)(1U) 
                                                    + 
                                                    (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                     >> 3U))
                                                    : 
                                                   (fsqrt__DOT__unnamedblk4__DOT__root_last 
                                                    >> 3U)));
    vlSelf->fsqrt__DOT__final_result_comb = ((vlSelf->fsqrt__DOT__pipe_nan
                                              [9U] 
                                              | vlSelf->fsqrt__DOT__pipe_neg
                                              [9U])
                                              ? 0x7fc00000U
                                              : (vlSelf->fsqrt__DOT__pipe_zero
                                                 [9U]
                                                  ? 
                                                 (vlSelf->fsqrt__DOT__pipe_sign
                                                  [9U] 
                                                  << 0x1fU)
                                                  : 
                                                 ((vlSelf->fsqrt__DOT__pipe_exp
                                                   [9U] 
                                                   << 0x17U) 
                                                  | fsqrt__DOT__unnamedblk4__DOT__frac_final)));
    fsqrt__DOT__unnamedblk1__DOT__in_data = vlSelf->input_a;
    fsqrt__DOT__unnamedblk1__DOT__in_exp = (0xffU & 
                                            (fsqrt__DOT__unnamedblk1__DOT__in_data 
                                             >> 0x17U));
    fsqrt__DOT__unnamedblk1__DOT__in_mant = (0x7fffffU 
                                             & fsqrt__DOT__unnamedblk1__DOT__in_data);
    fsqrt__DOT__unnamedblk1__DOT__mant_shifted = ((1U 
                                                   & (IData)(fsqrt__DOT__unnamedblk1__DOT__in_exp))
                                                   ? 
                                                  (0x10000000000000ULL 
                                                   | ((QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__in_mant)) 
                                                      << 0x1dU))
                                                   : 
                                                  (0x20000000000000ULL 
                                                   | ((QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__in_mant)) 
                                                      << 0x1eU)));
    fsqrt__DOT__unnamedblk1__DOT__k_curr = 0U;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = fsqrt__DOT__unnamedblk1__DOT__mant_shifted;
    fsqrt__DOT__unnamedblk1__DOT__cur_root = 0U;
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 4U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[0U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[0U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [0U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [0U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 3U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[1U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[1U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [1U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [1U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 4U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[2U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[2U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [2U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [2U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 3U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[3U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[3U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [3U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [3U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 3U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[4U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[4U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [4U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [4U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 2U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[5U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[5U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [5U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [5U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 2U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[6U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[6U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [6U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [6U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 2U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[7U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[7U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [7U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [7U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 2U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[8U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[8U] = fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT__unnamedblk1__DOT__cur_rem = vlSelf->fsqrt__DOT__pipe_rem
        [8U];
    fsqrt__DOT__unnamedblk1__DOT__cur_root = vlSelf->fsqrt__DOT__pipe_root
        [8U];
    fsqrt__DOT__unnamedblk1__DOT__loop_count = 2U;
    fsqrt__DOT__unnamedblk1__DOT__j = 0U;
    while (VL_LTS_III(32, fsqrt__DOT__unnamedblk1__DOT__j, fsqrt__DOT__unnamedblk1__DOT__loop_count)) {
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__term 
            = (0x3fffffffffffffULL & VL_SHIFTL_QQI(54,54,32, 
                                                   (1ULL 
                                                    | VL_SHIFTL_QQI(54,54,32, (QData)((IData)(fsqrt__DOT__unnamedblk1__DOT__cur_root)), 2U)), 
                                                   VL_MULS_III(32, (IData)(2U), 
                                                               ((IData)(0x1aU) 
                                                                - fsqrt__DOT__unnamedblk1__DOT__k_curr))));
        vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
            = (0x7fffffffffffffULL & (fsqrt__DOT__unnamedblk1__DOT__cur_rem 
                                      - vlSelf->fsqrt__DOT__unnamedblk1__DOT__term));
        if ((1U & (IData)((vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff 
                           >> 0x36U)))) {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & VL_SHIFTL_III(28,28,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U));
        } else {
            fsqrt__DOT__unnamedblk1__DOT__cur_root 
                = (0xfffffffU & (1U | VL_SHIFTL_III(28,32,32, fsqrt__DOT__unnamedblk1__DOT__cur_root, 1U)));
            fsqrt__DOT__unnamedblk1__DOT__cur_rem = 
                (0x3fffffffffffffULL & vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff);
        }
        fsqrt__DOT__unnamedblk1__DOT__k_curr = ((IData)(1U) 
                                                + fsqrt__DOT__unnamedblk1__DOT__k_curr);
        fsqrt__DOT__unnamedblk1__DOT__j = ((IData)(1U) 
                                           + fsqrt__DOT__unnamedblk1__DOT__j);
    }
    fsqrt__DOT____Vlvbound_h183cc360__0 = fsqrt__DOT__unnamedblk1__DOT__cur_rem;
    vlSelf->fsqrt__DOT__next_rem[9U] = fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = fsqrt__DOT__unnamedblk1__DOT__cur_root;
    vlSelf->fsqrt__DOT__next_root[9U] = fsqrt__DOT____Vlvbound_h163a4278__0;
}

VL_ATTR_COLD void Vfsqrt_10___024root___eval_stl(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfsqrt_10___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfsqrt_10___024root___eval_triggers__stl(Vfsqrt_10___024root* vlSelf);

VL_ATTR_COLD bool Vfsqrt_10___024root___eval_phase__stl(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfsqrt_10___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfsqrt_10___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__ico(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__act(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__nba(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsqrt_10___024root___ctor_var_reset(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->input_a = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_rem[__Vi0] = VL_RAND_RESET_Q(54);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_root[__Vi0] = VL_RAND_RESET_I(28);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_exp[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_sign[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_zero[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_nan[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__pipe_neg[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__next_rem[__Vi0] = VL_RAND_RESET_Q(54);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fsqrt__DOT__next_root[__Vi0] = VL_RAND_RESET_I(28);
    }
    vlSelf->fsqrt__DOT__final_result_comb = VL_RAND_RESET_I(32);
    vlSelf->fsqrt__DOT__unnamedblk1__DOT__term = VL_RAND_RESET_Q(54);
    vlSelf->fsqrt__DOT__unnamedblk1__DOT__diff = VL_RAND_RESET_Q(55);
    vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 = VL_RAND_RESET_Q(54);
    vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 = VL_RAND_RESET_I(28);
    vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 = VL_RAND_RESET_I(8);
    vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
