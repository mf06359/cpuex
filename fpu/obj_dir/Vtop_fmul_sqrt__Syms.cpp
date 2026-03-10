// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop_fmul_sqrt__pch.h"
#include "Vtop_fmul_sqrt.h"
#include "Vtop_fmul_sqrt___024root.h"

// FUNCTIONS
Vtop_fmul_sqrt__Syms::~Vtop_fmul_sqrt__Syms()
{
}

Vtop_fmul_sqrt__Syms::Vtop_fmul_sqrt__Syms(VerilatedContext* contextp, const char* namep, Vtop_fmul_sqrt* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
