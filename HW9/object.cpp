#include "object.hpp"

template <typename T>
object::T_pointer<T>::T_pointer(T value) {

}

template <typename T>
const std::type_info& object::T_pointer<T>::type() const {

}

template <typename T>
object::object_pointer* object::T_pointer<T>::copy() const {

}

template <typename T> 
object::object(const T& value) {

}

object::~object() {

}

object& object::operator=(const object& other) {

}

object::object(const object& other) {

}

const std::type_info& object::type() const {

}

template <typename T>
T object::cast_back() const {
    
}