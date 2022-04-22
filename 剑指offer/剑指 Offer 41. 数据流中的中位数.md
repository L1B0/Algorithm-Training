```c++
class MedianFinder {
public:
    /** initialize your data structure here. */
    typedef struct mynode{
        int val;
        struct mynode *pre,*next;
        mynode(int x) : val(x), pre(NULL), next(NULL) {}
    }mynode;

    int nums;
    mynode *mid;
    MedianFinder() {
        nums = 0;
        mid = NULL;
    }
    
    void addNum(int num) {
        
        mynode *temp = new mynode(num), *t;

        if(mid == NULL){
            mid = temp;
        }
        else{

            if(mid->val > temp->val){
                t = mid;
                while(t->pre != NULL && t->pre->val > temp->val) t = t->pre;

                if(t->pre != NULL)
                    t->pre->next = temp;
                temp->pre = t->pre;
                t->pre = temp;
                temp->next = t;
                
            }
            else{
                t = mid;
                while(t->next != NULL && t->next->val <= temp->val) t = t->next;

                if(t->next != NULL)
                    t->next->pre = temp;
                temp->next = t->next;
                t->next = temp;
                temp->pre = t;
            }

            if(nums % 2 == 1 && mid->val > temp->val){
                mid = mid->pre;
            }
            else if(nums % 2 == 0 && mid->val <= temp->val){
                mid = mid->next;
            }
        }

        nums ++;
    }
    
    double findMedian() {
        if(nums % 2 == 1) return (double)mid->val;
        return ((double)mid->val + (double)mid->next->val)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

有序双向链表

```

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        else{
            left.push(num);
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) return ((double)left.top()+(double)right.top())/2;
        return (double)left.top();
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
```

left 最大堆 right 最小堆，更新哪个不能直接放进去，先放进另一个。