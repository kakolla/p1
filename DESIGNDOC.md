
Changes:


Makefile
edited the makefile to include some ignore flags to get the kernel to compile (not using a VM, just the toolchain on a linux machine so it was complaining)

Also added test_project1.c for part 1


proc.c & proc.h
Added the metadata to track the number of syscalls and tracing enabled


syscall.c
Added the sectin to enable tracing and actaully print it out. along with the new system calls to the list and the identifying number.


sysproc.c
Syscall implementation for date() and trace(). One vital note for date() is that we need to pass in the struct rtcdate* pointer but also cast it to (void*) for argptr to properly work. If it succeeds it returns 0 and allows us to populate the struct.

date.c
Userspace program that calls date() by passing in a struct and making use of the cmostime() helper function within.

user.h
function prototype for trace and date.

usys.S
added the macro for trace and date that will be replaced.





