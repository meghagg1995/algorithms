int len(Node* head) {
    return head ? 1 + len(head->next) : 0;
}

/* O(2 * L) */
Node *nthNodeFromEnd(Node *head, int n)
{
    int pos = len(head) - n;
    while(head && pos > 0) {
        head = head->next;
        pos--;
    }
    return head;
}

/* O(L + (L-N+1)) = O(L) */
Node *nthNodeFromEnd(Node *head, int n)
{
    Node* ptr1 = head;
    Node* ptr2 = head;
    while(n > 0) {
        ptr1 = ptr1->next;
        n--;
    }
    while(ptr1) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return ptr2;
}
