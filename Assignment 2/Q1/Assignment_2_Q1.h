#include <cstddef>
#include <string> // Include the <string> header

#pragma once

typedef std::string Item_Type; // Change the data type to string

class Single_Linked_List {
public:
    // ... (other declarations remain the same)

    // Constructor and Destructor
    Single_Linked_List();
    ~Single_Linked_List();

    // Member functions
    void print() const; // Declare the print function here
    void push_front(const Item_Type& item);
    void push_back(const Item_Type& item);
    void pop_front();
    void pop_back();
    Item_Type& front();
    Item_Type& back();
    bool empty() const;
    void insert(size_t index, const Item_Type& item);
    bool remove(size_t index);
    size_t find(const Item_Type& item) const;
    // Public member function to get the number of items in the list
    size_t size() const;
private:
    // Data members
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;
};