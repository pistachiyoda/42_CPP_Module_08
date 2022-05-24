#include "Span.hpp"

#include <iostream>

int main()
{
    Span sp = Span(5);

    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(100);
    }
    catch (const Span::FilledException &e)
    {
        std::cerr << "filled" << std::endl;
    }

    Span longSpan = Span(20000);
    std::vector<int> numbers(15000, 100); // 15000の要素を100で初期化
    longSpan.addNumbers(numbers.begin(), numbers.end());
    std::cout << longSpan.getNumbers()[10000] << std::endl;

    try
    {
        longSpan.addNumbers(numbers.begin(), numbers.end());
    }
    catch (const Span::FilledException &e)
    {
        std::cerr << "filled" << std::endl;
    }

    Span emptySpan = Span();
    try
    {
        emptySpan.shortestSpan();
    }
    catch (const Span::NoSpanException &e)
    {
        std::cerr << "no span" << std::endl;
    }
    try
    {
        emptySpan.longestSpan();
    }
    catch (const Span::NoSpanException &e)
    {
        std::cerr << "no span" << std::endl;
    }
}
