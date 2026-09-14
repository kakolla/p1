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
