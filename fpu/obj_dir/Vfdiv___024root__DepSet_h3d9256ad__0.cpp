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
    // Body
    vlSelf->fdiv__DOT__st2_b_is_power2 = ((IData)(vlSelf->rst_n) 
                                          && (IData)(vlSelf->fdiv__DOT__st1_b_is_power2));
    if (vlSelf->rst_n) {
        vlSelf->fdiv__DOT__st2_exp_zero = vlSelf->fdiv__DOT__st1_exponent;
        vlSelf->fdiv__DOT__st2_exp_minus1 = (0x7ffU 
                                             & ((IData)(vlSelf->fdiv__DOT__st1_exponent) 
                                                - (IData)(1U)));
        vlSelf->fdiv__DOT__st2_exp_plus1 = (0x7ffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlSelf->fdiv__DOT__st1_exponent)));
        vlSelf->fdiv__DOT__st2_mantissa = vlSelf->fdiv__DOT__st1_mantissa_a;
        vlSelf->fdiv__DOT__st2_x1 = (0xffffffU & (IData)(
                                                         (0x1ffffffULL 
                                                          & ((((QData)((IData)(
                                                                               (0xffffffU 
                                                                                & (IData)(
                                                                                (vlSelf->fdiv__DOT__st1_y0_dy 
                                                                                >> 0x18U))))) 
                                                               << 0x17U) 
                                                              - 
                                                              ((QData)((IData)(
                                                                               (0xffffffU 
                                                                                & (IData)(vlSelf->fdiv__DOT__st1_y0_dy)))) 
                                                               * (QData)((IData)(
                                                                                (0x7ffU 
                                                                                & vlSelf->fdiv__DOT__st1_mantissa_b))))) 
                                                             >> 0x17U))));
        if (vlSelf->fdiv__DOT__st2_nan) {
            vlSelf->result = 0x7fc00000U;
        } else if (vlSelf->fdiv__DOT__st2_inf) {
            vlSelf->result = (0x7f800000U | ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                             << 0x1fU));
        } else if (vlSelf->fdiv__DOT__st2_zero) {
            vlSelf->result = ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                              << 0x1fU);
        } else if (vlSelf->fdiv__DOT__st2_valid) {
            vlSelf->result = (VL_LTES_III(11, 0xffU, (IData)(vlSelf->fdiv__DOT__final_exp))
                               ? (0x7f800000U | ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                                 << 0x1fU))
                               : (VL_GTES_III(11, 0U, (IData)(vlSelf->fdiv__DOT__final_exp))
                                   ? ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                      << 0x1fU) : (
                                                   ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                                    << 0x1fU) 
                                                   | ((0x7f800000U 
                                                       & ((IData)(vlSelf->fdiv__DOT__final_exp) 
                                                          << 0x17U)) 
                                                      | (0x7fffffU 
                                                         & ((2U 
                                                             == (IData)(vlSelf->fdiv__DOT__shift_sel))
                                                             ? (IData)(
                                                                       (vlSelf->fdiv__DOT__q_final 
                                                                        >> 0x18U))
                                                             : 
                                                            ((1U 
                                                              == (IData)(vlSelf->fdiv__DOT__shift_sel))
                                                              ? (IData)(
                                                                        (vlSelf->fdiv__DOT__q_final 
                                                                         >> 0x17U))
                                                              : (IData)(
                                                                        (vlSelf->fdiv__DOT__q_final 
                                                                         >> 0x16U)))))))));
        }
        vlSelf->fdiv__DOT__st1_exponent = (0x7ffU & 
                                           ((IData)(0x7fU) 
                                            + (((0U 
                                                 != 
                                                 (0xffU 
                                                  & (vlSelf->input_a 
                                                     >> 0x17U)))
                                                 ? 
                                                (0xffU 
                                                 & (vlSelf->input_a 
                                                    >> 0x17U))
                                                 : 1U) 
                                               - ((0U 
                                                   != 
                                                   (0xffU 
                                                    & (vlSelf->input_b 
                                                       >> 0x17U)))
                                                   ? 
                                                  (0xffU 
                                                   & (vlSelf->input_b 
                                                      >> 0x17U))
                                                   : 1U))));
        vlSelf->fdiv__DOT__st1_mantissa_a = ((0U != 
                                              (0xffU 
                                               & (vlSelf->input_a 
                                                  >> 0x17U)))
                                              ? (0x800000U 
                                                 | (0x7fffffU 
                                                    & vlSelf->input_a))
                                              : (0x7fffffU 
                                                 & vlSelf->input_a));
        vlSelf->fdiv__DOT__st1_mantissa_b = vlSelf->fdiv__DOT__m_b;
        vlSelf->fdiv__DOT__st1_y0_dy = vlSelf->fdiv__DOT__lut
            [(0xfffU & (vlSelf->fdiv__DOT__m_b >> 0xbU))];
    } else {
        vlSelf->fdiv__DOT__st2_exp_zero = 0U;
        vlSelf->fdiv__DOT__st2_exp_minus1 = 0U;
        vlSelf->fdiv__DOT__st2_exp_plus1 = 0U;
        vlSelf->fdiv__DOT__st2_mantissa = 0U;
        vlSelf->fdiv__DOT__st2_x1 = 0U;
        vlSelf->result = 0U;
        vlSelf->fdiv__DOT__st1_exponent = 0U;
        vlSelf->fdiv__DOT__st1_mantissa_a = 0U;
        vlSelf->fdiv__DOT__st1_mantissa_b = 0U;
        vlSelf->fdiv__DOT__st1_y0_dy = 0ULL;
    }
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->fdiv__DOT__st2_valid));
    vlSelf->fdiv__DOT__st1_b_is_power2 = ((IData)(vlSelf->rst_n) 
                                          && (0U == 
                                              (0x7fffffU 
                                               & vlSelf->fdiv__DOT__m_b)));
    vlSelf->fdiv__DOT__q_final = (0xffffffffffffULL 
                                  & (((QData)((IData)(vlSelf->fdiv__DOT__st2_mantissa)) 
                                      * (QData)((IData)(vlSelf->fdiv__DOT__st2_x1))) 
                                     + ((IData)(vlSelf->fdiv__DOT__st2_b_is_power2)
                                         ? 0ULL : 0x7fffffULL)));
    vlSelf->fdiv__DOT__st2_valid = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fdiv__DOT__st1_valid));
    vlSelf->fdiv__DOT__st2_sign = ((IData)(vlSelf->rst_n) 
                                   && (IData)(vlSelf->fdiv__DOT__st1_sign));
    vlSelf->fdiv__DOT__st2_nan = ((IData)(vlSelf->rst_n) 
                                  && (IData)(vlSelf->fdiv__DOT__st1_nan));
    vlSelf->fdiv__DOT__st2_inf = ((IData)(vlSelf->rst_n) 
                                  && (IData)(vlSelf->fdiv__DOT__st1_inf));
    vlSelf->fdiv__DOT__st2_zero = ((IData)(vlSelf->rst_n) 
                                   && (IData)(vlSelf->fdiv__DOT__st1_zero));
    vlSelf->fdiv__DOT__shift_sel = ((1U & (IData)((vlSelf->fdiv__DOT__q_final 
                                                   >> 0x2fU)))
                                     ? 2U : ((1U & (IData)(
                                                           (vlSelf->fdiv__DOT__q_final 
                                                            >> 0x2eU)))
                                              ? 1U : 0U));
    vlSelf->fdiv__DOT__final_exp = ((2U == (IData)(vlSelf->fdiv__DOT__shift_sel))
                                     ? (IData)(vlSelf->fdiv__DOT__st2_exp_plus1)
                                     : ((1U == (IData)(vlSelf->fdiv__DOT__shift_sel))
                                         ? (IData)(vlSelf->fdiv__DOT__st2_exp_zero)
                                         : (IData)(vlSelf->fdiv__DOT__st2_exp_minus1)));
    vlSelf->fdiv__DOT__st1_valid = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->input_valid));
    vlSelf->fdiv__DOT__st1_sign = ((IData)(vlSelf->rst_n) 
                                   && ((vlSelf->input_a 
                                        ^ vlSelf->input_b) 
                                       >> 0x1fU));
    vlSelf->fdiv__DOT__st1_nan = ((IData)(vlSelf->rst_n) 
                                  && ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
                                        | (IData)(vlSelf->fdiv__DOT__b_is_nan)) 
                                       | ((0U == (0x7fffffffU 
                                                  & vlSelf->input_a)) 
                                          & (0U == 
                                             (0x7fffffffU 
                                              & vlSelf->input_b)))) 
                                      | ((IData)(vlSelf->fdiv__DOT__a_is_inf) 
                                         & (IData)(vlSelf->fdiv__DOT__b_is_inf))));
    vlSelf->fdiv__DOT__st1_inf = ((IData)(vlSelf->rst_n) 
                                  && ((1U & (~ ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
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
                                          | (0U == 
                                             (0x7fffffffU 
                                              & vlSelf->input_b)))));
    vlSelf->fdiv__DOT__st1_zero = ((IData)(vlSelf->rst_n) 
                                   && ((1U & (~ ((((IData)(vlSelf->fdiv__DOT__a_is_nan) 
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
                                       && ((1U & (~ 
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
            VL_FATAL_MT("fdiv.sv", 3, "", "Input combinational region did not converge.");
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
            VL_FATAL_MT("fdiv.sv", 3, "", "NBA region did not converge.");
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
                VL_FATAL_MT("fdiv.sv", 3, "", "Active region did not converge.");
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
