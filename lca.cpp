/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void generate(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& node, bool& f){
        if(!root) return;
        if(f){
            if(node && root != node && (root == p || root == q)){
                f = false;
            } 
        
        if(!node && root == p) node = root;
        else if(!node && root == q) node = root;
        }
        generate(root->left, p, q, node, f);
         if(f){
            if(node && (root->left == node || root->right == node)){
                node = root;
            }
        }
        generate(root->right, p, q, node, f);
        if(f){
            if(node && (root->left == node || root->right == node)){
                node = root;
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = NULL;
        bool f = true;
        generate(root, p, q, node, f);
        return node;
    }
};