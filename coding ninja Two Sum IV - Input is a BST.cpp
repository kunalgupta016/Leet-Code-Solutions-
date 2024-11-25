#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/

void inorder(BinaryTreeNode<int>* root, vector<int>&ans){
    if(root==NULL){
        return ;
    }

    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	
    vector<int> arr;
    inorder(root,arr);

    int i = 0;
    int j = arr.size()-1;
    
    while(i<j){
        int sum = arr[i]+arr[j];
        if(sum==target){
            return true;
        }
        else if(sum>target){
            j--;
        }
        else{
            i++;
        }
    }

    return false;



}
