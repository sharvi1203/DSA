/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unsigned long long maxe = 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(make_pair(root,1));
        while (!q.empty()) {
            unsigned long long l = q.front().second, r = l; // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode* node = q.front().first;
                r = q.front().second;
                q.pop();
                if (node->left) q.push(make_pair(node->left, r * 2));
                if (node->right) q.push(make_pair(node->right, r * 2 + 1));
            }
            maxe = max({maxe, r + 1 - l});
        }
        return (int)maxe;
    }
};
