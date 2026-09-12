




#include "types.h"
#include "user.h"
#include "date.h"


// this is the user space program 
// TODO: acc write the syscall
int main(int argc, char *argv[]) {
	// struct rtcdate r = {0,0,0,0,0,0};

	struct rtcdate r;

	if (date(&r)) {
		printf(2, "date failed\n");
		exit();

	}
	// code to print date-time

	printf(1, "abi - shuold do date here\n");
	// the syscall shouldve populated the r struct if successul
	
	// hour: min: s  month date, year 
	printf(1, "%d:", r.hour);

	if (r.minute < 10) printf(1, "0%d:", r.minute);
	else printf(1, "%d:", r.minute);
	
	if (r.second < 10) printf(1, "0%d", r.second);
	else printf(1, "%d", r.second);
	
	printf(1, "   ");
	char months[12][30] = {
"January",
"February",
"March",
"April",
"May",
"June",
"July",
"August",
"September",
"October",
"November",
"December"
};
	printf(1, "%s ", months[r.month-1]);
	printf(1, "%d, %d \n", r.day, r.year);



	exit();
}
