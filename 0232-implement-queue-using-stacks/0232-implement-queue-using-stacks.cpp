class MyQueue {
public:// will perform amortised 0(1) time complexity;
    stack<int>st1;
    stack<int>st2;
    int ele;// it will take care of peak element and will reduce the tc of peak to 0(1);
    MyQueue() {
        
    }
    // push is 0(1)
    void push(int x) {
        if(st1.empty()){
            ele=x;
        }
        st1.push(x);
    }
    // pop is 0(1) if st2 is non empty and sometimes 0(n) incase of empty st2
    int pop() {
        if(st2.empty()){// 0(n) only if st2 is empty
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int num=st2.top();
        st2.pop();
        return num;
    }
    
    int peek() {
        if(!st2.empty()) return st2.top();
        else return ele;
    }
    
    bool empty() {
        if(st1.empty()&&st2.empty()) return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */