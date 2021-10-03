/* Recursive Solution */
/* Time Complexity: O(min(n,m)) */
/* Space Complexity: O(min(hn, hm))
   - Worst Case: O(min(n,m))
   - Best Case: O(min(log(n),log(m))) 
*/
bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    if(root1->data != root2->data) return false;
    return areMirror(root1->left, root2->right) && 
           areMirror(root1->right, root2->left);
}

/* BFS : Iterative Solution */
bool areMirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;
    queue<BinaryTreeNode<int>*> q1;
    queue<BinaryTreeNode<int>*> q2;
    q1.push(root1);
    q2.push(root2);
    while(!q1.empty() && !q2.empty()) {
        BinaryTreeNode<int>* c1 = q1.front();
        BinaryTreeNode<int>* c2 = q2.front();
        q1.pop(); q2.pop();
        if(!c1 && !c2) continue;
        if(!c1 || !c2) return false;
        if(c1->data != c2->data) return false;
        q1.push(c1->left);
        q1.push(c1->right);
        q2.push(c2->right);
        q2.push(c2->left);
    }
    if(q1.empty() && q2.empty()) return true;
    return false;
}
