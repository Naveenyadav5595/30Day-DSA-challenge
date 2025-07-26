#include <iostream>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize(TreeNode* root) {
    if (!root) return "#";
    return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
}

TreeNode* deserializeHelper(queue<string>& nodes) {
    string val = nodes.front(); nodes.pop();
    if (val == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(nodes);
    node->right = deserializeHelper(nodes);
    return node;
}

TreeNode* deserialize(string data) {
    stringstream ss(data);
    string token;
    queue<string> nodes;
    while (ss >> token) nodes.push(token);
    return deserializeHelper(nodes);
}

// Sample usage
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serialized = serialize(root);
    cout << "Serialized: " << serialized << endl;

    TreeNode* deserialized = deserialize(serialized);
    cout << "Root after deserialization: " << deserialized->val << endl;
}
