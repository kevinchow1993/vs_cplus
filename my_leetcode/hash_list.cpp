#include<iostream>
#include<vector>
using namespace std;

struct ListNode{
    ListNode *next;
    int val;
    ListNode(int x):val(x),next(NULL){}
};


int hash_func(int x,int l){
    return x%l;
}

void insert(ListNode *a[],ListNode *b,int table){
     int pos =hash_func(b->val,table);
     b->next = a[pos];
     a[pos] = b;


}
bool search(ListNode *a[],int b,int table){
    int pos = hash_func(b,table);
    ListNode *ptr = a[pos];
    while(ptr){
        if(ptr->val ==b){
            return true;
        }
    }
    return false;
}