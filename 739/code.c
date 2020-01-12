/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//与496求下一个最大元素相同，单调栈

//从左至右，到没遇到升高温度的那日都push，然后遇到则Pop并计数
//pop的个数即为剩下的天数，原来维护一个hash表，根据当前Pop的温度值
//寻到该温度在hash的位置即在列表中的位置然后将计数值存入即可得到
//也可以放入索引避免维护Hash表
// int* dailyTemperatures(int* T, int TSize, int* returnSize){

// }

//从右至左，若温度变小则存入若温度变大则将栈顶弹出，可以保持栈里元素单调，则栈顶即为下一个的最大元素，这题求相距的日子则可以放入索引
typedef struct {
    int *base;
    int *top;
    int cap;
} Stack;

void Init(Stack *s){
    s->base = (int *)malloc(sizeof(int) * 10);
    s->top = s->base;
    s->cap = 10;
}

void Push(Stack *s, int e){
    if(s->top-s->base>=s->cap){
        s->base = (int *)realloc(s->base, sizeof(int) * (s->cap + 10));
        s->top = s->base + s->cap;
        s->cap += 10;
    }
    *(s->top) = e;
    s->top++;
}

int Pop(Stack *s){
    return *--s->top;
}

bool IsEmpty(Stack *s){
    bool flag = false;
    if(s->top==s->base){
        flag = true;
    }
    return flag;
}

void Destory(Stack *s){
    free(s->base);
    s->base = s->top = NULL;
    s->cap = 0;
    free(s);
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){
    *returnSize = TSize;
    if(T==NULL||TSize==0){
        return 0;
    }

    Stack *s = (Stack *)malloc(sizeof(Stack));
    int *res = (int *)malloc(sizeof(int) * TSize);
    memset(res, 0, sizeof(int) * TSize);
    int i;
    for (i = TSize - 1; i >= 0;i--){
        int *tmp = s->top;
        tmp--;
        while(!IsEmpty(s)&&T[*tmp]<=T[i]){
            Pop(s);
        }
        res[i] = (IsEmpty(s)) ? 0 : (*tmp - i);
        Push(s, i);
    }
    Destory(s);
    return res;
}
