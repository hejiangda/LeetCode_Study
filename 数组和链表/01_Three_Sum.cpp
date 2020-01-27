#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        return ret;
    }
};
int main(){
    vector<int> example{-1,0,1,2,-1,-4};
    vector<vector<int>> result;
    Solution s;
    result=s.threeSum(example);
    for(auto v:result){
        cout<<"[";
        for(auto x:v){
            cout<<" "<<x<<" ";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
