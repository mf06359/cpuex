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

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitof___024root___dump_triggers__stl(Vitof___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vitof___024root___eval_phase__stl(Vitof___024root* vlSelf);

VL_ATTR_COLD void Vitof___024root___eval_settle(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_settle\n"); );
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
            Vitof___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("itof.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vitof___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vitof___024root___dump_triggers__stl(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vitof___024root___stl_sequent__TOP__0(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___stl_sequent__TOP__0\n"); );
    // Body
    if ((0U == vlSelf->itof__DOT__s2_abs_i)) {
        vlSelf->itof__DOT__next_exp = 0U;
        vlSelf->itof__DOT__next_frac = 0U;
    } else {
        vlSelf->itof__DOT__unnamedblk1__DOT__temp_exp 
            = (0xffU & ((IData)(0x7fU) + ((IData)(0x1fU) 
                                          - (IData)(vlSelf->itof__DOT__s2_lzc))));
        vlSelf->itof__DOT__shifted_mant = (vlSelf->itof__DOT__s2_abs_i 
                                           << (IData)(vlSelf->itof__DOT__s2_lzc));
        vlSelf->itof__DOT__guard = (1U & (vlSelf->itof__DOT__shifted_mant 
                                          >> 7U));
        vlSelf->itof__DOT__round = (1U & (vlSelf->itof__DOT__shifted_mant 
                                          >> 6U));
        vlSelf->itof__DOT__sticky = (0U != (0x3fU & vlSelf->itof__DOT__shifted_mant));
        vlSelf->itof__DOT__lsb = (1U & (vlSelf->itof__DOT__shifted_mant 
                                        >> 8U));
        if (((IData)(vlSelf->itof__DOT__guard) & (((IData)(vlSelf->itof__DOT__round) 
                                                   | (IData)(vlSelf->itof__DOT__sticky)) 
                                                  | (IData)(vlSelf->itof__DOT__lsb)))) {
            vlSelf->itof__DOT__next_exp = (0xffU & 
                                           (((IData)(1U) 
                                             + (((IData)(vlSelf->itof__DOT__unnamedblk1__DOT__temp_exp) 
                                                 << 0x17U) 
                                                | (0x7fffffU 
                                                   & (vlSelf->itof__DOT__shifted_mant 
                                                      >> 8U)))) 
                                            >> 0x17U));
            vlSelf->itof__DOT__next_frac = (0x7fffffU 
                                            & ((IData)(1U) 
                                               + (vlSelf->itof__DOT__shifted_mant 
                                                  >> 8U)));
        } else {
            vlSelf->itof__DOT__next_exp = vlSelf->itof__DOT__unnamedblk1__DOT__temp_exp;
            vlSelf->itof__DOT__next_frac = (0x7fffffU 
                                            & (vlSelf->itof__DOT__shifted_mant 
                                               >> 8U));
        }
    }
}

VL_ATTR_COLD void Vitof___024root___eval_stl(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vitof___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vitof___024root___eval_triggers__stl(Vitof___024root* vlSelf);

VL_ATTR_COLD bool Vitof___024root___eval_phase__stl(Vitof___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vitof__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vitof___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vitof___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vitof___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
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
    vlSelf->itof__DOT__next_exp = VL_RAND_RESET_I(8);
    vlSelf->itof__DOT__next_frac = VL_RAND_RESET_I(23);
    vlSelf->itof__DOT__shifted_mant = VL_RAND_RESET_I(32);
    vlSelf->itof__DOT__guard = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__round = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__sticky = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__lsb = VL_RAND_RESET_I(1);
    vlSelf->itof__DOT__unnamedblk1__DOT__temp_exp = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
}
