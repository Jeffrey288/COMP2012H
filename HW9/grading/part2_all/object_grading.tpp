template <typename T>
object::object(std::string grading, const T& value) {
    T_pointer<T>* tmp = new T_pointer<T>; tmp->value = value; this->obj_ptr = tmp;
}

template <typename T>
T object::get_value() const {
    return ((T_pointer<T>*)(void*)*(unsigned long long*)this)->value;
}