#ifndef MY_VECTOR_H
#define MY_VECTOR_H

template<class T>
class my_vector
{
public:
    typedef T value_type;//类型
    typedef T* iterator;//迭代器指针
    typedef T& reference;//引用

    my_vector(int len=0) :m_Data(nullptr),start(nullptr),m_len(len),pos(0) {
        if (len > 0) {
            //创建数组
            m_Data = new T[len];
            start = m_Data;
        }
    }

    ~my_vector() {
        if (m_Data) {
            delete[] m_Data;
            m_Data = nullptr;
        }
    }

    void push_back(const T& data) {

        if(pos==m_len) {//扩容
            int new_len = m_len * 2;
            T* new_data = new T[new_len];
            for (int i = 0; i < m_len; i++) {
                new_data[i] = m_Data[i];
            }
            delete[] m_Data;
            m_Data = new_data;
            m_len = new_len;
            start=m_Data;

        }
        m_Data[pos++] = data;
    }

    value_type pop_back() {
        return m_Data[--pos];
    }

    int size() {
        return pos;
    }

    int capacity() {
        return m_len;
    }
    iterator begin() {
        return start;
    }

    iterator end() {
        return start + pos;
    }

    reference operator[](int index) {
        if(index<pos)
            return m_Data[index];
        else {
            printf("下标越界");
            return m_Data[0];
        }
    }
protected:
    iterator m_Data;//指向数据的指针
    iterator start;//起始地址
    int m_len;//数据长度
    int pos;//当前位置
};


#endif //MY_VECTOR_H
