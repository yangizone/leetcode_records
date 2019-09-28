/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    if(l1==NULL||l2==NULL){
        return NULL;
    }
    struct ListNode *result_ListNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *l1_temp_ListNode = l1;
    struct ListNode *l2_temp_ListNode = l2;

    if(*l1_temp_ListNode.val<=*l2_temp_ListNode.val){
        result_ListNode.val = *l1_temp_ListNode.val;
        l1_temp_ListNode = *l1_temp_ListNode.next;
    }
    else{
        result_ListNode.val = *l2_temp_ListNode.val++;
        l2_temp_ListNode = *l2_temp_ListNode.next;
    }
    
    while(l1_temp_ListNode!=NULL&&l2_temp_ListNode!=NULL){
        struct ListNode *temp_ListNode = NULL;
        if(*l1_temp_ListNode.val<=*l2_temp_ListNode.val){
            result_ListNode.next = l1_temp_ListNode;

            l1_temp_ListNode = *l1_temp_ListNode.next;
        }
        else{
            result_ListNode.val = *l2_temp_ListNode.val++;
            l2_temp_ListNode = *l2_temp_ListNode.next;
        }
    }
    // struct ListNode *l1_temp_ListNode = l1;
    // struct ListNode *l2_temp_ListNode = l2;


    // while(l1!=NULL&&l2!=NULL){

    //     struct ListNode *temp_ListNode = NULL;
    //     if(l1.val<=l2.val){
    //         //temp_ListNode = l1_temp_ListNode;
    //         temp_ListNode.val = l1.val;
    //         temp
    //         *result_ListNode.next=
    //     }
    // }
    // return result_ListNode;
}