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

    public:
        // constructors
        vector() {
            data_ = new ValueT[0];
			size_ = 0;
        }

        vector(const int size) {
            data_ = new ValueT[size];
			size_ = size;
        }

        vector(const int size, const ValueT value) {
            data_ = new ValueT[size];
			size_ = size;

            for (int i = 0; i < size; i++) {
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
			return size_ == 0;
        }

        size_t size() const {
			return size_;
        }

		void clear() {
			size_ = 0;
			data_ = new ValueT[size_];
		}

		void push_back(const ValueT& value) {
			ValueT* newData = new ValueT[size_ + 1];

			std::copy(data_, data_ + size_, newData);
			newData[size_++] = value;

			delete[] data_;
			data_ = newData;
		}

		ValueT pop_back() {
			auto pop = data_[--size_];

			auto newData = new ValueT[size_];
			std::copy(data_, data_ + size_, newData);

			delete[] data_;
			data_ = newData;

			return pop;
		}

		ValueT& operator[](const int index) {
			return data_[index];
		}

		ValueT operator[](const int index) const {
			return data_[index];
		}

		ValueT& at(const size_t index) {
			if (index >= size_) throw std::out_of_range("index out of range");
			return data_[index];
		}

		ValueT& at(const size_t index) const {
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