#include<map>
#include<string>
#include<iostream>
#include<vector>

using namespace std;


class Solution
{

public:
    vector< vector<string> > groupAnagrams(vector<string> &strs){
        vector< vector<string> > res;
        map<int,int> m;
        const int p[26]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,87,101};
        for(size_t i = 0; i < strs.size(); i++)
        {
            long int sum=0;
            for(size_t j = 0; j < strs[i].size(); j++)
            {
                sum|=(1<<(strs[i][j]-'a'));

            }
            if(m.find(sum)==m.end()){
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                m.insert(pair<int,int>(sum,res.size()-1));


            }
            else if(res[m[sum]][0].size()!=strs[i].size()){
                vector<string> v;
                v.push_back(strs[i]);
                res.push_back(v);
                m.insert(pair<int,int>(sum,res.size()-1));
            }
            else{
                res[m[sum]].push_back(strs[i]);
            }
        }
        return res;
        
    }
};

main(int argc, char const *argv[])
{
    vector<string> v;
    v.push_back("duh");
    v.push_back("ill");
    Solution so;
    so.groupAnagrams(v);

    return 0;
}
