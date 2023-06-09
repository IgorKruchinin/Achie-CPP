//
// Created by smurf on 20.07.22.
//

#ifndef USM_SECTION_H
#define USM_SECTION_H
#include <vector>
#include <string>

class IntSection {
    std::string name_;
    //std::string::iterator it;
    //std::string line;
    std::vector<long> objects_;
    bool add_flag_;
public:
    IntSection(const std::string& name);
    IntSection(const std::string& name, const std::vector<long>& vec);
    void add(long object);
    std::vector<long>& get_objects();
    //void add(int object);
    size_t size();
    const long operator[] (size_t index);
    //auto operator[] (int index) -> decltype(objects_[index].get_type());
};

class StringSection {
    std::string name_;
    //std::string::iterator it;
    //std::string line;
    std::vector<std::string> objects_;
    bool add_flag_;
public:
    StringSection(const std::string& name);
    StringSection(const std::string& name, const std::vector<std::string>& vec);
    void add(const std::string& object);
    std::vector<std::string>& get_objects();
    //void add(int object);
    size_t size();
    //auto operator[] (int index) -> decltype(objects_[index].get_type());
    const std::string& operator[] (size_t index);
};


#endif //USM_SECTION_H
