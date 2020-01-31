// - 编程模拟实现一个浏览器的前进、后退功能队列
#include <bits/stdc++.h>

using namespace std;
class Browser{
    public:
        Browser& printNow(){
            cout<<"Now at:"<<now<<endl;
            return *this;
        }
        Browser& click(string s){
            BrowserBack.push(now);
            now=s;
            cout<<"#click ";
            printNow();
            return *this;
        }
        Browser& goback(){
            if(!BrowserBack.empty())
            {
                BrowserGo.push(now);
                now=BrowserBack.top();
                BrowserBack.pop();
            }
            cout<<"#goback ";
            printNow();
            return *this;
        } 
        Browser& goforward(){
            if(!BrowserGo.empty())
            {   
                BrowserBack.push(now);
                now=BrowserGo.top();
                BrowserGo.pop();
            }
            cout<<"#goforward ";
            printNow();
            return *this;
        }
        Browser(){
            now="Home";
            printNow();
        }
    private:
        stack<string> BrowserGo;
        stack<string> BrowserBack;
        string now;
};
int main(){
    Browser b;
    b.click("hello").click("hi").click("dada").goback().goback().goback().goback();
    b.goforward().goforward().click("girl").click("boy");
    b.goback().goback().goback().goback().goback();
    return 0;
}