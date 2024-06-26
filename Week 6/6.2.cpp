#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode *left, *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the binary search tree
TreeNode* insert(TreeNode* root, int x) {
    if (root == nullptr)
        return new TreeNode(x);
    if (x < root->value)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

// Function to find the lowest common ancestor of two nodes in the binary search tree
TreeNode* lowestCommonAncestor(TreeNode* root, int value1, int value2) {
    while (root != nullptr) {
        if (value1 < root->value && value2 < root->value)
            root = root->left;
        else if (value1 > root->value && value2 > root->value)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}

int main() {
    TreeNode* root = nullptr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int value1, value2;
    cin >> value1 >> value2;
    TreeNode* result = lowestCommonAncestor(root, value1, value2);
    if (result != nullptr)
        cout << result->value;
    return 0;
}