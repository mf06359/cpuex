// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfdiv.h for the primary calling header

#include "Vfdiv__pch.h"
#include "Vfdiv___024root.h"

VL_INLINE_OPT void Vfdiv___024root___ico_sequent__TOP__0(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->fdiv__DOT__a_is_nan = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelf->input_a)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelf->input_a))));
    vlSelf->fdiv__DOT__a_is_inf = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelf->input_a)));
    vlSelf->fdiv__DOT__b_is_nan = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelf->input_b)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelf->input_b))));
    vlSelf->fdiv__DOT__b_is_inf = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelf->input_b)));
}

void Vfdiv___024root___eval_ico(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vfdiv___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vfdiv___024root___eval_triggers__ico(Vfdiv___024root* vlSelf);

bool Vfdiv___024root___eval_phase__ico(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vfdiv___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vfdiv___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vfdiv___024root___eval_act(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfdiv___024root___nba_sequent__TOP__0(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdly__fdiv__DOT__pipe_sign;
    __Vdly__fdiv__DOT__pipe_sign = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v0;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v0;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v0 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v1;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v1;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v1 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v2;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v2;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v2 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v3;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v3;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v3 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v4;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v4;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v4 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v5;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v5;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v5 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v6;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v6;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v6 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v7;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v7;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v7 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v8;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v8;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v8 = 0;
    SData/*9:0*/ __Vdlyvval__fdiv__DOT__pipe_exponent__v9;
    __Vdlyvval__fdiv__DOT__pipe_exponent__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v9;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__pipe_exponent__v10;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v10 = 0;
    SData/*9:0*/ __Vdly__fdiv__DOT__pipe_zero;
    __Vdly__fdiv__DOT__pipe_zero = 0;
    SData/*9:0*/ __Vdly__fdiv__DOT__pipe_nan;
    __Vdly__fdiv__DOT__pipe_nan = 0;
    SData/*9:0*/ __Vdly__fdiv__DOT__pipe_inf;
    __Vdly__fdiv__DOT__pipe_inf = 0;
    SData/*9:0*/ __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val;
    __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v0;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v0 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9 = 0;
    IData/*25:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9 = 0;
    IData/*23:0*/ __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9;
    __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9 = 0;
    CData/*0:0*/ __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v10;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v10 = 0;
    // Body
    __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val 
        = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val;
    __Vdly__fdiv__DOT__pipe_sign = vlSelf->fdiv__DOT__pipe_sign;
    __Vdly__fdiv__DOT__pipe_inf = vlSelf->fdiv__DOT__pipe_inf;
    __Vdly__fdiv__DOT__pipe_nan = vlSelf->fdiv__DOT__pipe_nan;
    __Vdly__fdiv__DOT__pipe_zero = vlSelf->fdiv__DOT__pipe_zero;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v0 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v1 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v2 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v3 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v4 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v5 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v6 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v7 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v8 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v9 = 0U;
    __Vdlyvset__fdiv__DOT__pipe_exponent__v10 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0 = 0U;
    __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v10 = 0U;
    if (vlSelf->rst_n) {
        __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val 
            = ((0x3feU & ((IData)(vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val) 
                          << 1U)) | (IData)(vlSelf->input_valid));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3feU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((vlSelf->input_a 
                                            ^ vlSelf->input_b) 
                                           >> 0x1fU));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & (IData)(vlSelf->fdiv__DOT__pipe_sign));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3fdU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 1U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 1U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3fbU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 2U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 2U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3f7U & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 3U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 3U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3efU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 4U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 4U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3dfU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 5U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 5U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x3bfU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 6U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 6U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x37fU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 7U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 7U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x2ffU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 8U));
        vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                     >> 8U));
        __Vdly__fdiv__DOT__pipe_sign = ((0x1ffU & (IData)(__Vdly__fdiv__DOT__pipe_sign)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0) 
                                           << 9U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3feU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((1U & (~ 
                                                 ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
                                                    | (IData)(vlSelf->fdiv__DOT__b_is_nan)) 
                                                   | ((0U 
                                                       == 
                                                       (0x7fffffffU 
                                                        & vlSelf->input_a)) 
                                                      & (0U 
                                                         == 
                                                         (0x7fffffffU 
                                                          & vlSelf->input_b)))) 
                                                  | ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                                     & (IData)(vlSelf->fdiv__DOT__b_is_inf))))) 
                                          && ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                              | (0U 
                                                 == 
                                                 (0x7fffffffU 
                                                  & vlSelf->input_b)))));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & (IData)(vlSelf->fdiv__DOT__pipe_inf));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3fdU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 1U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 1U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3fbU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 2U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 2U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3f7U & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 3U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 3U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3efU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 4U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 4U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3dfU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 5U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 5U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x3bfU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 6U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 6U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x37fU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 7U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 7U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x2ffU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 8U));
        vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_inf) 
                     >> 8U));
        __Vdly__fdiv__DOT__pipe_inf = ((0x1ffU & (IData)(__Vdly__fdiv__DOT__pipe_inf)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0) 
                                          << 9U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3feU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
                                            | (IData)(vlSelf->fdiv__DOT__b_is_nan)) 
                                           | ((0U == 
                                               (0x7fffffffU 
                                                & vlSelf->input_a)) 
                                              & (0U 
                                                 == 
                                                 (0x7fffffffU 
                                                  & vlSelf->input_b)))) 
                                          | ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                             & (IData)(vlSelf->fdiv__DOT__b_is_inf))));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & (IData)(vlSelf->fdiv__DOT__pipe_nan));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3fdU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 1U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 1U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3fbU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 2U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 2U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3f7U & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 3U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 3U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3efU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 4U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 4U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3dfU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 5U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 5U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x3bfU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 6U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 6U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x37fU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 7U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 7U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x2ffU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 8U));
        vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_nan) 
                     >> 8U));
        __Vdly__fdiv__DOT__pipe_nan = ((0x1ffU & (IData)(__Vdly__fdiv__DOT__pipe_nan)) 
                                       | ((IData)(vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0) 
                                          << 9U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3feU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((1U & (~ 
                                                  ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
                                                     | (IData)(vlSelf->fdiv__DOT__b_is_nan)) 
                                                    | ((0U 
                                                        == 
                                                        (0x7fffffffU 
                                                         & vlSelf->input_a)) 
                                                       & (0U 
                                                          == 
                                                          (0x7fffffffU 
                                                           & vlSelf->input_b)))) 
                                                   | ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                                      & (IData)(vlSelf->fdiv__DOT__b_is_inf))))) 
                                           && ((1U 
                                                & (~ 
                                                   ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                                    | (0U 
                                                       == 
                                                       (0x7fffffffU 
                                                        & vlSelf->input_b))))) 
                                               && ((0U 
                                                    == 
                                                    (0x7fffffffU 
                                                     & vlSelf->input_a)) 
                                                   | (IData)(vlSelf->fdiv__DOT__b_is_inf)))));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & (IData)(vlSelf->fdiv__DOT__pipe_zero));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3fdU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 1U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 1U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3fbU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 2U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 2U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3f7U & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 3U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 3U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3efU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 4U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 4U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3dfU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 5U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 5U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x3bfU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 6U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 6U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x37fU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 7U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 7U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x2ffU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 8U));
        vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 
            = (1U & ((IData)(vlSelf->fdiv__DOT__pipe_zero) 
                     >> 8U));
        __Vdly__fdiv__DOT__pipe_zero = ((0x1ffU & (IData)(__Vdly__fdiv__DOT__pipe_zero)) 
                                        | ((IData)(vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0) 
                                           << 9U));
        vlSelf->fdiv__DOT__unnamedblk1__DOT__calc_exp 
            = (0x3ffU & ((IData)(0x7fU) + (((0U != 
                                             (0xffU 
                                              & (vlSelf->input_a 
                                                 >> 0x17U)))
                                             ? (0xffU 
                                                & (vlSelf->input_a 
                                                   >> 0x17U))
                                             : 1U) 
                                           - ((0U != 
                                               (0xffU 
                                                & (vlSelf->input_b 
                                                   >> 0x17U)))
                                               ? (0xffU 
                                                  & (vlSelf->input_b 
                                                     >> 0x17U))
                                               : 1U))));
        __Vdlyvval__fdiv__DOT__pipe_exponent__v0 = vlSelf->fdiv__DOT__unnamedblk1__DOT__calc_exp;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v0 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[0U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v1 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v1 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[1U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v2 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v2 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[2U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v3 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v3 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[3U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v4 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v4 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[4U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v5 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v5 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[5U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v6 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v6 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[6U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v7 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v7 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[7U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v8 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v8 = 1U;
        vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 
            = vlSelf->fdiv__DOT__pipe_exponent[8U];
        __Vdlyvval__fdiv__DOT__pipe_exponent__v9 = vlSelf->fdiv__DOT____Vlvbound_h28476e50__0;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v9 = 1U;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0 
            = ((0U != (0xffU & (vlSelf->input_a >> 0x17U)))
                ? (0x800000U | (0x7fffffU & vlSelf->input_a))
                : (0x7fffffU & vlSelf->input_a));
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0 = 1U;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v0 
            = ((0U != (0xffU & (vlSelf->input_b >> 0x17U)))
                ? (0x800000U | (0x7fffffU & vlSelf->input_b))
                : (0x7fffffU & vlSelf->input_b));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [0U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [0U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [0U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [1U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [1U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [1U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [2U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [2U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [2U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [3U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [3U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [3U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [4U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [4U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [4U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [5U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [5U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [5U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [6U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [6U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [6U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [7U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [7U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [7U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem
            [8U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [8U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div
            [8U];
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff 
            = (0x3ffffffU & (vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                             - vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div));
        if ((0x2000000U & vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff)) {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U));
        } else {
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo 
                = (0x3ffffffU & (1U | VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo, 1U)));
            vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
                = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff;
        }
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem 
            = (0x3ffffffU & VL_SHIFTL_III(26,26,32, vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem, 1U));
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9 = 1U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div;
        __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9 
            = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9 = 1U;
        vlSelf->fdiv__DOT__temp_exp = vlSelf->fdiv__DOT__pipe_exponent
            [9U];
        vlSelf->fdiv__DOT__temp_mantissa = vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo
            [9U];
        if ((0x200U & (IData)(vlSelf->fdiv__DOT__pipe_nan))) {
            vlSelf->result = 0x7fc00000U;
        } else if ((0x200U & (IData)(vlSelf->fdiv__DOT__pipe_inf))) {
            vlSelf->result = (0x7f800000U | (0x80000000U 
                                             & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                << 0x16U)));
        } else if ((0x200U & (IData)(vlSelf->fdiv__DOT__pipe_zero))) {
            vlSelf->result = (0x80000000U & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                             << 0x16U));
        } else if ((0x200U & (IData)(vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val))) {
            if ((0x2000000U & vlSelf->fdiv__DOT__temp_mantissa)) {
                vlSelf->fdiv__DOT__mantissa_rounded 
                    = (0x1ffffffU & ((0xffffffU & (vlSelf->fdiv__DOT__temp_mantissa 
                                                   >> 2U)) 
                                     + (1U & (vlSelf->fdiv__DOT__temp_mantissa 
                                              >> 1U))));
                vlSelf->result = ((0x1000000U & vlSelf->fdiv__DOT__mantissa_rounded)
                                   ? ((0xffU <= ((IData)(1U) 
                                                 + (IData)(vlSelf->fdiv__DOT__temp_exp)))
                                       ? (0x7f800000U 
                                          | (0x80000000U 
                                             & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                << 0x16U)))
                                       : ((0x80000000U 
                                           & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                              << 0x16U)) 
                                          | ((0x7f800000U 
                                              & (((IData)(1U) 
                                                  + (IData)(vlSelf->fdiv__DOT__temp_exp)) 
                                                 << 0x17U)) 
                                             | (0x7fffffU 
                                                & (vlSelf->fdiv__DOT__mantissa_rounded 
                                                   >> 1U)))))
                                   : (VL_GTES_III(32, 0U, 
                                                  VL_EXTENDS_II(32,10, (IData)(vlSelf->fdiv__DOT__temp_exp)))
                                       ? (0x80000000U 
                                          & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                             << 0x16U))
                                       : ((0xffU <= (IData)(vlSelf->fdiv__DOT__temp_exp))
                                           ? (0x7f800000U 
                                              | (0x80000000U 
                                                 & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                    << 0x16U)))
                                           : ((0x80000000U 
                                               & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                  << 0x16U)) 
                                              | ((0x7f800000U 
                                                  & ((IData)(vlSelf->fdiv__DOT__temp_exp) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & vlSelf->fdiv__DOT__mantissa_rounded))))));
            } else {
                vlSelf->fdiv__DOT__mantissa_rounded 
                    = (0x1ffffffU & ((0xffffffU & (vlSelf->fdiv__DOT__temp_mantissa 
                                                   >> 1U)) 
                                     + (1U & vlSelf->fdiv__DOT__temp_mantissa)));
                vlSelf->result = ((0x1000000U & vlSelf->fdiv__DOT__mantissa_rounded)
                                   ? (VL_GTES_III(32, 0U, 
                                                  VL_EXTENDS_II(32,10, (IData)(vlSelf->fdiv__DOT__temp_exp)))
                                       ? (0x80000000U 
                                          & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                             << 0x16U))
                                       : ((0xffU <= (IData)(vlSelf->fdiv__DOT__temp_exp))
                                           ? (0x7f800000U 
                                              | (0x80000000U 
                                                 & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                    << 0x16U)))
                                           : ((0x80000000U 
                                               & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                  << 0x16U)) 
                                              | ((0x7f800000U 
                                                  & ((IData)(vlSelf->fdiv__DOT__temp_exp) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & (vlSelf->fdiv__DOT__mantissa_rounded 
                                                       >> 1U))))))
                                   : (VL_GTES_III(32, 0U, 
                                                  (VL_EXTENDS_II(32,10, (IData)(vlSelf->fdiv__DOT__temp_exp)) 
                                                   - (IData)(1U)))
                                       ? (0x80000000U 
                                          & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                             << 0x16U))
                                       : ((0xffU <= 
                                           ((IData)(vlSelf->fdiv__DOT__temp_exp) 
                                            - (IData)(1U)))
                                           ? (0x7f800000U 
                                              | (0x80000000U 
                                                 & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                    << 0x16U)))
                                           : ((0x80000000U 
                                               & ((IData)(vlSelf->fdiv__DOT__pipe_sign) 
                                                  << 0x16U)) 
                                              | ((0x7f800000U 
                                                  & (((IData)(vlSelf->fdiv__DOT__temp_exp) 
                                                      - (IData)(1U)) 
                                                     << 0x17U)) 
                                                 | (0x7fffffU 
                                                    & vlSelf->fdiv__DOT__mantissa_rounded))))));
            }
        }
    } else {
        __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val = 0U;
        __Vdly__fdiv__DOT__pipe_sign = 0U;
        __Vdly__fdiv__DOT__pipe_inf = 0U;
        __Vdly__fdiv__DOT__pipe_nan = 0U;
        __Vdly__fdiv__DOT__pipe_zero = 0U;
        __Vdlyvset__fdiv__DOT__pipe_exponent__v10 = 1U;
        __Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v10 = 1U;
        vlSelf->result = 0U;
    }
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && 
                         (1U & ((IData)(vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val) 
                                >> 9U)));
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[0U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v0;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[0U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v0;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[0U] = 0U;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[1U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v1;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[2U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v2;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[3U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v3;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[4U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v4;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[5U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v5;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[6U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v6;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[7U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v7;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[8U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v8;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[9U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div__v9;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[1U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v1;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[2U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v2;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[3U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v3;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[4U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v4;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[5U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v5;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[6U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v6;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[7U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v7;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[8U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v8;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[9U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v9;
    }
    vlSelf->fdiv__DOT__pipe_nan = __Vdly__fdiv__DOT__pipe_nan;
    vlSelf->fdiv__DOT__pipe_inf = __Vdly__fdiv__DOT__pipe_inf;
    vlSelf->fdiv__DOT__pipe_sign = __Vdly__fdiv__DOT__pipe_sign;
    vlSelf->fdiv__DOT__pipe_zero = __Vdly__fdiv__DOT__pipe_zero;
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val 
        = __Vdly__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val;
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[1U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v1;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[2U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v2;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[3U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v3;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[4U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v4;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[5U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v5;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[6U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v6;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[7U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v7;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[8U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v8;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[9U] 
            = __Vdlyvval__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo__v9;
    }
    if (__Vdlyvset__fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem__v10) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[0U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[1U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[2U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[3U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[4U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[5U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[6U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[7U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[8U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[9U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[0U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[1U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[2U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[3U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[4U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[5U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[6U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[7U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[8U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[9U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[0U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[1U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[2U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[3U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[4U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[5U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[6U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[7U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[8U] = 0U;
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[9U] = 0U;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v0) {
        vlSelf->fdiv__DOT__pipe_exponent[0U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v0;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v1) {
        vlSelf->fdiv__DOT__pipe_exponent[1U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v1;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v2) {
        vlSelf->fdiv__DOT__pipe_exponent[2U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v2;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v3) {
        vlSelf->fdiv__DOT__pipe_exponent[3U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v3;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v4) {
        vlSelf->fdiv__DOT__pipe_exponent[4U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v4;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v5) {
        vlSelf->fdiv__DOT__pipe_exponent[5U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v5;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v6) {
        vlSelf->fdiv__DOT__pipe_exponent[6U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v6;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v7) {
        vlSelf->fdiv__DOT__pipe_exponent[7U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v7;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v8) {
        vlSelf->fdiv__DOT__pipe_exponent[8U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v8;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v9) {
        vlSelf->fdiv__DOT__pipe_exponent[9U] = __Vdlyvval__fdiv__DOT__pipe_exponent__v9;
    }
    if (__Vdlyvset__fdiv__DOT__pipe_exponent__v10) {
        vlSelf->fdiv__DOT__pipe_exponent[0U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[1U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[2U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[3U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[4U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[5U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[6U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[7U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[8U] = 0U;
        vlSelf->fdiv__DOT__pipe_exponent[9U] = 0U;
    }
}

void Vfdiv___024root___eval_nba(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfdiv___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vfdiv___024root___eval_triggers__act(Vfdiv___024root* vlSelf);

bool Vfdiv___024root___eval_phase__act(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfdiv___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfdiv___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfdiv___024root___eval_phase__nba(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfdiv___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__ico(Vfdiv___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__nba(Vfdiv___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__act(Vfdiv___024root* vlSelf);
#endif  // VL_DEBUG

void Vfdiv___024root___eval(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval\n"); );
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
            Vfdiv___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("fdiv_10.sv", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vfdiv___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfdiv___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fdiv_10.sv", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfdiv___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fdiv_10.sv", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfdiv___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfdiv___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfdiv___024root___eval_debug_assertions(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
