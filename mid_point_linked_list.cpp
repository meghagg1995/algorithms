Node *midPoint(Node *head)
{
    if(!head) return head;
    Node* node = head;
    while(node->next && node->next->next) {
        head = head->next;
        node = node->next->next;
    }
    return head;
}

Node *midPoint(Node *head)
{
    if(!head) return head;
    Node* node = head->next;
    while(node && node->next->next) {
        head = head->next;
        node = node->next->next;
    }
    return head;
}
