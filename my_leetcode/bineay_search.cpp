#include<iostream>
#include<vector>

using namespace std;
/*****************
 * 
 * 这里实现了两种二分查找的方法,递归和循环
 * 
 * 
*********************/
class bineay_search
{
public:
    int Bs_1(vector<int> &v,int begin,int end,int target){
        int mid = (begin+end)/2;
        if(end<begin){
            return -1;
        }
        if(v[mid]==target){
            return mid;
        }
        if(v[mid]<target){
            begin =mid+1;
           return Bs_1(v,begin,end,target);
        }
        if(v[mid>target]){
            end =mid-1;
            
            return Bs_1(v,begin,end,target);
        }
    }
    int Bs_2(vector<int> &v,int target){
        int begin = 0;
        int end = v.size()-1;
        
        while(begin<end){  
            int mid = (begin+end)/2 ;

            if(v[mid]==target){
                return mid;
            }
            if(v[mid]<target){
                begin = mid+1;
            }
            if(v[mid]>target){
                end = mid-1;
            }
        }
        return -1;
        

    }
    
        
    
};

main(int argc, char const *argv[])
{
    bineay_search bs;
    int a[]={1,3,5,7,9,12,35};
    vector<int> v(a,a+7);
    int target = 12;
    cout<<bs.Bs_1(v,0,v.size()-1,12)<<endl;

    cout<<bs.Bs_2(v,12)<<endl;
    cin.get();
    return 0;
}
