#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<limits.h>
#include<limits>


using namespace std;



/**
 * @brief 返回字符串第一个不同字符
 * 
 * @param s 
 * @return int 
 */
int firstUniqChar(string s) {
    unordered_map<char,int> um;
    for(char c:s){
        um[c]++;
    }
    for(size_t i =0;i<s.size();i++){
        if(um[s[i]]==1){
            return i;
        }
        
    }
}

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的一个字母异位词。
bool isAnagram(string s, string t) {
    
    int a[128]={0};
    if(s.size()!=t.size()){
        return false;
    }
    for(size_t i=0;i<s.size();i++){
    
            a[s[i]-'0']++;
    }
    
    for(size_t i = 0; i < t.size(); i++)
    {
        int x=t[i]-'0';
        if(a[x]){
            a[x]--;
        }
        else{
            return false;
        }
        
    }
    return true;
    

}


/**
 * @brief 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
 * 
 * @param s 
 * @return true 
 * @return false 
 */
bool isPalindrome(string s) {
    
}



int myAtoi(string str) {
    if(str.empty()){
        return 0;
    }
    int i=0;
    while(str[i]==' '){
        i++;
    }
    int sign =1;
    if(str[i]=='-'||str[i]=='+'){
        if(str[i]=='-'){
            sign = -1;
        }
        i++;
    }
    int n=0;
    while(i<=str.size()&&str[i]>='0'&&str[i]<='9'){
        int c = str[i]-'0';
        if(sign>0&&(n>INT32_MAX/10||(n==INT32_MAX/10&&c>INT32_MAX%10))){
           return INT32_MAX;
          

        }
        else if(sign<0&&(n>INT32_MAX/10||(n==INT32_MAX/10&&c>INT32_MAX%10+1))){
            return n=INT32_MIN;
           
        }
        n=n*10+c;
        i++;
    }
    return sign>0?n:-n;

}




int main(int argc, char const *argv[])
{
    string s{"anagram"};
    string t{"nagaram"};
    string n{"42"};
    cout<<"INT_32MAX"<<INT32_MAX<<'\n'<<"INT32_MIN"<<INT32_MIN<<endl;
    cout<<myAtoi(n)<<endl;
    cin.get();
    return 0;
}
