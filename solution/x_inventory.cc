#include <iostream>
#include <vector>
#include <string>
#include "inventory_1.h"
 
int main() {

    float* initial_value_ptr=new float(100.0); //Implicit conversion from double to float
    std::cout<<"We create the inventory"<<std::endl;
    Inventory<float> my_wallet(initial_value_ptr);
    
    //Inventory<float> my_copy = my_wallet; //ERROR 

    my_wallet.add_item(50.0f); //we add float money...

    //We transfer the wallet (std::move) 

    Inventory<float> my_other_wallet=std::move(my_wallet);

    //We check the bool() operator
    if (!my_wallet) {
        std::cout<<"The transfer has been completed successfully"<<std::endl;
    }

    //The new owner now adds money, but the existing money remains unchanged
    my_other_wallet.add_item(25.5f);
    std::cout<<"Current wallet value: "<<*my_other_wallet<<std::endl;

    //Now with string (testing the advantage of templates)
    std::vector<std::string>* p = new std::vector<std::string>();
    Inventory<std::vector<std::string>> my_wallet_2(p);
    std::cout<<"We create the -string- inventory"<<std::endl;

    my_wallet_2.add_item("two coins");
    my_wallet_2.add_item("one coin");

    //Note: We can use the -> operator to access the vector inside the object and apply the vector’s methods
    std::cout << "The wallet has " << my_wallet_2->size()<<" items"<<std::endl;

    std::cout<<"...Applying the destructor..."<<std::endl;
    return 0;
} 
