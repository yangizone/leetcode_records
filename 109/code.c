/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//可以用快慢指针获取中间元素
//也可以存储链表为数组，这样后面搜索到这件元素时间为O(1)
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL){
        return 0;
    }
    struct TreeNode* result=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    //将结果返回，就可以避免传入result的麻烦
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode)); //保存前一个节点
    //找到中间节点
    struct ListNode *slow = head;
    struct ListNode *quick = head;
    prev->next = head;
    //快慢指针也可以参考leetcode141
    while(quick&&slow){
        quick = quick->next;
        if(quick==NULL){
            break;
        }
        quick = quick->next;
        if(quick==NULL){
            break;
        }
        slow = slow->next;
        prev = prev->next;
    }
    result->val = slow->val;
    result->left = NULL;
    result->right = NULL;
    result->right = sortedListToBST(slow->next);
    //还差下面这一步就完成了
    //prev->next = NULL;
    //result->left = sortedListToBST(head);
    free(slow);
    free(quick);
    return result;
}
