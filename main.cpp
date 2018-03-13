#include <time.h>
#include <stdio.h>
#include <iostream>
#include "eulersolutions.h"

using namespace std;


int main(){
	double start,stopp;
	start=clock();
	euler92();
	stopp=clock();
	cout << (stopp-start)/CLOCKS_PER_SEC << "s" << endl;

	//printf("\n%lf s\n",(stopp-start)/CLOCKS_PER_SEC);
	return 0;
}
