/*
    1、从右向左，若当前位置能跳到的位置中有能跳到最后一个位置的位置则可，最后判断第一个位置可不可
    2、从右向左，若有能一步跳到最后一个位置的位置则可，最后判断第一个位置即可，比第一种可以减少每个位置上对每种选择反复的判断但不能保证所用步数最短
    3、贪婪算法，从左向右，判断每一步能跳到的最大位置，若最终最大位置到了末尾则可，可以保证所用步数最短
*/

//第一种方法
// bool canJump(int* nums, int numsSize){
//     //执行用时 :700 ms, 在所有 C 提交中击败了20.87%的用户
//     //内存消耗 :8.5 MB
//     if(numsSize==0){
//         return false;
//     }
//     int *canJumpPos = (int *)malloc(sizeof(int) * numsSize); //代表当前位置能否跳到最后一个位置
//     memset(canJumpPos, 0, sizeof(int) * numsSize);
//     canJumpPos[numsSize - 1] = 1;
//     int i;
//     for (i = numsSize - 2; i >= 0;i--){
//         //1、当前位置能跳到最后一个位置
//         //2、当前能跳到的位置中有能跳到最后一个位置的位置
//         if ((i + nums[i]) >= numsSize - 1)
//         {
//             canJumpPos[i] = 1;
//         }
//         int j;
//         for (j = 1; j <= nums[i];j++){
//             if(canJumpPos[i+j]==1){
//                 canJumpPos[i] = 1;
//                 break;
//             }
//         }
//     }
//     bool flag = false;
//     if(canJumpPos[0]==1){
//         flag = true;
//     }
//     return flag;
// }

//第二种方法，代码简洁，时间复杂度也很低
// bool canJump(int* nums, int numsSize){
//     //执行用时 :8 ms, 在所有 c 提交中击败了99.37%的用户
//     //内存消耗 :8.2 MB, 在所有 c 提交中击败了69.79%的用户
//     if(numsSize==0){
//         return false;
//     }
//     int canJumpPos = numsSize - 1; //表示可以跳到最后一个位置的位置
//     int i;
//     for (i = numsSize - 2; i >= 0;i--){
//         if (i + nums[i] >= canJumpPos)
//         {
//             canJumpPos = i;
//         }
//     }
//     bool flag = false;
//     if(canJumpPos==0){
//         flag = true;
//     }
//     return flag;
// }

//第三种方法，贪婪算法
bool canJump(int* nums, int numsSize){
    //执行用时 :12 ms, 在所有 c 提交中击败了85.43%的用户
    //内存消耗 :8.2 MB, 在所有 c 提交中击败了71.87%的用户
    if(numsSize==0){
        return false;
    }
    int maxPos = 0; //代表在当前边界内、下一步数走的最远的位置
    int steps = 0; //表示当前步数
    int posEnd = 0; //表示当前步数下的走的最远位置即边界

    int i;
    for (i = 0; i < numsSize - 1;i++){
        maxPos = (maxPos > (i + nums[i])) ? maxPos : (i + nums[i]);
        if(i==posEnd){
            //当前最大边界不比前边界大则应退出
            if(maxPos==posEnd){
                break;
            }
            posEnd = maxPos;
            steps++;
        }
    }
    bool flag = false;
    if (maxPos >= numsSize - 1)
    {
        flag = true;
    }
    return flag;
}