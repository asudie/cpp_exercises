#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    unsigned int N;
    std::vector<int> data_;
    int findMin();
    int findMax();
    

public:
    //Span();
    Span(unsigned int N);
    ~Span();
    Span(const Span &other);
    Span &operator=(const Span &other);

    void addNumber(int n);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void fillFull(std::vector<int>::iterator first, std::vector<int>::iterator last);
    int shortestSpan();
    int longestSpan();
    unsigned int getN();
    void printArray();

    class OutOfRange : public std::exception {
	public:
		const char* what() const throw() {
			return "You've reached the limit of elements";
		}
	};

    class SpanNotEnough : public std::exception {
	public:
		const char* what() const throw() {
			return "There are less than 2 elements";
		}
	};

    class AddingTooMany : public std::exception {
	public:
		const char* what() const throw() {
			return "You are adding too many elements";
		}
	};
};