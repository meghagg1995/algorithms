class Node {
  public:
  int data;
  Node* next;
  Node(int data) : data{data}, next(NULL) {}
};

void print(Node* head) {
    while(head) {
        std::cout << head->data << std::endl;
        head = head -> next;
    }
}

void print(Node* head) {
    if(!head) return;
    std::cout << head->data << std::endl;
    print(head->next);
}

int length(Node *head)
{
    int len = 0;
    while(head) {
        head = head -> next;
        len += 1;
    }
    return len;
}

void printIthNode(Node *head, int i)
{
    while(i > 0 && head) {
        head = head->next;
        i--;
    }
    if(head) cout << head->data << endl;
}

Node* insertNode(Node* head, int pos, int data) {
    Node* temp = head;
    if(pos == 0) {
        Node* n = new Node(data);
        n->next = head;
        return n;
    }
    pos--;
    while(head && pos > 0) {
        pos--;
        head = head->next;
    }
    if(head) {
        Node* n = new Node(data);
        n->next = head->next;
        head->next = n;
    }
    return temp;
}

Node *deleteNode(Node *head, int pos)
{
    if(!head) return head;
    Node* original = head;
    if(pos == 0) {
        Node* temp = head->next;
        delete head;
        return temp;
    }
    pos--;
    while(head && pos > 0) {
        head = head->next;
        pos--;
    }
    if(head && head->next) {
        Node* del = head->next;
        head->next = head->next->next;
        delete del;
    }
    return original;
}

Node* insertNode(Node *head, int i, int data) {
    if(pos == 0) {
        Node* n = new Node(data);
        n->next = head;
        return n;
    }
    if(!head) return head;
    head->next = insertNode(head->next, i-1, data);
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
    if(head && pos == 0) return head->next;
    if(!head) return head;
	head->next = deleteNodeRec(head->next, pos-1);
    return head;
}
