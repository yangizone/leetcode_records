bool isValid(char * s){
    if(s==NULL){
        return false;
    }
    //将三个字符标为三类，遇到左右括号就进行对比
    // '(' 0 '{' 1 '[' 2 或者直接存储为char数组对比
    int index=0; //代表最新的左括号的下标
    char store_char[10000]; //依次存储字符串的左括号
    while(*s!='\0'){
        if(*s=='('||*s=='{'||*s=='['){
            if(*s=='('){
                store_char[index] = ')';
            }
            if(*s=='{'){
                store_char[index] = '}';
            }            
            if(*s=='['){
                store_char[index] = ']';
            }
            index++;
        }
        else{
            if(index==0){
                return false;
            }
            if(*s==store_char[index-1]){
                index--;
            }
            else{
                return false;
            }
        }
        s++;
    }
    if(index==0){
        return true;
    }
    else{
        return false;
    }
}

//这次程序修改了多次，存在以下几个问题：
//1、将字符串比对，之前就是将左括号直接存入，忽视了是配对的右括号，直接比对出错
//2、存储字符串的数组过小，之后可以判断字符串的长度来选择，现在选择10000也只是恰好通过所有测试用例，并不具普适性
//3、当第一字符是右括号时，要判断是否，虽然想到了，但是却无视了这个情况，导致判断是数组—1越界
//4、当只有一个字符是左括号时，要判断剩下的左括号数，虽然也想到了，但是当时想的是右括号会多，又无视了这个情况，导致出错
//提示：这次明白了runtime error是运行时出错，不是时间超过限制
