// check if an integer is a palindrome without extra space
#include<bits/stdc++.h>
using namespace std;

int power(int a, int p){
    int temp = a;
    for(int i=1; i<p; i++){
        a*=temp;
    }
    return a;
}


int isPalindrome(int A) {
    // reverse the integer and compare the two integers unlike string without string
    int reverse=0, temp=A;
    if(A<0)
        return 0;
    while(temp/10!=0){
        int last=temp%10;
        reverse = reverse*10 + last;
        temp /= 10;
    }
    reverse = reverse*10+temp;
    if(reverse != A)
        return 0;
    return 1;
}

/*
fails for 1000011
any where i get leading zeros after removing the first digit

1000011 -> 00001 but in int it is only 1 and single value satisfies.
int count=0, first, last, temp=A;
    if(A<0)
        return 0;
    if(A%10 == A)
        return 1;
    while(A!=0)
    {
        count=0;
        last = A%10;
        while(temp/10 != 0)
        {
            temp/=10;
            count++;
        }
        first = temp;
        if(first != last)
            return 0;
        A = A-(power(10, count)*first);
        A = A/10;
        temp = A;
    }
    return 1;
*/
