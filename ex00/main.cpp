#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <iostream>

int main()
{
    // vector
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(10);
    vec.push_back(100);
    std::vector<int>::iterator vec_it;

    vec_it = easyfind(vec, 10);
    std::cout << *vec_it << std::endl;

    try {
        vec_it = easyfind(vec, 4);
    }
    catch (NotFoundException &e) {
        std::cout << "not found" << std::endl;
    }

    // list
    std::list<int> list;
    list.push_front(1);
    list.push_front(10);
    list.push_front(100);
    std::list<int>::iterator list_it;

    list_it = easyfind(list, 10);
    std::cout << *list_it << std::endl;

    try {
         list_it = easyfind(list, 4);
    }
    catch(NotFoundException &e) {
        std::cerr << "not found" << std::endl;
    }
    
    // deque
    std::deque<int> deque;
    deque.push_front(1);
    deque.push_front(10);
    deque.push_front(100);
    std::deque<int>::iterator deque_it;

    deque_it = easyfind(deque, 10);
    std::cout << *deque_it << std::endl;

    try {
         deque_it = easyfind(deque, 4);
    }
    catch(NotFoundException &e) {
        std::cerr << "not found" << std::endl;
    }

    return 0;
}
