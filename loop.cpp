#include<iostream>
#include<map>

using namespace std;

class Node{
    public:
    int data;
    Node* next ;

    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

bool detectLoop(Node* &head){
    map<Node*, bool> visited;
    Node* curr = head;

    while(curr->next != NULL){
        if(visited[curr] == true){
            return true;
            //cout<<"There is a Loop in LL "<<endl;
        }else{
            visited[curr] = true;
            curr = curr->next;
        }
    }
    //cout<<"There is no Loop in LL"<<endl;
    return false;
}

Node* floydCycleDetection(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && slow != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(fast == slow){
            //cout<<"loop present at "<<slow->data<<endl;
            return slow;
        }
    }
    return NULL;
}

Node* loopingNode(Node* &head){
    Node* startofLoop = floydCycleDetection(head);
    Node* fast = head;

    while(fast != startofLoop){
        fast = fast->next;
        startofLoop = startofLoop->next;
    }

    return fast;

}

void removeLoop(Node* &head){
    Node* loopStart = loopingNode(head);
    Node* temp = loopStart;

    while(temp->next != loopStart){
        temp = temp->next;
    }
    temp->next = NULL;
}



void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

main(){

    Node* node1 = new Node(3);
    Node* head = node1;

    Node* node2 = new Node(5);
    node1->next = node2;

    Node* node3 = new Node(7);
    node2->next = node3;

    Node* node4 = new Node(9);
    node3->next = node4;

    Node* node5 = new Node(11);
    node4->next = node5;

    Node* node6 = new Node(13);
    node5->next = node6;

    node6->next = node2;

    // if(detectLoop(head)){
    //     cout<<"Loop present "<<endl;
    // }else{
    //     cout<<"Loop not present ";
    // }

    if(floydCycleDetection(head)){
        cout<<"Loop present "<<endl;
    }else{
        cout<<"Loop not present "<<endl;
    }

    Node * loop = loopingNode(head);
    cout<<"Loop starting is: "<<loop->data<<endl;; 

    removeLoop(head);

    cout<<"after removing loop: "<<endl;
    print(head);

}