/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int *base; //栈底
    int *top; //栈顶
    int cap; //栈最大容量
} Stack;

void Init(Stack *s){
    s->base = (int *)malloc(sizeof(int) * 10);
    s->top = s->base;
    s->cap = 10;
}

void Push(Stack *s, int e){
    if(s->top-s->base>=s->cap){
        s->base = (int *)remalloc(s->base, sizeof(int) * (s->cap + 10));
        s->top = s->base + s->cap;
        s->cap += 10;
    }
    *(s->top) = e;
    s->top++;
}

int Pop(Stack *s, int e){
    int e = *(s->top);
    s->top--;
    return e;
}

int StackLen(Stack *s){
    return s->top - s->base;
}

int Clear(Stack *s){
    s->top = s->base;
}

int Destory(Stack *s){
    free(s->base);
    s->base = s->top = NULL;
    s->cap = 0;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    int *res = (int *)malloc(sizeof(int) * nums1Size);
    memset(res, 0, sizeof(int) * nums1Size);

}