#include "inventory_1.h"

/*
Specialization for when T is float
Allows adding coins to the pointed value
*/
template <>
void Inventory<float>::add_item(float val) {
    if (ptr) {
        *ptr += val;
        std::cout << "Coin value added: " << val << ". Total: " << *ptr << "\n";
    }
}
/*
Specialization for when T is std::vector<std::string>
Allows adding an individual string to the vector
*/
template <>
void Inventory<std::vector<std::string>>::add_item(const std::string& item) {
    if (ptr) {
        ptr->push_back(item);
        std::cout << "New item added: " << item << "\n";
    }
}