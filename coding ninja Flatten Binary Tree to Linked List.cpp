/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

void flattenBinaryTree(TreeNode<int>* root)
{
    
    TreeNode<int>* crr = root;
    while(crr!=NULL){
        if(crr->left){
            TreeNode<int>* pred = crr->left;
            while(pred->right){
                pred = pred->right;
            }
            pred->right = crr->right;
            crr->right = crr->left;
            crr->left = NULL;
        }
        crr = crr->right;
    }
}
