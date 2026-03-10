// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_fmul_sqrt__Syms.h"


void Vtop_fmul_sqrt___024root__trace_chg_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop_fmul_sqrt___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_chg_0\n"); );
    // Init
    Vtop_fmul_sqrt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_fmul_sqrt___024root*>(voidSelf);
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop_fmul_sqrt___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop_fmul_sqrt___024root__trace_chg_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgIData(oldp+0,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__unnamedblk1__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+1,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a));
        bufp->chgBit(oldp+2,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b));
        bufp->chgCData(oldp+3,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a),8);
        bufp->chgCData(oldp+4,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b),8);
        bufp->chgIData(oldp+5,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a),24);
        bufp->chgIData(oldp+6,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b),24);
        bufp->chgBit(oldp+7,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res));
        bufp->chgSData(oldp+8,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp),10);
        bufp->chgQData(oldp+9,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod),48);
        bufp->chgBit(oldp+11,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+12,(vlSelf->top_fmul_sqrt__DOT__sqrt_res),32);
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg) 
                                     >> 2U))));
        bufp->chgBit(oldp+14,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg));
        bufp->chgSData(oldp+15,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg),10);
        bufp->chgQData(oldp+16,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg),48);
        bufp->chgBit(oldp+18,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg));
        bufp->chgBit(oldp+19,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg));
        bufp->chgSData(oldp+20,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted),10);
        bufp->chgBit(oldp+21,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky));
        bufp->chgIData(oldp+22,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm),27);
        bufp->chgBit(oldp+23,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg));
        bufp->chgSData(oldp+24,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg),10);
        bufp->chgIData(oldp+25,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg),27);
        bufp->chgBit(oldp+26,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg));
        bufp->chgBit(oldp+27,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg));
        bufp->chgBit(oldp+28,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg));
        bufp->chgIData(oldp+29,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb),32);
        bufp->chgBit(oldp+30,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard));
        bufp->chgBit(oldp+31,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round));
        bufp->chgBit(oldp+32,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky));
        bufp->chgBit(oldp+33,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb));
        bufp->chgBit(oldp+34,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up));
        bufp->chgIData(oldp+35,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final),23);
        bufp->chgSData(oldp+36,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked),10);
        bufp->chgIData(oldp+37,((0xffffffU & ((IData)(0x400000U) 
                                              - (IData)(
                                                        (0xffffffULL 
                                                         & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                             * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0))) 
                                                            >> 0x18U)))))),24);
        bufp->chgCData(oldp+38,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg),3);
        bufp->chgCData(oldp+39,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg),3);
        bufp->chgQData(oldp+40,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out),48);
        bufp->chgCData(oldp+42,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus),8);
        bufp->chgCData(oldp+43,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg),3);
        bufp->chgBit(oldp+44,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg) 
                                     >> 1U))));
        bufp->chgBit(oldp+45,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg) 
                                     >> 1U))));
        bufp->chgCData(oldp+46,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out),8);
        bufp->chgBit(oldp+47,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out));
        bufp->chgIData(oldp+48,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed),24);
        bufp->chgIData(oldp+49,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0),24);
        bufp->chgIData(oldp+50,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0),24);
        bufp->chgIData(oldp+51,((0xffffffU & (IData)(
                                                     (0xffffffULL 
                                                      & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                          * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0))) 
                                                         >> 0x18U))))),24);
        bufp->chgIData(oldp+52,((0xffffffU & (IData)(
                                                     (0xffffffULL 
                                                      & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                          * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0))) 
                                                         >> 0x18U))))),24);
        bufp->chgIData(oldp+53,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg),24);
        bufp->chgIData(oldp+54,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg),18);
        bufp->chgCData(oldp+55,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg),8);
        bufp->chgCData(oldp+56,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus),8);
        bufp->chgBit(oldp+57,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg));
        bufp->chgIData(oldp+58,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed),25);
        bufp->chgQData(oldp+59,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult),43);
        bufp->chgIData(oldp+61,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner),24);
        bufp->chgCData(oldp+62,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final),8);
        bufp->chgIData(oldp+63,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final),23);
    }
    bufp->chgBit(oldp+64,(vlSelf->clk));
    bufp->chgBit(oldp+65,(vlSelf->rst_n));
    bufp->chgIData(oldp+66,(vlSelf->a),32);
    bufp->chgIData(oldp+67,(vlSelf->b),32);
    bufp->chgBit(oldp+68,(vlSelf->input_valid));
    bufp->chgIData(oldp+69,(vlSelf->result),32);
    bufp->chgBit(oldp+70,(vlSelf->out_valid));
    bufp->chgBit(oldp+71,((IData)((0U == (0x7fffffffU 
                                          & vlSelf->b)))));
    bufp->chgBit(oldp+72,((0xffU == (0xffU & (vlSelf->b 
                                              >> 0x17U)))));
    bufp->chgBit(oldp+73,((vlSelf->b >> 0x1fU)));
    bufp->chgCData(oldp+74,((0xffU & (vlSelf->b >> 0x17U))),8);
    bufp->chgIData(oldp+75,((0x7fffffU & vlSelf->b)),23);
    bufp->chgSData(oldp+76,((0x3ffU & (vlSelf->b >> 0xeU))),10);
    bufp->chgSData(oldp+77,((0x1ffU & ((0xffU & (vlSelf->b 
                                                 >> 0x17U)) 
                                       - (IData)(0x7fU)))),9);
}

void Vtop_fmul_sqrt___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_cleanup\n"); );
    // Init
    Vtop_fmul_sqrt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_fmul_sqrt___024root*>(voidSelf);
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
