#ifndef STACK_H
#define STACK_H
 
#include<vector>
#include<StackEmpty.h>
 
template <typename T>
 
class Stack
{
 
private:
   std::size_t m_top{-1};
   std::vector<T> m_data{};
 
public:
 
    Stack() = default; //defaulted default constructor
    Stack(T);
    Stack( const Stack<T>&) = default; //take a stack of type T object and copy it
    Stack( Stack<T>&& ) = default;
    Stack& operator = (const Stack<T>&) = default;
    Stack& operator = ( Stack<T>&&) = default;
    ~Stack() = default;
 
    Stack(const std::vector<T>& values); //user has a vector and we copy into a new stack
    Stack(const std::initializer_list<T>& values); //Stack<int> s1 {1,2,3};
 
    T Pop(); //whenever an elt is popped return the elt
 
    //here taking refernce would be bad because no proper ownership of data
    //Push(const T& element); //user can pass the value by l value reference and r value // l values are refered and r values are assigned
    //instead write as following
    void Push(const T);
 
    void Push(const T&& element);
 
    T& Peek();//return the reference of the element
 
    bool IsEmpty();// a boolean type
 
    void Swap(Stack<T>& other);//return type void, a Stack of T
   
    inline std::size_t Size();
 
    void <Stack>Clear();
 
    Stack<T> Merge(Stack<T>& other);
 
};
 
template <typename T>
inline Stack<T>::Stack(T)
{
 
}
 
template <typename T>
inline Stack<T>::Stack(const std::vector<T> &values)
{
   for(const T elt : values) {
    m_top++;
    m_data.push_back(elt);
   }
}
 
template <typename T>
inline Stack<T>::Stack(const std::initializer_list<T> &values)
{
    for(const T elt : values) {
        m_top++;
        m_data.push_back( elt );
    }
}
 
template <typename T>
inline T Stack<T>::Pop()
{
    if(IsEmpty()) {
        throw StackEmpty("Stack is empty\n");
    }
 
    //return m_data[m_top--];
    //we need to return the popped item to the user. So we must copy it safely somewhere
    
    T element = m_data[m_top];
    m_data.pop_back();
    m_top--;
 
    return element;
   
}
 
template <typename T>
inline void Stack<T>::Push(const T element) // for l values
{
    m_top++;
    m_data.push_back(element);
}
 
template <typename T>
inline void Stack<T>::Push(const T &&element) // for r values
{
    m_top++;
    m_data.push_back(element);
}
 
template <typename T>
inline T &Stack<T>::Peek()
{
    if(IsEmpty()) {
        throw StackEmpty("Stack is empty\n");
    }
 
    return m_data[m_top]; //just return the top item do not decrement top pointer
    // TODO: insert return statement here
}
 
template <typename T>
inline bool Stack<T>::IsEmpty()
{
    return m_top == -1;
}
 
template <typename T>
inline void Stack<T>::Swap(Stack<T> &other)
{
    m_data.swap(other.m_data); // swap this stack's m_data with other stacks m_data
}
 
template <typename T>
inline std::size_t Stack<T>::Size()
{
    return std::size_t();
}
 
template <typename T>
inline Stack<T> Stack<T>::Merge(Stack<T> &other)
{
    //one way is to take another stack and include the
    // Stack<T> result {};
    // for(const T elt : this->m_data) {
    //     result.m_data.push_back(elt);
    // }
 
    // for(const T elt : other->m_data) {
    //     result.m_data.push_back(elt);
    // }
 
    for(std::size_t i=0; i<other.Size(); i++) {
        this->Push( other.Pop() );
    }
 
    return result;
}
 
#endif // STACK_H
 
