//## 数组
//+ 实现一个大小固定的有序数组，支持动态增删改操作

#include <iostream>

using namespace std;

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