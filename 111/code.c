/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define getMax(x,y) ((x>y)?x:y)

bool flag = false;

int minDepth(struct TreeNode* root){
    //有个问题：根与叶节点为同一个节点时返回1，单独叶节点返回0
    //该代码没考虑到单独叶节点返回0
    if(root == NULL){
        return 0;
    }
    //加了个判断还是错误！
    if(root->left==NULL&&root->right==NULL){
        int res = flag ? 0 : 1;
        flag = true;
        return res;
    }
    return getMax(minDepth(root->left), minDepth(root->right)) + 1;
}