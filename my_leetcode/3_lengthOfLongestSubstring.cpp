#include<vector>
#include<iostream>
using namespace std;


/***************
 * 
 * 给定一个字符串，找出不含有重复字符的最长子串的长度。
示例：
给定 "abcabcbb" ，没有重复字符的最长子串是 "abc" ，那么长度就是3。
给定 "bbbbb" ，最长的子串就是 "b" ，长度是1。
给定 "pwwkew" ，最长子串是 "wke" ，长度是3。请注意答案必须是一个子串，"pwke" 是 子序列  而不是子串。

散列
***************************/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m[256]={0};
        int res=0,left=0;
        for(int i=0;i<s.size();i++){
            if(m[s[i]]==0||m[s[i]]<left){
                res=max(res,i-left+1);
            }
            else{
                left=m[s[i]];
            }
            m[s[i]]=i+1;
        }
        
        return res;
    }
};