/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//执行用时 :8 ms, 在所有 C 提交中击败了48.79%的用户
//内存消耗 :8 MB, 在所有 C 提交中击败了94.18%的用户
bool isMirrorSymmetric(struct TreeNode* node1, struct TreeNode* node2){
    // if(node1==NULL&&node2==NULL){
    //     return true;
    // }
    // else if(node1==NULL||node1==NULL){
    //     return false;
    // }
    // else{
    //     return (node1->val==node2->val)&&isMirrorSymmetric(node1->left,node2->right)&&isMirrorSymmetric(node1->right,node2->left);
    // }
    if(node1==NULL&&node2==NULL){
        return true;
    }
    if(node1==NULL||node2==NULL){
        return false;
    }
    return (node1->val==node2->val)&&isMirrorSymmetric(node1->left,node2->right)&&isMirrorSymmetric(node1->right,node2->left);
}

bool isSymmetric(struct TreeNode* root){
    if(root==NULL){
        return true;
    }
    return isMirrorSymmetric(root->left,root->right);
}