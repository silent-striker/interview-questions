#include<bits/stdc++.h>
using namespace std;

int maxSubArray(const vector<int> &A) {
    // O(n) kadane's algo (assumes atleast one +ve value)
    // check if all values are -ve
    bool flag=true;
    int size=A.size();
    for(int i=0; i<size; i++)
    {
        if(A[i]>0){
            flag=false;
        }
    }
    if(flag)
    {
        return *max_element(A.begin(), A.end());
    }
    
    long ans=INT_MIN, sum=0;
    for(int i=0; i<size ;i++){
        if(sum+A[i] > 0)
            sum+=A[i];
        else
            sum=0;
        ans = max(ans, sum);
    }
    return ans;
}

// nlogn approach, idea is to consider left subarray and right as independent and divide them
// three cases our answer lies in the left part or in between left and right or only right
/*
int maxSubArray(const vector<int> &A) {
    if(A.size()==1)
    {
        return A[0];
    }
    int size=A.size(), half = size/2;
    vector<int> left, right;
    for(int i=0; i<half; i++)
        left.push_back(A[i]);
    for(int i=half; i<size; i++)
    {
        right.push_back(A[i]);
    }
    
    int left_mss = maxSubArray(left), right_mss = maxSubArray(right);
    
    int leftMax = INT_MIN, rightMax=INT_MIN, sum=0;
    for(int i=half-1; i>=0; i++){
        sum+=A[i];
        leftMax=max(leftMax, sum);
    }
    sum=0;
    for(int i=half; i<size; i++){
        sum+=A[i];
        rightMax=max(rightMax, sum);
    }

    int ans = max(left_mss, right_mss);
    return max(ans, leftMax+rightMax);
}
*/

