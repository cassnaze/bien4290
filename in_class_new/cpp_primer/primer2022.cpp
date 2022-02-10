#include "primer2022.hpp"


// This is the constructor -> define addr like normal, but its just another function named the same thing
	// This means we just have to have the duplicate name of the class
mySpace::yourSpace::myClass::myClass(std::string name, int init_num_students){
	this->className = name;
	this->num_students = init_num_students;
}

int mySpace::yourSpace::myClass::get_num_students(){
	
	return this->num_students;
}

std::vector<std::string>* mySpace::yourSpace::myClass::get_classlist(){
	return &(this->classlist); // Accessing the reference of the classlist
}