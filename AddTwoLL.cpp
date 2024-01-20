#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next = NULL;

    Node(int d){
        this->data  = d;
    }    
};

void insert(Node* &head, int data) {
        Node* newNode = new Node(data);
        if(head == NULL)
            head = newNode;
        else{
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }cout<<endl;
}

Node* reverse(Node* &head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;
}

Node* add(Node* &first, Node* &second){
    int carry =  0;
    Node* head = NULL;
    Node* tail = NULL;

    while(first != NULL || second != NULL || carry != 0){
    
        int val1 = 0;
        if(first != NULL){
            val1 = first->data;
            //cout<<"val1 "<< val1 <<" "<<endl;
        }

        int val2 =0;
        if(second != NULL){
            val2 = second->data;
        }

        int sum = carry + val1+ val2;
        int digit = sum % 10;
    
        insert(head, digit);
        carry = sum / 10;
        
        if(first != NULL)
            first = first->next;

        if(second != NULL)
            second = second->next;

    }
    return head;
}


Node*  addTwoLL(Node* &first, Node* &second){
    first = reverse(first);
    second = reverse(second);

    Node* ans = add(first,second);

    ans = reverse(ans);
    return ans;
}

main(){
    Node* head1 = new Node(3);
    insert(head1,4);
    insert(head1,5);

    Node* head2 = new Node(6);
    insert(head2, 7);
    insert(head2, 8);
    insert(head2, 9);
    
    
    cout<<"First Linked List"<<endl;
    print(head1);
    cout<<"Second Linked List"<<endl;
    print(head2);

    Node* ans = addTwoLL(head1,head2);

    cout<<"Added LL"<<endl;
    print(ans);

}