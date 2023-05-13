//
// Created by smurf on 20.07.22.
//

#include "Section.h"
#include <type_traits>

IntSection::IntSection(const std::string& name)
        : name_(name) {}

StringSection::StringSection(const std::string& name)
        : name_(name) {}

StringSection::StringSection(const std::string& name, const std::vector<std::string>& vec)
    :name_(name), objects_(vec) {}

IntSection::IntSection(const std::string& name, const std::vector<long>& vec)
        :name_(name), objects_(vec) {}


void StringSection::add(const std::string& object) {
    objects_.emplace_back(object);
}

void IntSection::add(long object) {
    objects_.emplace_back(object);
}

std::vector<std::string>& StringSection::get_objects() {
    return objects_;
}

std::vector<long>& IntSection::get_objects() {
    return objects_;
}

/*void Section::add(int object) {
    //Object obj(object, file_);
    objects_.emplace_back(object);
    add_flag_ = true;
}*/

size_t IntSection::size() {
    return objects_.size();
}

size_t StringSection::size() {
    return objects_.size();
}

const long IntSection::operator[] (size_t index) {
    return objects_[index];
}

const std::string& StringSection::operator[] (size_t index) {
    return objects_[index];
}

/*auto Section::operator[] (long index) -> decltype(objects_[index].get_type()) {
    if (objects_[index].get_type() == typeid(long))
        return objects_[index].get_ivalue();
    else
        return objects_[index].get_svalue();
}*/
