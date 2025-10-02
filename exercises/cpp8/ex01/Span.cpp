#include "Span.hpp"

// Span::Span() : N(N), data_(NULL), filled(0){}
Span::Span(unsigned int N) : N(N){
    std::cout << "Constructor!" << std::endl;
}
Span::~Span(){
        std::cout << "Destructor!" << std::endl;
}
Span::Span(const Span &other)
{
    if(other.N > 0){
        this->data_ = other.data_;
        this->N = other.N;
    } else{
        data_.clear();
        N = 0;
    }
    std::cout << "Copy constructor: size = " << this->N << std::endl;
    printArray();
}

 Span& Span::operator=(const Span &other){
    if(this != &other)
    {
        this->N = other.N;

        if(other.N > 0){
            this->data_ = other.data_;
        } else{
            data_.clear();
            this->N = 0;
        }
    }
    std::cout << "Copy operator: size = " << this->N << std::endl;
    printArray();
    return *this;
}

void Span::addNumber(int n){
    if(data_.size() < N)
        data_.push_back(n);
     else
        throw OutOfRange();
    std::cout << "Added a number!" << std::endl;
}

void Span::addRange(std::vector<int>::iterator first, std::vector<int>::iterator last){
    if((unsigned)std::distance(first, last) > N - data_.size())
        throw AddingTooMany();
    data_.insert(data_.end(), first, last);
}

void Span::fillFull(std::vector<int>::iterator first, std::vector<int>::iterator last){
    while((unsigned)std::distance(first, last) > N - data_.size()) // it never comes here
        data_.insert(data_.end(), first, last);
    std::vector<int>::iterator it = first;
    while(data_.size() < N) // comes straight here <-----------------------------------------
        data_.push_back(*(it++));
}

void Span::printArray(){
    std::vector<int>::iterator it = data_.begin();
    for(; it != data_.end(); it++)
        std::cout << *it << std::endl;
}

void Span::printBig(){
    std::vector<int>::iterator it = data_.begin();
    for(; it != data_.end(); it++)
        std::cout << "["<< *it << "]";
    std::cout << std::endl;
}
int Span::shortestSpan(){
    if(data_.size() < 2)
        throw SpanNotEnough();
    std::vector<int> sorted = data_;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted[1] - sorted[0];
    for(unsigned int i = 2; i < sorted.size(); i++)
    {
        if(sorted[i] - sorted[i - 1] < min)
            min = sorted[i] - sorted[i - 1];
    }

    return min;
}

int Span::findMin(){
    //  if(data_.size() < 2)
    //     throw SpanNotEnough();
    std::vector<int>::iterator it = std::min_element(data_.begin(), data_.end());
    if(it != data_.end())
        return *it;
    else
        throw SpanNotEnough(); // test this shit!!!
}
int Span::findMax(){
    std::vector<int>::iterator it = std::max_element(data_.begin(), data_.end());
    if(it != data_.end())
        return *it;
    else
        throw SpanNotEnough(); // test this shit!!!
}

int Span::longestSpan(){
    if(data_.size() < 2)
        throw SpanNotEnough();
    return findMax() - findMin();
}
unsigned int Span::getN(){return N;}