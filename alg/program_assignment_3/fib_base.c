#include<stdio.h>

int fib[39] = {0};

void getFib()
{
     int i;
     fib[0] = 1, fib[1] = 2;
     for (i = 2; i < 39; i ++)
         fib[i] = fib[i - 1] + fib[i - 2];
}

int main(){
int n, i, m, j, isPut;
getFib();
    scanf("%d", &m);
    isPut = 0;
    for (j = 38; j >= 0;j --)
    {
        if ((m / fib[j]) == 1)
        {
            printf("1");
            m %= fib[j];   
            isPut = 1;   
        }
        else if (isPut && (m / fib[j]) == 0)
            printf("0");     
    }

}
