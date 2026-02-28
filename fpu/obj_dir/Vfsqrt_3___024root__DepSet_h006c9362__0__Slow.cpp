// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_3.h for the primary calling header

#include "Vfsqrt_3__pch.h"
#include "Vfsqrt_3___024root.h"

VL_ATTR_COLD void Vfsqrt_3___024root___eval_static(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vfsqrt_3___024root___eval_initial__TOP(Vfsqrt_3___024root* vlSelf);

VL_ATTR_COLD void Vfsqrt_3___024root___eval_initial(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_initial\n"); );
    // Body
    Vfsqrt_3___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
}

VL_ATTR_COLD void Vfsqrt_3___024root___eval_initial__TOP(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e686578U;
    __Vtemp_1[1U] = 0x61626c65U;
    __Vtemp_1[2U] = 0x72745f74U;
    __Vtemp_1[3U] = 0x667371U;
    VL_READMEM_N(true, 24, 1024, 0, VL_CVT_PACK_STR_NW(4, __Vtemp_1)
                 ,  &(vlSelf->fsqrt__DOT__lut), 0, ~0ULL);
}

VL_ATTR_COLD void Vfsqrt_3___024root___eval_final(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__stl(Vfsqrt_3___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vfsqrt_3___024root___eval_phase__stl(Vfsqrt_3___024root* vlSelf);

VL_ATTR_COLD void Vfsqrt_3___024root___eval_settle(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_settle\n"); );
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
            Vfsqrt_3___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("fsqrt_3.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vfsqrt_3___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__stl(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsqrt_3___024root___stl_sequent__TOP__0(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*23:0*/ fsqrt__DOT__x0_x0;
    fsqrt__DOT__x0_x0 = 0;
    QData/*47:0*/ fsqrt__DOT__mul_reg;
    fsqrt__DOT__mul_reg = 0;
    // Body
    vlSelf->out_valid = (1U & ((IData)(vlSelf->fsqrt__DOT__valid_reg) 
                               >> 2U));
    fsqrt__DOT__x0_x0 = (0xffffffU & (IData)((0xffffffULL 
                                              & (((QData)((IData)(vlSelf->fsqrt__DOT__x_0)) 
                                                  * (QData)((IData)(vlSelf->fsqrt__DOT__x_0))) 
                                                 >> 0x18U))));
    vlSelf->fsqrt__DOT__a_x0_x0 = (0xffffffU & (IData)(
                                                       (0xffffffULL 
                                                        & (((QData)((IData)(vlSelf->fsqrt__DOT__a_fixed)) 
                                                            * (QData)((IData)(fsqrt__DOT__x0_x0))) 
                                                           >> 0x18U))));
    fsqrt__DOT__mul_reg = (0xffffffffffffULL & ((QData)((IData)(vlSelf->fsqrt__DOT__a_x0_reg)) 
                                                * (QData)((IData)(vlSelf->fsqrt__DOT__double_x1))));
    vlSelf->fsqrt__DOT__result_inner = (0xffffffU & (IData)(
                                                            (fsqrt__DOT__mul_reg 
                                                             >> 0x16U)));
}

VL_ATTR_COLD void Vfsqrt_3___024root___eval_stl(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vfsqrt_3___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vfsqrt_3___024root___eval_triggers__stl(Vfsqrt_3___024root* vlSelf);

VL_ATTR_COLD bool Vfsqrt_3___024root___eval_phase__stl(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vfsqrt_3___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vfsqrt_3___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__act(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__nba(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsqrt_3___024root___ctor_var_reset(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst_n = VL_RAND_RESET_I(1);
    vlSelf->input_a = VL_RAND_RESET_I(32);
    vlSelf->input_valid = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->out_valid = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->fsqrt__DOT__lut[__Vi0] = VL_RAND_RESET_I(24);
    }
    vlSelf->fsqrt__DOT__valid_reg = VL_RAND_RESET_I(3);
    vlSelf->fsqrt__DOT__is_zero_reg = VL_RAND_RESET_I(3);
    vlSelf->fsqrt__DOT__is_abnormal_reg = VL_RAND_RESET_I(3);
    vlSelf->fsqrt__DOT__exp_out = VL_RAND_RESET_I(8);
    vlSelf->fsqrt__DOT__sign_out = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT__a_fixed = VL_RAND_RESET_I(24);
    vlSelf->fsqrt__DOT__x_0 = VL_RAND_RESET_I(24);
    vlSelf->fsqrt__DOT__double_x1 = VL_RAND_RESET_I(24);
    vlSelf->fsqrt__DOT__a_x0_x0 = VL_RAND_RESET_I(24);
    vlSelf->fsqrt__DOT__a_x0_reg = VL_RAND_RESET_I(24);
    vlSelf->fsqrt__DOT__exp_reg = VL_RAND_RESET_I(8);
    vlSelf->fsqrt__DOT__sign_reg = VL_RAND_RESET_I(1);
    vlSelf->fsqrt__DOT__result_inner = VL_RAND_RESET_I(24);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = VL_RAND_RESET_I(1);
}
