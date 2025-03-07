#include <iostream>
#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {

    if (head == nullptr) {
        smaller = larger = nullptr;
        return;
        
    }
    

    if(head->val > pivot) {
        larger = head;
        head = head->next;
        llpivot(head, smaller, larger->next, pivot);
    } else {
        smaller = head;
        head = head->next;
        // smaller = 
        llpivot(head, smaller->next, larger, pivot);
    }

    // head = head->next;
        // if (head->val > pivot) {
        //     // pass by reference so no copy
        //     // larger = head;
        //     // std::cout << larger->val << std::endl;

        //     // std::cout << larger->val << std::endl;
        //     // std::cout << smaller->val << std::endl;
        //     llpivot(head->next, smaller, head, pivot);
        //     // std::cout << head->val << std::endl;
        //     // if (head->next) {
        //     //     std::cout << larger->val <<  " --> " << head->next->val << std::endl;
        //     // } else {
        //     //     std::cout << larger->val <<  " -->  null" << std::endl;
        //     // }

        //     // larger = head;
        //     larger->next = head->next;
        // } else {
        //     smaller = head;
        //     llpivot(head->next, head, larger, pivot);
        //     smaller->next = head->next;
        // }
        

    

}

