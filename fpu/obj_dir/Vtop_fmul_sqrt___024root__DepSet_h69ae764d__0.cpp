// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_fmul_sqrt.h for the primary calling header

#include "Vtop_fmul_sqrt__pch.h"
#include "Vtop_fmul_sqrt___024root.h"

VL_INLINE_OPT void Vtop_fmul_sqrt___024root___ico_sequent__TOP__0(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a 
        = (vlSelf->a >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b 
        = (vlSelf->top_fmul_sqrt__DOT__sqrt_res >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a) 
           ^ (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a 
        = (0xffU & (vlSelf->a >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b 
        = (0xffU & (vlSelf->top_fmul_sqrt__DOT__sqrt_res 
                    >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a))
            ? (0x7fffffU & vlSelf->a) : (0x800000U 
                                         | (0x7fffffU 
                                            & vlSelf->a)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b))
            ? (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)
            : (0x800000U | (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a)) 
           | (0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp 
        = (0x3ffU & (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a) 
                      + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)) 
                     - (IData)(0x7fU)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod 
        = (0xffffffffffffULL & ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a)) 
                                * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b))));
}

void Vtop_fmul_sqrt___024root___eval_ico(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vtop_fmul_sqrt___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void Vtop_fmul_sqrt___024root___eval_triggers__ico(Vtop_fmul_sqrt___024root* vlSelf);

bool Vtop_fmul_sqrt___024root___eval_phase__ico(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop_fmul_sqrt___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vtop_fmul_sqrt___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop_fmul_sqrt___024root___eval_act(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vtop_fmul_sqrt___024root___nba_sequent__TOP__0(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*2:0*/ __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg;
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg = 0;
    CData/*2:0*/ __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg;
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg = 0;
    CData/*2:0*/ __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg;
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg = 0;
    // Body
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg;
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg;
    __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg;
    if (vlSelf->rst_n) {
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg 
            = ((6U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg) 
                      << 1U)) | (IData)(vlSelf->input_valid));
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg 
            = ((6U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg) 
                      << 1U)) | (IData)((0U == (0x7fffffffU 
                                                & vlSelf->b))));
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg 
            = ((6U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg) 
                      << 1U)) | (0xffU == (0xffU & 
                                           (vlSelf->b 
                                            >> 0x17U))));
        vlSelf->result = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus 
            = (0xffU & ((IData)(1U) + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out)));
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus 
            = (0xffU & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out) 
                        - (IData)(1U)));
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg 
            = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg 
            = (0xffffffU & (IData)((0xffffffULL & (
                                                   ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                    * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0))) 
                                                   >> 0x18U))));
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg 
            = (0x3ffffU & (- (IData)((0xffffffULL & 
                                      (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                        * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0))) 
                                       >> 0x18U)))));
        vlSelf->top_fmul_sqrt__DOT__sqrt_res = ((2U 
                                                 & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg))
                                                 ? 
                                                ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg) 
                                                 << 0x1fU)
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg))
                                                  ? 
                                                 (0x7f800000U 
                                                  | ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg) 
                                                     << 0x1fU))
                                                  : 
                                                 (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg) 
                                                   << 0x1fU) 
                                                  | (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final) 
                                                      << 0x17U) 
                                                     | vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final))));
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out 
            = (0xffU & ((IData)(0x7fU) + (0xffU & (
                                                   ((0xffU 
                                                     & (vlSelf->b 
                                                        >> 0x17U)) 
                                                    - (IData)(0x7fU)) 
                                                   >> 1U))));
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed 
            = ((0x800000U & vlSelf->b) ? (0x400000U 
                                          | (0x3fffffU 
                                             & (vlSelf->b 
                                                >> 1U)))
                : (0x800000U | (0x7fffffU & vlSelf->b)));
    } else {
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg = 0U;
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg = 0U;
        __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg = 0U;
        vlSelf->result = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg = 0ULL;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg = 0U;
        vlSelf->top_fmul_sqrt__DOT__sqrt_res = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out = 0U;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed = 0U;
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg));
    vlSelf->out_valid = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg 
        = __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg;
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg 
        = __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg;
    if ((1U & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                       >> 0x2fU)))) {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm 
            = (0x7ffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                                     >> 0x14U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky 
            = (0U != (0xfffffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted 
            = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg)));
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm 
            = (0x7ffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg 
                                     >> 0x13U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky 
            = (0U != (0x7ffffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted 
            = (0x3ffU & (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg));
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 3U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 2U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg) 
           | (0U != (3U & vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb 
        = (1U & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                 >> 4U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard) 
           & (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round) 
               | (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky)) 
              | (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb)));
    if (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up) {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & ((IData)(1U) + (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                                           >> 4U)));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked 
            = (0x3ffU & ((0U == vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final)
                          ? ((IData)(1U) + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg))
                          : (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg)));
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final 
            = (0x7fffffU & (vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg 
                            >> 4U));
        vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked 
            = vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg;
    }
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb 
        = (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg) 
            | ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked) 
               >> 9U)) ? ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                          << 0x1fU) : ((0xffU <= (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked))
                                        ? (0x7f800000U 
                                           | ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                                              << 0x1fU))
                                        : (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg) 
                                            << 0x1fU) 
                                           | ((0x7f800000U 
                                               & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked) 
                                                  << 0x17U)) 
                                              | vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final))));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0 = 
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut
        [(0x3ffU & (vlSelf->b >> 0xeU))];
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg;
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult 
        = (0x7ffffffffffULL & VL_MULS_QQQ(43, (0x7ffffffffffULL 
                                               & VL_EXTENDS_QI(43,25, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed)), 
                                          (0x7ffffffffffULL 
                                           & VL_EXTENDS_QI(43,18, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg))));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out 
        = (0xffffffffffffULL & ((0x200000ULL | ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg)) 
                                                << 0x17U)) 
                                + VL_EXTENDS_QQ(48,43, vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult)));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner 
        = (0xffffffU & (IData)((vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out 
                                >> 0x16U)));
    if ((0x800000U & vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner)) {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final 
            = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final 
            = (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner);
    } else {
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final 
            = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus;
        vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final 
            = (0x7ffffeU & (vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner 
                            << 1U));
    }
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0 
        = vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__lut_sq
        [(0x3ffU & (vlSelf->b >> 0xeU))];
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg 
        = ((IData)(vlSelf->rst_n) && (IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a 
        = (vlSelf->a >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b 
        = (vlSelf->top_fmul_sqrt__DOT__sqrt_res >> 0x1fU);
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res 
        = ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a) 
           ^ (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a 
        = (0xffU & (vlSelf->a >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b 
        = (0xffU & (vlSelf->top_fmul_sqrt__DOT__sqrt_res 
                    >> 0x17U));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a))
            ? (0x7fffffU & vlSelf->a) : (0x800000U 
                                         | (0x7fffffU 
                                            & vlSelf->a)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b))
            ? (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)
            : (0x800000U | (0x7fffffU & vlSelf->top_fmul_sqrt__DOT__sqrt_res)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub 
        = ((0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a)) 
           | (0U == (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp 
        = (0x3ffU & (((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a) 
                      + (IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b)) 
                     - (IData)(0x7fU)));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod 
        = (0xffffffffffffULL & ((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a)) 
                                * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b))));
    vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg 
        = ((IData)(vlSelf->rst_n) && (1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg) 
                                            >> 2U)));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out 
        = ((IData)(vlSelf->rst_n) && (vlSelf->b >> 0x1fU));
    vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg 
        = __Vdly__top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg;
}

void Vtop_fmul_sqrt___024root___eval_nba(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtop_fmul_sqrt___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vtop_fmul_sqrt___024root___eval_triggers__act(Vtop_fmul_sqrt___024root* vlSelf);

bool Vtop_fmul_sqrt___024root___eval_phase__act(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop_fmul_sqrt___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtop_fmul_sqrt___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop_fmul_sqrt___024root___eval_phase__nba(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop_fmul_sqrt___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__ico(Vtop_fmul_sqrt___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__nba(Vtop_fmul_sqrt___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_fmul_sqrt___024root___dump_triggers__act(Vtop_fmul_sqrt___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop_fmul_sqrt___024root___eval(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval\n"); );
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
            Vtop_fmul_sqrt___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("top_fmul_sqrt.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vtop_fmul_sqrt___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtop_fmul_sqrt___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top_fmul_sqrt.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtop_fmul_sqrt___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top_fmul_sqrt.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtop_fmul_sqrt___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtop_fmul_sqrt___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop_fmul_sqrt___024root___eval_debug_assertions(Vtop_fmul_sqrt___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst_n & 0xfeU))) {
        Verilated::overWidthError("rst_n");}
    if (VL_UNLIKELY((vlSelf->input_valid & 0xfeU))) {
        Verilated::overWidthError("input_valid");}
}
#endif  // VL_DEBUG
