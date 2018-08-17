
#include <memory>
#include <iostream>

using namespace std;
/**
 * @brief 
 * 
 */
class test_shared_ptr
{
private:
    
public:
    int val;
    test_shared_ptr(int a);
    ~test_shared_ptr();
};

test_shared_ptr::test_shared_ptr(int a)
{   
    val=a;
}

test_shared_ptr::~test_shared_ptr()
{   
    cout<<"执行析构函数 val =:"<<val<<endl;
}


int main()
{

    //TODO:
    
    

    test_shared_ptr *p = new test_shared_ptr(8);
    shared_ptr<test_shared_ptr> aptr(p);
    std::cout << "aptr.use_count() = " << aptr.use_count() <<"  value = "<<aptr->val<<std::endl;//use_count 是引用计数器
    std::shared_ptr<test_shared_ptr> cptr(aptr);
    std::cout << "aptr.use_count() = " << aptr.use_count() <<"  value = "<<aptr->val<<std::endl;//use_count 是引用计数器
    shared_ptr<test_shared_ptr> eptr = aptr;
    std::cout << "aptr.use_count() = " << aptr.use_count() <<"  value = "<<aptr->val<<std::endl;//use_count 是引用计数器
    


   // std::shared_ptr<test_shared_ptr> bptr(p);//方式1
    shared_ptr<test_shared_ptr> dptr(new test_shared_ptr(6));
    eptr = dptr;
    cptr = dptr;
    
    //std::shared_ptr<int> aptr = std::make_shared<int>(20);//方式

    //std::cout << "aptr.use_count() = " << aptr.use_count() <<"  value = "<<*aptr<<std::endl;//use_count 是引用计数器
  //  std::cout << "bptr.use_count() = " << bptr.use_count() <<"  value = "<<bptr->val<<std::endl;
  //  std::cout << "cptr.use_count() = " << cptr.use_count() <<"  value = "<<*cptr<<std::endl;
    //输出是：2，20
    //       1，30
    //       2，20
     cin.get();
}