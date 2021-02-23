// given an array of elements say integers we need to get the next greater permutation
// we use lexicographical method to find the permutation

// https://www.quora.com/How-would-you-explain-an-algorithm-that-generates-permutations-using-lexicographic-ordering

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    int largesti=-1, largestj, size=A.size();
    
    // finding the element at the right most end that can be swapped with larger element
    // keeping the prefix elements as long as possible
    for(int i=0; i<size-1; i++){
        if(A[i]<A[i+1]){
            largesti=i;
        }
    }
    if(largesti == -1){
        // this is when we have reached the last greatest permutation
        // reverses in place
        reverse(A.begin(), A.end());
        return A;
    }

    // finding a larger element than A[largesti] to the rightmost end 
    for(int j=0;j<size;j++){
        if(A[j]>A[largesti]){
            largestj=j;
        }
    }
    // swap the two elements
    A[largesti]=A[largesti]+A[largestj];
    A[largestj]=A[largesti]-A[largestj];
    A[largesti]=A[largesti]-A[largestj];
    
    // reverse the elements from largesti+1 till end
    // reverse only takes iterators
    reverse(A.begin()+largesti+1, A.end());

    return A;
}
