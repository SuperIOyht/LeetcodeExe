#include<mutex>
#include<condition_variable>
#include<functional>
using namespace std;

//class FooBar {
//private:
//    int n;
//    condition_variable cv;
//    mutex lk;
//    bool flag;
//public:
//    FooBar(int n) {
//        this->n = n;
//        flag = true;
//    }
//
//    void foo(function<void()> printFoo) {
//        std::unique_lock<std::mutex> ul(lk);
//        for (int i = 0; i < n; i++) {
//            cv.wait(ul, [this]() {return flag == true; });
//            // printFoo() outputs "foo". Do not change or remove this line.
//            printFoo();
//            flag = false;
//            cv.notify_one();
//        }
//    }
//
//    void bar(function<void()> printBar) {
//        std::unique_lock<std::mutex> ul(lk);
//        for (int i = 0; i < n; i++) {
//            cv.wait(ul, [this]() {return flag == false; });
//            // printBar() outputs "bar". Do not change or remove this line.
//            printBar();
//            flag = true;
//            cv.notify_one();
//        }
//    }
//};

//class FooBar {
//private:
//    int n;
//    mutex lk1, lk2;
//public:
//    FooBar(int n) {
//        this->n = n;
//        unique_lock<mutex> ul1(lk1), ul2(lk2);
//        ul1.lock();
//        //ul2.lock();
//    }
//
//    void foo(function<void()> printFoo) {
//
//        for (int i = 0; i < n; i++) {
//            unique_lock<mutex> ul1(lk1), ul2(lk2);
//            ul2.lock();
//            // printFoo() outputs "foo". Do not change or remove this line.
//            printFoo();
//            ul2.unlock();
//            ul1.lock();
//        }
//    }
//
//    void bar(function<void()> printBar) {
//
//        for (int i = 0; i < n; i++) {
//            unique_lock<mutex> ul1(lk1), ul2(lk2);
//            ul1.lock();
//            // printBar() outputs "bar". Do not change or remove this line.
//            printBar();
//            ul1.unlock();
//            ul2.lock();
//        }
//    }
//};

#include<atomic>
class FooBar {
private:
    int n;
    atomic<bool> flag = true;
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            // printFoo() outputs "foo". Do not change or remove this line.
            while (!flag) {
                this_thread::yield();
            }
            printFoo();
            flag.store(false);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            // printBar() outputs "bar". Do not change or remove this line.
            while (!flag) {
                this_thread::yield();
            }
            printBar();
            flag.store(true);
        }
    }
};