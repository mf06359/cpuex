// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfdiv.h for the primary calling header

#include "Vfdiv__pch.h"
#include "Vfdiv___024root.h"

VL_ATTR_COLD void Vfdiv___024root___eval_static(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfdiv___024root___eval_initial(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vfdiv___024root___eval_final(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__stl(Vfdiv___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfdiv___024root___eval_phase__stl(Vfdiv___024root* vlSelf);

VL_ATTR_COLD void Vfdiv___024root___eval_settle(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_settle\n"); );
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
            Vfdiv___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fdiv_10.sv", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfdiv___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__stl(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void Vfdiv___024root___ico_sequent__TOP__0(Vfdiv___024root* vlSelf);

VL_ATTR_COLD void Vfdiv___024root___eval_stl(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfdiv___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfdiv___024root___eval_triggers__stl(Vfdiv___024root* vlSelf);

VL_ATTR_COLD bool Vfdiv___024root___eval_phase__stl(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfdiv___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfdiv___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__ico(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___dump_triggers__ico\n"); );
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
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__act(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfdiv___024root___dump_triggers__nba(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfdiv___024root___ctor_var_reset(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->input_a = VL_RAND_RESET_I(32);
    vlSelf->input_b = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__a_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__b_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__a_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__b_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__pipe_sign = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fdiv__DOT__pipe_exponent[__Vi0] = VL_RAND_RESET_I(10);
    }
    vlSelf->fdiv__DOT__pipe_nan = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__pipe_zero = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__pipe_inf = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__temp_exp = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__temp_mantissa = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__mantissa_rounded = VL_RAND_RESET_I(25);
    vlSelf->fdiv__DOT__unnamedblk1__DOT__calc_exp = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT____Vlvbound_h228b8c1b__0 = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT____Vlvbound_h28476e50__0 = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT____Vlvbound_h1c8d4e6c__0 = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT____Vlvbound_h04aaabe8__0 = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT____Vlvbound_hcf786d1a__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_rem[__Vi0] = VL_RAND_RESET_I(26);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_quo[__Vi0] = VL_RAND_RESET_I(26);
    }
    for (int __Vi0 = 0; __Vi0 < 10; ++__Vi0) {
        vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_div[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__pipe_val = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_rem = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_quo = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_div = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT__unnamedblk1__DOT__t_diff = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h0062dff4__0 = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4422613d__0 = VL_RAND_RESET_I(26);
    vlSelf->fdiv__DOT__u_fdiv_mantissa__DOT____Vlvbound_h4c672f5a__0 = VL_RAND_RESET_I(24);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
