#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;


/**
 * @brief 只出现一次的数字
 *    异或
 * @param nums 
 * @return int 
 */
int singleNumber(vector<int>& nums) {
    int res= 0;
    for(auto i:nums){
        res^=i;
    }
    return res;

}

class rotateArray{
public:
void rotate(vector<int> nums, int k){
    int n = nums.size();
    k%=n;
    if(nums.empty()||!k) return;

    reverse(nums.begin(),nums.begin()+n-k);
    reverse(nums.begin()+n-k,nums.end());
    reverse(nums.begin(),nums.end());
}
  
};

/**
 * @brief 包含重复数
 * 
 * @param nums 
 * @return true 
 * @return false 
 */
bool containsDuplicate(vector<int> &nums){
    set<int> s;
    for(auto i:nums){
        if(s.count(i)){
            return true;
        }
        else{
            s.insert(i);
        }
    }
    return false;
} 

/**
 * @brief 删除重复数
 * 
 * @param nums 
 * @return int 
 */
int removeDuplicates(vector<int>& nums) {
    
    for(size_t i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]){
            nums.erase(nums.begin()+i-1);
            i--;
        }
    }
    return nums.size();

}


/**
 * @brief 两个数组的交集
 * 
 * @param nums1 
 * @param nums2 
 * @return vector<int> 
 */
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    map<int,int> m;
    vector<int> res;
    for(auto i:nums1){
        m[i]++;
    }
    for(auto j:nums2){
        if(m[j]){
            res.push_back(j);
            m[j]--;
        }
    }
    return res;

}
/**
 * @brief 多次买卖股票
 * 
 * @param prices 
 * @return int 
 */
int maxProfit_II(vector<int>& prices) {
    int res=0;
    for(size_t i=1;i<prices.size();i++){
        if(prices[i]>prices[i-1]){
            res+=prices[i]-prices[i-1];
        }
    }
    return res;


}

/**
 * @brief 旋转图像 
 * 先按对角线翻转,
 * @param matrix 
 */
void rotateImage(vector<vector<int> > &matrix){
    int n= matrix.size();
    
    
    for(size_t i = 0; i < n; i++)
    {
        
        for(size_t j = i+1; j < n; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
        reverse(matrix[i].begin(),matrix[i].end());
        
    }
    
    /*for(size_t i = 0; i < n; i++)
    {
        
        for(size_t j = 0; j < n-i; j++)
        {
            swap(matrix[i][j],matrix[n-1-j][n-1-i]);
        }
        
    }
    
    for(size_t i = 0; i < n/2; i++)
    {
        
        for(size_t j = 0; j < n; j++)
        {
            swap(matrix[i][j],matrix[n-1-i][j]);
        }
        
    }*/
}

/**
 * @brief 加一
 * 
 * @param digits 
 * @return vector<int> 
 */
vector<int> plusOne(vector<int> &digits){

                int n =digits.size();
    int dot=1;
    while(dot)
    {
        if(n){
            int m = digits[n-1]+1;
            digits[n-1] = m%10;
            dot = m/10;
            n--;}
        else{
            digits.insert(digits.begin(),1);
            dot=0;
        }
        

    }
    return digits;
    }

/**
 * @brief 把数组当中的零移到最后
 * 
 * @param nums 
 */
void movezeros(vector<int> &nums){
    int i=0,j=1;
    while(j<nums.size()&&i<nums.size()){
        if(nums[i]==0&&nums[j]!=0){
            swap(nums[i],nums[j]);
        }
        if(nums[i]!=0){
            i++;
            if(i>=j){
                j++;
            }
        }
        if(nums[j]==0){
            j++;
        }
    }
}
int main(int argc, char const *argv[])
{
    int a[]={4,2,4,0,0,3,0,5,1,0};
    int a1[]={1,2,3};
    int a2[]={4,5,6};
    int a3[]={7,8,9};
    vector<int> v1(a1,a1+3);
    vector<int> v2(a2,a2+3);
    vector<int> v3(a3,a3+3);

    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);

    vector<int> num(a,a+10);
    movezeros(num);
    //cout<<removeDuplicates(num)<<endl;
    

    


    cin.get();
    return 0;
}
