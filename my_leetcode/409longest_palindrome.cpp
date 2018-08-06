#include<iostream>
#include<vector>
#include<string>

using namespace std;


class Solution
{

public:
    int longest_palindrome(string s){
        int table[128]={0};
        int res=0;
        int flag = 0;
        for(size_t i = 0; i < s.size(); i++)
        {
            table[s[i]-'a']++;
        }
        
        for(size_t i = 0; i < 128; i++)
        {
            if(table[i]%2==0){
                res+=table[i];
            }
            else{
                res+=table[i]-1;
                flag =1;
            }
        }
        return res+flag;
        
        


    }
};

main(int argc, char const *argv[])
{

    string s ="abccccdd";
    
    Solution so;
    cout<<
    so.longest_palindrome(s)<<endl;
    cin.get();
    return 0;
}

