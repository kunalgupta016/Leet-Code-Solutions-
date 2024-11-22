#include<map>

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
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

TreeNode<int>* solve(vector<int> inorder, vector<int> postorder,int inorderStart ,int inorderEnd , int n ,int &index,map<int,int> &nodeToIndex){
    
    // index preorder ka index hai

    // base case
    if(index<0 || inorderStart>inorderEnd){
        return NULL;
    }


    // element le liye preoder ka 
    int element = postorder[index--];
    // us element ki ek node bna li
    TreeNode<int>* root = new TreeNode<int>(element);
    // ab us element ko inorder me find karenge using map 
    int position = nodeToIndex[element];

    
    // ab us position ke ek baad se end tak right ki call 
    root->right = solve(inorder,postorder,position+1,inorderEnd,n,index,nodeToIndex);
    // ab us position ke ek phle tk left ki call 
    root->left = solve(inorder, postorder, inorderStart,position-1, n, index,nodeToIndex);
    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder){
	
     int n = inOrder.size();
	int postOrderIndex = n-1;
     map<int,int> nodeToIndex;
     createMapping(inOrder,n,nodeToIndex);
     TreeNode<int>* ans = solve(inOrder,postOrder,0,n-1,n,postOrderIndex,nodeToIndex);
     return ans;



}
