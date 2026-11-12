
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

struct Tree {
    TreeNode* root;
};

void initTree(Tree& tree) {
    tree.root = nullptr;
}

void AddNode(TreeNode*& root, int val) {
    if (root == nullptr) {
        root = new TreeNode{val, nullptr, nullptr};
        return;
    }

    if (val < root->val) {
        AddNode(root->left, val);
    }
    else if (val > root->val) {
        AddNode(root->right, val);
    }
    else {
        throw logic_error("Elements must be different");
    }
}

void preOrder(TreeNode* root) {
    if (root == nullptr) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode* root) {
    if (root == nullptr) return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(TreeNode* root) {
    if (root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

bool isLeaf(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {

        return true;
    }
    return false;
}

void findLeaves(TreeNode* root) {
    if (root == nullptr) return;

    if (isLeaf(root)) {
        cout << root->val << " ";
    }

    findLeaves(root->left);
    findLeaves(root->right);
}

int getHeight(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if (left > right) return left + 1;
    return right + 1;
}

void printLongestBranch(TreeNode* root) {
    if (root == nullptr) return;

    if (getHeight(root->left) >= getHeight(root->right)) {
        printLongestBranch(root->left);
    }
    else {
        printLongestBranch(root->right);
    }

    cout << root->val << " ";
}

int main() {
    Tree BST;
    initTree(BST);

    AddNode(BST.root, 7);
    AddNode(BST.root, 8);
    AddNode(BST.root, 0);
    AddNode(BST.root, 12);
    AddNode(BST.root, 4);
    AddNode(BST.root, 6);
    AddNode(BST.root, 10);
    AddNode(BST.root, 9);
    AddNode(BST.root, -1);
    AddNode(BST.root, 5);
    AddNode(BST.root, 3);
    AddNode(BST.root, 1);
    AddNode(BST.root, 2);
    AddNode(BST.root, 14);
    AddNode(BST.root, 13);
    AddNode(BST.root, 15);

    cout << "preOrderLeft" << endl;
    preOrder(BST.root);
    cout << endl;

    cout << "inOrderLeft" << endl;
    inOrder(BST.root);
    cout << endl;

    cout << "postOrderLeft" << endl;
    postOrder(BST.root);
    cout << endl;

    cout << "Leaves" << endl;
    findLeaves(BST.root);
    cout << endl;

    cout << "Longest branch" << endl;
    printLongestBranch(BST.root);
    cout << endl;

    deleteTree(BST.root);
    return 0;
}
