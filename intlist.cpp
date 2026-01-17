// intlist.cpp
// Implements class IntList
// Leila Stuart, January 15th,16th,17th 2026 

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor--I asked ChatGPT why there was a segmentation fault here,
//     explicitly telling it not to alter my code as per the allowed use of AI
//     tools expressed in the syllabus. It pointed out various lines that 
//     could lead to a segmentation fault, so I decided to just rewrite the 
//     copy constructor thinking more about when I call other functions like 
//     push_back. In the end, my issue was that I was not initializing head and
//     tail for the list that I wanted to copy to.  
IntList::IntList(const IntList& source) {
    if (source.head == nullptr) { 
	    head = nullptr; 
	    tail = nullptr; 
	    return;
    }

    head = nullptr; 
    tail = nullptr;

    Node* curr = source.head; 
    while (curr) {
	    push_back(curr->info); 
	    curr = curr->next; 
    }
    return; 
}

// destructor deletes all nodes
IntList::~IntList() {
    if (!head) {
	    return; 
    }

    Node* curr = head; 
    while (curr) {
	    Node* temp = curr->next;
	    delete curr; 
	    curr = temp; 
    }
    return;
}

// return sum of values in list
int IntList::sum() const {
    if (!head) {
	   return 0;
    }
    int sum = 0;
    Node* curr = head;  
    while (curr->next) {
	   sum = sum + curr->info;
	   curr = curr->next;
    }
    sum = sum + curr->info; 
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    if (!head) {
	   return false;
    }
    Node* curr = head;
    if (curr->info == value) {
	    return true; 
    }
    while (curr->next) {
	   if (curr->next->info == value) {
		  return true; 
	   }
	   curr = curr->next; 
    } 
    return false;  
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (!head) {
	    return 0; 
    } 
    int max = head->info; 
    Node* curr = head; 
    while (curr->next) {
	    if (curr->next->info > max) {
		    max = curr->next->info; 
	    }
	    curr = curr->next; 
    }
    return max; 
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int sum = this->sum(); 
    int count = this->count();
    if (count) {
    	    return sum / count;
    } else {
	    return 0; 
    }
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node{value, nullptr}; 
    if (!head) {
	    head = newNode;
	    tail = newNode; 
    } else {
	    Node* temp = head; 
	    this->head = newNode; 
	    newNode->next = temp; 
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
	    head = newNode;
	    tail = newNode;
    } else {
	    this->tail->next = newNode; 
	    this->tail = newNode;
    } 
}

// return count of values
int IntList::count() const { 
    int count = 0; 
    if (head == nullptr) {
	    return count; 
    }

    Node* curr = head; 
    while (curr != nullptr) {
	    count += 1; 
	    if (curr->next) {
		    curr = curr->next; 
	    } else {
		    return count; 
	    }
    }

    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //Deleting the list
    if (head) { 
    	Node* curr1 = head; 
    	while (curr1) {
	  	Node*temp = curr1->next; 
	  	delete curr1; 
	  	curr1 = temp; 
    	}
    }
    //Adding in the new values
    if (source.head == nullptr) {
	    head = nullptr; 
	    tail = nullptr; 
	    return *this; 
    }

    head = nullptr;
    tail = nullptr;

    Node* curr2 = source.head; 
    while (curr2) {
	    push_back(curr2->info);  
	    curr2 = curr2->next;
    }
    return *this; 
}

// constructor sets up empty list
IntList::IntList(){ 
    this->head = nullptr; 
    this->tail = nullptr;  
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

