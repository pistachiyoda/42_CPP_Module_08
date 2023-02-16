#include "Span.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::cout << "=== 2 elements simple test ====" << std::endl;
    Span sp = Span(2);
    sp.addNumber(3);
    sp.addNumber(17);

    std::cout << sp.shortestSpan() << std::endl; // 14
    std::cout << sp.longestSpan() << std::endl;  // 14

    try {
        sp.addNumber(100);
    }
    catch (const Span::FilledException &e) {
        std::cerr << "filled" << std::endl;
    }

    std::cout << "=== numerous numbers test ====" << std::endl;
    unsigned int bigNum = 20000;
    Span longSp = Span(bigNum);
    srand((unsigned int)time(NULL));
    std::vector<int> numbers;
    for (unsigned int i = 0; i < bigNum; i++) {
        numbers.push_back(rand());
    } 
    longSp.addNumbers(numbers.begin(), numbers.end());

    std::cout << longSp.shortestSpan() << std::endl;
    std::cout << longSp.longestSpan() << std::endl;

    try {
        longSp.addNumbers(numbers.begin(), numbers.end());
    }
    catch (const Span::FilledException &e) {
        std::cerr << "filled" << std::endl;
    }

    std::cout << "=== empty error test ====" << std::endl;
    Span emptySp = Span();

    try {
        emptySp.shortestSpan();
    }
    catch (const Span::NoSpanException &e) {
        std::cerr << "no enogh span" << std::endl;
    }
    try {
        emptySp.longestSpan();
    }
    catch (const Span::NoSpanException &e) {
        std::cerr << "no enogh span" << std::endl;
    }

    std::cout << "=== one element error test ====" << std::endl;
    Span oneElementSp = Span(1);
    oneElementSp.addNumber(1);

    try {
        oneElementSp.shortestSpan();
    }
    catch (const Span::NoSpanException &e) {
        std::cerr << "no enogh span" << std::endl;
    }
    try {
        oneElementSp.longestSpan();
    }
    catch (const Span::NoSpanException &e) {
        std::cerr << "no enogh span" << std::endl;
    }
}
