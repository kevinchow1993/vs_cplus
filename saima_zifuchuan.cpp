#include<string>
#include<iostream>
using namespace std;



class saima_zifuchuan
{
public:
int is_in_string(string &s1,string &s2){
    size_t flag=0;
    for(size_t i = 0; i < s2.size(); i++)
    {
       
       flag = s1.find(s2[i]);
        if(flag ==string::npos){
            cout<<"can't find :"<<s2[i]<<endl;
            return 0;
        }
        else{
            cout<<"s1="<<s1<<"  find:"<<s2[i]<<"  flag="<<flag<<endl;
            s1.erase(s1.begin()+flag);

        }
       
    }
    return 1;
        }
};




int main(int argc, char const *argv[])
{
    string s1="dsfaashdffd";
    string s2="aash";
    cout<<"s1="<<s1<<"\ns2="<<s2<<endl;
   // cin>>s1>>s2;
   // cout<<"s1:"<<s1<<"\ns2:"<<s2<<endl;
   cout<<s1.find(s2)<<endl;

    saima_zifuchuan sz;

    
    cout<<sz.is_in_string(s1,s2)<<endl;

    cin.get();

    return 0;
}
