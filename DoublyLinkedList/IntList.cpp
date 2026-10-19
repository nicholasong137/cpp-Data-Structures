#include<iostream>
#include<string>
#include "IntList.h"
using namespace std;

IntList::IntList() {
    dummyHead->next = dummyTail;
    dummyHead->prev = nullptr;
    
    dummyTail->prev = dummyHead;
    dummyTail->next = nullptr;
}

IntList::~IntList() {
    IntNode* currNode = dummyHead;
    while (currNode != nullptr) {
        IntNode* nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }

    cout << "Destructor called, memory freed" << endl;
}

void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* tmpNode = nullptr;

    tmpNode = dummyHead->next;
    dummyHead->next = newNode;
    newNode->prev = dummyHead;

    newNode->next = tmpNode;
    tmpNode->prev = newNode;

    tmpNode = nullptr;
}

void IntList::pop_front() {
    IntNode* currNode = nullptr;
    IntNode* tmpNode = nullptr;

    if (dummyHead->next == dummyTail) {
        return;
    } else {
        currNode = dummyHead->next;
        tmpNode = currNode->next;

        dummyHead->next = tmpNode;
        tmpNode->prev = dummyHead;

        delete currNode;
    }
}

void IntList::push_back(int value) {
    IntNode* newNode = new IntNode(value);
    IntNode* tmpNode = nullptr;

    tmpNode = dummyTail->prev;
    tmpNode->next = newNode;
    newNode->prev = tmpNode;

    newNode->next = dummyTail;
    dummyTail->prev = newNode;

    tmpNode = nullptr;;
}

void IntList::pop_back() {
    IntNode* currNode = nullptr;
    IntNode* tmpNode = nullptr;

    if (dummyHead->next == dummyTail) {
        return;
    } else {
        currNode = dummyTail->prev;
        tmpNode = currNode->prev;

        tmpNode->next = dummyTail;
        dummyTail->prev = tmpNode;

        delete currNode;

        tmpNode = nullptr;
    }
}

bool IntList::empty() const {
    if (dummyHead->next == dummyTail) {
        return true;
    } else {
        return false;    }
}

std::ostream & operator<<(ostream &out, const IntList &rhs) {
    IntNode* currNode = rhs.dummyHead->next;

    while (currNode != rhs.dummyTail) {
        out << currNode->data;
        if ( currNode->next != rhs.dummyTail) {
            out << " ";
        }
        currNode = currNode->next;
    }

    return out;
}

void IntList::printReverse() const {
    IntNode* currNode = dummyTail->prev;

    while (currNode != dummyHead) {
        cout << currNode->data;
        if (currNode->prev != dummyHead) {
            cout << " ";
        }

        currNode = currNode->prev;
    }
}