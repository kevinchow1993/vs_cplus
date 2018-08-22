#include<iostream>
#include<vector>

using namespace std;


class s
{
private:
   
public:
int val = 1;


};

int main(int argc, char const *argv[])
{

    vector<int> a{1,2,3,4};
    s s;
    cout<<s.val;
    
    
    for(auto i:a)
    {
        cout<<i<<endl;
    }
    cin.get();
    
    return 0;
}
