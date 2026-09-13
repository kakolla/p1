## Part 1: Trace System Call (peeru)

peeru>
I implemented a new trace(int) system call that enables or disables system call tracing for the calling process. Each process also keeps track of the total number of system calls it has made since it was created.

When tracing is enabled, each system call prints the process ID,
process name, system call number, and system call name. Calling
trace(0) disables printing but does not stop the system call counter.

### Modified Files
user.h
- Added the user-level prototype for trace(int).

syscall.h
- Added SYS_trace as system call number 22.

usys.S
- Added the user-level system call stub for trace.

syscall.c
- Added sys_trace to the system call dispatch table.
- Added a lookup table that maps system call numbers to their
  human-readable names.
- Incremented the calling process's system call counter whenever a
  valid system call is made.
- Added conditional trace output when tracing is enabled for the
  calling process.

sysproc.c
- Implemented the kernel-side sys_trace(void) handler.
- Used argint() to retrieve the integer argument passed to trace.
- A nonzero argument enables tracing and 0 disables tracing.
- The system call returns the calling process's current total number
  of system calls.

proc.h
- Added per-process fields for whether tracing is enabled and for the
  total number of system calls made by the process.

proc.c
- Initialized the new tracing fields when a process is created.
- New processes begin with tracing disabled and a system call count
  of zero.

Makefile
- Added test_project1 to UPROGS so that it is included in the xv6
  file system.
- Added test_project1.c to EXTRA.

Design Notes
------------
The tracing state and system call counter are stored in struct proc
rather than globally so that tracing applies only to the process that
called trace(1).

The system call counter is incremented before the selected system call
is executed. This ensures that trace() itself is included in the value
returned by trace(0).

Trace output is produced after the system call executes. Therefore,
trace(1) enables tracing before its trace status is checked, while
trace(0) disables tracing before the output check.

Testing
-------
I tested the implementation using the provided test_project1 program.
The trace output included the required process ID, process name, system
call number, and system call name.

The program reported:

total syscalls so far: 10
total syscalls so far: 40

which matched the expected values in the provided test program.


## Part 2 - date() system call (kakolla)
Changes:

Makefile
edited the makefile to include some ignore flags to get the kernel to compile (not using a VM, just the toolchain on a linux machine so it was complaining)

Also added date.c for part 2 so that this can be called as a userspace program which has the date() system call underneath.


proc.c & proc.h
Added the date system call here, just following the same pattern as the other syscalls.


syscall.c
Added the new system call to the list and the identifying number (just incremented one).


sysproc.c
Syscall implementation for date() . One vital note for date() is that we need to pass in the struct rtcdate* pointer but also cast it to (void*) for argptr to properly work. If it succeeds it returns 0 and allows us to populate the struct. I did a grep search to find out what other calls use argptr and found that the file syscall for write does. In that file (sysfile), I saw the correct usage of the argptr function, and i just replicated that for the date syscall.

date.c
Userspace program that calls date() by passing in a struct and making use of the cmostime() helper function within. The cmostime function is part of a kernelspace program so it must be called within the date syscall (not within this userspace file).

user.h
function prototype for  date.

usys.S
added the macro for  date that will be replaced. 

## Design:
- followed the same pattern as uptime(), but since we need to pass in a struct to populate the time, I also followed how sys_write() worked since it uses argptr(). 


## Testing:
- Just ran date in xv6. Initially my struct wasn't gettting populated but then I noticed I was passing in the struct itself not the struct ptr. 





