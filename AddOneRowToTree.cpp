/*
https://leetcode.com/problems/add-one-row-to-tree/
623. Add One Row to Tree
Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

Note that the root node is at depth 1.

The adding rule is:

Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
cur's original left subtree should be the left subtree of the new left subtree root.
cur's original right subtree should be the right subtree of the new right subtree root.
If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.


*/


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
    public:
    void helper(TreeNode* root, int val, int depth){
        if(depth==2){
            TreeNode* a = new TreeNode(val,root->left,NULL);
            root->left = a;
            TreeNode* b = new TreeNode(val, NULL, root->right);
            root->right = b;
            return;
        }
        else{
            if(root->left!=NULL){
                helper(root->left, val, depth-1);
            }
            if(root->right!=NULL){
                helper(root->right, val, depth-1);
            }
        }  

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *ans = new TreeNode(val, root, NULL);
            return ans;
        }
        helper(root, val, depth);
        return root;
    } 
        
    
};
