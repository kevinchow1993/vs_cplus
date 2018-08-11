#include<iostream>
#include<vector>

using namespace std;


int main(int argc, char const *argv[])
{
    int a[]={1,2,3,4,5,6,7,8};

    for(size_t i = 0; i < 10; i++)
    {
        if(i%2){
            continue;
        }
        cout<<a[i]<<endl;
        
    }
    string s="bacsdaf";
    cout<<s[1]-s[0];
    cin.get();
    return 0;
}
