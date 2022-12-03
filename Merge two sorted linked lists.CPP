#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* temp1=head1, *temp2=head2;
    SinglyLinkedList *tempList =new SinglyLinkedList();
    while (temp1 && temp2){
        if(temp1->data < temp2->data){
            tempList->insert_node(temp1->data);
            temp1=temp1->next;
        }
        else if (temp1->data > temp2->data){
            tempList->insert_node(temp2->data);
            temp2=temp2->next;
        }
        else {
            tempList->insert_node(temp1->data);
            tempList->insert_node(temp2->data);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1){
        tempList->insert_node(temp1->data); 
        temp1=temp1->next;    
    } 
    while(temp2){
        tempList->insert_node(temp2->data);
        temp2=temp2->next;   
    } 
    return tempList->head;
}

int main()