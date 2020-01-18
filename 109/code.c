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
//执行用时 :28 ms, 在所有 C 提交中击败了34.53%的用户
//内存消耗 :24.9 MB, 在所有 C 提交中击败了5.13%的用户
struct TreeNode* sortedListToBST(struct ListNode* head){
    if(head==NULL){
        return 0;
    }
    struct TreeNode* result=(struct TreeNode *)malloc(sizeof(struct TreeNode));
    //将结果返回，就可以避免传入result的麻烦
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode)); //保存前一个节点
    struct ListNode *prevHead;
    //找到中间节点
    struct ListNode *slow = head;
    struct ListNode *quick = head;
    prev->next = head;
    prevHead = prev;
    //prevHead->next = head;无效因为这样即使prev->next=NULL，prevHead下一个也依旧指向Head
    //快慢指针也可以参考leetcode141
    while(quick&&quick->next){
        quick = quick->next->next;
        slow = slow->next;
        prev = prev->next;
    }
    result->val = slow->val;
    result->left = NULL;
    result->right = NULL;
    prev->next = NULL;
    //一直传入head,就算prev->next=NULL也不会让Head=NULL，因此死循环
    result->left = sortedListToBST(prevHead->next);
    result->right = sortedListToBST(slow->next);
    return result;
}
