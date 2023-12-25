#pragma once

#include <algorithm>
#include <string>
#include <sstream>

namespace my {
template<typename ValueT>
class vector {
    private:
        ValueT* data_;
        size_t size_;
		size_t capacity_;

    public:
        // constructors
        vector() {
			capacity_ = 10;
			size_ = 0;
            data_ = new ValueT[0];
			// data_ = nullptr;
        }

        vector(const int capacity) {
			capacity_ = capacity;
			size_ = 0;
            data_ = new ValueT[capacity];
        }

        vector(const int capacity, const ValueT value) {
			capacity_ = capacity;
			size_ = capacity;
            data_ = new ValueT[capacity];

            for (int i = 0; i < capacity; i++) {
                data_[i] = value;
            }
        }

		vector(vector<ValueT> const &) = delete;

		// destructor
		~vector() {
			// Call the destructor for each object in the array
			// for (size_t i = 0; i < size_; ++i) {
			// 	data_[i].~ValueT();
			// }
        	delete[] data_;
    	}

		// methods
        bool empty() const {
            // return std::all_of(std::begin(data_), std::end(data_), [](const T& el){ return el == nullptr; });
			return size_ == 0;
        }

        size_t size() const {
            // return std::count_if(std::begin(data_), std::end(data_), [](const T& el){ return el != nullptr; });
			return size_;
        }

		void clear() {
			size_ = 0;
			capacity_ = 10;
            data_ = new ValueT[capacity_];
		}

		void push_back(const ValueT& value) {
			if (size_ >= capacity_) {
				capacity_ = capacity_ > 0 ? capacity_ * 2 : 1;
				auto newData = new ValueT[capacity_];
				// std::copy(data_, data_ + size_, newData);

				// Manually copy the elements to the new array
				for (size_t i = 0; i < size_; ++i) {
					// newData[i] = ValueT(data_[i]);
            		new (newData + i) ValueT(data_[i]);
				}

				delete[] data_;
				data_ = newData;
			}
			// data_[size_++] = value;
			new (data_ + size_) ValueT(value);
			size_++;
		}

		ValueT pop_back() {
			auto first = data_[0];

			auto newData = new ValueT[capacity_];
			std::copy(data_ + 1, data_ + size_, newData);
			delete[] data_;
			data_ = newData;
			size_--;
			if (size_ < capacity_ / 3) capacity_ /= 2;

			return first;
		}

		ValueT& operator[](const ValueT index) {
			return data_[index];
		}

		ValueT operator[](const ValueT index) const {
			return data_[index];
		}

		ValueT& at(const size_t index) {
			if (index >= size_) throw std::out_of_range("index out of range");
			return data_[index];
		}

		vector<ValueT>& operator=(vector<ValueT> const &) = delete;

		std::string toString() const {
			std::ostringstream oss;
			oss << "[";

			for (size_t i = 0; i < size_; ++i) {
				oss << data_[i];
				if (i < size_ - 1) {
					oss << ", ";
				}
			}

			oss << "]";
			return oss.str();
		}
};
}