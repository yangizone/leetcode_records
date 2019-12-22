/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL){
        return false;
    }
    //快慢指针
    struct ListNode *slow = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *quick = (struct ListNode *)malloc(sizeof(struct ListNode));
    slow = head;
    quick = head->next;
    while (slow != quick)
    {
        if (slow==NULL||quick == NULL)
        {
            return false;
        }
        slow = slow->next;
        //避免这个问题：第一步跳出去就没了
        if(quick->next==NULL){
            return false;
        }
        quick = quick->next->next;        
    }
    return true;
}