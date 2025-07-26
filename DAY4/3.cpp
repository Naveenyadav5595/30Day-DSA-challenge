#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree() {
    // Manually building the tree as per example
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    return root;
}

void markParents(Node* root, unordered_map<Node*, Node*>& parent) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

Node* findTarget(Node* root, int target) {
    if (!root) return NULL;
    if (root->data == target) return root;
    Node* left = findTarget(root->left, target);
    if (left) return left;
    return findTarget(root->right, target);
}

int burnTree(Node* root, int target) {
    unordered_map<Node*, Node*> parent;
    markParents(root, parent);
    Node* targetNode = findTarget(root, target);
    
    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(targetNode);
    visited[targetNode] = true;
    
    int time = 0;
    while (!q.empty()) {
        int size = q.size();
        bool anyBurned = false;
        for (int i = 0; i < size; ++i) {
            Node* curr = q.front(); q.pop();
            for (Node* nbr : {curr->left, curr->right, parent[curr]}) {
                if (nbr && !visited[nbr]) {
                    anyBurned = true;
                    visited[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        if (anyBurned) time++;
    }
    return time;
}

int main() {
    Node* root = buildTree();
    int target = 5;
    cout << "Minimum time to burn the tree: " << burnTree(root, target) << endl;
    return 0;
}
