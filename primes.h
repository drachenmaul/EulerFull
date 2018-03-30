#ifndef PRIMES_H
#define PRIMES_H


#include<vector>

bool TRUNCATABLE(int prim);
unsigned GETPRIME(int NUMBER);
unsigned GETNEXTPRIME(int NUMBER);
unsigned GETPREVPRIME(int NUMBER);
int PRIMEFACTOR(unsigned long long NUMBER);//returns number of prime factors
int DISTINCTPRIMEFACTOR( long long NUMBER, std::vector<int> &primes );//returns number of distinct prime factors
int PRIMENUMBER(unsigned long long PRIME);
int PRIMEFACTORS(unsigned long long NUMBER);
void MAKEPRIMELIST();
int GETPRIMELIST(int NUMBER);
bool ISPRIME(int NUMBER);
int* PRIMEARRAY();
int* SIZEDPRIMEARRAY(int n);
void MAKEPRIMELISTSIEVE();
void initprimesieve(long long size, std::vector<bool> &liste);
void initprimelist(long long maxprime, std::vector<int> &liste);













#endif
