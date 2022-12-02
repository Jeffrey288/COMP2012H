CPPFLAGS = -std=c++11

OBJECTS = grader
SOURCES_PART1 = skiplist.hpp skiplist.tpp main.cpp
SOURCES_PART2 = object_replaced.hpp object.tpp main.cpp

all: $(OBJECTS)

object_replaced.hpp:
	@sed 's/T \+value *;/T value; T_pointer() = default;/g;s/object() : object(0) {}/object() : object(0) {} template <typename T> object(std::string grading, const T\& value); template <typename T> T get_value() const;/g' object.hpp > object_replaced.hpp
	@echo "\n#include \"object_grading.tpp\"" >> object_replaced.hpp

grader: $(SOURCES_PART2)
	-g++ -o $@ $(CPPFLAGS) main.cpp

clean:
	rm -rf $(OBJECTS) object_replaced.hpp