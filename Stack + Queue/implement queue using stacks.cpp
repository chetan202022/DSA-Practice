
// https://leetcode.com/problems/implement-queue-using-stacks/description/

class MyQueue {
public:

    stack<int> st1, st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st2.empty()){
            int a = st2.top(); st2.pop();
            st1.push(a);
        }
        st1.push(x);
        
    }
    
    int pop() {
        while(!st1.empty()){
            int a = st1.top(); st1.pop();
            st2.push(a);
        }
        if(!st2.empty()){ int a = st2.top(); st2.pop(); return a; }
        return -1;
    }
    
    int peek() {
        while(!st1.empty()){
            int a = st1.top(); st1.pop();
            st2.push(a);
        }
        if(!st2.empty()){ int a = st2.top(); return a; }
        return -1;
    }
    
    bool empty() {
        return (st1.empty() && st2.empty());
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
