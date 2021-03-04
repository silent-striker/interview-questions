// find number of trailing zeros in a factorial
#include<bits/stdc++.h>
using namespace std;

int trailingZeroes(int A) {
    // log(n) approach
    // idea behind this is 5(first layer)x5(second layer)x5...
    // first layer 5 is n=5xk that means this number is kth multiple of 5 and it repeats once in all those k multiples
    // so 5 repeats k times effectively, now next layer is n=5(considered)x5(this one)xr (2nd layer) that second 5 repeats r times.
    int count=0;
    // until i have values that can be written as 5xk, k=1,2,3....
    while(A/5>0)
    {
        count+=A/5;
        // get to next layer of numbers
        A/=5;
    }
    return count;
}

/*
int count5=0;
    // O(n) approach as we are checking number of 2's and 5's in each number
    // as they contribute to zeros
    if(A<5)
        return 0;
    for(int i=5; i<=A; i=i+5){
        int temp = i;
        // log i times
        while(temp%5==0)
        {
            temp/=5;
            count5++;
        }
    }
    return count5;
*/