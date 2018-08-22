#include<vector>
#include<iostream>
using namespace std;


struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * @brief 删除某个节点
 * 
 * @param node 
 */
void deleteNode(ListNode *node){
    ListNode *temp;
    node->val = node->next->val;
    temp = node->next;
    node->next = temp->next;
    delete temp;
}

/**
 * @brief 删除第n个节点
 * 
 * @param head 
 * @param n 
 * @return ListNode* 
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *first = head;
    ListNode *end =first;

    while(n--){
        end = end->next;
    }
    if(!end){
        return head->next;
    }
    while(end->next){
        first = first->next;
        end = end->next;

    }
    ListNode *temp = first->next;
    first->next = temp->next;
    delete temp;
    return head;

}

/**
 * @brief 翻转链表
 * 
 * @param head 
 * @return ListNode* 
 */
ListNode* reverseList(ListNode* head) {
    ListNode* newhead = new ListNode(-1);
    ListNode* temp;
    while(head){

    
        temp = head->next;
        head->next=newhead->next;
        newhead->next=head;
        head=temp;

    }
    return newhead->next;
}


/**
 * @brief 合并有序链表
 * 
 * @param l1 
 * @param l2 
 * @return ListNode* 
 */
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

    ListNode* head = new ListNode(-1);
    ListNode* p =head;
    while(l1&&l2){
        if(l1->val<l2->val){
            p->next = l1;
            l1=l1->next;
            
        }
        else{
            p->next = l2;
            l2 = l2->next;
           
        }
         p=p->next;

    }

    if(l1){
        p->next = l1;
    }
    if(l2){
        p->next = l2;
    }
    return head->next;
}

/**
 * @brief 链表回文 -快慢指针 求中点
 * 
 * 
 * @param head 
 * @return true 
 * @return false 
 */
bool isPalindrome(ListNode* head) {
    if(!head||!head->next){
        return true;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while(fast->next&&fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *dummy = new ListNode(-1);
    ListNode *temp;
    slow = slow->next;


    while(slow){
        temp = slow->next;
        slow->next = dummy->next;
        dummy->next = slow;
        slow = temp;
    }
    ListNode *second_head = dummy->next;
    while(second_head){
        if(head->val!=second_head->val){
            return false;
        }
        head = head->next;
        second_head= second_head->next;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    ListNode* a=new ListNode(1);
    ListNode* b=new ListNode(2);
    ListNode* c=new ListNode(3);
    ListNode* d=new ListNode(2);
    ListNode* e=new ListNode(1);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;

    isPalindrome(a);
    
    return 0;
}
