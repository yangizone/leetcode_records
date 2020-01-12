//普通的栈应该不好用了，需要创建链表式的栈来存储
typedef struct {
    char *base;
    char *top;
    int cap;
} Stack;

void InitStack(Stack *stack){
    stack->base = (char *)malloc(sizeof(char) * 20);
    stack->top = stack->base;
    stack->cap = 20;
}

void PushStack(Stack *stack,char *e){
    if(strlen(s)+s->top-s->base>=s->cap){
        s->base = (char *)malloc(sizeof(char) * (s->cap + strlen(s) + 20));
        s->top = s->base + s->cap;
        s->cap += (strlen(s) + 20);
    }

}

char * decodeString(char * s){
    //数字存在数组中
    //字母存在栈中
    //那么这种栈就需要类似链表性质得用next了.
}




























// #include<stdio.h>
// #include<stdlib.h>
// typedef struct
// {
// 	int *base;//栈底
// 	int *top;//栈顶
// 	int stack;//最大空间
// }sqs;
// void init(sqs *s)//初始化栈
// {
// 	s->base = (int *)malloc(100 * sizeof(int));
// 	s->top = s->base;//最初栈顶和栈底重合
// 	s->stack = 100;//栈的最大容量
// }
// void push(sqs *s,int e)///入栈
// {
// 	if(s->top - s->base >= s->stack){
// 		s->base = (int *)realloc(s->base, (s->stack + 10) * sizeof(int));//重新申请一段长度为s->stack+10的空间，并将原来的数据复制过去
// 		s->top = s->base + s->stack;//设置栈顶
// 		s->stack = s->stack + 10;//设置栈的最大容量
// 	}
// 	*(s->top) = e;
// 	s->top++;
// }
// void pop(sqs *s)//出栈
// {
// 	if(s->top == s->base)//栈为空栈
// 		return;
// 	while(s->top - 1 != s->base)
// 		printf("%d ",*--(s->top));
// 	printf("%d\n",*(--s->top));
// }
// /*void clears(sqs *s)//清空栈(重新赋值时会直接覆盖原来的元素)
// {
// 	s->top = s->base;
// }
// void Destroys(sqs *s)//销毁栈
// {
// 	int i, len;
// 	len = s->stack;//len=栈的长度
// 	for(i = 0; i < len; i++){
// 		free(s->base);//释放栈底
// 		s->base++;//栈底想栈顶方向移动
// 	}
// 	s->base = s->top = NULL;
// 	s->stack = 0;
// }*/
// void Stacklen(sqs *s)//求栈的当前容量 (不是最大容量，最大容量是s->stack)
// {
// 	printf("当前栈的容量为%d\n",s->top - s->base);
// }
// int main()
// {
// 	sqs s;
// 	init(&s);
// 	int n, m;
// 	printf("请输入元素个数：");
// 	scanf("%d",&n);
// 	printf("请输入%d个元素：",n);
// 	for(int i = 0; i < n; i++){
// 		scanf("%d",&m);
// 		push(&s,m);
// 	}
// 	Stacklen(&s);
// 	printf("你输入的元素为：");
// 	pop(&s);
// 	return 0;
// }
