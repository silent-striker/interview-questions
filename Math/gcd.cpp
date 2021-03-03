// find gcd of two numbers
// logic gcd(a, b) -> gcd(b, a%b) where a>b
#include<bits/stdc++.h>
using namespace std;

int gcd(int A, int B) {
    int rmd;
    if(A<B)
    {
        A=A+B;
        B=A-B;
        A=A-B;
    }
    while(B!=0){
        rmd=A%B;
        A=B;
        B=rmd;
    }
    return A;
}