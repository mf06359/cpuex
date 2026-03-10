// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop_fmul_sqrt__Syms.h"


VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_init_sub__TOP__0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"input_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+71,0,"out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("top_fmul_sqrt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+68,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"input_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+71,0,"out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"sqrt_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"sqrt_out_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_fmul", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+67,0,"input_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"input_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"input_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+71,0,"out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+2,0,"s1_sign_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+3,0,"s1_sign_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s1_exp_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+5,0,"s1_exp_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+6,0,"s1_mant_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+7,0,"s1_mant_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBit(c+8,0,"c1_sign_res",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"c1_exp_temp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declQuad(c+10,0,"c1_mant_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+12,0,"c1_is_zero_or_sub",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"s1_sign_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+16,0,"s1_exp_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declQuad(c+17,0,"s1_prod_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBit(c+19,0,"s1_valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"s1_zero_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+21,0,"c2_exp_adjusted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBit(c+22,0,"c2_sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+23,0,"c2_mant_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBit(c+24,0,"s2_sign_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+25,0,"s2_exp_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+26,0,"s2_mant_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 26,0);
    tracep->declBit(c+27,0,"s2_sticky_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"s2_valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"s2_zero_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+30,0,"c3_result_comb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+31,0,"guard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"round",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+33,0,"sticky",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+34,0,"lsb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"round_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"frac_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+37,0,"exp_checked",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_fsqrt", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+65,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+68,0,"input_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+69,0,"input_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+13,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+14,0,"out_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"delta_24",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+39,0,"is_zero_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+40,0,"is_abnormal_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declQuad(c+41,0,"P_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 47,0);
    tracep->declBus(c+79,0,"double_x1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+43,0,"exp_reg_plus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+44,0,"valid_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+72,0,"in_is_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"in_is_abnormal",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"is_zero_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"is_abnormal_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"s_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+75,0,"e_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+76,0,"m_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->declBus(c+47,0,"exp_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+48,0,"sign_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+49,0,"a_fixed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+50,0,"x_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+51,0,"x0_x0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+77,0,"lut_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 9,0);
    tracep->declBus(c+78,0,"e_wo_bias",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 8,0);
    tracep->declBus(c+52,0,"a_x0_x0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+53,0,"a_x0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+54,0,"a_x0_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+55,0,"delta_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 17,0);
    tracep->declBus(c+56,0,"exp_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+57,0,"exp_reg_minus",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+58,0,"sign_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"a_x0_signed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 24,0);
    tracep->declQuad(c+60,0,"delta_mult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 42,0);
    tracep->declBus(c+62,0,"result_inner",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 23,0);
    tracep->declBus(c+63,0,"exp_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+64,0,"mant_final",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 22,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_init_top(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_init_top\n"); );
    // Body
    Vtop_fmul_sqrt___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_fmul_sqrt___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtop_fmul_sqrt___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_register(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtop_fmul_sqrt___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtop_fmul_sqrt___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtop_fmul_sqrt___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtop_fmul_sqrt___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_const_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_const_0\n"); );
    // Init
    Vtop_fmul_sqrt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_fmul_sqrt___024root*>(voidSelf);
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop_fmul_sqrt___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_const_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+79,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__double_x1),24);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_full_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_full_0\n"); );
    // Init
    Vtop_fmul_sqrt___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop_fmul_sqrt___024root*>(voidSelf);
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop_fmul_sqrt___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtop_fmul_sqrt___024root__trace_full_0_sub_0(Vtop_fmul_sqrt___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop_fmul_sqrt__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_fmul_sqrt___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__unnamedblk1__DOT__i),32);
    bufp->fullBit(oldp+2,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_a));
    bufp->fullBit(oldp+3,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_b));
    bufp->fullCData(oldp+4,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_a),8);
    bufp->fullCData(oldp+5,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_b),8);
    bufp->fullIData(oldp+6,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_a),24);
    bufp->fullIData(oldp+7,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_mant_b),24);
    bufp->fullBit(oldp+8,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_sign_res));
    bufp->fullSData(oldp+9,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_exp_temp),10);
    bufp->fullQData(oldp+10,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_mant_prod),48);
    bufp->fullBit(oldp+12,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c1_is_zero_or_sub));
    bufp->fullIData(oldp+13,(vlSelf->top_fmul_sqrt__DOT__sqrt_res),32);
    bufp->fullBit(oldp+14,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg) 
                                  >> 2U))));
    bufp->fullBit(oldp+15,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_sign_reg));
    bufp->fullSData(oldp+16,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_exp_reg),10);
    bufp->fullQData(oldp+17,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_prod_reg),48);
    bufp->fullBit(oldp+19,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_valid_reg));
    bufp->fullBit(oldp+20,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s1_zero_reg));
    bufp->fullSData(oldp+21,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_exp_adjusted),10);
    bufp->fullBit(oldp+22,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_sticky));
    bufp->fullIData(oldp+23,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c2_mant_norm),27);
    bufp->fullBit(oldp+24,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sign_reg));
    bufp->fullSData(oldp+25,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_exp_reg),10);
    bufp->fullIData(oldp+26,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_mant_reg),27);
    bufp->fullBit(oldp+27,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_sticky_reg));
    bufp->fullBit(oldp+28,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_valid_reg));
    bufp->fullBit(oldp+29,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__s2_zero_reg));
    bufp->fullIData(oldp+30,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__c3_result_comb),32);
    bufp->fullBit(oldp+31,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__guard));
    bufp->fullBit(oldp+32,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round));
    bufp->fullBit(oldp+33,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__sticky));
    bufp->fullBit(oldp+34,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__lsb));
    bufp->fullBit(oldp+35,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__round_up));
    bufp->fullIData(oldp+36,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__frac_final),23);
    bufp->fullSData(oldp+37,(vlSelf->top_fmul_sqrt__DOT__u_fmul__DOT__unnamedblk1__DOT__exp_checked),10);
    bufp->fullIData(oldp+38,((0xffffffU & ((IData)(0x400000U) 
                                           - (IData)(
                                                     (0xffffffULL 
                                                      & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                          * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0))) 
                                                         >> 0x18U)))))),24);
    bufp->fullCData(oldp+39,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg),3);
    bufp->fullCData(oldp+40,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg),3);
    bufp->fullQData(oldp+41,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__P_out),48);
    bufp->fullCData(oldp+43,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_plus),8);
    bufp->fullCData(oldp+44,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__valid_reg),3);
    bufp->fullBit(oldp+45,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_zero_reg) 
                                  >> 1U))));
    bufp->fullBit(oldp+46,((1U & ((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__is_abnormal_reg) 
                                  >> 1U))));
    bufp->fullCData(oldp+47,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_out),8);
    bufp->fullBit(oldp+48,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_out));
    bufp->fullIData(oldp+49,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed),24);
    bufp->fullIData(oldp+50,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0),24);
    bufp->fullIData(oldp+51,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0),24);
    bufp->fullIData(oldp+52,((0xffffffU & (IData)((0xffffffULL 
                                                   & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                       * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x0_x0))) 
                                                      >> 0x18U))))),24);
    bufp->fullIData(oldp+53,((0xffffffU & (IData)((0xffffffULL 
                                                   & (((QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_fixed)) 
                                                       * (QData)((IData)(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__x_0))) 
                                                      >> 0x18U))))),24);
    bufp->fullIData(oldp+54,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_reg),24);
    bufp->fullIData(oldp+55,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_reg),18);
    bufp->fullCData(oldp+56,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg),8);
    bufp->fullCData(oldp+57,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_reg_minus),8);
    bufp->fullBit(oldp+58,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__sign_reg));
    bufp->fullIData(oldp+59,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__a_x0_signed),25);
    bufp->fullQData(oldp+60,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__delta_mult),43);
    bufp->fullIData(oldp+62,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__result_inner),24);
    bufp->fullCData(oldp+63,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__exp_final),8);
    bufp->fullIData(oldp+64,(vlSelf->top_fmul_sqrt__DOT__u_fsqrt__DOT__mant_final),23);
    bufp->fullBit(oldp+65,(vlSelf->clk));
    bufp->fullBit(oldp+66,(vlSelf->rst_n));
    bufp->fullIData(oldp+67,(vlSelf->a),32);
    bufp->fullIData(oldp+68,(vlSelf->b),32);
    bufp->fullBit(oldp+69,(vlSelf->input_valid));
    bufp->fullIData(oldp+70,(vlSelf->result),32);
    bufp->fullBit(oldp+71,(vlSelf->out_valid));
    bufp->fullBit(oldp+72,((IData)((0U == (0x7fffffffU 
                                           & vlSelf->b)))));
    bufp->fullBit(oldp+73,((0xffU == (0xffU & (vlSelf->b 
                                               >> 0x17U)))));
    bufp->fullBit(oldp+74,((vlSelf->b >> 0x1fU)));
    bufp->fullCData(oldp+75,((0xffU & (vlSelf->b >> 0x17U))),8);
    bufp->fullIData(oldp+76,((0x7fffffU & vlSelf->b)),23);
    bufp->fullSData(oldp+77,((0x3ffU & (vlSelf->b >> 0xeU))),10);
    bufp->fullSData(oldp+78,((0x1ffU & ((0xffU & (vlSelf->b 
                                                  >> 0x17U)) 
                                        - (IData)(0x7fU)))),9);
}
