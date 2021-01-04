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
    bool treeEqual(TreeNode* s, TreeNode * t){
        if(s == nullptr && t == nullptr){
            return true;
        }
        else if(s == nullptr || t ==nullptr){
            return false;
        }
        else if(s->val == t->val){
            return treeEqual(s->left,t->left) && treeEqual(s->right,t->right);
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == nullptr && t == nullptr){
            return true;
        }
        else if(s == nullptr){
            return false;
        }
        else if(t == nullptr){
            return true;
        }
        else if(treeEqual(s,t)){
            return true;
        }
        else {
            return isSubtree(s->left,t) || isSubtree(s->right,t);
        }
    }
};