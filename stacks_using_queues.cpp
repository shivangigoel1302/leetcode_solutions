class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    queue<int>q;
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    void reverse(queue<int>&q)
    {
        if(q.empty())
    {
        return;
    }
    int firstelement=q.front();
    q.pop();
    reverse(q);
    q.push(firstelement);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        reverse(q);
        int a=q.front();
        q.pop();
        reverse(q);
        return a;
    }

    /** Get the top element. */
    int top() {
        reverse(q);
        int a=q.front();
        reverse(q);
        return a;
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        if(!q.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
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
