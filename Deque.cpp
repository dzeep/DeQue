#include "Deque.h"



///------------------------------------------------------
/// Default constructor
/// 
Deque::Deque() {
	// Fill this in
	this->head = this->tail = NULL;
	this->noOfItems = 0;

} //end-Deque

///------------------------------------------------------
/// Destructor
/// 
Deque::~Deque() {
	// Fill this in
	while (this->head) {
		DequeNode* node = head;
		this->head = this->head->next;
		delete node;	
	}	
} //end-~Deque

///------------------------------------------------------
/// Adds a new item to the front of the Deque
/// 
void Deque::AddFront(int item) {
	if (this->noOfItems == 0) {
		this->head = new DequeNode(0);
		this->head->item = item;
		this->head->prev = NULL;
		this->head->next = NULL;

		this->tail = new DequeNode(0);
		this->tail->item = item;
		this->tail->prev = NULL;
		this->tail->next = NULL;
		this->noOfItems = 1;
	}
	else if (this->noOfItems == 1) {
		DequeNode* node = new DequeNode(0);
		node->item = item;
		node->next = this->head;
		node->prev = NULL;
		this->head = node;
		

		this->tail->prev = this->head;
		this->head->next = this->tail;
		this->noOfItems++;
	}
	else {
		DequeNode* node = new DequeNode(0);
		node->item = item;
		node->next = this->head;
		node->prev = NULL;
		this->head = node;

		this->head->next->prev = this->head;
		this->noOfItems++;
	}

} //end-AddFront

///------------------------------------------------------
/// Adds a new item to the end of the Deque
/// 
void Deque::AddRear(int item) {
	// Fill this in
	if (this->noOfItems == 0) {
		this->head = new DequeNode(0);
		this->head->item = item;
		this->head->prev = NULL;
		this->head->next = NULL;

		this->tail = new DequeNode(0);
		this->tail->item = item;
		this->tail->prev = NULL;
		this->tail->next = NULL;
		this->noOfItems = 1;
	}
	else if (this->noOfItems == 1) {
		DequeNode* node = new DequeNode(0);
		node->item = item;
		node->next = NULL;
		node->prev = this->tail;
		this->tail = node;

		this->head->next = this->tail;
		this->noOfItems++;
	}
	else {
		DequeNode* node = new DequeNode(0);
		node->item = item;
		node->next = NULL;
		node->prev = this->tail;
		this->tail = node;

		this->tail->prev->next = this->tail;
		this->noOfItems++;
	}
} //end-AddRear

///------------------------------------------------------
/// Remove and return the item at the front of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveFront() {
	// Fill this in
	if (IsEmpty()) throw ("Deque::Front: Empty Deque");

	int node = this->head->item;
	if (this->noOfItems == 1) {
		this->head = this->tail = NULL;
		noOfItems = 0;
	}
	else if (this->noOfItems == 2) {
		this->head = this->tail;
		this->head->next = this->tail->prev = NULL;
		noOfItems--;
	}
	else
	{
		this->head = this->head->next;
		this->head->prev = NULL;
		noOfItems--;
	}
	return node;
} //end-RemoveFront

///------------------------------------------------------
/// Remove and return the item at the rear of the Deque
/// If the Deque is empty, throw an exception
/// 
int Deque::RemoveRear() {
	// Fill this in
	if (IsEmpty()) throw ("Deque::Rear: Empty Deque");

	int node = this->tail->item;
	if (this->noOfItems == 1) {
		this->head = this->tail = NULL;
		noOfItems = 0;
	}
	else if (this->noOfItems == 2) {
		this->tail = this->head;
		this->head->next = this->tail->prev = NULL;
		noOfItems--;
	}
	else
	{
		this->tail = this->tail->prev;
		this->tail->next = NULL;
		noOfItems--;
	}
	return node;
} //end-RemoveRear

///------------------------------------------------------
/// Return the item at the front of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Front() {
	// Fill this in
	return this->head->item;
} //end-Front

///------------------------------------------------------
/// Return the item at the rear of the Deque (do not remove the item)
/// If the Deque is empty, throw an exception
/// 
int Deque::Rear() {
	// Fill this in
	return this->tail->item;
} //end-Rear