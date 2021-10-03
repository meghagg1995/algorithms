/* Recursive */
Node *reverseLinkedListRec(Node *head)
{
    if(!head || !head->next) return head;
    Node* temp = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

/* Iterative */
Node *reverseLinkedList(Node *head) {
    if(!head || !head->next) return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr) {
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
