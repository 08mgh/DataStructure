#include <iostream>

class IntVector {
private:
    int* data;
    int size;
    int capacity;

    void expand() {
        if (size < capacity)
            return;
        int newCap = (capacity == 0) ? 4 : capacity * 2;
        int* newData = new int[newCap];
        // ✅ 只有capacity>0，data才不是空指针，才拷贝元素
        if(capacity > 0)
        {
            for (int i = 0; i < size; ++i)
            {
                newData[i] = data[i];
            }
        }
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    explicit IntVector(int initialCapacity = 4) {
        // ✅ 先修正initialCapacity
        if (initialCapacity < 1)
            initialCapacity = 1;
        data = nullptr;
        size = 0;
        capacity = initialCapacity;
        data = new int[capacity];
    }

    ~IntVector() {
        delete[] data;
    }

    IntVector(const IntVector&) = delete;
    IntVector& operator=(const IntVector&) = delete;

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    bool empty() const {
        return size == 0;
    }

    // ✅【修复get】非法下标，不修改value，直接return false
    bool get(int index, int& value) const {
        if (index < 0 || index >= size)
        {
            return false;
        }
        value = data[index];
        return true;
    }

    int find(int value) const {
        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
                return i;
        }
        return -1;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > size)
            return false;
        expand();
        for (int i = size; i > index; i--)
        {
            data[i] = data[i-1];
        }
        data[index] = value;
        size++;
        return true;
    }

    // ✅【修复remove】非法下标，不修改removed，直接return false
    bool remove(int index, int& removed) {
        if (index < 0 || index >= size)
        {
            return false;
        }
        removed = data[index];
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i+1];
        }
        size--;
        return true;
    }

    void pushBack(int value) {
        insert(size, value);
    }

    void print() const {
        for (int i = 0; i < size; i++)
        {
            if (i > 0)
                std::cout << " ";
            std::cout << data[i];
        }
        std::cout << std::endl;
    }
};

// ========== main函数【原样完全保留，一点都不要删改！！】==========
int main()
{
    IntVector v;
    int val, rem;
    std::cout << "空表: size = " << v.getSize() << ", capacity = " << v.getCapacity() << ", empty = " << v.empty() << std::endl;

    bool ok = v.get(0, val);
    std::cout << "空表 get(0) 返回 " << ok << ", value = " << val << std::endl;

    ok = v.remove(0, rem);
    std::cout << "空表 remove(0) 返回 " << ok << ", removed = " << rem << std::endl;

    v.pushBack(10);
    v.pushBack(20);
    v.pushBack(30);
    v.pushBack(40);
    std::cout << "首次装满: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    ok = v.insert(5,99);
    std::cout << "满表 insert(5, 99) 返回 " << ok << ", size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    v.pushBack(50);
    std::cout << "追加 50 后: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    ok = v.insert(0,5);
    std::cout << "表头 insert(0, 5) 返回 " << ok << std::endl;
    v.print();

    ok = v.insert(3,25);
    std::cout << "中间 insert(3, 25) 返回 " << ok << std::endl;
    v.print();

    ok = v.insert(v.getSize(),60);
    std::cout << "表尾插入 60 返回 " << ok << std::endl;
    v.print();

    std::cout << "再次装满: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    ok = v.insert(4,28);
    std::cout << "满表 insert(4, 28) 返回 " << ok << ", size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    ok = v.remove(0, rem);
    std::cout << "remove(0) 返回 " << ok << ", removed = " << rem << std::endl;
    v.print();

    ok = v.remove(3, rem);
    std::cout << "remove(3) 返回 " << ok << ", removed = " << rem << std::endl;
    v.print();

    ok = v.remove(v.getSize()-1, rem);
    std::cout << "删除表尾 返回 " << ok << ", removed = " << rem << std::endl;
    v.print();

    std::cout << "删除后: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;

    ok = v.get(3, val);
    std::cout << "get(3) 返回 " << ok << ", value = " << val << std::endl;

    std::cout << "find(30) = " << v.find(30) << std::endl;
    std::cout << "find(99) = " << v.find(99) << std::endl;

    ok = v.get(v.getSize(), val);
    std::cout << "get(size) 返回 " << ok << ", value = " << val << std::endl;
    ok = v.get(-1, val);
    std::cout << "get(-1) 返回 " << ok << ", value = " << val << std::endl;

    ok = v.remove(v.getSize(), rem);
    std::cout << "remove(size) 返回 " << ok << ", removed = " << rem << std::endl;
    ok = v.remove(-1, rem);
    std::cout << "remove(-1) 返回 " << ok << ", removed = " << rem << std::endl;

    ok = v.insert(-1,99);
    std::cout << "insert(-1, 99) 返回 " << ok << std::endl;
    std::cout << "非法操作后: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    // 删除全部【！！这里保留原来while，绝对不能改成for循环！！】
    while(!v.empty())
    {
        v.remove(0, rem);
    }
    std::cout << "删除全部: size = " << v.getSize() << ", capacity = " << v.getCapacity() << ", empty = " << v.empty() << std::endl;
    v.print();

    v.pushBack(-1);
    std::cout << "清空后追加: size = " << v.getSize() << ", capacity = " << v.getCapacity() << std::endl;
    v.print();

    IntVector small(0);
    std::cout << "初始容量传 0: size = " << small.getSize() << ", capacity = " << small.getCapacity() << std::endl;
    small.pushBack(7);
    small.pushBack(7);
    std::cout << "small: size = " << small.getSize() << ", capacity = " << small.getCapacity() << std::endl;
    small.print();
    std::cout << "small.find(7) = " << small.find(7) << std::endl;

    IntVector negative(-3);
    std::cout << "初始容量传 -3: size = " << negative.getSize() << ", capacity = " << negative.getCapacity() << std::endl;
    std::cout << "v 仍为: ";
    v.print();
    std::cout << "各对象的 size: " << v.getSize() << " " << small.getSize() << " " << negative.getSize() << std::endl;

    return 0;
}