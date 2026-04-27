# C++ Smart Pointers: Move Semantics Exercise

This repository contains an exercise proposed for the **Computational Physics (C++)** course. The goal is to understand the internal mechanics behind `std::unique_ptr` by implementing a simplified custom smart pointer system.

## Objective

The exercise focuses on designing a templated class that manages dynamic memory for two different types of data:

- Pointers to a `float` value  
- Pointers to a `std::vector<std::string>`

Special attention is given to proper memory management and ownership semantics.

## Key Concepts

This implementation emphasizes:

- Template programming in C++  
- Manual memory management  
- Disabling copy semantics (copy constructor and copy assignment operator)  
- Implementing move semantics using the move assignment operator (`std::move`)  
- Understanding ownership transfer, similar to `std::unique_ptr`

## Compilation and Execution

The project is designed to run on **Linux systems**.

Inside the corresponding directory, there is a Makefile provided to compile and execute the code. This Makefile is generic and will work for any program whose name starts with -x-. Technical note: the -g flag is important for using Valgrind, as it provides more detailed information


