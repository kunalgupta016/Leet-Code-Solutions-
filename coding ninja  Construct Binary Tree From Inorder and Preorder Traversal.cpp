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
void createMapping(vector<int> &inorder , int n , map<int,int> &nodeToIndex){
    for(int i=0;i<n;i++){
        nodeToIndex[inorder[i]] = i;
    }
}


TreeNode<int>* solve(vector<int> inorder, vector<int> preorder,int inorderStart ,int inorderEnd , int n ,int &index,map<int,int> &nodeToIndex){
    
    // index preorder ka index hai

    // base case
    if(index>=n || inorderStart>inorderEnd){
        return NULL;
    }


    // element le liye preoder ka 
    int element = preorder[index++];
    // us element ki ek node bna li
    TreeNode<int>* root = new TreeNode<int>(element);
    // ab us element ko inorder me find karenge using map 
    int position = nodeToIndex[element];

    // ab us position ke ek phle tk left ki call 
    root->left = solve(inorder, preorder, inorderStart,position-1, n, index,nodeToIndex);
    // ab us position ke ek baad se end tak right ki call 
    root->right = solve(inorder,preorder,position+1,inorderEnd,n,index,nodeToIndex);
    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{   
    int n = inorder.size();
	  int preOrderIndex = 0;
  // map banaya hai yha par
    map<int,int> nodeToIndex;
  // mapping kar di 
    createMapping(inorder,n,nodeToIndex);
    TreeNode<int>* ans = solve(inorder,preorder,0,n-1,n,preOrderIndex,nodeToIndex);
    return ans;
}
