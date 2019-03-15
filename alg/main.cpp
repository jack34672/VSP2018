#include <iostream>
#include <math.h>

#define MAX 40

using namespace std;

int decimalToBaseFib(int n, int fibseq[]);

int main(int argc, const char * argv[]) {
    int a, b = 0;
    unsigned long long answer = 0;
    cin >> a;
    cin >> b;
    
    //fibonacci sequence i = 1 to 40
    int fibSeq[MAX] = {0};
    fibSeq[0] = 1;
    fibSeq[1] = 1;
    
    for(int i=2; i<MAX; i++)
        fibSeq[i] = fibSeq[i-1] + fibSeq[i-2];
    
    //decimal -> fib-based -> binary -> decimal
    for(int i=a; i<=b; i++){
//        answer += binaryToDecimal(decimalToBaseFib(i, fibSeq));
        answer += decimalToBaseFib(i, fibSeq);
    }

    cout << answer;
    return 0;
}

//decimal to fib-based
int decimalToBaseFib(int n, int fibSeq[]){
    int BaseFibNum = 0;
    int sum = 0;
    for(int i=MAX; i>0; i--){
        if(n - fibSeq[i] >= 0){
            BaseFibNum = BaseFibNum + pow(10, i-1);
            sum = sum + pow(2,i-1);
            n = n - fibSeq[i];
        }
    }
//    cout << BaseFibNum << " ";
//    cout << sum << "\n";
    return sum;
    //return BaseFibNum;
}

////binary to decimal
//long long int binaryToDecimal(long long int n){
//
//    long long int decimalNum = 0;
//    long long int lastDigit = 0;
//    int base = 1;
//
//    while(n != 0){
//        lastDigit = n % 10;
//        decimalNum = decimalNum + lastDigit * base;
//        base = base * 2;
//        n = n / 10;
//    }
//
//    return decimalNum;
//}
