/* in class 1/31/2022
 * this code will act has a primer on class design and creation in C++
 * basic form on a class
 */
 
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <vector> //https://en.cppreference.com/w/cpp/container/vector //reallocable vectors
 
 //mySpace::yourSpace::myClass
 
 namespace mySpace{
	 namespace yourSpace{
		class myClass{ // Stuff in the class is already initialized right away
			public:
				myClass(std::string name, int init_num_students); //constructor for myClass with an initial name and num of students 
				myClass(std::string name);
				myClass(); // Doesnt have to have anything in it when we make this
				~myClass(); // Destructor; deallocation; control what happens when a class is about to be removed from memory; close files, disconnect, free mem, etc.
							// References to std objects automatically deaollcate themselves ; have own destructor on the inside
				
				int get_num_students();
				std::string getname();
				void set_num_students(int num);
				void set_name(std::string newname);
				std::vector<std::string>* get_classlist();
				
			private:
				int num_students;
				std::string className;
				std::vector<std::string> classlist; // Saying that this is always going to contain strings
		};
	}
}