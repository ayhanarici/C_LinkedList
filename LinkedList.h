#include <iostream>
#include "Node.h"
using namespace std;
class LinkedList{
	Node *head;
	protected:
		int countList(){
			Node *iterator=head;
			int count=0;
			while(iterator->next!=NULL)
			{
				count++;
				iterator=iterator->next;
			}
			return count;
		}
	public:
		LinkedList(){
			head = NULL;
		}
		
		void insertFirst(int pdata)
		{
			Node *tempNode=new Node();
			tempNode->data=pdata;
			tempNode->next=head;
			head=tempNode;
		}
		
		void deleteFirst(){
			if(head==NULL){
				cout<<"Your Linked List is already empty..."<<endl;
			}else{
				Node *tempNode=head;
				cout<<head->data<<" is deleted..."<<endl;
				head=head->next;
				if (head==NULL){
					cout<<"Your Linked List is completely empty..."<<endl;
				}
				delete(tempNode);
			}
		}
		
		void insertEnd(int pdata){
			Node *tempNode=new Node();
			tempNode->data=pdata;
			if(head==NULL)
			{
				head=tempNode;
			}else
			{
				Node *iterator=head;
				while(iterator->next!=NULL)
				{
					iterator=iterator->next;
				}
				iterator->next=tempNode;
			}
		}
		void deleteEnd(){
			if(head==NULL)
			{
				cout<<"Your Linked List is already empty..."<<endl;
			}else if(head->next==NULL){
				cout<<"Last element "<<head->data<<" deleted"<<endl;
				cout<<"Your Linked List is completely empty..."<<endl;
				delete(head);
				head=NULL;
			}else{
				Node *tempNode=head;
				while(tempNode->next->next!=NULL){
					tempNode=tempNode->next;
				}
				cout<<"Last element "<<tempNode->next->data<<" deleted"<<endl;
				delete(tempNode->next);
				tempNode->next=NULL;
			}
			
		}
		
		void insertAtPosition(int pdata, int pos){
			Node *tempNode=new Node();
			tempNode->data=pdata;
			if(pos<0 || pos>countList()){
				cout<<"Position is out of range"<<endl;	
			}
			else if(pos==0){
				tempNode->next=head;
				head=tempNode;
			}else{
				Node *iterator=head;
				while(pos>1){
					iterator=iterator->next;
					--pos;
				}
				tempNode->next=iterator->next;
				iterator->next=tempNode;
			}
		}
		
		void deleteAtPosition(int pos){
			int p=pos;
			if(pos<0 || pos>countList()){
				cout<<"Position is out of range"<<endl;	
			}
			else if(head==NULL){
				cout<<"Your Linked List is already empty..."<<endl;
			}
			else
			{
				Node *tempNode, *iterator;
				if(pos==0){
					cout<<p<<". element "<<tempNode->next->data<<" deleted"<<endl;
					iterator=head;
					head=head->next;
					delete(iterator);
				}
				else
				{
					tempNode=iterator=head;
					while(pos>0){
						--pos;
						tempNode=iterator;
						iterator=iterator->next;
					}
					cout<<p<<". element "<<iterator->data<<" deleted"<<endl;
					tempNode->next=iterator->next;
					delete(iterator);
				}
			}
			
		}
		
		void printList(){
			if (head==NULL){
				cout<<"List is empty..."<<endl;
			}else{
				Node *tempNode=head;
				cout<<"Your Linked List is:";
				while(tempNode!=NULL)
				{
					cout<<tempNode->data<<"->";
					tempNode=tempNode->next;
				}
				cout<<"End of List"<<endl;
			}
			
		}
	
};
