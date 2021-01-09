#ifndef TLISTITEM_H
#define TLISTITEM_H
#include <memory>
#include <iostream>
#include "pentagon.h"
template <class T>
class TListItem{
private:
    std::shared_ptr<T> item;
    std::shared_ptr<TListItem<T>> next;
    std::shared_ptr<TListItem<T>> prev;
public:
    TListItem(const std::shared_ptr<T> &obj);
    std::shared_ptr<T> GetFigure() const;
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<TListItem<T>> GetPrev();
    void SetNext(std::shared_ptr<TListItem<T>> item);
    void SetPrev(std::shared_ptr<TListItem<T>> item);
    template <class A> friend std::ostream& operator<<(std::ostream &os, const TListItem<A> &obj);
    virtual ~TListItem(){};
};
template <class T>
TListItem<T>::TListItem(const std::shared_ptr<T> &obj){
    this->item = obj;
    this->next = nullptr;
    this->prev = nullptr;
}
template <class T>
std::shared_ptr<T> TListItem<T>::GetFigure() const{
    return this->item;
}
template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext(){
    return this->next;
}
template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetPrev(){
    return this->prev;
}
template <class T>
void TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> item){
    this->next = item;
}
template <class T>
void TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> item){
    this->prev = item;
}
template <class T>
std::ostream& operator<<(std::ostream &os, const TListItem<T> &obj){
    os << obj.item << std::endl;
    return os;
}
#endif
