/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    //原地算法，不想多分配一个链表
    if(head==NULL){
        return NULL;
    }
    struct ListNode *result = (struct ListNode *)malloc(sizeof(struct ListNode));
    result = head;
    while(head->next){
        int dummy = head->val;
        if(head->next->val==dummy){
            if(head->next->next){
                head->next = head->next->next;
            }
            else{
                head->next = NULL;
                break;
            }
        }
        else{
            head = head->next;
        }       
    }
    return result;
}