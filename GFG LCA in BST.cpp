class Solution{
    public:
    
        Node* solve(Node* root, int n1 ,int n2){
            if(root==NULL){
                return NULL;
            }
            if(root->data==n1 || root->data==n2){
                return root;
            }
            Node* leftans = solve(root->left,n1,n2);
            Node* rightans = solve(root->right,n1,n2);
            
            if(leftans==NULL && rightans==NULL){
                return NULL;
            }
            else if(leftans!=NULL && rightans==NULL){
                return leftans;
            }
            else if(leftans==NULL && rightans!=NULL){
                return rightans;
            }
            else{
                return root;
            }
        }
    
    
        Node* LCA(Node *root, int n1, int n2)
        {
            return solve(root,n1,n2);
        }

};
