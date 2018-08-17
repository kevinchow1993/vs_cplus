#include <vector>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;


/**
 * @brief ７０．爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 注意：给定 n 是一个正整数
 * @param n 
 * @return int 
 */
int climbStairs(int n){
    vector<int> dp(n+3,0);
    dp[1]=1;
    dp[2]=2;
    
    for(size_t i = 3; i < n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
    
}

/**
 * @brief 198 打家劫舍
 * 
 *你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素
 *就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 * @param nums 
 * @return int 
 */
int HouseRober(vector<int> &nums){
    if(!nums.size()){
        return 0;
    }
    vector<int> dp(nums.size()+3,0);

    dp[0]=nums[0];
    if(nums.size()>1){
        dp[1]=max(nums[0],nums[1]);
    }
    
    
    for(size_t i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i-1],dp[i-2]+nums[i]); 
    }
    return dp[nums.size()-1];

}

/**
 * @brief 最大子序列
 * 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * @param nums 
 * @return int 
 */
int maxSubArray(vector<int> &nums){
    if(!nums.size()){
        return 0;
    }
    if(nums.size()==1){
        return nums[0];
    }
    vector<int> dp(nums.size(),0);
    dp[0]=nums[0];
    int max_ofdp = dp[0];
    
    for(size_t i = 1; i < nums.size(); i++)
    {
        dp[i]= max(dp[i-1]+nums[i],nums[i]);
        if(dp[i]>max_ofdp){
            max_ofdp = dp[i];
        }
    }
    return max_ofdp;
    
}

/**
 * @brief  零钱兑换
 *  输入: coins = [1, 2, 5], amount = 11
    输出: 3 
    解释: 11 = 5 + 5 + 1
    dp[i]跟 dp[i-5] dp[i-2] dp[i-1] 有关 =min(dp[i-5] dp[i-2] dp[i-1])+1
 * @param nums 
 * @param amount 
 * @return int 
 */
int coinChange(vector<int> &coins,int amount){
    vector<int> dp(amount+1,amount+1);
 
    dp[0]=0;
    for(size_t i = 1; i <= amount; i++)
    {
        
        for(size_t j = 0; j < coins.size(); j++)
        {
            if(coins[j]<i){
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
    }
    return dp[amount]>amount+1?-1:dp[amount];   
}

/**
 * @brief 三角形
 * 
 * @param triangle 
 * @return int 
 */
int minimumTotal(vector<vector<int> > &triangle){
    

   vector<vector<int> > dp;
    for(size_t i = 0; i < triangle.size()-1; i++)
    {
        dp.push_back(vector<int>(triangle[i].size(),0));
    }
    dp.push_back(triangle.back());

    
    for(int i = triangle.size()-2; i >=0; i--)
    {
        
        for(size_t j = 0; j < triangle[i].size(); j++)
        {
            dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
        }
        
    }
    return dp[0][0];
    

    
}

int main(int argc, char const *argv[])
{

    int a1[]={2};
    int a2[]={3,4};
    int a3[]={6,5,7};
    int a4[]={4,1,8,3};
    vector<vector<int> > nums;
    nums.push_back(vector<int>(a1,a1+1));
    nums.push_back(vector<int>(a2,a2+2));
    nums.push_back(vector<int>(a3,a3+3));
    nums.push_back(vector<int>(a4,a4+4));

    minimumTotal(nums);
    cin.get();
    return 0;
}
