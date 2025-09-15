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
    Array<T> arr(other);
    return arr;
}

// Array *operator[](int index);

template <typename T>
unsigned int Array<T>::size(){return size_;}

template <typename T>
T* Array<T>::getData(){return data_;}