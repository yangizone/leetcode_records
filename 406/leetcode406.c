/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){  
    //根据已成功的C程序
    //可以得知：people代表输入的整数对，peopleSize代表人数即几个整数对,peopleColSize没用到我猜想应该代表(h,k)列数即2的意思
    //returnSize代表返回人数的指针即内容为peopleSize，returnColumnSizes代表整个整数队列的队列数的指针的指针
           
    //判断输入数据是否有效
    // if(people==NULL||peopleSize==0||peopleColSize==NULL){
    //     return NULL;
    // }
    
    //对输出结果动态分配内存，不能对输入数据进行修改（因为是指针）
    int **sort_people = (int **)malloc(peopleSize * sizeof(int *));
    //判断有无成功分配内存
    if(sort_people==NULL){
        return NULL;
    }
    int i;
    for (i = 0; i < peopleSize;i++){
        sort_people[i] = (int *)malloc(2 * sizeof(int));
        if(sort_people[i]==NULL){
            return NULL;
        }
        sort_people[i] = people[i]; //可以直接对指针赋值
    }

    //对输入的整数队列按身高升序排序，冒泡算法
    for (i = 0; i < peopleSize;i++){
        int j;
        for (j = 1; j < peopleSize-i;j++){
            //若身高更高，则下沉
            if(sort_people[j][0]<sort_people[j-1][0]){
                int *temp = NULL; //这里也是直接赋值指针
                temp = sort_people[j];
                sort_people[j] = sort_people[j - 1];
                sort_people[j - 1] = temp;
            }
            //若身高相等，则k值大的排后
            if(sort_people[j][0]==sort_people[j-1][0]){
                if(sort_people[j][1]<sort_people[j-1][1]){
                    int *temp = NULL; //这里也是直接赋值指针
                    temp = sort_people[j];
                    sort_people[j] = sort_people[j - 1];
                    sort_people[j - 1] = temp;
                }
            }
        }
    }

    //按k值排序，从尾到首
    for (i = peopleSize - 1; i >= 0;i--){
        int j = i - 1;
        int num=0;//表示排在这个人前面且身高等于h的人数
        while(j>=0&&sort_people[j][0]==sort_people[i][0]){
            num++;
            j--;
        }
        int offset = sort_people[i][1] - num;
        //不是交换，而是顺序向后偏移offset
        j = i;
        while((offset--)>0){
            int *temp = NULL;
            temp = sort_people[j];
            sort_people[j] = sort_people[j + 1];
            sort_people[j + 1] = temp;
            j++;
        }
    }

    *returnSize = peopleSize;
    *returnColumnSizes = (int *)malloc(peopleSize * sizeof(int));
    for (i = 0; i < peopleSize;i++){
        (*returnColumnSizes)[i] = 2;
    }
    return sort_people;
}

//现在这个程序存在调用空指针的问题，即返回值是指针，但该指针在函数局部变量区，返回时会被销毁所以采用malloc动态分配内存
//但这些在提示中也有，现在怀疑的是没有对动态分配内存的结果进行判断：安全性！但又报了新的错误
//AddressSanitizer: SEGV on unknown address 0x000000619d40 (pc 0x000000402307 bp 0x7ffdae2bb760 sp 0x7ffdae2bb710 T0)
//==30==The signal is caused by a WRITE memory access.
//这个错误是我误删了*returnColumnSizes的动态分配内存引起的

//最后通过了，但依旧有几个问题总结：
//1、最后通过了但是却没有判断数据正确性，因为people=[]始终过不去
//2、用到冒泡算法、贪心算法
//3、返回指针时要注意malloc动态分配内存