C++

priorty_queue<pair<int,int>> q
在优先队列中使用pair默认先比较第一个元素在比较第二个元素

binaray search中
int middle = low + (high - low) / 2  可以防止溢出，功能等效于(low + high) / 2
此外使用>>右移运算符 >>1 功能等于 /2 不过注意优先级顺序，移位运算符优先级低于+ - x /等

char类型与int类型之间转换要看ASCII码 
如'0' - '0' = 0
  '0' + 1 = '1'
例子：lc 67题
string a
for (int i = 0; i < a.size(); ++i)) {
    int carry = a[i] - '0';
}

BFS and DFS

DFS:有三种方式遍历树，前序中序后序 
例子lc 110

![image-20220730183644945](assets/image-20220730183644945.png)
