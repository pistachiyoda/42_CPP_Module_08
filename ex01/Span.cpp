#include "Span.hpp"

Span::Span() : n_(0)
{
}

Span::Span(unsigned int n) : n_(n)
{
}

Span::Span(const Span &span)
{
    *this = span;
}

Span &Span::operator=(const Span &span)
{
    if (this == &span)
        return *this;
    n_ = span.n_;
    numbers_ = span.numbers_;
    return *this;
}

Span::~Span()
{}

unsigned int Span::getN() const
{
    return n_;
}

std::vector<int> Span::getNumbers() const
{
    return numbers_;
}

void Span::addNumber(int number)
{
    if (numbers_.size() >= n_)
        throw FilledException();
    numbers_.push_back(number);
}

unsigned int Span::shortestSpan() const
{
    if (numbers_.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted = numbers_;
    // 破壊的なのでコピーしてからソート
    std::sort(sorted.begin(), sorted.end());
    std::vector<int>::iterator current = sorted.begin();
    std::vector<int>::iterator next = ++sorted.begin();
    unsigned int minSpan = (unsigned int)*next - *current;
    current = next;
    next++;
    while (next != sorted.end())
    {
        if ((unsigned int)*next - *current < minSpan)
            minSpan = (unsigned int)*next - *current;
        current = next;
        next++;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (numbers_.size() < 2)
        throw NoSpanException();
    std::vector<int> sorted = numbers_;
    std::sort(sorted.begin(), sorted.end());
    return (unsigned int)sorted.back() - sorted.front();
}
