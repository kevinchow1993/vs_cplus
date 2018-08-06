#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
int main()
{   
    vector<int> v;
    int i=0;
    do{
        int d;
        cin>>d;
        v.push_back(d);

    }while(getchar()!='\n');
    cin.get();
    return 0;
}
