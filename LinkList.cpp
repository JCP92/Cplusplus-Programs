//
//  main.cpp
//  HW Review
//
//  Created by Joshua Peckham on 12/4/16.
//  Copyright © 2016 Joshua Peckham. All rights reserved.
//

#include <iostream>
using namespace std;

class LinkList{
private:
    struct ListNode{
        ListNode *next;
        int value;
    };
    ListNode *head;
    int nodeCounter(ListNode *n)const;
    void reversePrint(ListNode *) const;
    
public:
    LinkList(){
        head = nullptr;
    }
    ~LinkList(){
        ListNode *pp = head;
        ListNode *np;
        
        while(pp != nullptr){
            np = pp->next;
            delete pp;
            pp = np;
        }
    }
    void delNode(int num){
        ListNode *ppntr = nullptr;
        ListNode *npntr = head;
        if(!head){
            return;
        }
        
        if(head->value == num){
            npntr = head->next;
            delete head;
            head = npntr;
        }
        else
            while( npntr != nullptr && npntr->value != num){
                ppntr = npntr;
                npntr = npntr->next;
            }
        if(npntr->value == num){
            ppntr->next = npntr->next;
            delete npntr;
        }
    }
    void append(int num){
        ListNode *newNode;
        ListNode *pntr;
        
        newNode = new ListNode;
        newNode->value = num;
        newNode->next = nullptr;
        
        if(!head){
            head = newNode;
        }
        else{
            pntr = head;
            
            while(pntr->next)
                pntr = pntr->next;
            
            pntr->next = newNode;
        }
    }
    void insert(int num){
        ListNode *newNode;
        ListNode *pp = nullptr;
        ListNode *np;
        
        newNode = new ListNode;
        newNode->value = num;
        
        if(!head){
            head = newNode;
            newNode->next = nullptr;
        }
        else{
            np = head;
            while(np != nullptr && np->value < num){
                pp = np;
                np = np->next;
            }
            if(pp == nullptr){
                head = newNode;
                newNode->next = np;
            }
            else{
                pp->next = newNode;
                newNode->next = np;
            }
        }
    }
    void view() const{
        ListNode *pntr = head;
        if(!head){
            cout << "Empty List" << endl;
        }
        while(pntr != NULL){
            cout << pntr->value << " ";
            pntr = pntr->next;
        }
        cout << endl << "End List " << endl;
    }
    int nodeCounter()const{
        nodeCounter( head );
        cout << endl;
        return 0;
    }
    void reversePrint() const{
        reversePrint(head);
        0;
    }
};

int main() {
    LinkList m;
    
    m.view();
    m.append(30);
    m.view();
    m.insert(25);
    m.insert(78);
    m.reversePrint();
    cout << m.nodeCounter() << endl;
    m.view();
    m.delNode(25);
    m.view();
    cout << m.nodeCounter() << endl;
    
    m.reversePrint();
    
    return 0;
}

int LinkList::nodeCounter(ListNode *ptr) const{
    if(ptr != nullptr){
        return (1 + nodeCounter(ptr->next));
    }
    else
        return 0;
}
void LinkList::reversePrint(ListNode *pntr) const{
    if(pntr != nullptr){
        reversePrint((pntr->next));
        cout << pntr->value << " ";
    }
    
}
























