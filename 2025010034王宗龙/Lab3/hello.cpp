#include <iostream>

bool getDoubled(int value, int& result) {
    result = value * 2;
    return true;
}

int main() {
<<<<<<< HEAD
    std::cout << "姓名: 刘胜" << std::endl;
    std::cout << "学号: 2025010016" << std::endl;
=======
    std::cout << "姓名: 王宗龙" << std::endl;
    std::cout << "学号: 2025010034" << std::endl;
>>>>>>> 70e09ca42363699cc58d513f383552294016a8f2
    
    bool isStudent = true;
    std::cout << "是否为学生: " << isStudent << std::endl;
    
<<<<<<< HEAD
    int lastTwo = 16;
    int doubled;
    getDoubled(lastTwo, doubled);
    std::cout << lastTwo << " 的两倍是 " << doubled << std::endl;
=======
    int value = 34;
    int result;
    if (getDoubled(value, result)) {
        std::cout << value << " 的两倍是 " << result << std::endl;
    }
>>>>>>> 70e09ca42363699cc58d513f383552294016a8f2
    
    return 0;
}