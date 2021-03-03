// reverse a given integer and if it overflows return 0;
#include<bits/stdc++.h>
using namespace std;

// check for overflow at every stage of the reversal
int reverse(int A) {
    int reverse = 0;
    bool neg = false;
    if(A<0){
        A*=-1;
        neg = true;
    }
    while(A>0){
        int last = A%10;
        // when no. of digits are one less than int max we then compare values
        if((reverse > INT_MAX/10) || (reverse == INT_MAX/10 && last > INT_MAX%10))
            return 0;
        reverse = reverse*10 + last;
        A/=10;
    }
    if(neg)
        reverse *=-1;
    return reverse;
}

/*
works to check overflow by using long or long long
bool neg = false;
    long long reverse = 0;
    if(A<0){
        neg=true;
        A*=-1;
    }
    int temp = A;
    while(temp > 0){
        reverse = reverse*10+(temp%10);
        temp/=10;
    }
    if(reverse > INT_MAX)
        return 0;

    if(neg){
        reverse*=-1;
    }
    return reverse;
*/