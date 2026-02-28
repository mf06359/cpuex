// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_3.h for the primary calling header

#include "Vfsqrt_3__pch.h"
#include "Vfsqrt_3__Syms.h"
#include "Vfsqrt_3___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__act(Vfsqrt_3___024root* vlSelf);
#endif  // VL_DEBUG

void Vfsqrt_3___024root___eval_triggers__act(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->rst_n)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__rst_n__0))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = vlSelf->rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfsqrt_3___024root___dump_triggers__act(vlSelf);
    }
#endif
}
