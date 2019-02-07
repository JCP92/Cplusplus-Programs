//
//  main.cpp
//  HW17
//
//  Created by Joshua Peckham on 11/1/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//

#include <iostream>
using namespace std;

class LinkList{
private:
    struct ListNode{
        int value;
        LinkList* next;
        LinkList* head;
    };
public:
    LinkList(){
        head = nullptr;
    }
    void appending( int n);
    void inserting( int n);
    void deletenode(int n);
    void print () const;
    ~LinkList();
    
};
void LinkList::appending( int n){
    ListNode* newNode = new ListNode; //initialize new node
    ListNode* nptr;  //temp pointer
    newNode->value = n; // sets value to n
    newNode->next = nullptr; // connects  new node to end of list
    
    if (!head){
        head = newNode;
        return;
    }
    else{
        nptr = head; // points to head of node
        while(nptr->next){ // look for last node
            nptr = nptr->next; //transition through till the end
        }
        nptr->next = newNode;
    }
}
void LinkList::inserting( int n){
    ListNode* newNode = new ListNode;
    ListNode* nptr, *pptr;
    pptr = nullptr;
    newNode->value = n;

    
    if (!head){ // head equals to nullptr
        head = newNode; // make head connect to new new node
        newNode->next = nullptr; // connext new node to null
        return;
    }
    else {
        nptr = head; //nodeptr connects to head
        pptr = nullptr; // previus pointer connected to null
    while( (nptr != nullptr) && ( newNode->value > nptr->value) ){ /*nptr goes through whole list and value is greater than new pointer value*/
        pptr = nptr;
        nptr = nptr->next;
        }
    }
    if (pptr == nullptr){
        head = newNode;
        newNode->next = nptr;
    }
    else{
        pptr->next = newNode;
        newNode->next = nptr;
    }
    
}
void LinkList::deletenode(int n){
    ListNode* nptr, *pptr = nullptr;
    
    if(!head)
        return;
    
    if(head->value == n){
        nptr = head->next;
        delete head;
        head = nptr;
    }
    else{
        nptr = head;
        while (nptr != nullptr && nptr->value != n){
            pptr = nptr;
            nptr = nptr->next;
        }
        if (nptr != nullptr){
            pptr->next = nptr->next;
            delete nptr;
        } 
    }
}

LinkList::~LinkList(){
    ListNode* nptr, *ptr;
    
    nptr = head;
    while (nptr != nullptr){
        ptr = nptr->next;
        delete nptr;
        nptr = ptr;
    }
}

void LinkList::print () const{
    ListNode* nptr = head;
    if ( head == nullptr){
        cout << "empty list" << endl;
    }
    else{
        while (nptr != nullptr){
        cout << nptr->value << "\t";
        nptr = nptr->next;
        }
    }
}



int main() {
    LinkList w;
    int n;
    w.print();
    cout << "Please append 5 values for the Nodes" << endl;
    for(int i = 0; i < 5; i++){
        cin >> n;
        w.appending(n);
    }
    cout << "The 5 apended values are: " << endl;
    w.print();
    cout << endl;
    
    cout << "Please instert a value " << endl;
    cin >> n;
    w.inserting(n);
    cout << endl;

    
    cout << "The new string is: " << endl;
    w.print();
    cout << endl;

    
    cout << "Please select a value to remove:" << endl;
    cin >> n;
    w.deletenode(n);
    
    cout << "The new string is: " << endl;
    w.print();
    cout << endl;


    
    return 0;
}


