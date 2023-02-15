class Solution {
public:
TreeNode* deleteNode(TreeNode* root, int key) {
    if( !root )
        return nullptr;
    
    if( root->val == key ){
        if( !root->right )
            return root->left;
        else{
            TreeNode* n = root->right;
            while( n->left )
                n = n->left;
            swap( n->val , root->val );
            
            root->right = deleteNode( root->right , key );
            return root;
        }
    }
    
    if( root->val > key )
        root->left = deleteNode( root->left , key );
    if( root->val < key )
        root->right = deleteNode( root->right , key );
    return root;
}
};