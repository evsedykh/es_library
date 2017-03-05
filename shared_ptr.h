#ifndef SHARED_PTR_H
#define SHARED_PTR_H

namespace es{

template<typename T>
class shared_ptr
{
public:
    explicit shared_ptr(T* obj = nullptr)
        : m_obj(obj)
        , m_refs(new size_t(0))
    {
        if(m_obj) ++*m_refs;
        std::cout << "ctor(T*), refs = " << *m_refs << std::endl;
    }
    shared_ptr(shared_ptr& other)
        : m_obj(other.m_obj)
        , m_refs(other.m_refs)
    {
        std::cout << "ctor(sp<T>&), refs = " << *m_refs << " -> ";
        ++*m_refs;
        std::cout << *m_refs << std::endl;
    }
    ~shared_ptr()
    {
        std::cout << "dtor() obj = " << m_obj << ", refs = " << *m_refs << " -> ";
        if(*m_refs)
        {
            --*m_refs;
            if(!*m_refs) delete m_obj;
        }
        std::cout << *m_refs;
        if(!*m_refs)
        {
            std::cout << ". Delete object.";
            delete m_refs;
        }
        std::cout << std::endl;
    }
    shared_ptr& operator=(shared_ptr& other)
    {
        std::cout << "operator=(), refs = " << *m_refs << " -> ";
        if(other != *this)
        {
            m_obj = other.m_obj;
            m_refs = other.m_refs;
            ++*m_refs;
        }
        std::cout << *m_refs << std::endl;
    }
    bool operator==(const shared_ptr& other) const
    {
        return other.m_obj == m_obj;
    }
    bool operator!=(const shared_ptr& other) const
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
    mutable size_t* m_refs;
};

} // namespace es

#endif // SHARED_PTR_H
