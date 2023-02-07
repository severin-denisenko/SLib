//
// Created by Severin on 06.02.2023.
//

#ifndef SLIB_SUNIQUEPTR_H
#define SLIB_SUNIQUEPTR_H

#include <utility>

namespace slib{

    template<typename T>
    class SUniquePtr{
    public:
        SUniquePtr() = default;

        explicit SUniquePtr(T* ptr) : m_ptr(ptr) {}

        ~SUniquePtr(){
            delete m_ptr;
        }

        SUniquePtr(const SUniquePtr& other) = delete;

        SUniquePtr(SUniquePtr&& other) noexcept {
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

        SUniquePtr& operator=(const SUniquePtr& other) = delete;

        SUniquePtr& operator=(SUniquePtr&& other) noexcept {
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }

    private:
        T* m_ptr;
    };

    template<typename T, typename... Args>
    SUniquePtr<T> make_unique(Args&&... args){
        return SUniquePtr<T>(new T(std::forward<Args>(args)...));
    }
}

#endif //SLIB_SUNIQUEPTR_H