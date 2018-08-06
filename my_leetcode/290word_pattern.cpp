#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;


class Solution
{
public:
    bool word_pattern(string &pattern,string &str){
        vector<string> words;
        char used[128]={0};
        map<string,char> word_map;
        string temp="";
        str+=' ';
        for(size_t i = 0; i < str.size(); i++)
        {
            if(str[i]!=' '){
                temp+=str[i];
            }
            else{
                words.push_back(temp);
                temp.clear();
            }

        }
        if(pattern.size()!=words.size()){
            return false;
        }
        for(size_t i = 0; i < pattern.size(); i++)
        {
            if(word_map.find(words[i])==word_map.end()){
                if(used[pattern[i]]){
                    return false;
                }
                else{
                    used[pattern[i]]=1;
                    word_map.insert(pair<string,char>(words[i],pattern[i]));
                }

            }
        }
        return true;
        
        
    }
};

main(int argc, char const *argv[])
{
    Solution so;
    string s1 = "abba";
    string s2 = "dog hot hot dog";
    cout<<so.word_pattern(s1,s2)<<endl;
    cin.get();
    return 0;
}
