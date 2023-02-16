#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() : std::stack<T>() {
    }
    MutantStack<T>(const MutantStack<T> &mutantStack) : std::stack<T>(mutantStack) {
    }
    ~MutantStack<T>() {
    }
    MutantStack<T> &operator=(const MutantStack<T> &mutantStack) {
        if (this != mutantStack)
            std::stack<T>::operator=(mutantStack);
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() {
        return this->c.begin();
    }
    iterator end() {
        return this->c.end();
    }
};

#endif
