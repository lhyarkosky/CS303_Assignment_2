#include "Assignment_2_Q1.h"
#include <cstddef> 
#include <iostream>
#include <string>

// Constructor
Single_Linked_List::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor
Single_Linked_List::~Single_Linked_List() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Member functions
// Member function to get the number of items in the list
size_t Single_Linked_List::size() const {
    return num_items;
}

void Single_Linked_List::print() const {
    Node* current = head;
    
    std::cout << "List contents:" << std::endl;
    
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << std::endl;
}
void Single_Linked_List::push_front(const Item_Type& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    num_items++;
}

void Single_Linked_List::push_back(const Item_Type& item) {
    Node* newNode = new Node(item);
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

void Single_Linked_List::pop_front() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
    }
}

void Single_Linked_List::pop_back() {
    if (!empty()) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        num_items--;
    }
}

Item_Type& Single_Linked_List::front() {
    if (!empty()) {
        return head->data;
    } else {
        // Handle an empty list here.
        static Item_Type empty_value = ""; // Return an empty string
        return empty_value;
    }
}

Item_Type& Single_Linked_List::back() {
    if (!empty()) {
        return tail->data;
    } else {
        // Call the front function to avoid redundancy
        return front();
    }
}


bool Single_Linked_List::empty() const {
    return num_items == 0;
}

void Single_Linked_List::insert(size_t index, const Item_Type& item) {
    if (index < 0 || index > num_items) {
        index = num_items; // Insert at the end if index is out of bounds
    }
    if (index == 0) {
        push_front(item);
    } else {
        Node* newNode = new Node(item);
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (index == num_items) {
            tail = newNode;
        }
        num_items++;
    }
}

bool Single_Linked_List::remove(size_t index) {
    if (index < 0 || index >= num_items || index < 0) {
        return false; // Index out of bounds
    }
    if (index == 0) {
        pop_front();
    } else {
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* toRemove = temp->next;
        temp->next = toRemove->next;
        if (index == num_items - 1) {
            tail = temp;
        }
        delete toRemove;
        num_items--;
    }
    return true;
}

size_t Single_Linked_List::find(const Item_Type& item) const {
    Node* temp = head;
    size_t index = 0;
    while (temp != nullptr) {
        if (temp->data == item) {
            return index; // Item found, return the index
        }
        temp = temp->next;
        index++;
    }
    // Item not found, return the number of items in the list
    return num_items;
}


int main() {
    Single_Linked_List myList;

    while (true) {
        std::cout << "Enter a command (push_front, push_back, pop_front, pop_back, front, back, empty, insert, remove, find, print, exit): ";
        std::string command;
        std::cin >> command;

        if (command == "push_front") {
            std::string item;
            std::cin >> item;
            myList.push_front(item);
        } else if (command == "push_back") {
            std::string item;
            std::cin >> item;
            myList.push_back(item);
        } else if (command == "pop_front") {
            myList.pop_front();
        } else if (command == "pop_back") {
            myList.pop_back();
        } else if (command == "front") {
            if (!myList.empty()) {
                std::cout << "Front item: " << myList.front() << std::endl;
            } else {
                std::cout << "List is empty." << std::endl;
            }
        } else if (command == "back") {
            if (!myList.empty()) {
                std::cout << "Back item: " << myList.back() << std::endl;
            } else {
                std::cout << "List is empty." << std::endl;
            }
        } else if (command == "empty") {
            std::cout << "Is empty: " << myList.empty() << std::endl;
        } else if (command == "insert") {
            size_t index;
            std::string item;
            std::cin >> index >> item;
            myList.insert(index, item);
        } else if (command == "remove") {
            size_t index;
            std::cin >> index;
            bool removed = myList.remove(index);
            if (removed) {
                std::cout << "Item removed successfully." << std::endl;
            } else {
                std::cout << "Item not removed (index out of bounds)." << std::endl;
            }
        } else if (command == "find") {
            std::string item;
            std::cin >> item;
            size_t index = myList.find(item);
            if (index < myList.size()) {
                std::cout << "Item found at index " << index << std::endl;
            } else {
                std::cout << "Item not found. List size=" << myList.size() << std::endl;
            }
        } else if (command == "print") {
            myList.print();
        } else if (command == "exit") {
            break; // Exit the program
        } else {
            std::cout << "Invalid command. Try again." << std::endl;
        }
    }

    return 0;
}