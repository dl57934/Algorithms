#include <stdio.h>

int getGcd(int A, int B);
int getLcm(int A, int B, int gcd);
int isBig(int A, int B);
int main(){
	int Aup, Adown;
	int Bup, Bdown;
	int originA, originB;
	int gcd;
	scanf("%d %d", &Aup, &Adown);
	scanf("%d %d", &Bup, &Bdown);
	originA = Adown;
	originB = Bdown;
	if(isBig(Adown, Bdown))
		gcd = getGcd(Adown, Bdown);
	else
		gcd = getGcd(Bdown, Adown);
	int lcm = getLcm(Adown, Bdown, gcd);
	Aup *= lcm/originA;
	Bup *= lcm/originB;

	if(isBig(Aup+Bup, lcm))
		gcd = getGcd(Aup+Bup, lcm);
	else
		gcd = getGcd(lcm, Aup+Bup);
	printf("%d %d",(Aup+Bup)/gcd ,lcm/gcd);
}

int isBig(int A, int B){
	return A > B;
}

int getGcd(int A, int B){
	if(B==0)
		return A;
	else 
		return getGcd(B, A%B);
}

int getLcm(int A, int B, int gcd){
	return A/gcd * B/gcd * gcd;
}