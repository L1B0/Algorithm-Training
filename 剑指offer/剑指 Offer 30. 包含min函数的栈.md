## 题面

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2.


提示：

各函数的调用总次数不超过 20000 次

## 解题思路

```c++
class MinStack {
public:
    /** initialize your data structure here. */
    int *l, rr, *mini;
    MinStack() {
        rr = 0;
        l = new int[20001];
        mini = new int[20001];
    }
    
    void push(int x) {
        if(rr == 0) mini[rr] = x;
        else mini[rr]= mini[rr-1] > x ? x : mini[rr-1];
        l[rr++] = x;
    }
    
    void pop() {
        rr--;
    }
    
    int top() {
        if(rr)
            return l[rr-1];
        else
            return NULL;
    }
    
    int min() {
        if(rr)
            return mini[rr-1];
        else
            return NULL;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
```

