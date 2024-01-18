#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;

    Node(int d){
        this->data = d;
        this->next = NULL;
    } 
};


void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* getMid(Node* &head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    cout<<"slow is "<<slow->data<<endl;
    return slow;
}

Node* reverse(Node* &head){
    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;

    while(curr != NULL){
       next = curr->next;
       curr->next = prev;
       prev = curr;
       curr = next;
    }
    return prev;
}

bool palindrome(Node* head){
    Node* middle = getMid(head);
    cout<<"middle is "<<middle->data<<endl; 
    Node* temp = middle->next;
    middle->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = middle->next;
    while(head2 != NULL){
        if(head1->data == head2->data){
            head1 = head1->next;
            head2 = head2->next;
        }else{
            return false;
        }
    }

    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}



main(){
    Node* node1 = new Node(1);
    Node* head = node1;

    Node* node2 = new Node(2);
    node1->next = node2;

    Node* node3 = new Node(3);
    node2->next = node3;

    Node* node4 = new Node(3);
    node3->next = node4;

    Node* node5 = new Node(2);
    node4->next = node5;

    Node* node6 = new Node(1);
    node5->next = node6;

    if(palindrome(head)){
        cout<<"LL is palindrome"<<endl;
    }else{
        cout<<"LL is not palindrome"<<endl;
    }

    print(head);
}