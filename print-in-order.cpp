#include<thread>
#include<functional>
#include<mutex>
#include<condition_variable>
#include<future>
using namespace std;

//conditional_variable
//class Foo {
//public:
//    std::condition_variable cv;
//    std::mutex mylock;
//    int i;
//    Foo() {
//        i = 0;
//    }
//
//    void first(function<void()> printFirst) {
//        // printFirst() outputs "first". Do not change or remove this line.
//        printFirst();
//        i++;
//        cv.notify_one();
//    }
//
//    void second(function<void()> printSecond) {
//        std::unique_lock<std::mutex> lg(mylock);
//        cv.wait(lg, [this] () { return i == 1; });
//        // printSecond() outputs "second". Do not change or remove this line.
//        printSecond();
//        i++;
//        cv.notify_one();
//    }
//
//    void third(function<void()> printThird) {
//        std::unique_lock<std::mutex> lg(mylock);
//        cv.wait(lg, [this] () { return i == 2; });
//        // printThird() outputs "third". Do not change or remove this line.
//        printThird();
//        i++;
//        cv.notify_one();
//    }
//};



//future
class Foo {
public:
    Foo() {
        
    }
    std::promise<void> pm1, pm2;
    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        pm1.set_value();
    }

    void second(function<void()> printSecond) {
        pm1.get_future().wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        pm2.set_value();
    }

    void third(function<void()> printThird) {
        pm2.get_future().wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};