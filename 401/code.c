/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** readBinaryWatch(int num, int* returnSize){
    *returnSize = 0;
    if(num==0){
        return NULL;
    }
    int hours[] = {0, 1, 2, 4, 8};
    int minutes[] = {0, 1, 2, 4, 8, 16, 32};
    char **result = (char **)malloc(sizeof(char * 1000));
    int i;
    for (i = 0;i<)
}