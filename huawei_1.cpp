#include<vector>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);
   // cout<<s<<endl;
    s+=' ';
    vector<string> res;
    string temp;
    
    for(size_t i = 0; i < s.size(); i++)        
    {
       if(s[i]!=' '){
           temp += s[i];}
        if(s[i]==' ')
        {
            while(s[i+1]==' '){
                i++;
            };
            res.push_back(temp);
            temp.clear();

        }
    
    }
       for(size_t i = res.size()-1; i > 0; i--)
       {
           cout<<res[i]<<" ";
       }
       cout<<res[0]<<endl;
    
    

    cin.get();
}
