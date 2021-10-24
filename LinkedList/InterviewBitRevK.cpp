#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

std::pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail)
{
    if(head == nullptr || head->next == nullptr)
        return std::make_pair(head, head);

    ListNode* tempHead{head};
        
    ListNode *prevNode{head}, *currNode{prevNode->next}, *nextNode{currNode->next};
    prevNode->next = nullptr;
    currNode->next = prevNode;
    
    while(currNode != tail)
    {
        prevNode = currNode;
        currNode = nextNode;
        nextNode = currNode->next;
        currNode->next = prevNode;
    }
    
    head = currNode;
    tail = tempHead;
    
    return std::make_pair(head, tail);
}

ListNode* solve(ListNode* A, int B) {
    int cnt{1}, i{0};
    ListNode *curr{A}, *temp{A}, *head{A}, *tail{A}, *globHead{nullptr}, *lastTail({nullptr});

    while(temp != nullptr)
    {
        temp = temp->next;
        std::cout << curr->val << ", ";
        if(lastTail != nullptr) std::cout << lastTail->val << std::endl;
        else std::cout << std::endl;

        if(cnt % B == 0)
        {
            if(i % 2 == 0)
            {
                std::pair<ListNode*, ListNode*> headTail = reverseList(head, tail);
                if(globHead == nullptr)
                    globHead = headTail.first;
                
                headTail.second->next = temp;
                if(lastTail != nullptr)
                    lastTail->next = headTail.first;
            }
            else
            {
                lastTail = curr;
            }
            head = temp;
            tail = temp;
            i++;

        }
        else
            tail = tail->next;

        cnt++;
        curr = temp;
    }

    return globHead;
}

void traverseLinkedList(ListNode* head)
{
    ListNode* curr{head};
    while(curr != nullptr)
    {
        std::cout << curr->val << ", ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

ListNode* insertAtEnd(ListNode* head, int val)
{
    if(head == nullptr)
        return new ListNode(val);
    
    ListNode* curr{head};
    while(curr->next != nullptr)
        curr = curr->next;

    curr->next = new ListNode(val);
    return head;
}

ListNode* swapPairs(ListNode* A) {
    if(A == nullptr || A->next == nullptr)
        return A;

    ListNode *head{A}, *tail{A->next};
    ListNode *curr{A->next->next};

    tail->next = head;
    head->next = nullptr;
    ListNode* globHead = tail;
    ListNode* lastTail = head;

    while(curr != nullptr)
    {
        head = curr,
        tail = curr->next;
        
        if(tail != nullptr)
        {
            curr = curr->next->next;
            tail->next = head;
            lastTail->next = tail;
            head->next = curr;
        }
        else
        {
            curr = curr->next;
            lastTail->next = head;
        }
        
        lastTail = head;
    }

    return globHead;
}


int main(int argc, char const *argv[])
{
    ListNode *head1{nullptr}, *head2{nullptr}, *head3{nullptr};

    head1 = insertAtEnd(head1, 1);
    head1 = insertAtEnd(head1, 2);
    head1 = insertAtEnd(head1, 3);
    head1 = insertAtEnd(head1, 4);
    head1 = insertAtEnd(head1, 65);
    head1 = insertAtEnd(head1, 63);
    head1 = insertAtEnd(head1, 6);
    head1 = insertAtEnd(head1, 46);
    head1 = insertAtEnd(head1, 28);
    head1 = insertAtEnd(head1, 82);
    head1 = insertAtEnd(head1, 83);

    traverseLinkedList(head1);

    head1 = swapPairs(head1);
    traverseLinkedList(head1);
    return 0;
}
