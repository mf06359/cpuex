// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vfsqrt_10__pch.h"
#include "Vfsqrt_10.h"
#include "Vfsqrt_10___024root.h"

// FUNCTIONS
Vfsqrt_10__Syms::~Vfsqrt_10__Syms()
{
}

Vfsqrt_10__Syms::Vfsqrt_10__Syms(VerilatedContext* contextp, const char* namep, Vfsqrt_10* modelp)
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
