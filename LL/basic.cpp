#include<iostream>
#include<vector>
#include<cmath> 
#include<algorithm>
#include<set>
#include<string>
#include<map>
#include<unordered_map>
#include<cstring>
#include<stack>
#include<queue>

using namespace std;

#define ll long long

const int INF = 1e9+7;
const int mod = 1e9+7;
const int MAX = 1e5+5;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL){}
};

void append(ListNode** head, int num){
    ListNode* new_node = new ListNode(num);
    ListNode* last = *head;

    // If the Linked List is empty, then make the new node as head 
    if(*head == NULL){
        *head = new_node;
        return;
    }   

    while(last->next != NULL) // traverse till the last node
        last = last->next;

    last->next = new_node; // Change the next of last node
    return;
}

void insertAtStart(ListNode** head, int num){
    ListNode* new_node = new ListNode(num);

    new_node->next = *head;   // Make next of new node as head 

    *head = new_node; // move the head to point to the new node
}

void insertAfter(ListNode* prev, int num){
    if(prev == NULL)
        return;

    ListNode* new_node = new ListNode(num);
    // new_node->val = num;
    new_node->next = prev->next; // Make next of new node as next of prev_node
    prev->next = new_node; // move the next of prev_node as new_node
}


void deleteNode(ListNode** head, int key){
    ListNode* temp = *head, *prev;

    // If head node itself holds the key to be deleted
    if(temp != NULL && temp->val == key){
        *head = temp->next; // changed head
        free(temp); // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next' 
    while(temp != NULL && temp->val != key){
        prev = temp;
        temp = temp->next;
    }

    // if key is not present in LL
    if(temp == NULL)
        return;

    prev->next = temp->next; // unlink the node from LL
    free(temp); // free memory
}

void deletedNodeAtPos(ListNode **head, int pos){
    // if LL is empty
    if(*head == NULL)
        return;

    ListNode *temp = *head;

    if(pos == 0){ // if head to be removed
        *head = temp->next; // change head
        free(temp);
    }

    // find prev node of the node to be deleted
    for(int i = 0; temp != NULL && i < pos-1; ++i){
        temp = temp->next;
    }

    // if pos is more than the no of nodes
    if(temp == NULL || temp->next == NULL)
        return;

    ListNode* next = temp->next->next;
    free(temp->next);
    temp->next = next;  
}

bool search(ListNode* head, int key){
    if(head == NULL)
        return false;
    if(head->val == key)
        return true;
    return search(head->next, key);
}

void printList(ListNode* node){
    while(node != NULL){
        cout << " " << node->val;
        node = node->next;
    }
    cout << endl;
}

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ListNode *head = NULL;
    insertAtStart(&head, 6);
    insertAtStart(&head, 4);
    insertAtStart(&head, 3);
    insertAtStart(&head, 2);
    insertAtStart(&head, 1);
    printList(head);
    append(&head, 7);
    printlist(head);
    insertAfter(head->next->next->next, 5);    
    printList(head);
    insertAtStart(&head, 0);
    printList(head);
    deleteNode(&head, 0);
    printList(head);
    deletedNodeAtPos(&head, 5); // pos
    printList(head);
    cout << (search(head, 3)?"yes " : " no") << endl;

}