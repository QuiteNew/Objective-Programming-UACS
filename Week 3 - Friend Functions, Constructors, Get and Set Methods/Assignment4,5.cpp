#include <iostream>
using namespace std;

//	remove these comments for Assignment 5

class student
{
	double gpa;
	int credits;

public:
	student();
	student(double, int);
	~student();

	double getGPA();
	int getCredits();
};

student::student()
{
	gpa = 0.0;
	credits = 0;
//	cout << "Creating student with gpa: " << 0 << " and credits: " << 0 << endl;

}

student::student(double g, int c)
{
	gpa = g;
	credits = c;
//	cout << "Creating student with gpa: " << gpa << " and credits: " << credits << endl;
}

student::~student()
{
//	cout << "Destroying student with gpa: " << gpa << " and credits: " << credits << endl;
}

double student::getGPA()
{
	return gpa;
}

int student::getCredits()
{
	return credits;
}



int main()
{
	int num, i;
	cout << "How many students will there be? ";
	cin >> num;

	student *s = new student[num];			// equivalent to new student()[num]

	double g;
	int c;

	for(i = 0; i < num; i++)
	{

		cout << "Student " << i << " - GPA:      ";
		cin >> g;
		cout << "Student " << i << " - Credits:  ";
		cin >> c;

//		cout << "Creating the pointer" << endl;
		student *sp = new student(g, c);
//		cout << "Dereferencing the pointer and assigning its value" << endl;
		s[i] = *sp;		// storing the value of the student in the array
//		cout << "Deleting the pointer" << endl;
		delete sp;
		cout << endl;
	}

	double sumGPA = 0;
	int sumcred = 0;
	cout << "The following students have been input:" << endl;
	for(i = 0; i < num; i++)
	{
		cout << "Student " << i << "\tGPA: " << s[i].getGPA() << "\tCredits: " << s[i].getCredits() << endl;
		sumGPA+= s[i].getGPA();
		sumcred += s[i].getCredits();
	}
	cout << "The average GPA of all students is " << sumGPA/num << " and a total of " << sumcred << " credits were achieved" << endl;

    return 0;
}
