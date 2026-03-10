// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfsqrt__pch.h"

//============================================================
// Constructors

Vfsqrt::Vfsqrt(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfsqrt__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst_n{vlSymsp->TOP.rst_n}
    , input_valid{vlSymsp->TOP.input_valid}
    , out_valid{vlSymsp->TOP.out_valid}
    , input_a{vlSymsp->TOP.input_a}
    , result{vlSymsp->TOP.result}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vfsqrt::Vfsqrt(const char* _vcname__)
    : Vfsqrt(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfsqrt::~Vfsqrt() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfsqrt___024root___eval_debug_assertions(Vfsqrt___024root* vlSelf);
#endif  // VL_DEBUG
void Vfsqrt___024root___eval_static(Vfsqrt___024root* vlSelf);
void Vfsqrt___024root___eval_initial(Vfsqrt___024root* vlSelf);
void Vfsqrt___024root___eval_settle(Vfsqrt___024root* vlSelf);
void Vfsqrt___024root___eval(Vfsqrt___024root* vlSelf);

void Vfsqrt::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfsqrt::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfsqrt___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfsqrt___024root___eval_static(&(vlSymsp->TOP));
        Vfsqrt___024root___eval_initial(&(vlSymsp->TOP));
        Vfsqrt___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfsqrt___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfsqrt::eventsPending() { return false; }

uint64_t Vfsqrt::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfsqrt::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfsqrt___024root___eval_final(Vfsqrt___024root* vlSelf);

VL_ATTR_COLD void Vfsqrt::final() {
    Vfsqrt___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfsqrt::hierName() const { return vlSymsp->name(); }
const char* Vfsqrt::modelName() const { return "Vfsqrt"; }
unsigned Vfsqrt::threads() const { return 1; }
void Vfsqrt::prepareClone() const { contextp()->prepareClone(); }
void Vfsqrt::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vfsqrt::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfsqrt::trace()' called on model that was Verilated without --trace option");
}
