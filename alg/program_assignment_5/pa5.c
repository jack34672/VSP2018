#include<stdio.h>

int transfer(int a, int b, int c);

int main(){
	int A, B, C;
	int balance, sol=0;
	int i=0;
	
	scanf("%d %d %d", &A, &B, &C);
	
	balance = (A+B+C)/3;
	

	if((A+B+C)%3!=0){
		sol = 0;
	}else{
		sol = transfer(A,B,C);
	}
	
	printf("%d", sol);


	return 0;
}

int time = 0;

int transfer(int a, int b, int c){
	int l, m, s;

	if((a==b)&&(b==c)){
		printf("%d, %d, %d\n", a, b, c);	
		return 1;
	}
	
	time++;
//	printf("%d\n", time);
	if((a>=b)&&(a>=c)){
		if(b>=c){l=a;m=b;s=c;}
		else{l=a;m=c;s=b;}
	}else if((b>=c)&&(b>=a)){
		if(a>=c){l=b;m=a;s=c;}
		else{l=b;m=c;s=a;}
	}else{
		if(a>=b){l=c;m=a;s=b;}
		else{l=c;m=b;s=a;}
	}
//	printf("%d, %d, %d\n", l, m, s);
	if(time<=100){
		if(((transfer(l-s, m, s+s)==1)||(transfer(l-m, m+m, s)==1))){
			return 1;
		}else{
			return 0;
		}
	}

}
