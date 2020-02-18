#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1);
        for(int& x:ret)
            x=1;
        if(ret.size()>2){
            for(int right=2;right<=rowIndex+1;right++){
                int tmp=1;
                for(int left=1;left<right-1;left++){
                    int t=ret[left];
                    ret[left]=tmp+ret[left];
                    tmp=t;
                }
            }
        }
        return ret;
    }
};