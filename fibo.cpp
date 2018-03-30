#include<stdio.h>
#include<stdlib.h>

unsigned GETFIBO(unsigned NUMMER){
	unsigned long fib1=0;
	unsigned long fib2=1;
	unsigned i;
	unsigned long print;
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




unsigned GETNEXTFIBO(unsigned NUMMER){
	unsigned long fib1=0;
	unsigned long fib2=1;
	unsigned i;
	unsigned long print;
	for(i=0;i!=1;){
		print=fib1+fib2;
		fib1=fib2;
		fib2=print;
		if(print>NUMMER)
			break;
	}
	return print;

}
unsigned GETPREVFIBO(unsigned NUMMER){
	unsigned long fib1=0;
	unsigned long fib2=1;
	unsigned long prev=1;
	unsigned i;
	unsigned long print=0;
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
