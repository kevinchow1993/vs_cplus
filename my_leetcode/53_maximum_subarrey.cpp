#include<iostream>
#include<vector>

using namespace std;


class Solution
{

public:
    int maxSubArray(vector<int> &v){
        int dp[v.size()];
        dp[0]=v[0];
        int max_0=dp[0];
        for(int i=1;i<v.size();i++){
            dp[i]=max(dp[i-1]+v[i],v[i]);
            if(dp[i]>max_0){
                max_0 = dp[i];
            }
        }
        return max_0;
    }

};



int main(int argc, char const *argv[])
{
    int a[]={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a,a+9);
    Solution sou;
    cout<<sou.maxSubArray(v)<<endl;
    cin.get();
    return 0;
}
