#include <iostream>
#include "BST.h"
#include "Person.h"
#include <string>
#include <fstream>
using namespace std;


bool readData(BST<Person> &, BST<Person> &, fstream &); //reads in data into BSTs
void namesDemo(BST<Person> &, fstream &, string); //demo for names BST
void bDaysDemo(BST<Person> &, fstream &, string); //demo for bDay BST
void clarityLine(ostream &); //clarity line

int main()
{
    BST<Person> bstName;
    BST<Person> bstBday;

    fstream ioFile;

    string outFileNames = "NamesOutput.txt";
    string outFileBDays = "BirthdaysOutput.txt";

    if (readData(bstName, bstBday, ioFile)) //makes sure data was read in
    {
        namesDemo(bstName, ioFile, outFileNames);
        bDaysDemo(bstBday, ioFile, outFileBDays);
    }
    


    system("pause");
    return 0;
}


/* gives visual clarity
Pre: os - ostream object by reference
Post: os is modified
Return:
*/
void clarityLine(ostream &os)
{
    os << string(30, '=') << endl;
}


/* reads data in
Pre: bstName - BST by person
     bstBday - BST by bDay
     inFile - fstream objects
Post:
Return: bool - true if data read in, false otherwise
*/
bool readData(BST<Person> &bstName, BST<Person> &bstBday, fstream &inFile)
{
    string fileName;
    
    while (!inFile.is_open())
    {
        cout << "Enter 1 to exit early." << endl; //way to exit incase the program has an issue with paths, except that it does not
        cout << "Enter entire path of the input file including file name: " << endl;
        cin >> fileName;
        cin.ignore(100, '\n');

        if (fileName == "1") //early exiting of program if wanted by the user
        {
            return false;
        }

        inFile.open(fileName, ios::in); //opens for input

        if (!inFile.is_open()) //if failed to open
        {
            cout << "ERROR: inFile: " << fileName << " was not found." << endl;
        }
    }

    string name;
    string bday;

    while (getline(inFile, name) && getline(inFile, bday)) //reads in dynamically allocated Person objects into the BST
    {
        bstName.insert(*(new Person(name, bday, 1)));
        bstBday.insert(*(new Person(name, bday, 2)));
    }

    inFile.close(); //close file
    return true;
}



/* Demo for the names
Pre: bstName - bst with data of type Person
     outFile - fstream object by reference to maintain file's integrity over multiple functions
     fileName - string of filename to output to
Post:
Return:
*/
void namesDemo(BST<Person> &bstName, fstream &outFile, string fileName)
{
    outFile.open(fileName, ios::out); //open for output
    //headers
    clarityLine(cout);
    clarityLine(outFile);
    cout << "Names: PreOrder" << endl;
    outFile << "Names: PreOrder" << endl;
    clarityLine(cout);
    clarityLine(outFile);

    cout << bstName.choice(1); //preOrder
    outFile << bstName.choice(1); //preOrder

    clarityLine(cout);
    clarityLine(outFile);

    cout << endl;
    outFile << endl;

    clarityLine(cout);
    clarityLine(outFile);
    cout << "Names: PostOrder" << endl;
    outFile << "Names: PostOrder" << endl;
    clarityLine(cout);
    clarityLine(outFile);

    cout << bstName.choice(3); //postOrder
    outFile << bstName.choice(3); //postOrder

    clarityLine(cout);
    clarityLine(outFile);

    outFile.close(); //close file
}



/* demo for bDays bst
Pre: bstBday - BST of type Person with data
     outFIle - fstream by reference to maintain integrity of output file across multiple functions
     fileName - string of file to output to
Post:
Return:
*/
void bDaysDemo(BST<Person> &bstBday, fstream &outFile, string fileName)
{
    outFile.open(fileName, ios::out); //open for output

    cout << endl; //visual aid for console output. Not needed for output file

    //headers
    clarityLine(cout);
    clarityLine(outFile);
    cout << "Birthdays: InOrder" << endl;
    outFile << "Birthdays: InOrder" << endl;
    clarityLine(cout);
    clarityLine(outFile);

    cout << bstBday.choice(2); //preOrder
    outFile << bstBday.choice(2); //preOrder

    clarityLine(cout);
    clarityLine(outFile);

    cout << endl;
    outFile << endl;

    clarityLine(cout);
    clarityLine(outFile);
    cout << "Birthdays: Breadth-First" << endl;
    outFile << "Birthdays: Breadth-First" << endl;
    clarityLine(cout);
    clarityLine(outFile);

    cout << bstBday.choice(4); //postOrder
    outFile << bstBday.choice(4); //postOrder

    clarityLine(cout);
    clarityLine(outFile);

    outFile.close(); //close file
}
