#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "misc.h"
#include <iostream>

using namespace std;




unsigned long long BinomKoeff(int n, int r) {
    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    unsigned long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}


double PASTRI(int ROW,int POS){
	double **triangle;
	int i,j;
	double ret;
	triangle = new double*[ROW];
	//TODO: Catch new allocation failure
	for(i=0;i<ROW;i++){
		triangle[i]=new double[i+1];
	}
	//TODO: Catch new allocation failure
	triangle[0][0]=1;
	for(i=1;i<ROW;i++){
		triangle[i][0]=1;
		triangle[i][i]=1;
		for(j=1;j<i;j++){
			triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j];
		}
	}
	ret=triangle[ROW-1][POS-1];
	for(i=0;i<ROW;i++){
		delete triangle[i];
	}
	delete(triangle);

	return ret;
}







int SUMOPD(int NUMBER){
	/*Sum of Proper Divisors, Proper Divisor ist Teiler der kleiner als die Zahl ist*/
	int i;
	int sum;
	for(i=1,sum=0;i<NUMBER/2+1;i++){
		if(NUMBER%i==0)
			sum+=i;
	}
	return sum;
}





int NUMBERROT(int NUMBER){
	int lang;
	int i;
	int *NUM;
	lang=GETLENGTH(NUMBER);
	NUM=WRITEINARRAY(NUMBER);
	for(i=0;i<lang-1;i++){
		SWAPINT(&NUM[i],&NUM[i+1]);
	}
	if(NUM[0]==0){
		free(NUM);
		return -1;
	}
	NUMBER=GETARRAYVALUE(NUM,lang);
	free(NUM);
	return NUMBER;
}


int GETARRAYVALUE(int *ARRAY,int lang){
	int value;
	int i;
	for(i=0,value=0;i<lang;i++){
		value+=ARRAY[lang-i-1]*pow10((double)i);
	}
	return value;

}



void SWAPINT(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}


bool SAMEDIGITS(int NUMBER1,int NUMBER2){
	int lang1,lang2;
	int* data1,*data2;
	int i,j;
	int check;
	lang1=GETLENGTH(NUMBER1);
	lang2=GETLENGTH(NUMBER2);
	if(lang1!=lang2)
		return false;
	data1=WRITEINARRAY(NUMBER1);
	data2=WRITEINARRAY(NUMBER2);
	for(check=0,i=0;i<lang1;i++){
		for(j=0;j<lang1;j++){
			if(data1[i]==data2[j]){
				check++;
				data2[j]=-1;
				break;
			}
		}
	}
	free(data1);
	free(data2);
	if(check==lang1)
		return true;
	else
		return false;
}



bool ISBINARYPALINDROM(int ZAHL){
	int BINARY;
	int lang;
	int used;
	int *data;
	int i;
	lang=100000;
	if(ZAHL==0)
		return false;
	data = new int[lang]();
	//TODO: Catch new allocation failure
	data[0]=ZAHL;
	used=1;
	for(i=0;1;i++){
		if(data[i]==1)
			break;
		if(data[i]%2==0){
			data[i+1]=data[i]/2;
			data[i]=0;
			used++;
		}
		else{
			data[i+1]=data[i]/2;
			data[i]=1;
			used++;
		}
	}
	BINARY=0;
	for(i=0;i<used/2;i++){
		if(data[i]==data[used-1-i])
			BINARY++;
	}
	if(BINARY==used/2)
		return true;
	else
		return false;
}




unsigned long long TRIANGLE(int n){
	unsigned long long ret;
	ret=n+1;
	ret*=n;
	ret/=2;
	return ret;
}



unsigned long long PENTAGONAL(int n){
	unsigned long long ret=n;
	ret*=3;
	ret-=1;
	ret*=n;
	ret/=2;
	return ret;
}
unsigned long long HEXAGONAL(int n){
	unsigned long long ret=n;
	ret*=2;
	ret-=1;
	ret*=n;
	return ret;
}


int FACULTY(int INPUT){
	int i;
	int OUTPUT;
	for(i=1,OUTPUT=1;i<INPUT+1;i++)
		OUTPUT*=i;
	return OUTPUT;
}




int* WRITEINARRAY(int INPUT){
	int *ret;
	int length;
	int i;
	int tmp;
	length=GETLENGTH(INPUT);
	ret = new int[length];
	//TODO: Catch new allocation failure
	ret[0]=INPUT;
	for(i=0;i<length-1;i++){
		tmp=ret[i]/10;
		ret[1+i]=tmp;
		ret[i]-=tmp*10;
	}
	for(i=0;i<length/2;i++){
		tmp=ret[i];
		ret[i]=ret[length-1-i];
		ret[length-1-i]=tmp;
	}
	return ret;
}


int GETLENGTH(int NUMBER){
	int length;
	if(NUMBER==0)
		return 1;
	for(length=0;NUMBER>0;length++){
		NUMBER/=10;
	}
	return length;
}




bool ISPALINDROM(int NUMBER){
	int length;
	int palindrom;
	int tmp;
	int i;
	int *look;
	bool result;
	length=GETLENGTH(NUMBER);
	if(length==1)
		return true;
	look = new int[length];
	//TODO: Catch new allocation failure
	look[0]=NUMBER;
	for(i=0;i<length-1;i++){
		tmp=look[i]/10;
		look[1+i]=tmp;
		look[i]-=tmp*10;
	}
	for(i=0,palindrom=0;i<length/2;i++){
		if(look[i]==look[length-1-i]){
			palindrom++;
		}
	}
	if(length/2==palindrom)
		result=true;
	else
		result=false;
	free(look);
	return result;
}

int ISPANDIGITAL(int INPUT){
	int res;
	int* num;
	int lang;
	int i;
	int j;
	lang=GETLENGTH(INPUT);
	if(lang>9)
		return 0;
	num=WRITEINARRAY(INPUT);
	for(i=1,res=0;i<lang+1;i++){
		for(j=0;j<lang;j++){
			if(num[j]==i){
				res++;
				break;
			}
		}
		if(j==lang)
			return 0;
	}
	if(res==lang)
		res=1;
	else
		res=0;
	free(num);
	return res;
}

bool CanReverse(int number){
	if(number%10==0)
		return false;
	else
		return true;
}

int reverse(int number){
    int reversed = 0;
    while (number > 0) {
        reversed = 10 * reversed + number % 10;
        number /= 10;
    }
   return reversed;
}

bool OnlyOddDigits(int number){
    while (number > 0) {
        if ((number % 10) % 2 == 0) return false;
        number /= 10;
    }
    return true;
}


bool IsReversible(int number){
	if(!CanReverse(number))
		return false;

	number+=reverse(number);
	if(OnlyOddDigits(number))
		return true;
	else
		return false;
}






bool abundant(int n){
	int i,divisorsum;

	for(i=n-1,divisorsum=0;i>0;i--){
		if(n%i==0)
			divisorsum+=i;
	}
	if(divisorsum>n)
		return true;
	else
		return false;
}




int QuadratSumme(int number){
	int summe, lang, i;
	lang=GETLENGTH(number);
	for(i=0,summe=0;i<lang;i++){
		summe+= (number%10)*(number%10);
		number/=10;
	}
	return summe;

}



bool isbouncy(int number){
	if(number<101)
		return false;
	bool ascending=false;
	bool descending=false;
	int length=GETLENGTH(number);
	int curr, last;
	curr=number%10;
	for(int i=0;i<length-1;i++){
		last=curr;
		number/=10;
		curr=number%10;
		if(curr<last)
			ascending=true;
		if(curr>last)
			descending=true;
	}





	if(ascending && descending)
		return true;
	else
		return false;
}



int Lettercount(int number){
	if (number > 1000 || number < -1000){
		cout << "Funktion Lettercount funktioniert nur bis einschließlich +-1000" << endl;
		return -1;
	}
	if(number == 1000)
		return 11;				//Wenn 1000 return "one thousand"
	int bis19[] = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4, 3, 6, 6, 8, 8, 7, 7, 9, 8, 8}; 	//Länge der Worte zero - nineteen
	int zehner[] = {6, 6, 5, 5, 5, 7, 6, 6};										//Länge von twenty - ninety
	int hu = 7;																		//Länge von "hundred"
	int und = 3;																		//Länge von und
	int sum=0;																		//rückgabe
	if(number < 0){		//wenn zahl negative füge ein
		sum+=5;			//"minus" hinzu
		number*=-1;		//und mache die Zahl anschließend positiv
	}

	int length=GETLENGTH(number);




	if (length == 3){		//100 bis max 999
		int tmp=number;
		tmp/=100;			//Finde hunderter Stelle raus
		sum+=bis19[tmp];	//Füge Hunderterzahl hinzu
		sum+=hu;			//Füge "hundred" hinzu
		if(number % 100 == 0)//Füge "and" hinzu wenn kein gerader hunderter
			return sum;		//Wenn glatter hunderter sind wir fertig
		sum+=und;			//Füge "and" hinzu
		number-=tmp*100;	//entferne Hunderterstelle
		length--;			//Passe länge an
	}

	if(length == 2){		//Zahl von 10 bis 99
		if(number < 20)
			sum+=bis19[number];
		else{
			if(number%10 != 0)			//20 ist nicht twenty-zero
				sum+=bis19[number%10];	//Zahl >= 20, füge einerstelle hinzu
		number/=10;
		sum+=zehner[number-2];			//Füge 10er-Stelle hinzu
		}
	}
	if(length == 1)
		sum+=bis19[number];


	return sum;
}




bool ispentagonal(int number){
	double penTest = (sqrt(1 + 24 * number) + 1.0) / 6.0;
	return penTest == ((int)penTest);
}


int GCD(int a, int b){
	while( a != 0 && b != 0){
		if(a < b)
			b%=a;
		else
			a%=b;
	}
	if(a==0)
		return b;
	else
		return a;
}


unsigned DigitSum(unsigned number){
	unsigned sum=0;
	unsigned length=GETLENGTH(number);
	for(unsigned i=0;i<length;i++){
		sum+=number%10;
		number/=10;
	}

	return sum;
}












