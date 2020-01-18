/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//执行用时 :12 ms, 在所有 C 提交中击败了40.18%的用户
//内存消耗 :8.3 MB, 在所有 C 提交中击败了40.54%的用户
struct ListNode* oddEvenList(struct ListNode* head){
    if(!head || !head->next) return head;
    struct ListNode *pre=head,*cur=head->next;
    while(cur && cur->next){
        struct ListNode* tmp=pre->next;
        pre->next=cur->next;
        cur->next=cur->next->next;
        pre->next->next=tmp;
        pre=pre->next;
        cur=cur->next;
    }
    return head;
}
