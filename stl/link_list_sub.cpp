#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
};

Node *creatList(){
	Node *p = new Node;

	p->data = -1;
	p->next = NULL;
	return p;
}
void printlist(Node *list){
	while(list){
		cout<<list->data<<" ";
		list = list->next;
	}
	cout<<endl;
}
void makeEmpty(Node *list){
	Node *p;
	while(list){
		p= list;
		list = list->next;
		delete p;
	}
}
bool insert(Node *list,int position,int data){
	if(position==0){
		Node *p =new Node;
		p->data = data;
		p->next = list;
		list = p;
	}
	int j=0;
	while(j<position-1&&list){
		list=list->next;
		j++;
	}
	if(list == NULL){
		return 0;
	}
	

	Node *p = new Node;

	
	p->data = data;
	p->next = list->next;
	list->next=p;



	return 1;
	
}
bool remove(Node *list, int data){
	Node *p;
	while(list&&list->data!=data){
		p=list;
		list=list->next;
	}
	if(list){
		p->next=list->next;
		delete list;
		return 1;
	
	}
	else{
		return 0;
	}
}
bool find(Node *list ,int data){
	while(list&&list->data!=data){
		list=list->next;

	}
	if(list){
		return 1;
	}
	
}
int findKth(Node *list,int position){
	while(--position&&list){
		list = list->next;
	}
	return list?list->data:0;
}
int main(int argc, char *argv[])
{

	
	Node *test_list;
	test_list = creatList();
	for(int i=0;i<10;i++){
		
		insert(test_list,i+1,i);
	}
	cout<<"creat a list from 0 to 10"<<endl;


	printlist(test_list);
	
	insert(test_list,5,12);
	printf("insert 5 12");
	printlist(test_list);
	remove(test_list,8);
	printf("remove 8th number");
	printlist(test_list);
	makeEmpty(test_list);
	


	return 0;
}