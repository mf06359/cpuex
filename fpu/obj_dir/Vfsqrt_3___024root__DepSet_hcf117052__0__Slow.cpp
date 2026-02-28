// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfsqrt_3.h for the primary calling header

#include "Vfsqrt_3__pch.h"
#include "Vfsqrt_3__Syms.h"
#include "Vfsqrt_3___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfsqrt_3___024root___dump_triggers__stl(Vfsqrt_3___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfsqrt_3___024root___eval_triggers__stl(Vfsqrt_3___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfsqrt_3__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfsqrt_3___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfsqrt_3___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
