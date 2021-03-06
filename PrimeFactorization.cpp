#include<bits/stdc++.h>
using namespace std;

const int maxn = 100010;
//判断是否为素数 
bool isPrime(int n){
	if(n==1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i=2; i<=sqr; i++){
		if(n%i==0) return false;
	} 
	return true;
}
////求素数表
int prime[maxn] , pnum =0 ;
//void findPrime(){
//	for(int i=1; i<maxn; i++){
//		if(isPrime(i)){
//			prime[pnum++] = i;
//		}
//	}
//} 
//筛选法求素数表
bool p[maxn] = {0};//素数为false 
void findPrime (){
	for(int i=2; i<maxn; i++){
		if(p[i] == false){//如果i是素数
			prime[pnum++] = i;
			for(int j=i+i; j<maxn; j+=i){
				p[j] = true;
			} 
		 } 
	}
}

struct factor{//x：质因子，cnt:个数 
	int x;
	int cnt;
}fac[10];

int main(){
	findPrime();
	int n, num =0;
	scanf("%d", &n);
	if(n==1) printf("1=1");
	else{
		printf("%d=",n);
		int sqr = (int)sqrt(1.0*n);
		for(int i=0; i<pnum&&prime[i]<=sqr; i++){
			if(n%prime[i] == 0){
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n%prime[i] == 0){
					fac[num].cnt++;
					n/=prime[i];
				}
				num++;
			}
			if(n==1) break;
			 
		}
		if(n!=1){
			fac[num].x = n;
			fac[num++].cnt=1;
		}
		for(int i=0; i<num; i++){
			if(i>0) printf("*");
			printf("%d", fac[i].x);
			if(fac[i].cnt>1){
				printf("^%d",fac[i].cnt);
			}
		}
	} 
	return 0;
} 
