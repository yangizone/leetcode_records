/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = (int *)malloc(1000 * sizeof(int));
    *returnSize = 0;
    inorder(root, returnSize, result);
    return result;
}
void inorder(struct TreeNode* root, int* returnSize, int* result){
    if(root!=NULL){
        inorder(root->left, returnSize, result);
        //这样虽然写的快，但是怎么输出都是[]
        //后来我想明白了：指针也变化了，此时输出的指向最后赋值的下一个指针肯定不会有输出
        //因此像数组一样赋值不改变指针位置，更合适！
        // *result++ = root->val; //指针就使用-> 非指针使用.
        // *returnSize++;
        result[(*returnSize)++] = root->val;
        inorder(root->right, returnSize, result);
    }
}

