/*
    给你 root1 和 root2 这两棵二叉搜索树。
    请你返回一个列表，其中包含 两棵树 中的所有整数并按 升序 排序。

    示例 1：
    输入：root1 = [2,1,4], root2 = [1,0,3]
    输出：[0,1,1,2,3,4]

    示例 2：
    输入：root1 = [0,-10,10], root2 = [5,1,7,0,2]
    输出：[-10,0,0,1,2,5,7,10]

    示例 3：
    输入：root1 = [], root2 = [5,1,7,0,2]
    输出：[0,1,2,5,7]

    示例 4：
    输入：root1 = [0,-10,10], root2 = []
    输出：[-10,0,10]

    示例 5：
    输入：root1 = [1,null,8], root2 = [8,1]
    输出：[1,1,8,8]

    提示：
    每棵树最多有 5000 个节点。
    每个节点的值在 [-10^5, 10^5] 之间。
    */



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
void getAllElementsResults(struct TreeNode* root1, struct TreeNode* root2, int* result, int* returnSize){
    struct TreeNode *dummy1 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *dummy2 = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    dummy1 = root1;
    dummy2 = root2;

    if(dummy1==NULL||dummy2==NULL){
        return;
    }

    if(dummy1->val > dummy2->val){
        dummy1 = dummy1->left;
        getAllElementsResults(dummy1, dummy2, result, returnSize);
        result[*returnSize] = dummy2->val;
        *returnSize++;
        dummy2 = dummy2->right;
        getAllElementsResults(dummy1, dummy2, result, returnSize);
    }
    else{
        dummy2 = dummy2->left;
        getAllElementsResults(dummy1, dummy2, result, returnSize);
        result[*returnSize] = dummy1->val;
        *returnSize++;
        dummy1 = dummy1->right;
        getAllElementsResults(dummy1, dummy2, result, returnSize);
    }
    free(dummy1);
    free(dummy2);
    return;
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    *returnSize = 0;
    int *result = (int *)malloc(sizeof(int) * 10000);
    memset(result, 0, sizeof(int) * 10000);
    getAllElementsResults(root1, root2, result, returnSize);
    return result;
}