/* Github username: RachitJain-Learner
   Aim: Solved Leetcode Question - Same Tree
   Date: 2nd October 2022
*/

/* 100. Same Tree
Problem Link: https://leetcode.com/problems/same-tree/
*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(p == NULL || q == NULL)
            return p == q ;
            
        bool checkLeft = isSameTree(p->left, q->left) ;
        bool checkRight = isSameTree(p->right, q->right) ;
        
        return (p->val == q->val) && checkLeft && checkRight ;
    }
};
