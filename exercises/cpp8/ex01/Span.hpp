#pragma once

#include <iostream>

class Span
{
private:
    unsigned int N;
    int *data_;

public:
    Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber();
    int shortestSpan();
    int longestSpan();
    unsigned int getN();

    class OutOfRange : public std::exception {
	public:
		const char* what() const throw() {
			return "You've reached the limit of elements";
		}
	};
};