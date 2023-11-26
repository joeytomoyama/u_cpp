#pragma once

template<typename T, int N>
class vector {
    private:
        T* data_;
        size_t size_;

    public:
        // constructor
        vector() {
            data_ = new T[0];
        }

        vector(const int size, const double value) {
            data_ = new T[size];

            for (int i = 0; i < size; i++) {
                data_[i] = value;
            }
        }

        vector(const int size) {
            // TODO
        }

        bool empty() const {
            return data_.empty();
        }

        size_t size() const {
            return data_.size();
        }
}