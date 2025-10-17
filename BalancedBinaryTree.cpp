// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

 //by recursion

class Solution {
public:
    void max_depth(TreeNode* root, int cnt, int& maxi, bool& f){
        if(f == false){
            return;
        }
        if(root != NULL){
            max_depth(root->left, cnt+1, maxi, f);
            maxi = max(maxi, cnt);
            int max_left = maxi-cnt;
            maxi = cnt;
            max_depth(root->right, cnt+1, maxi, f);
            maxi = max(maxi, cnt);
            int max_right = maxi-cnt;
            if(abs(max_left-max_right) > 1){
                f = false;
            }
            maxi = max(max_left+cnt, max_right+cnt);
        }
    }
    bool isBalanced(TreeNode* root) {
        int maxi = 0;
        bool f = true;
        max_depth(root, 1, maxi, f);
        return f;
    }
};