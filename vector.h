#ifndef __vector_h__
#define __vector_h__

template <typename T> class vector {
    public:
        vector();
        vector(unsigned int a);
        vector(unsigned int a, T val);
        vector(const vector& copy);
        int size() const;
        void push_back(const T& val);
        void pop_back();
        T operator[](unsigned int pos) const;

    private:
        unsigned int size_;
        unsigned int allocation_size_;
        T* data_;
};

template <typename T>
vector<T>::vector() {
    size_ = 0;
    allocation_size_ = 0;
}

template <typename T>
vector<T>::vector(unsigned int a) {
    size_ = a;
    allocation_size_ = a;
    data_ = new T[a];
}

template <typename T>
vector<T>::vector(unsigned int a, T val) {
    size_ = a;
    allocation_size_ = a;
    data_ = new T[size_];
    for (int i = 0; i < size_; i++) {
        data_[i] = val;
    }
}

template <typename T>
vector<T>::vector(const vector& copy) {
    size_ = copy.size();
    allocation_size_ = size_;
    data_ = new T[size_];
}

template <typename T>
void vector<T>::push_back(const T& val) {
    if (size_ == 0) {
        size_ = 1;
        allocation_size_ = 1;
        data_ = new T[allocation_size_];
        data_[0] = val;
    } else {
        if (size_ >= allocation_size_) {
            // Need to double the allocation
            T* temp = data_;
            allocation_size_ *= 2;
            data_ = new T[allocation_size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = temp[i];
            }
            data_[size_] = val;
            size_++;
            delete[] temp;
        } else {
            data_[size_] = val;
            size_++;
        }
    }
}

template <typename T>
void vector<T>::pop_back() {
    size_ = size_ - 1;
}

template <typename T>
T vector<T>::operator[](unsigned int pos) const {
    return *(data_ + pos);
}

template <typename T>
int vector<T>::size() const {
    return size_;
}

#endif
