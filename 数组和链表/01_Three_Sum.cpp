#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // void three(vector<int>& nums,set<vector<int>>& ret,int& i,int& j){
    //     if(i<j){
    //         int sum2=nums[i]+nums[j];
    //         if(sum2<0){
    //             for(int k=j-1;k>i and nums[k]>=0;k--){
    //                 if(sum2+nums[k]==0){
    //                     ret.insert(vector<int>{nums[i],nums[k],nums[j]});
    //                     break;
    //                 }
    //                 else if(sum2+nums[k]<0){
    //                     break;
    //                 }
    //             }
    //             int ii1=i+1;
    //             int jj1=j;
    //             int ii2=i;
    //             int jj2=j-1;
    //             three(nums,ret,ii1,jj1);
    //             three(nums,ret,ii2,jj2);
    //             i++;
    //         }
    //         else if(sum2>0){
    //             for(int k=i+1;k<j and nums[k]<=0;k++){
    //                 if(sum2+nums[k]==0){
    //                     ret.insert(vector<int>{nums[i],nums[k],nums[j]});
    //                     break;
    //                 }
    //                 else if(sum2+nums[k]>0){
    //                     break;
    //                 }
    //             }
    //             int ii1=i+1;
    //             int jj1=j;
    //             int ii2=i;
    //             int jj2=j-1;
    //             three(nums,ret,ii1,jj1);
    //             three(nums,ret,ii2,jj2);
    //             j--;
    //         }
    //         else if(sum2==0){
    //             int k=i+1;
    //             int ii1=i+1;
    //             int jj1=j;
    //             int ii2=i;
    //             int jj2=j-1;
    //             for(;k<j and nums[k]<=0;k++){
    //                 if(sum2+nums[k]==0){
    //                     ret.insert(vector<int>{nums[i],nums[k],nums[j]});
                        
    //                     break;
    //                 }
    //             }
    //             i++;       
    //             j--;
    //             three(nums,ret,ii1,jj1);
    //             three(nums,ret,ii2,jj2);
    //         }
    //     }
    // }
    unordered_set<int> st;

    void three(vector<int>& nums,set<vector<int>>& ret,int& i,int& j){
        int sum2=nums[i]+nums[j];
        
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        vector<vector<int>> ret;
        if(nums.size()<3){
            return ret;
        }
        set<vector<int>> r;
        for(int x:nums){
            st.insert(x);
        }
        while(i<j){
            three(nums,r,i,j);   
        }
        for(vector<int> x:r){
            ret.push_back(x);
        }
        return ret;
    }


};

/**
 * [-4 -1 -1 0 1 2 4]
 *   -2,0,1,1,2
 * -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6
 * 
 * 
 * */
int main(){
    vector<int> example{-1,-2,-3,4,1,3,0,3,-2,1,-2,2,-1,1,-5,4,-3};
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
    cout<<"demo:{";
    for(auto x:example){
        cout<<" "<<x<<" ";
    }
    cout<<"}"<<endl;
    return 0;
}
