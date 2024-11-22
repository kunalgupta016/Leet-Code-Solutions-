
#include<map>

/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/


BinaryTreeNode<int>* createParentMapping(BinaryTreeNode<int>* root
, int target,map<BinaryTreeNode<int>*,BinaryTreeNode<int>*>&NodeToParent){

    BinaryTreeNode<int>* res = NULL;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    NodeToParent[root]=NULL;
    while(!q.empty()){
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        // agar equal hbo gya
        if(front->data == target){
            res = front;
        }
        // check left haibhi nahi
        if(front->left){
            NodeToParent[front->left] = front;
            q.push(front->left);
        }
        // check right;
        if(front->right){
            NodeToParent[front->right] = front;
            q.push(front->right);
        }
    }


    return res;

}


int burn(BinaryTreeNode<int>* root, map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> NodeToParent){
    

    map<BinaryTreeNode<int>* , bool> visited;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    visited[root] = true;
    int ans = 0;
    
    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i=0;i<size;i++){
            // neighbouring 
            // left check 
            BinaryTreeNode<int>* front = q.front();
            q.pop();
            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            // right
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }
            // parent
            if(NodeToParent[front] && !visited[NodeToParent[front]]){
                flag = 1;
                q.push(NodeToParent[front]);
                visited[NodeToParent[front]] = true;
            }
        }

        if(flag){
            ans++;
        }
    }

return ans;


}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here

    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> NodeToParent;
    BinaryTreeNode<int>* targetNode = createParentMapping(root,start,NodeToParent);
    int ans = burn(targetNode,NodeToParent);
    return ans;
}
