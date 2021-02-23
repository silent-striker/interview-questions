// in a given array we have to find first +ve missing number, O(n) time and O(1) space
// the idea is the first missing number lies between 1 to size+1, why??
#include<bits/stdc++.h>
using namespace std;

// lets take values as indicies and at that place make the value negative.
int firstMissingPositive(vector<int> &A) {
    int size = A.size();
    // for values <= 0 make them some value greater than size as we won't consider them
    for(int i=0;i<size;i++){
        if(A[i]<=0){
            A[i]=size+2;
        }
    }

    // as all values are +ve we can use the mentioned approach
    for(int i=0;i<size;i++){
        if(abs(A[i])<=size){
            A[abs(A[i])-1]=-abs(A[abs(A[i])-1]);
        }
    }

    for(int i=0;i<size;i++){
        // if A[i]>0 that means that index was not visited and that number is not there
        if(A[i]>0)
            return i+1;
    }
    return size+1;

}

// this approach fails for vector with all values being same.
// here we try to place the value at its index location
/*
    int i=0, size = A.size();
    while(i<size){
        if(A[i]<=0 || A[i]>=size || A[i]-1==i){
            i++;
            continue;
        }
        int temp = A[i];
        A[i]=A[temp-1];
        A[temp-1]=temp;
    }
    
    for(int i=0; i<size; i++){
        if(A[i]!=i+1)
            return i+1;
    }
    return size+1;

*/