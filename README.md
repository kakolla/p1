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
  
  If xv6 does not compile or boot correctly on macOS with the CSCI 350 Docker setup, make the following two changes.
  
  1. Makefile
  
  In xv6-public-master/Makefile, find the CFLAGS line and remove:
  
  -fcf-protection=none
  
  For example, change:
  
  ... -Wno-infinite-recursion -fcf-protection=none -march=i686 ...
  
  to:
  
  ... -Wno-infinite-recursion -march=i686 ...
  
  This is needed if the GCC version in the CSCI 350 Docker environment does not recognize the -fcf-protection=none option.
  
  
  2. kernel.ld
  
  In xv6-public-master/kernel.ld, find:
  
  .stab : {
  
  and change it to:
  
  .stab : AT(LOADADDR(.rodata) + SIZEOF(.rodata)) {
  
  This fixes a boot issue on newer macOS/QEMU setups where xv6 may hang at:
  
  Booting from Hard Disk...
