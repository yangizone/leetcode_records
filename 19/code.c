
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(head==NULL||n<1){
        return NULL;
    }
    struct ListNode *quick = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *slow = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->next = head;
    quick = head;
    slow = head;
    while(n+1>0&&quick){ //跳过n+1次，这样可以索引到删除的那个节点的前一个
        quick = quick->next;
        n--;
    }
    //还要考虑删除链表头结点
    //下面这样当总结点数不足n+2时失败
    // if(quick==NULL){
    //     return NULL;
    // }
    while(quick){
        quick = quick->next;
        slow = slow->next;
    }
    //删除节点，那么意味着slow索引到该节点前一项
    //说明slow和quick至少差两项
    //需要判断slow->next是否为NULL
    if(slow->next==NULL){
        slow = NULL;
    }
    else
    {
        slow->next = slow->next->next;
    }

    return dummy->next;
}

