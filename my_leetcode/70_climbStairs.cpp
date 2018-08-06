
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int steps[n+3]={0};//加三的原因是,有的样例会只有两个台阶或一个台阶
        steps[1]=1;
        steps[2]=2;
        for(int i=3;i<=n;i++){
            steps[i]=steps[i-1]+steps[i-2];
            
        }
        return steps[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution sou;
    cout<<sou.climbStairs(6)<<endl;
    cin.get();
    return 0;
}
