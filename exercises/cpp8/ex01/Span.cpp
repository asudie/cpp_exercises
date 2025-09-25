#include "Span.hpp"

Span::Span() : N(N), data_(NULL){}
Span::Span(unsigned int N) : N(N){
    data_ = new int[N];
}
Span::~Span(){
    if(data_)
        delete[] data_;
        data_ = NULL;
}
Span::Span(const Span &other)
{
    if(other.N > 0){
        this->data_ = new int[other.N];

        for(unsigned int i = 0; i < other.N; i++)
            this->data_[i] = other.data_[i];
    } else{
        this->data_ = NULL;
    }
}

Span& Span::operator=(const Span &other){
    if(this != &other)
    {
        delete[] this->data_;
        this->N = other.N;

        if(other.N > 0){
        this->data_ = new int[other.N];

        for(unsigned int i = 0; i < other.N; i++)
            this->data_[i] = other.data_[i];
        } else{
            this->data_ = NULL;
        }
    }
    return *this;
}

void Span::addNumber(){}
int Span::shortestSpan(){}
int Span::longestSpan(){}
unsigned int Span::getN(){return N;}