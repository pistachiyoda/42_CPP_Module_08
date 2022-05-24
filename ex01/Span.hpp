#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>

// 最大N個のintを格納するコンテナクラス
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
    // 渡された値をコンテナに追加する
    // すでにN個の要素が格納されていた場合はexceptionを出す
    void addNumber(int number);
    // 複数の数字を受け取る事もできる
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end)
    {
        Iterator it;
        for (it = begin; it != end; it++)
        {
            addNumber(*it);
        }
    }
    // 格納されているすべての要素の中で最小の差を返す
    // [1, 3, 10] だったら3 - 1で2
    // 要素数が2個未満の場合はexceptionを出す
    // intのmaxとminの差はintじゃ表現できないのでunsigned intで返す
    unsigned int shortestSpan() const;
    // shortestSpan逆で最大の差を求める
    unsigned int longestSpan() const;

    class FilledException : public std::exception
    {};

    class NoSpanException : public std::exception
    {};
};

#endif
