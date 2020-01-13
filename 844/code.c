typedef struct {
    char *base;
    char *top;
    int cap;
} Stack;

void InitStack(Stack *s){
    s->base = (char *)malloc(sizeof(char) * 10);
    s->top = s->base;
    s->cap = 10;
}

bool IsStackEmpty(Stack *s){
    return (s->top == s->base) ? true : false;
}

void PushStack(Stack *s, char e){
    if(s->top-s->base>=s->cap){
        s->base = (char *)realloc(s->base, sizeof(char) * (s->cap + 10));
        s->top = s->base + s->cap;
        s->cap += 10;
    }
    *(s->top) = e;
    s->top++;
}

char PopStack(Stack *s){
    if(!IsStackEmpty){
        return *--s->top;
    }
    return 0;
}

int StackLen(Stack *s){
    return s->top - s->base;
}

void DestoryStack(Stack *s){
    free(s->top);
    s->base = s->top = NULL;
    s->cap = 0;
    free(s);
}

bool backspaceCompare(char * S, char * T){
    Stack *stackS = (Stack *)malloc(sizeof(Stack));
    Stack *stackT = (Stack *)malloc(sizeof(Stack));
    InitStack(stackS);
    InitStack(stackT);

    while(*S!='\0'){
        if(*S=='#'){
            PopStack(stackS);
        }
        else if (isalpha(*S)){
            PushStack(stackS, *S);
        }
        else{

        }
        S++;
    }

    while(*T!='\0'){
        if(*T=='#'){
            PopStack(stackT);
        }
        else if (isalpha(*S)){
            PushStack(stackT, *T);
        }
        else{

        }
        T++;
    }
    //printf("运行到这了吗？"); //维测

    if(StackLen(stackS)!=StackLen(stackT)){
        //printf("%d ",StackLen(stackS)); //维测
        //printf("%d ",StackLen(stackT)); //维测
        DestoryStack(stackS);
        DestoryStack(stackT);
        return false;
    }
    while(StackLen(stackS)){
        if(PopStack(stackS)!=PopStack(stackT)){
            DestoryStack(stackS);
            DestoryStack(stackT);
            return false;
        }
    }
    //printf("%d",StackLen(stackS)); //维测
    DestoryStack(stackS);
    DestoryStack(stackT);
    return true;
}

//Push函数有问题，不知道怎么解决
/*
=================================================================
==29==ERROR: AddressSanitizer: attempting free on address which was not malloc()-ed: 0x602000000052 in thread T0
    #0 0x7f26454c7f30 in free (/usr/local/lib64/libasan.so.5+0xe7f30)
    #4 0x7f2643c192e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
0x602000000052 is located 2 bytes inside of 10-byte region [0x602000000050,0x60200000005a)
allocated by thread T0 here:
    #0 0x7f26454c82b0 in malloc (/usr/local/lib64/libasan.so.5+0xe82b0)
    #4 0x7f2643c192e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)
SUMMARY: AddressSanitizer: bad-free (/usr/local/lib64/libasan.so.5+0xe7f30) in free
==29==ABORTING
*/
//20/01/13 暂时排查到 PushStack和PopStack均有问题
