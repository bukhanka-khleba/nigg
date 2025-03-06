#include <iostream>
#include <mutex>

class Singleton {
private:

    Singleton() {
        std::cout << "Singleton created" << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static std::mutex mutex;

public:
    
    static Singleton& getInstance() {
        std::lock_guard<std::mutex> lock(mutex);
        static Singleton instance;
        return instance;
    }


    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }

};


std::mutex Singleton::mutex;

int main() {

    Singleton& instance1 = Singleton::getInstance();
    Singleton& instance2 = Singleton::getInstance();

    std::cout << "Same instance: " << (&instance1 == &instance2) << std::endl;

    instance1.doSomething();
    return 0;
}