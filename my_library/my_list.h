#ifndef MY_LIST_H
#define MY_LIST_H
//简单的list
template<typename T>
//节点
struct list_node {
    list_node<T>* prev;
    list_node<T>* next;
    T data;
};
//list
template<typename T>
struct my_list {
    typedef  list_node<T>* iterator;
    my_list() {
        node=new list_node<T>;
        node->next=node;
        node->prev=node;
    }
    iterator begin() {
        return node->next;
    }
    iterator end() {
        return node;
    }

    void insert(iterator pos, const T& value) {
        iterator tmp = new list_node<T>;
        tmp->data = value;
        tmp->next = pos;
        tmp->prev = pos->prev;
        pos->prev->next = tmp;
        pos->prev = tmp;
    }

    void erase(iterator pos) {
        pos->next->prev=pos->prev;
        pos->prev->next=pos->next;
        delete pos;
    }

    void push_back(const T& value) {
        insert(node,value);
    }

    iterator pop_back() {
        iterator tmp=node->prev;
        erase(node->prev);
        return tmp;
    }
private:
    iterator node;//链表的结尾
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

#endif //MY_LIST_H
