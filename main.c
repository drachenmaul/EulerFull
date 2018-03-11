#include <time.h>
#include <stdio.h>
#include "eulersolutions.h"




int main(){
	double start,stopp;
	start=clock();
	euler39();
	stopp=clock();
	printf("\n%lf s\n",(stopp-start)/CLOCKS_PER_SEC);
	return 0;
}
