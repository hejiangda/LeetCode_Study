// - [Climbing Stairs（爬楼梯）](https://leetcode-cn.com/problems/climbing-stairs/)
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
//迭代法
    // int climbStairs(int n) {
    //     if(n==1)return 1;
    //     else if(n==2)return 2;
    //     int ways[n+1]={0};
    //     ways[1]=1;
    //     ways[2]=2;
    //     for(int i=3;i<n+1;i++){
    //         ways[i]=ways[i-1]+ways[i-2];
    //     }
    //     return ways[n];
    // }
    // void climb(int n,int *ways){
    //     if(n<=2)return;
    //     ways[n]=ways[n-1]+ways[n-2];
        
    // }
//递归法
    int climbStairs(int n) {
        if(ways==nullptr){
            ways=new int[n+1];
        }

        if(n==1){
            ways[1]=1;
            return 1;
        }else if(n==2){
            ways[2]=2;
            return 2;
        }else{
            if(ways[n]>0)
                return ways[n];
            ways[n]=climbStairs(n-1)+climbStairs(n-2);
            return ways[n];
        }
    }
    int * ways=nullptr;
};

int main(){

    return 0;
}