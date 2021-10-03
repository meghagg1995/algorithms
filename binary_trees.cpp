#include <stack>
#include <queue>

void zigZagOrder(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> q;
    stack<int> s;
    q.push(root);
    int dir = 0;
    while(!q.empty()) {
        /* common mistake to take q.size() in loop directly */
        int n = q.size();
        for(int i=0;i<n;i++) {
            BinaryTreeNode<int>* current = q.front();
            q.pop();
            if(dir == 0) {
                cout << current->data << " ";
            }else {
                s.push(current->data);
            }
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        if(dir == 1) {
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
            dir = 0;
        }else {
            dir = 1;
        }
        cout << endl;
    }
}

class Codec {
public:
    string serialize(TreeNode* root) {
        string serializedTree = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current) {
                serializedTree += to_string(current->val);
                q.push(current->left);
                q.push(current->right);
            }else {
                serializedTree += "N";
            }
            if(!q.empty()) serializedTree += ',';
        }
        return serializedTree;
    }
    TreeNode* getToken(string& data, int& start) {
        if(data[start] == 'N') {
            start += 2;
            return NULL;
        }
        string currentToken = "";
        while(start < data.length() && data[start]!=',') {
            currentToken += data[start];
            start++;
        }
        start += 1;
        return new TreeNode(stoi(currentToken));
    }
    TreeNode* deserialize(string data) {
        if(data[0] == 'N') return NULL;
        int start = 0;
        queue<TreeNode*> q;
        TreeNode* root = getToken(data, start);
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            current->left = getToken(data, start);
            current->right = getToken(data, start);
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        return root;
    }
};

void printDownK(BinaryTreeNode<int> *root, int k) {
    if(!root) return;
    if(k == 0) {
        cout << root->data << endl;
        return;
    }
    printDownK(root->left, k-1);
    printDownK(root->right, k-1);
}

int getNode(BinaryTreeNode<int> *root, int node, int k) {
    if(!root) return -1;
    if(root->data == node) {
        printDownK(root, k);
        return 1;
    }
    int leftDistance = getNode(root->left, node, k);
    if(leftDistance != -1){
        if(leftDistance == k) {
            cout << root->data << endl;
        }else if(leftDistance < k) {
            printDownK(root->right, k-leftDistance-1);
        }
        return 1+leftDistance;
    }
    int rightDistance = getNode(root->right, node, k);
    if(rightDistance != -1) {
        if(rightDistance == k) {
            cout << root->data << endl;
        }else if(rightDistance < k) {
            printDownK(root->left, k-rightDistance-1);
        }
        return 1+ rightDistance;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    getNode(root, node, k);
}
