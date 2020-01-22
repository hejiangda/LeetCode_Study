//## 数组
//+ 实现一个支持动态扩容的数组
#include <iostream>

using namespace std;
class autoScaleArray
{
    public:
        autoScaleArray(int sz)
        {
            if(sz<=0){
                cout<<"error! array size <=0"<<endl;
                exit(-1);
            }
            else{
                this->sz=sz;
                array=new int[sz];
                for(int i=0;i<sz;i++){
                    array[i]=0;
                }
            }
        }
        int& operator[](int index){
            if(index<0){
                cout<<"error! index <0"<<endl;
                exit(-1);
            }
            else if(index<sz){
                return array[index];
            }
            else {
                int *tmp=new int[sz*2];
                for(int i=0;i<sz;i++)
                {
                    tmp[i]=array[i];
                }
                for(int i=sz;i<sz*2;i++)
                {
                    tmp[i]=0;
                }
                delete array;
                array=tmp;
                sz=sz*2;
                return array[index];
            }
        }
        int size(){
            return this->sz;
        }
    private:
        int sz;
        int* array;
};


int main()
{
    autoScaleArray a(5);
    cout<<"array size is: "<<a.size()<<endl;
    for(int i=0;i<7;i++)
        a[i]=i;
    for(int i=6;i>=0;i--)
        cout<<"a["<<i<<"]="<<a[i]<<endl;
    cout<<"array size is: "<<a.size()<<endl;

    return 0;
}