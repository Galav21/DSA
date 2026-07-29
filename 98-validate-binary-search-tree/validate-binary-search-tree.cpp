class Solution {
private:
    bool validate(TreeNode* node, long long min_val, long long max_val){
        // An empty tree/leaf child is always a valid BST
        if(!node){
            return true;
        }
        // Check if the current node's value violates the BST bounds
        if(node->val <= min_val || node->val >= max_val){
            return false;
        }
        // Recursively validate left and right subtrees with updated bounds
        return validate(node->left, min_val, node->val) && 
               validate(node->right,node->val, max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        // Initial call with full 64-bit bounds (-∞ to +∞)
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};