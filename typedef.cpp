#include<vector>
#include<string>
#include<iostream>
#include<map>


using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);
   // cout<<s<<endl;
    s+=' ';
    vector<string> res;
    string temp;
    vector<string> string_vec;


    map<string,string> string_maps;
    
    for(size_t i = 0; i < s.size(); i++)        
    {
         if(s[i]==';'){
               string_vec.push_back(temp);
               
               string_maps.insert(pair<string,string>(string_vec[2],string_vec[1]));
               string_vec.clear();
               temp.clear();
           
           }
       if(s[i]!=' '){
           

           temp += s[i];
           }
        if(s[i]==' ')
        {
            while(s[i+1]==' '){
                i++;
            };
            string_vec.push_back(temp);
            temp.clear();

        }

    
    }
    string key;
    cin>>key;
    cout<<string_maps[key]<<endl;
    cin.get();

    

    cin.get();
}
