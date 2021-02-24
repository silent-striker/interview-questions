// we have an array of digits and we have to add one to the num formed by the digits
#include<bits/stdc++.h>
using namespace std;

// time O(n) and aux O(n) (for result vector)
vector<int> plusOne(vector<int> &A) {
    vector<int> result;
    int size = A.size(), carry = 1, stop = 0, j=0;
    if(size == 0)
        return result;

    // finding non zero most sig. digit.
    for(int i=0; i<size;i++){
        if(A[i]!=0){
            stop = i;
            break;
        }
    }

    j=size-1;
    while(j>=stop)
    {
        A[j]+=carry;
        carry = A[j]/10;
        result.push_back(A[j]%10);
        j--;
    }
    if(carry != 0){
        result.push_back(carry);
    }    
    reverse(result.begin(), result.end());
    return result;;
}