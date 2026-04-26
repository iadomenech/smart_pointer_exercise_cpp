Run:
 `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./x_inventory `

Output:
```
==3706== Memcheck, a memory error detector
==3706== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==3706== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==3706== Command: ./x_inventory
==3706== 
We create the inventory
Coin value added: 50. Total: 150
The transfer has been completed successfully
Coin value added: 25.5. Total: 175.5
Current wallet value: 175.5
We create the -string- inventory
New item added: two coins
New item added: one coin
The wallet has 2 items
...Applying the destructor...
==3706== 
==3706== HEAP SUMMARY:
==3706==     in use at exit: 0 bytes in 0 blocks
==3706==   total heap usage: 6 allocs, 6 frees, 74,876 bytes allocated
==3706== 
==3706== All heap blocks were freed -- no leaks are possible
==3706== 
==3706== For lists of detected and suppressed errors, rerun with: -s
==3706== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```