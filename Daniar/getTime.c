#include <stdlib.h>
#include <stdio.h>
#include "main.h"
#include <time.h>

void getTime(int *day,int *month, int *year){
	time_t now;
	time(&now);
	
	struct tm *local = localtime(&now);
	*day= local->tm_mday;            // get day of month (1 to 31)
	*month = local->tm_mon + 1;      // get month of year (0 to 11)
	*year = local->tm_year + 1900;   // get year since 1900
}
