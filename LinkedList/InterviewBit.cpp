#include <iostream>
#include <chrono>
#include <thread>
#include <deque>

struct Node
{
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
    Node(int val, Node* nextNode) : data(val), next(nextNode) {}
};

Node* insertAtEnd(Node* head, int val)
{
    if(head == nullptr)
        return new Node(val);
    
    Node* curr{head};
    while(curr->next != nullptr)
        curr = curr->next;

    curr->next = new Node(val);
    return head;
}

Node* insertAtBeginning(Node* head, int val)
{
    Node* newNode = new Node(val, head);
    head = newNode;

    return head;
}

Node* reverseList(Node* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;
        
    Node *prevNode{head}, *currNode{prevNode->next}, *nextNode{currNode->next};
    prevNode->next = nullptr;
    currNode->next = prevNode;
    
    while(nextNode != nullptr)
    {
        prevNode = currNode;
        currNode = nextNode;
        nextNode = currNode->next;
        currNode->next = prevNode;
    }
    
    head = currNode;
    
    return head;
}

void traverseLinkedList(Node* head)
{
    Node* curr{head};
    while(curr != nullptr)
    {
        std::cout << curr->data << ", ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

Node* sortedMerge(Node* a, Node* b)  
{  
    Node *l1, *l2, *head, *temp{nullptr};
    if(a->data < b->data)
    {
        l1 = a;
        l2 = b;
    }
    else
    {
        l1 = b;
        l2 = a;
    }
    
    head = l1;
    l1 = l1->next;
    
    while(l1 != nullptr)
    {
        if(l1->data < l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            
            Node *tmp{l1};
            l1 = l2;
            l2 = tmp;
        }
    }
    
    if(temp != nullptr)
        temp->next = l2;
    
    return head;
}  

bool palindromeList(Node* A)
{
    Node *temp{A};
    int totElems{0};
    std::deque<int> elems;

    while (temp != nullptr)
    {
        elems.push_back(temp->data);
        temp = temp->next;
    }

    while (elems.size() > 1)
    {
        if(elems.front() != elems.back())
            return false;

        elems.pop_back();
        elems.pop_front();
    } 
    
    return true;
}

bool palindromeListO1(Node* A)
{
    Node *s{A}, *f{A}, *previous{A};

    while(f != nullptr && f->next != nullptr)
    {
        previous = s;
        s = s->next;
        f = f->next->next;
    }

    Node *firstHalfEnd{nullptr}, *secondHalfStart{nullptr};

    if(f == nullptr)
    {
        firstHalfEnd = previous;
        secondHalfStart = s;
    }
    else
    {
        firstHalfEnd = s;
        s = s->next;
        secondHalfStart = s;
    }

    firstHalfEnd->next = nullptr;

    Node* secondHead = reverseList(secondHalfStart);

    Node* temp1{A}, *temp2{secondHead};

    traverseLinkedList(temp1);
    traverseLinkedList(temp2);

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if(temp1->data != temp2->data)
            return false;

        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return true;
}

Node* partition(Node* A, int B) {
    if(!A)
        return nullptr;

    Node *lesserStart = new Node(0);
    Node *equalStart = new Node(0);
    Node *greaterStart = new Node(0);

    Node *lesser = lesserStart;
    Node *equal = equalStart;
    Node *greater = greaterStart;
    Node *curr{A};

    Node* head{nullptr};

    while(curr)
    {
        if(curr->data < B)
        {
            lesser->next = curr;
            if(head == nullptr) head = curr;
            curr = curr->next;
            lesser = lesser->next;
        }
        else if(curr->data > B)
        {
            greater->next = curr;
            if(head == nullptr) head = curr;
            curr = curr->next;
            greater = greater->next;
        }
        else
        {
            equal->next = curr;
            if(head == nullptr) head = curr;
            curr = curr->next;
            equal = equal->next;
        }
    }

    lesser->next = (equalStart->next)? equalStart->next : greaterStart->next;
    equal->next = greaterStart->next;
    greater->next = nullptr;


    delete(lesserStart);
    delete(equalStart);
    delete(greaterStart);

    return head;
}

int main(int argc, char const *argv[])
{
    Node *head1{nullptr}, *head2{nullptr}, *head3{nullptr};

    // head1 = insertAtEnd(head1, 8);
    // head1 = insertAtEnd(head1, 1);
    // head1 = insertAtEnd(head1, 4);
    // head1 = insertAtEnd(head1, 2);
    // head1 = insertAtEnd(head1, 1);

    traverseLinkedList(head1);

    head2 = reverseList(head1);

    traverseLinkedList(head2);

    // if(palindromeListO1(head1))
    //     std::cout << "It's a palindrome list" << std::endl;
    // else
    //     std::cout << "It's not a palindrome list" << std::endl;


    // // head2 = insertAtEnd(head2, 2);
    // // head2 = insertAtEnd(head2, 3);
    // // head2 = insertAtEnd(head2, 20);

    // // traverseLinkedList(head2);

    // // head3 = sortedMerge(head1, head2);

    // // traverseLinkedList(head3);

    return 0;
}
