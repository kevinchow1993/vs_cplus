#include <vector>
#include<iostream>
#include<string>
#include<queue>
#include<cmath>
#include<algorithm>
#include<limits>


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
 * @brief 120三角形 最短路径和
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

/**
 * @brief 300.最长上升子序列
 * 
 * dp[i] 为以nums[i]结尾的最长子序列长度
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4 
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 * 
 * @param nums 
 * @return int 
 */
int lengthOfLIS(vector<int>& nums) {
    
    if(nums.empty()){
        return 0;
    }
    vector<int> dp(nums.size(),1);
    int max;
    int maxofall=1;
    dp[0]=1;
    for(int i = 1;i<nums.size();i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                max = dp[j]+1;
                if(dp[i]<max){
                    dp[i]=max;
                }
            }
            
        }
        if(dp[i]>maxofall){
            maxofall = dp[i];
        }
    }
    return maxofall;

}

/**
 * @brief 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 说明：每次只能向下或者向右移动一步。
 * 输入:
 * [
 * [1,3,1],
 * [1,5,1],
 * [4,2,1]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * dp[i][j] = [i][j]位置最小路径和
 * @param grid 
 * @return int 
 */
int minPathSum(vector<vector<int> > &grid){
    vector<vector<int> > dp(grid.size(),vector<int>(grid[0].size(),INT16_MAX));
    dp[0][0] = grid[0][0];
    
    for(size_t i = 1; i < grid.size(); i++)
    {
        dp[i][0] = dp[i-1][0]+grid[i][0];
    }
    for(size_t i = 1; i < grid[0].size(); i++)
    {
        dp[0][i] = dp[0][i-1]+grid[0][i];
        
    }
    

    for(size_t i = 1; i < grid.size(); i++)
    {
        
        for(size_t j = 1; j < grid[0].size(); j++)
        {
            dp[i][j]= min(dp[i-1][j],dp[i][j-1])+grid[i][j];
        }
        
    }
    return dp.back().back();
    
}

/**
 * @brief 地牢游戏
 *      从右下往左上地推
 * @param argc 
 * @param argv 
 * @return int 
 */

int calculateMinimumHP(vector<vector<int>>& dungeon) {

    int rows =dungeon.size();
    int columns = dungeon[0].size();
    vector<vector<int> > dp(dungeon.size(),vector<int>(dungeon[0].size(),INT16_MAX));
    dp[rows-1][columns-1] = 1-dungeon.back().back()>0?1-dungeon.back().back():1;

    //处理边界
    for(int i= rows -2;i>=0;i--){
        dp[i][columns-1] = max(dp[i+1][columns-1]-dungeon[i][columns-1],1);
    }
    for(int j = columns-2;j>=0;j--){
        dp[rows-1][j]=max(dp[rows-1][j+1]-dungeon[rows-1][j],1);
    }

    for(int i= rows -2;i>=0;i--){
        for(int j = columns-2;j>=0;j--){
            int a = max(dp[i+1][j]-dungeon[i][j],1);
            int b = max(dp[i][j+1] - dungeon[i][j],1);
            dp[i][j] = min(a,b);
        }
    }
    return dp[0][0];

    /*
    int m = dungeon.size(), n = dungeon[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = 1; dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j]);
            }
        }
        return dp[0][0];
    */


}

/**
 * @brief 袋鼠过河
 * 
 * @param nums 
 * @return int 
 */
int kangaroo(vector<int> &nums){
    vector<int> dp(nums.size()+1,INT16_MAX);
    dp[0] = 0;

    for(int i = 1; i <= nums.size(); i++)
    {


        for(int j = 0; j < i; j++)
        {
       
            if(nums[j]-(i-j)>=0){

                dp[i] = min(dp[j]+1,dp[i]);

            }
            
        }
        
    }
    return (dp.back()==INT16_MAX?-1:dp.back());
    
    
}


int main(int argc, char const *argv[])
{

    int a1[]={-2,-3,3};
    int a2[]={-5,-10,1};
    int a3[]={10,30,-5};
    int a4[]={4,1,8,3};
    vector<vector<int> > nums;
    nums.push_back(vector<int>(a1,a1+3));
    nums.push_back(vector<int>(a2,a2+3));
    nums.push_back(vector<int>(a3,a3+3));


    int b[]={2,0,1,1,1};
    vector<int> nums2(b,b+5);
    cout<<kangaroo(nums2);
    cin.get();
    return 0;
}
