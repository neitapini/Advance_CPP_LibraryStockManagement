# OperatorsOverloading
Exercise console c++, about overloading operators as cout and cin

include<iostream>
#include<string>
using namespace std;

//Structs of Address, Date and Student
struct Address
{
	int strNumber;
	string strName;
	int appNum;
	string city;
	string zipCode;
	string province;
	string country;

};
struct Date
{
	int day;
	int month;
	int year;
};
struct Student
{
	int id;
	string fn;
	string ln;
	Date regDate;
	Address address;
};

//Prototypes
ostream & operator << (ostream & out_stream, Address & an_address);
istream & operator >> (istream & input_stream, Address & an_address);
ostream & operator << (ostream & out_stream, Date & a_date);
istream & operator >> (istream & input_stream, Date & a_date);
ostream & operator << (ostream & out_stream, Student & a_student);
istream & operator >> (istream & input_stream, Student & a_student);


//Main function, entry point of the application
int main()
{
	
	Student s1;
	cin >> s1;
	cout << s1;

	
	system("pause");
	return 0;
}

//Functions operators Overloading
ostream & operator << (ostream & out_stream, Address & an_address)
{
	out_stream << "\nThe student addres is: ";
	out_stream << an_address.strNumber << ", " << an_address.strName << ", " << an_address.appNum << ", " << an_address.city << ", " << an_address.zipCode << ", " << an_address.country << ", " << an_address.country << endl;
	return out_stream;
}
istream & operator >> (istream & input_stream, Address & an_address)
{

	cout << "Enter the address : ";
	cout << "Street Number: ";
	input_stream >> an_address.strNumber;
	input_stream.ignore();
	cout << "Street Name: ";
	getline(input_stream, an_address.strName);
	cout << "Appartment number: ";
	input_stream >> an_address.appNum;
	input_stream.ignore();
	cout << "City: ";
	getline(input_stream, an_address.city);
	cout << "Zip Code: ";
	getline(input_stream, an_address.zipCode);
	cout << "Province: ";
	getline(input_stream, an_address.province);
	cout << "Country: ";
	getline(input_stream, an_address.country);

	return input_stream;

}
ostream & operator << (ostream & out_stream, Date & a_date)
{
	out_stream << "\nThe student registration date is: ";
	out_stream << a_date.day << "/" << a_date.month << "/" << a_date.year << endl;
	return out_stream;
}
istream & operator >> (istream & input_stream, Date & a_date)
{

	cout << "Enter the registration date expressed as day, month and year: ";
	input_stream >> a_date.day;
	input_stream >> a_date.month;
	input_stream >> a_date.year;

	return input_stream;

}
ostream & operator << (ostream & out_stream, Student & a_student)
{
	out_stream << "The student information is: ";
	out_stream << a_student.id << " - " << a_student.fn << " - " << a_student.ln << " - " << a_student.regDate << a_student.address << endl;
	return out_stream;
}
istream & operator >> (istream & input_stream, Student & a_student)
{

	cout << "Enter id, fn, ln: ";
	input_stream >> a_student.id;
	input_stream.ignore();
	getline(input_stream, a_student.fn);
	getline(input_stream, a_student.ln);
	Date regS1;
	input_stream >> regS1;
	a_student.regDate = regS1;
	Address addressS1;
	input_stream >> addressS1;
	a_student.address = addressS1;

	return input_stream;

}
