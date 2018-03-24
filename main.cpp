#include <time.h>
#include <stdio.h>
#include <iostream>
#include "eulersolutions.h"

using namespace std;



//Next Problems:  47, 49, 63, 81, 95, 113, 122, 407, 437


int main(){
	double start,stopp;
	start=clock();
	euler58();
	stopp=clock();
	cout << (stopp-start)/CLOCKS_PER_SEC << "s" << endl;
	return 0;
}


/*
 *
prob 63
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?
 *
 * */


/* Prob 437
 * When we calculate 8n modulo 11 for n=0 to 9 we get: 1, 8, 9, 6, 4, 10, 3, 2, 5, 7.
As we see all possible values from 1 to 10 occur. So 8 is a primitive root of 11.
But there is more:
If we take a closer look we see:
1+8=9
8+9=17≡6 mod 11
9+6=15≡4 mod 11
6+4=10
4+10=14≡3 mod 11
10+3=13≡2 mod 11
3+2=5
2+5=7
5+7=12≡1 mod 11.
So the powers of 8 mod 11 are cyclic with period 10, and 8n + 8n+1 ≡ 8n+2 (mod 11).
8 is called a Fibonacci primitive root of 11.
Not every prime has a Fibonacci primitive root.
There are 323 primes less than 10000 with one or more Fibonacci primitive roots and the sum of these primes is 1480491.
Find the sum of the primes less than 100,000,000 with at least one Fibonacci primitive root.
 *
 *
 */
