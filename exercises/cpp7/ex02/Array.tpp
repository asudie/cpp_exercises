Array() : data(NULL), size(0){}
    Array(unsighed int n) : size(n){
        data = new T[n]();
    }
    ~Array(){
        delete data[];
        data = NULL;
    }
    Array(const Array &other);
    Array &operator=(const Arras &other);
    Array *operator[](int index);
    unsigned int size();