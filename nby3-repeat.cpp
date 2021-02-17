// we have to find an integer that repeats more than n/3
// time-O(n) and aux space is O(1)
#include<bits/stdc++.h>
using namespace std;

// this solution is O(n)
// https://stackoverflow.com/questions/14761106/determine-if-more-than-half-of-the-array-repeats-in-a-distinct-array/14761366#14761366
// https://www.geeksforgeeks.org/n3-repeated-number-array-o1-space/
// based on moore's voting algorithm
// https://www.geeksforgeeks.org/majority-element/

// so we consider 
int repeatedNumber(const vector<int> &A) {
    int count1=0, c1, count2=0, c2, size = A.size();
    for(int i=0; i<size; i++)
    {
        if(c1 == A[i]){
            count1++;
        }
        else if(c2 == A[i]){
            count2++;
        }
        if(count1 == 0){
            c1 = A[i];
            count1++;
        }
        else if(count2 == 0){
            c2 = A[i];
            count2++;
        }
        
        else{
            // paired the two candidates with the third one
            count1--;
            count2--;
        }
    }
    
    count1=0; count2=0;
    for(int i=0;i<size;i++)
    {
        if(c1==A[i])
            count1++;
        if(c2 == A[i])
            count2++;
    }
    if(count1>size/3)
        return c1;
    if(count2>size/3)
        return c2;
    return -1;
}