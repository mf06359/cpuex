// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfsqrt_10__pch.h"

//============================================================
// Constructors

Vfsqrt_10::Vfsqrt_10(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vfsqrt_10__Syms(contextp(), _vcname__, this)}
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

Vfsqrt_10::Vfsqrt_10(const char* _vcname__)
    : Vfsqrt_10(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vfsqrt_10::~Vfsqrt_10() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vfsqrt_10___024root___eval_debug_assertions(Vfsqrt_10___024root* vlSelf);
#endif  // VL_DEBUG
void Vfsqrt_10___024root___eval_static(Vfsqrt_10___024root* vlSelf);
void Vfsqrt_10___024root___eval_initial(Vfsqrt_10___024root* vlSelf);
void Vfsqrt_10___024root___eval_settle(Vfsqrt_10___024root* vlSelf);
void Vfsqrt_10___024root___eval(Vfsqrt_10___024root* vlSelf);

void Vfsqrt_10::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfsqrt_10::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfsqrt_10___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vfsqrt_10___024root___eval_static(&(vlSymsp->TOP));
        Vfsqrt_10___024root___eval_initial(&(vlSymsp->TOP));
        Vfsqrt_10___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vfsqrt_10___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vfsqrt_10::eventsPending() { return false; }

uint64_t Vfsqrt_10::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vfsqrt_10::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vfsqrt_10___024root___eval_final(Vfsqrt_10___024root* vlSelf);

VL_ATTR_COLD void Vfsqrt_10::final() {
    Vfsqrt_10___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vfsqrt_10::hierName() const { return vlSymsp->name(); }
const char* Vfsqrt_10::modelName() const { return "Vfsqrt_10"; }
unsigned Vfsqrt_10::threads() const { return 1; }
void Vfsqrt_10::prepareClone() const { contextp()->prepareClone(); }
void Vfsqrt_10::atClone() const {
    contextp()->threadPoolpOnClone();
}

//============================================================
// Trace configuration

VL_ATTR_COLD void Vfsqrt_10::trace(VerilatedVcdC* tfp, int levels, int options) {
    vl_fatal(__FILE__, __LINE__, __FILE__,"'Vfsqrt_10::trace()' called on model that was Verilated without --trace option");
}
