#include<bits/stdc++.h>
using namespace std;

bool compare(string a, string b){
    return a+b>b+a;
}

string largestNumber(const vector<int> &A) {
    vector<string> strVal;
    string result;
    for(auto i=A.begin(); i!=A.end(); i++){
        strVal.push_back(to_string(*i));
    }
    
    sort(strVal.begin(), strVal.end(), compare);
    
    for(auto itr = strVal.end()-1; itr>=strVal.begin(); itr--){
        result+=*itr;
    }
    return result;
}

// strings approach failed at cases like 30 and 3
// string largestNumber(const vector<int> &A) {
//     vector<string> strVal;
//     string result;
//     for(auto i=A.begin(); i!=A.end(); i++){
//         strVal.push_back(to_string(*i));
//     }
    
//     sort(strVal.begin(), strVal.end());
    
//     for(auto itr = strVal.end()-1; itr>=strVal.begin(); itr--){
//         result+=*itr;
//     }
//     return result;
// }
// custom comparator for sort can solve your problem.