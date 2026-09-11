




#include "types.h"
#include "user.h"
#include "date.h"


// this is the user space program 
// TODO: acc write the syscall
int main(int argc, char *argv[]) {
	struct rtcdate r;

	if (date(&r)) {
		printf(2, "date failed\n");
		exit();

	}
	// code to print date-time

	printf(1, "abi - shuold do date here\n");


	exit();
}
