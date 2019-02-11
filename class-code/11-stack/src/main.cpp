#include <iostream>
#include <list>

void stack_example() {
    int ary[] = {8, 5, 6, 7, 7, 7, 4, 3, 10, -110, -66, 0, 44, 42, 9644, 900002, -800};
    std::list<int> stack;

    /* Adding to a stack. */
    for (int i = 0; i < 17; i++) {
        stack.push_front(ary[i]);
    }

    /* Printing the top element. */
    std::cout << "The top of the stack is: " << stack.front() << "\n";

    /* Remove the elements and print as we remove. */
    for (int i = 0; i < 17; i++) {
        std::cout << stack.front() << "\n";
        stack.pop_front();
    }
}

void queue_example() {
    int ary[] = {8, 5, 6, 7, 7, 7, 4, 3, 10, -110, -66, 0, 44, 42, 9644, 900002, -800};
    std::list<int> queue;

    /* Adding to a queue. */
    for (int i = 0; i < 17; i++) {
        queue.push_back(ary[i]);
    }

    /* Printing the top element. */
    std::cout << "The top of the queue is: " << queue.front() << "\n";

    /* Remove the elements and print as we remove. */
    for (int i = 0; i < 17; i++) {
        std::cout << queue.front() << "\n";
        queue.pop_front();
    }
}

int main(int argc, char *argv[]) {
    int ary[] = {8, 5, 6, 7, 7, 7, 4, 3, 10, -110, -66, 0, 44, 42, 9644, 900002, -800};
}
