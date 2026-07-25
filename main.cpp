#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_STUDENTS 5

struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}

void highestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

    float highestGrade = students[0].studentGrades;

    for (int i = 0; i < count; i++)
    {
        if (students[i].studentGrades > highestGrade)
        {
            highestGrade = students[i].studentGrades;
        }
    }
    cout << "Highest grade:" << endl;
    cout << highestGrade << endl;
    cout << "Student name:" << endl;

    for (int i = 0; i < count; i++)
    {
        if (students[i].studentGrades == highestGrade)
        {
            cout << students[i].studentName << endl;
        }
    }

}
void lowestGrade(Student students[], int count)
{
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

    float lowestGrade = students[0].studentGrades;

    for (int i = 0; i < count; i++)
    {
        if (students[i].studentGrades < lowestGrade)
        {
            lowestGrade = students[i].studentGrades;
        }
    }
    cout << "Lowest grade:" << endl;
    cout << lowestGrade << endl;
    cout << "Student name:" << endl;

    for (int i = 0; i < count; i++)
    {
        if (students[i].studentGrades == lowestGrade)
        {
            cout << students[i].studentName << endl;
        }
    }
}

void averageGrade(Student students[], int count)
{
    if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        sum += students[i].studentGrades;
    }

    float averageGrade = sum / count;

    cout << "Average grade: " << averageGrade << endl;
}
void printStudentId(Student students[], int count)
{
    if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	cout << "Student ID:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << students[i].studentId << endl;
    }
}
void printStudentName(Student students[], int count)
{
    if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
    
	cout << "Student name:" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << students[i].studentName << endl;
    }
}

int main() {
	int count = 0;  
	int choice;    

    Student stu1;
    Student stu2;
    Student stu3;
    Student stu4;
    Student stu5;
    count = 5;

    stu1.studentName = "Alex";
    stu1.studentId = 1;
    stu1.studentGrades = 87.5;

    stu2.studentName = "Bob";
    stu2.studentId = 2;
    stu2.studentGrades = 97.0;

    stu3.studentName = "Chris";
    stu3.studentId = 3;
    stu3.studentGrades = 92.0;

    stu4.studentName = "David";
    stu4.studentId = 4;
    stu4.studentGrades = 60.0;

    stu5.studentName = "Eli";
    stu5.studentId = 5;
    stu5.studentGrades = 97.0;

    cout << fixed << setprecision(1);

    Student students[MAX_STUDENTS] = {stu1, stu2, stu3, stu4, stu5};


	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();  

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

