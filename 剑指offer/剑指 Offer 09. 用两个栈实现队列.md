## 题面

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

 

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## 解题思路

```c++
class CQueue {
public:
    stack<int> now, backup;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        now.push(value);
    }
    
    int deleteHead() {
        int t = -1;
        if(!backup.empty()) // 缓冲区非空，先出去
        {
            t = backup.top();
            backup.pop();
            return t;
        }

        if(now.empty()) return t; // 缓冲区空且存储区空，说明队列空

        while(!now.empty()) // 存储区放入缓冲区
        {
            t = now.top();
            backup.push(t);
            now.pop();
        }

        t = backup.top();
        backup.pop();
        return t;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

