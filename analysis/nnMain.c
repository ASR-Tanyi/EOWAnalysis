// Lifted AArch64: main+0x360b70 nnMain (FDE+symbol).
#include "cpu.h"
#include "simd.h"

void f_70000001d0(Cpu *c);
void f_700008dba0(Cpu *c);
void f_700008e058(Cpu *c);
void f_700032ca20(Cpu *c);
void f_700032ca34(Cpu *c);
void f_7000331350(Cpu *c);
void f_700033a1f0(Cpu *c);
void f_700033a560(Cpu *c);
void f_70003458b0(Cpu *c);
void f_7000357070(Cpu *c);
void f_7000359018(Cpu *c);
void f_700035b60c(Cpu *c);
void f_7000360050(Cpu *c);
static void f_7000362c78(Cpu *c) {
    c->pc = 0x7000362c78ull;
    rt_dispatch(c);
}
void f_7000611d94(Cpu *c);
void f_70006126a0(Cpu *c);
void f_7000c3bda0(Cpu *c);
void f_70015891f0(Cpu *c);
void f_70018603a0(Cpu *c);
void f_7002362258(Cpu *c);
void f_700267aa60(Cpu *c);
void f_700267f040(Cpu *c);
void f_700267f2f0(Cpu *c);
void f_70026a1ab0(Cpu *c);
void f_7002707990(Cpu *c);
void f_70027360c0(Cpu *c);
void f_700273eca0(Cpu *c);
void f_70027474a4(Cpu *c);
void f_7002756830(Cpu *c);
void f_7002771c20(Cpu *c);
void f_7002819640(Cpu *c);
void f_70028311a0(Cpu *c);
void f_700283155c(Cpu *c);
void f_7002833e20(Cpu *c);  // plt:_ZdlPv
void f_7002833e30(Cpu *c);  // plt:__cxa_guard_acquire
void f_7002833e40(Cpu *c);  // plt:__cxa_guard_release
void f_7002833e50(Cpu *c);  // plt:_ZNSt3__119__shared_weak_count14__release_weakEv
void f_7002833ea0(Cpu *c);  // plt:_ZN2nn4time8FinalizeEv
void f_7002833eb0(Cpu *c);  // plt:_Znwm
void f_7002833f10(Cpu *c);  // plt:_ZN2nn3mem17StandardAllocator8AllocateEmm
void f_7002833f20(Cpu *c);  // plt:_ZN2nn3mem17StandardAllocator4FreeEPv
void f_7002833f70(Cpu *c);  // plt:_ZN2nn3mem17StandardAllocatorC1Ev
void f_7002833fc0(Cpu *c);  // plt:_ZNSt3__15mutex4lockEv
void f_7002833fd0(Cpu *c);  // plt:_ZNSt3__15mutex6unlockEv
void f_7002834000(Cpu *c);  // plt:_ZdaPv
void f_7002834040(Cpu *c);  // plt:_ZN2nn4diag6detail9AbortImplEPKNS_6ResultE
void f_7002834070(Cpu *c);  // plt:_ZN2nn2fs7UnmountEPKc
void f_70028340d0(Cpu *c);  // plt:_ZNSt3__17promiseIvEC1Ev
void f_7002834260(Cpu *c);  // plt:_ZNSt3__115recursive_mutex6unlockEv
void f_7002834270(Cpu *c);  // plt:_ZNSt3__115recursive_mutexC1Ev
void f_7002834520(Cpu *c);  // plt:sched_yield
void f_7002834e10(Cpu *c);  // plt:_ZN2nn2os15InitializeEventEPNS0_9EventTypeEbNS0_14EventClearModeE
void f_7002835390(Cpu *c);  // plt:_ZN2nn3mem17StandardAllocator10InitializeEPvm
void f_70028353c0(Cpu *c);  // plt:_ZN2nn3mem17StandardAllocator8FinalizeEv
void f_70028354c0(Cpu *c);  // plt:_ZN2nn2oe44SetPerformanceModeChangedNotificationEnabledEb
void f_70028354d0(Cpu *c);  // plt:_ZN2nn2oe42SetOperationModeChangedNotificationEnabledEb
void f_70028354e0(Cpu *c);  // plt:_ZN2nn2oe28SetResumeNotificationEnabledEb
void f_70028354f0(Cpu *c);  // plt:_ZN2nn2oe31EnterExitRequestHandlingSectionEv
void f_7002835560(Cpu *c);  // plt:_ZN2nv20SetGraphicsAllocatorEPFPvmmS0_EPFvS0_S0_EPFS0_S0_mS0_ES0_
void f_7002835570(Cpu *c);  // plt:_ZN2nv28SetGraphicsDevtoolsAllocatorEPFPvmmS0_EPFvS0_S0_EPFS0_S0_mS0_ES0_
void f_7002835580(Cpu *c);  // plt:_ZN2nv18InitializeGraphicsEPvm
void f_7002835700(Cpu *c);  // plt:memset

void f_7000360b70(Cpu *CPU_RESTRICT c) {
    FN_ENTER(0x7000360b70ull);
L_7000360b70:;
    c->sp = (uint64_t)(c->sp - 0xb0ull);
    { uint64_t ea = c->sp + 0x40ull; ST64(ea, VS64(8)); }
    { uint64_t ea = c->sp + 80; ST64(ea, c->x[29]); ST64(ea + 8, c->x[30]); }
    { uint64_t ea = c->sp + 96; ST64(ea, c->x[28]); ST64(ea + 8, c->x[27]); }
    { uint64_t ea = c->sp + 112; ST64(ea, c->x[26]); ST64(ea + 8, c->x[25]); }
    { uint64_t ea = c->sp + 128; ST64(ea, c->x[24]); ST64(ea + 8, c->x[23]); }
    { uint64_t ea = c->sp + 144; ST64(ea, c->x[22]); ST64(ea + 8, c->x[21]); }
    { uint64_t ea = c->sp + 160; ST64(ea, c->x[20]); ST64(ea + 8, c->x[19]); }
    c->x[29] = (uint64_t)(c->sp + 0x50ull);
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xcf8ull; uint64_t v = LD32(ea); c->x[9] = (uint64_t)(v); }
    c->x[10] = (uint32_t)((uint32_t)c->x[9] + 0x1ull);
    { uint64_t ea = c->x[8] + 0xcf8ull; ST32(ea, (uint32_t)c->x[10]); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000360e00; }
    c->x[0] = (uint32_t)(0x4f0ull);
    c->x[30] = 0x7000360bb0ull; f_7002833eb0(c);
    c->x[1] = (uint32_t)(0u | 0u);
    c->x[2] = (uint32_t)(0u | 0u);
    c->x[19] = (uint64_t)(0ull | c->x[0]);
    c->x[30] = 0x7000360bc0ull; f_7002834e10(c);
    c->x[0] = (uint64_t)(c->x[19] + 0x28ull);
    c->x[2] = (uint32_t)(0x348ull);
    c->x[1] = (uint32_t)(0u | 0u);
    c->x[20] = (uint64_t)(c->x[19] + 0x370ull);
    c->x[30] = 0x7000360bd4ull; f_7002835700(c);
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x780ull);
    { uint64_t ea = c->x[19] + 0x380ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->x[19] + 0x378ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x738ull);
    { uint64_t ea = c->x[19] + 0x370ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x7e0ull);
    { uint64_t ea = c->x[19] + 0x390ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x798ull);
    c->x[9] = (uint64_t)(c->x[19] + 0x388ull);
    { uint64_t ea = c->x[19] + 0x388ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x3a0ull);
    { uint64_t ea = c->x[19] + 0x398ull; ST64(ea, c->x[9]); }
    c->x[9] = (uint64_t)(0x7003436000ull);
    c->x[9] = (uint64_t)(c->x[9] + 0x7f8ull);
    { uint64_t ea = c->x[19] + 0x3b0ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x3c0ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x3d8ull);
    { uint64_t ea = c->x[19] + 0x3a8ull; ST64(ea, c->x[9]); }
    c->x[9] = (uint64_t)(0x7003436000ull);
    c->x[9] = (uint64_t)(c->x[9] + 0x618ull);
    { uint64_t ea = c->x[19] + 0x3b8ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(0ull | 0x100000001ull);
    { uint64_t ea = c->x[19] + 0x3a0ull; ST64(ea, c->x[9]); }
    { uint64_t ea = c->x[19] + 0x3c0ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x3c8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x3d0ull; ST64(ea, c->x[8]); }
    c->x[30] = 0x7000360c50ull; f_7002834270(c);
    c->x[8] = (uint64_t)(c->x[19] + 0x3e0ull);
    c->x[20] = (uint64_t)(0x7003445000ull);
    c->x[20] = (uint64_t)(c->x[20] + 0x828ull);
    { uint64_t ea = c->x[19] + 0x3f0ull; ST64(ea, c->x[8]); }
    c->x[21] = (uint64_t)(0x7003445000ull);
    c->x[21] = (uint64_t)(c->x[21] + 0x798ull);
    c->x[8] = (uint64_t)(c->x[19] + 0x400ull);
    { uint64_t ea = c->x[19] + 0x3e8ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->x[19] + 0x3e0ull; ST64(ea, c->x[21]); }
    c->x[22] = (uint32_t)(0x1ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x418ull);
    { uint64_t ea = c->x[19] + 0x400ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x408ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x3f8ull; ST64(ea, c->x[8]); }
    { uint64_t ea = c->x[19] + 0x410ull; ST64(ea, c->x[22]); }
    c->x[30] = 0x7000360c90ull; f_7002834270(c);
    c->x[8] = (uint64_t)(c->x[19] + 0x420ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x458ull);
    { uint64_t ea = c->x[19] + 0x428ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->x[19] + 0x430ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x440ull);
    { uint64_t ea = c->x[19] + 0x420ull; ST64(ea, c->x[21]); }
    { uint64_t ea = c->x[19] + 0x440ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x448ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x438ull; ST64(ea, c->x[8]); }
    { uint64_t ea = c->x[19] + 0x450ull; ST64(ea, c->x[22]); }
    c->x[30] = 0x7000360cbcull; f_7002834270(c);
    c->x[8] = (uint64_t)(c->x[19] + 0x460ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x498ull);
    { uint64_t ea = c->x[19] + 0x468ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->x[19] + 0x470ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x480ull);
    { uint64_t ea = c->x[19] + 0x460ull; ST64(ea, c->x[21]); }
    { uint64_t ea = c->x[19] + 0x480ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x488ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x478ull; ST64(ea, c->x[8]); }
    { uint64_t ea = c->x[19] + 0x490ull; ST64(ea, c->x[22]); }
    c->x[30] = 0x7000360ce8ull; f_7002834270(c);
    c->x[8] = (uint64_t)(c->x[19] + 0x4a0ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x4d8ull);
    { uint64_t ea = c->x[19] + 0x4a8ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->x[19] + 0x4b0ull; ST64(ea, c->x[8]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x4c0ull);
    { uint64_t ea = c->x[19] + 0x4a0ull; ST64(ea, c->x[21]); }
    { uint64_t ea = c->x[19] + 0x4c0ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x4c8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0x4b8ull; ST64(ea, c->x[8]); }
    { uint64_t ea = c->x[19] + 0x4d0ull; ST64(ea, c->x[22]); }
    c->x[30] = 0x7000360d14ull; f_7002834270(c);
    c->x[8] = (uint64_t)(c->x[19] + 0x4e4ull);
    c->x[0] = (uint32_t)(0x1ull);
    { uint64_t ea = c->x[19] + 0x4e0ull; ST8(ea, 0u); }
    { uint64_t ea = c->x[8] + 0x0ull; ST64(ea, c->x[22]); }
    c->x[8] = (uint64_t)(c->x[19] + 0x4e5ull);
    { uint64_t ea = c->x[8] + 0x0ull; ST32(ea, 0u); }
    { uint64_t ea = c->x[19] + 0x4e8ull; ST32(ea, 0u); }
    c->x[30] = 0x7000360d34ull; f_70028354c0(c);
    c->x[0] = (uint32_t)(0x1ull);
    c->x[30] = 0x7000360d3cull; f_70028354d0(c);
    c->x[0] = (uint32_t)(0x1ull);
    c->x[30] = 0x7000360d44ull; f_70028354e0(c);
    c->x[0] = (uint32_t)(0x20ull);
    c->x[30] = 0x7000360d4cull; f_7002833eb0(c);
    c->x[8] = (uint32_t)(0x10000ull);
    c->x[9] = (uint32_t)(0x2ull);
    { uint64_t ea = c->sp + 0x20ull; ST8(ea, (uint32_t)c->x[9]); }
    { uint64_t ea = c->sp + 16; ST64(ea, c->x[8]); ST64(ea + 8, 0ull); }
    c->x[8] = (uint32_t)(0x10ull);
    /* hint */
    c->x[9] = (uint64_t)(0x700033a1d0ull);
    c->x[20] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->sp + 0x24ull; ST32(ea, (uint32_t)c->x[8]); }
    c->x[8] = (uint64_t)(0x7003448000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x2e0ull);
    { uint64_t ea = c->x[0] + 0; ST64(ea, c->x[8]); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, c->x[9]); }
    c->x[0] = (uint32_t)(0x40ull);
    c->x[30] = 0x7000360d88ull; f_7002833eb0(c);
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x810ull);
    { uint64_t ea = c->x[0] + 0x10ull; ST64(ea, c->x[19]); }
    c->x[9] = (uint64_t)(0x7002746000ull);
    c->x[9] = (uint64_t)(c->x[9] + 0x7fcull);
    c->x[21] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, c->x[8]); ST64(ea + 8, c->x[9]); }
    c->x[0] = (uint64_t)(c->x[0] + 0x30ull);
    { uint64_t ea = c->x[21] + 0x20ull; ST64(ea, c->x[21]); }
    c->x[30] = 0x7000360db0ull; f_70028340d0(c);
    c->x[1] = (uint64_t)(c->sp + 0x10ull);
    c->x[0] = (uint64_t)(0ull | c->x[20]);
    c->x[2] = (uint64_t)(0ull | c->x[21]);
    c->x[30] = 0x7000360dc0ull; f_7000359018(c);
    { uint64_t ea = c->x[19] + 0x28ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[19] + 0x28ull; ST64(ea, c->x[20]); }
    if (c->x[0] == 0) { goto L_7000360dd8; }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000360dd8ull; rt_dispatch(c);
L_7000360dd8:;
    c->x[30] = 0x7000360ddcull; f_70028354f0(c);
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[19] + 0x4e0ull; ST8(ea, (uint32_t)c->x[22]); }
    { uint64_t ea = c->x[8] + 0xcf0ull; uint64_t v = LD64(ea); c->x[20] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0xcf0ull; ST64(ea, c->x[19]); }
    if (c->x[20] == 0) { goto L_7000360e00; }
    c->x[0] = (uint64_t)(0ull | c->x[20]);
    c->x[30] = 0x7000360df8ull; f_70027474a4(c);
    c->x[0] = (uint64_t)(0ull | c->x[20]);
    c->x[30] = 0x7000360e00ull; f_7002833e20(c);
L_7000360e00:;
    c->x[0] = (uint64_t)(0x7003488000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x940ull);
    c->x[1] = (uint32_t)(0x5000000ull);
    c->x[2] = (uint32_t)(0x1000ull);
    c->x[30] = 0x7000360e14ull; f_7002833f10(c);
    c->x[20] = (uint64_t)(0ull | c->x[0]);
    c->x[0] = (uint64_t)(0x700347e000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x5c0ull);
    c->x[30] = 0x7000360e24ull; f_7002833fc0(c);
    c->x[21] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[21] + 0xdf0ull; uint64_t v = LD64(ea); c->x[19] = (uint64_t)(v); }
    if (c->x[19] != 0) { goto L_7000360ea0; }
    c->x[0] = (uint32_t)(0xe0ull);
    c->x[30] = 0x7000360e38ull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0x7003436000ull);
    c->x[22] = (uint64_t)(c->x[22] + 0xd38ull);
    { uint64_t ea = c->x[0] + 0x8ull; ST64(ea, c->x[22]); }
    c->x[19] = (uint64_t)(0ull | c->x[0]);
    c->x[0] = (uint64_t)(c->x[0] + 0x10ull);
    c->x[30] = 0x7000360e50ull; f_7002833f70(c);
    c->x[0] = (uint64_t)(c->x[19] + 0x78ull);
    { uint64_t ea = c->x[19] + 0x68ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[19] + 0x70ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[19] + 88; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[30] = 0x7000360e64ull; f_7002833f70(c);
    { uint64_t ea = c->x[21] + 0xdf0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[19] + 0xd0ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[19] + 0xd8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[21] + 0xdf0ull; ST64(ea, c->x[19]); }
    { uint64_t ea = c->x[19] + 192; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_7000360e90; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdf0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000360e8cull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[19] = (uint64_t)(v); }
L_7000360e90:;
    c->x[8] = (uint64_t)(0x70034ca000ull);
    c->x[9] = (uint64_t)(0x7002759000ull);
    c->x[9] = (uint64_t)(c->x[9] + 0x588ull);
    { uint64_t ea = c->x[8] + 0xdf8ull; ST64(ea, c->x[9]); }
L_7000360ea0:;
    c->x[0] = (uint64_t)(0x700347e000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x5c0ull);
    c->x[30] = 0x7000360eacull; f_7002833fd0(c);
    { uint64_t ea = c->x[19] + 0xd8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    if (c->x[8] != 0) { goto L_7000360fbc; }
    c->x[8] = (uint32_t)(0x5000000ull);
    { uint64_t ea = c->x[19] + 0xd8ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->sp + 0x30ull; ST64(ea, c->x[20]); }
    { uint64_t ea = c->sp + 16; ST64(ea, c->x[8]); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(c->sp + 0x10ull);
    c->x[21] = (uint64_t)(c->x[8] + 0x20ull);
    c->x[8] = (uint32_t)(0x4000000ull);
    { uint64_t ea = c->sp + 32; ST64(ea, 0ull); ST64(ea + 8, c->x[20]); }
L_7000360ed4:;
    c->x[1] = (uint64_t)(ldx64(c, c->x[21]));
    c->x[9] = (uint64_t)(c->x[1] + c->x[8]);
    { uint32_t st = stx64(c, c->x[21], c->x[9]); c->x[10] = (uint32_t)(st); }
    if ((uint32_t)c->x[10] != 0) { goto L_7000360ed4; }
    c->x[8] = (uint32_t)(0x4000000ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x10ull);
    c->x[2] = (uint32_t)(0x4000000ull);
    { uint64_t ea = c->x[19] + 88; ST64(ea, c->x[1]); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000360ef8ull; f_7002835390(c);
    /* hint */
    /* hint */
L_7000360f00:;
    c->x[1] = (uint64_t)(ldx64(c, c->x[21]));
    c->x[8] = (uint64_t)(c->x[1] + 0x800000ull);
    { uint32_t st = stx64(c, c->x[21], c->x[8]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000360f00; }
    c->x[8] = (uint32_t)(0x800000ull);
    c->x[0] = (uint64_t)(c->x[19] + 0x78ull);
    c->x[2] = (uint32_t)(0x800000ull);
    { uint64_t ea = c->x[19] + 192; ST64(ea, c->x[1]); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000360f24ull; f_7002835390(c);
    c->x[0] = (uint64_t)(0x7002759000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x4b0ull);
    c->x[1] = (uint64_t)(0x7002759000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x5e0ull);
    c->x[2] = (uint64_t)(0x7002759000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0x6b0ull);
    c->x[3] = (uint64_t)(0ull | 0ull);
    c->x[30] = 0x7000360f44ull; f_7002835560(c);
    c->x[0] = (uint64_t)(0x7002759000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x780ull);
    c->x[1] = (uint64_t)(0x7002759000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x860ull);
    c->x[2] = (uint64_t)(0x7002759000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0x930ull);
    c->x[3] = (uint64_t)(0ull | 0ull);
    c->x[30] = 0x7000360f64ull; f_7002835570(c);
L_7000360f64:;
    c->x[0] = (uint64_t)(ldx64(c, c->x[21]));
    c->x[8] = (uint64_t)(c->x[0] + 0x800000ull);
    { uint32_t st = stx64(c, c->x[21], c->x[8]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000360f64; }
    c->x[1] = (uint32_t)(0x800000ull);
    c->x[30] = 0x7000360f7cull; f_7002835580(c);
    { uint64_t ea = c->sp + 0x20ull; uint64_t v = LD64(ea); c->x[19] = (uint64_t)(v); }
    if (c->x[19] == 0) { goto L_7000360fbc; }
    c->x[8] = (uint64_t)(c->x[19] + 0x8ull);
    /* hint */
    /* hint */
L_7000360f90:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000360f90; }
    if (c->x[9] != 0) { goto L_7000360fbc; }
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000360fb4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000360fbcull; f_7002833e50(c);
L_7000360fbc:;
    c->v[8] = 0x0ull;
    c->x[23] = (uint64_t)(0ull | 0xffffffff000000ull);
    c->x[26] = (uint64_t)(0ull | 0xfffff000000ull);
    c->x[23] = (uint64_t)((c->x[23] & 0xffffffffffff0000ull) | 0xff00ull);
    c->x[26] = (uint64_t)((c->x[26] & 0xffffffffffff0000ull) | 0xff00ull);
    c->x[28] = (uint64_t)(0x70034ca000ull);
    c->x[21] = (uint32_t)(0x1ull);
    c->x[25] = (uint64_t)(0x70034bd000ull);
    c->x[25] = (uint64_t)(c->x[25] + 0x5f0ull);
    c->x[20] = (uint64_t)(0x70034bd000ull);
    c->x[20] = (uint64_t)(c->x[20] + 0xb68ull);
    c->x[27] = (uint64_t)(0x70034b9000ull);
    c->x[27] = (uint64_t)(c->x[27] + 0x2e0ull);
    c->x[24] = (uint64_t)(0ull | 0xffffffff00000000ull);
    goto L_7000361014;
    /* hint */
    /* hint */
L_7000361000:;
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361008ull; f_7002833e20(c);
L_7000361008:;
    c->x[30] = 0x700036100cull; f_7002833ea0(c);
    { uint64_t ea = c->sp + 0x10ull; ST32(ea, (uint32_t)c->x[0]); }
    if ((uint32_t)c->x[0] != 0) { goto L_7000362c70; }
L_7000361014:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8e8ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_70003629d0; }
L_7000361024:;
    c->x[30] = 0x7000361028ull; f_700033a560(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] != 0) { goto L_70003610ac; }
    c->x[0] = (uint32_t)(0xd0ull);
    c->x[30] = 0x7000361038ull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xd38ull);
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[0] = (uint64_t)(c->x[0] + 0x50ull);
    { uint64_t ea = c->x[22] + 64; ST64(ea, 0ull); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000361060ull; f_7002833f70(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0xa8ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[22] + 0xb0ull; ST8(ea, (uint32_t)c->x[21]); }
    { uint64_t ea = c->x[22] + 177; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 185; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 193; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 0xc8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[22] + 152; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_700036109c; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdd0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361098ull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_700036109c:;
    c->x[8] = (uint64_t)(0x700274e000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xa30ull);
    c->x[9] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[9] + 0xdd8ull; ST64(ea, c->x[8]); }
L_70003610ac:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[9] = (uint32_t)(0xbcc8ull);
    c->x[19] = (uint64_t)(c->x[8] + c->x[9]);
    { uint64_t ea = c->x[19] + 0x4ull; uint64_t v = LD32(ea); c->x[9] = (uint64_t)(v); }
    (void)(subs32(c, (uint32_t)c->x[9], 0x1ull));
    if (COND_LT(c)) { goto L_70003610e8; }
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD32(ea); c->x[2] = (uint64_t)(v); }
    c->x[9] = (uint32_t)(0x3030ull);
    c->x[22] = (uint64_t)(c->x[8] + c->x[9]);
    c->x[9] = (uint32_t)(0x5058ull);
    c->x[1] = (uint64_t)(c->x[8] + c->x[9]);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003610e0ull; f_700032ca34(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003610e8ull; f_700032ca20(c);
L_70003610e8:;
    { uint64_t ea = c->x[19] + 0x4ull; ST32(ea, 0u); }
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[22] = (uint64_t)(0x70034bb000ull);
    { uint64_t ea = c->x[19] + 0x718ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD8(ea); c->x[8] = (uint64_t)(v); }
    if ((uint32_t)c->x[8] == 0) { goto L_7000361160; }
L_7000361100:;
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000361108ull; f_7000357070(c);
    { uint64_t ea = c->x[22] + 0x8d8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    if (c->x[8] == 0) { goto L_700036111c; }
    { uint64_t ea = c->x[8] + 0x180ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    (void)(subs64(c, c->x[8], 0x0ull));
    c->x[8] = (uint32_t)((COND_EQ(c)) ? 0u : (uint32_t)(0u + 1));
L_700036111c:;
    c->x[9] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[9] + 0x851ull; uint64_t v = LD8(ea); c->x[9] = (uint64_t)(v); }
    if ((uint32_t)c->x[9] == 0) { goto L_70003611e0; }
    c->x[8] = (uint64_t)(0x700347e000ull);
    c->v[0] = 0x0ull;
    { uint64_t ea = c->x[8] + 0x5a0ull; ST8(ea, (uint32_t)c->x[21]); }
    goto L_7000361230;
    /* hint */
    /* hint */
L_7000361140:;
    c->x[8] = (uint64_t)(0x700347e000ull);
    c->v[0] = 0x0ull;
    { uint64_t ea = c->x[8] + 0x5a0ull; ST8(ea, (uint32_t)c->x[21]); }
L_700036114c:;
    c->x[8] = (uint64_t)(0x70034c9000ull);
    { uint64_t ea = c->x[8] + 0x8ull; ST32(ea, VS32(0)); }
    { uint64_t ea = c->x[19] + 0x718ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD8(ea); c->x[8] = (uint64_t)(v); }
    if ((uint32_t)c->x[8] != 0) { goto L_7000361100; }
L_7000361160:;
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000361168ull; f_7000357070(c);
    { uint64_t ea = c->x[22] + 0x8d8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    if (c->x[8] == 0) { goto L_700036117c; }
    { uint64_t ea = c->x[8] + 0x180ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    (void)(subs64(c, c->x[8], 0x0ull));
    c->x[8] = (uint32_t)((COND_EQ(c)) ? 0u : (uint32_t)(0u + 1));
L_700036117c:;
    c->x[9] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[9] + 0x851ull; uint64_t v = LD8(ea); c->x[9] = (uint64_t)(v); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361140; }
    c->x[9] = (uint64_t)(0x70034bd000ull);
    c->v[0] = 0x0ull;
    { uint64_t ea = c->x[9] + 0x850ull; uint64_t v = LD8(ea); c->x[9] = (uint64_t)(v); }
    (void)(subs32(c, (uint32_t)c->x[9], 0x0ull));
    c->x[9] = (uint64_t)(0x700347e000ull);
    c->x[8] = (uint32_t)((COND_EQ(c)) ? (uint32_t)c->x[8] : (uint32_t)(0u + 1));
    { uint64_t ea = c->x[9] + 0x5a0ull; ST8(ea, (uint32_t)c->x[8]); }
    if (((c->x[8] >> 0) & 1) != 0) { goto L_700036114c; }
    c->x[8] = (uint64_t)(0x70034d1000ull);
    { uint64_t ea = c->x[8] + 0x960ull; c->v[0] = LD32(ea); }
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xd94ull; c->v[1] = LD32(ea); }
    c->x[8] = (uint64_t)(0x70034c9000ull);
    fp_op_s(c, FOP_MAXNM, 0, 0, 8);
    c->nzcv = cmp_s(c, VSF32(0), VSF32(1));
    c->v[0] = COND_GT(c) ? VS32(1) : VS32(0);
    { uint64_t ea = c->x[8] + 0xcull; c->v[1] = LD32(ea); }
    fp_op_s(c, FOP_ADD, 1, 1, 0);
    { uint64_t ea = c->x[8] + 0xcull; ST32(ea, VS32(1)); }
    goto L_700036114c;
    /* hint */
    /* hint */
L_70003611e0:;
    c->x[9] = (uint64_t)(0x70034bd000ull);
    c->v[0] = 0x0ull;
    { uint64_t ea = c->x[9] + 0x850ull; uint64_t v = LD8(ea); c->x[9] = (uint64_t)(v); }
    (void)(subs32(c, (uint32_t)c->x[9], 0x0ull));
    c->x[9] = (uint64_t)(0x700347e000ull);
    c->x[8] = (uint32_t)((COND_EQ(c)) ? (uint32_t)c->x[8] : (uint32_t)(0u + 1));
    { uint64_t ea = c->x[9] + 0x5a0ull; ST8(ea, (uint32_t)c->x[8]); }
    if (((c->x[8] >> 0) & 1) != 0) { goto L_7000361230; }
    c->x[8] = (uint64_t)(0x70034d1000ull);
    { uint64_t ea = c->x[8] + 0x960ull; c->v[0] = LD32(ea); }
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xd94ull; c->v[1] = LD32(ea); }
    c->x[8] = (uint64_t)(0x70034c9000ull);
    fp_op_s(c, FOP_MAXNM, 0, 0, 8);
    c->nzcv = cmp_s(c, VSF32(0), VSF32(1));
    c->v[0] = COND_GT(c) ? VS32(1) : VS32(0);
    { uint64_t ea = c->x[8] + 0xcull; c->v[1] = LD32(ea); }
    fp_op_s(c, FOP_ADD, 1, 1, 0);
    { uint64_t ea = c->x[8] + 0xcull; ST32(ea, VS32(1)); }
    /* hint */
L_7000361230:;
    c->x[8] = (uint64_t)(0x70034c9000ull);
    { uint64_t ea = c->x[8] + 0x8ull; ST32(ea, VS32(0)); }
    c->x[8] = (uint64_t)(0x70034bc000ull);
    { uint64_t ea = c->x[8] + 0x178ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361290; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361250:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361250; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361290; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361278ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361290; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361290ull; rt_dispatch(c);
L_7000361290:;
    c->x[8] = (uint64_t)(0x70034bc000ull);
    { uint64_t ea = c->x[8] + 0x178ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034b5000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x1d8ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362a18; }
L_70003612a8:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x1d0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    if (c->x[0] != 0) { goto L_70003612d4; }
    c->x[0] = (uint32_t)(0x18ull);
    c->x[30] = 0x70003612bcull; f_7002833eb0(c);
    c->x[8] = (uint64_t)(0x70033c4000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x448ull);
    { uint64_t ea = c->x[0] + 0x10ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[0] + 0; ST64(ea, c->x[8]); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x1d0ull; ST64(ea, c->x[0]); }
L_70003612d4:;
    { uint64_t ea = c->x[0] + 0x10ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[0] + 8; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000361310; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_70003612e4:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003612e4; }
    if (c->x[9] != 0) { goto L_7000361310; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361308ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361310ull; f_7002833e50(c);
L_7000361310:;
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x210ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    if (c->x[0] == 0) { goto L_7000361494; }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x18ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361328ull; rt_dispatch(c);
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x210ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    { uint64_t ea = c->x[25] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[22] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD32(ea); c->x[8] = (uint64_t)(v); }
    if (((c->x[8] >> 31) & 1) != 0) { goto L_7000361374; }
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8e8ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362c28; }
L_7000361350:;
    { uint64_t ea = c->x[25] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(c->x[8] + 0x10ull);
    c->x[30] = 0x700036135cull; f_7000c3bda0(c);
    { uint64_t ea = c->x[25] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[9] = (uint32_t)(0xffffffffull);
    { uint64_t ea = c->x[8] + 0x10ull; ST32(ea, (uint32_t)c->x[9]); }
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x210ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_70003613c0; }
L_7000361374:;
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361380:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361380; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_70003613c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003613a8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_70003613c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003613c0ull; rt_dispatch(c);
L_70003613c0:;
    c->x[8] = (uint64_t)(0x70034b9000ull);
    c->x[13] = (uint64_t)(0ull | 0xffffffffff000000ull);
    { uint64_t ea = c->x[8] + 0x210ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(c->x[25] + 0x10ull);
    c->x[14] = (uint32_t)(0x1000000ull);
    c->x[10] = (uint64_t)(lda64(c->x[8]));
    c->x[9] = (uint64_t)(c->x[10] & 0xff000000ull);
    c->x[11] = (uint64_t)(c->x[10] + c->x[13]);
    c->x[12] = (uint64_t)(c->x[11] & 0xfeffffffffffffffull);
    (void)(subs64(c, c->x[9], (uint64_t)(c->x[14])));
    c->x[22] = (uint64_t)((COND_EQ(c)) ? c->x[12] : (uint64_t)(c->x[11]));
    /* hint */
L_70003613f0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    (void)(subs64(c, c->x[9], (uint64_t)(c->x[10])));
    if (COND_NE(c)) { goto L_7000361410; }
    { uint32_t st = stx64(c, c->x[8], c->x[22]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003613f0; }
    c->x[10] = (uint32_t)(0x1ull);
    if (((c->x[10] >> 0) & 1) == 0) { goto L_7000361430; }
    goto L_7000361464;
L_7000361410:;
    c->x[10] = (uint32_t)(0u | 0u);
    c->excl_addr = ~0ull;
    if (((c->x[10] >> 0) & 1) == 0) { goto L_7000361430; }
    goto L_7000361464;
L_7000361420:;
    c->x[11] = (uint32_t)(0u | 0u);
    c->excl_addr = ~0ull;
    c->x[9] = (uint64_t)(0ull | c->x[10]);
    if ((uint32_t)c->x[11] != 0) { goto L_7000361464; }
L_7000361430:;
    c->x[10] = (uint64_t)(c->x[9] & 0xff000000ull);
    c->x[11] = (uint64_t)(c->x[9] + c->x[13]);
    c->x[12] = (uint64_t)(c->x[11] & 0xfeffffffffffffffull);
    (void)(subs64(c, c->x[10], (uint64_t)(c->x[14])));
    c->x[22] = (uint64_t)((COND_EQ(c)) ? c->x[12] : (uint64_t)(c->x[11]));
L_7000361444:;
    c->x[10] = (uint64_t)(ldx64(c, c->x[8]));
    (void)(subs64(c, c->x[10], (uint64_t)(c->x[9])));
    if (COND_NE(c)) { goto L_7000361420; }
    { uint32_t st = stx64(c, c->x[8], c->x[22]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361444; }
    c->x[11] = (uint32_t)(0x1ull);
    c->x[9] = (uint64_t)(0ull | c->x[10]);
    if ((uint32_t)c->x[11] == 0) { goto L_7000361430; }
L_7000361464:;
    (void)(logic64(c, (uint64_t)(c->x[22] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361494; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036147cull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[22] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361494; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361494ull; rt_dispatch(c);
L_7000361494:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x438ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x438ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_7000361528; }
    { uint64_t ea = c->x[22] + 0x18ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] == 0) { goto L_70003614c4; }
    c->x[8] = (uint64_t)(c->x[25] + 0x8ull);
L_70003614b0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003614b0; }
    if (c->x[9] == 0) { goto L_7000361500; }
L_70003614c4:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] == 0) { goto L_7000361520; }
L_70003614cc:;
    c->x[8] = (uint64_t)(c->x[25] + 0x8ull);
L_70003614d0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003614d0; }
    if (c->x[9] != 0) { goto L_7000361520; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003614f4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x70003614fcull; f_7002833e50(c);
    goto L_7000361520;
L_7000361500:;
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361510ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000361518ull; f_7002833e50(c);
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] != 0) { goto L_70003614cc; }
L_7000361520:;
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361528ull; f_7002833e20(c);
L_7000361528:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0xc98ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361588; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361540:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361540; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361580; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361568ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361580; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361580ull; rt_dispatch(c);
L_7000361580:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0xc98ull; ST64(ea, 0ull); }
L_7000361588:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x8b8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_70003615e8; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_70003615a0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003615a0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_70003615e0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003615c8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_70003615e0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003615e0ull; rt_dispatch(c);
L_70003615e0:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x8b8ull; ST64(ea, 0ull); }
L_70003615e8:;
    c->x[8] = (uint64_t)(0x70034ba000ull);
    { uint64_t ea = c->x[8] + 0xa00ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361648; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361600:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361600; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361640; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361628ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361640; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361640ull; rt_dispatch(c);
L_7000361640:;
    c->x[8] = (uint64_t)(0x70034ba000ull);
    { uint64_t ea = c->x[8] + 0xa00ull; ST64(ea, 0ull); }
L_7000361648:;
    c->x[8] = (uint64_t)(0x70034ba000ull);
    { uint64_t ea = c->x[8] + 0x9f8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_70003616a8; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361660:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361660; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_70003616a0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361688ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_70003616a0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003616a0ull; rt_dispatch(c);
L_70003616a0:;
    c->x[8] = (uint64_t)(0x70034ba000ull);
    { uint64_t ea = c->x[8] + 0x9f8ull; ST64(ea, 0ull); }
L_70003616a8:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x8b0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361700; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_70003616c0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003616c0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361700; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003616e8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361700; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361700ull; rt_dispatch(c);
L_7000361700:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0x8b0ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034bb000ull);
    { uint64_t ea = c->x[8] + 0x9c0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361760; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361720:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361720; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361760; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361748ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361760; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361760ull; rt_dispatch(c);
L_7000361760:;
    c->x[8] = (uint64_t)(0x70034bb000ull);
    { uint64_t ea = c->x[8] + 0x9c0ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0xbf0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_70003617c0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_7000361780:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361780; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_70003617c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003617a8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_70003617c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003617c0ull; rt_dispatch(c);
L_70003617c0:;
    c->x[8] = (uint64_t)(0x70034b5000ull);
    { uint64_t ea = c->x[8] + 0xbf0ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034aa000ull);
    { uint64_t ea = c->x[8] + 0x650ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x650ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_70003617dc; }
    c->x[30] = 0x70003617dcull; f_7002833e20(c);
L_70003617dc:;
    c->x[8] = (uint64_t)(0x70034a4000ull);
    { uint64_t ea = c->x[8] + 0x9e0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361830; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
L_70003617f0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003617f0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361830; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361818ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361830; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361830ull; rt_dispatch(c);
L_7000361830:;
    c->x[19] = (uint64_t)(0x70034a4000ull);
    c->x[8] = (uint64_t)(0x70034a4000ull);
    { uint64_t ea = c->x[19] + 0x9d8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x9e0ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x18ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036184cull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x9d8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[25] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x18ull; uint64_t v = LD32(ea); c->x[8] = (uint64_t)(v); }
    if (((c->x[8] >> 31) & 1) != 0) { goto L_7000361894; }
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8e8ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362be0; }
L_7000361870:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(c->x[8] + 0x18ull);
    c->x[30] = 0x700036187cull; f_7000c3bda0(c);
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[9] = (uint32_t)(0xffffffffull);
    { uint64_t ea = c->x[8] + 0x18ull; ST32(ea, (uint32_t)c->x[9]); }
    c->x[8] = (uint64_t)(0x70034a4000ull);
    { uint64_t ea = c->x[8] + 0x9d8ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] == 0) { goto L_70003618e0; }
L_7000361894:;
    c->x[8] = (uint64_t)(c->x[25] + 0x10ull);
    /* hint */
    /* hint */
L_70003618a0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003618a0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_70003618e0; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003618c8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_70003618e0; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003618e0ull; rt_dispatch(c);
L_70003618e0:;
    c->x[8] = (uint64_t)(0x70034a4000ull);
    c->x[13] = (uint64_t)(0ull | 0xffffffffff000000ull);
    { uint64_t ea = c->x[8] + 0x9d8ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    c->x[14] = (uint32_t)(0x1000000ull);
    c->x[10] = (uint64_t)(lda64(c->x[8]));
    c->x[9] = (uint64_t)(c->x[10] & 0xff000000ull);
    c->x[11] = (uint64_t)(c->x[10] + c->x[13]);
    c->x[12] = (uint64_t)(c->x[11] & 0xfeffffffffffffffull);
    (void)(subs64(c, c->x[9], (uint64_t)(c->x[14])));
    c->x[25] = (uint64_t)((COND_EQ(c)) ? c->x[12] : (uint64_t)(c->x[11]));
    /* hint */
L_7000361910:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    (void)(subs64(c, c->x[9], (uint64_t)(c->x[10])));
    if (COND_NE(c)) { goto L_7000361930; }
    { uint32_t st = stx64(c, c->x[8], c->x[25]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361910; }
    c->x[10] = (uint32_t)(0x1ull);
    if (((c->x[10] >> 0) & 1) == 0) { goto L_7000361950; }
    goto L_7000361984;
L_7000361930:;
    c->x[10] = (uint32_t)(0u | 0u);
    c->excl_addr = ~0ull;
    if (((c->x[10] >> 0) & 1) == 0) { goto L_7000361950; }
    goto L_7000361984;
L_7000361940:;
    c->x[11] = (uint32_t)(0u | 0u);
    c->excl_addr = ~0ull;
    c->x[9] = (uint64_t)(0ull | c->x[10]);
    if ((uint32_t)c->x[11] != 0) { goto L_7000361984; }
L_7000361950:;
    c->x[10] = (uint64_t)(c->x[9] & 0xff000000ull);
    c->x[11] = (uint64_t)(c->x[9] + c->x[13]);
    c->x[12] = (uint64_t)(c->x[11] & 0xfeffffffffffffffull);
    (void)(subs64(c, c->x[10], (uint64_t)(c->x[14])));
    c->x[25] = (uint64_t)((COND_EQ(c)) ? c->x[12] : (uint64_t)(c->x[11]));
L_7000361964:;
    c->x[10] = (uint64_t)(ldx64(c, c->x[8]));
    (void)(subs64(c, c->x[10], (uint64_t)(c->x[9])));
    if (COND_NE(c)) { goto L_7000361940; }
    { uint32_t st = stx64(c, c->x[8], c->x[25]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361964; }
    c->x[11] = (uint32_t)(0x1ull);
    c->x[9] = (uint64_t)(0ull | c->x[10]);
    if ((uint32_t)c->x[11] == 0) { goto L_7000361950; }
L_7000361984:;
    (void)(logic64(c, (uint64_t)(c->x[25] & c->x[26])));
    if (COND_NE(c)) { goto L_70003619b4; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036199cull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[25] & c->x[23])));
    if (COND_NE(c)) { goto L_70003619b4; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003619b4ull; rt_dispatch(c);
L_70003619b4:;
    c->x[8] = (uint64_t)(0x70034c8000ull);
    c->x[25] = (uint64_t)(0x70034c1000ull);
    c->x[25] = (uint64_t)(c->x[25] + 0x84ull);
    { uint64_t ea = c->x[8] + 0xfe0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361a10; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
L_70003619d0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003619d0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361a10; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003619f8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361a10; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361a10ull; rt_dispatch(c);
L_7000361a10:;
    c->x[8] = (uint64_t)(0x70034c8000ull);
    c->x[19] = (uint64_t)(0x70034d2000ull);
    { uint64_t ea = c->x[8] + 0xfe0ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8d8ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000361a60; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000361a34:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361a34; }
    if (c->x[9] != 0) { goto L_7000361a60; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361a58ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361a60ull; f_7002833e50(c);
L_7000361a60:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8c8ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000361aac; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_7000361a80:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361a80; }
    if (c->x[9] != 0) { goto L_7000361aac; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361aa4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361aacull; f_7002833e50(c);
L_7000361aac:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8b8ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000361af0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000361ac4:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361ac4; }
    if (c->x[9] != 0) { goto L_7000361af0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361ae8ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361af0ull; f_7002833e50(c);
L_7000361af0:;
    c->x[8] = (uint64_t)(0x70034aa000ull);
    { uint64_t ea = c->x[8] + 0x570ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x570ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_7000361b10; }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361b08ull; f_70018603a0(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361b10ull; f_7002833e20(c);
L_7000361b10:;
    c->x[30] = 0x7000361b14ull; f_70003458b0(c);
    c->x[8] = (uint64_t)(0x70034a9000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x88ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362a54; }
L_7000361b24:;
    c->x[8] = (uint64_t)(0x70034a9000ull);
    { uint64_t ea = c->x[8] + 0x80ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x80ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_7000361b44; }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361b3cull; f_7002707990(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361b44ull; f_7002833e20(c);
L_7000361b44:;
    c->x[8] = (uint64_t)(0x70034d1000ull);
    { uint64_t ea = c->x[8] + 0x798ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    if (c->x[8] == 0) { goto L_7000361b7c; }
    { uint64_t ea = c->x[19] + 0x3b0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[1] = (uint64_t)(0x7002948000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x2dcull);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361b64ull; f_700273eca0(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[1] = (uint64_t)(0x7002948000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x2ccull);
    c->x[30] = 0x7000361b74ull; f_700273eca0(c);
    c->x[8] = (uint64_t)(0x70034d1000ull);
    { uint64_t ea = c->x[8] + 0x798ull; ST64(ea, 0ull); }
L_7000361b7c:;
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x650ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000361bd0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
L_7000361b90:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361b90; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000361bd0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361bb8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000361bd0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361bd0ull; rt_dispatch(c);
L_7000361bd0:;
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x650ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x430ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362a90; }
L_7000361be8:;
    c->x[0] = (uint64_t)(0x70034bc000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xd10ull);
    c->x[30] = 0x7000361bf4ull; f_70006126a0(c);
    c->x[8] = (uint64_t)(0x70034c8000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xf60ull);
    c->x[8] = (uint64_t)(lda8(c->x[8]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362ad8; }
L_7000361c04:;
    c->x[19] = (uint64_t)(0x70034c1000ull);
    { uint64_t ea = c->x[19] + 0xe8ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    (void)(subs32(c, (uint32_t)c->x[1], 0x1ull));
    if (COND_LT(c)) { goto L_7000361cb8; }
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] != 0) { goto L_7000361ca0; }
    c->x[0] = (uint32_t)(0xd0ull);
    c->x[30] = 0x7000361c24ull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xd38ull);
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[0] = (uint64_t)(c->x[0] + 0x50ull);
    { uint64_t ea = c->x[22] + 64; ST64(ea, 0ull); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000361c4cull; f_7002833f70(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0xa8ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[22] + 0xb0ull; ST8(ea, (uint32_t)c->x[21]); }
    { uint64_t ea = c->x[22] + 177; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 185; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 193; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 0xc8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[22] + 152; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_7000361c88; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdd0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361c84ull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_7000361c88:;
    c->x[19] = (uint64_t)(0x70034c1000ull);
    c->x[8] = (uint64_t)(0x700274e000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xa30ull);
    { uint64_t ea = c->x[19] + 0xe8ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    c->x[9] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[9] + 0xdd8ull; ST64(ea, c->x[8]); }
L_7000361ca0:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[30] = 0x7000361ca8ull; f_7002771c20(c);
    c->x[8] = (uint32_t)(0xffffffffull);
    { uint64_t ea = c->x[19] + 0xe8ull; ST32(ea, (uint32_t)c->x[8]); }
    goto L_7000361cb8;
L_7000361cb4:;
    c->x[30] = 0x7000361cb8ull; f_7002834520(c);
L_7000361cb8:;
    c->x[8] = (uint64_t)(lda32(c->x[25]));
    (void)(subs32(c, (uint32_t)c->x[8], 0x1ull));
    if (COND_EQ(c)) { goto L_7000361cb4; }
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[25] = (uint64_t)(0x70034d2000ull);
    c->x[25] = (uint64_t)(c->x[25] + 0xbb0ull);
    if (c->x[22] != 0) { goto L_7000361d50; }
    c->x[0] = (uint32_t)(0xd0ull);
    c->x[30] = 0x7000361cdcull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xd38ull);
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[0] = (uint64_t)(c->x[0] + 0x50ull);
    { uint64_t ea = c->x[22] + 64; ST64(ea, 0ull); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000361d04ull; f_7002833f70(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0xa8ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[22] + 0xb0ull; ST8(ea, (uint32_t)c->x[21]); }
    { uint64_t ea = c->x[22] + 177; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 185; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 193; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 0xc8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[22] + 152; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_7000361d40; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdd0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361d3cull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_7000361d40:;
    c->x[8] = (uint64_t)(0x700274e000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xa30ull);
    c->x[9] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[9] + 0xdd8ull; ST64(ea, c->x[8]); }
L_7000361d50:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[8] = (uint64_t)(lda8(c->x[25]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362b20; }
L_7000361d60:;
    c->x[21] = (uint64_t)(0x70034d2000ull);
    c->x[21] = (uint64_t)(c->x[21] + 0xae0ull);
    c->x[0] = (uint64_t)(0x70034bf000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x1b0ull);
    c->x[1] = (uint64_t)(0x7002832000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x8b4ull);
    c->x[2] = (uint64_t)(0ull | c->x[21]);
    c->x[30] = 0x7000361d80ull; f_700008e058(c);
    c->x[8] = (uint64_t)(lda8(c->x[25]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362b60; }
L_7000361d88:;
    c->x[19] = (uint64_t)(0x70034bf000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x1a0ull);
    c->x[1] = (uint64_t)(0ull | c->x[22]);
    c->x[0] = (uint64_t)(c->x[19] + 0x10ull);
    c->x[2] = (uint64_t)(0x7002831000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0x544ull);
    c->x[3] = (uint64_t)(0ull | c->x[21]);
    c->x[30] = 0x7000361da8ull; f_700008dba0(c);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[21] = (uint64_t)(0x70034bf000ull);
    c->x[21] = (uint64_t)(c->x[21] + 0xb8ull);
    { uint64_t ea = c->x[19] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000361dec; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000361dc0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361dc0; }
    if (c->x[9] != 0) { goto L_7000361dec; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361de4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361decull; f_7002833e50(c);
L_7000361dec:;
    { uint64_t ea = c->x[21] + 0x8ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    goto L_7000361df8;
L_7000361df4:;
    { uint64_t ea = c->x[25] + 0x8ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
L_7000361df8:;
    (void)(subs64(c, c->x[25], (uint64_t)(c->x[21])));
    if (COND_EQ(c)) { goto L_7000361f44; }
    { uint64_t ea = c->x[25] + 0x10ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(c->sp + 0x10ull);
    c->x[30] = 0x7000361e0cull; f_70015891f0(c);
    { uint64_t ea = c->sp + 40; uint64_t a = LD64(ea), b = LD64(ea + 8); c->x[0] = (uint64_t)(a); c->x[22] = (uint64_t)(b); }
    if (c->x[0] == 0) { goto L_7000361ed8; }
    if (c->x[22] == 0) { goto L_7000361ec0; }
    c->x[19] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_7000361e20:;
    c->x[8] = (uint64_t)(ldx64(c, c->x[19]));
    c->x[8] = (uint64_t)(c->x[8] + 0x1ull);
    { uint32_t st = stx64(c, c->x[19], c->x[8]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361e20; }
    c->x[30] = 0x7000361e34ull; f_700267f040(c);
L_7000361e34:;
    c->x[8] = (uint64_t)(ldx64(c, c->x[19]));
    c->x[9] = (uint64_t)(c->x[8] - 0x1ull);
    { uint32_t st = stx64(c, c->x[19], c->x[9]); c->x[10] = (uint32_t)(st); }
    if ((uint32_t)c->x[10] != 0) { goto L_7000361e34; }
    if (c->x[8] != 0) { goto L_7000361e60; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361e58ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361e60ull; f_7002833e50(c);
L_7000361e60:;
    { uint64_t ea = c->sp + 40; uint64_t a = LD64(ea), b = LD64(ea + 8); c->x[8] = (uint64_t)(a); c->x[22] = (uint64_t)(b); }
    { uint64_t ea = c->sp + 0; ST64(ea, c->x[8]); ST64(ea + 8, c->x[22]); }
    if (c->x[22] == 0) { goto L_7000361ecc; }
    c->x[19] = (uint64_t)(c->x[22] + 0x8ull);
L_7000361e70:;
    c->x[8] = (uint64_t)(ldx64(c, c->x[19]));
    c->x[8] = (uint64_t)(c->x[8] + 0x1ull);
    { uint32_t st = stx64(c, c->x[19], c->x[8]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000361e70; }
    c->x[0] = (uint64_t)(c->sp + 0x0ull);
    c->x[30] = 0x7000361e88ull; f_700267f2f0(c);
    /* hint */
    /* hint */
L_7000361e90:;
    c->x[8] = (uint64_t)(ldx64(c, c->x[19]));
    c->x[9] = (uint64_t)(c->x[8] - 0x1ull);
    { uint32_t st = stx64(c, c->x[19], c->x[9]); c->x[10] = (uint32_t)(st); }
    if ((uint32_t)c->x[10] != 0) { goto L_7000361e90; }
    if (c->x[8] != 0) { goto L_7000361ed4; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361eb4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361ebcull; f_7002833e50(c);
    goto L_7000361ed4;
L_7000361ec0:;
    c->x[30] = 0x7000361ec4ull; f_700267f040(c);
    { uint64_t ea = c->sp + 0x28ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->sp + 0; ST64(ea, c->x[8]); ST64(ea + 8, c->x[22]); }
L_7000361ecc:;
    c->x[0] = (uint64_t)(c->sp + 0x0ull);
    c->x[30] = 0x7000361ed4ull; f_700267f2f0(c);
L_7000361ed4:;
    { uint64_t ea = c->sp + 0x30ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_7000361ed8:;
    c->x[8] = (uint64_t)(0x7003426000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x1d8ull);
    { uint64_t ea = c->sp + 0x10ull; ST64(ea, c->x[8]); }
    if (c->x[22] == 0) { goto L_7000361f04; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_7000361ef0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361ef0; }
    if (c->x[9] == 0) { goto L_7000361f20; }
L_7000361f04:;
    { uint64_t ea = c->sp + 0x20ull; uint64_t v = LD8(ea); c->x[8] = (uint64_t)(v); }
    if ((uint32_t)c->x[8] == 0) { goto L_7000361df4; }
L_7000361f0c:;
    { uint64_t ea = c->sp + 0x18ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[30] = 0x7000361f14ull; f_7002834260(c);
    goto L_7000361df4;
    /* hint */
    /* hint */
L_7000361f20:;
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361f30ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000361f38ull; f_7002833e50(c);
    { uint64_t ea = c->sp + 0x20ull; uint64_t v = LD8(ea); c->x[8] = (uint64_t)(v); }
    if ((uint32_t)c->x[8] != 0) { goto L_7000361f0c; }
    goto L_7000361df4;
L_7000361f44:;
    c->x[8] = (uint64_t)(0x70034bf000ull);
    c->x[21] = (uint64_t)(0x70034bf000ull);
    c->x[21] = (uint64_t)(c->x[21] + 0x70ull);
    { uint64_t ea = c->x[8] + 0x80ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    if (c->x[8] == 0) { goto L_7000361f80; }
    { uint64_t ea = c->x[21] + 0; uint64_t a = LD64(ea), b = LD64(ea + 8); c->x[8] = (uint64_t)(a); c->x[22] = (uint64_t)(b); }
    (void)(subs64(c, c->x[22], (uint64_t)(c->x[21])));
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[9] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[10] = (uint64_t)(v); }
    { uint64_t ea = c->x[10] + 0x8ull; ST64(ea, c->x[9]); }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[9] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x0ull; ST64(ea, c->x[9]); }
    { uint64_t ea = c->x[21] + 0x10ull; ST64(ea, 0ull); }
    if (COND_NE(c)) { goto L_7000362124; }
L_7000361f80:;
    c->x[9] = (uint64_t)(0x70034bd000ull);
    c->x[9] = (uint64_t)(c->x[9] + 0x970ull);
    c->x[21] = (uint64_t)(0ull | c->x[28]);
    { uint64_t ea = c->x[9] + 0; uint64_t a = LD64(ea), b = LD64(ea + 8); c->x[19] = (uint64_t)(a); c->x[8] = (uint64_t)(b); }
    c->x[28] = (uint64_t)(0ull | c->x[26]);
    c->x[26] = (uint64_t)(0ull | c->x[23]);
    (void)(subs64(c, c->x[8], (uint64_t)(c->x[19])));
    if (COND_EQ(c)) { goto L_7000361fcc; }
    c->x[22] = (uint64_t)(c->x[8] - 0x20ull);
    c->x[23] = (uint64_t)(0ull | c->x[22]);
    /* hint */
    /* hint */
L_7000361fb0:;
    { uint64_t ea = c->x[23]; uint64_t v = LD64(ea); c->x[23] = c->x[23] - 32; c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000361fc0ull; rt_dispatch(c);
    (void)(subs64(c, c->x[22], (uint64_t)(c->x[19])));
    c->x[22] = (uint64_t)(0ull | c->x[23]);
    if (COND_NE(c)) { goto L_7000361fb0; }
L_7000361fcc:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x930ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x48ull; ST64(ea, c->x[19]); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_700036201c; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_7000361ff0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000361ff0; }
    if (c->x[9] != 0) { goto L_700036201c; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362014ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036201cull; f_7002833e50(c);
L_700036201c:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x940ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000362060; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000362034:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362034; }
    if (c->x[9] != 0) { goto L_7000362060; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362058ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362060ull; f_7002833e50(c);
L_7000362060:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x988ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003620ac; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_7000362080:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362080; }
    if (c->x[9] != 0) { goto L_70003620ac; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003620a4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003620acull; f_7002833e50(c);
L_70003620ac:;
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x998ull);
    goto L_70003620cc;
    /* hint */
    /* hint */
L_70003620c0:;
    c->x[19] = (uint64_t)(c->x[19] + 0x10ull);
    (void)(subs64(c, c->x[19], (uint64_t)(c->x[20])));
    if (COND_EQ(c)) { goto L_7000362164; }
L_70003620cc:;
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[19] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003620c0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_70003620e0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003620e0; }
    if (c->x[9] != 0) { goto L_70003620c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362104ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036210cull; f_7002833e50(c);
    goto L_70003620c0;
L_7000362110:;
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362118ull; f_7002833e20(c);
    (void)(subs64(c, c->x[19], (uint64_t)(c->x[21])));
    c->x[22] = (uint64_t)(0ull | c->x[19]);
    if (COND_EQ(c)) { goto L_7000361f80; }
L_7000362124:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[19] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0x18ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] == 0) { goto L_7000362110; }
    c->x[8] = (uint64_t)(c->x[25] + 0x8ull);
L_7000362134:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362134; }
    if (c->x[9] != 0) { goto L_7000362110; }
    { uint64_t ea = c->x[25] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362158ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000362160ull; f_7002833e50(c);
    goto L_7000362110;
L_7000362164:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x950ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003621ac; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_7000362180:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362180; }
    if (c->x[9] != 0) { goto L_70003621ac; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003621a4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003621acull; f_7002833e50(c);
L_70003621ac:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x960ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003621f0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_70003621c4:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003621c4; }
    if (c->x[9] != 0) { goto L_70003621f0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003621e8ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003621f0ull; f_7002833e50(c);
L_70003621f0:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0xb68ull; uint64_t v = LD64(ea); c->x[25] = (uint64_t)(v); }
    if (c->x[25] == 0) { goto L_700036225c; }
    { uint64_t ea = c->x[25] + 144; uint64_t a = LD64(ea), b = LD64(ea + 8); c->x[23] = (uint64_t)(a); c->x[19] = (uint64_t)(b); }
    goto L_7000362208;
L_7000362204:;
    c->x[19] = (uint64_t)(c->x[19] - 0x18ull);
L_7000362208:;
    (void)(subs64(c, c->x[19], (uint64_t)(c->x[23])));
    if (COND_EQ(c)) { goto L_7000362250; }
    { uint64_t ea = c->x[19] - 16; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000362204; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_7000362220:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362220; }
    if (c->x[9] != 0) { goto L_7000362204; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362244ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036224cull; f_7002833e50(c);
    goto L_7000362204;
L_7000362250:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[25] + 0x98ull; ST64(ea, c->x[23]); }
    { uint64_t ea = c->x[8] + 0xb68ull; ST64(ea, 0ull); }
L_700036225c:;
    c->x[19] = (uint64_t)(0x70034d2000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xbb0ull);
    c->x[8] = (uint64_t)(lda8(c->x[19]));
    if (((c->x[8] >> 0) & 1) == 0) { goto L_7000362ba0; }
L_700036226c:;
    c->x[0] = (uint64_t)(0x70034d2000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x4b0ull);
    c->x[30] = 0x7000362278ull; f_70028311a0(c);
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[23] = (uint64_t)(0ull | c->x[26]);
    { uint64_t ea = c->x[8] + 0x920ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[25] = (uint64_t)(0x70034bd000ull);
    c->x[25] = (uint64_t)(c->x[25] + 0x5f0ull);
    { uint64_t ea = c->x[8] + 0x920ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_7000362298; }
    c->x[30] = 0x7000362298ull; f_7002834000(c);
L_7000362298:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[26] = (uint64_t)(0ull | c->x[28]);
    { uint64_t ea = c->x[8] + 0x928ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034bc000ull);
    { uint64_t ea = c->x[8] + 0x400ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] != 0) { goto L_70003622f8; }
    c->x[0] = (uint32_t)(0xa0ull);
    c->x[30] = 0x70003622b8ull; f_7002833eb0(c);
    c->x[8] = (uint64_t)(0x70034bc000ull);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 68; ST64(ea, 0ull); }
    c->x[9] = (uint32_t)(0x3f800000ull);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 0x80ull; ST32(ea, (uint32_t)c->x[9]); }
    { uint64_t ea = c->x[0] + 0x88ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[8] + 0x400ull; ST64(ea, c->x[0]); }
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 63; ST32(ea, 0u); }
    { uint64_t ea = c->x[0] + 80; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 96; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 112; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 144; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
L_70003622f8:;
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x400ull; ST64(ea, 0ull); }
    c->x[30] = 0x7000362304ull; f_70026a1ab0(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036230cull; f_7002833e20(c);
    c->x[8] = (uint64_t)(0x70034b9000ull);
    c->x[28] = (uint64_t)(0ull | c->x[21]);
    { uint64_t ea = c->x[8] + 0x580ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    c->x[21] = (uint32_t)(0x1ull);
    if (c->x[22] == 0) { goto L_7000362364; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
L_7000362324:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_7000362324; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000362364; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036234cull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000362364; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362364ull; rt_dispatch(c);
L_7000362364:;
    c->x[8] = (uint64_t)(0x70034b9000ull);
    { uint64_t ea = c->x[8] + 0x580ull; ST64(ea, 0ull); }
    c->x[8] = (uint64_t)(0x70034a4000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x668ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003623b0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000362384:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362384; }
    if (c->x[9] != 0) { goto L_70003623b0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003623a8ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003623b0ull; f_7002833e50(c);
L_70003623b0:;
    c->x[19] = (uint64_t)(0ull | 0ull);
    goto L_70003623cc;
    /* hint */
    /* hint */
L_70003623c0:;
    c->x[19] = (uint64_t)(c->x[19] + 0x1ull);
    (void)(subs64(c, c->x[19], 0x1dull));
    if (COND_EQ(c)) { goto L_7000362410; }
L_70003623cc:;
    c->x[8] = (uint64_t)(c->x[27] + (c->x[19] << 4));
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003623c0; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_70003623e0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003623e0; }
    if (c->x[9] != 0) { goto L_70003623c0; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362404ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036240cull; f_7002833e50(c);
    goto L_70003623c0;
L_7000362410:;
    c->x[19] = (uint64_t)(0x70034d2000ull);
    { uint64_t ea = c->x[19] + 0x2b8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[30] = 0x700036241cull; f_7000360050(c);
    { uint64_t ea = c->x[19] + 0x2b8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000362440; }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[19] + 0x2b8ull; ST64(ea, 0ull); }
    c->x[30] = 0x7000362430ull; f_7002819640(c);
    c->x[0] = (uint64_t)(0x70034d2000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x2c8ull);
    c->x[1] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362440ull; f_7002833f20(c);
L_7000362440:;
    c->x[8] = (uint64_t)(0x70034d2000ull);
    { uint64_t ea = c->x[8] + 0x328ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x328ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_7000362460; }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362458ull; f_7000331350(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362460ull; f_7002833e20(c);
L_7000362460:;
    c->x[19] = (uint64_t)(0x70034d2000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x2c8ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362470ull; f_70028353c0(c);
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[19] + 0x48ull; ST8(ea, 0u); }
    { uint64_t ea = c->x[8] + 0x8a0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x8a0ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_7000362488; }
    c->x[30] = 0x7000362488ull; f_7002833e20(c);
L_7000362488:;
    c->x[8] = (uint64_t)(0x70034b7000ull);
    { uint64_t ea = c->x[8] + 0xf80ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0xf80ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_70003624a8; }
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[30] = 0x70003624a0ull; f_7002362258(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003624a8ull; f_7002833e20(c);
L_70003624a8:;
    c->x[8] = (uint64_t)(0x70034cb000ull);
    { uint64_t ea = c->x[8] + 0x40ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000362500; }
    c->x[8] = (uint64_t)(c->x[22] + 0x10ull);
    /* hint */
    /* hint */
L_70003624c0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[19] = (uint64_t)(c->x[9] + c->x[24]);
    { uint32_t st = stx64(c, c->x[8], c->x[19]); c->x[9] = (uint32_t)(st); }
    if ((uint32_t)c->x[9] != 0) { goto L_70003624c0; }
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[26])));
    if (COND_NE(c)) { goto L_7000362500; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x68ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003624e8ull; rt_dispatch(c);
    (void)(logic64(c, (uint64_t)(c->x[19] & c->x[23])));
    if (COND_NE(c)) { goto L_7000362500; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362500ull; rt_dispatch(c);
L_7000362500:;
    c->x[8] = (uint64_t)(0x70034cb000ull);
    c->x[19] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0x40ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[19] + 0xcf0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[22] = (uint64_t)(0x70034bd000ull);
    c->x[22] = (uint64_t)(c->x[22] + 0x790ull);
    { uint64_t ea = c->x[22] + 0x4ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x4b0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x28ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036252cull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0xcf0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0x4ull; ST32(ea, 0u); }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x430ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x28ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362548ull; rt_dispatch(c);
    { uint64_t ea = c->x[22] + 0x0ull; ST32(ea, 0u); }
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] != 0) { goto L_70003625d0; }
    c->x[0] = (uint32_t)(0xd0ull);
    c->x[30] = 0x700036255cull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xd38ull);
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[0] = (uint64_t)(c->x[0] + 0x50ull);
    { uint64_t ea = c->x[22] + 64; ST64(ea, 0ull); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x7000362584ull; f_7002833f70(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0xa8ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[22] + 0xb0ull; ST8(ea, (uint32_t)c->x[21]); }
    { uint64_t ea = c->x[22] + 177; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 185; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 193; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 0xc8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[22] + 152; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_70003625c0; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdd0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003625bcull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_70003625c0:;
    c->x[8] = (uint64_t)(0x700274e000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xa30ull);
    c->x[9] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[9] + 0xdd8ull; ST64(ea, c->x[8]); }
L_70003625d0:;
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[9] = (uint32_t)(0xbd40ull);
    c->x[0] = (uint64_t)(c->sp + 0x10ull);
    { uint64_t ea = c->sp + 0x30ull; ST64(ea, 0ull); }
    c->x[1] = (uint64_t)(c->x[8] + c->x[9]);
    c->x[30] = 0x70003625e8ull; f_700035b60c(c);
    { uint64_t ea = c->sp + 0x30ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[8] = (uint64_t)(c->sp + 0x10ull);
    (void)(subs64(c, c->x[0], (uint64_t)(c->x[8])));
    if (COND_EQ(c)) { goto L_7000362610; }
    if (c->x[0] == 0) { goto L_7000362624; }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[8] = (uint64_t)(c->x[8] + 0x28ull);
    goto L_700036261c;
    /* hint */
    /* hint */
L_7000362610:;
    { uint64_t ea = c->sp + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(c->sp + 0x10ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x20ull);
L_700036261c:;
    { uint64_t ea = c->x[8] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362624ull; rt_dispatch(c);
L_7000362624:;
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] != 0) { goto L_70003626a8; }
    c->x[0] = (uint32_t)(0xd0ull);
    c->x[30] = 0x7000362634ull; f_7002833eb0(c);
    c->x[22] = (uint64_t)(0ull | c->x[0]);
    { uint64_t ea = c->x[0] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[8] = (uint64_t)(0x7003436000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xd38ull);
    { uint64_t ea = c->x[0] + 16; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 32; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    { uint64_t ea = c->x[0] + 48; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[0] = (uint64_t)(c->x[0] + 0x50ull);
    { uint64_t ea = c->x[22] + 64; ST64(ea, 0ull); ST64(ea + 8, c->x[8]); }
    c->x[30] = 0x700036265cull; f_7002833f70(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0xa8ull; ST16(ea, 0u); }
    { uint64_t ea = c->x[22] + 0xb0ull; ST8(ea, (uint32_t)c->x[21]); }
    { uint64_t ea = c->x[22] + 177; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 185; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 193; ST64(ea, 0ull); }
    { uint64_t ea = c->x[22] + 0xc8ull; ST64(ea, 0ull); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, c->x[22]); }
    { uint64_t ea = c->x[22] + 152; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[0] == 0) { goto L_7000362698; }
    c->x[19] = (uint64_t)(0x70034ca000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xdd0ull);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362694ull; rt_dispatch(c);
    { uint64_t ea = c->x[19] + 0x0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
L_7000362698:;
    c->x[8] = (uint64_t)(0x700274e000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0xa30ull);
    c->x[9] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[9] + 0xdd8ull; ST64(ea, c->x[8]); }
L_70003626a8:;
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x730ull);
    { uint64_t ea = c->x[22] + 0x8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[19] + 0x68ull; uint64_t v = LD32(ea); c->x[1] = (uint64_t)(v); }
    c->x[30] = 0x70003626bcull; f_7002771c20(c);
    { uint64_t ea = c->x[19] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[19] + 0x68ull; ST32(ea, 0u); }
    { uint64_t ea = c->x[19] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    c->x[19] = (uint64_t)(0x70034d2000ull);
    if (c->x[22] == 0) { goto L_7000362700; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_70003626d4:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003626d4; }
    if (c->x[9] != 0) { goto L_7000362700; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003626f8ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362700ull; f_7002833e50(c);
L_7000362700:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x750ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_700036274c; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_7000362720:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362720; }
    if (c->x[9] != 0) { goto L_700036274c; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362744ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036274cull; f_7002833e50(c);
L_700036274c:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x780ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000362790; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_7000362764:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362764; }
    if (c->x[9] != 0) { goto L_7000362790; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362788ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362790ull; f_7002833e50(c);
L_7000362790:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x770ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003627dc; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_70003627b0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003627b0; }
    if (c->x[9] != 0) { goto L_70003627dc; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003627d4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003627dcull; f_7002833e50(c);
L_70003627dc:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x760ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_7000362820; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
L_70003627f4:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003627f4; }
    if (c->x[9] != 0) { goto L_7000362820; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362818ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362820ull; f_7002833e50(c);
L_7000362820:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x740ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_700036286c; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
    /* hint */
L_7000362840:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362840; }
    if (c->x[9] != 0) { goto L_700036286c; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362864ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036286cull; f_7002833e50(c);
L_700036286c:;
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    c->x[30] = 0x7000362874ull; f_7002756830(c);
    { uint64_t ea = c->x[28] + 0xdd0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[28] + 0xdd0ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_700036288c; }
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xdd8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x700036288cull; rt_dispatch(c);
L_700036288c:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x728ull; uint64_t v = LD64(ea); c->x[1] = (uint64_t)(v); }
    if (c->x[1] == 0) { goto L_70003628a4; }
    c->x[0] = (uint64_t)(0x7003488000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x940ull);
    c->x[30] = 0x70003628a4ull; f_7002833f20(c);
L_70003628a4:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x8a8ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_70003628ec; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_70003628c0:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_70003628c0; }
    if (c->x[9] != 0) { goto L_70003628ec; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003628e4ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x70003628ecull; f_7002833e50(c);
L_70003628ec:;
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xc68ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0xc68ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_7000362908; }
    c->x[8] = (uint64_t)(0x70034ca000ull);
    { uint64_t ea = c->x[8] + 0xc70ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362908ull; rt_dispatch(c);
L_7000362908:;
    { uint64_t ea = c->x[19] + 0x3b0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    if (c->x[22] == 0) { goto L_7000362924; }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362918ull; f_70027360c0(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362920ull; f_7002833e20(c);
    { uint64_t ea = c->x[19] + 0x3b0ull; ST64(ea, 0ull); }
L_7000362924:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    c->x[8] = (uint64_t)(c->x[8] + 0x4b8ull);
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0; ST64(ea, 0ull); ST64(ea + 8, 0ull); }
    if (c->x[22] == 0) { goto L_700036296c; }
    c->x[8] = (uint64_t)(c->x[22] + 0x8ull);
    /* hint */
L_7000362940:;
    c->x[9] = (uint64_t)(ldx64(c, c->x[8]));
    c->x[10] = (uint64_t)(c->x[9] - 0x1ull);
    { uint32_t st = stx64(c, c->x[8], c->x[10]); c->x[11] = (uint32_t)(st); }
    if ((uint32_t)c->x[11] != 0) { goto L_7000362940; }
    if (c->x[9] != 0) { goto L_700036296c; }
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    { uint64_t ea = c->x[8] + 0x10ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362964ull; rt_dispatch(c);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x700036296cull; f_7002833e50(c);
L_700036296c:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x4d8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x4d8ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_7000362988; }
    { uint64_t ea = c->x[0] + 0x0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x8ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x7000362988ull; rt_dispatch(c);
L_7000362988:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x4c8ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x4c8ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_70003629a4; }
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x4d0ull; uint64_t v = LD64(ea); c->x[8] = (uint64_t)(v); }
    c->pc = c->x[8]; c->x[30] = 0x70003629a4ull; rt_dispatch(c);
L_70003629a4:;
    c->x[8] = (uint64_t)(0x70034bd000ull);
    { uint64_t ea = c->x[8] + 0x4b0ull; uint64_t v = LD64(ea); c->x[22] = (uint64_t)(v); }
    { uint64_t ea = c->x[8] + 0x4b0ull; ST64(ea, 0ull); }
    if (c->x[22] == 0) { goto L_7000361008; }
    c->x[0] = (uint64_t)(c->x[22] + 0x8ull);
    c->x[30] = 0x70003629bcull; f_7002834070(c);
    { uint64_t ea = c->x[22] + 0x0ull; uint64_t v = LD64(ea); c->x[0] = (uint64_t)(v); }
    { uint64_t ea = c->x[22] + 0x0ull; ST64(ea, 0ull); }
    if (c->x[0] == 0) { goto L_7000361000; }
    c->x[30] = 0x70003629ccull; f_7002834000(c);
    goto L_7000361000;
L_70003629d0:;
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x70003629dcull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361024; }
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x70003629f0ull; f_700033a1f0(c);
    /* hint */
    c->x[0] = (uint64_t)(0x7000331770ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362a08ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x7000362a14ull; f_7002833e40(c);
    goto L_7000361024;
L_7000362a18:;
    c->x[0] = (uint64_t)(0x70034b5000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x1d8ull);
    c->x[30] = 0x7000362a24ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_70003612a8; }
    /* hint */
    c->x[0] = (uint64_t)(0x70003312e0ull);
    c->x[1] = (uint64_t)(0x70034b5000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x1d0ull);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362a44ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034b5000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x1d8ull);
    c->x[30] = 0x7000362a50ull; f_7002833e40(c);
    goto L_70003612a8;
L_7000362a54:;
    c->x[0] = (uint64_t)(0x70034a9000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x88ull);
    c->x[30] = 0x7000362a60ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361b24; }
    /* hint */
    c->x[0] = (uint64_t)(0x7000331300ull);
    c->x[1] = (uint64_t)(0x70034a9000ull);
    c->x[1] = (uint64_t)(c->x[1] + 0x80ull);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362a80ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034a9000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x88ull);
    c->x[30] = 0x7000362a8cull; f_7002833e40(c);
    goto L_7000361b24;
L_7000362a90:;
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x430ull);
    c->x[30] = 0x7000362a9cull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361be8; }
    c->x[19] = (uint64_t)(0x70034bc000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0xd10ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362ab0ull; f_7000611d94(c);
    c->x[0] = (uint64_t)(0x7000612000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xa0ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362ac8ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x430ull);
    c->x[30] = 0x7000362ad4ull; f_7002833e40(c);
    goto L_7000361be8;
L_7000362ad8:;
    c->x[0] = (uint64_t)(0x70034c8000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xf60ull);
    c->x[30] = 0x7000362ae4ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361c04; }
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x920ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362af8ull; f_700267aa60(c);
    c->x[0] = (uint64_t)(0x7002646000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xfd0ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362b10ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034c8000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xf60ull);
    c->x[30] = 0x7000362b1cull; f_7002833e40(c);
    goto L_7000361c04;
L_7000362b20:;
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000362b28ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361d60; }
    c->x[19] = (uint64_t)(0x70034d2000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362b3cull; f_700283155c(c);
    c->x[0] = (uint64_t)(0x7002830000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xfd0ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362b54ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000362b5cull; f_7002833e40(c);
    goto L_7000361d60;
L_7000362b60:;
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000362b68ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361d88; }
    c->x[19] = (uint64_t)(0x70034d2000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362b7cull; f_700283155c(c);
    c->x[0] = (uint64_t)(0x7002830000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xfd0ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362b94ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0ull | c->x[25]);
    c->x[30] = 0x7000362b9cull; f_7002833e40(c);
    goto L_7000361d88;
L_7000362ba0:;
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362ba8ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_700036226c; }
    c->x[22] = (uint64_t)(0x70034d2000ull);
    c->x[22] = (uint64_t)(c->x[22] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[22]);
    c->x[30] = 0x7000362bbcull; f_700283155c(c);
    c->x[0] = (uint64_t)(0x7002830000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0xfd0ull);
    c->x[1] = (uint64_t)(0ull | c->x[22]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362bd4ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362bdcull; f_7002833e40(c);
    goto L_700036226c;
L_7000362be0:;
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x7000362becull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361870; }
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362c00ull; f_700033a1f0(c);
    /* hint */
    c->x[0] = (uint64_t)(0x7000331770ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362c18ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x7000362c24ull; f_7002833e40(c);
    goto L_7000361870;
L_7000362c28:;
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x7000362c34ull; f_7002833e30(c);
    if ((uint32_t)c->x[0] == 0) { goto L_7000361350; }
    c->x[19] = (uint64_t)(0x70034bd000ull);
    c->x[19] = (uint64_t)(c->x[19] + 0x4b0ull);
    c->x[0] = (uint64_t)(0ull | c->x[19]);
    c->x[30] = 0x7000362c48ull; f_700033a1f0(c);
    /* hint */
    c->x[0] = (uint64_t)(0x7000331770ull);
    c->x[1] = (uint64_t)(0ull | c->x[19]);
    c->x[2] = (uint64_t)(0x7003074000ull);
    c->x[2] = (uint64_t)(c->x[2] + 0xe70ull);
    c->x[30] = 0x7000362c60ull; f_70000001d0(c);
    c->x[0] = (uint64_t)(0x70034bd000ull);
    c->x[0] = (uint64_t)(c->x[0] + 0x8e8ull);
    c->x[30] = 0x7000362c6cull; f_7002833e40(c);
    goto L_7000361350;
L_7000362c70:;
    c->x[0] = (uint64_t)(c->sp + 0x10ull);
    c->x[30] = 0x7000362c78ull; f_7002834040(c);
    __attribute__((musttail)) return f_7000362c78(c);
}
