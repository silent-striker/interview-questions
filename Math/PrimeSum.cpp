// an even num is given find sum of primes (sol is always existing Goldbach's conjecture)
// find the first pair a,b such that n = a+b and both a and b are primes
#include<bits/stdc++.h>
using namespace std;

// different way to find prime
// faster way
bool checkPrime(int a){
    if(a <= 1)
        false;
    if(a==2 || a==3)
        return true;
    if(a%2==0 || a%3 == 0)
        return false;
    for(int i=5; i*i<=a; i+=6)
        if(a%i==0 || a%(i+2)==0)
            return false;
    return true;
}
vector<int> primesum(int A) {
    vector<int> result;
    if(A==1 || A==2 || A==3)
        return result;
    // the smaller value will be smaller or equal to the half value
    for(int a=2; a<A/2; a++){
        if(checkPrime(a) && checkPrime(A-a)){
            result.push_back(a);
            result.push_back(A-a);
            break;
        }
    }
    return result;
}