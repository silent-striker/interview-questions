// have to convert column name to respective value
// hint is to use base conversion like for base 10 or base 2, here we use base 26
// symbols are from A-Z
#include<bits/stdc++.h>
using namespace std;

int power(int a, int p)
{
    int temp = a;
    if(p == 0)
        return 1;
    while(p>1)
    {
        a*=temp;
        p--;
    }
    return a;
}
int titleToNumber(string A) {
    int value=0, len = A.size();
    for(char c:A){
        len-=1;
        value+=(power(26, len)*(c-'A'+1));
    }
    return value;
}