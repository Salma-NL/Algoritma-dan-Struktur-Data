#include <iostream>
#include <vector>
#include <string>
#include "RedBlackTree.h"

using namespace std;

void preorderTraversal(const RedBlackTree::Node* currentNode,
                       const RedBlackTree::Node* nilNode,
                       vector<int>& traversalResult) {
    if (currentNode == nilNode) return;

    traversalResult.push_back(currentNode->key);
    preorderTraversal(currentNode->left, nilNode, traversalResult);
    preorderTraversal(currentNode->right, nilNode, traversalResult);
}

void inorderTraversal(const RedBlackTree::Node* currentNode,
                      const RedBlackTree::Node* nilNode,
                      vector<int>& traversalResult) {
    if (currentNode == nilNode) return;

    inorderTraversal(currentNode->left, nilNode, traversalResult);
    traversalResult.push_back(currentNode->key);
    inorderTraversal(currentNode->right, nilNode, traversalResult);
}

void postorderTraversal(const RedBlackTree::Node* currentNode,
                        const RedBlackTree::Node* nilNode,
                        vector<int>& traversalResult) {
    if (currentNode == nilNode) return;

    postorderTraversal(currentNode->left, nilNode, traversalResult);
    postorderTraversal(currentNode->right, nilNode, traversalResult);
    traversalResult.push_back(currentNode->key);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalNumbers;
    cin >> totalNumbers;

    RedBlackTree redBlackTree;

    for (int i = 0; i < totalNumbers; i++) {
        int number;
        cin >> number;

        if (!redBlackTree.contains(number)) {
            redBlackTree.insert(number);
        }
    }

    int totalQueries;
    cin >> totalQueries;

    if (redBlackTree.empty()) {
        cout << "Tree kosong. Tidak ada yang bisa ditampilkan.\n";
        return 0;
    }

    for (int i = 0; i < totalQueries; i++) {
        string traversalType;
        cin >> traversalType;

        vector<int> preorderResult;
        vector<int> inorderResult;
        vector<int> postorderResult;

        if (traversalType == "PREORDER") {
            preorderTraversal(redBlackTree.root(),
                              redBlackTree.nil(),
                              preorderResult);

            cout << "[Preorder] : ";
            for (size_t j = 0; j < preorderResult.size(); j++) {
                cout << preorderResult[j];
                if (j + 1 < preorderResult.size()) cout << " ";
            }
            cout << '\n';
        }

        else if (traversalType == "INORDER") {
            inorderTraversal(redBlackTree.root(),
                             redBlackTree.nil(),
                             inorderResult);

            cout << "[Inorder] : ";
            for (size_t j = 0; j < inorderResult.size(); j++) {
                cout << inorderResult[j];
                if (j + 1 < inorderResult.size()) cout << " ";
            }
            cout << '\n';
        }

        else if (traversalType == "POSTORDER") {
            postorderTraversal(redBlackTree.root(),
                               redBlackTree.nil(),
                               postorderResult);

            cout << "[Postorder] : ";
            for (size_t j = 0; j < postorderResult.size(); j++) {
                cout << postorderResult[j];
                if (j + 1 < postorderResult.size()) cout << " ";
            }
            cout << '\n';
        }

        else if (traversalType == "ALL") {
            preorderTraversal(redBlackTree.root(),
                              redBlackTree.nil(),
                              preorderResult);

            inorderTraversal(redBlackTree.root(),
                             redBlackTree.nil(),
                             inorderResult);

            postorderTraversal(redBlackTree.root(),
                               redBlackTree.nil(),
                               postorderResult);

            cout << "[Preorder] : ";
            for (size_t j = 0; j < preorderResult.size(); j++) {
                cout << preorderResult[j];
                if (j + 1 < preorderResult.size()) cout << " ";
            }
            cout << '\n';

            cout << "[Inorder] : ";
            for (size_t j = 0; j < inorderResult.size(); j++) {
                cout << inorderResult[j];
                if (j + 1 < inorderResult.size()) cout << " ";
            }
            cout << '\n';

            cout << "[Postorder] : ";
            for (size_t j = 0; j < postorderResult.size(); j++) {
                cout << postorderResult[j];
                if (j + 1 < postorderResult.size()) cout << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}