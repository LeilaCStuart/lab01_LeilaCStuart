// intlist.cpp
// Implements class IntList
// Leila Stuart, January 15th,16th 2026 

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    return; //FINISH THIS
}

// destructor deletes all nodes
IntList::~IntList() {
    return; //FINISH THIS
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
    int count = 1; 
    Node* curr = nullptr; 

    if (head == nullptr) {
 	   return 0; 
    }

    curr = head; 
    if (curr == nullptr) {
	    return 0; 
    } else {
	    while (curr->next) {
		count += 1; 
		curr = curr->next;
	    }
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT THIS AFTER OTHERS 
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

