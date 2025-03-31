//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//
//你的实现应该支持如下操作：
//
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。
// 数组实现,因此front和rear都只需要用整型表示下标来访问即可

#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int* a;
    int front;
    int rear;
    int k;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    // 初始化
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->a = (int*)malloc(sizeof(int) * (k + 1));
    obj->front = obj->rear = 0;
    obj->k = k;

    return obj;
}

// 当front=rear就为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->front == obj->rear;
}

// rear+1=front就为满,需要取模保证在数组大小范围内
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    // 为满则插入失败，返回false
    if (myCircularQueueIsFull(obj)) {
        return false;
    }

    // 不为满，在rear位置插入数据，rear++，且要取模保证范围
    obj->a[obj->rear] = value;
    obj->rear = (obj->rear + 1) % (obj->k + 1);
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    // 为空则删除失败
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    // 不为空，front++
    obj->front++;
    (obj->front) %= (obj->k + 1);

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    // 为空返回-1
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    else {
        return obj->a[obj->front];
    }
}

int myCircularQueueRear(MyCircularQueue* obj) {
    // 为空返回-1
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    // 当rear在下标为0的位置，-1访问数组会出错（假设k=4）
    // 因此(rear-1+k+1)%(k+1)
    // return obj->a[(obj->rear-1+(obj->k)+1)%(obj->k+1)];
    // 或者当rear在0的时候，知道尾元素在数组最后一个位置
    // 否则就是在下标为rear-1的位置
    else {
        return obj->a[(obj->rear - 1 + obj->k + 1) % (obj->k + 1)];
    }
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->a);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/