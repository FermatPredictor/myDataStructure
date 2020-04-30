//leetcode 124. Binary Tree Maximum Path Sum 題解
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
    //函數功能: 回傳至少通過root值的單向最大路徑和(只能往左或右走)，並更新通過root的最大路徑和
    int maxSinglePathPassRoot(TreeNode* root, int &MAX){
        if(root==NULL){
            return 0;
        }
        int left = max(0,maxSinglePathPassRoot(root->left, MAX));
        int right = max(0,maxSinglePathPassRoot(root->right, MAX));
        MAX = max(MAX, root->val + left+ right);
        return root->val+max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        int M = root->val;
        maxSinglePathPassRoot(root, M);
        return M;
    }
};
