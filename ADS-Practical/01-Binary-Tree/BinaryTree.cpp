#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinaryTree {
public:
    Node *root;

    BinaryTree() {
        this->root = nullptr;
    }

    void insertNode(Node *newNode, Node *root) {
        char choice;
        while (true) {  // Iteratively navigate
            cout << "[ PRESS L ] : To Insert at Left of [ " << root->data << " ]\n"
                 << "[ PRESS R ] : To Insert at Right of [ " << root->data << " ]\n";
            cin >> choice;

            if (choice == 'L' || choice == 'l') {
                if (root->left == nullptr) {
                    root->left = newNode;
                    return;
                } else {
                    root = root->left;
                }
            } else if (choice == 'R' || choice == 'r') {
                if (root->right == nullptr) {
                    root->right = newNode;
                    return;
                } else {
                    root = root->right;
                }
            } else {
                cout << "Invalid choice. Please press L or R.\n";
            }
        }
    }

    void PreOrder(Node *root) {
        if (root == nullptr) return;
        cout << root->data << " ,";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder(Node *root) {
        if (root == nullptr) return;
        InOrder(root->left);
        cout << root->data << " ,";
        InOrder(root->right);
    }

    void PostOrder(Node *root) {
        if (root == nullptr) return;
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ,";
    }

    void displayBinaryTree() {
        int choice;
        cout << "\nTree Traversals :\n[1] PreOrder Traversal\n[2] InOrder Traversal\n[3] PostOrder Traversal\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "PreOrder Sequence : [";
                PreOrder(root);
                cout << " ]\n";
                break;
            case 2:
                cout << "InOrder Sequence : [ ";
                InOrder(root);
                cout << " ]\n";
                break;
            case 3:
                cout << "PostOrder Sequence : [";
                PostOrder(root);
                cout << " ]\n";
                break;
            default:
                cout << "Invalid Choice...\n";
                break;
        }
    }

    int NumberOfNode(Node *root) {
        if (root == nullptr) return 0;
        return NumberOfNode(root->left) + NumberOfNode(root->right) + 1;
    }

    int heightOfTree(Node *root) {
        if (root == nullptr) return -1; // Height of an empty tree is -1
        int leftHeight = heightOfTree(root->left);
        int rightHeight = heightOfTree(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void getRoot() {
        if (root == nullptr) {
            cout << "Tree is empty, no root node exists.\n";
        } else {
            cout << "Root : " << root->data << endl;
        }
    }

    void getLeafNode(Node *root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            cout << root->data << " ,";
        }
        getLeafNode(root->left);
        getLeafNode(root->right);
    }

    void createBinaryTree() {
        int val, choice;
        root = nullptr; // Resetting root

        do {
            cout << "Enter data for node :";
            cin >> val;
            Node *newNode = new Node(val);
            if (root == nullptr) {
                root = newNode;
            } else {
                insertNode(newNode, root);
            }
            cout << "[1] Continue..\n[0] Exit..\n";
            cin >> choice;
        } while (choice == 1);
    }

    void insertNewNode() {
        if (root == nullptr) {
            cout << "Tree is empty. Create a tree first.\n";
            return;
        }
        int val;
        cout << "Enter data for new node: ";
        cin >> val;
        Node *newNode = new Node(val);
        insertNode(newNode, root);
    }
};

int main() {
    BinaryTree tree;
    int choice;
    do {
        cout << "\nBinary Tree Menu:\n";
        cout << "[1] Create Binary Tree\n";
        cout << "[2] Insert Node\n";
        cout << "[3] Display Tree Traversals\n";
        cout << "[4] Get Number Of Nodes\n";
        cout << "[5] Get Height of the Tree\n";
        cout << "[6] Get Root\n";
        cout << "[7] Display Leaf Nodes\n";
        cout << "[8] Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.createBinaryTree();
                break;
            case 2:
                tree.insertNewNode();
                break;
            case 3:
                tree.displayBinaryTree();
                break;
            case 4:
                cout << "Number Of Nodes : " << tree.NumberOfNode(tree.root) << endl;
                break;
            case 5:
                cout << "Height Of Tree : " << tree.heightOfTree(tree.root) << endl;
                break;
            case 6:
                tree.getRoot();
                break;
            case 7:
                cout << "Leaf Nodes: ";
                tree.getLeafNode(tree.root);
                cout << endl;
                break;
            case 8:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
