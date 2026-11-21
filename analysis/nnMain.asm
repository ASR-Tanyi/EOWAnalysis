// main+0x360b70 nnMain (FDE+symbol), end main+0x362c78
L_7000360b70:
  7000360b70  d102c3ff  sub       sp, sp, #0xb0
  7000360b74  fd0023e8  str       d8, [sp, #0x40]
  7000360b78  a9057bfd  stp       x29, x30, [sp, #0x50]
  7000360b7c  a9066ffc  stp       x28, x27, [sp, #0x60]
  7000360b80  a90767fa  stp       x26, x25, [sp, #0x70]
  7000360b84  a9085ff8  stp       x24, x23, [sp, #0x80]
  7000360b88  a90957f6  stp       x22, x21, [sp, #0x90]
  7000360b8c  a90a4ff4  stp       x20, x19, [sp, #0xa0]
  7000360b90  910143fd  add       x29, sp, #0x50
  7000360b94  d0018b48  adrp      x8, #0x70034ca000
  7000360b98  b94cf909  ldr       w9, [x8, #0xcf8]
  7000360b9c  1100052a  add       w10, w9, #1
  7000360ba0  b90cf90a  str       w10, [x8, #0xcf8]
  7000360ba4  350012e9  cbnz      w9, #0x7000360e00  // conditional L_7000360e00
  7000360ba8  52809e00  mov       w0, #0x4f0
  7000360bac  94934cc1  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000360bb0  2a1f03e1  mov       w1, wzr
  7000360bb4  2a1f03e2  mov       w2, wzr
  7000360bb8  aa0003f3  mov       x19, x0
  7000360bbc  94935095  bl        #0x7002834e10  // call main+0x2834e10 plt:_ZN2nn2os15InitializeEventEPNS0_9EventTypeEbNS0_14EventClearModeE
  7000360bc0  9100a260  add       x0, x19, #0x28
  7000360bc4  52806902  mov       w2, #0x348
  7000360bc8  2a1f03e1  mov       w1, wzr
  7000360bcc  910dc274  add       x20, x19, #0x370
  7000360bd0  949352cc  bl        #0x7002835700  // call main+0x2835700 plt:memset
  7000360bd4  d00186a8  adrp      x8, #0x7003436000
  7000360bd8  911e0108  add       x8, x8, #0x780
  7000360bdc  f901c274  str       x20, [x19, #0x380]
  7000360be0  f901be68  str       x8, [x19, #0x378]
  7000360be4  d00186a8  adrp      x8, #0x7003436000
  7000360be8  911ce108  add       x8, x8, #0x738
  7000360bec  f901ba68  str       x8, [x19, #0x370]
  7000360bf0  d00186a8  adrp      x8, #0x7003436000
  7000360bf4  911f8108  add       x8, x8, #0x7e0
  7000360bf8  f901ca68  str       x8, [x19, #0x390]
  7000360bfc  d00186a8  adrp      x8, #0x7003436000
  7000360c00  911e6108  add       x8, x8, #0x798
  7000360c04  910e2269  add       x9, x19, #0x388
  7000360c08  f901c668  str       x8, [x19, #0x388]
  7000360c0c  910e8268  add       x8, x19, #0x3a0
  7000360c10  f901ce69  str       x9, [x19, #0x398]
  7000360c14  d00186a9  adrp      x9, #0x7003436000
  7000360c18  911fe129  add       x9, x9, #0x7f8
  7000360c1c  f901da68  str       x8, [x19, #0x3b0]
  7000360c20  910f0268  add       x8, x19, #0x3c0
  7000360c24  910f6260  add       x0, x19, #0x3d8
  7000360c28  f901d669  str       x9, [x19, #0x3a8]
  7000360c2c  d00186a9  adrp      x9, #0x7003436000
  7000360c30  91186129  add       x9, x9, #0x618
  7000360c34  f901de68  str       x8, [x19, #0x3b8]
  7000360c38  b20003e8  mov       x8, #0x100000001
  7000360c3c  f901d269  str       x9, [x19, #0x3a0]
  7000360c40  f901e27f  str       xzr, [x19, #0x3c0]
  7000360c44  f901e67f  str       xzr, [x19, #0x3c8]
  7000360c48  f901ea68  str       x8, [x19, #0x3d0]
  7000360c4c  94934d89  bl        #0x7002834270  // call main+0x2834270 plt:_ZNSt3__115recursive_mutexC1Ev
  7000360c50  910f8268  add       x8, x19, #0x3e0
  7000360c54  b0018734  adrp      x20, #0x7003445000
  7000360c58  9120a294  add       x20, x20, #0x828
  7000360c5c  f901fa68  str       x8, [x19, #0x3f0]
  7000360c60  b0018735  adrp      x21, #0x7003445000
  7000360c64  911e62b5  add       x21, x21, #0x798
  7000360c68  91100268  add       x8, x19, #0x400
  7000360c6c  f901f674  str       x20, [x19, #0x3e8]
  7000360c70  f901f275  str       x21, [x19, #0x3e0]
  7000360c74  52800036  mov       w22, #1
  7000360c78  91106260  add       x0, x19, #0x418
  7000360c7c  f902027f  str       xzr, [x19, #0x400]
  7000360c80  f902067f  str       xzr, [x19, #0x408]
  7000360c84  f901fe68  str       x8, [x19, #0x3f8]
  7000360c88  f9020a76  str       x22, [x19, #0x410]
  7000360c8c  94934d79  bl        #0x7002834270  // call main+0x2834270 plt:_ZNSt3__115recursive_mutexC1Ev
  7000360c90  91108268  add       x8, x19, #0x420
  7000360c94  91116260  add       x0, x19, #0x458
  7000360c98  f9021674  str       x20, [x19, #0x428]
  7000360c9c  f9021a68  str       x8, [x19, #0x430]
  7000360ca0  91110268  add       x8, x19, #0x440
  7000360ca4  f9021275  str       x21, [x19, #0x420]
  7000360ca8  f902227f  str       xzr, [x19, #0x440]
  7000360cac  f902267f  str       xzr, [x19, #0x448]
  7000360cb0  f9021e68  str       x8, [x19, #0x438]
  7000360cb4  f9022a76  str       x22, [x19, #0x450]
  7000360cb8  94934d6e  bl        #0x7002834270  // call main+0x2834270 plt:_ZNSt3__115recursive_mutexC1Ev
  7000360cbc  91118268  add       x8, x19, #0x460
  7000360cc0  91126260  add       x0, x19, #0x498
  7000360cc4  f9023674  str       x20, [x19, #0x468]
  7000360cc8  f9023a68  str       x8, [x19, #0x470]
  7000360ccc  91120268  add       x8, x19, #0x480
  7000360cd0  f9023275  str       x21, [x19, #0x460]
  7000360cd4  f902427f  str       xzr, [x19, #0x480]
  7000360cd8  f902467f  str       xzr, [x19, #0x488]
  7000360cdc  f9023e68  str       x8, [x19, #0x478]
  7000360ce0  f9024a76  str       x22, [x19, #0x490]
  7000360ce4  94934d63  bl        #0x7002834270  // call main+0x2834270 plt:_ZNSt3__115recursive_mutexC1Ev
  7000360ce8  91128268  add       x8, x19, #0x4a0
  7000360cec  91136260  add       x0, x19, #0x4d8
  7000360cf0  f9025674  str       x20, [x19, #0x4a8]
  7000360cf4  f9025a68  str       x8, [x19, #0x4b0]
  7000360cf8  91130268  add       x8, x19, #0x4c0
  7000360cfc  f9025275  str       x21, [x19, #0x4a0]
  7000360d00  f902627f  str       xzr, [x19, #0x4c0]
  7000360d04  f902667f  str       xzr, [x19, #0x4c8]
  7000360d08  f9025e68  str       x8, [x19, #0x4b8]
  7000360d0c  f9026a76  str       x22, [x19, #0x4d0]
  7000360d10  94934d58  bl        #0x7002834270  // call main+0x2834270 plt:_ZNSt3__115recursive_mutexC1Ev
  7000360d14  91139268  add       x8, x19, #0x4e4
  7000360d18  52800020  mov       w0, #1
  7000360d1c  3913827f  strb      wzr, [x19, #0x4e0]
  7000360d20  f9000116  str       x22, [x8]
  7000360d24  91139668  add       x8, x19, #0x4e5
  7000360d28  b900011f  str       wzr, [x8]
  7000360d2c  b904ea7f  str       wzr, [x19, #0x4e8]
  7000360d30  949351e4  bl        #0x70028354c0  // call main+0x28354c0 plt:_ZN2nn2oe44SetPerformanceModeChangedNotificationEnabledEb
  7000360d34  52800020  mov       w0, #1
  7000360d38  949351e6  bl        #0x70028354d0  // call main+0x28354d0 plt:_ZN2nn2oe42SetOperationModeChangedNotificationEnabledEb
  7000360d3c  52800020  mov       w0, #1
  7000360d40  949351e8  bl        #0x70028354e0  // call main+0x28354e0 plt:_ZN2nn2oe28SetResumeNotificationEnabledEb
  7000360d44  52800400  mov       w0, #0x20
  7000360d48  94934c5a  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000360d4c  52a00028  mov       w8, #0x10000
  7000360d50  52800049  mov       w9, #2
  7000360d54  390083e9  strb      w9, [sp, #0x20]
  7000360d58  a9017fe8  stp       x8, xzr, [sp, #0x10]
  7000360d5c  52800208  mov       w8, #0x10
  7000360d60  d503201f  nop
  7000360d64  10eca369  adr       x9, #0x700033a1d0
  7000360d68  aa0003f4  mov       x20, x0
  7000360d6c  b90027e8  str       w8, [sp, #0x24]
  7000360d70  90018748  adrp      x8, #0x7003448000
  7000360d74  910b8108  add       x8, x8, #0x2e0
  7000360d78  a9007c08  stp       x8, xzr, [x0]
  7000360d7c  a901241f  stp       xzr, x9, [x0, #0x10]
  7000360d80  52800800  mov       w0, #0x40
  7000360d84  94934c4b  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000360d88  d00186a8  adrp      x8, #0x7003436000
  7000360d8c  91204108  add       x8, x8, #0x810
  7000360d90  f9000813  str       x19, [x0, #0x10]
  7000360d94  d0011f29  adrp      x9, #0x7002746000
  7000360d98  911ff129  add       x9, x9, #0x7fc
  7000360d9c  aa0003f5  mov       x21, x0
  7000360da0  a9002408  stp       x8, x9, [x0]
  7000360da4  9100c000  add       x0, x0, #0x30
  7000360da8  f90012b5  str       x21, [x21, #0x20]
  7000360dac  94934cc9  bl        #0x70028340d0  // call main+0x28340d0 plt:_ZNSt3__17promiseIvEC1Ev
  7000360db0  910043e1  add       x1, sp, #0x10
  7000360db4  aa1403e0  mov       x0, x20
  7000360db8  aa1503e2  mov       x2, x21
  7000360dbc  97ffe097  bl        #0x7000359018  // call main+0x359018
  7000360dc0  f9401660  ldr       x0, [x19, #0x28]
  7000360dc4  f9001674  str       x20, [x19, #0x28]
  7000360dc8  b4000080  cbz       x0, #0x7000360dd8  // conditional L_7000360dd8
  7000360dcc  f9400008  ldr       x8, [x0]
  7000360dd0  f9400508  ldr       x8, [x8, #8]
  7000360dd4  d63f0100  blr       x8  // call-register
L_7000360dd8:
  7000360dd8  949351c6  bl        #0x70028354f0  // call main+0x28354f0 plt:_ZN2nn2oe31EnterExitRequestHandlingSectionEv
  7000360ddc  d0018b48  adrp      x8, #0x70034ca000
  7000360de0  39138276  strb      w22, [x19, #0x4e0]
  7000360de4  f9467914  ldr       x20, [x8, #0xcf0]
  7000360de8  f9067913  str       x19, [x8, #0xcf0]
  7000360dec  b40000b4  cbz       x20, #0x7000360e00  // conditional L_7000360e00
  7000360df0  aa1403e0  mov       x0, x20
  7000360df4  948f99ac  bl        #0x70027474a4  // call main+0x27474a4
  7000360df8  aa1403e0  mov       x0, x20
  7000360dfc  94934c09  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000360e00:
  7000360e00  90018940  adrp      x0, #0x7003488000
  7000360e04  91250000  add       x0, x0, #0x940
  7000360e08  52a0a001  mov       w1, #0x5000000
  7000360e0c  52820002  mov       w2, #0x1000
  7000360e10  94934c40  bl        #0x7002833f10  // call main+0x2833f10 plt:_ZN2nn3mem17StandardAllocator8AllocateEmm
  7000360e14  aa0003f4  mov       x20, x0
  7000360e18  d00188e0  adrp      x0, #0x700347e000
  7000360e1c  91170000  add       x0, x0, #0x5c0
  7000360e20  94934c68  bl        #0x7002833fc0  // call main+0x2833fc0 plt:_ZNSt3__15mutex4lockEv
  7000360e24  d0018b55  adrp      x21, #0x70034ca000
  7000360e28  f946fab3  ldr       x19, [x21, #0xdf0]
  7000360e2c  b50003b3  cbnz      x19, #0x7000360ea0  // conditional L_7000360ea0
  7000360e30  52801c00  mov       w0, #0xe0
  7000360e34  94934c1f  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000360e38  d00186b6  adrp      x22, #0x7003436000
  7000360e3c  9134e2d6  add       x22, x22, #0xd38
  7000360e40  f9000416  str       x22, [x0, #8]
  7000360e44  aa0003f3  mov       x19, x0
  7000360e48  91004000  add       x0, x0, #0x10
  7000360e4c  94934c49  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000360e50  9101e260  add       x0, x19, #0x78
  7000360e54  7900d27f  strh      wzr, [x19, #0x68]
  7000360e58  f9003a76  str       x22, [x19, #0x70]
  7000360e5c  a905fe7f  stp       xzr, xzr, [x19, #0x58]
  7000360e60  94934c44  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000360e64  f946faa0  ldr       x0, [x21, #0xdf0]
  7000360e68  7901a27f  strh      wzr, [x19, #0xd0]
  7000360e6c  f9006e7f  str       xzr, [x19, #0xd8]
  7000360e70  f906fab3  str       x19, [x21, #0xdf0]
  7000360e74  a90c7e7f  stp       xzr, xzr, [x19, #0xc0]
  7000360e78  b40000c0  cbz       x0, #0x7000360e90  // conditional L_7000360e90
  7000360e7c  d0018b53  adrp      x19, #0x70034ca000
  7000360e80  9137c273  add       x19, x19, #0xdf0
  7000360e84  f9400668  ldr       x8, [x19, #8]
  7000360e88  d63f0100  blr       x8  // call-register
  7000360e8c  f9400273  ldr       x19, [x19]
L_7000360e90:
  7000360e90  d0018b48  adrp      x8, #0x70034ca000
  7000360e94  b0011fc9  adrp      x9, #0x7002759000
  7000360e98  91162129  add       x9, x9, #0x588
  7000360e9c  f906fd09  str       x9, [x8, #0xdf8]
L_7000360ea0:
  7000360ea0  d00188e0  adrp      x0, #0x700347e000
  7000360ea4  91170000  add       x0, x0, #0x5c0
  7000360ea8  94934c4a  bl        #0x7002833fd0  // call main+0x2833fd0 plt:_ZNSt3__15mutex6unlockEv
  7000360eac  f9406e68  ldr       x8, [x19, #0xd8]
  7000360eb0  b5000868  cbnz      x8, #0x7000360fbc  // conditional L_7000360fbc
  7000360eb4  52a0a008  mov       w8, #0x5000000
  7000360eb8  f9006e74  str       x20, [x19, #0xd8]
  7000360ebc  f9001bf4  str       x20, [sp, #0x30]
  7000360ec0  a9017fe8  stp       x8, xzr, [sp, #0x10]
  7000360ec4  910043e8  add       x8, sp, #0x10
  7000360ec8  91008115  add       x21, x8, #0x20
  7000360ecc  52a08008  mov       w8, #0x4000000
  7000360ed0  a90253ff  stp       xzr, x20, [sp, #0x20]
L_7000360ed4:
  7000360ed4  c85ffea1  ldaxr     x1, [x21]
  7000360ed8  8b080029  add       x9, x1, x8
  7000360edc  c80afea9  stlxr     w10, x9, [x21]
  7000360ee0  35ffffaa  cbnz      w10, #0x7000360ed4  // conditional L_7000360ed4
  7000360ee4  52a08008  mov       w8, #0x4000000
  7000360ee8  91004260  add       x0, x19, #0x10
  7000360eec  52a08002  mov       w2, #0x4000000
  7000360ef0  a905a261  stp       x1, x8, [x19, #0x58]
  7000360ef4  94935127  bl        #0x7002835390  // call main+0x2835390 plt:_ZN2nn3mem17StandardAllocator10InitializeEPvm
  7000360ef8  d503201f  nop
  7000360efc  d503201f  nop
L_7000360f00:
  7000360f00  c85ffea1  ldaxr     x1, [x21]
  7000360f04  91600028  add       x8, x1, #0x800, lsl #12
  7000360f08  c809fea8  stlxr     w9, x8, [x21]
  7000360f0c  35ffffa9  cbnz      w9, #0x7000360f00  // conditional L_7000360f00
  7000360f10  52a01008  mov       w8, #0x800000
  7000360f14  9101e260  add       x0, x19, #0x78
  7000360f18  52a01002  mov       w2, #0x800000
  7000360f1c  a90c2261  stp       x1, x8, [x19, #0xc0]
  7000360f20  9493511c  bl        #0x7002835390  // call main+0x2835390 plt:_ZN2nn3mem17StandardAllocator10InitializeEPvm
  7000360f24  b0011fc0  adrp      x0, #0x7002759000
  7000360f28  9112c000  add       x0, x0, #0x4b0
  7000360f2c  b0011fc1  adrp      x1, #0x7002759000
  7000360f30  91178021  add       x1, x1, #0x5e0
  7000360f34  b0011fc2  adrp      x2, #0x7002759000
  7000360f38  911ac042  add       x2, x2, #0x6b0
  7000360f3c  aa1f03e3  mov       x3, xzr
  7000360f40  94935188  bl        #0x7002835560  // call main+0x2835560 plt:_ZN2nv20SetGraphicsAllocatorEPFPvmmS0_EPFvS0_S0_EPFS0_S0_mS0_ES0_
  7000360f44  b0011fc0  adrp      x0, #0x7002759000
  7000360f48  911e0000  add       x0, x0, #0x780
  7000360f4c  b0011fc1  adrp      x1, #0x7002759000
  7000360f50  91218021  add       x1, x1, #0x860
  7000360f54  b0011fc2  adrp      x2, #0x7002759000
  7000360f58  9124c042  add       x2, x2, #0x930
  7000360f5c  aa1f03e3  mov       x3, xzr
  7000360f60  94935184  bl        #0x7002835570  // call main+0x2835570 plt:_ZN2nv28SetGraphicsDevtoolsAllocatorEPFPvmmS0_EPFvS0_S0_EPFS0_S0_mS0_ES0_
L_7000360f64:
  7000360f64  c85ffea0  ldaxr     x0, [x21]
  7000360f68  91600008  add       x8, x0, #0x800, lsl #12
  7000360f6c  c809fea8  stlxr     w9, x8, [x21]
  7000360f70  35ffffa9  cbnz      w9, #0x7000360f64  // conditional L_7000360f64
  7000360f74  52a01001  mov       w1, #0x800000
  7000360f78  94935182  bl        #0x7002835580  // call main+0x2835580 plt:_ZN2nv18InitializeGraphicsEPvm
  7000360f7c  f94013f3  ldr       x19, [sp, #0x20]
  7000360f80  b40001f3  cbz       x19, #0x7000360fbc  // conditional L_7000360fbc
  7000360f84  91002268  add       x8, x19, #8
  7000360f88  d503201f  nop
  7000360f8c  d503201f  nop
L_7000360f90:
  7000360f90  c85ffd09  ldaxr     x9, [x8]
  7000360f94  d100052a  sub       x10, x9, #1
  7000360f98  c80bfd0a  stlxr     w11, x10, [x8]
  7000360f9c  35ffffab  cbnz      w11, #0x7000360f90  // conditional L_7000360f90
  7000360fa0  b50000e9  cbnz      x9, #0x7000360fbc  // conditional L_7000360fbc
  7000360fa4  f9400268  ldr       x8, [x19]
  7000360fa8  aa1303e0  mov       x0, x19
  7000360fac  f9400908  ldr       x8, [x8, #0x10]
  7000360fb0  d63f0100  blr       x8  // call-register
  7000360fb4  aa1303e0  mov       x0, x19
  7000360fb8  94934ba6  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000360fbc:
  7000360fbc  2f00e408  movi      d8, #0000000000000000
  7000360fc0  b2687ff7  mov       x23, #0xffffffff000000
  7000360fc4  b2684ffa  mov       x26, #0xfffff000000
  7000360fc8  f29fe017  movk      x23, #0xff00
  7000360fcc  f29fe01a  movk      x26, #0xff00
  7000360fd0  d0018b5c  adrp      x28, #0x70034ca000
  7000360fd4  52800035  mov       w21, #1
  7000360fd8  b0018af9  adrp      x25, #0x70034bd000
  7000360fdc  9117c339  add       x25, x25, #0x5f0
  7000360fe0  b0018af4  adrp      x20, #0x70034bd000
  7000360fe4  912da294  add       x20, x20, #0xb68
  7000360fe8  b0018adb  adrp      x27, #0x70034b9000
  7000360fec  910b837b  add       x27, x27, #0x2e0
  7000360ff0  b2607ff8  mov       x24, #-0x100000000
  7000360ff4  14000008  b         #0x7000361014  // jump L_7000361014
  7000360ff8  d503201f  .word     0xd503201f  // outside recovered control flow
  7000360ffc  d503201f  .word     0xd503201f  // outside recovered control flow
L_7000361000:
  7000361000  aa1603e0  mov       x0, x22
  7000361004  94934b87  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000361008:
  7000361008  94934ba6  bl        #0x7002833ea0  // call main+0x2833ea0 plt:_ZN2nn4time8FinalizeEv
  700036100c  b90013e0  str       w0, [sp, #0x10]
  7000361010  3500e300  cbnz      w0, #0x7000362c70  // conditional L_7000362c70
L_7000361014:
  7000361014  90018ae8  adrp      x8, #0x70034bd000
  7000361018  9123a108  add       x8, x8, #0x8e8
  700036101c  08dffd08  ldarb     w8, [x8]
  7000361020  3600cd88  tbz       w8, #0, #0x70003629d0  // conditional L_70003629d0
L_7000361024:
  7000361024  97ff654f  bl        #0x700033a560  // call main+0x33a560
  7000361028  f946eb96  ldr       x22, [x28, #0xdd0]
  700036102c  b5000416  cbnz      x22, #0x70003610ac  // conditional L_70003610ac
  7000361030  52801a00  mov       w0, #0xd0
  7000361034  94934b9f  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000361038  aa0003f6  mov       x22, x0
  700036103c  a9007c1f  stp       xzr, xzr, [x0]
  7000361040  b00186a8  adrp      x8, #0x7003436000
  7000361044  9134e108  add       x8, x8, #0xd38
  7000361048  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  700036104c  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  7000361050  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  7000361054  91014000  add       x0, x0, #0x50
  7000361058  a90422df  stp       xzr, x8, [x22, #0x40]
  700036105c  94934bc5  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000361060  f946eb80  ldr       x0, [x28, #0xdd0]
  7000361064  790152df  strh      wzr, [x22, #0xa8]
  7000361068  3902c2d5  strb      w21, [x22, #0xb0]
  700036106c  f80b12df  stur      xzr, [x22, #0xb1]
  7000361070  f80b92df  stur      xzr, [x22, #0xb9]
  7000361074  f80c12df  stur      xzr, [x22, #0xc1]
  7000361078  f90066df  str       xzr, [x22, #0xc8]
  700036107c  f906eb96  str       x22, [x28, #0xdd0]
  7000361080  a909fedf  stp       xzr, xzr, [x22, #0x98]
  7000361084  b40000c0  cbz       x0, #0x700036109c  // conditional L_700036109c
  7000361088  b0018b53  adrp      x19, #0x70034ca000
  700036108c  91374273  add       x19, x19, #0xdd0
  7000361090  f9400668  ldr       x8, [x19, #8]
  7000361094  d63f0100  blr       x8  // call-register
  7000361098  f9400276  ldr       x22, [x19]
L_700036109c:
  700036109c  b0011f68  adrp      x8, #0x700274e000
  70003610a0  9128c108  add       x8, x8, #0xa30
  70003610a4  b0018b49  adrp      x9, #0x70034ca000
  70003610a8  f906ed28  str       x8, [x9, #0xdd8]
L_70003610ac:
  70003610ac  f94006c8  ldr       x8, [x22, #8]
  70003610b0  52979909  mov       w9, #0xbcc8
  70003610b4  8b090113  add       x19, x8, x9
  70003610b8  b9400669  ldr       w9, [x19, #4]
  70003610bc  7100053f  cmp       w9, #1
  70003610c0  5400014b  b.lt      #0x70003610e8  // conditional L_70003610e8
  70003610c4  b9400262  ldr       w2, [x19]
  70003610c8  52860609  mov       w9, #0x3030
  70003610cc  8b090116  add       x22, x8, x9
  70003610d0  528a0b09  mov       w9, #0x5058
  70003610d4  8b090101  add       x1, x8, x9
  70003610d8  aa1603e0  mov       x0, x22
  70003610dc  97ff2e56  bl        #0x700032ca34  // call main+0x32ca34
  70003610e0  aa1603e0  mov       x0, x22
  70003610e4  97ff2e4f  bl        #0x700032ca20  // call main+0x32ca20
L_70003610e8:
  70003610e8  b900067f  str       wzr, [x19, #4]
  70003610ec  90018af3  adrp      x19, #0x70034bd000
  70003610f0  d0018ad6  adrp      x22, #0x70034bb000
  70003610f4  f9438e68  ldr       x8, [x19, #0x718]
  70003610f8  3941a108  ldrb      w8, [x8, #0x68]
  70003610fc  34000328  cbz       w8, #0x7000361160  // conditional L_7000361160
L_7000361100:
  7000361100  aa1903e0  mov       x0, x25
  7000361104  97ffd7db  bl        #0x7000357070  // call main+0x357070
  7000361108  f9446ec8  ldr       x8, [x22, #0x8d8]
  700036110c  b4000088  cbz       x8, #0x700036111c  // conditional L_700036111c
  7000361110  f940c108  ldr       x8, [x8, #0x180]
  7000361114  f100011f  cmp       x8, #0
  7000361118  1a9f07e8  cset      w8, ne
L_700036111c:
  700036111c  90018ae9  adrp      x9, #0x70034bd000
  7000361120  39614529  ldrb      w9, [x9, #0x851]
  7000361124  340005e9  cbz       w9, #0x70003611e0  // conditional L_70003611e0
  7000361128  b00188e8  adrp      x8, #0x700347e000
  700036112c  2f00e400  movi      d0, #0000000000000000
  7000361130  39168115  strb      w21, [x8, #0x5a0]
  7000361134  1400003f  b         #0x7000361230  // jump L_7000361230
  7000361138  d503201f  .word     0xd503201f  // outside recovered control flow
  700036113c  d503201f  .word     0xd503201f  // outside recovered control flow
L_7000361140:
  7000361140  b00188e8  adrp      x8, #0x700347e000
  7000361144  2f00e400  movi      d0, #0000000000000000
  7000361148  39168115  strb      w21, [x8, #0x5a0]
L_700036114c:
  700036114c  90018b48  adrp      x8, #0x70034c9000
  7000361150  bd000900  str       s0, [x8, #8]
  7000361154  f9438e68  ldr       x8, [x19, #0x718]
  7000361158  3941a108  ldrb      w8, [x8, #0x68]
  700036115c  35fffd28  cbnz      w8, #0x7000361100  // conditional L_7000361100
L_7000361160:
  7000361160  aa1903e0  mov       x0, x25
  7000361164  97ffd7c3  bl        #0x7000357070  // call main+0x357070
  7000361168  f9446ec8  ldr       x8, [x22, #0x8d8]
  700036116c  b4000088  cbz       x8, #0x700036117c  // conditional L_700036117c
  7000361170  f940c108  ldr       x8, [x8, #0x180]
  7000361174  f100011f  cmp       x8, #0
  7000361178  1a9f07e8  cset      w8, ne
L_700036117c:
  700036117c  90018ae9  adrp      x9, #0x70034bd000
  7000361180  39614529  ldrb      w9, [x9, #0x851]
  7000361184  35fffde9  cbnz      w9, #0x7000361140  // conditional L_7000361140
  7000361188  90018ae9  adrp      x9, #0x70034bd000
  700036118c  2f00e400  movi      d0, #0000000000000000
  7000361190  39614129  ldrb      w9, [x9, #0x850]
  7000361194  7100013f  cmp       w9, #0
  7000361198  b00188e9  adrp      x9, #0x700347e000
  700036119c  1a9f0508  csinc     w8, w8, wzr, eq
  70003611a0  39168128  strb      w8, [x9, #0x5a0]
  70003611a4  3707fd48  tbnz      w8, #0, #0x700036114c  // conditional L_700036114c
  70003611a8  90018b88  adrp      x8, #0x70034d1000
  70003611ac  bd496100  ldr       s0, [x8, #0x960]
  70003611b0  b0018b48  adrp      x8, #0x70034ca000
  70003611b4  bd4d9501  ldr       s1, [x8, #0xd94]
  70003611b8  90018b48  adrp      x8, #0x70034c9000
  70003611bc  1e286800  fmaxnm    s0, s0, s8
  70003611c0  1e212000  fcmp      s0, s1
  70003611c4  1e20cc20  fcsel     s0, s1, s0, gt
  70003611c8  bd400d01  ldr       s1, [x8, #0xc]
  70003611cc  1e202821  fadd      s1, s1, s0
  70003611d0  bd000d01  str       s1, [x8, #0xc]
  70003611d4  17ffffde  b         #0x700036114c  // jump L_700036114c
  70003611d8  d503201f  .word     0xd503201f  // outside recovered control flow
  70003611dc  d503201f  .word     0xd503201f  // outside recovered control flow
L_70003611e0:
  70003611e0  90018ae9  adrp      x9, #0x70034bd000
  70003611e4  2f00e400  movi      d0, #0000000000000000
  70003611e8  39614129  ldrb      w9, [x9, #0x850]
  70003611ec  7100013f  cmp       w9, #0
  70003611f0  b00188e9  adrp      x9, #0x700347e000
  70003611f4  1a9f0508  csinc     w8, w8, wzr, eq
  70003611f8  39168128  strb      w8, [x9, #0x5a0]
  70003611fc  370001a8  tbnz      w8, #0, #0x7000361230  // conditional L_7000361230
  7000361200  90018b88  adrp      x8, #0x70034d1000
  7000361204  bd496100  ldr       s0, [x8, #0x960]
  7000361208  b0018b48  adrp      x8, #0x70034ca000
  700036120c  bd4d9501  ldr       s1, [x8, #0xd94]
  7000361210  90018b48  adrp      x8, #0x70034c9000
  7000361214  1e286800  fmaxnm    s0, s0, s8
  7000361218  1e212000  fcmp      s0, s1
  700036121c  1e20cc20  fcsel     s0, s1, s0, gt
  7000361220  bd400d01  ldr       s1, [x8, #0xc]
  7000361224  1e202821  fadd      s1, s1, s0
  7000361228  bd000d01  str       s1, [x8, #0xc]
  700036122c  d503201f  nop
L_7000361230:
  7000361230  90018b48  adrp      x8, #0x70034c9000
  7000361234  bd000900  str       s0, [x8, #8]
  7000361238  f0018ac8  adrp      x8, #0x70034bc000
  700036123c  f940bd16  ldr       x22, [x8, #0x178]
  7000361240  b4000296  cbz       x22, #0x7000361290  // conditional L_7000361290
  7000361244  910042c8  add       x8, x22, #0x10
  7000361248  d503201f  nop
  700036124c  d503201f  nop
L_7000361250:
  7000361250  c85ffd09  ldaxr     x9, [x8]
  7000361254  8b180133  add       x19, x9, x24
  7000361258  c809fd13  stlxr     w9, x19, [x8]
  700036125c  35ffffa9  cbnz      w9, #0x7000361250  // conditional L_7000361250
  7000361260  ea1a027f  tst       x19, x26
  7000361264  54000161  b.ne      #0x7000361290  // conditional L_7000361290
  7000361268  f94002c8  ldr       x8, [x22]
  700036126c  aa1603e0  mov       x0, x22
  7000361270  f9403508  ldr       x8, [x8, #0x68]
  7000361274  d63f0100  blr       x8  // call-register
  7000361278  ea17027f  tst       x19, x23
  700036127c  540000a1  b.ne      #0x7000361290  // conditional L_7000361290
  7000361280  f94002c8  ldr       x8, [x22]
  7000361284  aa1603e0  mov       x0, x22
  7000361288  f9400508  ldr       x8, [x8, #8]
  700036128c  d63f0100  blr       x8  // call-register
L_7000361290:
  7000361290  f0018ac8  adrp      x8, #0x70034bc000
  7000361294  f900bd1f  str       xzr, [x8, #0x178]
  7000361298  90018aa8  adrp      x8, #0x70034b5000
  700036129c  91076108  add       x8, x8, #0x1d8
  70003612a0  08dffd08  ldarb     w8, [x8]
  70003612a4  3600bba8  tbz       w8, #0, #0x7000362a18  // conditional L_7000362a18
L_70003612a8:
  70003612a8  90018aa8  adrp      x8, #0x70034b5000
  70003612ac  f940e900  ldr       x0, [x8, #0x1d0]
  70003612b0  b5000120  cbnz      x0, #0x70003612d4  // conditional L_70003612d4
  70003612b4  52800300  mov       w0, #0x18
  70003612b8  94934afe  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  70003612bc  f0018308  adrp      x8, #0x70033c4000
  70003612c0  91112108  add       x8, x8, #0x448
  70003612c4  f900081f  str       xzr, [x0, #0x10]
  70003612c8  a9007c08  stp       x8, xzr, [x0]
  70003612cc  90018aa8  adrp      x8, #0x70034b5000
  70003612d0  f900e900  str       x0, [x8, #0x1d0]
L_70003612d4:
  70003612d4  f9400816  ldr       x22, [x0, #0x10]
  70003612d8  a900fc1f  stp       xzr, xzr, [x0, #8]
  70003612dc  b40001b6  cbz       x22, #0x7000361310  // conditional L_7000361310
  70003612e0  910022c8  add       x8, x22, #8
L_70003612e4:
  70003612e4  c85ffd09  ldaxr     x9, [x8]
  70003612e8  d100052a  sub       x10, x9, #1
  70003612ec  c80bfd0a  stlxr     w11, x10, [x8]
  70003612f0  35ffffab  cbnz      w11, #0x70003612e4  // conditional L_70003612e4
  70003612f4  b50000e9  cbnz      x9, #0x7000361310  // conditional L_7000361310
  70003612f8  f94002c8  ldr       x8, [x22]
  70003612fc  aa1603e0  mov       x0, x22
  7000361300  f9400908  ldr       x8, [x8, #0x10]
  7000361304  d63f0100  blr       x8  // call-register
  7000361308  aa1603e0  mov       x0, x22
  700036130c  94934ad1  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361310:
  7000361310  90018ac8  adrp      x8, #0x70034b9000
  7000361314  f9410900  ldr       x0, [x8, #0x210]
  7000361318  b4000be0  cbz       x0, #0x7000361494  // conditional L_7000361494
  700036131c  f9400008  ldr       x8, [x0]
  7000361320  f9400d08  ldr       x8, [x8, #0x18]
  7000361324  d63f0100  blr       x8  // call-register
  7000361328  90018ac8  adrp      x8, #0x70034b9000
  700036132c  f9410919  ldr       x25, [x8, #0x210]
  7000361330  f9400728  ldr       x8, [x25, #8]
  7000361334  aa1903f6  mov       x22, x25
  7000361338  b9401108  ldr       w8, [x8, #0x10]
  700036133c  37f801c8  tbnz      w8, #0x1f, #0x7000361374  // conditional L_7000361374
  7000361340  90018ae8  adrp      x8, #0x70034bd000
  7000361344  9123a108  add       x8, x8, #0x8e8
  7000361348  08dffd08  ldarb     w8, [x8]
  700036134c  3600c6e8  tbz       w8, #0, #0x7000362c28  // conditional L_7000362c28
L_7000361350:
  7000361350  f9400728  ldr       x8, [x25, #8]
  7000361354  91004100  add       x0, x8, #0x10
  7000361358  94236a92  bl        #0x7000c3bda0  // call main+0xc3bda0
  700036135c  f9400728  ldr       x8, [x25, #8]
  7000361360  12800009  mov       w9, #-1
  7000361364  b9001109  str       w9, [x8, #0x10]
  7000361368  90018ac8  adrp      x8, #0x70034b9000
  700036136c  f9410916  ldr       x22, [x8, #0x210]
  7000361370  b4000296  cbz       x22, #0x70003613c0  // conditional L_70003613c0
L_7000361374:
  7000361374  910042c8  add       x8, x22, #0x10
  7000361378  d503201f  nop
  700036137c  d503201f  nop
L_7000361380:
  7000361380  c85ffd09  ldaxr     x9, [x8]
  7000361384  8b180133  add       x19, x9, x24
  7000361388  c809fd13  stlxr     w9, x19, [x8]
  700036138c  35ffffa9  cbnz      w9, #0x7000361380  // conditional L_7000361380
  7000361390  ea1a027f  tst       x19, x26
  7000361394  54000161  b.ne      #0x70003613c0  // conditional L_70003613c0
  7000361398  f94002c8  ldr       x8, [x22]
  700036139c  aa1603e0  mov       x0, x22
  70003613a0  f9403508  ldr       x8, [x8, #0x68]
  70003613a4  d63f0100  blr       x8  // call-register
  70003613a8  ea17027f  tst       x19, x23
  70003613ac  540000a1  b.ne      #0x70003613c0  // conditional L_70003613c0
  70003613b0  f94002c8  ldr       x8, [x22]
  70003613b4  aa1603e0  mov       x0, x22
  70003613b8  f9400508  ldr       x8, [x8, #8]
  70003613bc  d63f0100  blr       x8  // call-register
L_70003613c0:
  70003613c0  90018ac8  adrp      x8, #0x70034b9000
  70003613c4  b2689fed  mov       x13, #-0x1000000
  70003613c8  f901091f  str       xzr, [x8, #0x210]
  70003613cc  91004328  add       x8, x25, #0x10
  70003613d0  52a0200e  mov       w14, #0x1000000
  70003613d4  c8dffd0a  ldar      x10, [x8]
  70003613d8  92681d49  and       x9, x10, #0xff000000
  70003613dc  8b0d014b  add       x11, x10, x13
  70003613e0  9247f96c  and       x12, x11, #0xfeffffffffffffff
  70003613e4  eb0e013f  cmp       x9, x14
  70003613e8  9a8b0196  csel      x22, x12, x11, eq
  70003613ec  d503201f  nop
L_70003613f0:
  70003613f0  c85ffd09  ldaxr     x9, [x8]
  70003613f4  eb0a013f  cmp       x9, x10
  70003613f8  540000c1  b.ne      #0x7000361410  // conditional L_7000361410
  70003613fc  c80bfd16  stlxr     w11, x22, [x8]
  7000361400  35ffff8b  cbnz      w11, #0x70003613f0  // conditional L_70003613f0
  7000361404  5280002a  mov       w10, #1
  7000361408  3600014a  tbz       w10, #0, #0x7000361430  // conditional L_7000361430
  700036140c  14000016  b         #0x7000361464  // jump L_7000361464
L_7000361410:
  7000361410  2a1f03ea  mov       w10, wzr
  7000361414  d5033f5f  clrex
  7000361418  360000ca  tbz       w10, #0, #0x7000361430  // conditional L_7000361430
  700036141c  14000012  b         #0x7000361464  // jump L_7000361464
L_7000361420:
  7000361420  2a1f03eb  mov       w11, wzr
  7000361424  d5033f5f  clrex
  7000361428  aa0a03e9  mov       x9, x10
  700036142c  350001cb  cbnz      w11, #0x7000361464  // conditional L_7000361464
L_7000361430:
  7000361430  92681d2a  and       x10, x9, #0xff000000
  7000361434  8b0d012b  add       x11, x9, x13
  7000361438  9247f96c  and       x12, x11, #0xfeffffffffffffff
  700036143c  eb0e015f  cmp       x10, x14
  7000361440  9a8b0196  csel      x22, x12, x11, eq
L_7000361444:
  7000361444  c85ffd0a  ldaxr     x10, [x8]
  7000361448  eb09015f  cmp       x10, x9
  700036144c  54fffea1  b.ne      #0x7000361420  // conditional L_7000361420
  7000361450  c80bfd16  stlxr     w11, x22, [x8]
  7000361454  35ffff8b  cbnz      w11, #0x7000361444  // conditional L_7000361444
  7000361458  5280002b  mov       w11, #1
  700036145c  aa0a03e9  mov       x9, x10
  7000361460  34fffe8b  cbz       w11, #0x7000361430  // conditional L_7000361430
L_7000361464:
  7000361464  ea1a02df  tst       x22, x26
  7000361468  54000161  b.ne      #0x7000361494  // conditional L_7000361494
  700036146c  f9400328  ldr       x8, [x25]
  7000361470  aa1903e0  mov       x0, x25
  7000361474  f9403508  ldr       x8, [x8, #0x68]
  7000361478  d63f0100  blr       x8  // call-register
  700036147c  ea1702df  tst       x22, x23
  7000361480  540000a1  b.ne      #0x7000361494  // conditional L_7000361494
  7000361484  f9400328  ldr       x8, [x25]
  7000361488  aa1903e0  mov       x0, x25
  700036148c  f9400508  ldr       x8, [x8, #8]
  7000361490  d63f0100  blr       x8  // call-register
L_7000361494:
  7000361494  90018ae8  adrp      x8, #0x70034bd000
  7000361498  f9421d16  ldr       x22, [x8, #0x438]
  700036149c  f9021d1f  str       xzr, [x8, #0x438]
  70003614a0  b4000456  cbz       x22, #0x7000361528  // conditional L_7000361528
  70003614a4  f9400ed9  ldr       x25, [x22, #0x18]
  70003614a8  b40000f9  cbz       x25, #0x70003614c4  // conditional L_70003614c4
  70003614ac  91002328  add       x8, x25, #8
L_70003614b0:
  70003614b0  c85ffd09  ldaxr     x9, [x8]
  70003614b4  d100052a  sub       x10, x9, #1
  70003614b8  c80bfd0a  stlxr     w11, x10, [x8]
  70003614bc  35ffffab  cbnz      w11, #0x70003614b0  // conditional L_70003614b0
  70003614c0  b4000209  cbz       x9, #0x7000361500  // conditional L_7000361500
L_70003614c4:
  70003614c4  f94006d9  ldr       x25, [x22, #8]
  70003614c8  b40002d9  cbz       x25, #0x7000361520  // conditional L_7000361520
L_70003614cc:
  70003614cc  91002328  add       x8, x25, #8
L_70003614d0:
  70003614d0  c85ffd09  ldaxr     x9, [x8]
  70003614d4  d100052a  sub       x10, x9, #1
  70003614d8  c80bfd0a  stlxr     w11, x10, [x8]
  70003614dc  35ffffab  cbnz      w11, #0x70003614d0  // conditional L_70003614d0
  70003614e0  b5000209  cbnz      x9, #0x7000361520  // conditional L_7000361520
  70003614e4  f9400328  ldr       x8, [x25]
  70003614e8  aa1903e0  mov       x0, x25
  70003614ec  f9400908  ldr       x8, [x8, #0x10]
  70003614f0  d63f0100  blr       x8  // call-register
  70003614f4  aa1903e0  mov       x0, x25
  70003614f8  94934a56  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  70003614fc  14000009  b         #0x7000361520  // jump L_7000361520
L_7000361500:
  7000361500  f9400328  ldr       x8, [x25]
  7000361504  aa1903e0  mov       x0, x25
  7000361508  f9400908  ldr       x8, [x8, #0x10]
  700036150c  d63f0100  blr       x8  // call-register
  7000361510  aa1903e0  mov       x0, x25
  7000361514  94934a4f  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  7000361518  f94006d9  ldr       x25, [x22, #8]
  700036151c  b5fffd99  cbnz      x25, #0x70003614cc  // conditional L_70003614cc
L_7000361520:
  7000361520  aa1603e0  mov       x0, x22
  7000361524  94934a3f  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000361528:
  7000361528  90018aa8  adrp      x8, #0x70034b5000
  700036152c  f9464d16  ldr       x22, [x8, #0xc98]
  7000361530  b40002d6  cbz       x22, #0x7000361588  // conditional L_7000361588
  7000361534  910042c8  add       x8, x22, #0x10
  7000361538  d503201f  nop
  700036153c  d503201f  nop
L_7000361540:
  7000361540  c85ffd09  ldaxr     x9, [x8]
  7000361544  8b180133  add       x19, x9, x24
  7000361548  c809fd13  stlxr     w9, x19, [x8]
  700036154c  35ffffa9  cbnz      w9, #0x7000361540  // conditional L_7000361540
  7000361550  ea1a027f  tst       x19, x26
  7000361554  54000161  b.ne      #0x7000361580  // conditional L_7000361580
  7000361558  f94002c8  ldr       x8, [x22]
  700036155c  aa1603e0  mov       x0, x22
  7000361560  f9403508  ldr       x8, [x8, #0x68]
  7000361564  d63f0100  blr       x8  // call-register
  7000361568  ea17027f  tst       x19, x23
  700036156c  540000a1  b.ne      #0x7000361580  // conditional L_7000361580
  7000361570  f94002c8  ldr       x8, [x22]
  7000361574  aa1603e0  mov       x0, x22
  7000361578  f9400508  ldr       x8, [x8, #8]
  700036157c  d63f0100  blr       x8  // call-register
L_7000361580:
  7000361580  90018aa8  adrp      x8, #0x70034b5000
  7000361584  f9064d1f  str       xzr, [x8, #0xc98]
L_7000361588:
  7000361588  90018aa8  adrp      x8, #0x70034b5000
  700036158c  f9445d16  ldr       x22, [x8, #0x8b8]
  7000361590  b40002d6  cbz       x22, #0x70003615e8  // conditional L_70003615e8
  7000361594  910042c8  add       x8, x22, #0x10
  7000361598  d503201f  nop
  700036159c  d503201f  nop
L_70003615a0:
  70003615a0  c85ffd09  ldaxr     x9, [x8]
  70003615a4  8b180133  add       x19, x9, x24
  70003615a8  c809fd13  stlxr     w9, x19, [x8]
  70003615ac  35ffffa9  cbnz      w9, #0x70003615a0  // conditional L_70003615a0
  70003615b0  ea1a027f  tst       x19, x26
  70003615b4  54000161  b.ne      #0x70003615e0  // conditional L_70003615e0
  70003615b8  f94002c8  ldr       x8, [x22]
  70003615bc  aa1603e0  mov       x0, x22
  70003615c0  f9403508  ldr       x8, [x8, #0x68]
  70003615c4  d63f0100  blr       x8  // call-register
  70003615c8  ea17027f  tst       x19, x23
  70003615cc  540000a1  b.ne      #0x70003615e0  // conditional L_70003615e0
  70003615d0  f94002c8  ldr       x8, [x22]
  70003615d4  aa1603e0  mov       x0, x22
  70003615d8  f9400508  ldr       x8, [x8, #8]
  70003615dc  d63f0100  blr       x8  // call-register
L_70003615e0:
  70003615e0  90018aa8  adrp      x8, #0x70034b5000
  70003615e4  f9045d1f  str       xzr, [x8, #0x8b8]
L_70003615e8:
  70003615e8  b0018ac8  adrp      x8, #0x70034ba000
  70003615ec  f9450116  ldr       x22, [x8, #0xa00]
  70003615f0  b40002d6  cbz       x22, #0x7000361648  // conditional L_7000361648
  70003615f4  910042c8  add       x8, x22, #0x10
  70003615f8  d503201f  nop
  70003615fc  d503201f  nop
L_7000361600:
  7000361600  c85ffd09  ldaxr     x9, [x8]
  7000361604  8b180133  add       x19, x9, x24
  7000361608  c809fd13  stlxr     w9, x19, [x8]
  700036160c  35ffffa9  cbnz      w9, #0x7000361600  // conditional L_7000361600
  7000361610  ea1a027f  tst       x19, x26
  7000361614  54000161  b.ne      #0x7000361640  // conditional L_7000361640
  7000361618  f94002c8  ldr       x8, [x22]
  700036161c  aa1603e0  mov       x0, x22
  7000361620  f9403508  ldr       x8, [x8, #0x68]
  7000361624  d63f0100  blr       x8  // call-register
  7000361628  ea17027f  tst       x19, x23
  700036162c  540000a1  b.ne      #0x7000361640  // conditional L_7000361640
  7000361630  f94002c8  ldr       x8, [x22]
  7000361634  aa1603e0  mov       x0, x22
  7000361638  f9400508  ldr       x8, [x8, #8]
  700036163c  d63f0100  blr       x8  // call-register
L_7000361640:
  7000361640  b0018ac8  adrp      x8, #0x70034ba000
  7000361644  f905011f  str       xzr, [x8, #0xa00]
L_7000361648:
  7000361648  b0018ac8  adrp      x8, #0x70034ba000
  700036164c  f944fd16  ldr       x22, [x8, #0x9f8]
  7000361650  b40002d6  cbz       x22, #0x70003616a8  // conditional L_70003616a8
  7000361654  910042c8  add       x8, x22, #0x10
  7000361658  d503201f  nop
  700036165c  d503201f  nop
L_7000361660:
  7000361660  c85ffd09  ldaxr     x9, [x8]
  7000361664  8b180133  add       x19, x9, x24
  7000361668  c809fd13  stlxr     w9, x19, [x8]
  700036166c  35ffffa9  cbnz      w9, #0x7000361660  // conditional L_7000361660
  7000361670  ea1a027f  tst       x19, x26
  7000361674  54000161  b.ne      #0x70003616a0  // conditional L_70003616a0
  7000361678  f94002c8  ldr       x8, [x22]
  700036167c  aa1603e0  mov       x0, x22
  7000361680  f9403508  ldr       x8, [x8, #0x68]
  7000361684  d63f0100  blr       x8  // call-register
  7000361688  ea17027f  tst       x19, x23
  700036168c  540000a1  b.ne      #0x70003616a0  // conditional L_70003616a0
  7000361690  f94002c8  ldr       x8, [x22]
  7000361694  aa1603e0  mov       x0, x22
  7000361698  f9400508  ldr       x8, [x8, #8]
  700036169c  d63f0100  blr       x8  // call-register
L_70003616a0:
  70003616a0  b0018ac8  adrp      x8, #0x70034ba000
  70003616a4  f904fd1f  str       xzr, [x8, #0x9f8]
L_70003616a8:
  70003616a8  90018aa8  adrp      x8, #0x70034b5000
  70003616ac  f9445916  ldr       x22, [x8, #0x8b0]
  70003616b0  b4000296  cbz       x22, #0x7000361700  // conditional L_7000361700
  70003616b4  910042c8  add       x8, x22, #0x10
  70003616b8  d503201f  nop
  70003616bc  d503201f  nop
L_70003616c0:
  70003616c0  c85ffd09  ldaxr     x9, [x8]
  70003616c4  8b180133  add       x19, x9, x24
  70003616c8  c809fd13  stlxr     w9, x19, [x8]
  70003616cc  35ffffa9  cbnz      w9, #0x70003616c0  // conditional L_70003616c0
  70003616d0  ea1a027f  tst       x19, x26
  70003616d4  54000161  b.ne      #0x7000361700  // conditional L_7000361700
  70003616d8  f94002c8  ldr       x8, [x22]
  70003616dc  aa1603e0  mov       x0, x22
  70003616e0  f9403508  ldr       x8, [x8, #0x68]
  70003616e4  d63f0100  blr       x8  // call-register
  70003616e8  ea17027f  tst       x19, x23
  70003616ec  540000a1  b.ne      #0x7000361700  // conditional L_7000361700
  70003616f0  f94002c8  ldr       x8, [x22]
  70003616f4  aa1603e0  mov       x0, x22
  70003616f8  f9400508  ldr       x8, [x8, #8]
  70003616fc  d63f0100  blr       x8  // call-register
L_7000361700:
  7000361700  90018aa8  adrp      x8, #0x70034b5000
  7000361704  f904591f  str       xzr, [x8, #0x8b0]
  7000361708  d0018ac8  adrp      x8, #0x70034bb000
  700036170c  f944e116  ldr       x22, [x8, #0x9c0]
  7000361710  b4000296  cbz       x22, #0x7000361760  // conditional L_7000361760
  7000361714  910042c8  add       x8, x22, #0x10
  7000361718  d503201f  nop
  700036171c  d503201f  nop
L_7000361720:
  7000361720  c85ffd09  ldaxr     x9, [x8]
  7000361724  8b180133  add       x19, x9, x24
  7000361728  c809fd13  stlxr     w9, x19, [x8]
  700036172c  35ffffa9  cbnz      w9, #0x7000361720  // conditional L_7000361720
  7000361730  ea1a027f  tst       x19, x26
  7000361734  54000161  b.ne      #0x7000361760  // conditional L_7000361760
  7000361738  f94002c8  ldr       x8, [x22]
  700036173c  aa1603e0  mov       x0, x22
  7000361740  f9403508  ldr       x8, [x8, #0x68]
  7000361744  d63f0100  blr       x8  // call-register
  7000361748  ea17027f  tst       x19, x23
  700036174c  540000a1  b.ne      #0x7000361760  // conditional L_7000361760
  7000361750  f94002c8  ldr       x8, [x22]
  7000361754  aa1603e0  mov       x0, x22
  7000361758  f9400508  ldr       x8, [x8, #8]
  700036175c  d63f0100  blr       x8  // call-register
L_7000361760:
  7000361760  d0018ac8  adrp      x8, #0x70034bb000
  7000361764  f904e11f  str       xzr, [x8, #0x9c0]
  7000361768  90018aa8  adrp      x8, #0x70034b5000
  700036176c  f945f916  ldr       x22, [x8, #0xbf0]
  7000361770  b4000296  cbz       x22, #0x70003617c0  // conditional L_70003617c0
  7000361774  910042c8  add       x8, x22, #0x10
  7000361778  d503201f  nop
  700036177c  d503201f  nop
L_7000361780:
  7000361780  c85ffd09  ldaxr     x9, [x8]
  7000361784  8b180133  add       x19, x9, x24
  7000361788  c809fd13  stlxr     w9, x19, [x8]
  700036178c  35ffffa9  cbnz      w9, #0x7000361780  // conditional L_7000361780
  7000361790  ea1a027f  tst       x19, x26
  7000361794  54000161  b.ne      #0x70003617c0  // conditional L_70003617c0
  7000361798  f94002c8  ldr       x8, [x22]
  700036179c  aa1603e0  mov       x0, x22
  70003617a0  f9403508  ldr       x8, [x8, #0x68]
  70003617a4  d63f0100  blr       x8  // call-register
  70003617a8  ea17027f  tst       x19, x23
  70003617ac  540000a1  b.ne      #0x70003617c0  // conditional L_70003617c0
  70003617b0  f94002c8  ldr       x8, [x22]
  70003617b4  aa1603e0  mov       x0, x22
  70003617b8  f9400508  ldr       x8, [x8, #8]
  70003617bc  d63f0100  blr       x8  // call-register
L_70003617c0:
  70003617c0  90018aa8  adrp      x8, #0x70034b5000
  70003617c4  f905f91f  str       xzr, [x8, #0xbf0]
  70003617c8  b0018a48  adrp      x8, #0x70034aa000
  70003617cc  f9432900  ldr       x0, [x8, #0x650]
  70003617d0  f903291f  str       xzr, [x8, #0x650]
  70003617d4  b4000040  cbz       x0, #0x70003617dc  // conditional L_70003617dc
  70003617d8  94934992  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_70003617dc:
  70003617dc  f0018a08  adrp      x8, #0x70034a4000
  70003617e0  f944f116  ldr       x22, [x8, #0x9e0]
  70003617e4  b4000276  cbz       x22, #0x7000361830  // conditional L_7000361830
  70003617e8  910042c8  add       x8, x22, #0x10
  70003617ec  d503201f  nop
L_70003617f0:
  70003617f0  c85ffd09  ldaxr     x9, [x8]
  70003617f4  8b180133  add       x19, x9, x24
  70003617f8  c809fd13  stlxr     w9, x19, [x8]
  70003617fc  35ffffa9  cbnz      w9, #0x70003617f0  // conditional L_70003617f0
  7000361800  ea1a027f  tst       x19, x26
  7000361804  54000161  b.ne      #0x7000361830  // conditional L_7000361830
  7000361808  f94002c8  ldr       x8, [x22]
  700036180c  aa1603e0  mov       x0, x22
  7000361810  f9403508  ldr       x8, [x8, #0x68]
  7000361814  d63f0100  blr       x8  // call-register
  7000361818  ea17027f  tst       x19, x23
  700036181c  540000a1  b.ne      #0x7000361830  // conditional L_7000361830
  7000361820  f94002c8  ldr       x8, [x22]
  7000361824  aa1603e0  mov       x0, x22
  7000361828  f9400508  ldr       x8, [x8, #8]
  700036182c  d63f0100  blr       x8  // call-register
L_7000361830:
  7000361830  f0018a13  adrp      x19, #0x70034a4000
  7000361834  f0018a08  adrp      x8, #0x70034a4000
  7000361838  f944ee60  ldr       x0, [x19, #0x9d8]
  700036183c  f904f11f  str       xzr, [x8, #0x9e0]
  7000361840  f9400008  ldr       x8, [x0]
  7000361844  f9400d08  ldr       x8, [x8, #0x18]
  7000361848  d63f0100  blr       x8  // call-register
  700036184c  f944ee76  ldr       x22, [x19, #0x9d8]
  7000361850  aa1603f9  mov       x25, x22
  7000361854  f94006c8  ldr       x8, [x22, #8]
  7000361858  b9401908  ldr       w8, [x8, #0x18]
  700036185c  37f801c8  tbnz      w8, #0x1f, #0x7000361894  // conditional L_7000361894
  7000361860  90018ae8  adrp      x8, #0x70034bd000
  7000361864  9123a108  add       x8, x8, #0x8e8
  7000361868  08dffd08  ldarb     w8, [x8]
  700036186c  36009ba8  tbz       w8, #0, #0x7000362be0  // conditional L_7000362be0
L_7000361870:
  7000361870  f94006c8  ldr       x8, [x22, #8]
  7000361874  91006100  add       x0, x8, #0x18
  7000361878  9423694a  bl        #0x7000c3bda0  // call main+0xc3bda0
  700036187c  f94006c8  ldr       x8, [x22, #8]
  7000361880  12800009  mov       w9, #-1
  7000361884  b9001909  str       w9, [x8, #0x18]
  7000361888  f0018a08  adrp      x8, #0x70034a4000
  700036188c  f944ed19  ldr       x25, [x8, #0x9d8]
  7000361890  b4000299  cbz       x25, #0x70003618e0  // conditional L_70003618e0
L_7000361894:
  7000361894  91004328  add       x8, x25, #0x10
  7000361898  d503201f  nop
  700036189c  d503201f  nop
L_70003618a0:
  70003618a0  c85ffd09  ldaxr     x9, [x8]
  70003618a4  8b180133  add       x19, x9, x24
  70003618a8  c809fd13  stlxr     w9, x19, [x8]
  70003618ac  35ffffa9  cbnz      w9, #0x70003618a0  // conditional L_70003618a0
  70003618b0  ea1a027f  tst       x19, x26
  70003618b4  54000161  b.ne      #0x70003618e0  // conditional L_70003618e0
  70003618b8  f9400328  ldr       x8, [x25]
  70003618bc  aa1903e0  mov       x0, x25
  70003618c0  f9403508  ldr       x8, [x8, #0x68]
  70003618c4  d63f0100  blr       x8  // call-register
  70003618c8  ea17027f  tst       x19, x23
  70003618cc  540000a1  b.ne      #0x70003618e0  // conditional L_70003618e0
  70003618d0  f9400328  ldr       x8, [x25]
  70003618d4  aa1903e0  mov       x0, x25
  70003618d8  f9400508  ldr       x8, [x8, #8]
  70003618dc  d63f0100  blr       x8  // call-register
L_70003618e0:
  70003618e0  f0018a08  adrp      x8, #0x70034a4000
  70003618e4  b2689fed  mov       x13, #-0x1000000
  70003618e8  f904ed1f  str       xzr, [x8, #0x9d8]
  70003618ec  910042c8  add       x8, x22, #0x10
  70003618f0  52a0200e  mov       w14, #0x1000000
  70003618f4  c8dffd0a  ldar      x10, [x8]
  70003618f8  92681d49  and       x9, x10, #0xff000000
  70003618fc  8b0d014b  add       x11, x10, x13
  7000361900  9247f96c  and       x12, x11, #0xfeffffffffffffff
  7000361904  eb0e013f  cmp       x9, x14
  7000361908  9a8b0199  csel      x25, x12, x11, eq
  700036190c  d503201f  nop
L_7000361910:
  7000361910  c85ffd09  ldaxr     x9, [x8]
  7000361914  eb0a013f  cmp       x9, x10
  7000361918  540000c1  b.ne      #0x7000361930  // conditional L_7000361930
  700036191c  c80bfd19  stlxr     w11, x25, [x8]
  7000361920  35ffff8b  cbnz      w11, #0x7000361910  // conditional L_7000361910
  7000361924  5280002a  mov       w10, #1
  7000361928  3600014a  tbz       w10, #0, #0x7000361950  // conditional L_7000361950
  700036192c  14000016  b         #0x7000361984  // jump L_7000361984
L_7000361930:
  7000361930  2a1f03ea  mov       w10, wzr
  7000361934  d5033f5f  clrex
  7000361938  360000ca  tbz       w10, #0, #0x7000361950  // conditional L_7000361950
  700036193c  14000012  b         #0x7000361984  // jump L_7000361984
L_7000361940:
  7000361940  2a1f03eb  mov       w11, wzr
  7000361944  d5033f5f  clrex
  7000361948  aa0a03e9  mov       x9, x10
  700036194c  350001cb  cbnz      w11, #0x7000361984  // conditional L_7000361984
L_7000361950:
  7000361950  92681d2a  and       x10, x9, #0xff000000
  7000361954  8b0d012b  add       x11, x9, x13
  7000361958  9247f96c  and       x12, x11, #0xfeffffffffffffff
  700036195c  eb0e015f  cmp       x10, x14
  7000361960  9a8b0199  csel      x25, x12, x11, eq
L_7000361964:
  7000361964  c85ffd0a  ldaxr     x10, [x8]
  7000361968  eb09015f  cmp       x10, x9
  700036196c  54fffea1  b.ne      #0x7000361940  // conditional L_7000361940
  7000361970  c80bfd19  stlxr     w11, x25, [x8]
  7000361974  35ffff8b  cbnz      w11, #0x7000361964  // conditional L_7000361964
  7000361978  5280002b  mov       w11, #1
  700036197c  aa0a03e9  mov       x9, x10
  7000361980  34fffe8b  cbz       w11, #0x7000361950  // conditional L_7000361950
L_7000361984:
  7000361984  ea1a033f  tst       x25, x26
  7000361988  54000161  b.ne      #0x70003619b4  // conditional L_70003619b4
  700036198c  f94002c8  ldr       x8, [x22]
  7000361990  aa1603e0  mov       x0, x22
  7000361994  f9403508  ldr       x8, [x8, #0x68]
  7000361998  d63f0100  blr       x8  // call-register
  700036199c  ea17033f  tst       x25, x23
  70003619a0  540000a1  b.ne      #0x70003619b4  // conditional L_70003619b4
  70003619a4  f94002c8  ldr       x8, [x22]
  70003619a8  aa1603e0  mov       x0, x22
  70003619ac  f9400508  ldr       x8, [x8, #8]
  70003619b0  d63f0100  blr       x8  // call-register
L_70003619b4:
  70003619b4  f0018b28  adrp      x8, #0x70034c8000
  70003619b8  90018b19  adrp      x25, #0x70034c1000
  70003619bc  91021339  add       x25, x25, #0x84
  70003619c0  f947f116  ldr       x22, [x8, #0xfe0]
  70003619c4  b4000276  cbz       x22, #0x7000361a10  // conditional L_7000361a10
  70003619c8  910042c8  add       x8, x22, #0x10
  70003619cc  d503201f  nop
L_70003619d0:
  70003619d0  c85ffd09  ldaxr     x9, [x8]
  70003619d4  8b180133  add       x19, x9, x24
  70003619d8  c809fd13  stlxr     w9, x19, [x8]
  70003619dc  35ffffa9  cbnz      w9, #0x70003619d0  // conditional L_70003619d0
  70003619e0  ea1a027f  tst       x19, x26
  70003619e4  54000161  b.ne      #0x7000361a10  // conditional L_7000361a10
  70003619e8  f94002c8  ldr       x8, [x22]
  70003619ec  aa1603e0  mov       x0, x22
  70003619f0  f9403508  ldr       x8, [x8, #0x68]
  70003619f4  d63f0100  blr       x8  // call-register
  70003619f8  ea17027f  tst       x19, x23
  70003619fc  540000a1  b.ne      #0x7000361a10  // conditional L_7000361a10
  7000361a00  f94002c8  ldr       x8, [x22]
  7000361a04  aa1603e0  mov       x0, x22
  7000361a08  f9400508  ldr       x8, [x8, #8]
  7000361a0c  d63f0100  blr       x8  // call-register
L_7000361a10:
  7000361a10  f0018b28  adrp      x8, #0x70034c8000
  7000361a14  b0018b93  adrp      x19, #0x70034d2000
  7000361a18  f907f11f  str       xzr, [x8, #0xfe0]
  7000361a1c  90018ae8  adrp      x8, #0x70034bd000
  7000361a20  91236108  add       x8, x8, #0x8d8
  7000361a24  f9400516  ldr       x22, [x8, #8]
  7000361a28  a9007d1f  stp       xzr, xzr, [x8]
  7000361a2c  b40001b6  cbz       x22, #0x7000361a60  // conditional L_7000361a60
  7000361a30  910022c8  add       x8, x22, #8
L_7000361a34:
  7000361a34  c85ffd09  ldaxr     x9, [x8]
  7000361a38  d100052a  sub       x10, x9, #1
  7000361a3c  c80bfd0a  stlxr     w11, x10, [x8]
  7000361a40  35ffffab  cbnz      w11, #0x7000361a34  // conditional L_7000361a34
  7000361a44  b50000e9  cbnz      x9, #0x7000361a60  // conditional L_7000361a60
  7000361a48  f94002c8  ldr       x8, [x22]
  7000361a4c  aa1603e0  mov       x0, x22
  7000361a50  f9400908  ldr       x8, [x8, #0x10]
  7000361a54  d63f0100  blr       x8  // call-register
  7000361a58  aa1603e0  mov       x0, x22
  7000361a5c  949348fd  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361a60:
  7000361a60  90018ae8  adrp      x8, #0x70034bd000
  7000361a64  91232108  add       x8, x8, #0x8c8
  7000361a68  f9400516  ldr       x22, [x8, #8]
  7000361a6c  a9007d1f  stp       xzr, xzr, [x8]
  7000361a70  b40001f6  cbz       x22, #0x7000361aac  // conditional L_7000361aac
  7000361a74  910022c8  add       x8, x22, #8
  7000361a78  d503201f  nop
  7000361a7c  d503201f  nop
L_7000361a80:
  7000361a80  c85ffd09  ldaxr     x9, [x8]
  7000361a84  d100052a  sub       x10, x9, #1
  7000361a88  c80bfd0a  stlxr     w11, x10, [x8]
  7000361a8c  35ffffab  cbnz      w11, #0x7000361a80  // conditional L_7000361a80
  7000361a90  b50000e9  cbnz      x9, #0x7000361aac  // conditional L_7000361aac
  7000361a94  f94002c8  ldr       x8, [x22]
  7000361a98  aa1603e0  mov       x0, x22
  7000361a9c  f9400908  ldr       x8, [x8, #0x10]
  7000361aa0  d63f0100  blr       x8  // call-register
  7000361aa4  aa1603e0  mov       x0, x22
  7000361aa8  949348ea  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361aac:
  7000361aac  90018ae8  adrp      x8, #0x70034bd000
  7000361ab0  9122e108  add       x8, x8, #0x8b8
  7000361ab4  f9400516  ldr       x22, [x8, #8]
  7000361ab8  a9007d1f  stp       xzr, xzr, [x8]
  7000361abc  b40001b6  cbz       x22, #0x7000361af0  // conditional L_7000361af0
  7000361ac0  910022c8  add       x8, x22, #8
L_7000361ac4:
  7000361ac4  c85ffd09  ldaxr     x9, [x8]
  7000361ac8  d100052a  sub       x10, x9, #1
  7000361acc  c80bfd0a  stlxr     w11, x10, [x8]
  7000361ad0  35ffffab  cbnz      w11, #0x7000361ac4  // conditional L_7000361ac4
  7000361ad4  b50000e9  cbnz      x9, #0x7000361af0  // conditional L_7000361af0
  7000361ad8  f94002c8  ldr       x8, [x22]
  7000361adc  aa1603e0  mov       x0, x22
  7000361ae0  f9400908  ldr       x8, [x8, #0x10]
  7000361ae4  d63f0100  blr       x8  // call-register
  7000361ae8  aa1603e0  mov       x0, x22
  7000361aec  949348d9  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361af0:
  7000361af0  b0018a48  adrp      x8, #0x70034aa000
  7000361af4  f942b916  ldr       x22, [x8, #0x570]
  7000361af8  f902b91f  str       xzr, [x8, #0x570]
  7000361afc  b40000b6  cbz       x22, #0x7000361b10  // conditional L_7000361b10
  7000361b00  aa1603e0  mov       x0, x22
  7000361b04  9453fa27  bl        #0x70018603a0  // call main+0x18603a0
  7000361b08  aa1603e0  mov       x0, x22
  7000361b0c  949348c5  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000361b10:
  7000361b10  97ff8f68  bl        #0x70003458b0  // call main+0x3458b0
  7000361b14  90018a48  adrp      x8, #0x70034a9000
  7000361b18  91022108  add       x8, x8, #0x88
  7000361b1c  08dffd08  ldarb     w8, [x8]
  7000361b20  360079a8  tbz       w8, #0, #0x7000362a54  // conditional L_7000362a54
L_7000361b24:
  7000361b24  90018a48  adrp      x8, #0x70034a9000
  7000361b28  f9404116  ldr       x22, [x8, #0x80]
  7000361b2c  f900411f  str       xzr, [x8, #0x80]
  7000361b30  b40000b6  cbz       x22, #0x7000361b44  // conditional L_7000361b44
  7000361b34  aa1603e0  mov       x0, x22
  7000361b38  948e9796  bl        #0x7002707990  // call main+0x2707990
  7000361b3c  aa1603e0  mov       x0, x22
  7000361b40  949348b8  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000361b44:
  7000361b44  90018b88  adrp      x8, #0x70034d1000
  7000361b48  f943cd08  ldr       x8, [x8, #0x798]
  7000361b4c  b4000188  cbz       x8, #0x7000361b7c  // conditional L_7000361b7c
  7000361b50  f941da76  ldr       x22, [x19, #0x3b0]
  7000361b54  f0012f21  adrp      x1, #0x7002948000
  7000361b58  910b7021  add       x1, x1, #0x2dc
  7000361b5c  aa1603e0  mov       x0, x22
  7000361b60  948f7450  bl        #0x700273eca0  // call main+0x273eca0
  7000361b64  aa1603e0  mov       x0, x22
  7000361b68  f0012f21  adrp      x1, #0x7002948000
  7000361b6c  910b3021  add       x1, x1, #0x2cc
  7000361b70  948f744c  bl        #0x700273eca0  // call main+0x273eca0
  7000361b74  90018b88  adrp      x8, #0x70034d1000
  7000361b78  f903cd1f  str       xzr, [x8, #0x798]
L_7000361b7c:
  7000361b7c  90018ac8  adrp      x8, #0x70034b9000
  7000361b80  f9432916  ldr       x22, [x8, #0x650]
  7000361b84  b4000276  cbz       x22, #0x7000361bd0  // conditional L_7000361bd0
  7000361b88  910042c8  add       x8, x22, #0x10
  7000361b8c  d503201f  nop
L_7000361b90:
  7000361b90  c85ffd09  ldaxr     x9, [x8]
  7000361b94  8b180133  add       x19, x9, x24
  7000361b98  c809fd13  stlxr     w9, x19, [x8]
  7000361b9c  35ffffa9  cbnz      w9, #0x7000361b90  // conditional L_7000361b90
  7000361ba0  ea1a027f  tst       x19, x26
  7000361ba4  54000161  b.ne      #0x7000361bd0  // conditional L_7000361bd0
  7000361ba8  f94002c8  ldr       x8, [x22]
  7000361bac  aa1603e0  mov       x0, x22
  7000361bb0  f9403508  ldr       x8, [x8, #0x68]
  7000361bb4  d63f0100  blr       x8  // call-register
  7000361bb8  ea17027f  tst       x19, x23
  7000361bbc  540000a1  b.ne      #0x7000361bd0  // conditional L_7000361bd0
  7000361bc0  f94002c8  ldr       x8, [x22]
  7000361bc4  aa1603e0  mov       x0, x22
  7000361bc8  f9400508  ldr       x8, [x8, #8]
  7000361bcc  d63f0100  blr       x8  // call-register
L_7000361bd0:
  7000361bd0  90018ac8  adrp      x8, #0x70034b9000
  7000361bd4  f903291f  str       xzr, [x8, #0x650]
  7000361bd8  90018ae8  adrp      x8, #0x70034bd000
  7000361bdc  9110c108  add       x8, x8, #0x430
  7000361be0  08dffd08  ldarb     w8, [x8]
  7000361be4  36007568  tbz       w8, #0, #0x7000362a90  // conditional L_7000362a90
L_7000361be8:
  7000361be8  f0018ac0  adrp      x0, #0x70034bc000
  7000361bec  91344000  add       x0, x0, #0xd10
  7000361bf0  940ac2ac  bl        #0x70006126a0  // call main+0x6126a0
  7000361bf4  f0018b28  adrp      x8, #0x70034c8000
  7000361bf8  913d8108  add       x8, x8, #0xf60
  7000361bfc  08dffd08  ldarb     w8, [x8]
  7000361c00  360076c8  tbz       w8, #0, #0x7000362ad8  // conditional L_7000362ad8
L_7000361c04:
  7000361c04  90018b13  adrp      x19, #0x70034c1000
  7000361c08  b940ea61  ldr       w1, [x19, #0xe8]
  7000361c0c  7100043f  cmp       w1, #1
  7000361c10  5400054b  b.lt      #0x7000361cb8  // conditional L_7000361cb8
  7000361c14  f946eb96  ldr       x22, [x28, #0xdd0]
  7000361c18  b5000456  cbnz      x22, #0x7000361ca0  // conditional L_7000361ca0
  7000361c1c  52801a00  mov       w0, #0xd0
  7000361c20  949348a4  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000361c24  aa0003f6  mov       x22, x0
  7000361c28  a9007c1f  stp       xzr, xzr, [x0]
  7000361c2c  b00186a8  adrp      x8, #0x7003436000
  7000361c30  9134e108  add       x8, x8, #0xd38
  7000361c34  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  7000361c38  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  7000361c3c  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  7000361c40  91014000  add       x0, x0, #0x50
  7000361c44  a90422df  stp       xzr, x8, [x22, #0x40]
  7000361c48  949348ca  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000361c4c  f946eb80  ldr       x0, [x28, #0xdd0]
  7000361c50  790152df  strh      wzr, [x22, #0xa8]
  7000361c54  3902c2d5  strb      w21, [x22, #0xb0]
  7000361c58  f80b12df  stur      xzr, [x22, #0xb1]
  7000361c5c  f80b92df  stur      xzr, [x22, #0xb9]
  7000361c60  f80c12df  stur      xzr, [x22, #0xc1]
  7000361c64  f90066df  str       xzr, [x22, #0xc8]
  7000361c68  f906eb96  str       x22, [x28, #0xdd0]
  7000361c6c  a909fedf  stp       xzr, xzr, [x22, #0x98]
  7000361c70  b40000c0  cbz       x0, #0x7000361c88  // conditional L_7000361c88
  7000361c74  b0018b53  adrp      x19, #0x70034ca000
  7000361c78  91374273  add       x19, x19, #0xdd0
  7000361c7c  f9400668  ldr       x8, [x19, #8]
  7000361c80  d63f0100  blr       x8  // call-register
  7000361c84  f9400276  ldr       x22, [x19]
L_7000361c88:
  7000361c88  90018b13  adrp      x19, #0x70034c1000
  7000361c8c  b0011f68  adrp      x8, #0x700274e000
  7000361c90  9128c108  add       x8, x8, #0xa30
  7000361c94  b940ea61  ldr       w1, [x19, #0xe8]
  7000361c98  b0018b49  adrp      x9, #0x70034ca000
  7000361c9c  f906ed28  str       x8, [x9, #0xdd8]
L_7000361ca0:
  7000361ca0  f94006c0  ldr       x0, [x22, #8]
  7000361ca4  94903fdf  bl        #0x7002771c20  // call main+0x2771c20
  7000361ca8  12800008  mov       w8, #-1
  7000361cac  b900ea68  str       w8, [x19, #0xe8]
  7000361cb0  14000002  b         #0x7000361cb8  // jump L_7000361cb8
L_7000361cb4:
  7000361cb4  94934a1b  bl        #0x7002834520  // call main+0x2834520 plt:sched_yield
L_7000361cb8:
  7000361cb8  88dfff28  ldar      w8, [x25]
  7000361cbc  7100051f  cmp       w8, #1
  7000361cc0  54ffffa0  b.eq      #0x7000361cb4  // conditional L_7000361cb4
  7000361cc4  f946eb96  ldr       x22, [x28, #0xdd0]
  7000361cc8  b0018b99  adrp      x25, #0x70034d2000
  7000361ccc  912ec339  add       x25, x25, #0xbb0
  7000361cd0  b5000416  cbnz      x22, #0x7000361d50  // conditional L_7000361d50
  7000361cd4  52801a00  mov       w0, #0xd0
  7000361cd8  94934876  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000361cdc  aa0003f6  mov       x22, x0
  7000361ce0  a9007c1f  stp       xzr, xzr, [x0]
  7000361ce4  b00186a8  adrp      x8, #0x7003436000
  7000361ce8  9134e108  add       x8, x8, #0xd38
  7000361cec  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  7000361cf0  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  7000361cf4  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  7000361cf8  91014000  add       x0, x0, #0x50
  7000361cfc  a90422df  stp       xzr, x8, [x22, #0x40]
  7000361d00  9493489c  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000361d04  f946eb80  ldr       x0, [x28, #0xdd0]
  7000361d08  790152df  strh      wzr, [x22, #0xa8]
  7000361d0c  3902c2d5  strb      w21, [x22, #0xb0]
  7000361d10  f80b12df  stur      xzr, [x22, #0xb1]
  7000361d14  f80b92df  stur      xzr, [x22, #0xb9]
  7000361d18  f80c12df  stur      xzr, [x22, #0xc1]
  7000361d1c  f90066df  str       xzr, [x22, #0xc8]
  7000361d20  f906eb96  str       x22, [x28, #0xdd0]
  7000361d24  a909fedf  stp       xzr, xzr, [x22, #0x98]
  7000361d28  b40000c0  cbz       x0, #0x7000361d40  // conditional L_7000361d40
  7000361d2c  b0018b53  adrp      x19, #0x70034ca000
  7000361d30  91374273  add       x19, x19, #0xdd0
  7000361d34  f9400668  ldr       x8, [x19, #8]
  7000361d38  d63f0100  blr       x8  // call-register
  7000361d3c  f9400276  ldr       x22, [x19]
L_7000361d40:
  7000361d40  b0011f68  adrp      x8, #0x700274e000
  7000361d44  9128c108  add       x8, x8, #0xa30
  7000361d48  b0018b49  adrp      x9, #0x70034ca000
  7000361d4c  f906ed28  str       x8, [x9, #0xdd8]
L_7000361d50:
  7000361d50  f94006c8  ldr       x8, [x22, #8]
  7000361d54  f9400116  ldr       x22, [x8]
  7000361d58  08dfff28  ldarb     w8, [x25]
  7000361d5c  36006e28  tbz       w8, #0, #0x7000362b20  // conditional L_7000362b20
L_7000361d60:
  7000361d60  b0018b95  adrp      x21, #0x70034d2000
  7000361d64  912b82b5  add       x21, x21, #0xae0
  7000361d68  d0018ae0  adrp      x0, #0x70034bf000
  7000361d6c  9106c000  add       x0, x0, #0x1b0
  7000361d70  b0012681  adrp      x1, #0x7002832000
  7000361d74  9122d021  add       x1, x1, #0x8b4
  7000361d78  aa1503e2  mov       x2, x21
  7000361d7c  97f4b0b7  bl        #0x700008e058  // call main+0x8e058
  7000361d80  08dfff28  ldarb     w8, [x25]
  7000361d84  36006ee8  tbz       w8, #0, #0x7000362b60  // conditional L_7000362b60
L_7000361d88:
  7000361d88  d0018af3  adrp      x19, #0x70034bf000
  7000361d8c  91068273  add       x19, x19, #0x1a0
  7000361d90  aa1603e1  mov       x1, x22
  7000361d94  91004260  add       x0, x19, #0x10
  7000361d98  90012682  adrp      x2, #0x7002831000
  7000361d9c  91151042  add       x2, x2, #0x544
  7000361da0  aa1503e3  mov       x3, x21
  7000361da4  97f4af7f  bl        #0x700008dba0  // call main+0x8dba0
  7000361da8  f9400676  ldr       x22, [x19, #8]
  7000361dac  d0018af5  adrp      x21, #0x70034bf000
  7000361db0  9102e2b5  add       x21, x21, #0xb8
  7000361db4  a9007e7f  stp       xzr, xzr, [x19]
  7000361db8  b40001b6  cbz       x22, #0x7000361dec  // conditional L_7000361dec
  7000361dbc  910022c8  add       x8, x22, #8
L_7000361dc0:
  7000361dc0  c85ffd09  ldaxr     x9, [x8]
  7000361dc4  d100052a  sub       x10, x9, #1
  7000361dc8  c80bfd0a  stlxr     w11, x10, [x8]
  7000361dcc  35ffffab  cbnz      w11, #0x7000361dc0  // conditional L_7000361dc0
  7000361dd0  b50000e9  cbnz      x9, #0x7000361dec  // conditional L_7000361dec
  7000361dd4  f94002c8  ldr       x8, [x22]
  7000361dd8  aa1603e0  mov       x0, x22
  7000361ddc  f9400908  ldr       x8, [x8, #0x10]
  7000361de0  d63f0100  blr       x8  // call-register
  7000361de4  aa1603e0  mov       x0, x22
  7000361de8  9493481a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361dec:
  7000361dec  f94006b9  ldr       x25, [x21, #8]
  7000361df0  14000002  b         #0x7000361df8  // jump L_7000361df8
L_7000361df4:
  7000361df4  f9400739  ldr       x25, [x25, #8]
L_7000361df8:
  7000361df8  eb15033f  cmp       x25, x21
  7000361dfc  54000a40  b.eq      #0x7000361f44  // conditional L_7000361f44
  7000361e00  b9401321  ldr       w1, [x25, #0x10]
  7000361e04  910043e0  add       x0, sp, #0x10
  7000361e08  94489cfa  bl        #0x70015891f0  // call main+0x15891f0
  7000361e0c  a942dbe0  ldp       x0, x22, [sp, #0x28]
  7000361e10  b4000640  cbz       x0, #0x7000361ed8  // conditional L_7000361ed8
  7000361e14  b4000576  cbz       x22, #0x7000361ec0  // conditional L_7000361ec0
  7000361e18  910022d3  add       x19, x22, #8
  7000361e1c  d503201f  nop
L_7000361e20:
  7000361e20  c85f7e68  ldxr      x8, [x19]
  7000361e24  91000508  add       x8, x8, #1
  7000361e28  c8097e68  stxr      w9, x8, [x19]
  7000361e2c  35ffffa9  cbnz      w9, #0x7000361e20  // conditional L_7000361e20
  7000361e30  948c7484  bl        #0x700267f040  // call main+0x267f040
L_7000361e34:
  7000361e34  c85ffe68  ldaxr     x8, [x19]
  7000361e38  d1000509  sub       x9, x8, #1
  7000361e3c  c80afe69  stlxr     w10, x9, [x19]
  7000361e40  35ffffaa  cbnz      w10, #0x7000361e34  // conditional L_7000361e34
  7000361e44  b50000e8  cbnz      x8, #0x7000361e60  // conditional L_7000361e60
  7000361e48  f94002c8  ldr       x8, [x22]
  7000361e4c  aa1603e0  mov       x0, x22
  7000361e50  f9400908  ldr       x8, [x8, #0x10]
  7000361e54  d63f0100  blr       x8  // call-register
  7000361e58  aa1603e0  mov       x0, x22
  7000361e5c  949347fd  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000361e60:
  7000361e60  a942dbe8  ldp       x8, x22, [sp, #0x28]
  7000361e64  a9005be8  stp       x8, x22, [sp]
  7000361e68  b4000336  cbz       x22, #0x7000361ecc  // conditional L_7000361ecc
  7000361e6c  910022d3  add       x19, x22, #8
L_7000361e70:
  7000361e70  c85f7e68  ldxr      x8, [x19]
  7000361e74  91000508  add       x8, x8, #1
  7000361e78  c8097e68  stxr      w9, x8, [x19]
  7000361e7c  35ffffa9  cbnz      w9, #0x7000361e70  // conditional L_7000361e70
  7000361e80  910003e0  mov       x0, sp
  7000361e84  948c751b  bl        #0x700267f2f0  // call main+0x267f2f0
  7000361e88  d503201f  nop
  7000361e8c  d503201f  nop
L_7000361e90:
  7000361e90  c85ffe68  ldaxr     x8, [x19]
  7000361e94  d1000509  sub       x9, x8, #1
  7000361e98  c80afe69  stlxr     w10, x9, [x19]
  7000361e9c  35ffffaa  cbnz      w10, #0x7000361e90  // conditional L_7000361e90
  7000361ea0  b50001a8  cbnz      x8, #0x7000361ed4  // conditional L_7000361ed4
  7000361ea4  f94002c8  ldr       x8, [x22]
  7000361ea8  aa1603e0  mov       x0, x22
  7000361eac  f9400908  ldr       x8, [x8, #0x10]
  7000361eb0  d63f0100  blr       x8  // call-register
  7000361eb4  aa1603e0  mov       x0, x22
  7000361eb8  949347e6  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  7000361ebc  14000006  b         #0x7000361ed4  // jump L_7000361ed4
L_7000361ec0:
  7000361ec0  948c7460  bl        #0x700267f040  // call main+0x267f040
  7000361ec4  f94017e8  ldr       x8, [sp, #0x28]
  7000361ec8  a9005be8  stp       x8, x22, [sp]
L_7000361ecc:
  7000361ecc  910003e0  mov       x0, sp
  7000361ed0  948c7508  bl        #0x700267f2f0  // call main+0x267f2f0
L_7000361ed4:
  7000361ed4  f9401bf6  ldr       x22, [sp, #0x30]
L_7000361ed8:
  7000361ed8  b0018628  adrp      x8, #0x7003426000
  7000361edc  91076108  add       x8, x8, #0x1d8
  7000361ee0  f9000be8  str       x8, [sp, #0x10]
  7000361ee4  b4000116  cbz       x22, #0x7000361f04  // conditional L_7000361f04
  7000361ee8  910022c8  add       x8, x22, #8
  7000361eec  d503201f  nop
L_7000361ef0:
  7000361ef0  c85ffd09  ldaxr     x9, [x8]
  7000361ef4  d100052a  sub       x10, x9, #1
  7000361ef8  c80bfd0a  stlxr     w11, x10, [x8]
  7000361efc  35ffffab  cbnz      w11, #0x7000361ef0  // conditional L_7000361ef0
  7000361f00  b4000109  cbz       x9, #0x7000361f20  // conditional L_7000361f20
L_7000361f04:
  7000361f04  394083e8  ldrb      w8, [sp, #0x20]
  7000361f08  34fff768  cbz       w8, #0x7000361df4  // conditional L_7000361df4
L_7000361f0c:
  7000361f0c  f9400fe0  ldr       x0, [sp, #0x18]
  7000361f10  949348d4  bl        #0x7002834260  // call main+0x2834260 plt:_ZNSt3__115recursive_mutex6unlockEv
  7000361f14  17ffffb8  b         #0x7000361df4  // jump L_7000361df4
  7000361f18  d503201f  .word     0xd503201f  // outside recovered control flow
  7000361f1c  d503201f  .word     0xd503201f  // outside recovered control flow
L_7000361f20:
  7000361f20  f94002c8  ldr       x8, [x22]
  7000361f24  aa1603e0  mov       x0, x22
  7000361f28  f9400908  ldr       x8, [x8, #0x10]
  7000361f2c  d63f0100  blr       x8  // call-register
  7000361f30  aa1603e0  mov       x0, x22
  7000361f34  949347c7  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  7000361f38  394083e8  ldrb      w8, [sp, #0x20]
  7000361f3c  35fffe88  cbnz      w8, #0x7000361f0c  // conditional L_7000361f0c
  7000361f40  17ffffad  b         #0x7000361df4  // jump L_7000361df4
L_7000361f44:
  7000361f44  d0018ae8  adrp      x8, #0x70034bf000
  7000361f48  d0018af5  adrp      x21, #0x70034bf000
  7000361f4c  9101c2b5  add       x21, x21, #0x70
  7000361f50  f9404108  ldr       x8, [x8, #0x80]
  7000361f54  b4000168  cbz       x8, #0x7000361f80  // conditional L_7000361f80
  7000361f58  a9405aa8  ldp       x8, x22, [x21]
  7000361f5c  eb1502df  cmp       x22, x21
  7000361f60  f9400509  ldr       x9, [x8, #8]
  7000361f64  f94002ca  ldr       x10, [x22]
  7000361f68  f9000549  str       x9, [x10, #8]
  7000361f6c  f94002c9  ldr       x9, [x22]
  7000361f70  f9400508  ldr       x8, [x8, #8]
  7000361f74  f9000109  str       x9, [x8]
  7000361f78  f9000abf  str       xzr, [x21, #0x10]
  7000361f7c  54000d41  b.ne      #0x7000362124  // conditional L_7000362124
L_7000361f80:
  7000361f80  90018ae9  adrp      x9, #0x70034bd000
  7000361f84  9125c129  add       x9, x9, #0x970
  7000361f88  aa1c03f5  mov       x21, x28
  7000361f8c  a9402133  ldp       x19, x8, [x9]
  7000361f90  aa1a03fc  mov       x28, x26
  7000361f94  aa1703fa  mov       x26, x23
  7000361f98  eb13011f  cmp       x8, x19
  7000361f9c  54000180  b.eq      #0x7000361fcc  // conditional L_7000361fcc
  7000361fa0  d1008116  sub       x22, x8, #0x20
  7000361fa4  aa1603f7  mov       x23, x22
  7000361fa8  d503201f  nop
  7000361fac  d503201f  nop
L_7000361fb0:
  7000361fb0  f85e06e8  ldr       x8, [x23], #0xffffffffffffffe0
  7000361fb4  aa1603e0  mov       x0, x22
  7000361fb8  f9400508  ldr       x8, [x8, #8]
  7000361fbc  d63f0100  blr       x8  // call-register
  7000361fc0  eb1302df  cmp       x22, x19
  7000361fc4  aa1703f6  mov       x22, x23
  7000361fc8  54ffff41  b.ne      #0x7000361fb0  // conditional L_7000361fb0
L_7000361fcc:
  7000361fcc  90018ae8  adrp      x8, #0x70034bd000
  7000361fd0  9124c108  add       x8, x8, #0x930
  7000361fd4  f9400516  ldr       x22, [x8, #8]
  7000361fd8  f9002513  str       x19, [x8, #0x48]
  7000361fdc  a9007d1f  stp       xzr, xzr, [x8]
  7000361fe0  b40001f6  cbz       x22, #0x700036201c  // conditional L_700036201c
  7000361fe4  910022c8  add       x8, x22, #8
  7000361fe8  d503201f  nop
  7000361fec  d503201f  nop
L_7000361ff0:
  7000361ff0  c85ffd09  ldaxr     x9, [x8]
  7000361ff4  d100052a  sub       x10, x9, #1
  7000361ff8  c80bfd0a  stlxr     w11, x10, [x8]
  7000361ffc  35ffffab  cbnz      w11, #0x7000361ff0  // conditional L_7000361ff0
  7000362000  b50000e9  cbnz      x9, #0x700036201c  // conditional L_700036201c
  7000362004  f94002c8  ldr       x8, [x22]
  7000362008  aa1603e0  mov       x0, x22
  700036200c  f9400908  ldr       x8, [x8, #0x10]
  7000362010  d63f0100  blr       x8  // call-register
  7000362014  aa1603e0  mov       x0, x22
  7000362018  9493478e  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_700036201c:
  700036201c  f0018ac8  adrp      x8, #0x70034bd000
  7000362020  91250108  add       x8, x8, #0x940
  7000362024  f9400516  ldr       x22, [x8, #8]
  7000362028  a9007d1f  stp       xzr, xzr, [x8]
  700036202c  b40001b6  cbz       x22, #0x7000362060  // conditional L_7000362060
  7000362030  910022c8  add       x8, x22, #8
L_7000362034:
  7000362034  c85ffd09  ldaxr     x9, [x8]
  7000362038  d100052a  sub       x10, x9, #1
  700036203c  c80bfd0a  stlxr     w11, x10, [x8]
  7000362040  35ffffab  cbnz      w11, #0x7000362034  // conditional L_7000362034
  7000362044  b50000e9  cbnz      x9, #0x7000362060  // conditional L_7000362060
  7000362048  f94002c8  ldr       x8, [x22]
  700036204c  aa1603e0  mov       x0, x22
  7000362050  f9400908  ldr       x8, [x8, #0x10]
  7000362054  d63f0100  blr       x8  // call-register
  7000362058  aa1603e0  mov       x0, x22
  700036205c  9493477d  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000362060:
  7000362060  f0018ac8  adrp      x8, #0x70034bd000
  7000362064  91262108  add       x8, x8, #0x988
  7000362068  f9400516  ldr       x22, [x8, #8]
  700036206c  a9007d1f  stp       xzr, xzr, [x8]
  7000362070  b40001f6  cbz       x22, #0x70003620ac  // conditional L_70003620ac
  7000362074  910022c8  add       x8, x22, #8
  7000362078  d503201f  nop
  700036207c  d503201f  nop
L_7000362080:
  7000362080  c85ffd09  ldaxr     x9, [x8]
  7000362084  d100052a  sub       x10, x9, #1
  7000362088  c80bfd0a  stlxr     w11, x10, [x8]
  700036208c  35ffffab  cbnz      w11, #0x7000362080  // conditional L_7000362080
  7000362090  b50000e9  cbnz      x9, #0x70003620ac  // conditional L_70003620ac
  7000362094  f94002c8  ldr       x8, [x22]
  7000362098  aa1603e0  mov       x0, x22
  700036209c  f9400908  ldr       x8, [x8, #0x10]
  70003620a0  d63f0100  blr       x8  // call-register
  70003620a4  aa1603e0  mov       x0, x22
  70003620a8  9493476a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003620ac:
  70003620ac  f0018ad3  adrp      x19, #0x70034bd000
  70003620b0  91266273  add       x19, x19, #0x998
  70003620b4  14000006  b         #0x70003620cc  // jump L_70003620cc
  70003620b8  d503201f  .word     0xd503201f  // outside recovered control flow
  70003620bc  d503201f  .word     0xd503201f  // outside recovered control flow
L_70003620c0:
  70003620c0  91004273  add       x19, x19, #0x10
  70003620c4  eb14027f  cmp       x19, x20
  70003620c8  540004e0  b.eq      #0x7000362164  // conditional L_7000362164
L_70003620cc:
  70003620cc  f9400676  ldr       x22, [x19, #8]
  70003620d0  a9007e7f  stp       xzr, xzr, [x19]
  70003620d4  b4ffff76  cbz       x22, #0x70003620c0  // conditional L_70003620c0
  70003620d8  910022c8  add       x8, x22, #8
  70003620dc  d503201f  nop
L_70003620e0:
  70003620e0  c85ffd09  ldaxr     x9, [x8]
  70003620e4  d100052a  sub       x10, x9, #1
  70003620e8  c80bfd0a  stlxr     w11, x10, [x8]
  70003620ec  35ffffab  cbnz      w11, #0x70003620e0  // conditional L_70003620e0
  70003620f0  b5fffe89  cbnz      x9, #0x70003620c0  // conditional L_70003620c0
  70003620f4  f94002c8  ldr       x8, [x22]
  70003620f8  aa1603e0  mov       x0, x22
  70003620fc  f9400908  ldr       x8, [x8, #0x10]
  7000362100  d63f0100  blr       x8  // call-register
  7000362104  aa1603e0  mov       x0, x22
  7000362108  94934752  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  700036210c  17ffffed  b         #0x70003620c0  // jump L_70003620c0
L_7000362110:
  7000362110  aa1603e0  mov       x0, x22
  7000362114  94934743  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
  7000362118  eb15027f  cmp       x19, x21
  700036211c  aa1303f6  mov       x22, x19
  7000362120  54fff300  b.eq      #0x7000361f80  // conditional L_7000361f80
L_7000362124:
  7000362124  f94006d3  ldr       x19, [x22, #8]
  7000362128  f9400ed9  ldr       x25, [x22, #0x18]
  700036212c  b4ffff39  cbz       x25, #0x7000362110  // conditional L_7000362110
  7000362130  91002328  add       x8, x25, #8
L_7000362134:
  7000362134  c85ffd09  ldaxr     x9, [x8]
  7000362138  d100052a  sub       x10, x9, #1
  700036213c  c80bfd0a  stlxr     w11, x10, [x8]
  7000362140  35ffffab  cbnz      w11, #0x7000362134  // conditional L_7000362134
  7000362144  b5fffe69  cbnz      x9, #0x7000362110  // conditional L_7000362110
  7000362148  f9400328  ldr       x8, [x25]
  700036214c  aa1903e0  mov       x0, x25
  7000362150  f9400908  ldr       x8, [x8, #0x10]
  7000362154  d63f0100  blr       x8  // call-register
  7000362158  aa1903e0  mov       x0, x25
  700036215c  9493473d  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  7000362160  17ffffec  b         #0x7000362110  // jump L_7000362110
L_7000362164:
  7000362164  f0018ac8  adrp      x8, #0x70034bd000
  7000362168  91254108  add       x8, x8, #0x950
  700036216c  f9400516  ldr       x22, [x8, #8]
  7000362170  a9007d1f  stp       xzr, xzr, [x8]
  7000362174  b40001d6  cbz       x22, #0x70003621ac  // conditional L_70003621ac
  7000362178  910022c8  add       x8, x22, #8
  700036217c  d503201f  nop
L_7000362180:
  7000362180  c85ffd09  ldaxr     x9, [x8]
  7000362184  d100052a  sub       x10, x9, #1
  7000362188  c80bfd0a  stlxr     w11, x10, [x8]
  700036218c  35ffffab  cbnz      w11, #0x7000362180  // conditional L_7000362180
  7000362190  b50000e9  cbnz      x9, #0x70003621ac  // conditional L_70003621ac
  7000362194  f94002c8  ldr       x8, [x22]
  7000362198  aa1603e0  mov       x0, x22
  700036219c  f9400908  ldr       x8, [x8, #0x10]
  70003621a0  d63f0100  blr       x8  // call-register
  70003621a4  aa1603e0  mov       x0, x22
  70003621a8  9493472a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003621ac:
  70003621ac  f0018ac8  adrp      x8, #0x70034bd000
  70003621b0  91258108  add       x8, x8, #0x960
  70003621b4  f9400516  ldr       x22, [x8, #8]
  70003621b8  a9007d1f  stp       xzr, xzr, [x8]
  70003621bc  b40001b6  cbz       x22, #0x70003621f0  // conditional L_70003621f0
  70003621c0  910022c8  add       x8, x22, #8
L_70003621c4:
  70003621c4  c85ffd09  ldaxr     x9, [x8]
  70003621c8  d100052a  sub       x10, x9, #1
  70003621cc  c80bfd0a  stlxr     w11, x10, [x8]
  70003621d0  35ffffab  cbnz      w11, #0x70003621c4  // conditional L_70003621c4
  70003621d4  b50000e9  cbnz      x9, #0x70003621f0  // conditional L_70003621f0
  70003621d8  f94002c8  ldr       x8, [x22]
  70003621dc  aa1603e0  mov       x0, x22
  70003621e0  f9400908  ldr       x8, [x8, #0x10]
  70003621e4  d63f0100  blr       x8  // call-register
  70003621e8  aa1603e0  mov       x0, x22
  70003621ec  94934719  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003621f0:
  70003621f0  f0018ac8  adrp      x8, #0x70034bd000
  70003621f4  f945b519  ldr       x25, [x8, #0xb68]
  70003621f8  b4000339  cbz       x25, #0x700036225c  // conditional L_700036225c
  70003621fc  a9494f37  ldp       x23, x19, [x25, #0x90]
  7000362200  14000002  b         #0x7000362208  // jump L_7000362208
L_7000362204:
  7000362204  d1006273  sub       x19, x19, #0x18
L_7000362208:
  7000362208  eb17027f  cmp       x19, x23
  700036220c  54000220  b.eq      #0x7000362250  // conditional L_7000362250
  7000362210  f85f0276  ldur      x22, [x19, #-0x10]
  7000362214  b4ffff96  cbz       x22, #0x7000362204  // conditional L_7000362204
  7000362218  910022c8  add       x8, x22, #8
  700036221c  d503201f  nop
L_7000362220:
  7000362220  c85ffd09  ldaxr     x9, [x8]
  7000362224  d100052a  sub       x10, x9, #1
  7000362228  c80bfd0a  stlxr     w11, x10, [x8]
  700036222c  35ffffab  cbnz      w11, #0x7000362220  // conditional L_7000362220
  7000362230  b5fffea9  cbnz      x9, #0x7000362204  // conditional L_7000362204
  7000362234  f94002c8  ldr       x8, [x22]
  7000362238  aa1603e0  mov       x0, x22
  700036223c  f9400908  ldr       x8, [x8, #0x10]
  7000362240  d63f0100  blr       x8  // call-register
  7000362244  aa1603e0  mov       x0, x22
  7000362248  94934702  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  700036224c  17ffffee  b         #0x7000362204  // jump L_7000362204
L_7000362250:
  7000362250  f0018ac8  adrp      x8, #0x70034bd000
  7000362254  f9004f37  str       x23, [x25, #0x98]
  7000362258  f905b51f  str       xzr, [x8, #0xb68]
L_700036225c:
  700036225c  90018b93  adrp      x19, #0x70034d2000
  7000362260  912ec273  add       x19, x19, #0xbb0
  7000362264  08dffe68  ldarb     w8, [x19]
  7000362268  360049c8  tbz       w8, #0, #0x7000362ba0  // conditional L_7000362ba0
L_700036226c:
  700036226c  90018b80  adrp      x0, #0x70034d2000
  7000362270  9112c000  add       x0, x0, #0x4b0
  7000362274  94933bcb  bl        #0x70028311a0  // call main+0x28311a0
  7000362278  f0018ac8  adrp      x8, #0x70034bd000
  700036227c  aa1a03f7  mov       x23, x26
  7000362280  f9449100  ldr       x0, [x8, #0x920]
  7000362284  f0018ad9  adrp      x25, #0x70034bd000
  7000362288  9117c339  add       x25, x25, #0x5f0
  700036228c  f904911f  str       xzr, [x8, #0x920]
  7000362290  b4000040  cbz       x0, #0x7000362298  // conditional L_7000362298
  7000362294  9493475b  bl        #0x7002834000  // call main+0x2834000 plt:_ZdaPv
L_7000362298:
  7000362298  f0018ac8  adrp      x8, #0x70034bd000
  700036229c  aa1c03fa  mov       x26, x28
  70003622a0  f904951f  str       xzr, [x8, #0x928]
  70003622a4  d0018ac8  adrp      x8, #0x70034bc000
  70003622a8  f9420116  ldr       x22, [x8, #0x400]
  70003622ac  b5000276  cbnz      x22, #0x70003622f8  // conditional L_70003622f8
  70003622b0  52801400  mov       w0, #0xa0
  70003622b4  949346ff  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  70003622b8  d0018ac8  adrp      x8, #0x70034bc000
  70003622bc  aa0003f6  mov       x22, x0
  70003622c0  f804401f  stur      xzr, [x0, #0x44]
  70003622c4  52a7f009  mov       w9, #0x3f800000
  70003622c8  a9007c1f  stp       xzr, xzr, [x0]
  70003622cc  b9008009  str       w9, [x0, #0x80]
  70003622d0  f900441f  str       xzr, [x0, #0x88]
  70003622d4  f9020100  str       x0, [x8, #0x400]
  70003622d8  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  70003622dc  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  70003622e0  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  70003622e4  b803f01f  stur      wzr, [x0, #0x3f]
  70003622e8  a9057c1f  stp       xzr, xzr, [x0, #0x50]
  70003622ec  a9067c1f  stp       xzr, xzr, [x0, #0x60]
  70003622f0  a9077c1f  stp       xzr, xzr, [x0, #0x70]
  70003622f4  a9097c1f  stp       xzr, xzr, [x0, #0x90]
L_70003622f8:
  70003622f8  aa1603e0  mov       x0, x22
  70003622fc  f902011f  str       xzr, [x8, #0x400]
  7000362300  948cfdec  bl        #0x70026a1ab0  // call main+0x26a1ab0
  7000362304  aa1603e0  mov       x0, x22
  7000362308  949346c6  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
  700036230c  f0018aa8  adrp      x8, #0x70034b9000
  7000362310  aa1503fc  mov       x28, x21
  7000362314  f942c116  ldr       x22, [x8, #0x580]
  7000362318  52800035  mov       w21, #1
  700036231c  b4000256  cbz       x22, #0x7000362364  // conditional L_7000362364
  7000362320  910042c8  add       x8, x22, #0x10
L_7000362324:
  7000362324  c85ffd09  ldaxr     x9, [x8]
  7000362328  8b180133  add       x19, x9, x24
  700036232c  c809fd13  stlxr     w9, x19, [x8]
  7000362330  35ffffa9  cbnz      w9, #0x7000362324  // conditional L_7000362324
  7000362334  ea1a027f  tst       x19, x26
  7000362338  54000161  b.ne      #0x7000362364  // conditional L_7000362364
  700036233c  f94002c8  ldr       x8, [x22]
  7000362340  aa1603e0  mov       x0, x22
  7000362344  f9403508  ldr       x8, [x8, #0x68]
  7000362348  d63f0100  blr       x8  // call-register
  700036234c  ea17027f  tst       x19, x23
  7000362350  540000a1  b.ne      #0x7000362364  // conditional L_7000362364
  7000362354  f94002c8  ldr       x8, [x22]
  7000362358  aa1603e0  mov       x0, x22
  700036235c  f9400508  ldr       x8, [x8, #8]
  7000362360  d63f0100  blr       x8  // call-register
L_7000362364:
  7000362364  f0018aa8  adrp      x8, #0x70034b9000
  7000362368  f902c11f  str       xzr, [x8, #0x580]
  700036236c  d0018a08  adrp      x8, #0x70034a4000
  7000362370  9119a108  add       x8, x8, #0x668
  7000362374  f9400516  ldr       x22, [x8, #8]
  7000362378  a9007d1f  stp       xzr, xzr, [x8]
  700036237c  b40001b6  cbz       x22, #0x70003623b0  // conditional L_70003623b0
  7000362380  910022c8  add       x8, x22, #8
L_7000362384:
  7000362384  c85ffd09  ldaxr     x9, [x8]
  7000362388  d100052a  sub       x10, x9, #1
  700036238c  c80bfd0a  stlxr     w11, x10, [x8]
  7000362390  35ffffab  cbnz      w11, #0x7000362384  // conditional L_7000362384
  7000362394  b50000e9  cbnz      x9, #0x70003623b0  // conditional L_70003623b0
  7000362398  f94002c8  ldr       x8, [x22]
  700036239c  aa1603e0  mov       x0, x22
  70003623a0  f9400908  ldr       x8, [x8, #0x10]
  70003623a4  d63f0100  blr       x8  // call-register
  70003623a8  aa1603e0  mov       x0, x22
  70003623ac  949346a9  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003623b0:
  70003623b0  aa1f03f3  mov       x19, xzr
  70003623b4  14000006  b         #0x70003623cc  // jump L_70003623cc
  70003623b8  d503201f  .word     0xd503201f  // outside recovered control flow
  70003623bc  d503201f  .word     0xd503201f  // outside recovered control flow
L_70003623c0:
  70003623c0  91000673  add       x19, x19, #1
  70003623c4  f100767f  cmp       x19, #0x1d
  70003623c8  54000240  b.eq      #0x7000362410  // conditional L_7000362410
L_70003623cc:
  70003623cc  8b131368  add       x8, x27, x19, lsl #4
  70003623d0  f9400516  ldr       x22, [x8, #8]
  70003623d4  a9007d1f  stp       xzr, xzr, [x8]
  70003623d8  b4ffff56  cbz       x22, #0x70003623c0  // conditional L_70003623c0
  70003623dc  910022c8  add       x8, x22, #8
L_70003623e0:
  70003623e0  c85ffd09  ldaxr     x9, [x8]
  70003623e4  d100052a  sub       x10, x9, #1
  70003623e8  c80bfd0a  stlxr     w11, x10, [x8]
  70003623ec  35ffffab  cbnz      w11, #0x70003623e0  // conditional L_70003623e0
  70003623f0  b5fffe89  cbnz      x9, #0x70003623c0  // conditional L_70003623c0
  70003623f4  f94002c8  ldr       x8, [x22]
  70003623f8  aa1603e0  mov       x0, x22
  70003623fc  f9400908  ldr       x8, [x8, #0x10]
  7000362400  d63f0100  blr       x8  // call-register
  7000362404  aa1603e0  mov       x0, x22
  7000362408  94934692  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
  700036240c  17ffffed  b         #0x70003623c0  // jump L_70003623c0
L_7000362410:
  7000362410  90018b93  adrp      x19, #0x70034d2000
  7000362414  f9415e60  ldr       x0, [x19, #0x2b8]
  7000362418  97fff70e  bl        #0x7000360050  // call main+0x360050
  700036241c  f9415e76  ldr       x22, [x19, #0x2b8]
  7000362420  b4000116  cbz       x22, #0x7000362440  // conditional L_7000362440
  7000362424  aa1603e0  mov       x0, x22
  7000362428  f9015e7f  str       xzr, [x19, #0x2b8]
  700036242c  9492dc85  bl        #0x7002819640  // call main+0x2819640
  7000362430  90018b80  adrp      x0, #0x70034d2000
  7000362434  910b2000  add       x0, x0, #0x2c8
  7000362438  aa1603e1  mov       x1, x22
  700036243c  949346b9  bl        #0x7002833f20  // call main+0x2833f20 plt:_ZN2nn3mem17StandardAllocator4FreeEPv
L_7000362440:
  7000362440  90018b88  adrp      x8, #0x70034d2000
  7000362444  f9419516  ldr       x22, [x8, #0x328]
  7000362448  f901951f  str       xzr, [x8, #0x328]
  700036244c  b40000b6  cbz       x22, #0x7000362460  // conditional L_7000362460
  7000362450  aa1603e0  mov       x0, x22
  7000362454  97ff3bbf  bl        #0x7000331350  // call main+0x331350
  7000362458  aa1603e0  mov       x0, x22
  700036245c  94934671  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000362460:
  7000362460  90018b93  adrp      x19, #0x70034d2000
  7000362464  910b2273  add       x19, x19, #0x2c8
  7000362468  aa1303e0  mov       x0, x19
  700036246c  94934bd5  bl        #0x70028353c0  // call main+0x28353c0 plt:_ZN2nn3mem17StandardAllocator8FinalizeEv
  7000362470  f0018ac8  adrp      x8, #0x70034bd000
  7000362474  3901227f  strb      wzr, [x19, #0x48]
  7000362478  f9445100  ldr       x0, [x8, #0x8a0]
  700036247c  f904511f  str       xzr, [x8, #0x8a0]
  7000362480  b4000040  cbz       x0, #0x7000362488  // conditional L_7000362488
  7000362484  94934667  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_7000362488:
  7000362488  b0018aa8  adrp      x8, #0x70034b7000
  700036248c  f947c116  ldr       x22, [x8, #0xf80]
  7000362490  f907c11f  str       xzr, [x8, #0xf80]
  7000362494  b40000b6  cbz       x22, #0x70003624a8  // conditional L_70003624a8
  7000362498  f94006c0  ldr       x0, [x22, #8]
  700036249c  947fff6f  bl        #0x7002362258  // call main+0x2362258
  70003624a0  aa1603e0  mov       x0, x22
  70003624a4  9493465f  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
L_70003624a8:
  70003624a8  b0018b48  adrp      x8, #0x70034cb000
  70003624ac  f9402116  ldr       x22, [x8, #0x40]
  70003624b0  b4000296  cbz       x22, #0x7000362500  // conditional L_7000362500
  70003624b4  910042c8  add       x8, x22, #0x10
  70003624b8  d503201f  nop
  70003624bc  d503201f  nop
L_70003624c0:
  70003624c0  c85ffd09  ldaxr     x9, [x8]
  70003624c4  8b180133  add       x19, x9, x24
  70003624c8  c809fd13  stlxr     w9, x19, [x8]
  70003624cc  35ffffa9  cbnz      w9, #0x70003624c0  // conditional L_70003624c0
  70003624d0  ea1a027f  tst       x19, x26
  70003624d4  54000161  b.ne      #0x7000362500  // conditional L_7000362500
  70003624d8  f94002c8  ldr       x8, [x22]
  70003624dc  aa1603e0  mov       x0, x22
  70003624e0  f9403508  ldr       x8, [x8, #0x68]
  70003624e4  d63f0100  blr       x8  // call-register
  70003624e8  ea17027f  tst       x19, x23
  70003624ec  540000a1  b.ne      #0x7000362500  // conditional L_7000362500
  70003624f0  f94002c8  ldr       x8, [x22]
  70003624f4  aa1603e0  mov       x0, x22
  70003624f8  f9400508  ldr       x8, [x8, #8]
  70003624fc  d63f0100  blr       x8  // call-register
L_7000362500:
  7000362500  b0018b48  adrp      x8, #0x70034cb000
  7000362504  90018b53  adrp      x19, #0x70034ca000
  7000362508  f900211f  str       xzr, [x8, #0x40]
  700036250c  f9467a68  ldr       x8, [x19, #0xcf0]
  7000362510  f0018ad6  adrp      x22, #0x70034bd000
  7000362514  911e42d6  add       x22, x22, #0x790
  7000362518  b94006c1  ldr       w1, [x22, #4]
  700036251c  f9425900  ldr       x0, [x8, #0x4b0]
  7000362520  f9400008  ldr       x8, [x0]
  7000362524  f9401508  ldr       x8, [x8, #0x28]
  7000362528  d63f0100  blr       x8  // call-register
  700036252c  f9467a68  ldr       x8, [x19, #0xcf0]
  7000362530  b90006df  str       wzr, [x22, #4]
  7000362534  b94002c1  ldr       w1, [x22]
  7000362538  f9421900  ldr       x0, [x8, #0x430]
  700036253c  f9400008  ldr       x8, [x0]
  7000362540  f9401508  ldr       x8, [x8, #0x28]
  7000362544  d63f0100  blr       x8  // call-register
  7000362548  b90002df  str       wzr, [x22]
  700036254c  f946eb96  ldr       x22, [x28, #0xdd0]
  7000362550  b5000416  cbnz      x22, #0x70003625d0  // conditional L_70003625d0
  7000362554  52801a00  mov       w0, #0xd0
  7000362558  94934656  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  700036255c  aa0003f6  mov       x22, x0
  7000362560  a9007c1f  stp       xzr, xzr, [x0]
  7000362564  900186a8  adrp      x8, #0x7003436000
  7000362568  9134e108  add       x8, x8, #0xd38
  700036256c  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  7000362570  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  7000362574  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  7000362578  91014000  add       x0, x0, #0x50
  700036257c  a90422df  stp       xzr, x8, [x22, #0x40]
  7000362580  9493467c  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  7000362584  f946eb80  ldr       x0, [x28, #0xdd0]
  7000362588  790152df  strh      wzr, [x22, #0xa8]
  700036258c  3902c2d5  strb      w21, [x22, #0xb0]
  7000362590  f80b12df  stur      xzr, [x22, #0xb1]
  7000362594  f80b92df  stur      xzr, [x22, #0xb9]
  7000362598  f80c12df  stur      xzr, [x22, #0xc1]
  700036259c  f90066df  str       xzr, [x22, #0xc8]
  70003625a0  f906eb96  str       x22, [x28, #0xdd0]
  70003625a4  a909fedf  stp       xzr, xzr, [x22, #0x98]
  70003625a8  b40000c0  cbz       x0, #0x70003625c0  // conditional L_70003625c0
  70003625ac  90018b53  adrp      x19, #0x70034ca000
  70003625b0  91374273  add       x19, x19, #0xdd0
  70003625b4  f9400668  ldr       x8, [x19, #8]
  70003625b8  d63f0100  blr       x8  // call-register
  70003625bc  f9400276  ldr       x22, [x19]
L_70003625c0:
  70003625c0  90011f68  adrp      x8, #0x700274e000
  70003625c4  9128c108  add       x8, x8, #0xa30
  70003625c8  90018b49  adrp      x9, #0x70034ca000
  70003625cc  f906ed28  str       x8, [x9, #0xdd8]
L_70003625d0:
  70003625d0  f94006c8  ldr       x8, [x22, #8]
  70003625d4  5297a809  mov       w9, #0xbd40
  70003625d8  910043e0  add       x0, sp, #0x10
  70003625dc  f9001bff  str       xzr, [sp, #0x30]
  70003625e0  8b090101  add       x1, x8, x9
  70003625e4  97ffe40a  bl        #0x700035b60c  // call main+0x35b60c
  70003625e8  f9401be0  ldr       x0, [sp, #0x30]
  70003625ec  910043e8  add       x8, sp, #0x10
  70003625f0  eb08001f  cmp       x0, x8
  70003625f4  540000e0  b.eq      #0x7000362610  // conditional L_7000362610
  70003625f8  b4000160  cbz       x0, #0x7000362624  // conditional L_7000362624
  70003625fc  f9400008  ldr       x8, [x0]
  7000362600  9100a108  add       x8, x8, #0x28
  7000362604  14000006  b         #0x700036261c  // jump L_700036261c
  7000362608  d503201f  .word     0xd503201f  // outside recovered control flow
  700036260c  d503201f  .word     0xd503201f  // outside recovered control flow
L_7000362610:
  7000362610  f9400be8  ldr       x8, [sp, #0x10]
  7000362614  910043e0  add       x0, sp, #0x10
  7000362618  91008108  add       x8, x8, #0x20
L_700036261c:
  700036261c  f9400108  ldr       x8, [x8]
  7000362620  d63f0100  blr       x8  // call-register
L_7000362624:
  7000362624  f946eb96  ldr       x22, [x28, #0xdd0]
  7000362628  b5000416  cbnz      x22, #0x70003626a8  // conditional L_70003626a8
  700036262c  52801a00  mov       w0, #0xd0
  7000362630  94934620  bl        #0x7002833eb0  // call main+0x2833eb0 plt:_Znwm
  7000362634  aa0003f6  mov       x22, x0
  7000362638  a9007c1f  stp       xzr, xzr, [x0]
  700036263c  900186a8  adrp      x8, #0x7003436000
  7000362640  9134e108  add       x8, x8, #0xd38
  7000362644  a9017c1f  stp       xzr, xzr, [x0, #0x10]
  7000362648  a9027c1f  stp       xzr, xzr, [x0, #0x20]
  700036264c  a9037c1f  stp       xzr, xzr, [x0, #0x30]
  7000362650  91014000  add       x0, x0, #0x50
  7000362654  a90422df  stp       xzr, x8, [x22, #0x40]
  7000362658  94934646  bl        #0x7002833f70  // call main+0x2833f70 plt:_ZN2nn3mem17StandardAllocatorC1Ev
  700036265c  f946eb80  ldr       x0, [x28, #0xdd0]
  7000362660  790152df  strh      wzr, [x22, #0xa8]
  7000362664  3902c2d5  strb      w21, [x22, #0xb0]
  7000362668  f80b12df  stur      xzr, [x22, #0xb1]
  700036266c  f80b92df  stur      xzr, [x22, #0xb9]
  7000362670  f80c12df  stur      xzr, [x22, #0xc1]
  7000362674  f90066df  str       xzr, [x22, #0xc8]
  7000362678  f906eb96  str       x22, [x28, #0xdd0]
  700036267c  a909fedf  stp       xzr, xzr, [x22, #0x98]
  7000362680  b40000c0  cbz       x0, #0x7000362698  // conditional L_7000362698
  7000362684  90018b53  adrp      x19, #0x70034ca000
  7000362688  91374273  add       x19, x19, #0xdd0
  700036268c  f9400668  ldr       x8, [x19, #8]
  7000362690  d63f0100  blr       x8  // call-register
  7000362694  f9400276  ldr       x22, [x19]
L_7000362698:
  7000362698  90011f68  adrp      x8, #0x700274e000
  700036269c  9128c108  add       x8, x8, #0xa30
  70003626a0  90018b49  adrp      x9, #0x70034ca000
  70003626a4  f906ed28  str       x8, [x9, #0xdd8]
L_70003626a8:
  70003626a8  f0018ad3  adrp      x19, #0x70034bd000
  70003626ac  911cc273  add       x19, x19, #0x730
  70003626b0  f94006c0  ldr       x0, [x22, #8]
  70003626b4  b9406a61  ldr       w1, [x19, #0x68]
  70003626b8  94903d5a  bl        #0x7002771c20  // call main+0x2771c20
  70003626bc  f9400676  ldr       x22, [x19, #8]
  70003626c0  b9006a7f  str       wzr, [x19, #0x68]
  70003626c4  a9007e7f  stp       xzr, xzr, [x19]
  70003626c8  90018b93  adrp      x19, #0x70034d2000
  70003626cc  b40001b6  cbz       x22, #0x7000362700  // conditional L_7000362700
  70003626d0  910022c8  add       x8, x22, #8
L_70003626d4:
  70003626d4  c85ffd09  ldaxr     x9, [x8]
  70003626d8  d100052a  sub       x10, x9, #1
  70003626dc  c80bfd0a  stlxr     w11, x10, [x8]
  70003626e0  35ffffab  cbnz      w11, #0x70003626d4  // conditional L_70003626d4
  70003626e4  b50000e9  cbnz      x9, #0x7000362700  // conditional L_7000362700
  70003626e8  f94002c8  ldr       x8, [x22]
  70003626ec  aa1603e0  mov       x0, x22
  70003626f0  f9400908  ldr       x8, [x8, #0x10]
  70003626f4  d63f0100  blr       x8  // call-register
  70003626f8  aa1603e0  mov       x0, x22
  70003626fc  949345d5  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000362700:
  7000362700  f0018ac8  adrp      x8, #0x70034bd000
  7000362704  911d4108  add       x8, x8, #0x750
  7000362708  f9400516  ldr       x22, [x8, #8]
  700036270c  a9007d1f  stp       xzr, xzr, [x8]
  7000362710  b40001f6  cbz       x22, #0x700036274c  // conditional L_700036274c
  7000362714  910022c8  add       x8, x22, #8
  7000362718  d503201f  nop
  700036271c  d503201f  nop
L_7000362720:
  7000362720  c85ffd09  ldaxr     x9, [x8]
  7000362724  d100052a  sub       x10, x9, #1
  7000362728  c80bfd0a  stlxr     w11, x10, [x8]
  700036272c  35ffffab  cbnz      w11, #0x7000362720  // conditional L_7000362720
  7000362730  b50000e9  cbnz      x9, #0x700036274c  // conditional L_700036274c
  7000362734  f94002c8  ldr       x8, [x22]
  7000362738  aa1603e0  mov       x0, x22
  700036273c  f9400908  ldr       x8, [x8, #0x10]
  7000362740  d63f0100  blr       x8  // call-register
  7000362744  aa1603e0  mov       x0, x22
  7000362748  949345c2  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_700036274c:
  700036274c  f0018ac8  adrp      x8, #0x70034bd000
  7000362750  911e0108  add       x8, x8, #0x780
  7000362754  f9400516  ldr       x22, [x8, #8]
  7000362758  a9007d1f  stp       xzr, xzr, [x8]
  700036275c  b40001b6  cbz       x22, #0x7000362790  // conditional L_7000362790
  7000362760  910022c8  add       x8, x22, #8
L_7000362764:
  7000362764  c85ffd09  ldaxr     x9, [x8]
  7000362768  d100052a  sub       x10, x9, #1
  700036276c  c80bfd0a  stlxr     w11, x10, [x8]
  7000362770  35ffffab  cbnz      w11, #0x7000362764  // conditional L_7000362764
  7000362774  b50000e9  cbnz      x9, #0x7000362790  // conditional L_7000362790
  7000362778  f94002c8  ldr       x8, [x22]
  700036277c  aa1603e0  mov       x0, x22
  7000362780  f9400908  ldr       x8, [x8, #0x10]
  7000362784  d63f0100  blr       x8  // call-register
  7000362788  aa1603e0  mov       x0, x22
  700036278c  949345b1  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000362790:
  7000362790  f0018ac8  adrp      x8, #0x70034bd000
  7000362794  911dc108  add       x8, x8, #0x770
  7000362798  f9400516  ldr       x22, [x8, #8]
  700036279c  a9007d1f  stp       xzr, xzr, [x8]
  70003627a0  b40001f6  cbz       x22, #0x70003627dc  // conditional L_70003627dc
  70003627a4  910022c8  add       x8, x22, #8
  70003627a8  d503201f  nop
  70003627ac  d503201f  nop
L_70003627b0:
  70003627b0  c85ffd09  ldaxr     x9, [x8]
  70003627b4  d100052a  sub       x10, x9, #1
  70003627b8  c80bfd0a  stlxr     w11, x10, [x8]
  70003627bc  35ffffab  cbnz      w11, #0x70003627b0  // conditional L_70003627b0
  70003627c0  b50000e9  cbnz      x9, #0x70003627dc  // conditional L_70003627dc
  70003627c4  f94002c8  ldr       x8, [x22]
  70003627c8  aa1603e0  mov       x0, x22
  70003627cc  f9400908  ldr       x8, [x8, #0x10]
  70003627d0  d63f0100  blr       x8  // call-register
  70003627d4  aa1603e0  mov       x0, x22
  70003627d8  9493459e  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003627dc:
  70003627dc  f0018ac8  adrp      x8, #0x70034bd000
  70003627e0  911d8108  add       x8, x8, #0x760
  70003627e4  f9400516  ldr       x22, [x8, #8]
  70003627e8  a9007d1f  stp       xzr, xzr, [x8]
  70003627ec  b40001b6  cbz       x22, #0x7000362820  // conditional L_7000362820
  70003627f0  910022c8  add       x8, x22, #8
L_70003627f4:
  70003627f4  c85ffd09  ldaxr     x9, [x8]
  70003627f8  d100052a  sub       x10, x9, #1
  70003627fc  c80bfd0a  stlxr     w11, x10, [x8]
  7000362800  35ffffab  cbnz      w11, #0x70003627f4  // conditional L_70003627f4
  7000362804  b50000e9  cbnz      x9, #0x7000362820  // conditional L_7000362820
  7000362808  f94002c8  ldr       x8, [x22]
  700036280c  aa1603e0  mov       x0, x22
  7000362810  f9400908  ldr       x8, [x8, #0x10]
  7000362814  d63f0100  blr       x8  // call-register
  7000362818  aa1603e0  mov       x0, x22
  700036281c  9493458d  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_7000362820:
  7000362820  f0018ac8  adrp      x8, #0x70034bd000
  7000362824  911d0108  add       x8, x8, #0x740
  7000362828  f9400516  ldr       x22, [x8, #8]
  700036282c  a9007d1f  stp       xzr, xzr, [x8]
  7000362830  b40001f6  cbz       x22, #0x700036286c  // conditional L_700036286c
  7000362834  910022c8  add       x8, x22, #8
  7000362838  d503201f  nop
  700036283c  d503201f  nop
L_7000362840:
  7000362840  c85ffd09  ldaxr     x9, [x8]
  7000362844  d100052a  sub       x10, x9, #1
  7000362848  c80bfd0a  stlxr     w11, x10, [x8]
  700036284c  35ffffab  cbnz      w11, #0x7000362840  // conditional L_7000362840
  7000362850  b50000e9  cbnz      x9, #0x700036286c  // conditional L_700036286c
  7000362854  f94002c8  ldr       x8, [x22]
  7000362858  aa1603e0  mov       x0, x22
  700036285c  f9400908  ldr       x8, [x8, #0x10]
  7000362860  d63f0100  blr       x8  // call-register
  7000362864  aa1603e0  mov       x0, x22
  7000362868  9493457a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_700036286c:
  700036286c  f946eb80  ldr       x0, [x28, #0xdd0]
  7000362870  948fcff0  bl        #0x7002756830  // call main+0x2756830
  7000362874  f946eb80  ldr       x0, [x28, #0xdd0]
  7000362878  f906eb9f  str       xzr, [x28, #0xdd0]
  700036287c  b4000080  cbz       x0, #0x700036288c  // conditional L_700036288c
  7000362880  90018b48  adrp      x8, #0x70034ca000
  7000362884  f946ed08  ldr       x8, [x8, #0xdd8]
  7000362888  d63f0100  blr       x8  // call-register
L_700036288c:
  700036288c  f0018ac8  adrp      x8, #0x70034bd000
  7000362890  f9439501  ldr       x1, [x8, #0x728]
  7000362894  b4000081  cbz       x1, #0x70003628a4  // conditional L_70003628a4
  7000362898  d0018920  adrp      x0, #0x7003488000
  700036289c  91250000  add       x0, x0, #0x940
  70003628a0  949345a0  bl        #0x7002833f20  // call main+0x2833f20 plt:_ZN2nn3mem17StandardAllocator4FreeEPv
L_70003628a4:
  70003628a4  f0018ac8  adrp      x8, #0x70034bd000
  70003628a8  9122a108  add       x8, x8, #0x8a8
  70003628ac  f9400516  ldr       x22, [x8, #8]
  70003628b0  a9007d1f  stp       xzr, xzr, [x8]
  70003628b4  b40001d6  cbz       x22, #0x70003628ec  // conditional L_70003628ec
  70003628b8  910022c8  add       x8, x22, #8
  70003628bc  d503201f  nop
L_70003628c0:
  70003628c0  c85ffd09  ldaxr     x9, [x8]
  70003628c4  d100052a  sub       x10, x9, #1
  70003628c8  c80bfd0a  stlxr     w11, x10, [x8]
  70003628cc  35ffffab  cbnz      w11, #0x70003628c0  // conditional L_70003628c0
  70003628d0  b50000e9  cbnz      x9, #0x70003628ec  // conditional L_70003628ec
  70003628d4  f94002c8  ldr       x8, [x22]
  70003628d8  aa1603e0  mov       x0, x22
  70003628dc  f9400908  ldr       x8, [x8, #0x10]
  70003628e0  d63f0100  blr       x8  // call-register
  70003628e4  aa1603e0  mov       x0, x22
  70003628e8  9493455a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_70003628ec:
  70003628ec  90018b48  adrp      x8, #0x70034ca000
  70003628f0  f9463500  ldr       x0, [x8, #0xc68]
  70003628f4  f906351f  str       xzr, [x8, #0xc68]
  70003628f8  b4000080  cbz       x0, #0x7000362908  // conditional L_7000362908
  70003628fc  90018b48  adrp      x8, #0x70034ca000
  7000362900  f9463908  ldr       x8, [x8, #0xc70]
  7000362904  d63f0100  blr       x8  // call-register
L_7000362908:
  7000362908  f941da76  ldr       x22, [x19, #0x3b0]
  700036290c  b40000d6  cbz       x22, #0x7000362924  // conditional L_7000362924
  7000362910  aa1603e0  mov       x0, x22
  7000362914  948f4deb  bl        #0x70027360c0  // call main+0x27360c0
  7000362918  aa1603e0  mov       x0, x22
  700036291c  94934541  bl        #0x7002833e20  // call main+0x2833e20 plt:_ZdlPv
  7000362920  f901da7f  str       xzr, [x19, #0x3b0]
L_7000362924:
  7000362924  f0018ac8  adrp      x8, #0x70034bd000
  7000362928  9112e108  add       x8, x8, #0x4b8
  700036292c  f9400516  ldr       x22, [x8, #8]
  7000362930  a9007d1f  stp       xzr, xzr, [x8]
  7000362934  b40001d6  cbz       x22, #0x700036296c  // conditional L_700036296c
  7000362938  910022c8  add       x8, x22, #8
  700036293c  d503201f  nop
L_7000362940:
  7000362940  c85ffd09  ldaxr     x9, [x8]
  7000362944  d100052a  sub       x10, x9, #1
  7000362948  c80bfd0a  stlxr     w11, x10, [x8]
  700036294c  35ffffab  cbnz      w11, #0x7000362940  // conditional L_7000362940
  7000362950  b50000e9  cbnz      x9, #0x700036296c  // conditional L_700036296c
  7000362954  f94002c8  ldr       x8, [x22]
  7000362958  aa1603e0  mov       x0, x22
  700036295c  f9400908  ldr       x8, [x8, #0x10]
  7000362960  d63f0100  blr       x8  // call-register
  7000362964  aa1603e0  mov       x0, x22
  7000362968  9493453a  bl        #0x7002833e50  // call main+0x2833e50 plt:_ZNSt3__119__shared_weak_count14__release_weakEv
L_700036296c:
  700036296c  f0018ac8  adrp      x8, #0x70034bd000
  7000362970  f9426d00  ldr       x0, [x8, #0x4d8]
  7000362974  f9026d1f  str       xzr, [x8, #0x4d8]
  7000362978  b4000080  cbz       x0, #0x7000362988  // conditional L_7000362988
  700036297c  f9400008  ldr       x8, [x0]
  7000362980  f9400508  ldr       x8, [x8, #8]
  7000362984  d63f0100  blr       x8  // call-register
L_7000362988:
  7000362988  f0018ac8  adrp      x8, #0x70034bd000
  700036298c  f9426500  ldr       x0, [x8, #0x4c8]
  7000362990  f902651f  str       xzr, [x8, #0x4c8]
  7000362994  b4000080  cbz       x0, #0x70003629a4  // conditional L_70003629a4
  7000362998  f0018ac8  adrp      x8, #0x70034bd000
  700036299c  f9426908  ldr       x8, [x8, #0x4d0]
  70003629a0  d63f0100  blr       x8  // call-register
L_70003629a4:
  70003629a4  f0018ac8  adrp      x8, #0x70034bd000
  70003629a8  f9425916  ldr       x22, [x8, #0x4b0]
  70003629ac  f902591f  str       xzr, [x8, #0x4b0]
  70003629b0  b4ff32d6  cbz       x22, #0x7000361008  // conditional L_7000361008
  70003629b4  910022c0  add       x0, x22, #8
  70003629b8  949345ae  bl        #0x7002834070  // call main+0x2834070 plt:_ZN2nn2fs7UnmountEPKc
  70003629bc  f94002c0  ldr       x0, [x22]
  70003629c0  f90002df  str       xzr, [x22]
  70003629c4  b4ff31e0  cbz       x0, #0x7000361000  // conditional L_7000361000
  70003629c8  9493458e  bl        #0x7002834000  // call main+0x2834000 plt:_ZdaPv
  70003629cc  17fff98d  b         #0x7000361000  // jump L_7000361000
L_70003629d0:
  70003629d0  f0018ac0  adrp      x0, #0x70034bd000
  70003629d4  9123a000  add       x0, x0, #0x8e8
  70003629d8  94934516  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  70003629dc  34ff3240  cbz       w0, #0x7000361024  // conditional L_7000361024
  70003629e0  f0018ad3  adrp      x19, #0x70034bd000
  70003629e4  9112c273  add       x19, x19, #0x4b0
  70003629e8  aa1303e0  mov       x0, x19
  70003629ec  97ff5e01  bl        #0x700033a1f0  // call main+0x33a1f0
  70003629f0  d503201f  nop
  70003629f4  10e76be0  adr       x0, #0x7000331770
  70003629f8  aa1303e1  mov       x1, x19
  70003629fc  d0016882  adrp      x2, #0x7003074000
  7000362a00  9139c042  add       x2, x2, #0xe70
  7000362a04  97f275f3  bl        #0x70000001d0  // call main+0x1d0
  7000362a08  f0018ac0  adrp      x0, #0x70034bd000
  7000362a0c  9123a000  add       x0, x0, #0x8e8
  7000362a10  9493450c  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362a14  17fff984  b         #0x7000361024  // jump L_7000361024
L_7000362a18:
  7000362a18  f0018a80  adrp      x0, #0x70034b5000
  7000362a1c  91076000  add       x0, x0, #0x1d8
  7000362a20  94934504  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362a24  34ff4420  cbz       w0, #0x70003612a8  // conditional L_70003612a8
  7000362a28  d503201f  nop
  7000362a2c  10e745a0  adr       x0, #0x70003312e0
  7000362a30  f0018a81  adrp      x1, #0x70034b5000
  7000362a34  91074021  add       x1, x1, #0x1d0
  7000362a38  d0016882  adrp      x2, #0x7003074000
  7000362a3c  9139c042  add       x2, x2, #0xe70
  7000362a40  97f275e4  bl        #0x70000001d0  // call main+0x1d0
  7000362a44  f0018a80  adrp      x0, #0x70034b5000
  7000362a48  91076000  add       x0, x0, #0x1d8
  7000362a4c  949344fd  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362a50  17fffa16  b         #0x70003612a8  // jump L_70003612a8
L_7000362a54:
  7000362a54  f0018a20  adrp      x0, #0x70034a9000
  7000362a58  91022000  add       x0, x0, #0x88
  7000362a5c  949344f5  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362a60  34ff8620  cbz       w0, #0x7000361b24  // conditional L_7000361b24
  7000362a64  d503201f  nop
  7000362a68  10e744c0  adr       x0, #0x7000331300
  7000362a6c  f0018a21  adrp      x1, #0x70034a9000
  7000362a70  91020021  add       x1, x1, #0x80
  7000362a74  d0016882  adrp      x2, #0x7003074000
  7000362a78  9139c042  add       x2, x2, #0xe70
  7000362a7c  97f275d5  bl        #0x70000001d0  // call main+0x1d0
  7000362a80  f0018a20  adrp      x0, #0x70034a9000
  7000362a84  91022000  add       x0, x0, #0x88
  7000362a88  949344ee  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362a8c  17fffc26  b         #0x7000361b24  // jump L_7000361b24
L_7000362a90:
  7000362a90  f0018ac0  adrp      x0, #0x70034bd000
  7000362a94  9110c000  add       x0, x0, #0x430
  7000362a98  949344e6  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362a9c  34ff8a60  cbz       w0, #0x7000361be8  // conditional L_7000361be8
  7000362aa0  d0018ad3  adrp      x19, #0x70034bc000
  7000362aa4  91344273  add       x19, x19, #0xd10
  7000362aa8  aa1303e0  mov       x0, x19
  7000362aac  940abcba  bl        #0x7000611d94  // call main+0x611d94
  7000362ab0  90001580  adrp      x0, #0x7000612000
  7000362ab4  91028000  add       x0, x0, #0xa0
  7000362ab8  aa1303e1  mov       x1, x19
  7000362abc  d0016882  adrp      x2, #0x7003074000
  7000362ac0  9139c042  add       x2, x2, #0xe70
  7000362ac4  97f275c3  bl        #0x70000001d0  // call main+0x1d0
  7000362ac8  f0018ac0  adrp      x0, #0x70034bd000
  7000362acc  9110c000  add       x0, x0, #0x430
  7000362ad0  949344dc  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362ad4  17fffc45  b         #0x7000361be8  // jump L_7000361be8
L_7000362ad8:
  7000362ad8  d0018b20  adrp      x0, #0x70034c8000
  7000362adc  913d8000  add       x0, x0, #0xf60
  7000362ae0  949344d4  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362ae4  34ff8900  cbz       w0, #0x7000361c04  // conditional L_7000361c04
  7000362ae8  f0018ad3  adrp      x19, #0x70034bd000
  7000362aec  91248273  add       x19, x19, #0x920
  7000362af0  aa1303e0  mov       x0, x19
  7000362af4  948c5fdb  bl        #0x700267aa60  // call main+0x267aa60
  7000362af8  90011720  adrp      x0, #0x7002646000
  7000362afc  913f4000  add       x0, x0, #0xfd0
  7000362b00  aa1303e1  mov       x1, x19
  7000362b04  d0016882  adrp      x2, #0x7003074000
  7000362b08  9139c042  add       x2, x2, #0xe70
  7000362b0c  97f275b1  bl        #0x70000001d0  // call main+0x1d0
  7000362b10  d0018b20  adrp      x0, #0x70034c8000
  7000362b14  913d8000  add       x0, x0, #0xf60
  7000362b18  949344ca  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362b1c  17fffc3a  b         #0x7000361c04  // jump L_7000361c04
L_7000362b20:
  7000362b20  aa1903e0  mov       x0, x25
  7000362b24  949344c3  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362b28  34ff91c0  cbz       w0, #0x7000361d60  // conditional L_7000361d60
  7000362b2c  90018b93  adrp      x19, #0x70034d2000
  7000362b30  9112c273  add       x19, x19, #0x4b0
  7000362b34  aa1303e0  mov       x0, x19
  7000362b38  94933a89  bl        #0x700283155c  // call main+0x283155c
  7000362b3c  d0012660  adrp      x0, #0x7002830000
  7000362b40  913f4000  add       x0, x0, #0xfd0
  7000362b44  aa1303e1  mov       x1, x19
  7000362b48  d0016882  adrp      x2, #0x7003074000
  7000362b4c  9139c042  add       x2, x2, #0xe70
  7000362b50  97f275a0  bl        #0x70000001d0  // call main+0x1d0
  7000362b54  aa1903e0  mov       x0, x25
  7000362b58  949344ba  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362b5c  17fffc81  b         #0x7000361d60  // jump L_7000361d60
L_7000362b60:
  7000362b60  aa1903e0  mov       x0, x25
  7000362b64  949344b3  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362b68  34ff9100  cbz       w0, #0x7000361d88  // conditional L_7000361d88
  7000362b6c  90018b93  adrp      x19, #0x70034d2000
  7000362b70  9112c273  add       x19, x19, #0x4b0
  7000362b74  aa1303e0  mov       x0, x19
  7000362b78  94933a79  bl        #0x700283155c  // call main+0x283155c
  7000362b7c  d0012660  adrp      x0, #0x7002830000
  7000362b80  913f4000  add       x0, x0, #0xfd0
  7000362b84  aa1303e1  mov       x1, x19
  7000362b88  d0016882  adrp      x2, #0x7003074000
  7000362b8c  9139c042  add       x2, x2, #0xe70
  7000362b90  97f27590  bl        #0x70000001d0  // call main+0x1d0
  7000362b94  aa1903e0  mov       x0, x25
  7000362b98  949344aa  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362b9c  17fffc7b  b         #0x7000361d88  // jump L_7000361d88
L_7000362ba0:
  7000362ba0  aa1303e0  mov       x0, x19
  7000362ba4  949344a3  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362ba8  34ffb620  cbz       w0, #0x700036226c  // conditional L_700036226c
  7000362bac  90018b96  adrp      x22, #0x70034d2000
  7000362bb0  9112c2d6  add       x22, x22, #0x4b0
  7000362bb4  aa1603e0  mov       x0, x22
  7000362bb8  94933a69  bl        #0x700283155c  // call main+0x283155c
  7000362bbc  d0012660  adrp      x0, #0x7002830000
  7000362bc0  913f4000  add       x0, x0, #0xfd0
  7000362bc4  aa1603e1  mov       x1, x22
  7000362bc8  d0016882  adrp      x2, #0x7003074000
  7000362bcc  9139c042  add       x2, x2, #0xe70
  7000362bd0  97f27580  bl        #0x70000001d0  // call main+0x1d0
  7000362bd4  aa1303e0  mov       x0, x19
  7000362bd8  9493449a  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362bdc  17fffda4  b         #0x700036226c  // jump L_700036226c
L_7000362be0:
  7000362be0  f0018ac0  adrp      x0, #0x70034bd000
  7000362be4  9123a000  add       x0, x0, #0x8e8
  7000362be8  94934492  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362bec  34ff6420  cbz       w0, #0x7000361870  // conditional L_7000361870
  7000362bf0  f0018ad3  adrp      x19, #0x70034bd000
  7000362bf4  9112c273  add       x19, x19, #0x4b0
  7000362bf8  aa1303e0  mov       x0, x19
  7000362bfc  97ff5d7d  bl        #0x700033a1f0  // call main+0x33a1f0
  7000362c00  d503201f  nop
  7000362c04  10e75b60  adr       x0, #0x7000331770
  7000362c08  aa1303e1  mov       x1, x19
  7000362c0c  d0016882  adrp      x2, #0x7003074000
  7000362c10  9139c042  add       x2, x2, #0xe70
  7000362c14  97f2756f  bl        #0x70000001d0  // call main+0x1d0
  7000362c18  f0018ac0  adrp      x0, #0x70034bd000
  7000362c1c  9123a000  add       x0, x0, #0x8e8
  7000362c20  94934488  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362c24  17fffb13  b         #0x7000361870  // jump L_7000361870
L_7000362c28:
  7000362c28  f0018ac0  adrp      x0, #0x70034bd000
  7000362c2c  9123a000  add       x0, x0, #0x8e8
  7000362c30  94934480  bl        #0x7002833e30  // call main+0x2833e30 plt:__cxa_guard_acquire
  7000362c34  34ff38e0  cbz       w0, #0x7000361350  // conditional L_7000361350
  7000362c38  f0018ad3  adrp      x19, #0x70034bd000
  7000362c3c  9112c273  add       x19, x19, #0x4b0
  7000362c40  aa1303e0  mov       x0, x19
  7000362c44  97ff5d6b  bl        #0x700033a1f0  // call main+0x33a1f0
  7000362c48  d503201f  nop
  7000362c4c  10e75920  adr       x0, #0x7000331770
  7000362c50  aa1303e1  mov       x1, x19
  7000362c54  d0016882  adrp      x2, #0x7003074000
  7000362c58  9139c042  add       x2, x2, #0xe70
  7000362c5c  97f2755d  bl        #0x70000001d0  // call main+0x1d0
  7000362c60  f0018ac0  adrp      x0, #0x70034bd000
  7000362c64  9123a000  add       x0, x0, #0x8e8
  7000362c68  94934476  bl        #0x7002833e40  // call main+0x2833e40 plt:__cxa_guard_release
  7000362c6c  17fff9b9  b         #0x7000361350  // jump L_7000361350
L_7000362c70:
  7000362c70  910043e0  add       x0, sp, #0x10
  7000362c74  949344f3  bl        #0x7002834040  // call main+0x2834040 plt:_ZN2nn4diag6detail9AbortImplEPKNS_6ResultE, fallthrough main+0x362c78
