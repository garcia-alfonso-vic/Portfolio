#ifndef MYSTACK_H
#define MYSTACK_H
#include <cassert>

template <typename ITEM_TYPE>
class Stack{
public:
    class Iterator
    {
    public:
        //give access to list to access _ptr
        friend class Stack;   

        //default ctor
        Iterator()
        { 
            _ptr = nullptr; 
        }          
        //Point Iterator to where p is pointing to   
        Iterator(node<ITEM_TYPE>* p)               
        : _ptr(p) {}      

        //dereference operator
        ITEM_TYPE operator *()
        {
            return this->_ptr->_item;
        }
        //true if _ptr is NULL    
        bool is_null()
        {
            return _ptr == nullptr;
        }
        //true if left != right
        friend bool operator !=(const Iterator& left, 
            const Iterator& right)  
        {
            return left._ptr != right._ptr;
        }
        //true if left == right
        friend bool operator ==(const Iterator& left,
            const Iterator& right)  
        {
            return left._ptr == right._ptr;
        }

        //member operator:++it or ++it = new_value
        Iterator& operator++()
        {
            assert(this->_ptr != nullptr);

            Iterator* prev = new Iterator(this->_ptr->_next);
            return *prev;                        
        }

        friend Iterator operator++(Iterator& it, int unused)
        {        
            assert(it._ptr != nullptr);
            Iterator temp = it;
            it._ptr = it._ptr->_next;
            return temp;
        }

    private:
        node<ITEM_TYPE>* _ptr;    //pointer being encapsulated
    };

    Stack()
    {
        _top = nullptr;
        _size = 0;
    }
    Stack(const Stack<ITEM_TYPE>& copyMe)
    {
        this->_top = _copy_list(copyMe._top);
        this->_size = copyMe._size;
    }
    ~Stack() 
    {
        //delete function
        _clear_list(_top);
    }
    Stack<ITEM_TYPE>& operator=(const Stack<ITEM_TYPE>& RHS)
    {
        if (this == &RHS)
            return *this;
        if (_top)
            _clear_list(_top);

        this->_top = _copy_list(RHS._top);
        this->_size = RHS._size;

        return *this;
    }
    ITEM_TYPE top()
    {
        return _top->_item;
    }
    bool empty()
    {
        return (_top == nullptr);
    }
    void push(ITEM_TYPE item)
    {
        ++_size;
        _top = _insert_head(_top, item);
        
    }
    ITEM_TYPE pop()
    {
        assert(_top != nullptr && "OOPS @ Stack pop() : trying to pop a null top.\n");
        if (_top)
        {
            _size--;
        }
        return _delete_node(_top, _top);
        
    }   
    template<typename T>
    friend ostream& operator<<(ostream& outs, const Stack<T>& printMe)
    {
        outs << "Head->";
        node<T>* walker = printMe._top;

        for (int i = 0; i < printMe._size; i++)
        {
            outs << *walker;
            walker = walker->_next;
        }
        outs << endl;
        return outs;
    }
    //Iterator to the head node
    Iterator begin() const
    {
        return Iterator(_top);
    }
    //Iterator to NULL                   
    Iterator end() const
    {
        return Iterator(nullptr);
    }
    int size() const 
    { 
        return _size; 
    }

private:
    node<ITEM_TYPE>* _top;
    int _size;
};
#endif //MYSTACK_H