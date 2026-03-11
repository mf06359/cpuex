// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vftoi.h for the primary calling header

#include "Vftoi__pch.h"

void Vftoi___024root___ctor_var_reset(Vftoi___024root* vlSelf);

Vftoi___024root::Vftoi___024root(Vftoi__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vftoi___024root___ctor_var_reset(this);
}

void Vftoi___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vftoi___024root::~Vftoi___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
