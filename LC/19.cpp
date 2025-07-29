#include <iostream>
using namespace std;

class ListNode {
public: 
    int data;
    ListNode* next;
    
    ListNode(int val){
        this->data = val;
        this->next = nullptr;
    }
};

void printList(ListNode *head){
    ListNode *temp = head;
    while (temp != nullptr){
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}

ListNode* reverseList(ListNode *head){
    ListNode *prev = nullptr, *curr = head, *next;

    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

void removeNthFromEnd(ListNode *head, int n){
    // reverse it and remove nth node from start
    head = reverseList(head);
    ListNode *nth = head, *prev = nullptr;
    // when reaching the nth node
    // store next's pointer in a var 
    // go to one before 
    // give it next's pointer
    if (n == 1){
        head = head->next;
        reverseList(head);
        return;
    }

    for (int i = 0; i < n-1; i++){
        prev = nth;
        nth = nth->next;
    }
    // make prev -> nth-> next
    prev->next = nth->next; 
    // reverse it again
    printList(head);
    head = reverseList(head);

}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 5;
    printList(head);
    removeNthFromEnd(head, n);
    printList(head);
}
