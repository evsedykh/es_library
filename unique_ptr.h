#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

namespace es{


template<typename T>
class unique_ptr
{
public:
    explicit unique_ptr(T* obj = nullptr)
        : m_obj(obj)
    {
        std::cout << "ctor(T*)" << std::endl;
    }
    unique_ptr(unique_ptr& other)
        : m_obj(other.m_obj)
    {
        other.m_obj = nullptr;
        std::cout << "ctor(up<T>&)" << std::endl;
    }
    ~unique_ptr()
    {
        std::cout << "dtor() obj = " << m_obj << std::endl;
        delete m_obj;
    }
    unique_ptr& operator=(unique_ptr& other)
    {
        std::cout << "operator=()" << std::endl;
        if(other != *this)
        {
            m_obj = other.m_obj;
            other.m_obj = nullptr;
        }
    }
    bool operator==(const unique_ptr& other) const
    {
        return other.m_obj == m_obj;
    }
    bool operator!=(const unique_ptr& other) const
    {
        return other.m_obj != m_obj;
    }
    T& operator*() const
    {
        if(m_obj)
        {
            return *m_obj;
        } else throw std::runtime_error("Null pointer.");
    }
    T* operator->() const
    {
        if(m_obj)
        {
            return m_obj;
        } else throw std::runtime_error("Null pointer.");
    }

private:
    T* m_obj;
};

} // namespace es

#endif // UNIQUE_PTR_H
