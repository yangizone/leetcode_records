/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//1、对每一个元素寻找在nums2中的下一个更大元素O(n2)
//但存在一个特性：num1是num2的子集，能不能改进
//2、先对nums2进行快排O(nlogn)再寻找下一个更大元素
//用散列表存储用到O(n)，可能比第一种方法更快
//值(key)--num2快排后新位置(value)
//有问题，是下一个更大元素而不是数组中比他更大的下一个元素，所以不进行快排了
//那么转换为找到每一个在nums2中的位置然后每一次都寻找下一个更大的，但是可以保存每一个更大元素，当下一个在其左边的元素来寻找时只需判断是否有存储以及比较当前元素即可，现在依旧沿用之前那个方案
//执行用时 :12 ms, 在所有 C 提交中击败了90.79%的用户
//内存消耗 :8.4 MB, 在所有 C 提交中击败了5.15%的用户
struct hash_entry {
    int id;            /* we'll use this field as the key */
    int value;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *users = NULL;

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    //为了避免全局变量没有初始化，因此我在这里加上初始化
    //或者通过释放内存的方法
    //1、下面方式可行
    users = NULL;
    *returnSize = 0;
    if(nums1Size==0){
        return 0;
    }
    int *res = (int *)malloc(sizeof(int) * nums1Size);
    memset(res, -1, sizeof(int) * nums1Size);
    *returnSize = nums1Size;

    //将nums2中的对应位置放入散列表中
    int i;
    for (i = 0; i < nums2Size;i++){
        struct hash_entry *user = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        //因为已经保证没有重复元素，所以不判断了
        user->id = nums2[i];
        user->value = i;
        HASH_ADD_INT(users, id, user);
    }

    //根据num1的值取到nums2下一个的位置上
    for (i = 0; i < nums1Size;i++){
        //说是执行结果和提交结果不一致是因为变量没有初始化
        //因此我加上了初始化但是依旧出错
        //那么就是第二个问题，全局变量需要初始化详见LeetCode？注释
        struct hash_entry *s = NULL;
        HASH_FIND_INT(users, nums1 + i, s);
        int j;
        // printf("%d\n", s->value); //维测
        for (j = s->value + 1; j < nums2Size;j++){
            if(nums2[j]>nums1[i]){
                res[i] = nums2[j];
                break;
            }
        }
    }
    return res;
}

//在自测试用例中是通过的，但是提交就错了？？？
//ERROR1:
// [1,3,5,2,4]
// [5,4,3,2,1]
// 输出
// [4,-1,-1,-1,-1]
// 预期结果
// [-1,-1,-1,-1,-1]


// typedef struct {
//     int *base; //栈底
//     int *top; //栈顶
//     int cap; //栈最大容量
// } Stack;

// void Init(Stack *s){
//     s->base = (int *)malloc(sizeof(int) * 10);
//     s->top = s->base;
//     s->cap = 10;
// }

// void Push(Stack *s, int e){
//     if(s->top-s->base>=s->cap){
//         s->base = (int *)remalloc(s->base, sizeof(int) * (s->cap + 10));
//         s->top = s->base + s->cap;
//         s->cap += 10;
//     }
//     *(s->top) = e;
//     s->top++;
// }

// int Pop(Stack *s, int e){
//     int e = *(s->top);
//     s->top--;
//     return e;
// }

// int StackLen(Stack *s){
//     return s->top - s->base;
// }

// int Clear(Stack *s){
//     s->top = s->base;
// }

// int Destory(Stack *s){
//     free(s->base);
//     s->base = s->top = NULL;
//     s->cap = 0;
// }

// int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
//     *returnSize = 0;
//     if(nums1Size==0){
//         return 0;
//     }
//     int *res = (int *)malloc(sizeof(int) * nums1Size);
//     memset(res, 0, sizeof(int) * nums1Size);

// }
