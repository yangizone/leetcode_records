/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//用栈，将满足条件的入栈，当碰到下一个满足条件的时候出栈然后入栈
typedef struct {
    int *base;
    int *top;
} Stack;

void Init(Stack *s){
    s->base = (int *)malloc(sizeof(int) * 1000);
    s->top = s->base;
}

void Push(Stack *s, int e){
    *(s->top) = e;
    s->top++;
}

int Pop(Stack *s){
    return *(s->top--);
}

void Destory(Stack *s){
    free(s->base);
    free(s);
}

int* filterRestaurants(int** restaurants, int restaurantsSize, int* restaurantsColSize, int veganFriendly, int maxPrice, int maxDistance, int* returnSize){
    *returnSize = 0;
    int i;
    Stack *s = (Stack *)malloc(sizeof(Stack));
    for (i = 0;i<restaurantsSize;i++){
        if(restaurants[i][2]==veganFriendly&&restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance){
            Push(s, restaurants[i][0]);
            (*returnSize)++;
        }
    }
    int *resRank = (int *)malloc(sizeof(int) * (*returnSize));
    memset(resRank, 0, sizeof(int) * (*returnSize));
    for (i = 0; i < (*returnSize);i++){
        
    }
    restaurantsColSize = (int *)malloc(sizeof(int) * (*returnSize));
}

