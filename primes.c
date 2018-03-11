#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "primes.h"

int TRUNCATABLE(int prim){
	int i,tmp,l;
	for(l=0,tmp=prim;tmp!=0;tmp/=10,l++); //bestimme länge der zahl

	//Teste auf wegnehmen von rechter Seite

	for(tmp=prim,i=0;i<l;i++,tmp/=10){
		if(!ISPRIME(tmp))
			return 0;
	}

	//Teste auf wegnehmen von linker Seite

	int teiler;
	for(teiler=pow(10,l-1),tmp=prim,i=0;i<l;i++,tmp%=teiler,teiler/=10){
		if(!ISPRIME(tmp))
			return 0;


	}


	return 1;
}


void MAKEPRIMELISTSIEVE(){
	int i,j;
	FILE* datei;
	char *prime;
	int limit=100000000;
	if((prime=malloc(limit*sizeof(char)))==NULL){
		printf("MAKEPRIMELISTSIEVE out of Memory!\n");
		return;
	}
	prime[0]=0;
	prime[1]=0;
	for(i=2;i<limit;i++){
		prime[i]=1;
	}
	for(i=2;i<3;i++){
		if(prime[i]){
			for(j=2;j<=(limit/i);j++){
				prime[j*i]=0;
			}
		}
	}
	for(i=3;i*i<limit;i++){
		if(prime[i]){
			for(j=2;j<=(limit/i);j++){
				prime[j*i]=0;
			}
		}
	}
	datei=fopen("primelist.txt","w");
	for(i=0;i<limit;i++){
		if(prime[i])
			fprintf(datei,"%i\n",i);
	}
	fclose(datei);
	free(prime);
	printf("Primliste erstellt, enthaelt alle Primzahlen bis 100 Millionen.\n");
}



int* SIZEDPRIMEARRAY(int n){
	int SIZE=n;
	int* prime;
	FILE* datei;
	int i;
	if((prime=malloc(SIZE*sizeof(int)))==NULL){
		printf("PRIMEARRAY out of Memory\n");
		return NULL;
	}
	if((datei=fopen("primelist.txt","r"))==NULL){
		printf("Keine Primzahlenliste gefunden, wird erstellt, einen Moment bitte.\n");
		MAKEPRIMELISTSIEVE();
		if((datei=fopen("primelist.txt","r"))==NULL){
			printf("Das wars ich bin tot!\n");
			return NULL;
		}
	}
	for(i=0;i<n;i++){
		fscanf(datei,"%i",&prime[i]);
	}
	fclose(datei);
	return prime;
}



int* PRIMEARRAY(){
	int SIZE=5761455;
	int* prime;
	FILE* datei;
	int i;
	if((prime=malloc(SIZE*sizeof(int)))==NULL){
		printf("PRIMEARRAY out of Memory\n");
		return NULL;
	}
	if((datei=fopen("primelist.txt","r"))==NULL){
		printf("Keine Primzahlenliste gefunden, wird erstellt, einen Moment bitte.\n");
		MAKEPRIMELISTSIEVE();
		if((datei=fopen("primelist.txt","r"))==NULL){
			printf("Das wars ich bin tot!\n");
			return NULL;
		}
	}
	for(i=0;i<SIZE;i++){
		fscanf(datei,"%i",&prime[i]);
	}
	fclose(datei);
	return prime;
}




void MAKEPRIMELIST(){
	FILE* datei;
	int prime;
	datei=fopen("primelist.txt","w");
	for(prime=2;prime<100000000;prime=GETNEXTPRIME(prime)){
		fprintf(datei,"%i\n",prime);
	}
	fclose(datei);
	printf("Primliste erstellt, enthaelt alle Primzahlen bis 100 Millionen.\n");
}


int GETPRIMELIST(int NUMBER){
	FILE* datei;
	int i;
	int prime;
	if((datei=fopen("primelist.txt","r"))==NULL){
		printf("Keine Primzahlenliste gefunden, wird erstellt, das wird aber etwas dauern.\n");
		MAKEPRIMELIST();
		if((datei=fopen("primelist.txt","r"))==NULL){
			printf("Das wars ich bin tot!\n");
			return -1;
		}
	}
	i=0;
	while(i!=NUMBER){
		if((fscanf(datei,"%i",&prime))==EOF){
			printf("primelist.txt exceeded!\n");
			return -1;
		}
		i++;
	}
	fclose(datei);
	return prime;
}


int ISPRIME(int NUMBER){
	int n=2;
	if(NUMBER<2)
		return 0;
	while(1){
		if(n*n>NUMBER)
			return 1;
		if(NUMBER%n==0)
			return 0;
		n++;
	}
	return -1;
}





int PRIMEFACTORS(unsigned long long NUMBER){
	unsigned long long prev=2;
	int num=1;
	int count=0;
	while(prev<=NUMBER){
		if(NUMBER%prev==0){
			NUMBER/=prev;
			count++;
			if(count>2)
				return -1;
		}
		else{
			num++;
			prev=GETPRIME(num);
		}

	}
	if(count==0)
		return -1;
	else
		return count;
}





int PRIMEFACTOR(unsigned long long NUMBER){
	unsigned long long prev=2;
	int num=1;
	int count=0;
	while(prev<=NUMBER){
		if(NUMBER%prev==0){
			NUMBER/=prev;
			count++;
			printf("Primfaktor %i ist %Lu\n",count,prev);
		}
		else{
			num++;
			prev=GETPRIME(num);
		}

	}
	if(count==0)
		printf("%Lu ist eine Primzahl!\n",NUMBER);
	return count;
}



int PRIMENUMBER(unsigned long long PRIME){
	unsigned long long number;
	int i;
	int k;
	for(k=0,i=1;k!=1;i++){
		if(GETPRIME(i)>PRIME){
			printf("Eingabe keine Primzahl!\n");
			return -1;
		}
		if(GETPRIME(i)==PRIME){
			k=1;
			number=i;
		}
	}
	return number;
}






int GETPRIME(int NUMBER){
	int x=3;
	int n=2;
	int k=2;
	int prime=3;
	if(NUMBER==1)
		return 2;


	while(k<NUMBER+1){
		if(x%n==0){
			x+=2;
			n=2;
		}
		else {
			if(n*n>x){
				k++;
				prime=x;
				x+=2;
				n=2;
			}
			else
				n++;
		}
	}



	return prime;
}


int GETNEXTPRIME(int NUMBER){
	int x=NUMBER+1;
	int n=2;
	int k=0;
	int prime=3;
	if(NUMBER==1)
		return 2;
	while(k!=1){
		if(x%n==0){
			x++;
			n=2;
		}
		else {
			if(n*n>x){
				k++;
				prime=x;
			}
			else
				n++;
		}
	}
	return prime;
}








int GETPREVPRIME(int NUMBER){
	int x=NUMBER-1;
	int n=2;
	int k=0;
	int prime=3;
	while(k!=1){
		if(x==2)
			return 2;
		if(x%n==0){
			x--;
			n=2;
		}
		else {
			if(n*n>x){
				k++;
				prime=x;
			}
			else
				n++;
		}
	}
	return prime;
}
