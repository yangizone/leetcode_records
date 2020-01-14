//执行用时 :68 ms, 在所有 C 提交中击败了33.90%的用户
//内存消耗 :42.1 MB, 在所有 C 提交中击败了5.71%的用户
typedef struct {
    int *base;
    int *top;
    int cap;
    int *minHead;
    int *minPot;
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->base = (int *)malloc(sizeof(int) * 10);
    obj->top = obj->base;
    obj->cap = 10;
    //obj->min = INT_MAX;
    obj->minHead = (int *)malloc(sizeof(int) * 10);
    //打印结果显示memset将INT_MAX赋值成了-1
    //解释：memset将ASCII码转为二进制赋值，按字节赋值，
    //int为4字节，最后为11111111111111111111111111111111即-1
    //大佬将最大值赋值为0x3f3f3f3f，他的十进制是 1061109567也就是10^9级别的（和0x7fffffff一个数量级），作为一个oier， 一般场合下的题目数据都是小于10^9的，所以它可以作为无穷大使用而不致出现数据大于无穷大的情形。因为0x3f3f3f3f的每个字节都是0x3f！所以要把一段内存全部置为无穷大，我们只需要memset(a,0x3f,sizeof(a))（memset按字节赋值）。
    //memset(obj->minHead, 0x3f, sizeof(int) * 10);
    int i;
    for (i = 0; i < 10; i++)
    {
        *(obj->minHead + i) = INT_MAX;
    }
    
    obj->minPot = obj->minHead;
    // printf("%d ", *(obj->minHead)); //维测
    // printf("%d ", *(obj->minPot)); //维测
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    // printf("%d ", obj->top-obj->base); //维测
    //因为base分配了10个地址，然后若是判断top-base是否超过cap，这时top已经超过了cap+base即超过了动态分配的地址，因此减了一;之后又出了一个问题，发现有些值赋值成了非Push进的值，发现realloc后top是赋值成base+cap，上面减了一这里没改导致访问了非动态分配内存的地址，因此出错
    if (obj->top-obj->base>=obj->cap-1)
    {
        // printf("\n我进来了"); //维测
        obj->base = (int *)realloc(obj->base, sizeof(int) * (obj->cap + 10));
        obj->top = obj->base + obj->cap-1;
        obj->minHead = (int *)realloc(obj->minHead, sizeof(int) * (obj->cap + 10));
        obj->minPot = obj->minHead + obj->cap-1;
        obj->cap += 10;
    }
    *(obj->top) = x;
    obj->top++;
    if(*(obj->minPot)>x){
        *(obj->minPot) = x;
        obj->minPot++;
        *(obj->minPot) = x;
    }
    else{
        int temp = *(obj->minPot);
        obj->minPot++;
        *(obj->minPot) = temp;
    }
    // printf("%d ", x); //维测
}

void minStackPop(MinStack* obj) {
    if(obj->top-obj->base>0){
        obj->top--;
    }
    if(obj->minPot-obj->minHead>1){
        obj->minPot--;
        *(obj->minPot) = *(obj->minPot - 1);
    }
    else if(obj->minPot==obj->minHead+1){
        obj->minPot--;
        *(obj->minPot) = INT_MAX;
    }
    else{

    }
}

int minStackTop(MinStack* obj) {
    return *(obj->top - 1);
}

int minStackGetMin(MinStack* obj) {
    //维测
    // int len = obj->top - obj->base;
    // printf("%d\n", len);
    // int *temp = obj->minHead;
    // int i;
    // for (i = 0; i < len;i++){
    //     printf("%d ", *(temp + i));
    // }
    return *(obj->minPot-1);
}

void minStackFree(MinStack* obj) {
    free(obj->base);
    obj->base = obj->top = NULL;
    obj->cap = 0;
    free(obj->minHead);
    obj->minHead = obj->minPot = NULL;
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

//第一次错误用例：(未考虑到弹出最小值更新的情况)
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

//第二次错误用例：(memset赋值的问题，看前文注释)
// ["MinStack","push","push","push","getMin","pop","getMin"]
// [[],[0],[1],[0],[],[],[]]

//第三次错误用例：(这次真的赋值成了最大值,memset前面巧妙的方法不适用，还是老老实实循环吧)
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

//第四次错误用例：(和第三用例相同，即还有一个问题，即当Pop完之后当前的值未删除导致后续push判断依旧用的是之前的值)
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

//第五次错误用例：(数组越界，暂时发现pop时未考虑到已经到达栈底的情况但不是造成该问题的原因，暂时发现是第10个push出了问题怀疑是realloc，见前文注释)
// ["MinStack","push","push","push","getMin","push","push","push","push","push","top","push","push","getMin","push","getMin","push","push","getMin","push","top","push","getMin","push","push","push","push","getMin","push","push","top","push","push","getMin","pop","getMin","push","push","getMin","getMin","push","getMin","pop","push","push","push","getMin","push","getMin","getMin","getMin","pop","getMin","push","push","getMin","top","getMin","push","getMin","getMin","getMin","getMin","push","getMin","getMin","getMin","push","getMin","push","getMin","push","getMin","getMin","getMin","getMin","pop","getMin","push","getMin","getMin","push","push","pop","push","getMin","push","top","top","push","push","getMin","pop","getMin","push","top","push","getMin","push","getMin","getMin"]
// [[],[85],[-99],[67],[],[-27],[61],[-97],[-27],[35],[],[99],[-66],[],[-89],[],[4],[-70],[],[52],[],[54],[],[94],[-41],[-75],[-32],[],[5],[29],[],[-78],[-74],[],[],[],[-58],[-44],[],[],[-64],[],[],[-45],[-99],[-27],[],[-96],[],[],[],[],[],[26],[-58],[],[],[],[25],[],[],[],[],[33],[],[],[],[71],[],[-62],[],[-78],[],[],[],[],[],[],[-30],[],[],[85],[-15],[],[-40],[],[72],[],[],[18],[59],[],[],[],[-59],[],[10],[],[9],[],[]]