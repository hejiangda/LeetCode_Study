//## 数组
// + 实现一个支持动态扩容的数组
// + 实现一个大小固定的有序数组，支持动态增删改操作
// - 实现两个有序数组合并为一个有序数组
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

class orderedArray{
    public:
        orderedArray(int sz)
        {
            this->sz=sz;
            array=new int[sz];
            bot=0;
        }
        int size(){
            return sz;
        }
        void insert(int x){
            if(bot==0){
                array[0]=x;
                bot++;
            }
            else if(bot<sz){
                int i=bot;
                for(;i>=0;i--){
                    if(i==0){
                        array[i]=x;
                        break;
                    }
                    if(x<array[i-1])
                    {
                        array[i]=array[i-1];
                    }else{
                        array[i]=x;
                        break;
                    }
                }
                bot++;
            }
            else
            {
                cout<<"error! array is full"<<endl;
            }
        }
        bool del(int x){
            for(int i=0;i<bot;i++){
                if(array[i]==x)
                {
                    for(int j=i;j<bot;j++){
                        array[j]=array[j+1];
                    }
                    bot--;
                    return true;
                }
            }
            cout<<"error! can not find "<<x<<endl;
            return false;
        }
        void edit(int x,int y){
            if(del(x))
                insert(y);
        }
        void print()
        {
            for(int i=0;i<bot;i++){
                cout<<"["<<i<<"] = "<<array[i]<<endl;
            }
            cout<<endl;
        }
    private:
        int sz;
        int* array;
        int bot;
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
    orderedArray b(5);
    b.insert(1);
    b.insert(6);
    b.insert(3);
    b.insert(0);
    b.insert(9);
    b.insert(10);
    b.edit(9,11);
    b.print();
    return 0;
}