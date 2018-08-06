#include<thread>
#include<iostream>
#include<mutex>

using namespace std;
class mutitask
{
private:
    int num;
public:
    mutitask(int a){
        num= a;
    }
    void setnum(int &num){
        this->num = num;
    }
    void printnum(){
        cout<<num<<endl;
    }

};

void print1(int &i){
    while(i){
        i--;
    }
}

void print2(int &i){
    while(i){
        i--;
    }
}
main(int argc, char const *argv[])
{
    int i=100;
   // mutitask m(10);
    thread t1(print1,ref(i));
    thread t2(print2,ref(i));
    t1.detach();
    t2.detach();
    print1(i);
    cin.get();
    return 0;
}
