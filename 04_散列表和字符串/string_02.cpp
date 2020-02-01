// - 实现朴素的字符串匹配算法
#include <bits/stdc++.h>

using namespace std;
int bf(const string& s,const string& pattern){
    if(s.length()<pattern.length()){
        return -1;
    }
    for(int i=0;i<s.length()-pattern.length();i++){
        int flg=true;
        for(int j=0;j<pattern.length();j++){
            if(s[i+j]!=pattern[j]){
                flg=false;
                break;
            }
        }
        if(flg)return i;
    }
    return -1;
}
int main(){
    string s="aabbccdd";
    string pattern="bc";
    cout<<"index:"<<bf(s,pattern)<<endl;
    return 0;
}