// bool isValid(char * s){
//     if(s==NULL){
//         return false;
//     }
//     //将三个字符标为三类，遇到左右括号就进行对比
//     // '(' 0 '{' 1 '[' 2 或者直接存储为char数组对比
//     int index=0; //代表最新的左括号的下标
//     char store_char[10000]; //依次存储字符串的左括号
//     while(*s!='\0'){
//         if(*s=='('||*s=='{'||*s=='['){
//             if(*s=='('){
//                 store_char[index] = ')';
//             }
//             if(*s=='{'){
//                 store_char[index] = '}';
//             }
//             if(*s=='['){
//                 store_char[index] = ']';
//             }
//             index++;
//         }
//         else{
//             if(index==0){
//                 return false;
//             }
//             if(*s==store_char[index-1]){
//                 index--;
//             }
//             else{
//                 return false;
//             }
//         }
//         s++;
//     }
//     if(index==0){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

//这次程序修改了多次，存在以下几个问题：
//1、将字符串比对，之前就是将左括号直接存入，忽视了是配对的右括号，直接比对出错
//2、存储字符串的数组过小，之后可以判断字符串的长度来选择，现在选择10000也只是恰好通过所有测试用例，并不具普适性
//可以通过strlen(s)来获取字符串的长度，这样可以解决这个问题
//3、当第一字符是右括号时，要判断是否，虽然想到了，但是却无视了这个情况，导致判断是数组—1越界
//4、当只有一个字符是左括号时，要判断剩下的左括号数，虽然也想到了，但是当时想的是右括号会多，又无视了这个情况，导致出错
//提示：这次明白了runtime error是运行时出错，不是时间超过限制


//实现栈来解决这个问题
//执行用时 :4 ms, 在所有 C 提交中击败了65.55%的用户
//内存消耗 :8.2 MB, 在所有 C 提交中击败了5.07%的用户
//小括号 ：Parentheses,bracket 中括号：bracket 大括号：braces
typedef enum
{
    LEFT_PARENTHESES = '(',
    LEFT_BRACKET = '[',
    LEFT_BRACES = '{'
} LeftBrackets;

typedef enum
{
    RIGHT_PARENTHESES = ')',
    RIGHT_BRACKET = ']',
    RIGHT_BRACES = '}'
} RightBrackets;

typedef struct {
    char *base; //栈底
    char *top; //栈顶
    int cap; //最大容量
} Stack;

void InitStack(Stack *stack){
    stack->base = (char *)malloc(sizeof(char) * 10);
    stack->top = stack->base;
    stack->cap = 10;
}

void PushStack(Stack *stack, char e){
    if(stack->top-stack->base>=stack->cap){
        stack->base = (char *)realloc(stack->base, sizeof(char) * (stack->cap + 10));
        stack->top = stack->base + stack->cap;
        stack->cap += 10;
    }
    *(stack->top) = e;
    stack->top++;
}

char PopStack(Stack *stack){
    char e = *--stack->top;
    //*(stack->top - 1);
    //stack->top--;
    return e;
}

bool IsStackEmpty(Stack *stack){
    bool flag = false;
    if(stack->top==stack->base){
        flag = true;
    }
    return flag;
}

void DestoryStack(Stack *stack){
    free(stack->base);
    stack->base = stack->top = NULL;
    stack->cap = 0;
    free(stack);
}

bool isBracketValid(Stack *stack, char e){
    if(IsStackEmpty(stack)){
        DestoryStack(stack);
        return false;
    }
    char stackEle = PopStack(stack);
    //printf("%c", stackEle); //维测
    switch (e)
    {
        case RIGHT_PARENTHESES:
        //error: a label can only be part of a statement and a declaration is not a statement
        //在case结构中不应该进行变量声明
        //char e = PopStack(stack);
            if(stackEle!=LEFT_PARENTHESES){
                DestoryStack(stack);
                return false;
            }
            break;
        case RIGHT_BRACKET:
            if(stackEle!=LEFT_BRACKET){
                DestoryStack(stack);
                return false;
            }
            break;
        case RIGHT_BRACES:
            if(stackEle!=LEFT_BRACES){
                DestoryStack(stack);
                return false;
            }
            break;
        default:
            break;
    }
    return true;
}

bool isValid(char * s){
    if(s==NULL || strlen(s)==0){
        return true;
    }

    Stack *stack = (Stack *)malloc(sizeof(Stack));
    InitStack(stack);
    while(*s!='\0'){
        if(*s==LEFT_PARENTHESES||*s==LEFT_BRACKET||*s==LEFT_BRACES){
            PushStack(stack, *s);
        }
        else if(*s==RIGHT_PARENTHESES||*s==RIGHT_BRACKET||*s==RIGHT_BRACES){
            //printf("%c", *s); //维测
            if(isBracketValid(stack, *s)==false){
                return false;
            }
        }
        else{

        }
        s++;
    }
    //printf("%c", *s); //维测
    if(IsStackEmpty(stack)){
        return true;
    }
    return false;
}

//这里的栈顶指向的是最顶上元素的下一个位置的指针
