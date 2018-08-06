
#include<vector>
#include<iostream>

using namespace std;
/****************归并排序**************
 * 
 * 
 * 思路：分治算法
 * 先用递归拆分，后合并两个数组
 * 
 * 
 * **********************************/


class Solution
{
public:

    void merge_two_vec(vector<int> &vec1,vector<int> &vec2,vector<int> &Vec){
        int i=0,j=0;
        
        while(i<vec1.size()&&j<vec2.size()){
            if(vec1[i]<vec2[j]){
                Vec.push_back(vec1[i]);
                i++;
            }
            
            else
            {
                Vec.push_back(vec2[j]);
                j++;
            }
            
        }
        
        for( ; i < vec1.size(); i++)
        {
            Vec.push_back(vec1[i]);
        }
        
        for(; j < vec2.size(); j++)
        {
            Vec.push_back(vec2[j]);
        }
        
        
    }

   void merge_sort(vector<int> &v){
        if(v.size()<2){
            return;
        }
        int mid = v.size()/2;
        vector<int> sub1;
        vector<int> sub2;
        sub1.insert(sub1.begin(),v.begin(),v.begin()+mid);
        sub2.insert(sub2.begin(),v.begin()+mid,v.end());

        merge_sort(sub1);
        merge_sort(sub2);
        v.clear();
        merge_two_vec(sub1,sub2,v);
        
    }

};

int main(int argc, char const *argv[])
{
    int a[6]= {2,7,32,4,5,12};
    int b[] = {4,5,6,23,0,57,6,73};
    vector<int> v1(a,a+6);
    vector<int> v2(b,b+8);
    vector<int> v3;
    v2.insert(v2.begin()+3,v1.begin(),v1.begin()+3);
    vector<int> v;
    Solution s;
    s.merge_two_vec(v1,v2,v);
    s.merge_sort(v1);
    for(size_t i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<endl;
    }
    cin.get();
    return 0;
}
