




#include "types.h"
#include "user.h"
#include "date.h"


// this is the user space program 
// TODO: acc write the syscall
int main(int argc, char *argv[]) {
	struct rtcdate r = {0,0,0,0,0,0};

	if (date(&r)) {
		printf(2, "date failed\n");
		exit();

	}
	// code to print date-time

	printf(1, "abi - shuold do date here\n");
	// the syscall shouldve populated the r struct if successul
	
	// hour: min: s  month date, year 
	printf(1, "%d:%d:%d   %d %d, %d \n", r.hour, r.minute, r.second, r.month, r.day, r.year);



	exit();
}
