# CS350P1

usc email 1: peeru@usc.edu
  
usc email 2: kakolla@usc.edu
  
How to compile:

$ make

then

$ make qemu-nox
  
How to run:

$ make qemu-nox

Notes:
- xv6-public-master/usys.S is pretty interesting as it uses a macro to inject the actual syscall number into the eax register and doesn't repeat
code for every type. The 'int' assembly instruction signals the processor to jump to kernel mode and actually run the syscall routine handler.
- Mac / Apple Silicon Compatibility:

    On newer macOS / QEMU setups, xv6 may hang at:
    
    Booting from Hard Disk...
    
    To fix this, edit:
    
    xv6-public-master/kernel.ld
    
    Change:
    
    .stab : {
    
    to:
    
    .stab : AT(LOADADDR(.rodata) + SIZEOF(.rodata)) {
    
    This is only a compatibility fix for running xv6 on my Mac/QEMU setup and does not change the Project 1 functionality.
