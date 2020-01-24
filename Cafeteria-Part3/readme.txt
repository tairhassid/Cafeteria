This is a standalone system that mimics a cafeteria ordering system.
It was a project for my college cpp course.

First part:
The idea behind the system and it's functionallity was raised by another team
and they wrote only the header files (.h files- only declarations).

Second part:
My partner and I corrected the header files to match what we've learned,
and implemented as cpp files.
The task was to avoid using STL (data structures, object functions and the class string)
and templates in this part.

Third part (this repository):
This part is based on the second part, the tasks were:
1. Implement linked list using templates and use it instead of one of the arrays
   (the implementation is MyLinkedList, and it's used in Order.h)
2. Use the string class instead of all the char* in the project
3. Use vector instead of arrays all over the project
4. implement three design patterns- we implemented Observer (IObserver), Singleton and Facade- (Cafeteria)