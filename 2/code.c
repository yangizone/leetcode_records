/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    //初始化一个指针指向结果，可以避免当前指针后移
    struct ListNode *list1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *list2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *res = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *curr = (struct ListNode *)malloc(sizeof(struct ListNode));

    list1 = l1;
    list2 = l2;
    curr = res;

    int ca = 0; //代表进位
    while (list1||list2)
    {
        // 若两个链表非等长，短链表作补0处理
        int x = list1 ? list1->val : 0;
        int y = list2 ? list2->val : 0;
       
        int sum;
        sum = x + y + ca;
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->next->val = sum % 10;
        ca = sum / 10;

        curr = curr->next;      
        list1 = list1->next;
        list2 = list2->next;
    }

    if(ca){
        curr->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        curr->next->val = ca;
    }
    return res->next;
}
