// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitof.h for the primary calling header

#include "Vitof__pch.h"
#include "Vitof___024root.h"

VL_ATTR_COLD void Vitof___024root___eval_static(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vitof___024root___eval_initial(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void Vitof___024root___eval_final(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vitof___024root___eval_settle(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitof___024root___dump_triggers__act(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___dump_triggers__act\n"); );
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
VL_ATTR_COLD void Vitof___024root___dump_triggers__nba(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vitof___024root___ctor_var_reset(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->in_i = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->out_f = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__s1_abs_i = VL_RAND_RESET_I(32);
    vlSelf->itof__DOT__s1_sign = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__s1_valid = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__s2_lzc = VL_RAND_RESET_I(5);
    vlSelf->itof__DOT__s2_abs_i = VL_RAND_RESET_I(32);
    vlSelf->itof__DOT__s2_sign = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__s2_valid = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__round = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__lsb = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__unnamedblk1__DOT__exp = VL_RAND_RESET_I(8);
    vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant = VL_RAND_RESET_I(32);
    vlSelf->itof__DOT__unnamedblk1__DOT__frac = VL_RAND_RESET_I(23);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
