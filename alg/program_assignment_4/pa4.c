#include<stdio.h>

int main(){
	
	unsigned long long i;
	int n, l, s; 
	int a=0, b=0;
	unsigned long long sum=0;
	unsigned long long c_1, c_2;

	scanf("%d", &n);

	if((n==2)||(n==3)){
		sum = 1;
	}else if(n%2==1){
		a=1;
		b=(n-3)/2;
		sum = sum + b + 1;
	}else{
		a=0;
		b=n/2;
		sum = sum + 1;
	}

//	printf("%d\n", sum);


	while(b>=3){
		c_1=1;
		c_2=1;
		b=b-3;
		a=a+2;
		if(a<b){
			l=b;
			s=a;
		}else{
			l=a;
			s=b;
		}

		for(i=1; i<s+1; i++){
			c_1 = c_1 * i;
		}
//		printf("c_1 = %llu\n", c_1);
		for(i=l+1; i<=s+l; i++){
			c_2 = c_2 * i;
		}
//		printf("c_2 = %llu\n", c_2);
		sum = sum + c_2/c_1;
//		printf("times = %llu\n", c_2/c_1);
//		printf("sum = %llu\n", sum);
	}
	if(n==0){
		sum = 0;
	}	
	printf("%llu", sum);

	return 0;
}
