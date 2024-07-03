#ifndef STACKEMPTY_H
#define STACKEMPTY_H
 
#include<iostream>
 
class StackEmpty: public std::exception
{
    private:
        std::string m_msg{"EMPTY"};
 
    public:
        StackEmpty()=default;
        ~StackEmpty()=default;
        StackEmpty(const StackEmpty& )=delete;
        StackEmpty(StackEmpty&&)=default;//mandatory
        StackEmpty& operator=(const StackEmpty&)=delete;
        StackEmpty& operator=(StackEmpty&&)=delete;
 
    const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return m_msg.c_str();
    }
};
 
#endif // STACKEMPTY