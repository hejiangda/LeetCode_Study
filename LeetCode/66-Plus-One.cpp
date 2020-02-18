#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int acc=1;
        for(auto it=digits.rbegin();it!=digits.rend();it++){
            *it+=acc;
            acc=0;
            if(*it>=10){
                acc=1;
                *it=0;
            }
        }
        if(acc>0){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};