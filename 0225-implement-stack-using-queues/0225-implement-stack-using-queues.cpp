class MyStack {
public:
    queue<int>qt1;
    MyStack() {
        
    }
    
    void push(int x) {
        qt1.push(x);
        for(int i=0;i<qt1.size()-1;i++){
            qt1.push(qt1.front());
            qt1.pop();
        }
    }
    
    int pop() {
        int ele=qt1.front();
        qt1.pop();
        return ele;
    }
    
    int top() {
        return qt1.front();
    }
    
    bool empty() {
        if(qt1.size()==0) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */