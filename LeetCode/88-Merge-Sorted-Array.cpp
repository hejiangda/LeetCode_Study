#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p,q;
        p=m-1;
        q=n-1;
        int i=m+n-1;
        while(p>=0 and q>=0){
            if(nums2[q]>nums1[p]){
                nums1[i--]=nums2[q--];
            }else{
                nums1[i--]=nums1[p--];
            }
        }
        while(q>=0){
            nums1[i--]=nums2[q--];
        }
    }
};