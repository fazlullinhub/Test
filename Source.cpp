#include <iostream>
#include <memory>


template <typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> next;

    Node(T value) : data(value), next(nullptr) {}
};


template <typename T>
class LinkedList {
private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void add(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool remove(T val) {
        auto current = head;
        std::shared_ptr<Node<T>> previous = nullptr;

        while (current) {
            if (current->data == val) {
                if (current == head) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }

                if (current == tail) {
                    tail = previous;
                }

                delete current;
                return true;
            }

            previous = current;
            current = current->next;
        }
        return false;
    }

    std::shared_ptr<Node<T>> find(T val) {
        auto current = head;

        while (current) {
            if (current->data == val) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void printList() {
        auto current = head;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


template <typename T>
class Stack {
private:
    std::shared_ptr<Node<T>> top;

public:
    Stack() : top(nullptr) {}

    void push(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top) {
            top = top->next;
        }
    }

    std::shared_ptr<Node<T>> peek() const {
        return top;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    void printStack() {
        auto current = top;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};


template <typename T>
class Queue {
private:
private:
    std::shared_ptr<Node<T>> front;
    std::shared_ptr<Node<T>> rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T val) {
        auto newNode = std::make_shared<Node<T>>(val);
        if (rear) {
            rear->next = newNode;
        }
        else {
            front = newNode;
        }
        rear = newNode;
    }

    void dequeue() {
        if (front) {
            front = front->next;
            if (!front) {
                rear = nullptr;
            }
        }
    }

    std::shared_ptr<Node<T>> peek() const {
        return front;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    void printQueue() {
        auto current = front;

        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "LinkedList demo:" << std::endl;
    LinkedList<int> list;
    list.add(1);
    list.add(2);
    list.add(3);
    std::cout << "Initial list: ";
    list.printList();

    int valueToFind = 2;
    auto foundNode = list.find(valueToFind);
    if (foundNode) {
        std::cout << "Found value " << foundNode->data << std::endl;
    }
    else {
        std::cout << "Value not found" << std::endl;
    }

    int valueToRemove = 2;
    bool removed = list.remove(valueToRemove);
    if (removed) {
        std::cout << "Value " << valueToRemove << " removed" << std::endl;
    }
    else {
        std::cout << "Value not found for removal" << std::endl;
    }

    std::cout << "List after removal: ";
    list.printList();


    std::cout << "\nStack demo:" << std::endl;
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "Stack contents: ";
    stack.printStack();
    stack.pop();
    std::cout << "Stack after pop: ";
    stack.printStack();

    std::cout << "\nQueue demo:" << std::endl;
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    std::cout << "Queue contents: ";
    queue.printQueue();
    queue.dequeue();
    std::cout << "Queue after dequeue: ";
    queue.printQueue();

    return 0;
}
