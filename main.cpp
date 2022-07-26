#include <iostream>
#include "LinkedList.h"
using namespace std;
int main(int argc, char** argv) {
	LinkedList *LList=new LinkedList();
	LList->insertFirst(50);
	LList->insertEnd(90);
	LList->insertEnd(10);
	LList->insertEnd(70);
	LList->insertEnd(80);
	LList->insertEnd(30);
	LList->printList();
	LList->deleteAtPosition(2);
	LList->printList();
	return 0;
}
