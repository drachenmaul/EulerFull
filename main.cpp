#include <time.h>
#include <iostream>
#include "eulersolutions.h"

using namespace std;



//Next Problems:  49, 63, 81, 95, 113, 122, 407, 437


int main(){
	double start,stopp;
	start=clock();
	euler41();
	stopp=clock();
	cout << (stopp-start)/CLOCKS_PER_SEC << "s" << endl;
	return 0;
}
