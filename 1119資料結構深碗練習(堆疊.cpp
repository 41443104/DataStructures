#include <iostream>
using namespace std;

template <class T>
class Stack {
private:
    T* stack;   // 指向堆疊陣列的指標
    int top;    // 最上方元素的索引（-1 代表空堆疊）
    int box;    // 堆疊目前的最大容量

public:
    // 建構子_預設容量為 10
    Stack(int box = 10) 
    {
        this->box = box;         // 把傳入的容量存進成員變數 box
        stack = new T[this->box]; // 動態配置陣列記憶體
        top = -1;                // 初始化為空堆疊
    }

    // 解構子_釋放動態陣列記憶體
    ~Stack()
    {
        delete[] stack;
    }

    // 判斷堆疊是否為空
    bool IsEmpty() 
    {
        return top == -1; //如果top=-1就回傳true
    }

    // 回傳最上方元素的參考
    T& Top() {
        static T dummy = T(); // 空堆疊時的備用預設值
        if (IsEmpty()) 
        {
            cout << "堆疊裡沒東西!" << endl;
            return dummy; // 堆疊為空時提前回傳，避免存取到 stack[-1]
        }
        return stack[top]; // 回傳目前最上方元素的參考
    }

    // 將元素推入堆疊頂端（滿了就擴充為 2 倍）
    void Push(const T& item) 
    {
        if (top == box - 1) 
        {
            int newbox = box * 2;
            T* newStack = new T[newbox];

            // 將舊陣列的元素複製到新陣列
            for (int i = 0; i <= top; i++) 
            {
                newStack[i] = stack[i];
            }

            delete[] stack; // 釋放舊陣列
            stack = newStack; // 讓成員指標 stack 改指向新陣列
            box = newbox; // 更新目前的最大容量紀錄
        }

        top++;              // 頂端索引往上移
        stack[top] = item;  // 放入新元素
    }

    // 移除堆疊頂端元素
    void Pop() 
    {
        if (IsEmpty()) 
        {
            cout << "堆疊裡沒東西! 無法移除." << endl;
            return;
        }
        top--; // 頂端索引往下移，移除最上方元素
    }

    // 輔助功能：從底到頂印出堆疊內容
    void Display() 
    {
        if (IsEmpty())
        {
            cout << "堆疊裡沒東西." << endl;
            return;
        }
        cout << "Stack (尾 -> 頭): ";
        for (int i = 0; i <= top; i++) 
        {
            cout << stack[i];
            if (i < top) cout << " -> "; // 最後一個元素後方不加箭頭
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s; // 使用預設容量 10
    int choice = -1;
    int value;

    while (choice != 0) 
    {
        cout << "\n=== Stack Menu ===" << endl;
        cout << "1. Push(插入)" << endl;
        cout << "2. Pop(拿出)" << endl;
        cout << "3. Top(第一項)" << endl;
        cout << "4. IsEmpty(檢查)" << endl;
        cout << "5. Display(顯示)" << endl;
        cout << "0. Exit(離開)" << endl;
        cout << "選擇: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "輸入數字: ";
            cin >> value;
            s.Push(value);
            cout << "插入 " << value << " 成功." << endl;
            break;

        case 2:
            if (!s.IsEmpty())
            {
                cout << "移除: " << s.Top() << endl;
                s.Pop();
            }
            else {
                cout << "堆疊裡沒東西! 無法移除." << endl;
            }
            break;

        case 3:
            if (!s.IsEmpty()) {
                cout << "第一項: " << s.Top() << endl;
            }
            else {
                s.Top();
            }
            break;

        case 4:
            if (s.IsEmpty()) {
                cout << "堆疊是空 (true)." << endl;
            }
            else {
                cout << "堆疊不是空的 (false)." << endl;
            }
            break;

        case 5:
            s.Display();
            break;

        case 0:
            cout << "離開 Stack Menu..." << endl;
            break;

        default:
            cout << "選擇無效,請重新輸入." << endl;
        }
    }

    return 0;
}