#include<iostream>

class ABC
{
private:
    int m_id{0};
    float* m_valuePtr{nullptr};
public:
    ABC(int id, float* ptr) : m_id{id}, m_valuePtr{ptr} {}
    ~ABC() = default;
    ABC(const ABC&) = delete;
    ABC(ABC&&) = delete;
    ABC& operator = (const ABC&&) = delete;
    ABC& operator = (ABC&&) = delete;
    

    ~ABC() {
        delete m_valuePtr; //memory leakage prevented
    }

};

/*
     [     101     |  200.0f        ]
   


*/


//classt enter
template <typename T>
class Wrapper
{
private:
   T* m_ptr;

public:
    Wrapper(T* ptr) : m_ptr {ptr} { }

    Wrapper() {
        delete m_ptr;
    }
};

void Magic(){
    Wrapper<ABC> wr_obj { { new ABC {101, new float{200.0f}} } };
}


int main() {
    //ABC* obj {new ABC {101, new float{200.0f}} };
    Magic();
}

/*
1) Main calls Magic()
2) In Magic function we create wr_obj (stack memory)
3) wr_obj stores the address of the Heap allocated ABC object.
4) wr_obj goes out of scope at the end of magic function. Since wr_obj is a 
stack allocated variable, it will get auto destructed.
Destructor of Wrapper<ABC> class will be called.
5) Wrapper class destructor will call delete on the stored pointer
for ABC. which will indirectly also delete it.
*/

//Modern CPP likes to keep things in boxes


/*
    memory------>box [memory will be shared] {box is called: 
    shared pointer}

    memory---box [memory will NEVER BE SHARED] {box is calld unique pointer}

    memory--->box[memory will "stalked"] {box is called weak_ptr}

    functions/callables ---> box {box is called function_wrapper}

    reference--->box {box is called reference_wrapper}

    semaphores---> box {box is called
        a) lock guard b) unique lock ...
    }
    
*/