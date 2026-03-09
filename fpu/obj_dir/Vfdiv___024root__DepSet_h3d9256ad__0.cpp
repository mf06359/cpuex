// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfdiv.h for the primary calling header

#include "Vfdiv__pch.h"
#include "Vfdiv___024root.h"

VL_INLINE_OPT void Vfdiv___024root___ico_sequent__TOP__0(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ fdiv__DOT__a_is_inf;
    fdiv__DOT__a_is_inf = 0;
    CData/*0:0*/ fdiv__DOT__b_is_inf;
    fdiv__DOT__b_is_inf = 0;
    SData/*10:0*/ fdiv__DOT__raw_exp;
    fdiv__DOT__raw_exp = 0;
    // Body
    fdiv__DOT__raw_exp = (0x7ffU & ((IData)(0x7fU) 
                                    + (((0U != (0xffU 
                                                & (vlSelf->input_a 
                                                   >> 0x17U)))
                                         ? (0xffU & 
                                            (vlSelf->input_a 
                                             >> 0x17U))
                                         : 1U) - ((0U 
                                                   != 
                                                   (0xffU 
                                                    & (vlSelf->input_b 
                                                       >> 0x17U)))
                                                   ? 
                                                  (0xffU 
                                                   & (vlSelf->input_b 
                                                      >> 0x17U))
                                                   : 1U))));
    vlSelf->fdiv__DOT__m_b = ((0U != (0xffU & (vlSelf->input_b 
                                               >> 0x17U)))
                               ? (0x800000U | (0x7fffffU 
                                               & vlSelf->input_b))
                               : (0x7fffffU & vlSelf->input_b));
    vlSelf->fdiv__DOT__m_a = ((0U != (0xffU & (vlSelf->input_a 
                                               >> 0x17U)))
                               ? (0x800000U | (0x7fffffU 
                                               & vlSelf->input_a))
                               : (0x7fffffU & vlSelf->input_a));
    fdiv__DOT__a_is_inf = (IData)((0x7f800000U == (0x7fffffffU 
                                                   & vlSelf->input_a)));
    fdiv__DOT__b_is_inf = (IData)((0x7f800000U == (0x7fffffffU 
                                                   & vlSelf->input_b)));
    vlSelf->fdiv__DOT__shift_pred = (vlSelf->fdiv__DOT__m_a 
                                     >= vlSelf->fdiv__DOT__m_b);
    vlSelf->fdiv__DOT__is_inf = ((IData)(fdiv__DOT__a_is_inf) 
                                 | (0U == (0x7fffffffU 
                                           & vlSelf->input_b)));
    vlSelf->fdiv__DOT__is_zero = ((0U == (0x7fffffffU 
                                          & vlSelf->input_a)) 
                                  | (IData)(fdiv__DOT__b_is_inf));
    vlSelf->fdiv__DOT__is_nan = ((IData)(((0x7f800000U 
                                           == (0x7f800000U 
                                               & vlSelf->input_a)) 
                                          & (0U != 
                                             (0x7fffffU 
                                              & vlSelf->input_a)))) 
                                 | ((IData)(((0x7f800000U 
                                              == (0x7f800000U 
                                                  & vlSelf->input_b)) 
                                             & (0U 
                                                != 
                                                (0x7fffffU 
                                                 & vlSelf->input_b)))) 
                                    | (((0U == (0x7fffffffU 
                                                & vlSelf->input_a)) 
                                        & (0U == (0x7fffffffU 
                                                  & vlSelf->input_b))) 
                                       | ((IData)(fdiv__DOT__a_is_inf) 
                                          & (IData)(fdiv__DOT__b_is_inf)))));
    vlSelf->fdiv__DOT__exp_N = (0x7ffU & ((IData)(vlSelf->fdiv__DOT__shift_pred)
                                           ? (IData)(fdiv__DOT__raw_exp)
                                           : ((IData)(fdiv__DOT__raw_exp) 
                                              - (IData)(1U))));
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
    if (vlSelf->rst_n) {
        vlSelf->fdiv__DOT__st2_bias = vlSelf->fdiv__DOT__st1_bias;
        vlSelf->fdiv__DOT__st2_adjusted_a = vlSelf->fdiv__DOT__st1_adjusted_a;
        vlSelf->fdiv__DOT__st2_x1 = (0xffffffU & (IData)(
                                                         (0x1ffffffULL 
                                                          & ((((QData)((IData)(
                                                                               (0xffffffU 
                                                                                & (IData)(
                                                                                (vlSelf->fdiv__DOT__st1_y0_dy 
                                                                                >> 0x18U))))) 
                                                               << 0x17U) 
                                                              - 
                                                              (0x7ffffffffULL 
                                                               & ((QData)((IData)(
                                                                                (0xffffffU 
                                                                                & (IData)(vlSelf->fdiv__DOT__st1_y0_dy)))) 
                                                                  * (QData)((IData)(vlSelf->fdiv__DOT__st1_m_b_10_0))))) 
                                                             >> 0x17U))));
        if (vlSelf->fdiv__DOT__st2_valid) {
            vlSelf->result = ((IData)(vlSelf->fdiv__DOT__st2_nan)
                               ? 0x7fc00000U : (((1U 
                                                  & (IData)(
                                                            (vlSelf->fdiv__DOT__q_final 
                                                             >> 0x2fU)))
                                                  ? (IData)(vlSelf->fdiv__DOT__st2_inf_C)
                                                  : 
                                                 ((1U 
                                                   & (IData)(
                                                             (vlSelf->fdiv__DOT__q_final 
                                                              >> 0x2eU)))
                                                   ? (IData)(vlSelf->fdiv__DOT__st2_inf_N)
                                                   : (IData)(vlSelf->fdiv__DOT__st2_inf_S)))
                                                 ? 
                                                (0x7f800000U 
                                                 | ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                                    << 0x1fU))
                                                 : 
                                                (((1U 
                                                   & (IData)(
                                                             (vlSelf->fdiv__DOT__q_final 
                                                              >> 0x2fU)))
                                                   ? (IData)(vlSelf->fdiv__DOT__st2_zero_C)
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->fdiv__DOT__q_final 
                                                               >> 0x2eU)))
                                                    ? (IData)(vlSelf->fdiv__DOT__st2_zero_N)
                                                    : (IData)(vlSelf->fdiv__DOT__st2_zero_S)))
                                                  ? 
                                                 ((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                                  << 0x1fU)
                                                  : 
                                                 (((IData)(vlSelf->fdiv__DOT__st2_sign) 
                                                   << 0x1fU) 
                                                  | ((((1U 
                                                        & (IData)(
                                                                  (vlSelf->fdiv__DOT__q_final 
                                                                   >> 0x2fU)))
                                                        ? (IData)(vlSelf->fdiv__DOT__st2_exp_C)
                                                        : 
                                                       ((1U 
                                                         & (IData)(
                                                                   (vlSelf->fdiv__DOT__q_final 
                                                                    >> 0x2eU)))
                                                         ? (IData)(vlSelf->fdiv__DOT__st2_exp_N)
                                                         : (IData)(vlSelf->fdiv__DOT__st2_exp_S))) 
                                                      << 0x17U) 
                                                     | (0x7fffffU 
                                                        & ((1U 
                                                            & (IData)(
                                                                      (vlSelf->fdiv__DOT__q_final 
                                                                       >> 0x2fU)))
                                                            ? (IData)(
                                                                      (vlSelf->fdiv__DOT__q_final 
                                                                       >> 0x18U))
                                                            : 
                                                           ((1U 
                                                             & (IData)(
                                                                       (vlSelf->fdiv__DOT__q_final 
                                                                        >> 0x2eU)))
                                                             ? (IData)(
                                                                       (vlSelf->fdiv__DOT__q_final 
                                                                        >> 0x17U))
                                                             : (IData)(
                                                                       (vlSelf->fdiv__DOT__q_final 
                                                                        >> 0x16U))))))))));
        }
        vlSelf->fdiv__DOT__st1_bias = ((0U == (0x7fffffU 
                                               & vlSelf->fdiv__DOT__m_b))
                                        ? 0ULL : 0x17fffffULL);
        vlSelf->fdiv__DOT__st1_adjusted_a = ((IData)(vlSelf->fdiv__DOT__shift_pred)
                                              ? vlSelf->fdiv__DOT__m_a
                                              : (vlSelf->fdiv__DOT__m_a 
                                                 << 1U));
        vlSelf->fdiv__DOT__st1_m_b_10_0 = (0x7ffU & vlSelf->fdiv__DOT__m_b);
        vlSelf->fdiv__DOT__st2_exp_C = vlSelf->fdiv__DOT__st1_exp_C;
        vlSelf->fdiv__DOT__st2_exp_N = vlSelf->fdiv__DOT__st1_exp_N;
        vlSelf->fdiv__DOT__st2_exp_S = vlSelf->fdiv__DOT__st1_exp_S;
        vlSelf->fdiv__DOT__st1_exp_C = (0xffU & ((IData)(1U) 
                                                 + (IData)(vlSelf->fdiv__DOT__exp_N)));
        vlSelf->fdiv__DOT__st1_exp_N = (0xffU & (IData)(vlSelf->fdiv__DOT__exp_N));
        vlSelf->fdiv__DOT__st1_exp_S = (0xffU & ((IData)(vlSelf->fdiv__DOT__exp_N) 
                                                 - (IData)(1U)));
    } else {
        vlSelf->fdiv__DOT__st2_bias = 0ULL;
        vlSelf->fdiv__DOT__st2_adjusted_a = 0U;
        vlSelf->fdiv__DOT__st2_x1 = 0U;
        vlSelf->result = 0U;
        vlSelf->fdiv__DOT__st1_bias = 0ULL;
        vlSelf->fdiv__DOT__st1_adjusted_a = 0U;
        vlSelf->fdiv__DOT__st1_m_b_10_0 = 0U;
        vlSelf->fdiv__DOT__st2_exp_C = 0U;
        vlSelf->fdiv__DOT__st2_exp_N = 0U;
        vlSelf->fdiv__DOT__st2_exp_S = 0U;
        vlSelf->fdiv__DOT__st1_exp_C = 0U;
        vlSelf->fdiv__DOT__st1_exp_N = 0U;
        vlSelf->fdiv__DOT__st1_exp_S = 0U;
    }
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->fdiv__DOT__st2_valid));
    vlSelf->fdiv__DOT__q_final = (0x1ffffffffffffULL 
                                  & (((QData)((IData)(
                                                      (vlSelf->fdiv__DOT__st2_adjusted_a 
                                                       * 
                                                       (0x7fU 
                                                        & (vlSelf->fdiv__DOT__st2_x1 
                                                           >> 0x11U))))) 
                                      << 0x11U) + (
                                                   (0x3ffffffffffULL 
                                                    & ((QData)((IData)(vlSelf->fdiv__DOT__st2_adjusted_a)) 
                                                       * (QData)((IData)(
                                                                         (0x1ffffU 
                                                                          & vlSelf->fdiv__DOT__st2_x1))))) 
                                                   + vlSelf->fdiv__DOT__st2_bias)));
    vlSelf->fdiv__DOT__st2_valid = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fdiv__DOT__st1_valid));
    vlSelf->fdiv__DOT__st2_sign = ((IData)(vlSelf->rst_n) 
                                   && (IData)(vlSelf->fdiv__DOT__st1_sign));
    vlSelf->fdiv__DOT__st2_nan = ((IData)(vlSelf->rst_n) 
                                  && (IData)(vlSelf->fdiv__DOT__st1_nan));
    vlSelf->fdiv__DOT__st2_inf_C = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fdiv__DOT__st1_inf_C));
    vlSelf->fdiv__DOT__st2_inf_N = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fdiv__DOT__st1_inf_N));
    vlSelf->fdiv__DOT__st2_inf_S = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fdiv__DOT__st1_inf_S));
    vlSelf->fdiv__DOT__st2_zero_C = ((IData)(vlSelf->rst_n) 
                                     && (IData)(vlSelf->fdiv__DOT__st1_zero_C));
    vlSelf->fdiv__DOT__st2_zero_N = ((IData)(vlSelf->rst_n) 
                                     && (IData)(vlSelf->fdiv__DOT__st1_zero_N));
    vlSelf->fdiv__DOT__st2_zero_S = ((IData)(vlSelf->rst_n) 
                                     && (IData)(vlSelf->fdiv__DOT__st1_zero_S));
    vlSelf->fdiv__DOT__st1_valid = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->input_valid));
    vlSelf->fdiv__DOT__st1_sign = ((IData)(vlSelf->rst_n) 
                                   && ((vlSelf->input_a 
                                        ^ vlSelf->input_b) 
                                       >> 0x1fU));
    vlSelf->fdiv__DOT__st1_nan = ((IData)(vlSelf->rst_n) 
                                  && (IData)(vlSelf->fdiv__DOT__is_nan));
    vlSelf->fdiv__DOT__st1_inf_C = ((IData)(vlSelf->rst_n) 
                                    && (((IData)(vlSelf->fdiv__DOT__is_inf) 
                                         & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                        | VL_LTES_III(11, 0xffU, 
                                                      (0x7ffU 
                                                       & ((IData)(1U) 
                                                          + (IData)(vlSelf->fdiv__DOT__exp_N))))));
    vlSelf->fdiv__DOT__st1_inf_N = ((IData)(vlSelf->rst_n) 
                                    && (((IData)(vlSelf->fdiv__DOT__is_inf) 
                                         & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                        | VL_LTES_III(11, 0xffU, (IData)(vlSelf->fdiv__DOT__exp_N))));
    vlSelf->fdiv__DOT__st1_inf_S = ((IData)(vlSelf->rst_n) 
                                    && (((IData)(vlSelf->fdiv__DOT__is_inf) 
                                         & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                        | VL_LTES_III(11, 0xffU, 
                                                      (0x7ffU 
                                                       & ((IData)(vlSelf->fdiv__DOT__exp_N) 
                                                          - (IData)(1U))))));
    vlSelf->fdiv__DOT__st1_zero_C = ((IData)(vlSelf->rst_n) 
                                     && (((IData)(vlSelf->fdiv__DOT__is_zero) 
                                          & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                         | VL_GTES_III(11, 0U, 
                                                       (0x7ffU 
                                                        & ((IData)(1U) 
                                                           + (IData)(vlSelf->fdiv__DOT__exp_N))))));
    vlSelf->fdiv__DOT__st1_zero_N = ((IData)(vlSelf->rst_n) 
                                     && (((IData)(vlSelf->fdiv__DOT__is_zero) 
                                          & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                         | VL_GTES_III(11, 0U, (IData)(vlSelf->fdiv__DOT__exp_N))));
    vlSelf->fdiv__DOT__st1_zero_S = ((IData)(vlSelf->rst_n) 
                                     && (((IData)(vlSelf->fdiv__DOT__is_zero) 
                                          & (~ (IData)(vlSelf->fdiv__DOT__is_nan))) 
                                         | VL_GTES_III(11, 0U, 
                                                       (0x7ffU 
                                                        & ((IData)(vlSelf->fdiv__DOT__exp_N) 
                                                           - (IData)(1U))))));
}

VL_INLINE_OPT void Vfdiv___024root___nba_sequent__TOP__1(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->fdiv__DOT__st1_y0_dy = vlSelf->fdiv__DOT__lut
        [(0xfffU & (vlSelf->fdiv__DOT__m_b >> 0xbU))];
}

void Vfdiv___024root___eval_nba(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfdiv___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfdiv___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vfdiv___024root___eval_triggers__act(Vfdiv___024root* vlSelf);

bool Vfdiv___024root___eval_phase__act(Vfdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfdiv___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
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
