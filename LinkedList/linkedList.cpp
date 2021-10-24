#include <iostream>

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

Node* deleteFirstNode(Node* head)
{
    if(head == nullptr || head->next == nullptr)
        return nullptr;
    
    Node* temp{head};
    head = head->next;

    delete(temp);
    temp = nullptr;

    return head;
}

Node* deleteLastNode(Node* head)
{
    if(head == nullptr || head->next == nullptr)
        return nullptr;

    Node* curr{head};
    while(curr->next->next != nullptr)
        curr = curr->next;

    Node* temp{curr->next};
    curr->next = nullptr;

    delete temp;
    temp = nullptr;

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

int main(int argc, char const *argv[])
{
    Node* head{nullptr};

    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);

    head = insertAtBeginning(head, 0);
    head = insertAtBeginning(head, -1);

    traverseLinkedList(head);

    head = deleteFirstNode(head);

    traverseLinkedList(head);

    head = deleteLastNode(head);
    head = deleteLastNode(head);

    traverseLinkedList(head);

    return 0;
}
