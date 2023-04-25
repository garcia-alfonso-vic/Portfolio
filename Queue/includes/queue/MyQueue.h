#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <cassert>
#include "../node/node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
public:
    class Iterator{
    public:
        //give access to list to access _ptr
        friend class Queue;                               
        //default ctor
        Iterator()
        {
            _ptr = nullptr;
        }
        //Point Iterator to where p is pointing to                          
        Iterator(node<T>* p) : _ptr(p) {}                   
        //dereference operator
        T operator *()
        {
            return this->_ptr->_item;
        }
        //true if _ptr is NULL    
        bool is_null()
        {
            return (_ptr == nullptr);
        }
        //true if left != right            
        friend bool operator !=(const Iterator& left,
                                const Iterator& right)  
        {
            return !(left._ptr == right._ptr);
        }

        //true if left == right
        friend bool operator ==(const Iterator& left,
                                const Iterator& right)  
        {
            return left._ptr == right._ptr;
        }

        //member operator:++it
        // or ++it = new_value
        Iterator& operator++()
        {  
            assert(this->_ptr != nullptr);                       
            Iterator* it = new Iterator(this->_ptr->_next);
            return *it;
        }
        //friend operator: it++
        friend Iterator operator++(Iterator& it, int unused)
        {
            assert(it._ptr != nullptr);         
            Iterator* temp = new Iterator(it._ptr);
            it._ptr = it._ptr->_next;
            return it;
        }

    private:
        node<T>* _ptr;                          //pointer being encapsulated
    };

    Queue() : 
        _front(nullptr),
        _rear(nullptr),
        _size( 0)
    {}   

    Queue(const Queue<T>& copyMe)
    {
        if (copyMe._front == nullptr)
            return;
        //TODO: COPY LIST IS NOT COPYING CORRECTLY! from _copy_list() may be wrong
        _front = _copy_list(copyMe._front);
        _rear = _copy_list(_rear, copyMe._front);
        _size = copyMe._size;
    }
    ~Queue()
    {
        _clear_list(_front);
        _rear = nullptr;
        _size = 0;
    }
    //It does not create a separate memory block or new memory space.
    Queue& operator=(const Queue<T>& RHS)
    {

        //I dont know if _rear updates here...
        if (this == &RHS)
        {
            return *this;
        }
        if (_front)
        {
            _clear_list(_front);
            _rear =  nullptr;
        }
        //...here
        _front = RHS._front;
        _rear = RHS._rear;
        _size = RHS._size;
        return *this;
    }

    bool empty() 
    {
        return (_front == nullptr);
    }
    T front()
    {
        return _front->_item;
    }
    T back()
    {
        return _at(_front, _size-1);
    }
    //_front function is implicitly updated throught he _isnert_after() 
    // that returns the node insered, in this case, at the end.
    void push(T item)
    {
        _size++;
        // Function updates _front to inlude inserted node &&  
        // returns the node inserted. In a Queue's case, it is
        // always at the end.
        _rear = _insert_after(_front, _rear, item);
        if (!_front)
            _front = _rear;
            
            
    }   
    T pop()
    {
        if (_front)
        {
            _size--;
            if (_size == 0)
            {
                _rear = nullptr; 
            }
        }
        
        //updates front of Queue without certain node
        return _delete_node(_front, _front);
    }

    //Iterator to the head node
    Iterator begin() const
    {
        return Iterator(_front);
    }
     //Iterator to NULL                                     
    Iterator end() const
    {
        return Iterator(nullptr);
    }                                      
    void print_pointers()
    {
        node<T>* walker = _front;

        for(int i = 0; i < _size; i++)
        {
            cout << " {" << i << "}" << walker << endl;
            walker = walker->_next;
        }
    }
    int size() const 
    { 
        return _size; 
    }
    template<typename TT>
    friend ostream& operator << (ostream& outs, const Queue<TT>& printMe)
    {
        outs << "Head->";
        node<TT>* walker = printMe._front;
        for (int i = 0; i < printMe._size; i++)
        {
            outs << *walker;
            walker = walker->_next;
        }
        outs << endl;
        return outs;
    }
private:
    node<T>* _front;
    node<T>* _rear;
    int _size;
};
#endif //MYQUEUE_H