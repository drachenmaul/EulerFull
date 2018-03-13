#include <time.h>
#include <stdio.h>
#include <iostream>
#include "eulersolutions.h"

using namespace std;



//Next Problems:  47, 49, 50, 58, 63, 81


int main(){
	double start,stopp;
	start=clock();
	euler92();
	stopp=clock();
	cout << (stopp-start)/CLOCKS_PER_SEC << "s" << endl;

	//printf("\n%lf s\n",(stopp-start)/CLOCKS_PER_SEC);
	return 0;
}
