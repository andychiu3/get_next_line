## get_next_line

A C function that reads a line from a file descriptor, returning one line at a time, including the newline character, until the file is fully read or an error occurs.

![gnl](https://github.com/user-attachments/assets/30b6ba57-5878-4643-8a89-75b10a17b4f0)

Passed [francinette](https://github.com/xicodomingues/francinette) - an open-source tester.

<br> 

## Relation to SOLID's D (Dependency Inversion Principle)

As I see it, there are some parallels between get_next_line and SOLID's Dependency Inversion Principle, although they're not exactly the same...

DIP emphasizes that high-level modules should depend on abstractions, not concrete implementations.  
get_next_line abstracts the process of reading lines from any file descriptor, decoupling the calling code from specific file-handling details.  
