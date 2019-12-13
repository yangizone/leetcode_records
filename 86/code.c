/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    //执行用时 :8 ms, 在所有 c 提交中击败了45.50%的用户
    //内存消耗 :7.4 MB, 在所有 c 提交中击败了6.94%的用户
    //算法以及代码都有可优化的空间！
    if(head == NULL){
        return NULL;
    }
    //添加哑节点
    struct ListNode *lessListHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *lessList = (struct ListNode *)malloc(sizeof(struct ListNode));
    lessList->next = NULL;
    lessListHead = lessList; //保存链表头便于结果返回
    struct ListNode *moreListHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *moreList = (struct ListNode *)malloc(sizeof(struct ListNode));
    moreList->next = NULL;
    moreListHead = moreList; //保存链表头便于结果返回
    struct ListNode *dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy = head;
    while(dummy != NULL){
        if(dummy->val < x){
            lessList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            lessList->next->val = dummy->val;
            lessList->next->next = NULL;
            lessList = lessList->next;
        }
        else{
            moreList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            moreList->next->val = dummy->val;
            moreList->next->next = NULL;
            moreList = moreList->next;
        }
        dummy = dummy->next;
    }
    //还需要考虑两个链表为空的情况
    if(lessListHead->next != NULL){        
        if(moreListHead->next != NULL){
            lessList->next = (struct ListNode *)malloc(sizeof(struct ListNode));
            lessList->next = moreListHead->next;
        }
        return lessListHead->next;        
    }
    else
    {
        return moreListHead->next;
    }    
    //return lessListHead->next;
    //教训：
    //1、链表中next要先赋值为NULL再为其动态分配内存
    //2、因此可以采取哑结点达到上述效果
    //3、写完代码需要多想一步写写自测试用例，不然依旧无法AC
}