#include <iostream>
#include <algorithm>

template<class t>
class Array {
public:
    Array():size_(1)
    {
        this->capacity = size_;
        this->data_ = new t[size_]{};

    }

    /*Array(int new_size_) :size_(new_size_){
        capacity = new_size_;
        data_ = new t[new_size_];
        for (int i = 0; i < size_; i++)
        {
            data_[i] = 0;
        }
    }*/

    Array(const Array& arr) {
        this->size_ = arr.size_;
        this->data_ = new t[size_];
        std::memcpy(arr.data_, this->data_,arr.size_);
    }

    void Resize(int new_size) {
        if (new_size > this->capacity)
        {
            int new_capacity = std::max(new_size, this->size_ * 2);
            t* new_data = new t[new_capacity];
            for (int i = 0; i < size_; ++i) {
                new_data[i] = data_[i];
            }
            delete[] this->data_;
            this->data_ = new_data;
            this->capacity = new_capacity;
        }
        this->size_ = new_size;
    }

    void push_back(t new_value) {
        if (data_[0] == 0)
        {
            data_[0] = new_value;
        }
        else {
            Resize(size_ + 1);
            data_[size_ - 1] = new_value;
        }
    }

    void pop_back() {
        if (this->data_) {
            t* tmp = new t[this->size_ - 1];
            for (int i = 0; i < this->size_ - 1; i++)
            {
                tmp[i] = data_[i];
            }
            size_--;
            capacity--;
            for (int i = 0; i < this->size_ - 1; i++) {
                data_[i] = tmp[i];
            }
            delete[] tmp;
        }
    }

    void Check_arr() {
        std::cout << "arr:";
        for (int i = 0; i < size_; i++)
        {
            std::cout << this->data_[i] << ", ";
        }
        std::cout << "\n";
    }


    int size_check()const {
        return this->size_;
    }


    int* begin()
    {
        return &data_[0];
    }

    int* end()
    {
        return &data_[size_];
    }

    t& operator[](int i) {
        return data_[i];
    }

    ~Array() {
        if (data_) {
            delete[] data_;
        }
    }

private:
    int size_;
    t *data_;
    int capacity;
};

int main()
{
    Array<int> arr;
    //Array<int> arr2(12);

    arr.push_back(1);
    //arr2.push_back(13);
    arr.Check_arr();
    arr.pop_back();
    arr.Check_arr();
    arr.size_check();
    return 0;

}

void Function(Array<std::string> obj)
{
    obj.Check_arr();
}


