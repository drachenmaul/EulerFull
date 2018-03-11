#include<stdio.h>
#include<stdlib.h>

int GETFIBO(int NUMMER){
	unsigned long int fib1=0;
	unsigned long int fib2=1;
	int i;
	unsigned long int print;
	if(NUMMER==1)
		return 0;
	if(NUMMER==2)
		return 1;
	for(print=0,i=2;i<NUMMER;i++){
		print=fib1+fib2;
		fib1=fib2;
		fib2=print;
	}
	return print;
}




int GETNEXTFIBO(int NUMMER){
	unsigned long int fib1=0;
	unsigned long int fib2=1;
	int i;
	unsigned long int print;
	for(i=0;i!=1;){
		print=fib1+fib2;
		fib1=fib2;
		fib2=print;
		if(print>NUMMER)
			break;
	}
	return print;

}
int GETPREVFIBO(int NUMMER){
	unsigned long int fib1=0;
	unsigned long int fib2=1;
	unsigned long prev=1;
	int i;
	unsigned long int print;
	for(i=0;i!=1;){
		prev=print;
		print=fib1+fib2;
		fib1=fib2;
		fib2=print;
		if(print>NUMMER)
			break;
	}
	return prev;
}
