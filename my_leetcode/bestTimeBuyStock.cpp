#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:

    vector<int> get_price(){
            string s;
            getline(cin,s);
            vector<int> res;
            int num=0;
            for(size_t i = 0; i < s.size(); i++)
            {
                if(s[i]>'0'&&s[i]<='9'){
                    num=num*10+s[i]-'0';
                    }
                if(s[i+1]=='Y'){
                    res.push_back(num);
                    num=0;
                    
                }
                if(s[i+1]=='S'){
                    res.push_back((num)*7);
                    mum=0;
                }
            }
            return res;
            
    }

    
    int maxProfit(vector<int> &prices) {
        // write your code here
        int i,j,m,n,t;
        if(prices.size()==0)
        {
            return 0;
        }
        t = prices.size();
        n=prices[0];
        m = 0;
        for(i=0;i<prices.size()-1;i++)
        {
            if(prices[i+1]<=n)
            {
                n=prices[i+1];
            }
           if(m<=prices[i+1]-n)
           {
               m=prices[i+1]-n;
           }
        }
   
        return m;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> v;
    v= so.get_price();
    cout<<so.maxProfit(v)<<endl;
    return 0;
}
