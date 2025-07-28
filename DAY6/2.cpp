#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    struct Info {
        int size;
        int minVal;
        int maxVal;
        bool isBST;
    };

    int maxBSTSize = 0;

    Info dfs(TreeNode* node) {
        if (!node) return {0, INT_MAX, INT_MIN, true};

        Info left = dfs(node->left);
        Info right = dfs(node->right);

        Info curr;
        curr.size = left.size + right.size + 1;
        curr.minVal = min(node->val, left.minVal);
        curr.maxVal = max(node->val, right.maxVal);

        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            curr.isBST = true;
            maxBSTSize = max(maxBSTSize, curr.size);
        } else {
            curr.isBST = false;
        }

        return curr;
    }

    int largestBSTSubtree(TreeNode* root) {
        dfs(root);
        return maxBSTSize;
    }
};
