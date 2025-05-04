/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Node{
public:
    int val;
    Node* right;
    Node(int _val){
        val = _val;
        right = nullptr;
    }
};

class LL{
public:
    Node* head;
    Node* temp;
    LL(){
        head = new Node(0);
        temp = head;

    }

    void add(int val){
        temp->right = new Node(val);
        temp = temp->right;
    }

    int next(){
        head = head->right;
        return head->val;
    }

    bool hasNext(){
        if(head->right != nullptr) return true;
        return false;
    }
};

void search(TreeNode* root,LL* ll){
    if(root == nullptr) return;
    if(root->left != nullptr) search(root->left,ll);
    ll->add(root->val);
    if(root->right != nullptr) search(root->right,ll);
}

class BSTIterator {
public:
    LL* ll;
    BSTIterator(TreeNode* root) {
        ll = new LL();
        search(root,ll);
    }
    
    int next() {
        return ll->next();
    }
    
    bool hasNext() {
        return ll->hasNext();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */