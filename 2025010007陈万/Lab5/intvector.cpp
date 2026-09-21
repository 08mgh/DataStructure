#include <iostream>
class IntVector {
private:
    int* data;
    int size;
    int capacity;

    void expand() {
        // 如果还有容量，不需要扩容，直接返回
        if (size < capacity)
            return;
        // 没有空间了，扩容：一般扩为原来2倍
        int newCap = (capacity == 0) ? 4 : capacity * 2;
        int* newData = new int[newCap];
        // 拷贝旧数组元素到新数组
        for(int i = 0; i < size; i++){
            newData[i] = data[i];
        }
        delete[] data;  //释放旧内存
        data = newData;
        capacity = newCap;
    }

public:
    // 构造函数
    IntVector(){
        size = 0;
        capacity = 4;
        data = new int[capacity];
    }
    //析构函数，防止内存泄漏
    ~IntVector(){
        delete[] data;
    }

    // 在末尾添加元素
    void push_back(int val){
        expand();  //先检查扩容
        data[size++] = val;
    }

    // 获取索引位置元素
    int get(int idx){
        if(idx <0 || idx >= size){
            std::cout << "越界！";
            return -1;
        }
        return data[idx];
    }

    // 在指定位置插入元素
    void insert(int idx, int val){
        if(idx <0 || idx > size) return;
        expand();
        // 元素后移，从后往前挪
        for(int i = size; i > idx; i--){
            data[i] = data[i-1];
        }
        data[idx] = val;
        size++;
    }

    // 删除指定位置元素
    int remove(int idx){
        if(idx <0 || idx >= size) return -1;
        int res = data[idx];
        for(int i = idx; i < size-1; i++){
            data[i] = data[i+1];
        }
        size--;
        return res;
    }

    bool empty(){
        return size == 0;
    }

    void print(){
        for(int i=0;i<size;i++){
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    int getSize(){ return size; }
    int getCapacity(){ return capacity; }
};

int main() {
    IntVector v;
    std::cout << "size = " << v.getSize() << ", capacity = " << v.getCapacity() << ", empty = " << v.empty() << "\n";
    std::cout << "get(0) value = " << v.get(0) << "\n";
    std::cout << "remove(0), removed = " << v.remove(0) << "\n";

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    std::cout << "size = " << v.getSize() << ", capacity = " << v.getCapacity() << "\n";
    v.print();

    v.insert(5,99);
    std::cout << "insert(5,99) size = " << v.getSize() << ", capacity = " << v.getCapacity() << "\n";
    v.print();

    v.push_back(50);
    std::cout << "add 50, size = " << v.getSize() << "\n";
    v.print();
    return 0;
}
