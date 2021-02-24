// we have to find left and right indices where values between
// left and right (inclusive of both) are flipped (0->1, 1->0)
// we need to find left and right such that we get max ones overall
#include<bits/stdc++.h>
using namespace std;

// to get left and right to get max ones after flipping 
// i wanted to use Max sum subarray approach (kadane's algorithm) where
// 0-> +1 val, 1->-1 val and i want to max sum for a substring.
vector<int> flip(string A) {
    vector<int> result;
    int left=-1, right=-1, temp=0, sum=0, len = A.length(), mx = INT_MIN;
    for(int i=0; i<len; i++){
        sum+=(A[i] == '0'?+1:-1);
        if(sum<0){
            temp = i+1;
            sum=0; 
            continue;
        }
        if(sum>=0 && mx<sum){
            right = i;
            mx = sum;
            left = temp;
        }
    }
    if(left == -1 && right == -1)
        return result;
    result.push_back(left); result.push_back(right);
    return result;
}