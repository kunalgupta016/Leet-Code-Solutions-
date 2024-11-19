/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

pair<int,int> Diameter(TreeNode<int>*root){
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = Diameter(root->left); //left subtree 
    pair<int,int> right = Diameter(root->right); // right subtree

    int op1 = left.first; // left subtree ki diameter
    int op2 = right.first; // right subtree ki diamter
    int op3 = left.second + right.second ; // diameter through adges

    pair<int,int> ans; 
    ans.first = max(op1, max(op2,op3)); // total diamter
    ans.second = max(left.second , right.second) + 1; // total height
    return ans;
}


int diameterOfBinaryTree(TreeNode<int> *root){
	return Diameter(root).first;
}
