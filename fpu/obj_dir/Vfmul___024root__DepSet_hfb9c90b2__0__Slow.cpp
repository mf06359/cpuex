// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfmul.h for the primary calling header

#include "Vfmul__pch.h"
#include "Vfmul__Syms.h"
#include "Vfmul___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vfmul___024root___dump_triggers__stl(Vfmul___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vfmul___024root___eval_triggers__stl(Vfmul___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfmul__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfmul___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vfmul___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
