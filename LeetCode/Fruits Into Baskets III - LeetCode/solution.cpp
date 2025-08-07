struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

void initTree(Node* root, vector<int>& baskets, int left, int right){
    // Taking a vector we will devide the vector from middle and call recersively until left == right


    root->val = *max_element(baskets.begin()+left,baskets.begin()+ right + 1);



    //Base
    if(left == right) return;

    root->left = new Node();
    root->right = new Node();
    initTree(root->left,baskets,left,((right-left)/2 )+left );
    initTree(root->right,baskets,((right-left)/2) + left + 1,right);




}


void update(Node* root,int fruit){
    // we now that root is sufficient
    // fruit will be placed definietly
    // after placement we need to remove the connection
    // we can do this by turning into -1


    if(root->left != nullptr && root->left->val >= fruit){

        update(root->left,fruit);

        if(root->right == nullptr) 
            root->val = root->left->val;
        else root->val = max(root->left->val,root->right->val);


    }
    else if(root->right != nullptr && root->right->val >= fruit){

        update(root->right,fruit);

        if(root->left == nullptr) 
            root->val = root->right->val;
        else root->val = max(root->left->val,root->right->val);


    }
    else root->val = -1;

}

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        Node* root = new Node();
        initTree(root,baskets,0,baskets.size()-1);
        int result = 0;

        for(int f : fruits){


            if(f> root->val) result++;
            else update(root,f);

        }
        return result;
    }
};