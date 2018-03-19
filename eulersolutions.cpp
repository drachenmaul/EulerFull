#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include "primes.h"
#include "bigint.h"
#include "fibo.h"
#include "misc.h"
#include "eulersolutions.h"
#include <iostream>
#include <vector>
#include <climits>

using namespace std;




void euler1(){
	/*Find the sum of all the multiples of 3 or 5 below 1000.*/
	int i;
	int result;
	/*Diese Schleife schaut f�r alle Zahlen unter 1000 ob sie restlos durch 3 oder 5 teilbar sind.
	 * Wenn ja wird die aktuelle Zahl auf das Ergebniss addiert.*/
	for(i=0,result=0;i<1000;i++){
		if(i%5==0||i%3==0)
			result+=i;
	}
	printf("%i\n",result);
	}




void euler2(){
	/*By considering the terms in the Fibonacci sequence whose values do not exceed four million,
	 * find the sum of the even-valued terms.*/
	
	int fib1;
	int fib2;
	int print;
	int result;
	
	/*Schleife berechnet Fibonaccizahlen und guckt ob sie gerade sind,
	 * wenn ja wird die aktuelle Zahl auf das Ergebniss aufsummiert.*/
	for(fib1=0,fib2=1,print=0,result=0;print<4000000;){
		if(print%2==0)
			result+=print;
		print=fib1+fib2;
		fib1=fib2;
		fib2=print;

	}
	printf("%i\n",result);
	
	
}



void euler3(){
	/*What is the largest prime factor of the number 600851475143 ?*/
	unsigned long long start=600851475143;
	int n=2;
	int x=3;
	int k=0;
	int i=1;
	int a[10001]={2};
	/*Extrem ineffizienter Code der sich erst alle Primzahlen bis 10001 in ein Array schreibt
	 * und dann von der gr��ten bis zur kleinsten Primzahl durchpr�ft ob die gro�e zahl
	 * restlos teilbar ist, wenn sie restlos teilbar ist wird sie geteilt und der faktor ausgegeben.*/
	while(k<10001){
			if(x%n==0){
				x++;
				n=2;
			}
			else {
				if(n*n>x){
					k++;
					a[i]=x;
					i++;
					x++;
					n=2;
				}
				else
					n++;
			}
	}
	for(i=0;i<1000;i++){
		if(start%a[i]==0){
			start/=a[i];
			printf("%i\n",a[i]);
		}
	}


}





void euler4(){
	/*Find the largest palindrome made from the product of two 3-digit numbers.*/
	
	int i,j;
	int currentpal,largestpal;
	
	/*Die Schleife schaut f�r jedes m�gliche Produkt aus 3-stelligen Zahlen ob es ein pallindrom ist
	 *wenn ja, schaut sie ob das aktuelle Palindrom gr��er ist als das aktuell Gr��te, wenn ja
	 *wird das gr��te neu definiert.*/
	for(currentpal=0,largestpal=0,i=100;i<1000;i++){
		for(j=100;j<1000;j++){
			currentpal=i*j;
			if(ISPALINDROM(currentpal)==1){
				if(currentpal>largestpal)
					largestpal=currentpal;
			}
		}
	}
	printf("%i\n",largestpal);
	

}

void euler5(){
	/*What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/
	long ziel=1;
	int i=1;
	
	/*Die Schleife testet f�r alle Zahlen ob sie durch die Zahlen 1-20 restlos teilbar sind, findet es die erste solche Zahl
	 * bricht sie ab und das Ergebniss wird ausgegeben.*/
	
	while(i<21){
		if(ziel%i==0){
			i++;
		}
		else{
			ziel++;
			i=1;
		}
	}
	printf("%li\n",ziel);
	
	
}




void euler6(){
	/*Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/
	int i;
	
	int sumosquares;
	int squareofsums;
	int sum;
	int diff;
	
	/*Zuerst wird die Summe der Quadrahtzahlen und die Summe der normalen Zahlen.
	 * Dann werden die normalen Zahlen quadriert, die Differenz berechnet und
	 * das Ergebniss ausgegeben*/
	for(i=0,sumosquares=0,sum=0;i<101;i++){
		sumosquares+=i*i;
		sum+=i;
	}
	squareofsums=sum*sum;
	diff=squareofsums-sumosquares;
	printf("%i\n",diff);
	
	
}






void euler7(){
	/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
	 * */
	
	
	/*Primzahlenbibleothek genutzt*/
	printf("%i\n",GETPRIME(10001));
	
	
}

void euler8(){
	/*Find the greatest product of five consecutive digits in the 1000-digit number.

73167176531330624919225119674426574742355349194934
96983520312774506326239578318016984801869478851843
85861560789112949495459501737958331952853208805511
12540698747158523863050715693290963295227443043557
66896648950445244523161731856403098711121722383113
62229893423380308135336276614282806444486645238749
30358907296290491560440772390713810515859307960866
70172427121883998797908792274921901699720888093776
65727333001053367881220235421809751254540594752243
52584907711670556013604839586446706324415722155397
53697817977846174064955149290862569321978468622482
83972241375657056057490261407972968652414535100474
82166370484403199890008895243450658541227588666881
16427171479924442928230863465674813919123162824586
17866458359124566529476545682848912883142607690042
24219022671055626321111109370544217506941658960408
07198403850962455444362981230987879927244284909188
84580156166097919133875499200524063689912560717606
05886116467109405077541002256983155200055935729725
71636269561882670428252483600823257530420752963450*/
	FILE* datei;
	char a[1000];
	int b[1000];
	int i;
	int maxmult;
	int mult;
	/*Liest chars aus der datei ein und wandelt sie in ints um die multipliziert werden. Ausgabe des Ergebniss am Ende.*/
	if((datei=fopen("nbr.txt","r"))==NULL){
		printf("Konnte Datei nicht oeffnen!\n");
		return;
	}
	for(i=0;(fscanf(datei,"%c",&a[i])!=EOF);i++);
	fclose(datei);
	for(i=0;i<1000;i++){
		b[i]=a[i]-48;
	}
	for(i=4,maxmult=0,mult=0;i<1000;i++){
		mult=b[i-4]*b[i-3]*b[i-2]*b[i-1]*b[i];
		if(mult>maxmult){
			maxmult=mult;
		}
	}
	printf("%i\n",maxmult);
}


void euler9(){
	/*A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2

For example, 32 + 42 = 9 + 16 = 25 = 52.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.*/
	double c;
	int a,b;
	
	/*Brute Force, alles wird durchprobiert*/
	for(a=1;a<1000;a++){
		for(b=1;b<1000;b++){
			c=1000-a-b;
				if(a*a+b*b==c*c){
					printf("a: %i\n",a);
					printf("b: %i\n",b);
					printf("c: %lf\n",c);
					printf("a*b*c=%lf\n",a*b*c);
				}
			}
		}
	
}


void euler10(){
	/*The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.*/
	
	int n=2;
	int x=3;
	int k=0;
	int c=0;
	int result=2;
	/*Primzahlen ausrechnen und aufaddieren, k�nnte k�rzer sein
	 * unter verwendung meiner sp�ter Entstandenen Bibleothek*/
	
	while(c==0){
			if(x%n==0){
				x++;
				n=2;
			}
			else {
				if(n*n>x){
					if(x>2000000){
						c=1;
						k++;
						break;
					}
					result+=x;
					k++;
					x++;
					n=2;
				}
				else
					n++;
			}
	}

	printf("%i\n",result);
	
	
}


void euler11(){
	/*In the 20�20 grid below, four numbers along a diagonal line have been marked in red.

08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

The product of these numbers is 26 � 63 � 78 � 14 = 1788696.

What is the greatest product of four adjacent numbers in any direction (up, down, left, right, or diagonally) in the 20�20 grid?
	 * */
	FILE* datei;
	
	int **grid;
	int gridsize;
	int i,j;
	int product;
	int gproduct;
	
	/*Grid wird zuerst aus einer Datei in eine Matrixanordnung geschrieben, danach werden zuerst
	 * alle horizontale m�glichkeiten, dann alle vertikalen, dann diagonal rechtsoben nach links unten
	 * und zuletzt diagonal linksoben nach rechts unten gepr�ft, am Ende das gr��te resultat ausgegeben*/
	gridsize=20;
	if((datei=fopen("prob11.txt","r"))==NULL){
		printf("File not found!\n");
		return;
	}
	grid = new int*[gridsize];
	//TODO: Catch new allocation failure
	for(i=0;i<gridsize;i++){
		grid[i]= new int[gridsize];
	}
	//TODO: Catch new allocation failure
	for(i=0;i<gridsize;i++){
		for(j=0;j<gridsize;j++){
			fscanf(datei,"%i",&grid[i][j]);
			if(grid[i][j]==0){
				fscanf(datei,"%i",&grid[i][j]);
				if(grid[i][j]>9){
					grid[i][j]=0;
					fseek(datei,-2,SEEK_CUR);
				}
			}
		}
	}
	gproduct=0;
	for(i=0;i<gridsize;i++){
		for(j=0;j<gridsize-3;j++){
			product=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
			if(product>gproduct)
				gproduct=product;
		}
	}
	for(j=0;j<gridsize;j++){
		for(i=0;i<gridsize-3;i++){
			product=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
			if(product>gproduct)
				gproduct=product;
		}
	}
	for(i=0;i<gridsize-3;i++){
		for(j=0;j<gridsize-3;j++){
			product=grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
			if(product>gproduct)
				gproduct=product;
		}
	}
	for(i=0;i<gridsize-3;i++){
		for(j=3;j<gridsize;j++){
			product=grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
			if(product>gproduct)
				gproduct=product;
		}
	}
	for(i=0;i<gridsize;i++){
		free(grid[i]);
	}
	free(grid);
	printf("%i\n",gproduct);
	
	
}


void euler12(){
	/*What is the value of the first triangle number to have over five hundred divisors?*/
	
	int triangle;
	int divisors;
	int i;
	int j;
	
	/*Nummer erh�hen, gucken wieviele Teiler und das ganze bis ich gefunden hab was ich suche*/
	for(i=1,triangle=0,divisors=0;divisors<501;i++){
		triangle+=i;
		for(divisors=1,j=1;j<sqrt(triangle)+1;j++){
			if(triangle%j==0)
				divisors+=2;
		}
	}
	printf("%i\n",triangle);
	
	
}



void euler13(){
	/*Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
37107287533902102798797998220837590246510135740250
46376937677490009712648124896970078050417018260538
74324986199524741059474233309513058123726617309629
91942213363574161572522430563301811072406154908250
23067588207539346171171980310421047513778063246676
89261670696623633820136378418383684178734361726757
28112879812849979408065481931592621691275889832738
44274228917432520321923589422876796487670272189318
47451445736001306439091167216856844588711603153276
70386486105843025439939619828917593665686757934951
62176457141856560629502157223196586755079324193331
64906352462741904929101432445813822663347944758178
92575867718337217661963751590579239728245598838407
58203565325359399008402633568948830189458628227828
80181199384826282014278194139940567587151170094390
35398664372827112653829987240784473053190104293586
86515506006295864861532075273371959191420517255829
71693888707715466499115593487603532921714970056938
54370070576826684624621495650076471787294438377604
53282654108756828443191190634694037855217779295145
36123272525000296071075082563815656710885258350721
45876576172410976447339110607218265236877223636045
17423706905851860660448207621209813287860733969412
81142660418086830619328460811191061556940512689692
51934325451728388641918047049293215058642563049483
62467221648435076201727918039944693004732956340691
15732444386908125794514089057706229429197107928209
55037687525678773091862540744969844508330393682126
18336384825330154686196124348767681297534375946515
80386287592878490201521685554828717201219257766954
78182833757993103614740356856449095527097864797581
16726320100436897842553539920931837441497806860984
48403098129077791799088218795327364475675590848030
87086987551392711854517078544161852424320693150332
59959406895756536782107074926966537676326235447210
69793950679652694742597709739166693763042633987085
41052684708299085211399427365734116182760315001271
65378607361501080857009149939512557028198746004375
35829035317434717326932123578154982629742552737307
94953759765105305946966067683156574377167401875275
88902802571733229619176668713819931811048770190271
25267680276078003013678680992525463401061632866526
36270218540497705585629946580636237993140746255962
24074486908231174977792365466257246923322810917141
91430288197103288597806669760892938638285025333403
34413065578016127815921815005561868836468420090470
23053081172816430487623791969842487255036638784583
11487696932154902810424020138335124462181441773470
63783299490636259666498587618221225225512486764533
67720186971698544312419572409913959008952310058822
95548255300263520781532296796249481641953868218774
76085327132285723110424803456124867697064507995236
37774242535411291684276865538926205024910326572967
23701913275725675285653248258265463092207058596522
29798860272258331913126375147341994889534765745501
18495701454879288984856827726077713721403798879715
38298203783031473527721580348144513491373226651381
34829543829199918180278916522431027392251122869539
40957953066405232632538044100059654939159879593635
29746152185502371307642255121183693803580388584903
41698116222072977186158236678424689157993532961922
62467957194401269043877107275048102390895523597457
23189706772547915061505504953922979530901129967519
86188088225875314529584099251203829009407770775672
11306739708304724483816533873502340845647058077308
82959174767140363198008187129011875491310547126581
97623331044818386269515456334926366572897563400500
42846280183517070527831839425882145521227251250327
55121603546981200581762165212827652751691296897789
32238195734329339946437501907836945765883352399886
75506164965184775180738168837861091527357929701337
62177842752192623401942399639168044983993173312731
32924185707147349566916674687634660915035914677504
99518671430235219628894890102423325116913619626622
73267460800591547471830798392868535206946944540724
76841822524674417161514036427982273348055556214818
97142617910342598647204516893989422179826088076852
87783646182799346313767754307809363333018982642090
10848802521674670883215120185883543223812876952786
71329612474782464538636993009049310363619763878039
62184073572399794223406235393808339651327408011116
66627891981488087797941876876144230030984490851411
60661826293682836764744779239180335110989069790714
85786944089552990653640447425576083659976645795096
66024396409905389607120198219976047599490197230297
64913982680032973156037120041377903785566085089252
16730939319872750275468906903707539413042652315011
94809377245048795150954100921645863754710598436791
78639167021187492431995700641917969777599028300699
15368713711936614952811305876380278410754449733078
40789923115535562561142322423255033685442488917353
44889911501440648020369068063960672322193204149535
41503128880339536053299340368006977710650566631954
81234880673210146739058568557934581403627822703280
82616570773948327592232845941706525094512325230608
22918802058777319719839450180888072429661980811197
77158542502016545090413245809786882778948721859617
72107838435069186155435662884062257473692284509516
20849603980134001723930671666823555245252804609722
53503534226472524250874054075591789781264330331690*/
	BIGINT a;
	BIGINT b;
	int i;
	FILE* datei;

	
	/*Datei �ffnen, die zahlen in ein BIGINT schreiben und aufaddieren,
	 * printen lassen und ersten 10 Zahlen ablesen*/
	datei=fopen("50digitnumbers.txt","r");
	BIGINTSET(&a,0);
	for(i=0;i<100;i++){
		BIGINTSET(&b,0);
		BIGINTREAD(&b,datei);
		BIGINTADDBI(&a,b);
		BIGINTFREE(&b);
	}
	BIGINTPRINT(a);
	fclose(datei);

}



void euler14(){
	/*The following iterative sequence is defined for the set of positive integers:

n -> n/2 (n is even)
n -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
	 * */
	FILE* datei;
	
	unsigned long lang=0;
	unsigned long rechenwert=1;
	unsigned long max_l=0;
	unsigned long max_zahl=0;
	unsigned long n=1;
	datei=fopen("result.txt","w");
	
	/*Schleife zur bestimmung der Kettenl�nge, ziemlich offensichtlich*/
	while(n<1000001){
		if(rechenwert==1){
			fprintf(datei,"Kettenlaenge fuer %lu ist %lu!\n",n,lang);
			if(lang>max_l){
				max_l=lang;
				max_zahl=n;
				n++;
				lang=0;
				rechenwert=n;
			}
			else{
				n++;
				lang=0;
				rechenwert=n;
			}
		}
		else{
			if(rechenwert%2==0){
				rechenwert=rechenwert/2;
				lang++;
			}
			else{
				rechenwert=3*rechenwert+1;
				lang++;
			}
		}
	}
	fprintf(datei,"Sieger: Kettenlaenge fuer %lu ist %lu!\n",max_zahl,max_l);
	fclose(datei);
	printf("Sieger: Kettenlaenge fuer %lu ist %lu!\n",max_zahl,max_l);
	
	
}



void euler15(){
	
	
	printf("Wege durch eine 20x20 Grid: %lf\n",PASTRI(41,21));

	
	


}




void euler16(){
	/*2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

What is the sum of the digits of the number 2^1000?
	 * */
	BIGINT a;
	int sum;
	
	
	/*Nutze meine Custom BIGINT Bib, f�r Infos BIGINT BIB schauen*/
	BIGINTSET(&a,2);
	BIGINTPOWER(&a,1000);
	sum=BIGINTDIGITSUM(a);
	printf("%i\n",sum);
}



void euler17(){
	/*

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
	 *
	 */
	int sum=0;
	for(int i=1; i <=1000;i++)
		sum+=Lettercount(i);

	cout << sum << endl;




}



void euler18(){
	/*Find the maximum total from top to bottom of the triangle in the textfile.*/
	int rows=15;
	int **triangle;
	int i,j;
	FILE *datei;
	
	
	/*Als erstes Textfile checken und alle 09 durch 9 und alle 08 durch 8 ersetzen (Oktazahlen) Pyramide allokieren und Werte anf�llen, anschlie�end
	 * arbeitet sich das Programm von unten an die Spitze der Pyramide indem es guckt welcher von 2 nebeneinanderstehenden Werten der gr��ere ist
	 * und diesen dann auf den Wert in der Zeile dar�ber addiert. Dies wird wiederholt bis in der Spitze der Pyramide das Ergebniss steht.*/
	triangle = new int*[rows];
	//TODO: Catch new allocation failure
	for(i=0;i<rows;i++){
		triangle[i]=new int[i+1];
	}
	//TODO: Catch new allocation failure
	if((datei=fopen("prob18.txt","r"))==NULL){
		printf("Datei nicht zu oeffnen!\n");
		return;
	}
	for(i=0;i<rows;i++){
		for(j=0;j<i+1;j++){
			fscanf(datei,"%i",&triangle[i][j]);
		}
	}
	fclose(datei);
	for(i=rows-1;i>0;i--){
		for(j=0;j<i;j++){
			if(triangle[i][j]>triangle[i][j+1]){
				triangle[i-1][j]+=triangle[i][j];
			}
			else{
				triangle[i-1][j]+=triangle[i][j+1];
			}
		}
	}
	printf("Maximale Summe: %i\n",triangle[0][0]);
	for(i=0;i<rows;i++){
		free(triangle[i]);
	}
	free(triangle);
	
	
}

void euler19(){
	printf("%i\n",(12*100)/7);
}


void euler20(){
	/*n! means n � (n - 1) � ... � 3 � 2 � 1

For example, 10! = 10 � 9 � ... � 3 � 2 � 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
	 * */
	
	BIGINT a;
	int sum;
	
	/*BIGINT Bib benutzt*/
	BIGINTFACULTY(&a,100);
	sum=BIGINTDIGITSUM(a);
	printf("%i\n",sum);
	
	
}





void euler21(){
	
	int i;
	int sum;
	int supd;
	
	for(sum=0,i=1;i<10000;i++){
		supd=SUMOPD(i);
		if(supd!=i){
			if(SUMOPD(supd)==i){
				sum+=i;
			}
		}
	}
	printf("Sum of amicable numbers below 10k: %i\n",sum);
	
	
}




void euler23(){
	int i,j;
	int count=0;
	int* abundantnbrs;
	int numbers[28124]={0};
	int sum;
	for(i=0;i<28124;i++){
		if(abundant(i)){
			count++;
		}
	}

	abundantnbrs= new int[count];
	//TODO: Catch new allocation failure
	for(i=0,j=0;i<28124;i++){
		if(abundant(i)){
			abundantnbrs[j]=i;
			j++;
		}
	}


	for(i=0;i<count;i++){
		for(j=i;j<count;j++){
			if((abundantnbrs[i]+abundantnbrs[j])<28124)
					numbers[abundantnbrs[i]+abundantnbrs[j]]=1;
			else
				break;
		}
	}


	for(sum=0,i=0;i<28124;i++)
		if(numbers[i]==0)
			sum+=i;


	printf("%d\n",sum);
}



void euler25(){
	/*What is the first term in the Fibonacci sequence to contain 1000 digits?*/
	
	BIGINT a,b;
	int i;
	
	/*BIGINTs die Fibonacciwerte ausrechnen sich abwechselnd aufaddieren und
	 * wenn die genutzte l�nge 1000 knackt das Ergebniss ausgibt.*/
	BIGINTSET(&a,1);
	BIGINTSET(&b,1);
	for(i=2;a.used!=1000&&b.used!=1000;){
		BIGINTADDBI(&a,b);
		if(a.used<1000)
			i++;
		else{
			i++;
			break;
		}
		BIGINTADDBI(&b,a);
		if(b.used<1000)
			i++;
		else{
			i++;
			break;
		}

	}
	printf("%i\n",i);
	
	
}



void euler27(){
	/*Euler published the remarkable quadratic formula:

 n� + n + 41

It turns out that the formula will produce 40 primes for the consecutive values n = 0 to 39. However, when n = 40, 402 + 40 + 41 = 40(40 + 1) + 41 is divisible by 41, and certainly when n = 41, 41� + 41 + 41 is clearly divisible by 41.

Using computers, the incredible formula  n� - 79n + 1601 was discovered, which produces 80 primes for the consecutive values n = 0 to 79. The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:

    n� + an + b, where |a| < 1000 and |b| < 1000

    where |n| is the modulus/absolute value of n
    e.g. |11| = 11 and |-4| = 4

Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n = 0.
	 * */
	
	int a,b;
	int maxa,maxb;
	int primecount,maxprimecount;
	int n;
	
	/*3-fach-Schleife die alle a und b durchgeht, indem n von 0 an durchgeschaut wird. Nach durchgang von n
	 * wird geschaut ob neue Maximalwerte erreicht wurden. Wenn alles durchgecheckt wurde wird das Ergebniss ausgegeben*/
	for(maxprimecount=0,maxa=0,maxb=0,a=-999;a<1000;a++){
		for(b=-999;b<1000;b++){
			for(n=0,primecount=0;n==primecount;n++){
				if(ISPRIME(n*n+a*n+b)==1)
					primecount++;
			}
			if(primecount>maxprimecount){
				maxprimecount=primecount;
				maxa=a;
				maxb=b;
			}
		}
	}
	printf("Produkt von %i und %i fuer maximale Primzahlen ist: %i\nEs entstehen %i Primzahlen.\n",maxa,maxb,maxa*maxb,maxprimecount);
	
	
}


void euler28(){
	/*Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?*/
	int i,j;
	
	int sum;
	int summand;
	
	/*Per Hand hergeileitet, Grenze Ergibt sich aus Gridgr��e(ungerade)+1 geteilt durch 2*/
	for(sum=1,summand=1,i=1;i<501;i++){
		for(j=0;j<4;j++){
			if(j<4)
				summand+=i*2;
			sum+=summand;

		}
	}
	printf("%i\n",sum);
	

}






void euler30(){
	/*Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
	 * */
	
	/*Wichtigster Schritt: Erkennen, dass das maximum bei Faktor*9^5 liegt, Faktor
	 * ausrechnen und somit den maximalwert bestimmen*/
	int max=354295;
	int current;
	int sum;
	int i;
	int value;
	int element[10];
	int tmp;
	
	/*Hier wird die aktuell betrachtete Zahl zuerst in ein Array geschrieben und anschlie�end jedes
	 * Element ^5 genommen aufaddiert geschaut ob es die Ursprungszahl ergibt und wenn ja aufs
	 * Ergebniss drauf addiert*/
	for(sum=0,current=2;current<max;current++){
		element[0]=current;
		for(i=0;element[i]>9;i++){
			tmp=element[i]/10;
			element[i+1]=tmp;
			element[i]-=tmp*10;
		}
		for(value=0;i>-1;i--){
			value+=pow(element[i],5);
		}
		if(value==current){
			sum+=value;
		}
	}
	printf("%i\n",sum);
	

}


void euler31(){/*
	In England the currency is made up of pound, �, and pence, p, and there are eight coins in general circulation:
	    1p, 2p, 5p, 10p, 20p, 50p, �1 (100p) and �2 (200p).
	It is possible to make �2 in the following way:
	    1ף1 + 1�50p + 2�20p + 1�5p + 1�2p + 3�1p
	How many different ways can �2 be made using any number of coins?*/
	
	int a,b,c,d,e,f,g;
	unsigned long long count;
	
	for(a=0,count=1;a<201;a++)
		for(b=0;b<101;b++)
			for(c=0;c<41;c++)
				for(d=0;d<21;d++)
					for(e=0;e<11;e++)
						for(f=0;f<5;f++)
							for(g=0;g<3;g++)
								if(a*1+b*2+c*5+d*10+e*20+f*50+g*100==200)
										count++;
	printf("%llu\n",count);
}


void euler34(){
	/*145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
	 * */
	
	int max=3000000;
	int i;
	int lang;
	int sum;
	int j;
	int facsum;
	int *array;
	
	/*Gucke wie lang Zahl ist, schreibe Zahl in array, bilde die Fakult�ten der einzelnen Array eintr�ge
	 * addiere die Fakult�ten und schaue nach ob die Ursprungszahl rauskommt
	 * wenn ja aufs gesamtergebniss addieren*/
	for(i=3,sum=0;i<max;i++){
		lang=GETLENGTH(i);
		array=WRITEINARRAY(i);
		for(j=0,facsum=0;j<lang;j++){
			facsum+=FACULTY(array[j]);
		}
		if(facsum==i)
			sum+=facsum;
		free(array);
	}
	printf("%i\n",sum);
	
	
}





void euler35(){
	/*The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
	 * */
	int *prime;
	int circprimecount;
	int circ;
	int lang;
	int i,j;
	int check;
	
	
	/*Schnappe prime rotiere sie sooft wie sie lang ist, wenn die Rotation zur�ck gibt, dass eine 0 f�hrend ist
	 * brich ab und mach mit der n�chsten Prime weiter, ansonsten wird geschaut ist es ne prime, wenn alle rotationen
	 * prime sind wird der circularprimecount um 1 erh�ht.
	 * Was lernen wir: F�hrende Nullen sind mal wieder sehr �tzend*/
	prime=PRIMEARRAY();
	for(i=0,circprimecount=0;prime[i]<1000000;i++){
		circ=prime[i];
		lang=GETLENGTH(circ);
		for(j=0,check=0;j<lang;j++){
			circ=NUMBERROT(circ);
			if(circ==-1)
				break;
			if(ISPRIME(circ)){
				check++;
			}
			if(check==lang){
				circprimecount++;
			}
		}
	}
	free(prime);
	printf("Es gibt %i circular primes unter 1000000!\n",circprimecount);
	
	
}


void euler36(){
	/*Find the sum of all numbers, less than one million,
	 *  which are palindromic in base 10 and base 2.*/
	
	int sum;
	int i;
	
	for(i=1,sum=0;i<1000000;i+=2){
		if(ISPALINDROM(i)){
			if(ISBINARYPALINDROM(i))
				sum+=i;
		}
	}
	printf("%i\n",sum);
	
	
}






void euler37(){
	/*
	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

	Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

	NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
	 */
	int trunccount, i, sum;

	for(i=11,trunccount=0,sum=0;trunccount<11;i++){
		if(ISPRIME(i))
			if(TRUNCATABLE(i)){
				sum+=i;
				trunccount++;
				printf("Got one! %d\n",i);
			}
	}

	printf("Sum of truncatable primes: %d\n",sum);




}


void euler39(){
	int a,b,p,max,curr,maxp;


	for(max=0, maxp=0, p=1;p<=1000;p++){
		for(curr=0, a=1;a<p-1;a++){
			for(b=1;b<=p-a-b;b++){
				if(a*a+b*b==(p-a-b)*(p-a-b)){
					curr++;
				}
			}

		}
		if(curr>max){
			maxp=p;
			max=curr;
		}
	}
	printf("%i\n", maxp);




}




void euler41(){
	/*We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
	 * */
	
	int prime=11;
	int pand;
	int gpand;
	
	/*Die Funktion ISPANDIGITAL pr�ft ob die Nummer pandigital ist, sie wird mit Primzahlen gef�ttert, am Ende wird verglichen und die gr��te Ausgegeben.
	 * Wichtig ist es zu erkennen, dass es keine 8,9 und 10 stelligen pandigitalen Primzahlen geben kann, da diese immer durch 3 Teilbar w�re (Summe 1-8/9/10 ist durch 3 teilbar)*/
	for(gpand=0,pand=1;prime<10000000;prime=GETNEXTPRIME(prime)){
		if(ISPANDIGITAL(prime)==1)
			pand=prime;
		if(pand>gpand)
			gpand=pand;
	}
	printf("%i\n",gpand);
	

}

void euler42(){
	/*The n_th term of the sequence of triangle numbers is given by, tn = �n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we
 form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t_10.
 If the word value is a triangle number then we shall call the word a triangle word.
 Using words.txt (right click and 'Save Link/Target As...'),
  a 16K text file containing nearly two-thousand common English words, how many are triangle words?*/
	
	FILE* datei;

	int count;
	char word;
	int i;
	int wordvalue;
	
	/*Idee wie folgt, ich lese aus der Datei und gucke ob mein eingelesener Wert zwischen A und Z liegt, falls ich auf
	 * ein Komma treffe, schaue ich nach ob der Wortwert eine Triangle-Number ist, wenn ja erh�he ich den Z�hler*/
	datei=fopen("words.txt","r");
	for(wordvalue=0,count=0;(fscanf(datei,"%c",&word))!=EOF;){
		if(word>64&&word<91){
			wordvalue+=word-64;
		}
		if(word==44){
			for(i=1;TRIANGLE(i)<wordvalue+1;i++){
				if(TRIANGLE(i)==wordvalue){
					count++;
					break;
				}
			}
			wordvalue=0;
		}
	}
	/*Hier wird der Check nochmal wiederholt, da das letzte Wort nicht mit einem Komma abgeschlossen wird*/
	for(i=1;TRIANGLE(i)<wordvalue+1;i++){
		if(TRIANGLE(i)==wordvalue){
			count++;
			break;
		}
	}
	printf("%i\n",count);
	
	
}




void euler44(){
	/*

Pentagonal numbers are generated by the formula, Pn=n(3n−1)/2. The first ten pentagonal numbers are:

1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

It can be seen that P4 + P7 = 22 + 70 = 92 = P8. However, their difference, 70 − 22 = 48, is not pentagonal.

Find the pair of pentagonal numbers, Pj and Pk, for which their sum and difference are pentagonal and D = |Pk − Pj| is minimised; what is the value of D?
	 */
	int diff=10000000;
	int pentagon[10001];
	pentagon[0]=0;
	for(int i=1;i<10001;i++)
		pentagon[i]=PENTAGONAL(i);

	for(int i = 1; i < 10001; i++)
		for(int j = i+1 ; j < 10001 ; j++){
			if(ispentagonal(pentagon[i]+pentagon[j]) && ispentagonal(pentagon[j]-pentagon[i])){
				if(pentagon[j]-pentagon[i] < diff)
					diff=pentagon[j]-pentagon[i];
			}
		}
	cout << diff << endl;


	//TODO: Anständiges Abbruchkriterium
}












void euler45(){
	/*Find the next triangle number that is also pentagonal and hexagonal.*/
	
	int i,j;
	int check;
	unsigned long long p,h;
	/*Alle Hexagonalen Zahlen sind auch Triangle Zahlen, es reicht also Nach Pentagonalen Zahlen zu suchen, die auch Hexagonal sind!*/
	
	for(i=144,check=0,p=0;check==0;i++){
		h=HEXAGONAL(i);
		for(j=0;p<h;j++){
			p=PENTAGONAL(j);
		}
		if(p==h){
			check++;
		}
	}
	printf("%Lu\n",p);
	
	
}


void euler46(){
/*
	It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

	9 = 7 + 2�1^2
	15 = 7 + 2�2^2
	21 = 3 + 2�3^2
	25 = 7 + 2�3^2
	27 = 19 + 2�2^2
	33 = 31 + 2�1^2

	It turns out that the conjecture was false.

	What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
	int test,prime,snumber,possible;
	for(possible=1,test=9;possible;test+=2){
		if(!ISPRIME(test)){
			for(possible=0,prime=2;prime<test;prime=GETNEXTPRIME(prime)){
				for(snumber=1;prime+2*snumber*snumber<=test;snumber++){
					if(prime+2*snumber*snumber==test)
						possible=1;
				}
			}
		}
	}

	printf("Erster Fehlschlag bei %d\n",test-2); //test-2 da letzte inkrementierung der for schleife r�ckg�ngig gemachtw erden muss
}

void euler48(){
	/*Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.*/
	BIGINT a,b;
	
	int i;
	
	/*Wieder BIGINTs, a auf 0 setzen, dann in Schleife 1^1 2^2 etc berechnen und jeweils auf a aufaddieren*/
	BIGINTSET(&a,0);
	for(i=1;i<1001;i++){
		BIGINTSET(&b,i);
		BIGINTPOWER(&b,i);
		BIGINTADDBI(&a,b);
		BIGINTFREE(&b);
	}
	BIGINTPRINT(a);
	
	
}


void euler50(){
/*	The prime 41, can be written as the sum of six consecutive primes:
	41 = 2 + 3 + 5 + 7 + 11 + 13

	This is the longest sum of consecutive primes that adds to a prime below one-hundred.

	The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

	Which prime, below one-million, can be written as the sum of the most consecutive primes?*/

	int i,j;
	int prime[41538];
	for(j=0,i=2;i<500000;i++)
		if(ISPRIME(i))
			prime[j++]=i;


	int current, highest, length;

	for(j=0, highest=0, length=0 ;j<41538; j++){
		current=0;
		for(i=j;current<1000000;current+=prime[i],i++){
			if(ISPRIME(current)){
				if(current>highest && (i-j)>length){
					highest=current;
					length=i-j;
				}
			}
		}

	}


	printf("Primzahl: %i\n",highest);
	printf("Kettenglieder: %i\n",length);

}



void euler52(){
	/*It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
	 * */
	
	int number;
	
	/*Nicht wirklich was zu sagen, schaue nach obs f�r doppelt stimmt, wenn ja f�r dreifach etc.*/
	for(number=1;1;number++){
		if(SAMEDIGITS(number,2*number))
			if(SAMEDIGITS(number,3*number))
				if(SAMEDIGITS(number,4*number))
					if(SAMEDIGITS(number,5*number))
						if(SAMEDIGITS(number,6*number))
							break;
	}
	printf("%i\n",number);
	
	
}

void euler53(){

	
	
	int n,r;
	int count;

	for(count=0,n=0;n<=100;n++){
		for(r=0;r<=n;r++)
			if(BinomKoeff(n,r)>1000000)
				count++;
	}



	printf("%d\n",count);

	
	
}



















void euler56(){
	/*Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?*/
	
	BIGINT k;
	int a,b;
	int sum;
	int maxsum;
	
	/*Und wieder BIGINTs, Wert ausrechnen, Ziffern addieren, vergleichen und am Ende das gr��te Ausgeben.*/
	for(maxsum=0,a=2;a<100;a++){
		for(sum=0,b=2;b<100;b++){
			BIGINTSET(&k,a);
			BIGINTPOWER(&k,b);
			sum=BIGINTDIGITSUM(k);
			BIGINTFREE(&k);
			if(sum>maxsum){
				maxsum=sum;
			}
		}
	}
	printf("%i\n",maxsum);
	
	
}


















void euler67(){
	/*Find the maximum total from top to bottom of the triangle in the textfile.*/
	int rows=100;
	int **triangle;
	int i,j;
	FILE *datei;
	
	
	/*Als erstes Textfile checken und alle 09 durch 9 und alle 08 durch 8 ersetzen (Oktazahlen) Pyramide allokieren und Werte anf�llen, anschlie�end
	 * arbeitet sich das Programm von unten an die Spitze der Pyramide indem es guckt welcher von 2 nebeneinanderstehenden Werten der gr��ere ist
	 * und diesen dann auf den Wert in der Zeile dar�ber addiert. Dies wird wiederholt bis in der Spitze der Pyramide das Ergebniss steht.*/
	triangle = new int*[rows];
	//TODO: Catch new allocation failure
	for(i=0;i<rows;i++){
		triangle[i]=new int[i+1];
	}
	//TODO: Catch new allocation failure
	if((datei=fopen("prob67.txt","r"))==NULL){
		printf("Datei nicht zu oeffnen!\n");
		return;
	}
	for(i=0;i<rows;i++){
		for(j=0;j<i+1;j++){
			fscanf(datei,"%i",&triangle[i][j]);
		}
	}
	fclose(datei);
	for(i=rows-1;i>0;i--){
		for(j=0;j<i;j++){
			if(triangle[i][j]>triangle[i][j+1]){
				triangle[i-1][j]+=triangle[i][j];
			}
			else{
				triangle[i-1][j]+=triangle[i][j+1];
			}
		}
	}
	printf("Maximale Summe: %i\n",triangle[0][0]);
	for(i=0;i<rows;i++){
		free(triangle[i]);
	}
	free(triangle);
	
	
}



void euler87(){
	/*

The smallest number expressible as the sum of a prime square, prime cube, and prime fourth power is 28. In fact, there are exactly four numbers below fifty that can be expressed in such a way:

28 = 2^2 + 2^3 + 2^4
33 = 3^2 + 2^3 + 2^4
49 = 5^2 + 2^3 + 2^4
47 = 2^2 + 3^3 + 2^4

How many numbers below fifty million can be expressed as the sum of a prime square, prime cube, and prime fourth power?
	 */
	int i, j, k;
	vector<bool> numbers(50000000, false);
	int *prime = SIZEDPRIMEARRAY(950);
	long long num;
	for(i=0;i<950;i++){
		num=0;
		for(j=0;j<950;j++){
			for(k=0;k<950;k++){
				num=(long long)prime[i]*prime[i];
				num+=(long long)prime[j]*prime[j]*prime[j];
				num+=(long long)prime[k]*prime[k]*prime[k]*prime[k];
				if(num<50000000)
					numbers[num]=true;
				else break;
			}
		}
	}



	for(i=0,num=0;i<50000000;i++)
		if(numbers[i]==true){
			num++;
		}


	cout << num << endl;
	cout << "1097343" << endl;

}





















void euler92(){

/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
 */


	int i,anzahl,qsumme;




	for(i=1,anzahl=0;i<10000000;i++){
		qsumme=i;
		while(qsumme != 1 && qsumme!=89)
			qsumme=QuadratSumme(qsumme);
		if(qsumme==89)
			anzahl++;
	}
	cout << anzahl << " Anfangszahlen unter 10000000 enden mit 89." << endl;




}



















void euler97(){
	/*The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 2^6972593-1; it contains exactly 2,098,960 digits. Subsequently other Mersenne primes, of the form 2^p-1, have been found which contain more digits.

However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433�2^7830457+1.

Find the last ten digits of this prime number.
	 * */

	
	long long unsigned a,b;
	a=1;
	/*Das wichtigste ist a%=10000000000, was bewirkt, dass nur die letzten Ziffern betrachtet werden, der Rest
	 * ist stumpfes ausrechnen*/
	for(b=0;b<7830457;b++)
	{
		a%=10000000000;
		a*=2;
	}
	b=28433*a+1;
	b%=10000000000;
	printf("%llu\n",b);
}




void euler112(){
	/*

Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
	 *
	 */


	int i, bouncy;



	for(i=101, bouncy=0;bouncy*100!=99*(i-1);i++){ // i-1, da die Bedingung das verhältnis vor inkrementierung checken muss
		if(isbouncy(i))
			bouncy++;
	}
	cout << i-1 << endl; //i-1 entfernt die letzte inkrementierung wieder










}













void euler145(){
	/*

Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible. Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (10^9)?

	*/
	
	
	int i;
	int count=0;
	int limit=1e9;

	for(i=0;i<limit;i++){
		if(IsReversible(i))
			count++;
		if(i%500000==0)
			printf("%d\n",i);
	}

	printf("Es gibt %i reversible Zahlen unter %i\n",count,limit);
	
	

}


void euler187(){
	/*A composite is a number containing at least two prime factors. For example, 15 = 3 � 5; 9 = 3 � 3; 12 = 2 � 2 � 3.

There are ten composites below thirty containing precisely two,
not necessarily distinct, prime factors: 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

How many composite integers, n < 10^8, have precisely two, not necessarily distinct, prime factors?
	 * */
	int i,j;
	int prime1=2;
	int prime2=2;
	int limit=100000000;
	int count;
	int *prime;
	
	
	prime=SIZEDPRIMEARRAY(3500000);
	for(count=0,i=0;prime1*prime1<limit;i++){
		prime1=prime[i];
		prime2=prime[i];
		for(j=i;prime1*prime2<limit;j++){
			prime2=prime[j];
			count++;
		}
		count --;
	}
	count++;
	free(prime);
	printf("Zahlen mit 2 Primfaktoren unter 100 Millionen: %i.\n",count);
	
	
}



void euler206(){
/* Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit. */

	long long i, j;
	long long val;
	int counter;
	int ziffer[]= {0,9,8,7,6,5,4,3,2,1};

	for(i=1e9;;i++){
		val=i*i;
		for(counter=0, j=0;j<10;j++){
			if(val % 10 ==ziffer[j]){
				counter++;
				val/=100;
			}else
				break;
				}
		if(counter==10)
			break;
	}
	cout << i << endl;
}


void euler357(){
/*
	Consider the divisors of 30: 1,2,3,5,6,10,15,30.
	It can be seen that for every divisor d of 30, d+30/d is prime.

	Find the sum of all positive integers n not exceeding 100 000 000
	such that for every divisor d of n, d+n/d is prime.
*/
	unsigned long long summe, grenze;
	vector<bool> sieve;
	grenze=100000000;
	initprimesieve(grenze,sieve);
	// 1 is the only odd number where i+1 is prime
	summe=1;
    // scan only even numbers >= 2 of the form 2+4k
	for (unsigned int n = 2; n <= grenze; n += 4){
		if (!sieve[n+1])       // checke für teiler 1
			continue;
		if (!sieve[2 + n/2]) //und für Teiler 2,
			continue;
		bool valid = true;
		for (unsigned teiler = 3; teiler*teiler <= n; teiler++){ //und den Rest
			if (n % teiler != 0)
				continue;
			if (!sieve[teiler + n / teiler]){
				valid = false;
	            break;
			}
		}
		if (valid)
			summe += n;
	}
	cout << summe << endl;
}


























