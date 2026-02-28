// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_3.h for the primary calling header

#include "Vfsqrt_3__pch.h"
#include "Vfsqrt_3___024root.h"

void Vfsqrt_3___024root___eval_act(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vfsqrt_3___024root___nba_sequent__TOP__0(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*47:0*/ fsqrt__DOT__mul_reg;
    fsqrt__DOT__mul_reg = 0;
    IData/*23:0*/ fsqrt__DOT__result_inner;
    fsqrt__DOT__result_inner = 0;
    CData/*2:0*/ __Vdly__fsqrt__DOT__is_abnormal_reg;
    __Vdly__fsqrt__DOT__is_abnormal_reg = 0;
    CData/*2:0*/ __Vdly__fsqrt__DOT__is_zero_reg;
    __Vdly__fsqrt__DOT__is_zero_reg = 0;
    // Body
    __Vdly__fsqrt__DOT__is_zero_reg = vlSelf->fsqrt__DOT__is_zero_reg;
    __Vdly__fsqrt__DOT__is_abnormal_reg = vlSelf->fsqrt__DOT__is_abnormal_reg;
    if (vlSelf->rst_n) {
        vlSelf->fsqrt__DOT__valid_reg = ((6U & ((IData)(vlSelf->fsqrt__DOT__valid_reg) 
                                                << 1U)) 
                                         | (IData)(vlSelf->input_valid));
        __Vdly__fsqrt__DOT__is_zero_reg = ((6U & ((IData)(vlSelf->fsqrt__DOT__is_zero_reg) 
                                                  << 1U)) 
                                           | (IData)(
                                                     (0U 
                                                      == 
                                                      (0x7fffffffU 
                                                       & vlSelf->input_a))));
        __Vdly__fsqrt__DOT__is_abnormal_reg = ((6U 
                                                & ((IData)(vlSelf->fsqrt__DOT__is_abnormal_reg) 
                                                   << 1U)) 
                                               | (0xffU 
                                                  == 
                                                  (0xffU 
                                                   & (vlSelf->input_a 
                                                      >> 0x17U))));
        vlSelf->fsqrt__DOT__exp_reg = vlSelf->fsqrt__DOT__exp_out;
        vlSelf->fsqrt__DOT__a_x0_reg = (0xffffffU & (IData)(
                                                            (0xffffffULL 
                                                             & (((QData)((IData)(vlSelf->fsqrt__DOT__a_fixed)) 
                                                                 * (QData)((IData)(vlSelf->fsqrt__DOT__x_0))) 
                                                                >> 0x18U))));
        vlSelf->fsqrt__DOT__double_x1 = (0xffffffU 
                                         & ((IData)(0xc00000U) 
                                            - (IData)(
                                                      (0xffffffULL 
                                                       & (((QData)((IData)(vlSelf->fsqrt__DOT__a_fixed)) 
                                                           * (QData)((IData)(vlSelf->fsqrt__DOT__x0_x0))) 
                                                          >> 0x18U)))));
        vlSelf->result = ((2U & (IData)(vlSelf->fsqrt__DOT__is_zero_reg))
                           ? ((IData)(vlSelf->fsqrt__DOT__sign_reg) 
                              << 0x1fU) : ((2U & (IData)(vlSelf->fsqrt__DOT__is_abnormal_reg))
                                            ? (0x7f800000U 
                                               | ((IData)(vlSelf->fsqrt__DOT__sign_reg) 
                                                  << 0x1fU))
                                            : (((IData)(vlSelf->fsqrt__DOT__sign_reg) 
                                                << 0x1fU) 
                                               | (((IData)(vlSelf->fsqrt__DOT__exp_final) 
                                                   << 0x17U) 
                                                  | vlSelf->fsqrt__DOT__mant_final))));
        vlSelf->fsqrt__DOT__exp_out = (0xffU & ((IData)(0x7fU) 
                                                + (0xffU 
                                                   & (((0xffU 
                                                        & (vlSelf->input_a 
                                                           >> 0x17U)) 
                                                       - (IData)(0x7fU)) 
                                                      >> 1U))));
        vlSelf->fsqrt__DOT__a_fixed = ((0x800000U & vlSelf->input_a)
                                        ? (0x400000U 
                                           | (0x3fffffU 
                                              & (vlSelf->input_a 
                                                 >> 1U)))
                                        : (0x800000U 
                                           | (0x7fffffU 
                                              & vlSelf->input_a)));
    } else {
        vlSelf->fsqrt__DOT__valid_reg = 0U;
        __Vdly__fsqrt__DOT__is_zero_reg = 0U;
        __Vdly__fsqrt__DOT__is_abnormal_reg = 0U;
        vlSelf->fsqrt__DOT__exp_reg = 0U;
        vlSelf->fsqrt__DOT__a_x0_reg = 0U;
        vlSelf->fsqrt__DOT__double_x1 = 0U;
        vlSelf->result = 0U;
        vlSelf->fsqrt__DOT__exp_out = 0U;
        vlSelf->fsqrt__DOT__a_fixed = 0U;
    }
    vlSelf->fsqrt__DOT__is_zero_reg = __Vdly__fsqrt__DOT__is_zero_reg;
    vlSelf->fsqrt__DOT__is_abnormal_reg = __Vdly__fsqrt__DOT__is_abnormal_reg;
    vlSelf->out_valid = (1U & ((IData)(vlSelf->fsqrt__DOT__valid_reg) 
                               >> 2U));
    fsqrt__DOT__mul_reg = (0xffffffffffffULL & ((QData)((IData)(vlSelf->fsqrt__DOT__a_x0_reg)) 
                                                * (QData)((IData)(vlSelf->fsqrt__DOT__double_x1))));
    fsqrt__DOT__result_inner = (0xffffffU & ((IData)(
                                                     (fsqrt__DOT__mul_reg 
                                                      >> 0x16U)) 
                                             + (1U 
                                                & (IData)(
                                                          (fsqrt__DOT__mul_reg 
                                                           >> 0x15U)))));
    if ((0x800000U & fsqrt__DOT__result_inner)) {
        vlSelf->fsqrt__DOT__exp_final = vlSelf->fsqrt__DOT__exp_reg;
        vlSelf->fsqrt__DOT__mant_final = (0x7fffffU 
                                          & fsqrt__DOT__result_inner);
    } else {
        vlSelf->fsqrt__DOT__exp_final = (0xffU & ((IData)(vlSelf->fsqrt__DOT__exp_reg) 
                                                  - (IData)(1U)));
        vlSelf->fsqrt__DOT__mant_final = (0x7ffffeU 
                                          & (fsqrt__DOT__result_inner 
                                             << 1U));
    }
    vlSelf->fsqrt__DOT__sign_reg = ((IData)(vlSelf->rst_n) 
                                    && (IData)(vlSelf->fsqrt__DOT__sign_out));
    vlSelf->fsqrt__DOT__sign_out = ((IData)(vlSelf->rst_n) 
                                    && (vlSelf->input_a 
                                        >> 0x1fU));
}

VL_INLINE_OPT void Vfsqrt_3___024root___nba_sequent__TOP__1(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->fsqrt__DOT__x_0 = vlSelf->fsqrt__DOT__lut
        [(0x3ffU & (vlSelf->input_a >> 0xeU))];
    vlSelf->fsqrt__DOT__x0_x0 = vlSelf->fsqrt__DOT__lut_sq
        [(0x3ffU & (vlSelf->input_a >> 0xeU))];
}

void Vfsqrt_3___024root___eval_nba(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfsqrt_3___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vfsqrt_3___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vfsqrt_3___024root___eval_triggers__act(Vfsqrt_3___024root* vlSelf);

bool Vfsqrt_3___024root___eval_phase__act(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vfsqrt_3___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vfsqrt_3___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vfsqrt_3___024root___eval_phase__nba(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vfsqrt_3___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__nba(Vfsqrt_3___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__act(Vfsqrt_3___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsqrt_3___024root___eval(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vfsqrt_3___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("fsqrt_3.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vfsqrt_3___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("fsqrt_3.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vfsqrt_3___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vfsqrt_3___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vfsqrt_3___024root___eval_debug_assertions(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
