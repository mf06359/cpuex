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

VL_ATTR_COLD void Vfdiv___024root___eval_initial__TOP(Vfdiv___024root* vlSelf);

VL_ATTR_COLD void Vfdiv___024root___eval_initial(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_initial\n"); );
    // Body
    Vfdiv___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vfdiv___024root___eval_initial__TOP(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e6d656dU;
    __Vtemp_1[1U] = 0x5f6c7574U;
    __Vtemp_1[2U] = 0x796c6f72U;
    __Vtemp_1[3U] = 0x7461U;
    VL_READMEM_N(true, 48, 4096, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelf->fdiv__DOT__lut), 0, ~0ULL);
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
            VL_FATAL_MT("fdiv.sv", 3, "", "Settle region did not converge.");
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

VL_ATTR_COLD void Vfdiv___024root___stl_sequent__TOP__0(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___stl_sequent__TOP__0\n"); );
    // Init
    QData/*47:0*/ fdiv__DOT__q_biased;
    fdiv__DOT__q_biased = 0;
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
    vlSelf->fdiv__DOT__m_b = ((0U != (0xffU & (vlSelf->input_b 
                                               >> 0x17U)))
                               ? (0x800000U | (0x7fffffU 
                                               & vlSelf->input_b))
                               : (0x7fffffU & vlSelf->input_b));
    vlSelf->fdiv__DOT__b_is_nan = (IData)(((0x7f800000U 
                                            == (0x7f800000U 
                                                & vlSelf->input_b)) 
                                           & (0U != 
                                              (0x7fffffU 
                                               & vlSelf->input_b))));
    vlSelf->fdiv__DOT__b_is_inf = (IData)((0x7f800000U 
                                           == (0x7fffffffU 
                                               & vlSelf->input_b)));
    fdiv__DOT__q_biased = (0xffffffffffffULL & (((QData)((IData)(vlSelf->fdiv__DOT__st2_mantissa)) 
                                                 * (QData)((IData)(vlSelf->fdiv__DOT__st2_x1))) 
                                                + ((IData)(vlSelf->fdiv__DOT__st2_b_is_power2)
                                                    ? 0ULL
                                                    : 0x7fffffULL)));
    vlSelf->fdiv__DOT__rounded_mantissa = (0x1ffffffU 
                                           & ((0xffffffU 
                                               & ((1U 
                                                   & (IData)(
                                                             (fdiv__DOT__q_biased 
                                                              >> 0x2eU)))
                                                   ? (IData)(
                                                             (fdiv__DOT__q_biased 
                                                              >> 0x17U))
                                                   : (IData)(
                                                             (fdiv__DOT__q_biased 
                                                              >> 0x16U)))) 
                                              + (1U 
                                                 & ((1U 
                                                     & (IData)(
                                                               (fdiv__DOT__q_biased 
                                                                >> 0x2eU)))
                                                     ? (IData)(
                                                               (fdiv__DOT__q_biased 
                                                                >> 0x16U))
                                                     : (IData)(
                                                               (fdiv__DOT__q_biased 
                                                                >> 0x15U))))));
    vlSelf->fdiv__DOT__final_exp = (0x7ffU & (VL_EXTENDS_II(11,10, (IData)(vlSelf->fdiv__DOT__st2_exponent)) 
                                              + (((1U 
                                                   & (IData)(
                                                             (fdiv__DOT__q_biased 
                                                              >> 0x2eU)))
                                                   ? 0U
                                                   : 0x7ffU) 
                                                 + 
                                                 ((0x1000000U 
                                                   & vlSelf->fdiv__DOT__rounded_mantissa)
                                                   ? 1U
                                                   : 0U))));
}

VL_ATTR_COLD void Vfdiv___024root___eval_stl(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfdiv___024root___stl_sequent__TOP__0(vlSelf);
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
    vlSelf->fdiv__DOT__m_b = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__a_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__b_is_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__a_is_inf = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__b_is_inf = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->fdiv__DOT__lut[__Vi0] = VL_RAND_RESET_Q(48);
    }
    vlSelf->fdiv__DOT__st1_valid = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_sign = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_inf = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_zero = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_b_is_power2 = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st1_exponent = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__st1_mantissa_a = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__st1_mantissa_b = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__st1_y0_dy = VL_RAND_RESET_Q(48);
    vlSelf->fdiv__DOT__st2_valid = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_sign = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_nan = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_inf = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_zero = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_b_is_power2 = VL_RAND_RESET_I(1);
    vlSelf->fdiv__DOT__st2_exponent = VL_RAND_RESET_I(10);
    vlSelf->fdiv__DOT__st2_mantissa = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__st2_mantissa_b = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__st2_x1 = VL_RAND_RESET_I(24);
    vlSelf->fdiv__DOT__rounded_mantissa = VL_RAND_RESET_I(25);
    vlSelf->fdiv__DOT__final_exp = VL_RAND_RESET_I(11);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
