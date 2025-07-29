#include <iostream>
using namespace std;

class ListNode{
public: 
    int data;
    ListNode* next;

    ListNode(int val){
        this->data = val;
        this->next = nullptr;
    }
};

ListNode* middleNode(ListNode* head) {
        // optimal solution: 
        // fast tortoise slow tortoise 
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
void printList(ListNode* head){
    while (head != nullptr){
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

ListNode* reverseList(ListNode* head){
    ListNode *prev = nullptr, *curr = head, *next;
    while (curr != nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);

    printList(head);
    head = reverseList(head);
    printList(head);
}
