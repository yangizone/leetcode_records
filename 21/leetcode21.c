/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL){
        return NULL;
    }
    struct ListNode *result_ListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *Headres_ListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    Headres_ListNode = result_ListNode;

    while(l1 || l2){
        int temp1 = l1 ? l1->val : INT_MAX;
        int temp2 = l2 ? l2->val : INT_MAX;
        result_ListNode->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        if(temp1 <= temp2){
            result_ListNode->next->val = temp1;
            l1 = l1->next;
        }
        else{
            result_ListNode->next->val = temp2;
            l2 = l2->next;
        }
        result_ListNode->next->next = NULL;
        result_ListNode = result_ListNode->next;
    }
    return Headres_ListNode->next;
}