#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
#include <math.h>











void BIGINTREAD(BIGINT *DEST,FILE* DATEI){
	int i;
	int tmp;
	char s;
	for(i=0;1;i++){
		if(fscanf(DATEI,"%c",&s)==EOF)
			break;
		else{
			if(s=='\r'){
				fscanf(DATEI,"%c",&s);
				if(s=='\n')
					break;
				else
					fseek(DATEI,-1,SEEK_CUR);
			}
			if(s=='\n')
				break;
			DEST->data[i]=s-'0';
		}
	}
	DEST->used=i;
	for(i=0;i<DEST->used/2;i++){
		tmp=DEST->data[i];
		DEST->data[i]=DEST->data[DEST->used-i-1];
		DEST->data[DEST->used-i-1]=tmp;
	}
}


void BIGINTFREE(BIGINT *INPUT){
	free(INPUT->data);
}


void BIGINTPRINTF(BIGINT INPUT, FILE* DATEI){
	int i;
		for(i=0;i<INPUT.used;i++){
			fprintf(DATEI,"%i",INPUT.data[INPUT.used-1-i]);
		}
		printf("\n");
}




void BIGINTADDBI(BIGINT *INPUT,BIGINT ADDITION){
	int i;
	int l;
	if(INPUT->used<ADDITION.used){
		l=ADDITION.used;
	}
	else{
		l=INPUT->used;
	}
	INPUT->used=l;
	for(i=0;i<l;i++){
		INPUT->data[i]+=ADDITION.data[i];
	}
	BIGINTREALIGN(INPUT);
}


void BIGINTRESET(BIGINT *INPUT,long long STARTWERT){
	int i;
	for(i=0;i<INPUT->used;i++){
		INPUT->data[i]=0;
	}
	INPUT->data[0]=STARTWERT;
	INPUT->used=1;
	BIGINTREALIGN(INPUT);
}




void BIGINTSET(BIGINT *INPUT,long long STARTWERT){
	INPUT->data=calloc(10000,sizeof(int));
	INPUT->data[0]=STARTWERT;
	INPUT->lange=10000;
	INPUT->used=1;
	BIGINTREALIGN(INPUT);

}

void BIGINTREALIGN(BIGINT *INPUT){
	int i;
	int j;
	int zwischenwert;
	for(i=0;i<INPUT->used;i++){
		if(INPUT->data[i]>9){
			zwischenwert=INPUT->data[i]/10;
			if(INPUT->lange<i+2){
				if((INPUT->data=realloc(INPUT->data,10*INPUT->lange*sizeof(int)))==NULL){
					printf("BIGINTREALIGN out of Memory!");
					return;
				}
				for(j=INPUT->lange;j<INPUT->lange*10;j++){
					INPUT->data[j]=0;
				}
				INPUT->lange*=10;
			}
			if(INPUT->used<i+2){
				INPUT->used++;
			}
			INPUT->data[i]-=zwischenwert*10;
			INPUT->data[i+1]+=zwischenwert;
		}
	}
}

void BIGINTPRINT(BIGINT a){
	int i;
	for(i=0;i<a.used;i++){
		printf("%i",a.data[a.used-1-i]);
	}
	printf("\n");
}


void BIGINTMLTPY(BIGINT *INPUT,long long FAKTOR){
	int i;
	for(i=0;i<INPUT->used;i++){
		INPUT->data[i]*=FAKTOR;
	}
	BIGINTREALIGN(INPUT);
}

void BIGINTPOWER(BIGINT *INPUT,long long POWER){
	long long value;
	int i;
	value=BIGINTVALUE(*INPUT);
	for(i=0;i<POWER-1;i++){
		BIGINTMLTPYPOWER(INPUT,value);
	}
	BIGINTREALIGN(INPUT);
}

void BIGINTMLTPYPOWER(BIGINT *INPUT,long long FAKTOR){
	int i;
	int k;
	for(i=0,k=0;i<INPUT->used;i++){
		INPUT->data[i]*=FAKTOR;
		if(INPUT->data[i]>500000){
			k=1;
		}
	}
	if(k==1){
		BIGINTREALIGN(INPUT);
	}

}

void BIGINTADDI(BIGINT *INPUT,long long ADDITION){
	INPUT->data[0]+=ADDITION;
	BIGINTREALIGN(INPUT);
}



void BIGINTFACULTY(BIGINT *INPUT, int FACULTY){
	int i;
	BIGINTSET(INPUT,1);
	for(i=1;i<FACULTY+1;i++){
		BIGINTMLTPYPOWER(INPUT,i);
		BIGINTREALIGN(INPUT);
	}
}


int BIGINTDIGITSUM(BIGINT INPUT){
	int i;
	int n;
	for(i=0,n=0;i<INPUT.used;i++){
		n+=INPUT.data[i];
	}
	return n;
}



int BIGINTVALUE(BIGINT INPUT){
	long long value;
	int i;
	for(i=0,value=0;i<INPUT.used;i++){
		value+=INPUT.data[i]*pow10((double)i);
	}
	return value;

}
