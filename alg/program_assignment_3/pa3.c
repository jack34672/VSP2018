#include<stdio.h>

int function_x(int m);

void getFib();

int fib[19] = {0};

int main(void){

	int a, b, i;
	unsigned long long total = 0;
	char c;

	getFib();
	scanf("%d\n", &a);
	scanf("%d", &b);

	for(i=a; i<=b; i++){
		total = total + function_x(i);
	}
	printf("%llu\n", total);
	return 0;
}

void getFib()
{
     int i;
     fib[0] = 1, fib[1] = 2;
     for (i = 2; i < 19; i ++)
         fib[i] = fib[i - 1] + fib[i - 2];
}

int function_x(int m){
    int i, j, isPut, sum=0, k, twos = 1;
    isPut = 0;
    for (j = 18; j >= 0;j --)
    {
        if ((m / fib[j]) == 1)
        {
	   		for(k=0; k<j; k++){
				twos = twos * 2;
			}
			sum = sum + twos;
			twos = 1;
            m %= fib[j];
            isPut = 1;
        }
        else if (isPut && (m / fib[j]) == 0)
			sum = sum;
    }
	return sum;
}

