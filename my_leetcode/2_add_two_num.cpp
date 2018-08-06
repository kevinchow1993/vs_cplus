#include<vector>
#include<iostream>
using namespace std;


/****两数相加
 * 
 * 给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，
 * 它们的每个节点只存储单个数字。将两数相加返回一个新的链表。
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
   输出：7 -> 0 -> 8
   原因：342 + 465 = 807

   这道题用递归做会浪费时间
*********/




 // Definition for singly-linked list.
 struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

/*class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *Ln = new ListNode(-1);
        ListNode *p=Ln;
        int sum;
        int dot=0;
        while(l1||l2){
            int n1 = l1?l1->val:0;
            int n2 = l2?l2->val:0;
            sum = (n1+n2+dot);
            p->next = new ListNode(sum%10);
            p=p->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            dot=sum/10;
        }
        if(dot) p->next = new ListNode(dot);
        return Ln->next;
    }
};*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode result(1);
        ListNode *L =&result;
        int flag = 0;
        add_number(l1,l2,flag,L);
        return L->next;
        
    }
    void add_number(ListNode * l1,ListNode *l2 ,int &flag,ListNode* result){
 
        if(!l1&&!l2){
          
            return;
        }
        int n1 =l1?l1->val:0;
        int n2 = l2?l2->val:0;
        int sum =n1+n2+flag;

  
        flag =sum/10;
        result->next  = new ListNode(sum%10);
    
        add_number(l1->next,l2->next,flag,result->next);


    }
};


int main(int argc, char const *argv[])
{
    ListNode a(3);
    ListNode b(4);
    ListNode c(5);
    ListNode d(6);
    ListNode e(7);
    ListNode f(8);

    a.next=&b;
    b.next =&c;
    d.next = &e;
    e.next = &f;

    ListNode* l1 =&a;
    ListNode* l2 = &d;
    Solution sou;
    ListNode* res =  sou.addTwoNumbers(l1,l2);

    return 0;
}
