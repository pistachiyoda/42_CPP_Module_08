#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    std::vector<int>::iterator it;

    it = easyfind(vec, 2);

    std::cout << *it << std::endl;

    try
    {
        it = easyfind(vec, 4);
    }
    catch (NotFoundException &e)
    {
        std::cout << "not found" << std::endl;
    }

    return 0;
}
