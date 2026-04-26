#ifndef INVENTORY_1_H
#define INVENTORY_1_H

#include <iostream>
#include <vector>
#include <string>
/*
The explicit keyword matters here because the constructor takes a single parameter.
 Without it, the compiler could perform implicit conversions from the argument type
 to this class in function calls, which can lead to subtle and hard-to-track bugs.
 Example:
 class MyClass { public: MyClass(int x){}}
 void f(MyClass A){}
 f(1), f(MyClass(1))-> both compile (We want to avoid this)
*/
template <typename T>
class Inventory {
private:
    T* ptr;

public: 
    // Constructor
    explicit Inventory(T* p = nullptr) : ptr(p) {}

    // Destructor (RAII)
    ~Inventory() {
        delete ptr;
    }

    // Disable Copy 
    Inventory(const Inventory&) = delete; // copy constructor disabled
    Inventory& operator=(const Inventory&) = delete; // copy assignment disabled

    /*
    Note: Inventory&& other -> Indicates the rvalue of the variable Inventory named other
    */
    Inventory(Inventory&& other) : ptr(other.ptr) { //transfer the pointer
        other.ptr = nullptr; //set the original to be nullptr
    }
    Inventory& operator=(Inventory&& other) { //to use invB=std::move(invA)
        if (this != &other) {
            delete ptr;
            ptr = other.ptr; //we take ownership of the pointer
            other.ptr = nullptr;
        }
        return *this;
    }

    // Here we define the functions, but they must be written in the .cc file (a templates-related thing)
    void add_item(float val);
    void add_item(const std::string& item);

    // pointer behaviour
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    explicit operator bool() const { return ptr != nullptr; }
};

#endif // INVENTORY_1_H