// - [Sqrt(x) （x 的平方根）](https://leetcode-cn.com/problems/sqrtx/)
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int left=0,right=x;
        while(left<=right){
            int mid=(left+right)/2;
            if(mid*mid<=x){
                if(mid<right and (mid+1)*(mid+1)<=x){
                    left=mid+1;
                }else return mid;
            }
            else {
                right=mid-1;
            }
        }      
        return 0;
    }
};
int main(){
    Solution s;
    cout<<s.mySqrt(4)<<endl;
    cout<<s.mySqrt(5)<<endl;
    cout<<s.mySqrt(6)<<endl;
    cout<<s.mySqrt(8)<<endl;
    cout<<s.mySqrt(9)<<endl;
    return 0;
}