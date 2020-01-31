#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
     vector<int> twoSum(vector<int>& nums,int targ) {
        vector<int> ret;
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            if( mp.find(targ-nums[i])!=mp.end()&&i!=mp[targ-nums[i]]){
                ret.push_back(i);
                ret.push_back(mp[targ-nums[i]]);
                break;
            }
            
        }
        return ret;
    }
};
int main(){
    vector<int> example{2, 7, 11, 15};
    int target=9;
    vector<int> result;
    Solution s;
    result=s.twoSum(example,target);
    cout<<"[";
    for(auto v:result){
        
        // for(auto x:v){
            cout<<" "<<v<<" ";
        // }
        
    }
    cout<<"]"<<endl;
    return 0;
}
