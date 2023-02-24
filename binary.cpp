#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) {
        return root;
    }
    if (root->val > val) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    TreeNode* result = searchBST(root, 4);

    if (result) {
        std::cout << "Node found: " << result->val << std::endl;
    } else {
        std::cout << "Node not found" << std::endl;
    }

    return 0;
}
