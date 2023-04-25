#ifndef LINKEDLISTFUNCTIONSTEMPLATED
#define LINKEDLISTFUNCTIONSTEMPLATED

#include <cassert>
#include <iostream>

#include "../node/node.h"

using namespace std;

//Linked List General Functions:
template <typename T>
void _print_list(node<T>* head);

//recursive fun! :)
template <typename T>
void _print_list_backwards(node<T> *head);

//return ptr to key or NULL
template <typename T> node<T>* _search_list(node<T>* head, T key);


template <typename T> node<T>* _insert_head(node<T> *&head, T insert_this);

//insert after ptr: insert head if marker null
template <typename T> node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this);

//insert before ptr: insert head if marker null
template <typename T> node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this);

//ptr to previous node
template <typename T> node<T>* _previous_node(node<T>* prev_to_this);

//delete, return item
template <typename T> T _delete_node(node<T>*& head, node<T>* delete_this);

//duplicate the list...
template <typename T> node<T>* _copy_list(node<T>* head);

//duplicate the list, return pointer to last node in dest... 
//     use this function in your queue big three 
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src);

//delete all the nodes
template <typename T>
void _clear_list(node<T>*& head);

//_item at this position
template <typename T>
T& _at(node<T>* head, int pos);


//DEFINITIONS 
template <typename T> void _print_list(node<T>* head)
{
    node<T>* walker = head;
    cout << "Head->";
    while (walker != nullptr)
    {   
        cout << *walker;
        walker = walker->_next;
    }
    cout << "|||\n";
    
}
//recursive fun! :)
template <typename T> void _print_list_backwards(node<T> *head)
{
    node<T>* walker = head;
    
    if (walker != nullptr)
    {
        _print_list_nackwards(walker->_next);
    }else
    {
        cout << walker;
    }
}
template <typename T> node<T>* _search_list(node<T>* head, T key)
{
    node<T>* walker = head;
    node<T>* found = nullptr;
    if (head == nullptr)
        return found;
    
    while (walker != nullptr)
    {
        if (walker->_item == key)
        {
            found = walker;
            break;
        }
        walker = walker->_next;
    }

    return found;
}
template <typename T> node<T>* _insert_head(node<T> *&head, T insert_this)
{
    node<T>* newNode = new node<T>(insert_this);
    if (head != nullptr)
    {
        newNode->_prev = nullptr;
        newNode->_next = head;
        head->_prev = newNode;
    }
    head = newNode;
    
    return head;
}
template <typename T> node<T>* _insert_after(node<T>*& head, node<T> *after_this, T insert_this)
{
    // assert(after_this != nullptr && "OOPS, tried to insert after a null pointer.\n");
    
    if (head == nullptr)
        return _insert_head(head, insert_this);
    
    node<T>* inserted = new node<T>(insert_this, after_this->_next, after_this);

    // Checks if after_this is @ end of the linked list
    if (after_this->_next != nullptr)
        after_this->_next->_prev = inserted;
    
    after_this->_next = inserted;

    
    return inserted;
}
//insert before ptr: insert head if marker null
template <typename T> node<T>* _insert_before(node<T>*& head, node<T>* before_this, T insert_this)
{
    if (head == nullptr)
        return _insert_head(head, insert_this);
    node<T>* inserted = new node<T>(insert_this, before_this, before_this->_prev);

    if (before_this->_prev != nullptr)
        before_this->_prev->_next = inserted;
    
    before_this->_prev = inserted;


    return inserted;
}
template <typename T> T _delete_node(node<T>*& head, node<T>* delete_this)
{
    assert(delete_this != nullptr && "ERROR @ _delete_node() : Trying to delete a nullptr from Linked List.\n");
    
    T data_deleted = delete_this->_item;
    node<T>* found_node = _search_list(head, delete_this->_item);
    
    if (found_node == nullptr)
        return -1;
    
    if (delete_this != head)
    {
        node<T>* prev_of_deleted = _previous_node(delete_this);
        node<T>* next_of_deleted = delete_this->_next;

        if (prev_of_deleted != nullptr)
        {
            prev_of_deleted->_next = next_of_deleted; 
        }
        if (next_of_deleted != nullptr)
        {
            next_of_deleted->_prev = prev_of_deleted;
        }
    }else 
    {
        delete_this = delete_this->_next;
        if (delete_this != nullptr)
            delete_this->_prev = nullptr;
        head = delete_this;
    }
    
    return data_deleted;

}
//duplicate the list...
template <typename T> node<T>* _copy_list(node<T>* head)
{
    if (head == nullptr)
        return nullptr;
    
    //create temp variable 
    node<T>* walker = head;
    
    //allocates head of new list(Dest)
    node<T>* newList = new node<T>(walker->_item);
    //move 
    walker = walker->_next;

    node<T>* current = newList;

    while (walker != nullptr)
    {
        current->_next = new node<T>(walker->_item);
        
        node<T>* previous = new node<T>(current->_item, current->_next, current->_prev);
        current->_prev = previous->_prev;
        current->_next->_prev = previous;

        current = current->_next;
        
        // newList = newList->_next;
        walker = walker->_next;
    }
    
    return newList;
}

//duplicate the list, return pointer to last node in dest... 
//     use this function in your queue big three 
template <typename T> node<T> *_copy_list(node<T> *&dest, node<T> *src)
{
    if (src == nullptr)
        return nullptr;
    
    //create temp variable 
    node<T>* walker = src;
    
    //allocates head of new list(Dest)
    dest = new node<T>(walker->_item);
    //move walker
    walker = walker->_next;

    //iterate through new list
    node<T>* current = dest;

    while (walker != nullptr)
    {
        dest->_next = new node<T>(walker->_item);
        
        node<T>* previous = new node<T>(dest->_item, dest->_next, dest->_prev);
        dest->_prev = previous->_prev;
        dest->_next->_prev = previous;

        // current = current->_next;
        
        dest = dest->_next;
        walker = walker->_next;
    }
    
    return dest;
}
//ptr to previous node
template <typename T> node<T>* _previous_node(node<T>* prev_to_this)
{
    return prev_to_this->_prev;
}
template <typename T> T& _at(node<T>* head, int pos)
{
    assert(head != nullptr && "OOPS @ _at() : head is nullptr.\n");
    return *(head + pos);
}
//delete all the nodes
template <typename T> void _clear_list(node<T>*& head)
{
    if (head == nullptr)
        return;
    
    node<T>* temp = new node<T>();

    while(temp != nullptr)
    {
        temp = head;
        
        T deleted = _delete_node(head,head);
        temp = temp->_next;
    } 
}
#endif //LINKEDLISTFUNCTIONSTEMPLATED