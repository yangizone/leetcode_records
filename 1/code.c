/**
 * Note: The returned array must be malloced, assume caller calls free().
 */



//leetcode官方对C语言的注释
// 编译时，将会采用-O1级优化。 AddressSanitizer也被开启来检测out-of-bounds和use-after-free错误。

// 为了使用方便，大部分标准库的头文件已经被自动导入。

// 如想使用哈希表运算, 您可以使用 uthash。 "uthash.h"已经默认被导入。请看如下示例:

// 1. 往哈希表中添加一个对象：

// struct hash_entry {
//     int id;            /* we'll use this field as the key */
//     char name[10];
//     UT_hash_handle hh; /* makes this structure hashable */
// };

// struct hash_entry *users = NULL;

// void add_user(struct hash_entry *s) {
//     HASH_ADD_INT(users, id, s);
// }
// 2. 在哈希表中查找一个对象：

// struct hash_entry *find_user(int user_id) {
//     struct hash_entry *s;
//     HASH_FIND_INT(users, &user_id, s);
//     return s;
// }



// 详见官方代码tests/example.c
// #include <stdio.h>   /* gets */
// #include <stdlib.h>  /* atoi, malloc */
// #include <string.h>  /* strcpy */
// #include "uthash.h"

// struct my_struct {
//     int id;                    /* key */
//     char name[10];
//     UT_hash_handle hh;         /* makes this structure hashable */
// };

// struct my_struct *users = NULL;

// void add_user(int user_id, char *name) {
//     struct my_struct *s;

//     HASH_FIND_INT(users, &user_id, s);  /* id already in the hash? */
//     if (s==NULL) {
//       s = (struct my_struct *)malloc(sizeof *s);
//       s->id = user_id;
//       HASH_ADD_INT( users, id, s );  /* id: name of key field */
//     }
//     strcpy(s->name, name);
// }

// struct my_struct *find_user(int user_id) {
//     struct my_struct *s;

//     HASH_FIND_INT( users, &user_id, s );  /* s: output pointer */
//     return s;
// }

// void delete_user(struct my_struct *user) {
//     HASH_DEL(users, user);  /* user: pointer to deletee */
//     free(user);
// }

// void delete_all() {
//   struct my_struct *current_user, *tmp;

//   HASH_ITER(hh, users, current_user, tmp) {
//     HASH_DEL(users, current_user);  /* delete it (users advances to next) */
//     free(current_user);             /* free it */
//   }
// }

// void print_users() {
//     struct my_struct *s;

//     for(s=users; s != NULL; s=(struct my_struct*)(s->hh.next)) {
//         printf("user id %d: name %s\n", s->id, s->name);
//     }
// }

// int name_sort(struct my_struct *a, struct my_struct *b) {
//     return strcmp(a->name,b->name);
// }

// int id_sort(struct my_struct *a, struct my_struct *b) {
//     return (a->id - b->id);
// }

// void sort_by_name() {
//     HASH_SORT(users, name_sort);
// }

// void sort_by_id() {
//     HASH_SORT(users, id_sort);
// }

// int main(int argc, char *argv[]) {
//     char in[10];
//     int id=1, running=1;
//     struct my_struct *s;
//     unsigned num_users;

//     while (running) {
//         printf(" 1. add user\n");
//         printf(" 2. add/rename user by id\n");
//         printf(" 3. find user\n");
//         printf(" 4. delete user\n");
//         printf(" 5. delete all users\n");
//         printf(" 6. sort items by name\n");
//         printf(" 7. sort items by id\n");
//         printf(" 8. print users\n");
//         printf(" 9. count users\n");
//         printf("10. quit\n");
//         gets(in);
//         switch(atoi(in)) {
//             case 1:
//                 printf("name?\n");
//                 add_user(id++, gets(in));
//                 break;
//             case 2:
//                 printf("id?\n");
//                 gets(in); id = atoi(in);
//                 printf("name?\n");
//                 add_user(id, gets(in));
//                 break;
//             case 3:
//                 printf("id?\n");
//                 s = find_user(atoi(gets(in)));
//                 printf("user: %s\n", s ? s->name : "unknown");
//                 break;
//             case 4:
//                 printf("id?\n");
//                 s = find_user(atoi(gets(in)));
//                 if (s) delete_user(s);
//                 else printf("id unknown\n");
//                 break;
//             case 5:
//                 delete_all();
//                 break;
//             case 6:
//                 sort_by_name();
//                 break;
//             case 7:
//                 sort_by_id();
//                 break;
//             case 8:
//                 print_users();
//                 break;
//             case 9:
//                 num_users=HASH_COUNT(users);
//                 printf("there are %u users\n", num_users);
//                 break;
//             case 10:
//                 running=0;
//                 break;
//         }
//     }

//     delete_all();  /* free any structures */
//     return 0;
// }



//学习LeetCode上的C语言hash表的使用，不使用暴力破解
//执行用时 :16 ms, 在所有 C 提交中击败了88.84%的用户
//内存消耗 :9.7 MB, 在所有 C 提交中击败了5.04%的用户
//uthash不允许有相同的key不同的value加入，这也合理
//但是要是将id和value都赋值为value就会出现nums出现相同的元素而不能同时放入uthash的情况
//换个思路，可以将id存value去索引，value存数组索引id作为结果取出，但这样可能使得Hash表会很大
struct hash_entry {
    int id; //存储数组中的整数
    int value; //存储该整数在数组中的下标
    UT_hash_handle hh; /* makes this structure hashable */
};

struct hash_entry *users = NULL;

void add_user(int user_id, int user_value){
    struct hash_entry *user_temp;
    HASH_FIND_INT(users, &user_id, user_temp);
    if(user_temp==NULL){
        user_temp = (struct hash_entry *)malloc(sizeof(struct hash_entry));
        user_temp->id = user_id;
        user_temp->value = user_value;
        HASH_ADD_INT(users, id, user_temp);
    }
}

struct hash_entry *find_user(int user_id) {
    struct hash_entry *user_temp;
    HASH_FIND_INT(users, &user_id, user_temp);
    return user_temp;
}

void delete_user(struct hash_entry *user) {
    HASH_DEL(users, user);
    free(user);
}

void delete_all() {
    struct hash_entry *current_user, *tmp;
    HASH_ITER(hh, users, current_user, tmp) {
        delete_user(current_user);
    }
}

void print_users() {
    struct hash_entry *s;
    for(s=users; s != NULL; s=(struct my_struct*)(s->hh.next)) {
        printf("user id %d: value %s\n", s->id, s->value);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    if(nums==NULL || numsSize==0){
        //下面这个要注意
        *returnSize = 0;
        return 0;
    }
    int *res = (int *)malloc(sizeof(int) * 2);
    int i;
    for (i = 0; i < numsSize;i++){
        add_user(nums[i], i);
    }
    //print_users();

    struct hash_entry *user = NULL;
    //for循环实现查找
    for (i = 0; i < numsSize; i++)
    {
        int temp = target - nums[i]; //在hash表中需要查找的键值
        //有个问题，HASH_FIND_INT找到的是第一个符合key的value吗？
        //一般情况下，一个Key对应一个value
        //按照我现在的做法就会出现一个Key对应多个value的情况
        //但这题题目也没保证但用例也没出现超过两个相同的情况，那么下面代码也适用，但之后还需要考虑细节
        user = find_user(temp);
        //还需要考虑返回的和当前数不能是同一个元素
        if(user!=NULL&&user->value!=i){
            res[0] = i;
            res[1] = user->value;
            delete_all();
            return res;
        }
    }

    //uthash循环实现查找，下面代码有问题
    //在[3,3] 6就会出现问题
    // struct hash_entry *curr_user, *tmp;
    // HASH_ITER(hh, users, curr_user, tmp){
    //     int temp = target - curr_user->id;
    //     user = find_user(temp);
    //     if(user!=NULL&&user->value!=curr_user->value){
    //         res[0] = curr_user->value;
    //         res[1] = user->value;
    //         delete_all();
    //         return res;
    //     }
    // }

    delete_all();
    return 0;
}

//之后还需要考虑的细节：
//1、现在的做法会导致Key对应多个value的情况，怎么改进？
//2、怎么可以写必要的函数来避免代码的定式？
//即只写需要的函数，其他可以内化在代码中而不用提取
//当然为了代码可读性，必要的重构也可以
//问题：
//虽然代码AC了，但是自验证时却发现了一些问题
//1、出现下面问题
//Line 207: Char 3: runtime error: load of null pointer of type 'int' (__Serializer__.c)
//2、print_users()时打印[3,3]时出现
//user id 3: value (null)
//3、用HASH_ITER循环居然失败