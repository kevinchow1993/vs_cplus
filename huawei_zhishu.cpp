#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin>>num;

    while(num%2==0){
        cout<<2<<" ";
        num/=2;
    }
    for(int i=3;i<sqrt(num);i+=2){
        while(num%i==0){
            cout<<i<<" ";
            num/=i;
        }
    }
    if(num>2){
        cout<<num<<" ";

    }
    cin.get();
    cin.get();
    return 0;
}
