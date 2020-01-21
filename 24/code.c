/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
//内存消耗 :7.1 MB, 在所有 C 提交中击败了83.88%的用户
//一遍过，未调试
struct ListNode* swapPairs(struct ListNode* head){
    if(head==NULL){
        return 0;
    }
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode)); //next指向头结点
    dummy->next = head;
    struct ListNode *pre, *curr;
    pre = dummy;
    curr = head;
    while(curr && curr->next){
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = curr;

        pre = curr;
        curr = curr->next;
    }
    return dummy->next;
}