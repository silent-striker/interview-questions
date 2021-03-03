// fizz buzz question
#include<bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int A)
{
// The naive soln is checking %15 then % 5 and then %3. But +,-,*,/ are O(N)
   // and % is a O(N^2) operator. So we will try solving without %
   vector<string> res;
   int count3 = 0, count5 = 0;
   for(int i = 1; i<=A; i++){
       count3++; count5++;
       string d = "";
       if(count3 == 3){
           d += "Fizz"; 
           count3 = 0; //reset
       }
       if(count5 == 5){
           d += "Buzz"; 
           count5 = 0; //reset
       } // this also covers 15(fizzbuzz) as buzz is appended to d that already has "fizz"
       
       
       if(d == ""){
           res.push_back(to_string(i)); 
       } else {
           res.push_back(d);
       }
   }
   return res;
}