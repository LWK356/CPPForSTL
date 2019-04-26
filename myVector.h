//
// Created by ttp on 2019/4/26.
//

#ifndef UNTITLED1_MYVECTOR_H
#define UNTITLED1_MYVECTOR_H

template<class T>
class myVector {
public:
    typedef T value_type;

    class iterator {
        friend class myVector<T>;

        typedef T value_type;
    protected:
        T *point;
    public:
        iterator &operator++() {
            point++;
            return *this;
        }

        iterator &operator--() {
            point--;
            return *this;
        }

        iterator &operator=(iterator &it) {
            this->point = it.point;
            return *this;
        }

        bool operator!=(const iterator &iter) {
            return this->point != iter.point;
        }

        bool operator==(const iterator &iter) {
            return iter.point == point;
        }

        T &operator*() {
            return *point;
        }

        T *operator->() {
            return point;
        }

        iterator &operator+(int n) {
            this->point += n;
            return *this;
        }

        iterator &operator-(int n) {
            this->point -= n;
            return *this;
        }

        int operator-(iterator &it) {
            return this->point - it.point;
        }

        bool operator<(const iterator &iter) {
            return iter.point < point;
        }

        bool operator>(const iterator &iter) {
            return iter.point > point;
        }
    };

private:
    iterator begin_;  // 表示目前使用空间的头部
    iterator end_;    // 表示目前使用空间的尾部
    iterator cap_;    // 表示目前储存空间的尾部
    int nowGetLen;
public:
    myVector() {
        nowGetLen = 4;
        begin_.point = new T[nowGetLen];
        end_.point = begin_.point;
        cap_.point = begin_.point + nowGetLen;
    }

    void push_back(const T &element) {
        int len = end_.point - begin_.point;
        if (nowGetLen > len) {
            *(end_) = element;
            ++end_;
        } else {
            iterator begin_2;
            begin_2.point = new T[nowGetLen * 2];
            for (int i = 0; i < nowGetLen; ++i) {
                *(begin_2.point + i) = *(begin_.point + i);
            }
            nowGetLen *= 2;
            delete begin_.point;
            begin_ = begin_2;
            end_.point = begin_.point + len;
            cap_.point = begin_.point + nowGetLen;
            *(end_) = element;
            ++end_;
        }
    }

    T &operator[](int n) {
        return *(begin_.point + n);
    }

    virtual ~myVector() {
        delete begin_.point;
    }

    iterator &begin() {
        return begin_;
    }

    iterator &end() {
        return end_;
    }
};

#endif //UNTITLED1_MYVECTOR_H
