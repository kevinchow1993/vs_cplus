#include<vector>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;


class Solution
{
public:
    Solution(){
        vs={"password","admin","qwerty","hello","iloveyou","112233"};
       // vs ={"password","admin","qwerty","hello","iloveyou","112233"};
        sp_symbol ="!@#$%^&*()_+-=<>?:~,.{}[]?/";
        capital = 0x00;
    }
    int  codetest(string s){
        string sub2;
        int temp=-100;
        if(s.size()<8){
            return 1;
        }
        for(size_t i=0;i<6;i++){
            if(s.find(vs[i])!=string::npos){
                return 5;
            }

        }
        for(size_t i=0;i<s.size() ;i++){
         if(sp_symbol.find(s[i])!=string::npos){
                break;
            }
            if(i==s.size()-1){
                return 2;
            }
 
        }
        if(is_num_and_cara(s,0)){
            return 2;
        }
        for(size_t i =1;i<s.size();i++){

            if(i>2){
                if('0'<=s[i-2]&&s[i-2]<='9'){
    
                    if(temp==s[i]-s[i-1]){

                        return 3;
                        }

                }
            if(('a'<=s[i-2]&&s[i-2]<='z')||('A'<=s[i-2]&&s[i-2]<='Z')){
                if(temp==s[i]-s[i-1]&&abs(s[i]-s[i-1])==1){

                    return 3;
                    }
            }
            }


            temp=s[i]-s[i-1];
            sub.push_back(temp);
    
        }
        return 0;

    }
private:
    vector<string> vs;
    string sp_symbol;
    int capital;
    string sub;

    bool is_num_and_cara(string s,int a){
        int ca=0x00;
        
        for(size_t i =0;i<s.size();i++){
        if('0'+a<=s[i]&&s[i]<='9'-a){
            ca|=0x01;
     
        }
        if('a'+a<=s[i]&&s[i]<='z'-a){
            ca|=0x02;

        }
        if('A'+a<=s[i]&&s[i]<='Z'-a){
            ca|=0x04;

        }}
        if(a) return ca;
        else{
        return ca^0x07;}


    
    }
    

    

};
 
 int main(int argc, char const *argv[])
 {

    Solution s;
    vector<string> vstr;
    int n;
    cin>>n;
    vector<int> res;
    while(n--){
        string str;
        cin>>str;
        res.push_back(s.codetest(str));
    }
    for(auto i:res){
        if(i){
            cout<<"weak code!:"<<i<<endl;
        }
        else{
            cout<<"strong code!"<<endl;
        }
    }

    cin.get();
    cin.get();
     return 0;
 }
 