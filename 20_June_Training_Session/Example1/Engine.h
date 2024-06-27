#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
    /* data */
    unsigned int m_id{0};
    int m_horsepower{0};
    float m_torque{0.0f};
public:
    Engine() = default;
    Engine(const Engine& other) = delete;
    Engine(Engine&&) = delete;
    Engine operator = (const Engine& other) = delete;
    Engine& operator = (Engine&&) = delete;
    ~Engine() = default;
    
    Engine(unsigned int id, int horsepower, float torque);

    unsigned int id() const { return m_id; }

    int horsepower() const { return m_horsepower; }

    float torque() const { return m_torque; }
};

#endif // ENGINE_H
