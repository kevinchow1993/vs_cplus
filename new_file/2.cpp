#include<Eigen/Eigen>
#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Eigen::Isometry3d T;
    T.setIdentity();
    Eigen::Vector3d p;
    p<<1,2,3;
    Eigen::Vector3d p2 = T*p;
    cout<<T.matrix()<<endl;
    cout<<p2<<endl;
    cout<<p(1)<<endl;
    cin.get();
    return 0;
}
