template <typename T>
Array<T>::Array() : data_(NULL), size_(0){std::cout << "Default constructor!" << std::endl;}
    
template <typename T>
Array<T>::Array(unsigned int n) : size_(n){
        data_ = new T[n]();
        std::cout << "Parameter constructor!" << std::endl;
    }

template <typename T>
Array<T>::~Array(){
        delete[] data_;
        data_ = NULL;
        std::cout << "Destructor!" << std::endl;

    }

template <typename T>
Array<T>::Array(const Array &other) : size_(other.size_)
{
    if(other.size_ > 0){
        this->data_ = new T[other.size_];

        for(unsigned int i = 0; i < other.size_; i++)
            this->data_[i] = other.data_[i];
    } else{
        this->data_ = NULL;
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other){
    if(this != &other)
    {
        delete[] this->data_;
        this->size_ = other.size_;

        if(other.size_ > 0){
        this->data_ = new T[other.size_];

        for(unsigned int i = 0; i < other.size_; i++)
            this->data_[i] = other.data_[i];
        } else{
            this->data_ = NULL;
        }
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](int index){
    if(index < 0 || (unsigned int)index >= this->size_)
        throw OutOfRange();
    return this->data_[index];
        
}

template <typename T>
unsigned int Array<T>::size(){return size_;}

template <typename T>
T* Array<T>::getData(){return data_;}

template <typename T>
void Array<T>::setData(unsigned int i, T el){
    this->data_[i] = el;
}