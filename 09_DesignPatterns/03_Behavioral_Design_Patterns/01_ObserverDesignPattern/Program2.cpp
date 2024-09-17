#include <iostream>
#include <vector>
#include <memory>
#include<algorithm>

// Forward declaration of Observer interface
class Observer;


class Subject {
public:
    virtual void attach(std::shared_ptr<Observer> observer) = 0;
    virtual void detach(std::shared_ptr<Observer> observer) = 0;
    virtual void notify() = 0;
};

// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Concrete implementation of Subject
class ConcreteSubject : public Subject {
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void attach(std::shared_ptr<Observer> observer) override {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) override {
        // Remove observer

        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        // Notify all observers
        for (const auto& observer : observers) {
            observer->update();
        }
    }

    // Example method that triggers notification
    void stateChanged() {
        // Something happened, notify observers
        notify();
    }
};

// Concrete implementation of Observer
class ConcreteObserver : public Observer {
public:
    void update() override {
        std::cout << "Observer is notified and updated!\n";
    }
};

int main() {
    // Create subject
    auto subject = std::make_shared<ConcreteSubject>();

    // Create observers
    auto observer1 = std::make_shared<ConcreteObserver>();
    auto observer2 = std::make_shared<ConcreteObserver>();

    // Attach observers to the subject
    subject->attach(observer1);
    subject->attach(observer2);

    // Trigger state change in subject
    subject->stateChanged(); // This will notify both observers

    // Detach observer2
    subject->detach(observer2);

    // Trigger state change again
    subject->stateChanged(); // This will notify only observer1

    return 0;
}
