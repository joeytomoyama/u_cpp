namespace my {

    template<typename ValueT>
    class vector {
    
        private:

            ValueT* vecArray_;
            size_t size_;

        public:
        
            vector();
            vector(size_t n, const ValueT val);
            ~vector();
            bool empty() const;
            size_t size() const;
            void clear();
            void push_back(const ValueT&);
            ValueT pop_back();
            ValueT operator[](size_t) const;
            ValueT& operator[](size_t);
            ValueT at(size_t) const;
            ValueT& at(size_t);
            vector(vector<ValueT> const &) = delete;
            vector<ValueT>& operator=(vector<ValueT> const &) = delete;
    };

    template<typename ValueT>
    vector<ValueT>::vector() {
        vecArray_ = new ValueT[0];
        size_ = 0;
    }

    template<typename ValueT>
    vector<ValueT>::vector(size_t n, const ValueT val) {
        vecArray_ = new ValueT[n];
        size_ = n;
        for (size_t i = 0; i < n; i++) {
            vecArray_[i] = val;
        }
    }

    template<typename ValueT>
    vector<ValueT>::~vector() {
        delete[] vecArray_;
    }

    /**
     * Liefert zurück ob sich Elemente in dem Array befinden
    */
    template<typename ValueT>
    bool vector<ValueT>::empty() const {
        return size_ == 0;
    }

    /**
     * Liefert die Anzahl der Elemente zurück
    */
    template<typename ValueT>
    size_t vector<ValueT>::size() const {
        return size_;
    }

    /**
     * Löscht das Array
    */
    template<typename ValueT>
    void vector<ValueT>::clear() {
        delete[] vecArray_;
        vecArray_ = new ValueT[0];
        size_ = 0;
    }

    /**
     * Fügt ein neues Elemente hinten am Array ein
    */
    template<typename ValueT>
    void vector<ValueT>::push_back(const ValueT& val) {
        ValueT* temp = new ValueT[size_ + 1];
        for (size_t i = 0; i < size_; i++) {
            temp[i] = vecArray_[i];
        }
        temp[size_] = val;
        delete[] vecArray_;
        vecArray_ = temp;
        size_++;
    }

    /**
     * Löscht das letzte Element im Array und liefert es zurück
    */
    template<typename ValueT>
    ValueT vector<ValueT>::pop_back() {
        ValueT* temp = new ValueT[size_ - 1];
        for (size_t i = 0; i < size_ - 1; i++) {
            temp[i] = vecArray_[i];
        }
        ValueT val = vecArray_[size_ - 1];
        delete[] vecArray_;
        vecArray_ = temp;
        size_--;
        return val;
    }

    /**
     * Liefert Referenz auf das gewünschte Element zurück
     * Gibt lesenden Zugriff
    */
    template<typename ValueT>
    ValueT vector<ValueT>::operator[](size_t index) const {
        return vecArray_[index];
    }

    /**
     * Liefert Referenz auf das gewünschte Element zurück
     * Gibt schreibenden Zugriff
    */
    template<typename ValueT>
    ValueT& vector<ValueT>::operator[](size_t index) {
        return vecArray_[index];
    }

    /**
     * siehe operator[]
     * prüft ob Index gültig ist
    */
    template<typename ValueT>
    ValueT vector<ValueT>::at(size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return vecArray_[index];
    }

    template<typename ValueT>
    ValueT& vector<ValueT>::at(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return vecArray_[index];
    }
}