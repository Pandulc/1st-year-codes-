#include <string>
#include <cstring>
using namespace std;

class Pets{
private:
	string type;
	string race;
	string name;
	string responsable_person;
	int age;
public:
	Pets();
	void setType(string ty);
	string getType(void);
	void setRace(string ra);
	string getRace(void);
	void setName(string na);
	string getName(void);
	void setResponsable(string re);
	string getResponsable(void);
	void setAge(int ag);
	int getAge(void);
	string toString(void);
	
};

Pets::Pets(){	
}

void Pets::setType(string ty){
	type=ty;
}

string Pets::getType(){
	return type;
}

void Pets::setRace(string ra){
	race=ra;
}

string Pets::getRace(){
	return race;
}

void Pets::setName(string na){
	name=na;
}

string Pets::getName(){
	return name;
}

void Pets::setResponsable(string re){
	responsable_person=re;
}

string Pets::getResponsable(){
	return responsable_person;
}

void Pets::setAge(int ag){
	age=ag;
}

int Pets::getAge(){
	return age;
}

string Pets::toString(){
	string print_string = " ";
	print_string = "Tipo:"+type+"Raza:"+race+"Nombre:"+name+"Responsable a cargo:"+responsable_person+"Edad:"+to_string(age);
	return print_string;
}
