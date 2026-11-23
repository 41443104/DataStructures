#include <iostream>
using namespace std;
template <class T>
class Queue {
private:
    T* queue;   // 指向動態配置陣列的指標
    int front;  // 佇列最前端的元素
    int rear;   // 佇列最後端的元素
    int count;  // 目前佇列中實際的元素數量
    int box;    // 佇列陣列目前的最大容量

public:
    // 建構子_預設容量為 10，初始化索引與計數器
    Queue(int queueCapacity = 10) 
    {
        box = queueCapacity;
        queue = new T[box]; // 動態配置陣列記憶體
        front = 0;
        rear = -1;
        count = 0;
    }

    // 解構子_釋放動態陣列記憶體
    ~Queue()
    {
        delete[] queue;
    }

    // 判斷佇列是否為空
    bool IsEmpty()
    {
        return count == 0;
    }

    // 回傳最前端的元素
    T& Front()
    {
        static T dummy = T(); // 佇列為空時的備用預設值
        if (IsEmpty())
        {
            cout << "佇列裡沒東西!" << endl;
            return dummy;
        }
        return queue[front];
    }

    // 回傳最後端的元素
    T& Rear() 
    {
        static T dummy = T(); // 佇列為空時的備用預設值
        if (IsEmpty())
        {
            cout << "佇列裡沒東西!" << endl;
            return dummy;
        }
        return queue[rear];
    }

    // 將元素加入佇列尾端；若已滿則擴充容量為原本的 2 倍
    void Push(const T& item)
    {
        // 當元素數量達到最大容量時，進行陣列*2
        if (count == box)
        {
            int newBox = box * 2;
            T* newQueue = new T[newBox];

            // 依照排隊順序複製到新陣列
            for (int i = 0; i < count; i++)
            {
                newQueue[i] = queue[(front + i) % box];
            }

            delete[] queue;     // 釋放舊陣列記憶體
            queue = newQueue;   // 指向新陣列
            box = newBox;       // 更新容量上限
            front = 0;          // 新陣列從索引 0 開始
            rear = count - 1;   // 尾端落在第 count - 1 格
        }

        // 尾端索引環狀前進一格並存入新元素
        rear = (rear + 1) % box;
        queue[rear] = item;
        count++;
    }

    // 移除佇列最前端的元素（先進先出）
    void Pop() 
    {
        if (IsEmpty())
        {
            cout << "佇列裡沒東西! 無法移除." << endl;
            return;
        }
        // 前端索引環狀前進一格，並減少元素數量
        front = (front + 1) % box;
        count--;
    }

    // 顯示_從最前面（Front）到最後面（Rear）印出佇列內容
    void Display() {
        if (IsEmpty()) {
            cout << "佇列裡沒東西." << endl;
            return;
        }
        cout << "Queue (第一項 -> 最後一項): ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % box];
            if (i < count - 1) cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Queue<int> q; // 使用預設容量 10
    int choice = -1;
    int value;

    while (choice != 0) {
        cout << "\n=== Queue Menu ===" << endl;
        cout << "1. Push(插入)" << endl;
        cout << "2. Pop(移除)" << endl;
        cout << "3. Front(第一項)" << endl;
        cout << "4. Rear(最後一項)" << endl;
        cout << "5. IsEmpty(檢查)" << endl;
        cout << "6. Display(顯示)" << endl;
        cout << "0. Exit(離開)" << endl;
        cout << "選擇: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            cout << "輸入數字: ";
            cin >> value;
            q.Push(value);
            cout << "插入 " << value << " 成功." << endl;
            break;

        case 2: 
            if (!q.IsEmpty()) {
                cout << "移除: " << q.Front() << endl;
                q.Pop();
            }
            else {
                q.Pop(); // 印出空佇列提示
            }
            break;

        case 3:
            if (!q.IsEmpty()) {
                cout << "第一項: " << q.Front() << endl;
            }
            else {
                q.Front();
            }
            break;

        case 4: 
            if (!q.IsEmpty()) {
                cout << "最後一項: " << q.Rear() << endl;
            }
            else {
                q.Rear();
            }
            break;

        case 5: 
            if (q.IsEmpty()) {
                cout << "佇列是空的 (true)." << endl;
            }
            else {
                cout << "佇列不是空的 (false)." << endl;
            }
            break;

        case 6: 
            q.Display();
            break;

        case 0: 
            cout << "離開 Queue Menu..." << endl;
            break;

        default:
            cout << "輸入無效,請重新輸入." << endl;
            break;
        }
    }

    return 0;
}