/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head){
    if(head == NULL){
        return 0;
    }
    struct ListNode *nodeHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    nodeHead = head;
    int index = 0;
    while(head != NULL){
        if (head->next == NULL || head->next->next == NULL)
        {
            break;
        }
        if(index%2 == 0){
            oddNode->next = head->next;
            if(head->next->next!=NULL){
                head->next = head->next->next;
                head->next->next = head;
            }
            else{
                head->next->next = (struct ListNode *)malloc(sizeof(struct ListNode));
                head->next->next = head;
            }
        }
        index++;
        head = head->next;
    }
    return nodeHead;
}