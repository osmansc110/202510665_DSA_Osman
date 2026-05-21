#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// ========================= FUNCTIONS =========================

void line()
{
    cout << "\n==================================================\n";
}

void showMainMenu()
{
    line();
    cout << "        Foundations and History of C++\n";
    line();
    cout << "[1] History of C++\n";
    cout << "[2] Learn C++ Concepts\n";
    cout << "[3] Exit Program\n";
    cout << "Choose an option : ";
}

void historyMenu()
{
    line();
    cout << "              History of C++\n";
    line();
    cout << "[1] Origin of Programming Languages\n";
    cout << "[2] Development of C Language\n";
    cout << "[3] Birth of C++\n";
    cout << "[4] Evolution of Modern C++\n";
    cout << "[5] Return to Main Menu\n";
    cout << "Enter your choice : ";
}

void conceptsMenu()
{
    line();
    cout << "              Learn C++ Concepts\n";
    line();
    cout << "[1] Data Types\n";
    cout << "[2] Control Statements\n";
    cout << "[3] Loops\n";
    cout << "[4] Arrays\n";
    cout << "[5] File Streams\n";
    cout << "[6] Return to Main Menu\n";
    cout << "Enter your choice : ";
}

// ========================= HISTORY SECTION =========================

void showHistoryChapter(int choice)
{

    switch (choice)
    {

    case 1:
        line();
        cout << "Origin of Programming Languages\n";
        line();
        cout << "Early programming languages included FORTRAN,\n";
        cout << "ALGOL, and CPL. These languages influenced\n";
        cout << "many modern programming languages.\n";
        break;

    case 2:
        line();
        cout << "Development of C Language\n";
        line();
        cout << "BCPL inspired the B language, which later\n";
        cout << "led to the creation of the C programming\n";
        cout << "language by Dennis Ritchie.\n";
        break;

    case 3:
        line();
        cout << "Birth of C++\n";
        line();
        cout << "Bjarne Stroustrup created C with Classes\n";
        cout << "by combining C language features with\n";
        cout << "object-oriented ideas from Simula 67.\n";
        break;

    case 4:
        line();
        cout << "Evolution of Modern C++\n";
        line();
        cout << "C++ evolved into a powerful programming\n";
        cout << "language supporting OOP, STL, templates,\n";
        cout << "file handling, and modern software design.\n";
        break;

    case 5:
        cout << "Returning to Main Menu...\n";
        break;

    default:
        cout << "Invalid Choice!\n";
    }
}

// ========================= FILE READING FUNCTION =========================

void readFile(string fileName)
{

    ifstream file(fileName);

    if (file.is_open())
    {

        string line;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    else
    {
        cout << "Unable to open file : " << fileName << endl;
    }
}

// ========================= CONCEPTS SECTION =========================

void showConcept(int choice)
{

    switch (choice)
    {

    case 1:
        line();
        cout << "Data Types\n";
        line();
        cout << "Examples : int, float, double, char, bool.\n";
        break;

    case 2:
        line();
        cout << "Control Statements\n";
        line();
        cout << "C++ uses if, else, else-if, and switch.\n";
        break;

    case 3:
        line();
        cout << "Loops\n";
        line();
        cout << "Loops include for, while, and do-while.\n";
        break;

    case 4:
        line();
        cout << "Arrays\n";
        line();
        cout << "Arrays store multiple values of same type.\n";
        break;

    case 5:
        line();
        cout << "File Streams\n";
        line();

        // Reads from external file
        readFile("filestream.txt");

        break;

    case 6:
        cout << "Returning to Main Menu...\n";
        break;

    default:
        cout << "Invalid Choice!\n";
    }
}

// ========================= MAIN PROGRAM =========================

int main()
{

    int mainChoice;
    int subChoice;

    do
    {

        showMainMenu();
        cin >> mainChoice;

        if (cin.fail())
        {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "Please enter numbers only.\n";
            continue;
        }

        switch (mainChoice)
        {

        case 1:

            do
            {

                historyMenu();
                cin >> subChoice;

                showHistoryChapter(subChoice);

            } while (subChoice != 5);

            break;

        case 2:

            do
            {

                conceptsMenu();
                cin >> subChoice;

                showConcept(subChoice);

            } while (subChoice != 6);

            break;

        case 3:

            cout << "\nExiting Program...\n";
            cout << "Thank you for using the system.\n";

            break;

        default:

            cout << "Invalid Choice!\n";
        }

    } while (mainChoice != 3);

    return 0;
}