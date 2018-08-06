#include <iostream>
#include <string>
using namespace std;


class reverseStrng
{

public:
    void LeftRotateString(string &s,int n,int m){
        m%=n;
        reverse(s,0,m-1);
        reverse(s,m,n-1);
        reverse(s,0,n-1);

    }
private:
    void reverse(string &s,int start,int end){
        while(start<end){
            char t=s[start];
            s[start]=s[end];
            s[end]=t;
            start++;
            end--;
        }
}
};


int main(int argc, char const *argv[])
{
    string s1 ="kevinchow";
    char* s2 = "kevinchow";

    cout<<s2[3]<<endl;
    reverseStrng handle;
    handle.LeftRotateString(s1,9,5);
    cout<<s1<<endl;
   cin.get();
    return 0;
}


