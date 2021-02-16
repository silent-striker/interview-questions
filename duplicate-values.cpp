// vector is only read only 
// there maybe more than one duplicate value but return any one
// here size = n+1 and values lie between 1-n
// there is always one duplicate in this array.
#include<bits/stdc++.h>
using namespace std;

int repeatedNumber(const vector<int> &A) {
    int size = A.size(), sqt = sqrt(size);
    int range_count[sqt]={0}, range_index;
    int j;
    for(int i=0; i<size; i++){
        j=A[i]/sqt;
        if(A[i]%sqt == 0)
        {
            j=j-1;
        }
        range_count[j]++;
    }

    for(int i=0; i<sqt; i++){
        if(range_count[i] > sqt){
            range_index=i+1;
            break;
        }
    }

    unordered_map<int,int> freq;
    for(int i=0;i<size; i++){
        if(A[i] <= range_index*sqt && A[i] >= ((range_index-1)*sqt)+1 ){
            freq[A[i]]++;
        }
    }

    for(auto itr=freq.begin(); itr!=freq.end(); itr++){
        if(itr->second > 1){
            return itr->first;
        }
    }
    return -1;
}


/*
//normal freq approach
int size = A.size(), freq[size]={0};
    for(int i=0; i<size; i++){
        freq[A[i]]++;
    }
    for(int i=1;i<size; i++){
        if(freq[i]>1)
            return i;
    }
    return -1;
*/