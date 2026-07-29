class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *second = nullptr, *prev = nullptr;
        TreeNode *curr = root;

        while (curr != nullptr) {
            if (curr->left == nullptr) {
                // Process node
                if (prev && prev->val > curr->val) {
                    if (first == nullptr) first = prev;
                    second = curr;
                }
                prev = curr;
                curr = curr->right;
            } else {
                // Find inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right != nullptr && pred->right != curr) {
                    pred = pred->right;
                }

                if (pred->right == nullptr) {
                    // Create thread
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Revert thread & process node
                    pred->right = nullptr;
                    if (prev && prev->val > curr->val) {
                        if (first == nullptr) first = prev;
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        // Swap back the values of the two mismatched nodes
        if (first && second) {
            std::swap(first->val, second->val);
        }
    }
};