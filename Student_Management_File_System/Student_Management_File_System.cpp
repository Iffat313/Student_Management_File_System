/******************************************************************************


*******************************************************************************/
#include <iostream>
#include<fstream>
#include<string>
//Student Management System

using namespace std;

//This is a test for commit or stash

class student
{
public:
    string ID;
    string name;
    int list_grades[5];

};

void menu();

void choice_1();

void choice_2();

void Grade_Calculation();

void choice_3();

void Grade_Analysis();


int
main()
{

    int x;
    do
    {

        menu();
        cout << "Enter your choice(1-4): ";
        cin >> x;

        if (x == 1)
        {
            choice_1();
        }

        if (x == 2)
        {
            choice_2();
        }

        if (x == 3)
        {
            choice_3();
        }

        if (x == 4)
        {
            break;
        }
    } while (x < 4 && x >= 1);



    return 0;
}

// Choices for the menu are programmed via functions: 

void
menu()
{
    cout << "---Student Management Grade System---" << endl;
    cout << "1. Add a new student" << endl;
    cout << "2. Search for a student" << endl;
    cout << "3. Display Class statistics" << endl;
    cout << "4. Exit" << endl;

}

void
choice_1()
{
    ofstream myfile("StudentData.txt", ios::app);

    int num;
    student obj;

    cout << "Enter Student ID: ";
    cin >> obj.ID;
    myfile << obj.ID << endl;

    cout << "Enter Student Name: ";
    cin >> obj.name;
    myfile << obj.name << endl;



    cout << "Enter the number of grades (max 5): ";
    cin >> num;

    cout << "Enter " << num << " grades: " << endl;
    obj.list_grades[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Enter grade " << i + 1 << " : ";
        cin >> obj.list_grades[i];
        myfile << obj.list_grades[i] << " ";

    }
    cout << "Student Data saved to file" << endl;
    myfile << endl;

    myfile.close();


}


void
Grade_Calculation(int num_for_line)
{
    ifstream myreadfile("StudentData.txt");
    int num_for_line2 = num_for_line + 1;
    num_for_line = 0;
    double digits = 0;
    int counter = 0;
    int number;
    int greatest = 0;
    int lowest = 100;
    string mytext2;
    string empty;

    while (getline(myreadfile, mytext2))
    {
        num_for_line++;
        if (num_for_line == num_for_line2)
        {
            cout << "The Student Name is: " << mytext2 << endl;
            break;
        }
    }

    while (myreadfile >> number)
    {
        digits = digits + number;
        counter++;
        if (greatest < number)
        {
            greatest = number;
        }
        if (lowest > number)
        {
            lowest = number;
        }


    }
    digits = digits / counter;
    cout << "The average score is: " << digits << endl;
    cout << "The highest score is: " << greatest << endl;
    cout << "The Lowest score is: " << lowest << endl;

    myreadfile.close();
}


void
choice_2()
{
    int line = 0;


    student obj2;
    obj2.ID;
    cout << "Enter the Student ID to search for: ";
    cin >> obj2.ID;

    string mytext;
    ifstream myreadfile("StudentData.txt");
    while (getline(myreadfile, mytext))
    {
        line++;
        if (mytext == obj2.ID)
        {
            cout << "Student ID found" << endl;
            cout << "The ID is: " << obj2.ID << endl;
            break;
        }

    }

    if (mytext != obj2.ID)
    {
        cout << "This ID does not exsist" << endl;
    }

    if (mytext == obj2.ID)
    {

        Grade_Calculation(line);



    }

    myreadfile.close();

}

void
Grade_Analysis()
{
    ifstream myreadfile("StudentData.txt");	//make it to where program reads every third line that way its guarenteed numbers
    int data;
    int total = 0;
    int lineplacement = 0;
    int counter_2 = 0;


    while (myreadfile >> data) {
        cout << "THIS SHOULD POP UP IN THE CONCOLE" << endl;
        lineplacement++;
        if (lineplacement % 3 == 0) {
            counter_2++;
            total = total + data;

        }
    }

    cout << "This is the class average: " << total << endl;


}

void
choice_3()
{
    Grade_Analysis();
}

