#ifndef MY_LIST_H
#define MY_LIST_H
//简单的list
//节点
template<typename T>
struct list_node {
    list_node<T>* prev;
    list_node<T>* next;
    T data;
};
// 迭代器
template<typename T>
struct list_iterator {
    typedef list_iterator<T> iterator;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;

    list_node<T>* node;

    list_iterator(list_node<T>* n = nullptr) : node(n) {}

    // 前置++
    iterator& operator++() {
        node = node->next;
        return *this;
    }

    // 后置++
    iterator operator++(int) {
        iterator tmp = *this;
        node = node->next;
        return tmp;
    }

    // 前置--
    iterator& operator--() {
        node = node->prev;
        return *this;
    }

    // 后置--
    iterator operator--(int) {
        iterator tmp = *this;
        node = node->prev;
        return tmp;
    }

    reference operator*() {
        return node->data;
    }

    pointer operator->() {
        return &(node->data);
    }

    bool operator==(const iterator& other) const {
        return node == other.node;
    }

    bool operator!=(const iterator& other) const {
        return node != other.node;
    }
};

// list
template<typename T>
struct my_list {
    typedef list_iterator<T> iterator;
    typedef list_node<T>* pointer;

    my_list() {
        node = new list_node<T>;
        node->next = node;
        node->prev = node;
    }

    ~my_list() {
        clear();
        delete node;
    }

    iterator begin() {
        return iterator(node->next);
    }

    iterator end() {
        return iterator(node);
    }

    void insert(iterator pos, const T& value) {
        list_node<T>* new_node = new list_node<T>;
        new_node->data = value;

        list_node<T>* cur = pos.node;
        new_node->next = cur;
        new_node->prev = cur->prev;

        cur->prev->next = new_node;
        cur->prev = new_node;
    }

    void erase(iterator pos) {
        list_node<T>* cur = pos.node;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }

    void push_back(const T& value) {
        insert(end(), value);
    }

    iterator pop_back() {
        iterator tmp = iterator(node->prev);
        erase(tmp);
        return tmp;
    }

    void clear() {
        while (begin() != end()) {
            erase(begin());
        }
    }

private:
    pointer node; // 哨兵节点
};

template<typename T>
void  printVec(T begin,T end) {
    while(begin!=end) {
        printf("%d ",*begin);
        begin++;
    }
    printf("\n");
}

template<typename T>
void  printList(list_node<T>* begin,list_node<T>* end) {
    while(begin!=end) {
        printf("%d ",begin->data);
        begin=begin->next;
    }
    printf("\n");
}

template<typename T>
void printContiner(T begin,T end) {
    while(begin!=end) {
        printf("%d ",*begin);
        begin++;
    }
    printf("\n");
}

#endif //MY_LIST_H
