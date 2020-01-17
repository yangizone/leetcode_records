/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sortedBinarySearch(struct ListNode* head, struct TreeNode* result, int flag){
    //一种是上面传进来就是NULL赋成NULL
    //一种是上面需要初始化先赋值为NULL(我这里判断的是head不是result)
    if(head==NULL){
        //暂时猜测是赋值为NULL和在结果中的null不是一个东西
        //result = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        //result = NULL;
        //result = NULL;
        return;
    }
    printf("\n%d:\n", flag);//
    if(flag!=0){
        result = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    }
    else{
        flag++;
    }
    struct ListNode *prev = (struct ListNode *)malloc(sizeof(struct ListNode)); //保存前一个节点
    //找到中间节点
    struct ListNode *slow;
    //= (struct ListNode *)malloc(sizeof(struct ListNode));
    struct ListNode *quick;
    // = (struct ListNode *)malloc(sizeof(struct ListNode));
    prev->next = head;
    slow = head;
    quick = head;
    printf("%d ", head->val);//
    //快慢指针也可以参考leetcode141
    while(quick&&slow){
        quick = quick->next;
        if(quick==NULL){
            break;
        }
        quick = quick->next;
        if(quick==NULL){
            break;
        }
        slow = slow->next;
        prev = prev->next;
    }
    result->val = slow->val;
    printf("%d  ", result->val);//
    //printf("%d  ", slow->next->val);//
    result->left = NULL;
    result->right = NULL;
    //这里传进去的result->right也可能是一样的，不会改变之前链接的right
    sortedBinarySearch(slow->next, result->right, flag);
    //为了解决始终跳不出链表头的循环加了判断，应该有更好的办法！
    //指向同一个地方的指针，其中一个置为NULL并不会改变另一个指针的值，因为另一个指针指向的地方没有改变
    //所以必须存储前一个指针

    // if(head==slow){
    //     head = NULL;
    //     slow = NULL; //所以按理说这行也没什么效果
    // }
    // else
    // {
    //     slow = NULL;
    // }
    // if(head==slow){
    //     printf("\n# 111  ");//
    // }
    // slow = NULL;
    // if(head==NULL){
    //     printf("\n# 222  ");//
    // }
    // if(head){
    //     //printf("# %d  ", slow->val);//
    //     printf("# %d  ", head->val);//
    // }
    // else{
    //     printf("\n# 111  ");//
    // }
    printf("# %d  ", prev->next->val);//
    if(head==slow){
        head = NULL;
    }
    prev->next = NULL;
    if(head==NULL){
        printf("\n# 222  ");//
    }
    //printf("%d  ", slow->val);//
    sortedBinarySearch(head, result->left, flag);
    free(slow);
    free(quick);
    return;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
    struct TreeNode *result = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    struct TreeNode *resultHead = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    resultHead = result;
    int flag = 0; //为了解决第一次进去动态分配内存加了判断符号，应该有更好的方法！
    sortedBinarySearch(head, result, flag);
    printf("\n%d  ", result->val);//
    //printf("%d  ", result->left->val);//
    //printf("%d  ", result->right->val);//
    return resultHead;
}
