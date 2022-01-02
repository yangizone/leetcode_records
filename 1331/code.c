/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//用hash表更好，但是有重复的值我还是以后再考虑怎么用
// struct hash_entry {
//     int id;            /* we'll use this field as the key */
//     int value;
//     UT_hash_handle hh; /* makes this structure hashable */
// };

// struct hash_entry *users = NULL;

// void add_user(struct hash_entry *s) {
//     HASH_ADD_INT(users, id, s);
// }

// struct hash_entry *find_user(int user_id) {
//     struct hash_entry *s;
//     HASH_FIND_INT(users, &user_id, s);
//     return s;
// }

// int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
//     *returnSize=0;
//     int *res = (int *)malloc(sizeof(int) * arrSize);
//     memset(res, 0, sizeof(int) * arrSize);
//     int i;
//     for (i = 0; i < arrSize;i++){
//         struct 
//         HASH_ADD_INT(users, id, s);
//     }
// }

int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
    *returnSize=0;
    int *res = (int *)malloc(sizeof(int) * arrSize);
    memset(res, 0, sizeof(int) * arrSize);
    //暴力破解
    //快排
    int temp = (int *)malloc(sizeof(int) * (arrSize + 1));
    memcpy(temp, arr, sizeof(int) * (arrSize + 1));
    memset(temp, '\0', sizeof(int) * (arrSize + 1));
    qsort(temp, arrSize, sizeof(int), cmp);
    int i;
    // for (i = 0; i < arrSize;i++){
    //     printf("%d ", arr[i]);
    // }
    for (i = 0; i < arrSize;i++){
        int j;
        for (j = 0; j < arrSize;j++){
            if(arr[j]==)
        }
    }
        return res;
}
