#include<iostream>
using namespace std;
struct ListNode{
    ListNode *next;
    int val;
    ListNode(int x):val(x),next(NULL){}
};


main(int argc, char const *argv[])
{
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);

    int num;
    cin>>num;
    ListNode *head=NULL;
    ListNode *p=NULL;
    for(size_t i=0;i<num;i++){
        int x;
        cin>>x;
         if (head ==NULL){
             head = new ListNode(x);
             p=head;

         }
        p->next = new ListNode(x);
        p=p->next;

    }
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cin.get();
    cin.get();
    return 0;
}
