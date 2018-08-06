#include<iostream>
#include<vector>
#include<map>
using namespace std;

/**************************两数之和*******************

 * 
 * 
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。

你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。


****************************************************/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> numbers;
        vector<int> results;
        for(int i = 0;i<nums.size();i++){
            numbers.insert(map<int,int>::value_type(nums[i],i));
        }
        for(int j =0;j<nums.size();j++){
            //如果找到，而且不为自己
            if(numbers.count(target-nums[j])&&j!=numbers[target-nums[j]]){
 
                results.push_back(j);
                results.push_back(numbers.find(target-nums[j])->second);
                
                break;
            }
            
        }
        return results;
    }
};

int main(int argc, char const *argv[])
{
    int a[] = {1,4,5,3,2,56,8,9,10};

    vector<int> v(a,a+9);
    vector<int> result;
    Solution sou;
    result =  sou.twoSum(v,11);
    
    

    return 0;
}
