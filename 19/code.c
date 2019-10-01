
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
    //将dummy->next索引到head可以避免直接修改head
    //同时在该题中也可以实现删除头结点的情况
    dummy->next = head;
    // quick = head;
    // slow = head;
    quick = dummy;
    slow = dummy;
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
    slow->next = slow->next->next;
    return dummy->next;
}

