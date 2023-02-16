#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int n_;
    std::vector<int> numbers_;

public:
    Span();
    Span(unsigned int n);
    Span(const Span &span);
    Span &operator=(const Span &span);
    ~Span();

    unsigned int getN() const;
    std::vector<int> getNumbers() const;

    void addNumber(int number);
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
        Iterator it;
        for (it = begin; it != end; it++) {
            addNumber(*it);
        }
    }

    class FilledException : public std::exception
    {};
    class NoSpanException : public std::exception
    {};
};

#endif
