#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for(int i=0;i<ret.size();i++){
            ret[i].resize(i+1);
            ret[i].front()=1;
            ret[i].back()=1;
            if(ret[i].size()>2){
                for(int j=1;j<ret[i].size()-1;j++){
                    ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
                }
            }
        }
        return ret;
    }
};