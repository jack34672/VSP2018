#include<stdio.h>

int function_x(int a);

int fibonacci(int n);

int fib[100] = {0};

int main(void){

	int a, b, i;
	char c;

	scanf("%c%c%c%c", &c, &c, &c, &c);
	scanf("%d, ", &a);
	scanf("%c%c%c%c", &c, &c, &c, &c);
	scanf("%d", &b);

	a = fibonacci(a);
	b = function_x(b);

	printf("%d, %d\n", a, b); 
	
	for(i=0; ; i++){
		printf("%d", fib[i]);
	}

	return 0;
}

int sum = 0;

int function(int a){
	int fibnum, lastnum, i;
	for(i=1; i<=a; i++){
		fibnum = fibonacci(i);
		if(fibnum>a){
			return sum + 2^(i-1) + function(a-lastnum); 
			break;
		}else if(fibnum == a){
			return sum + 2^i;
			break;
		}
		lastnum = fibnum;
	}
}

int fibonacci(int n)
{
    if (n == 0) 
    {
        return 1;
     } 
     if (n == 1) {
           return 1;
     }
     return fibonacci(n - 1) + fibonacci(n - 2);
}
