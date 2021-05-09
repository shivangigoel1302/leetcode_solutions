class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int lmt;
    int queue[401];
    int size = 0;
    int front;
    MyCircularDeque(int k) {

        front = 200;
        lmt = k;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        size++;
        queue[front--] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        queue[front + ++size] = value;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        size--;
        front++;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        size--;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if(isEmpty()) return -1;
        return queue[front+1];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if(isEmpty()) return -1;
        return queue[front + size];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return !size;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(lmt == size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
