#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Solution{
    public:
    Node* insertAtEnd(Node* head, int x){
        if(head == NULL){
            return new Node(x);
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new Node(x);
        return head;
    }
    void printList(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main(){
    Solution obj;
    Node* head = NULL;
    int n, x;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> x;

        head = obj.insertAtEnd(head, x);
    }
    cout << "Linked List: ";
    obj.printList(head);

    return 0;
}