#include<iostream>
#include<string>
using std::string;

/*
-------------------------
ENCAPSULATION
--> YOU REACH IT IN MY OWN WAY!
Blocking other classes to reach encapsulated classe's attributes and methods directly
Instead letting them to reach these with a way that provided exclusively
Those ways are getter-setter likely methods
-------------------------
-------------------------
ABSTRACTION
--> HIDE COMPLEXITY!
Every Class links itself to Abstract Class must do the obligations
of Abstract Class
-------------------------
-------------------------
INHERITANCE
Parent Class - Super Class
Child Class - Sub Class

Child Class takes all attributes and methods from Parent Class
Child Class can also have it's own methods and attributes
-------------------------
-------------------------
POLYMORPHISM (Many Forms)

A method can be written in Parent Class and Child Class too
Employee *e1 = &d;
d->Work();
If there is no Work() implementation in Developer Class then Work() in Parent class
will be invoked
But if there is a Work() implementation in Developer Class then it will be invoked

*/

class AbstractEmployee { //ABSTRACT CLASS
	virtual void AskForPromotion() = 0; // Pure Virtual Function - Abstract Function
};



//final keyword prevents other classes inherit from a class
class Employee : AbstractEmployee { // Class accepted Abstract Class'es obligatories
protected: // Derived class can access protected data
	string Name;
private: // Private:This data is Only for this class 
	string Company; //Attributes
	int Age;
public: // All attributes are private by default
	Employee(string name, string company, int age) { // CONSTRUCTOR
		Name = name;
		Company = company;
		Age = age;
	};
	void Introduce() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}
	void setName(string name) { //name setter method
		Name = name;
	}
	string getName() { //name getter method
		return Name;
	}
	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}
	auto setAge(int age) {
		if (age >= 18) {
		Age = age;
		}
		return 17.56;
	}
	int getAge() {
		return Age;
	}
	void AskForPromotion() { //Overriding Abstract Classes Method -AN OBLIGATION
		if (Age > 30) {
			std::cout << Name << " got promoted" << std::endl;
		}
		else {
			std::cout << Name << ", sorry no promotion for you" << std::endl;
		}
	}
	virtual void Work() { 
		/*
			Virtual Means:
			Check Work() method inside derived classes
			and if there is a newer version then invoke that one not this
		*/
		std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
	}
};



// Inheritance is private by default
// Private: Access is only for inside of the sub class
// Public: Access in and out of the sub class
class Developer: public Employee {//Child Class
public:
	// Child Constructor
	Developer(string name, string company, int age, string language)
	:Employee(name, company, age)
	{
		FavProgLan = language;
	}
	string FavProgLan;
	void FixBug() {
		std::cout << Name << " fixed bug using " << FavProgLan << std::endl;
	}
	void Work() {
		std::cout << Name << " is solving problems with " << FavProgLan << ", programming, making money and happy!" << std::endl;
	}
};

class Teacher : public Employee { //Child Class
private:
	string Subject;
public:
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	{
		Subject = subject;
	}
	void PrepareLesson() {
		std::cout << getName() << " is preparing " << Subject << " lesson" << std::endl;
	}
	void Work() {
		std::cout << Name << "is teaching children " << Subject << " and happy!" << std::endl;
	}
};

int main()
{
	Employee employee1 = Employee("Beste", "XY", 24); // Object employee1
	Employee employee2 = Employee("John", "Amazon", 35); // Object employee2
	//employee1.AskForPromotion();
	//employee2.AskForPromotion();
	Developer d = Developer("Metin", "Google", 24, "Python");
	Teacher t = Teacher("Jack", "School", 31, "Mathematics");
	//t.PrepareLesson();
	//t.AskForPromotion();

	//d.Work();
	//t.Work();

	Employee *e1 = &d;
	Employee *e2 = &t;
	e1->Work();
	e2->Work();


	//d.AskForPromotion();
	//std::cout << d.getName();
	//employee1.Introduce();
	//employee2.Introduce();
	//employee1.setAge(17);
	//std::cout << employee1.getName() << " is " << employee1.getAge() << " years old." << std::endl;
	//std::cout << employee1.setAge(24) << std::endl;
	return 0;
}
