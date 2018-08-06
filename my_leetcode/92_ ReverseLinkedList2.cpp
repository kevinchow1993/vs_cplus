
 // 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         ListNode* pre_head=NULL;
         ListNode* result=head;
        ListNode* tail =NULL;
        int changelength = n-m+1;
        while(head&&--m){
            pre_head = head;
            head=head->next;
           
        }
        tail = head;
        ListNode *new_head =NULL;
        ListNode *next=NULL;
        while(changelength--){
            next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;          
        }
        tail->next = head;
        if (pre_head){
            pre_head->next = new_head;
            return result;
        }
        if(!pre_head){
            return new_head;
        }
    }
};