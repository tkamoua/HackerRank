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
    //create helper function createBST(vector<int> & nums, int start, int stop)
    //if start == stop
    //      return nullptr
    //get middle element of start stop
    //set as root (to be returned later)
    //set left child to (start+middle)/2 and right child to (end + middle)/2
    // call createBST(nums,left child, start,middle) and createBST(nums,right child, middle,stop)
    //return root
    TreeNode* createBST(vector<int> & nums, int start, int stop){
        if (start>=stop){
            return nullptr;
        }
        int middle = (start+stop)/2;
        int midval = nums[middle];
        TreeNode * root = new TreeNode(midval);
        root->left = createBST(nums,start,middle);
        root->right = createBST(nums,middle+1,stop);
        
        
  
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
  
        int middle = (0+ nums.size())/2;
        

        return createBST(nums,0,nums.size());
    }
};