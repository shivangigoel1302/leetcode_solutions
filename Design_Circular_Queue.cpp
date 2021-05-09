class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    int* queue;
    int front ,rear;
    int size;
    MyCircularQueue(int k) {
        queue = new int[k];
        front = -1;
        rear = -1;
        size = k;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(front == 0 && rear == size-1){
            return false;
        }
        if(front == rear+1) return false;
        if(front == -1) front = 0;
        rear = (rear+1)%size;
        queue[rear] = value;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(front == -1){
            return false;
        }
        if(front == rear) front = rear = -1;
        else {
            front = (front+1)%size;

        }
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if(front == -1){
            return -1;
        }
        return queue[front];
    }

    /** Get the last item from the queue. */
    int Rear() {
         if(front == -1){
            return -1;
        }
        return queue[rear];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
         if(front == -1){
            return true;
        }
    return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if(front == 0 && rear == size-1){
            return true;
        }
        if(front == rear+1) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
