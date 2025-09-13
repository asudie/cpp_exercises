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
    // here
}

   // Array &operator=(const Arras &other);
   // Array *operator[](int index);
template <typename T>
unsigned int Array<T>::size(){return size_;}