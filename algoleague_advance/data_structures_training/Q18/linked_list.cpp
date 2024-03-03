#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

void insert(Node* &head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if(head != NULL) head->prev = newNode;
    head = newNode;
}

void deleteNode(Node* &head,Node* &start_node){
    if(head == NULL) return;
    else if(head->prev == NULL){
        if(head->next != NULL) {
            start_node = head->next;
            head->next->prev = NULL;
            head->next = NULL;
        }
        else head = NULL;
    }
    else if(head->next == NULL){
        head->prev->next = NULL;
        head->prev = NULL;
    }
    else{
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head->next = NULL;
        head->prev = NULL;
    }
}

int32_t main(){

    int n,k; cin>>n>>k;
    Node* head = NULL;
    for(int i = n;i>0;i--) insert(head,i);


    Node* temp = head;
    int remaining = n;
    int k_counter = 0;
    int val_k = k%n;


    while(remaining>1){
        if(temp == NULL) temp = head;
        if(k_counter == val_k){
            // deletion
            cout<<temp->data<<" ";
            Node* temp2;
            if(temp->next!=NULL) temp2 = temp->next;
            else temp2 = head;
            deleteNode(temp,head);
            temp = temp2;
            remaining--;
            val_k = k%remaining;
            k_counter = 0;
        }
        else{
            k_counter++;
            temp = temp->next;
        }
    }

    cout<<head->data;
}