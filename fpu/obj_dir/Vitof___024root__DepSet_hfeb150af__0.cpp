// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vitof.h for the primary calling header

#include "Vitof__pch.h"
#include "Vitof___024root.h"

void Vitof___024root___eval_act(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vitof___024root___nba_sequent__TOP__0(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*7:0*/ itof__DOT____Vconcswap_1_h0380839c__0;
    itof__DOT____Vconcswap_1_h0380839c__0 = 0;
    IData/*22:0*/ itof__DOT____Vconcswap_1_h04fd4a94__0;
    itof__DOT____Vconcswap_1_h04fd4a94__0 = 0;
    CData/*4:0*/ __Vfunc_itof__DOT__lzc32__0__Vfuncout;
    __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_itof__DOT__lzc32__0__v;
    __Vfunc_itof__DOT__lzc32__0__v = 0;
    // Body
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->itof__DOT__s2_valid));
    if (vlSelf->rst_n) {
        if ((0U == vlSelf->itof__DOT__s2_abs_i)) {
            vlSelf->out_f = 0U;
        } else {
            vlSelf->itof__DOT__unnamedblk1__DOT__exp 
                = (0xffU & ((IData)(0x7fU) + ((IData)(0x1fU) 
                                              - (IData)(vlSelf->itof__DOT__s2_lzc))));
            vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                = (vlSelf->itof__DOT__s2_abs_i << (IData)(vlSelf->itof__DOT__s2_lzc));
            vlSelf->itof__DOT__guard = (1U & (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                              >> 7U));
            vlSelf->itof__DOT__round = (1U & (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                              >> 6U));
            vlSelf->itof__DOT__sticky = (0U != (0x3fU 
                                                & vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant));
            vlSelf->itof__DOT__lsb = (1U & (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                            >> 8U));
            if (((IData)(vlSelf->itof__DOT__guard) 
                 & (((IData)(vlSelf->itof__DOT__round) 
                     | (IData)(vlSelf->itof__DOT__sticky)) 
                    | (IData)(vlSelf->itof__DOT__lsb)))) {
                itof__DOT____Vconcswap_1_h0380839c__0 
                    = (0xffU & (((IData)(1U) + (((IData)(vlSelf->itof__DOT__unnamedblk1__DOT__exp) 
                                                 << 0x17U) 
                                                | (0x7fffffU 
                                                   & (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                                      >> 8U)))) 
                                >> 0x17U));
                itof__DOT____Vconcswap_1_h04fd4a94__0 
                    = (0x7fffffU & ((IData)(1U) + (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                                   >> 8U)));
                vlSelf->itof__DOT__unnamedblk1__DOT__exp 
                    = itof__DOT____Vconcswap_1_h0380839c__0;
                vlSelf->itof__DOT__unnamedblk1__DOT__frac 
                    = itof__DOT____Vconcswap_1_h04fd4a94__0;
            } else {
                vlSelf->itof__DOT__unnamedblk1__DOT__frac 
                    = (0x7fffffU & (vlSelf->itof__DOT__unnamedblk1__DOT__shifted_mant 
                                    >> 8U));
            }
            vlSelf->out_f = (((IData)(vlSelf->itof__DOT__s2_sign) 
                              << 0x1fU) | (((IData)(vlSelf->itof__DOT__unnamedblk1__DOT__exp) 
                                            << 0x17U) 
                                           | vlSelf->itof__DOT__unnamedblk1__DOT__frac));
        }
        vlSelf->itof__DOT__s2_valid = vlSelf->itof__DOT__s1_valid;
        vlSelf->itof__DOT__s2_sign = vlSelf->itof__DOT__s1_sign;
        vlSelf->itof__DOT__s2_abs_i = vlSelf->itof__DOT__s1_abs_i;
        __Vfunc_itof__DOT__lzc32__0__v = vlSelf->itof__DOT__s1_abs_i;
        {
            if ((__Vfunc_itof__DOT__lzc32__0__v >> 0x1fU)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0U;
                goto __Vlabel1;
            }
            if ((0x40000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 1U;
                goto __Vlabel1;
            }
            if ((0x20000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 2U;
                goto __Vlabel1;
            }
            if ((0x10000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 3U;
                goto __Vlabel1;
            }
            if ((0x8000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 4U;
                goto __Vlabel1;
            }
            if ((0x4000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 5U;
                goto __Vlabel1;
            }
            if ((0x2000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 6U;
                goto __Vlabel1;
            }
            if ((0x1000000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 7U;
                goto __Vlabel1;
            }
            if ((0x800000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 8U;
                goto __Vlabel1;
            }
            if ((0x400000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 9U;
                goto __Vlabel1;
            }
            if ((0x200000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xaU;
                goto __Vlabel1;
            }
            if ((0x100000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xbU;
                goto __Vlabel1;
            }
            if ((0x80000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xcU;
                goto __Vlabel1;
            }
            if ((0x40000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xdU;
                goto __Vlabel1;
            }
            if ((0x20000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xeU;
                goto __Vlabel1;
            }
            if ((0x10000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0xfU;
                goto __Vlabel1;
            }
            if ((0x8000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x10U;
                goto __Vlabel1;
            }
            if ((0x4000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x11U;
                goto __Vlabel1;
            }
            if ((0x2000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x12U;
                goto __Vlabel1;
            }
            if ((0x1000U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x13U;
                goto __Vlabel1;
            }
            if ((0x800U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x14U;
                goto __Vlabel1;
            }
            if ((0x400U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x15U;
                goto __Vlabel1;
            }
            if ((0x200U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x16U;
                goto __Vlabel1;
            }
            if ((0x100U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x17U;
                goto __Vlabel1;
            }
            if ((0x80U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x18U;
                goto __Vlabel1;
            }
            if ((0x40U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x19U;
                goto __Vlabel1;
            }
            if ((0x20U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1aU;
                goto __Vlabel1;
            }
            if ((0x10U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1bU;
                goto __Vlabel1;
            }
            if ((8U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1cU;
                goto __Vlabel1;
            }
            if ((4U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1dU;
                goto __Vlabel1;
            }
            if ((2U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1eU;
                goto __Vlabel1;
            }
            if ((1U & __Vfunc_itof__DOT__lzc32__0__v)) {
                __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1fU;
                goto __Vlabel1;
            }
            __Vfunc_itof__DOT__lzc32__0__Vfuncout = 0x1fU;
            __Vlabel1: ;
        }
        vlSelf->itof__DOT__s2_lzc = __Vfunc_itof__DOT__lzc32__0__Vfuncout;
        vlSelf->itof__DOT__s1_abs_i = ((vlSelf->in_i 
                                        >> 0x1fU) ? 
                                       ((IData)(1U) 
                                        + (~ vlSelf->in_i))
                                        : vlSelf->in_i);
    } else {
        vlSelf->out_f = 0U;
        vlSelf->itof__DOT__s2_lzc = 0U;
        vlSelf->itof__DOT__s2_abs_i = 0U;
        vlSelf->itof__DOT__s2_sign = 0U;
        vlSelf->itof__DOT__s2_valid = 0U;
        vlSelf->itof__DOT__s1_abs_i = 0U;
    }
    vlSelf->itof__DOT__s1_valid = ((IData)(vlSelf->rst_n) 
                                   && (IData)(vlSelf->input_valid));
    vlSelf->itof__DOT__s1_sign = ((IData)(vlSelf->rst_n) 
                                  && (vlSelf->in_i 
                                      >> 0x1fU));
}

void Vitof___024root___eval_nba(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vitof___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vitof___024root___eval_triggers__act(Vitof___024root* vlSelf);

bool Vitof___024root___eval_phase__act(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vitof___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vitof___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vitof___024root___eval_phase__nba(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vitof___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitof___024root___dump_triggers__nba(Vitof___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vitof___024root___dump_triggers__act(Vitof___024root* vlSelf);
#endif  // VL_DEBUG

void Vitof___024root___eval(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vitof___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("itof_without_fadd.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vitof___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("itof_without_fadd.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vitof___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vitof___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vitof___024root___eval_debug_assertions(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
