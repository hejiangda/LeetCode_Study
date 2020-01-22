//## 数组
//+ 实现两个有序数组合并为一个有序数组

#include <iostream>

using namespace std;

int a[]={1,2,3,5,8,9,11,15,19};
int b[]={-9,-7,-5,4,6,7,10,13,16};


int main(){
    int la,lb;
    la=sizeof(a)/sizeof(int);
    lb=sizeof(b)/sizeof(int);
    int * c=new int[la+lb];
    int i=0,j=0,k=0;
    while(k!=la+lb){
        if(i<la&&j<lb)
            a[i]<b[j]?c[k]=a[i++]:c[k]=b[j++];
        else if(i>=la)
            c[k]=b[j++];
        else if(j>=lb)
            c[k]=a[i++];
        k++;
    }
    for(int h=0;h<la+lb;h++){
        cout<<"c["<<h<<"]="<<c[h]<<endl;
    }
    return 0;
}