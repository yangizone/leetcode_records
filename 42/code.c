//栈+贪心算法
//借鉴找到下一个最大元素思想
//依次找到比前者更高的柱子，则之间的空量即为容量，再从左至右和从右至左
//执行用时 :4 ms, 在所有 C 提交中击败了94.13%的用户
//内存消耗 :12 MB, 在所有 C 提交中击败了5.55%的用户
typedef struct {
    int *base; //栈底
    int *top; //栈顶
    int cap; //容量
} Stack;

void InitStack(Stack *s){
    s->base = (int *)malloc(sizeof(int) * 10);
    s->top = s->base;
    s->cap = 10;
}

void PushStack(Stack *s, int e){
    if(s->top-s->base>=s->cap){
        s->base = (int *)realloc(s->base, sizeof(int) * (s->cap + 10));
        s->top = s->base + s->cap;
        s->cap += 10;
    }
    *(s->top) = e;
    s->top++;
}

int PopStack(Stack *s){
    int e = *--s->top;
    return e;
}

bool isStackEmpty(Stack *s){
    bool flag = false;
    if(s->top==s->base){
        flag = true;
    }
    return flag;
}

int StackLen(Stack *s){
    return s->top - s->base;
}

void ClearStack(Stack *s){
    s->top = s->base;
}

void DestoryStack(Stack *s){
    free(s->base);
    s->base = s->top = NULL;
    s->cap = 0;
    free(s);
}

int trap(int* height, int heightSize){
    if(height==NULL||heightSize==0){
        return 0;
    }

    Stack *s = (Stack *)malloc(sizeof(Stack));
    //printf("%d", height[i]); //维测
    InitStack(s);
    int maxCap = 0;
    int temp = 0;
    int left_boundry = 0; //代表从左至右循环的最大边界
    int i;
    for (i = 0; i < heightSize; i++)
    {
        //printf("%d", height[i]); //维测
        if(isStackEmpty(s)||height[i]<*s->base){
            PushStack(s, height[i]);
            temp -= height[i];
            //printf("%d ", temp); //维测
            //printf("%d ", *s->base); //维测
            //printf("%d ", StackLen(s)); //维测
        }
        else if(height[i]>=*s->base){
            //printf("你进来了吗？"); //维测
            //当没有两根柱子夹住时，不需要计算
            maxCap += ((StackLen(s) > 1) ? ((*s->base * StackLen(s)) + temp) : 0);
            //printf("%d ", temp); //维测
            temp = -height[i];
            ClearStack(s);
            PushStack(s, height[i]);
            left_boundry = i;
            //printf("%d ", StackLen(s)); //维测
        }
        else{

        }
        //printf("%d ", maxCap); //维测
    }
    //printf("%d", maxCap); //维测

    temp = 0;
    ClearStack(s);
    for (i = heightSize - 1; i >= left_boundry; i--)
    {
        if(isStackEmpty(s)||height[i]<*s->base){
            PushStack(s, height[i]);
            temp -= height[i];
        }
        else if(height[i]>=*s->base){
            maxCap += ((StackLen(s) > 1) ? ((*s->base * StackLen(s)) + temp) : 0);
            temp = -height[i];
            ClearStack(s);
            PushStack(s, height[i]);
        }
        else{

        }
        //printf("%d ", maxCap); //维测
    }
    //printf("%d", maxCap); //维测
    if(maxCap<0){
        maxCap = 0;
    }
    DestoryStack(s);
    return maxCap;
}

//好像没必要用到栈，就当练习栈了
//犯了一个错误，还是要小心：height==NULL写成了height=NULL
//原来思路有个问题，就是相等的情况可能会算两次，那就第二次到前一次的末位就截止