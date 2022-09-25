class MyCircularQueue {
private:
    int size = 0;
    int startIndex = 0,endIndex=0;
    int count = 0;
    vector<int> v;
public:
    MyCircularQueue(int k) {
        size = k;
        v = vector<int>(k);
    }
    
    bool enQueue(int value) {
        if(count ==size)return false;
        v[endIndex] = value;
        endIndex  = endIndex==size-1 ? 0 : endIndex+1;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(count ==0)return false;
        v[startIndex]=-1;
        startIndex  = startIndex==size-1 ? 0 : startIndex+1;
        count--;
        return true;
    }
    
    int Front() {
        if(count == 0)return -1;
        return v[startIndex];
        
    }
    
    int Rear() {
        if(count == 0)return -1;
        
        return endIndex==0 ?v[size-1] : v[endIndex-1];
    }
    
    bool isEmpty() {
        return count ==0;
    }
    
    bool isFull() {
        return count ==size;
    }
};
/*
3 1,2,3,4
8 3,9,5,0
*/

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