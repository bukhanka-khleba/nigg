#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(const std::string& message) = 0;
};

class Subject {
private:
    std::vector<std::weak_ptr<IObserver>> observers;
    std::string state;

    void cleanup() {
        observers.erase(
            std::remove_if(observers.begin(), observers.end(),
                [](const std::weak_ptr<IObserver>& ptr) { return ptr.expired(); }),
            observers.end());
    }

public:
    void attach(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
        cleanup();
    }

    void detach(std::shared_ptr<IObserver> observer) {
        observers.erase(
            std::remove_if(observers.begin(), observers.end(),
                [&observer](const std::weak_ptr<IObserver>& ptr) {
                    return ptr.lock() == observer;
                }),
            observers.end());
    }

    void notify() {
        cleanup();
        for (const auto& weak_observer : observers) {
            if (auto observer = weak_observer.lock()) {
                observer->update(state);
            }
        }
    }

    void setState(const std::string& newState) {
        state = newState;
        notify();
    }

    std::string getState() const {
        return state;
    }
};


class ConcreteObserver : public IObserver {
private:
    std::string name;

public:
    ConcreteObserver(const std::string& name) : name(name) {}

    void update(const std::string& message) override {
        std::cout << "Observer " << name 
                  << " received message: " << message << std::endl;
    }
};

int main() {

    Subject subject;

    auto observer1 = std::make_shared<ConcreteObserver>("Observer 1");
    auto observer2 = std::make_shared<ConcreteObserver>("Observer 2");
    auto observer3 = std::make_shared<ConcreteObserver>("Observer 3");

    subject.attach(observer1);
    subject.attach(observer2);
    subject.attach(observer3);

    subject.setState("First notification");

    subject.detach(observer2);

    subject.setState("Second notification");

    return 0;
}