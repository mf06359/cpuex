// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_10.h for the primary calling header

#include "Vfsqrt_10__pch.h"
#include "Vfsqrt_10___024root.h"

VL_INLINE_OPT void Vfsqrt_10___024root___ico_sequent__TOP__0(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___ico_sequent__TOP__0\n"); );
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
    QData/*53:0*/ fsqrt__DOT____Vlvbound_h183cc360__0;
    fsqrt__DOT____Vlvbound_h183cc360__0 = 0;
    IData/*27:0*/ fsqrt__DOT____Vlvbound_h163a4278__0;
    fsqrt__DOT____Vlvbound_h163a4278__0 = 0;
    // Body
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

void Vfsqrt_10___024root___eval_ico(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfsqrt_10___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfsqrt_10___024root___eval_triggers__ico(Vfsqrt_10___024root* vlSelf);

bool Vfsqrt_10___024root___eval_phase__ico(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfsqrt_10___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfsqrt_10___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfsqrt_10___024root___eval_act(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfsqrt_10___024root___nba_sequent__TOP__0(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___nba_sequent__TOP__0\n"); );
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
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v0;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v0;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v0 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v1;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v1;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v1 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v2;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v2;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v2 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v3;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v3;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v3 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v4;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v4;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v4 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v5;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v5;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v5 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v6;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v6;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v6 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v7;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v7;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v7 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v8;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v8;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v8 = 0;
    QData/*53:0*/ __Vdlyvval__fsqrt__DOT__pipe_rem__v9;
    __Vdlyvval__fsqrt__DOT__pipe_rem__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v9;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_rem__v10;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v10 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v0;
    __Vdlyvval__fsqrt__DOT__pipe_root__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v0;
    __Vdlyvset__fsqrt__DOT__pipe_root__v0 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v1;
    __Vdlyvval__fsqrt__DOT__pipe_root__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v1;
    __Vdlyvset__fsqrt__DOT__pipe_root__v1 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v2;
    __Vdlyvval__fsqrt__DOT__pipe_root__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v2;
    __Vdlyvset__fsqrt__DOT__pipe_root__v2 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v3;
    __Vdlyvval__fsqrt__DOT__pipe_root__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v3;
    __Vdlyvset__fsqrt__DOT__pipe_root__v3 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v4;
    __Vdlyvval__fsqrt__DOT__pipe_root__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v4;
    __Vdlyvset__fsqrt__DOT__pipe_root__v4 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v5;
    __Vdlyvval__fsqrt__DOT__pipe_root__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v5;
    __Vdlyvset__fsqrt__DOT__pipe_root__v5 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v6;
    __Vdlyvval__fsqrt__DOT__pipe_root__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v6;
    __Vdlyvset__fsqrt__DOT__pipe_root__v6 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v7;
    __Vdlyvval__fsqrt__DOT__pipe_root__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v7;
    __Vdlyvset__fsqrt__DOT__pipe_root__v7 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v8;
    __Vdlyvval__fsqrt__DOT__pipe_root__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v8;
    __Vdlyvset__fsqrt__DOT__pipe_root__v8 = 0;
    IData/*27:0*/ __Vdlyvval__fsqrt__DOT__pipe_root__v9;
    __Vdlyvval__fsqrt__DOT__pipe_root__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v9;
    __Vdlyvset__fsqrt__DOT__pipe_root__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_root__v10;
    __Vdlyvset__fsqrt__DOT__pipe_root__v10 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v0;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v0;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v0 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v1;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v1;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v1 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v2;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v2;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v2 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v3;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v3;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v3 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v4;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v4;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v4 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v5;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v5;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v5 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v6;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v6;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v6 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v7;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v7;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v7 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v8;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v8;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v8 = 0;
    CData/*7:0*/ __Vdlyvval__fsqrt__DOT__pipe_exp__v9;
    __Vdlyvval__fsqrt__DOT__pipe_exp__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v9;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_exp__v10;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v10 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v0;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v0;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v0 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v1;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v1;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v1 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v2;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v2;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v2 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v3;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v3;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v3 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v4;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v4;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v4 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v5;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v5;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v5 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v6;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v6;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v6 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v7;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v7;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v7 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v8;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v8;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v8 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_sign__v9;
    __Vdlyvval__fsqrt__DOT__pipe_sign__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v9;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_sign__v10;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v10 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v0;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v0;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v0 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v1;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v1;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v1 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v2;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v2;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v2 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v3;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v3;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v3 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v4;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v4;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v4 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v5;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v5;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v5 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v6;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v6;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v6 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v7;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v7;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v7 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v8;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v8;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v8 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_neg__v9;
    __Vdlyvval__fsqrt__DOT__pipe_neg__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v9;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_neg__v10;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v10 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v0;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v0;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v0 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v1;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v1;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v1 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v2;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v2;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v2 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v3;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v3;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v3 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v4;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v4;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v4 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v5;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v5;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v5 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v6;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v6;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v6 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v7;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v7;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v7 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v8;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v8;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v8 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_valid__v9;
    __Vdlyvval__fsqrt__DOT__pipe_valid__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v9;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_valid__v10;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v10 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v0;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v0;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v0 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v1;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v1;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v1 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v2;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v2;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v2 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v3;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v3;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v3 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v4;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v4;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v4 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v5;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v5;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v5 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v6;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v6;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v6 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v7;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v7;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v7 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v8;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v8;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v8 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_zero__v9;
    __Vdlyvval__fsqrt__DOT__pipe_zero__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v9;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_zero__v10;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v10 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v0;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v0;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v0 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v1;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v1;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v1 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v2;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v2;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v2 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v3;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v3;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v3 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v4;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v4;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v4 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v5;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v5;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v5 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v6;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v6;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v6 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v7;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v7;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v7 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v8;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v8;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v8 = 0;
    CData/*0:0*/ __Vdlyvval__fsqrt__DOT__pipe_nan__v9;
    __Vdlyvval__fsqrt__DOT__pipe_nan__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v9;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fsqrt__DOT__pipe_nan__v10;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v10 = 0;
    // Body
    __Vdlyvset__fsqrt__DOT__pipe_valid__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_valid__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_nan__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_zero__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_neg__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_sign__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_exp__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_root__v10 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v0 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v1 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v2 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v3 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v4 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v5 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v6 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v7 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v8 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v9 = 0U;
    __Vdlyvset__fsqrt__DOT__pipe_rem__v10 = 0U;
    if (vlSelf->rst_n) {
        __Vdlyvval__fsqrt__DOT__pipe_valid__v0 = vlSelf->input_valid;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[0U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v1 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[1U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v2 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[2U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v3 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[3U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v4 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[4U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v5 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[5U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v6 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[6U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v7 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[7U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v8 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0 
            = vlSelf->fsqrt__DOT__pipe_valid[8U];
        __Vdlyvval__fsqrt__DOT__pipe_valid__v9 = vlSelf->fsqrt__DOT____Vlvbound_h5f9d1add__0;
        __Vdlyvset__fsqrt__DOT__pipe_valid__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_nan__v0 = (0xffU 
                                                == 
                                                (0xffU 
                                                 & (vlSelf->input_a 
                                                    >> 0x17U)));
        __Vdlyvset__fsqrt__DOT__pipe_nan__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[0U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v1 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[1U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v2 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[2U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v3 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[3U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v4 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[4U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v5 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[5U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v6 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[6U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v7 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[7U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v8 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0 
            = vlSelf->fsqrt__DOT__pipe_nan[8U];
        __Vdlyvval__fsqrt__DOT__pipe_nan__v9 = vlSelf->fsqrt__DOT____Vlvbound_hd7d92583__0;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_zero__v0 = (0U 
                                                 == 
                                                 (0x7fffffffU 
                                                  & vlSelf->input_a));
        __Vdlyvset__fsqrt__DOT__pipe_zero__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[0U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v1 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[1U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v2 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[2U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v3 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[3U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v4 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[4U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v5 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[5U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v6 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[6U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v7 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[7U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v8 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0 
            = vlSelf->fsqrt__DOT__pipe_zero[8U];
        __Vdlyvval__fsqrt__DOT__pipe_zero__v9 = vlSelf->fsqrt__DOT____Vlvbound_hd515fe4c__0;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_neg__v0 = ((vlSelf->input_a 
                                                 >> 0x1fU) 
                                                & (0U 
                                                   != 
                                                   (0x7fffffffU 
                                                    & vlSelf->input_a)));
        __Vdlyvset__fsqrt__DOT__pipe_neg__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[0U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v1 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[1U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v2 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[2U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v3 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[3U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v4 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[4U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v5 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[5U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v6 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[6U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v7 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[7U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v8 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hae105176__0 
            = vlSelf->fsqrt__DOT__pipe_neg[8U];
        __Vdlyvval__fsqrt__DOT__pipe_neg__v9 = vlSelf->fsqrt__DOT____Vlvbound_hae105176__0;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_sign__v0 = (vlSelf->input_a 
                                                 >> 0x1fU);
        __Vdlyvset__fsqrt__DOT__pipe_sign__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[0U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v1 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[1U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v2 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[2U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v3 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[3U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v4 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[4U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v5 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[5U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v6 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[6U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v7 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[7U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v8 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0 
            = vlSelf->fsqrt__DOT__pipe_sign[8U];
        __Vdlyvval__fsqrt__DOT__pipe_sign__v9 = vlSelf->fsqrt__DOT____Vlvbound_h2cbfc0a9__0;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_exp__v0 = (0xffU 
                                                & (((IData)(0x7fU) 
                                                    + 
                                                    (0xffU 
                                                     & (vlSelf->input_a 
                                                        >> 0x17U))) 
                                                   >> 1U));
        __Vdlyvset__fsqrt__DOT__pipe_exp__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[0U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v1 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[1U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v2 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[2U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v3 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[3U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v4 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[4U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v5 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[5U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v6 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[6U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v7 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[7U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v8 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0 
            = vlSelf->fsqrt__DOT__pipe_exp[8U];
        __Vdlyvval__fsqrt__DOT__pipe_exp__v9 = vlSelf->fsqrt__DOT____Vlvbound_h3937421c__0;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_root__v0 = vlSelf->fsqrt__DOT__next_root
            [0U];
        __Vdlyvset__fsqrt__DOT__pipe_root__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[1U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v1 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[2U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v2 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[3U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v3 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[4U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v4 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[5U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v5 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[6U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v6 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[7U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v7 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[8U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v8 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0 
            = vlSelf->fsqrt__DOT__next_root[9U];
        __Vdlyvval__fsqrt__DOT__pipe_root__v9 = vlSelf->fsqrt__DOT____Vlvbound_hc6f81eba__0;
        __Vdlyvset__fsqrt__DOT__pipe_root__v9 = 1U;
        __Vdlyvval__fsqrt__DOT__pipe_rem__v0 = vlSelf->fsqrt__DOT__next_rem
            [0U];
        __Vdlyvset__fsqrt__DOT__pipe_rem__v0 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[1U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v1 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v1 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[2U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v2 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v2 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[3U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v3 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v3 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[4U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v4 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v4 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[5U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v5 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v5 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[6U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v6 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v6 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[7U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v7 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v7 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[8U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v8 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v8 = 1U;
        vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0 
            = vlSelf->fsqrt__DOT__next_rem[9U];
        __Vdlyvval__fsqrt__DOT__pipe_rem__v9 = vlSelf->fsqrt__DOT____Vlvbound_h18df1d37__0;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v9 = 1U;
        vlSelf->result = vlSelf->fsqrt__DOT__final_result_comb;
    } else {
        __Vdlyvset__fsqrt__DOT__pipe_valid__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_nan__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_zero__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_neg__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_sign__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_exp__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_root__v10 = 1U;
        __Vdlyvset__fsqrt__DOT__pipe_rem__v10 = 1U;
        vlSelf->result = 0U;
    }
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && 
                         vlSelf->fsqrt__DOT__pipe_valid
                         [9U]);
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v0) {
        vlSelf->fsqrt__DOT__pipe_nan[0U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v1) {
        vlSelf->fsqrt__DOT__pipe_nan[1U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v2) {
        vlSelf->fsqrt__DOT__pipe_nan[2U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v3) {
        vlSelf->fsqrt__DOT__pipe_nan[3U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v4) {
        vlSelf->fsqrt__DOT__pipe_nan[4U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v5) {
        vlSelf->fsqrt__DOT__pipe_nan[5U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v6) {
        vlSelf->fsqrt__DOT__pipe_nan[6U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v7) {
        vlSelf->fsqrt__DOT__pipe_nan[7U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v8) {
        vlSelf->fsqrt__DOT__pipe_nan[8U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v9) {
        vlSelf->fsqrt__DOT__pipe_nan[9U] = __Vdlyvval__fsqrt__DOT__pipe_nan__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_nan__v10) {
        vlSelf->fsqrt__DOT__pipe_nan[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_nan[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v0) {
        vlSelf->fsqrt__DOT__pipe_zero[0U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v1) {
        vlSelf->fsqrt__DOT__pipe_zero[1U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v2) {
        vlSelf->fsqrt__DOT__pipe_zero[2U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v3) {
        vlSelf->fsqrt__DOT__pipe_zero[3U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v4) {
        vlSelf->fsqrt__DOT__pipe_zero[4U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v5) {
        vlSelf->fsqrt__DOT__pipe_zero[5U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v6) {
        vlSelf->fsqrt__DOT__pipe_zero[6U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v7) {
        vlSelf->fsqrt__DOT__pipe_zero[7U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v8) {
        vlSelf->fsqrt__DOT__pipe_zero[8U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v9) {
        vlSelf->fsqrt__DOT__pipe_zero[9U] = __Vdlyvval__fsqrt__DOT__pipe_zero__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_zero__v10) {
        vlSelf->fsqrt__DOT__pipe_zero[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_zero[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v0) {
        vlSelf->fsqrt__DOT__pipe_neg[0U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v1) {
        vlSelf->fsqrt__DOT__pipe_neg[1U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v2) {
        vlSelf->fsqrt__DOT__pipe_neg[2U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v3) {
        vlSelf->fsqrt__DOT__pipe_neg[3U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v4) {
        vlSelf->fsqrt__DOT__pipe_neg[4U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v5) {
        vlSelf->fsqrt__DOT__pipe_neg[5U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v6) {
        vlSelf->fsqrt__DOT__pipe_neg[6U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v7) {
        vlSelf->fsqrt__DOT__pipe_neg[7U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v8) {
        vlSelf->fsqrt__DOT__pipe_neg[8U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v9) {
        vlSelf->fsqrt__DOT__pipe_neg[9U] = __Vdlyvval__fsqrt__DOT__pipe_neg__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_neg__v10) {
        vlSelf->fsqrt__DOT__pipe_neg[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_neg[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v0) {
        vlSelf->fsqrt__DOT__pipe_sign[0U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v1) {
        vlSelf->fsqrt__DOT__pipe_sign[1U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v2) {
        vlSelf->fsqrt__DOT__pipe_sign[2U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v3) {
        vlSelf->fsqrt__DOT__pipe_sign[3U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v4) {
        vlSelf->fsqrt__DOT__pipe_sign[4U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v5) {
        vlSelf->fsqrt__DOT__pipe_sign[5U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v6) {
        vlSelf->fsqrt__DOT__pipe_sign[6U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v7) {
        vlSelf->fsqrt__DOT__pipe_sign[7U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v8) {
        vlSelf->fsqrt__DOT__pipe_sign[8U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v9) {
        vlSelf->fsqrt__DOT__pipe_sign[9U] = __Vdlyvval__fsqrt__DOT__pipe_sign__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_sign__v10) {
        vlSelf->fsqrt__DOT__pipe_sign[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_sign[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v0) {
        vlSelf->fsqrt__DOT__pipe_exp[0U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v1) {
        vlSelf->fsqrt__DOT__pipe_exp[1U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v2) {
        vlSelf->fsqrt__DOT__pipe_exp[2U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v3) {
        vlSelf->fsqrt__DOT__pipe_exp[3U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v4) {
        vlSelf->fsqrt__DOT__pipe_exp[4U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v5) {
        vlSelf->fsqrt__DOT__pipe_exp[5U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v6) {
        vlSelf->fsqrt__DOT__pipe_exp[6U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v7) {
        vlSelf->fsqrt__DOT__pipe_exp[7U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v8) {
        vlSelf->fsqrt__DOT__pipe_exp[8U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v9) {
        vlSelf->fsqrt__DOT__pipe_exp[9U] = __Vdlyvval__fsqrt__DOT__pipe_exp__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_exp__v10) {
        vlSelf->fsqrt__DOT__pipe_exp[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_exp[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v0) {
        vlSelf->fsqrt__DOT__pipe_root[0U] = __Vdlyvval__fsqrt__DOT__pipe_root__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v1) {
        vlSelf->fsqrt__DOT__pipe_root[1U] = __Vdlyvval__fsqrt__DOT__pipe_root__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v2) {
        vlSelf->fsqrt__DOT__pipe_root[2U] = __Vdlyvval__fsqrt__DOT__pipe_root__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v3) {
        vlSelf->fsqrt__DOT__pipe_root[3U] = __Vdlyvval__fsqrt__DOT__pipe_root__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v4) {
        vlSelf->fsqrt__DOT__pipe_root[4U] = __Vdlyvval__fsqrt__DOT__pipe_root__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v5) {
        vlSelf->fsqrt__DOT__pipe_root[5U] = __Vdlyvval__fsqrt__DOT__pipe_root__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v6) {
        vlSelf->fsqrt__DOT__pipe_root[6U] = __Vdlyvval__fsqrt__DOT__pipe_root__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v7) {
        vlSelf->fsqrt__DOT__pipe_root[7U] = __Vdlyvval__fsqrt__DOT__pipe_root__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v8) {
        vlSelf->fsqrt__DOT__pipe_root[8U] = __Vdlyvval__fsqrt__DOT__pipe_root__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v9) {
        vlSelf->fsqrt__DOT__pipe_root[9U] = __Vdlyvval__fsqrt__DOT__pipe_root__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_root__v10) {
        vlSelf->fsqrt__DOT__pipe_root[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_root[9U] = 0U;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v0) {
        vlSelf->fsqrt__DOT__pipe_rem[0U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v1) {
        vlSelf->fsqrt__DOT__pipe_rem[1U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v2) {
        vlSelf->fsqrt__DOT__pipe_rem[2U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v3) {
        vlSelf->fsqrt__DOT__pipe_rem[3U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v4) {
        vlSelf->fsqrt__DOT__pipe_rem[4U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v5) {
        vlSelf->fsqrt__DOT__pipe_rem[5U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v6) {
        vlSelf->fsqrt__DOT__pipe_rem[6U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v7) {
        vlSelf->fsqrt__DOT__pipe_rem[7U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v8) {
        vlSelf->fsqrt__DOT__pipe_rem[8U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v9) {
        vlSelf->fsqrt__DOT__pipe_rem[9U] = __Vdlyvval__fsqrt__DOT__pipe_rem__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_rem__v10) {
        vlSelf->fsqrt__DOT__pipe_rem[0U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[1U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[2U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[3U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[4U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[5U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[6U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[7U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[8U] = 0ULL;
        vlSelf->fsqrt__DOT__pipe_rem[9U] = 0ULL;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v0) {
        vlSelf->fsqrt__DOT__pipe_valid[0U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v0;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v1) {
        vlSelf->fsqrt__DOT__pipe_valid[1U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v1;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v2) {
        vlSelf->fsqrt__DOT__pipe_valid[2U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v2;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v3) {
        vlSelf->fsqrt__DOT__pipe_valid[3U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v3;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v4) {
        vlSelf->fsqrt__DOT__pipe_valid[4U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v4;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v5) {
        vlSelf->fsqrt__DOT__pipe_valid[5U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v5;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v6) {
        vlSelf->fsqrt__DOT__pipe_valid[6U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v6;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v7) {
        vlSelf->fsqrt__DOT__pipe_valid[7U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v7;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v8) {
        vlSelf->fsqrt__DOT__pipe_valid[8U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v8;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v9) {
        vlSelf->fsqrt__DOT__pipe_valid[9U] = __Vdlyvval__fsqrt__DOT__pipe_valid__v9;
    }
    if (__Vdlyvset__fsqrt__DOT__pipe_valid__v10) {
        vlSelf->fsqrt__DOT__pipe_valid[0U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[1U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[2U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[3U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[4U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[5U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[6U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[7U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[8U] = 0U;
        vlSelf->fsqrt__DOT__pipe_valid[9U] = 0U;
    }
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

void Vfsqrt_10___024root___eval_nba(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfsqrt_10___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfsqrt_10___024root___eval_triggers__act(Vfsqrt_10___024root* vlSelf);

bool Vfsqrt_10___024root___eval_phase__act(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfsqrt_10___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfsqrt_10___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfsqrt_10___024root___eval_phase__nba(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfsqrt_10___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__ico(Vfsqrt_10___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__nba(Vfsqrt_10___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_10___024root___dump_triggers__act(Vfsqrt_10___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsqrt_10___024root___eval(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval\n"); );
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
            Vfsqrt_10___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fsqrt_10.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfsqrt_10___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfsqrt_10___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fsqrt_10.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfsqrt_10___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fsqrt_10.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfsqrt_10___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfsqrt_10___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfsqrt_10___024root___eval_debug_assertions(Vfsqrt_10___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_10__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_10___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
