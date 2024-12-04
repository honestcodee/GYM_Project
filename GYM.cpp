#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
const int MAXMEMBERS = 100;
const int MAXTRAINER = 15;
//=====================================STRUCTS=========================================
struct members{
    string memberUsername;
    string memberPassword;
    string memberTrain;
    int memberPacakage;
    int membersfee;
    char feestatus;
};
struct trainers{
    string trainerUsername;
    string trainerPassword;
    string trainerTime;
    int trainerDues;
    int paidDues;
};
//====================================================================================
// prtotypes...
void gymName();
void menu();
void gymName();
void AdminDisplay();
void trainerDisplay();
void logindispaly();
void signupdispaly();
void enter();
void admin();
void trainer();
void member();
void memberlogin();
void membersignup();
void intializeData(members memarr[],trainers trainarr[]);
void initialize(string reqname[][2], int reqfee[], string techname[], string description[]);
void addmember(members memarr[],trainers trainarr[], int &mcount);
void update(members memarr[],trainers trainarr[]);
void deletee(members memarr[], int &mcount);
void analytics(int mcount,members memarr[],trainers trainarr[], int tcount);
void memberlist(members memarr[], int mcount);
void listtrainer(trainers trainarr[], int tcount);
void editrainer(trainers trainarr[], int &tcount);
void trainerfees();
void packages();
int validatereg(string n);
int discount(int f, int mcount);
int mailvalidate(string m);
void enroll(string reqname[][2], int reqfee[], int &reqcount, int mcount);
void requests(members memarr[], string reqname[][2], int reqfee[], int reqcount, int &mcount);
void availabletrain(trainers trainarr[], int tcount);
void traintech(string techname[], string description[], int &techcount);
void shedules(trainers trainarr[], int tcount);
void trainerrdue(trainers trainarr[], int logintrainer);
void memberrdue(members memarr[], int loginmember);
void changetrainer(members memarr[],trainers trainarr[], int loginmember);
bool loaduser(members memarr[]);
bool saveuser(members memarr[]);
bool loadtrainer(trainers trainarr[]);
bool savetrainer(trainers trainarr[]);
void feedbackk(string feedback[][4]);
void intifeedback(string feedback[][4]);
void viewfeedback(string feedback[][4]);
int strtoint(string n);
bool loadrequests(string reqname[][2],int reqfee[]);
bool saverequests(string reqname[][2], int reqfee[]);
void getPassword(string &password)
{
    char ch;
    while (true)
    {
        ch = _getch(); // get a character without echoing it to the console

        if (ch == 13)
        { // Enter key is pressed
            break;
        }
        else if (ch == 8)
        { // Backspace key is pressed
            if (password.length() > 0)
            {
                password = password.substr(0, password.length() - 1);
                cout << "\b \b"; // erase last character
            }
        }
        else
        {
            password += ch;
            cout << "*"; // display an asterisk for each character
        }
    }
    cout << endl; // Move to the next line after password input
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//--------------------------------------------------------------------------------------------------------------

int main()
{
    //========================Declaration of all the arrays===========
    string techname[10];
    string description[10];
    members memarr[MAXMEMBERS]; 
    trainers trainarr[MAXTRAINER];
    string memberMails[MAXMEMBERS];
    string reqname[10][2]; // 2D Array
    int reqfee[10];
    string feedback[10][4];
    //================================================================
    initialize( reqname, reqfee, techname, description);
    intializeData(memarr,trainarr);
    intifeedback(feedback);
    loaduser(memarr);
    loadtrainer(trainarr);
    loadrequests(reqname,reqfee);
    int input, option;
    int logintrainer = 0, loginmember = 0;
    int mcount = 0, tcount = 0, reqcount = 0, techcount = 0;
    string user, pwd;
    string trainuser = "", trainpwd = "";
    string memuser = "", mempwd = "";
    bool memberSearchFlag = false;
    bool trainerSearchFlag = false;
    int loggedInUserType = -10;
    do
    {
        system("cls");
        gymName();
        menu();
        cout << "\tChoose an option: ";
        cin >> input;
        while (input > 4 && input < 0 || !cin || cin.eof() || cin.fail())
        {
            cout << "\tChoose an option: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> input;
        }
        cout << endl;

        switch (input)
        {

        case 1:
            system("cls");
            gymName();
            enter();
            cout << "Enter the username for Admin: ";
            cin >> user;
            pwd="";
            cout << "Enter Password for Admin: ";
            getPassword(pwd);

            if (user == "1" && pwd == "1")
                loggedInUserType = 1;
            else
                loggedInUserType = -1;
            break;
        case 2:
            system("cls");
            gymName();
            enter();
            cout << "Enter the username for trainer: ";
            cin >> trainuser;
            trainpwd="";
            cout << "Enter Password for trainer: ";
            getPassword(trainpwd);
            for (int i = 0; i < MAXTRAINER; i++)
            {
                if (trainuser == trainarr[i].trainerUsername && trainpwd == trainarr[i].trainerPassword)
                {
                    logintrainer = i;
                    trainerSearchFlag = true;
                    break;
                }
            }

            if (trainerSearchFlag == true)
            {
                loggedInUserType = 2;
            }
            else
            {
                loggedInUserType = -1;
            }
            break;
        case 3:
            system("cls");
            gymName();
            enter();
            cout << "Enter the username for Member: ";
            cin >> memuser;

            cout << "Enter Password for Member: ";
            cin >> mempwd;
            for (int i = 0; i < MAXMEMBERS; i++)
            {
                if (memuser == memarr[i].memberUsername && mempwd == memarr[i].memberPassword)
                {
                    loginmember = i;
                    memberSearchFlag = true;
                    break;
                }
            }

            if (memberSearchFlag == true)
            {
                loggedInUserType = 3;
            }
            else
            {
                loggedInUserType = -1;
            }
            break;
        case 4:
            loggedInUserType = 4;
            break;
        case 0:
            loggedInUserType = -10;
            cout << "Thank you for using system..)" << endl;
            break;

        default:
            cout << "Invalid choice!!!";
            break;
        }
        if (loggedInUserType == 1) // admin
        {
            do
            {
                system("cls");
                gymName();
                admin();
                AdminDisplay();
                cout << "\tChoose an option: ";
                cin >> input;
                while (input > 8 && input < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tChoose an option: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> input;
                }
                switch (input)
                {
                case 1:
                    system("cls");
                    gymName();
                    admin();
                    addmember(memarr,trainarr, mcount);

                    break;
                case 2:
                    system("cls");
                    gymName();
                    admin();
                    update(memarr,trainarr);
                    break;
                case 3:
                    system("cls");
                    gymName();
                    admin();
                    deletee(memarr, mcount);
                    break;
                case 4:
                    system("cls");
                    gymName();
                    admin();
                    memberlist(memarr, mcount);
                    break;
                case 5:
                    system("cls");
                    gymName();
                    admin();
                    listtrainer(trainarr, tcount);
                    break;
                case 6:
                    system("cls");
                    gymName();
                    admin();
                    editrainer(trainarr, tcount);
                    break;
                case 7:
                    system("cls");
                    gymName();
                    admin();
                    analytics(mcount,memarr,trainarr, tcount);
                    break;
                case 8:
                    system("cls");
                    gymName();
                    admin();
                    requests(memarr, reqname, reqfee, reqcount, mcount);

                    break;
                case 9:
                    system("cls");
                    gymName();
                    admin();
                    viewfeedback(feedback);
                    break;
                case 0:
                    cout << "Administrator is logged out" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!";
                    break;
                }
            } while (input != 0);
            input = -1; 
        }
        else if (loggedInUserType == 2) // trainer
        {
            do
            {
                 system("cls");
                 gymName();
                 trainer();
                trainerDisplay();
                cout << "\tChoose an option: ";
                cin >> input;
                while (input > 3 && input < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tChoose an option: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> input;
                }
                switch (input)
                {
                case 1:
                    system("cls");
                    gymName();
                    trainer();
                    shedules(trainarr, tcount);
                    break;
                case 2:
                    system("cls");
                    gymName();
                    trainer();
                    traintech(techname, description, techcount);
                    break;
                case 3:
                    system("cls");
                    gymName();
                    trainer();
                    trainerrdue(trainarr, logintrainer);
                    break;
                case 0:
                    cout << "You are logged out" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!";
                    break;
                }

            } while (input != 0);
            input = -1; 
        }
        else if (loggedInUserType == 3) // userlogin
        {
            do
            {
                system("cls");
                gymName();
                member();
                memberlogin();
                logindispaly();
                cout << "\tChoose an option: ";
                cin >> input;
                while (input > 3 && input < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tChoose an option: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> input;
                }
                switch (input)
                {

                case 1:
                    system("cls");
                    gymName();
                    memberlogin();
                    memberrdue(memarr, loginmember);
                    break;
                case 2:
                    system("cls");
                    gymName();
                    memberlogin();
                    changetrainer(memarr,trainarr, loginmember);
                    break;
                case 3:
                    system("cls");
                    gymName();
                    memberlogin();
                    availabletrain(trainarr, tcount);
                    break;
                case 4:
                    system("cls");
                    gymName();
                    memberlogin();
                    feedbackk(feedback);
                    break;
                case 0:
                    cout << "You are logged out" << endl;
                    break;

                default:
                    cout << "Invalid choice!!!";
                    break;
                }

            } while (input != 0);
            input = -1; 
        }
        else if (loggedInUserType == 4) // signup
        {

            do
            {
                system("cls");
                gymName();
                member();
                membersignup();
                signupdispaly();
                cout << "\tChoose an option: ";
                cin >> input;
                while (input > 3 && input < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tChoose an option: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> input;
                }
                switch (input)
                {

                case 1:
                    system("cls");
                    gymName();
                    membersignup();
                    packages();
                    break;
                case 2:
                    system("cls");
                    gymName();
                    membersignup();
                    availabletrain(trainarr, tcount);
                    break;
                case 3:
                    system("cls");
                    gymName();
                    membersignup();
                    enroll(reqname, reqfee, reqcount, mcount);
                    break;
                case 0:

                    cout << "You are logged out" << endl;
                    break;
                default:
                    cout << "Invalid choice!!!";
                    break;
                }

            } while (input != 0);
            input = -1; 
        }
        else if (loggedInUserType == -1)
        {
            cout << "You have entered invalid Credentials!!!" << endl;
        }
    } while (input != 0);
    bool a = saveuser(memarr);
    if (a == true)
        cout << "The data of user is stored sucessfully...)" << endl;
    else
        cout << "We r sorry, the data is not stored..";
    bool b = savetrainer(trainarr);
    if (b == true)
        cout << "The data of trainer is stored sucessfully...)";
    bool c =saverequests(reqname,reqfee);
    if(c==true)
        cout<<"The data of requests is stored successfully..)";

    return 0;
}
void gymName()
{
    setColor(4);

    cout << " __  __     __         ______   ______     ______        ______     __  __     __    __    " << endl
         << "/\\ \\ /\\ \\   /\\ \\       /\\__  _\\ /\\  == \\   /\\  __ \\      /\\  ___\\   /\\ \\_\\ \\   /\\ \\-./  \\   " << endl
         << "\\ \\ \\\\_\\ \\  \\ \\ \\____  \\/_/\\ \\/ \\ \\  __<   \\ \\  __ \\     \\ \\ \\__ \\  \\ \\____ \\  \\ \\ \\-./\\ \\  " << endl
         << " \\ \\______\\  \\ \\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\     \\ \\_____\\  \\/______\\  \\ \\_\\ \\ \\_\\ " << endl
         << "  \\/______/   \\/_____/     \\/_/   \\/_/ /_/   \\/_/\\/_/      \\/_____/   \\/_____/   \\/_/  \\/_/ " << endl;

}
void menu()
{
    setColor(7);
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(30) << "1.login as Admin.." << setw(30) << "2.login as Trainer..           |" << endl
         << "              |   " << setw(30) << "3.login as Member.." << setw(30) << "4.Signup for new member.       |" << endl
         << "              |   " << setw(30) << "0. logout..                                                  |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void AdminDisplay()
{
    setColor(7);
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.Add a member.." << setw(25) << "2.Update a Member..                 |" << endl
         << "              |   " << setw(25) << "3.Delete a Member.." << setw(25) << "4.List all members..                |" << endl
         << "              |   " << setw(25) << "5.Veiw Trainers.." << setw(25) << "6.Edit a Trainer..                  |" << endl
         << "              |   " << setw(25) << "7.Veiw Analytics.." << setw(25) << "8.View pending Requests             |" << endl
         << "              |   " << setw(25) << "9.View feedbacks.. " << setw(25) << "0.Logout..                          |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void trainerDisplay()
{
    setColor(7);
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.View Schedules" << setw(25) << "2.Fitness Techniques..              |" << endl
         << "              |   " << setw(25) << "3.Dues Info.." << setw(25) << "0.Logout..                          |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void logindispaly()
{
    setColor(7);
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.Dues Info" << setw(25) << "2.Change your Trainer..             |" << endl
         << "              |   " << setw(25) << "3.View Shedules" << setw(25) << "4.Give feedback                     |" << endl
         << "              |   " << setw(25) << "0.Logout..                                                   |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void signupdispaly()
{
    setColor(7);
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.Current Packages" << setw(25) << "2.Availaible Trainers..             |" << endl
         << "              |   " << setw(25) << "3.Guidlines to Enroll.." << setw(25) << "0.Logout..                          |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void enter()
{
    setColor(7);
    // system("cls");
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                  Enter Credentials   (^_^)                                      | " << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}
void admin()
{
    // system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Admin (login)                               | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void trainer()
{
    // system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Trainer (login)                             |  " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void member()
{
    // system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Welcome to Member                           | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void memberlogin()
{
    // system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                    Member (login)                             | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void membersignup()
{
    // system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                    Member (Signup)                             | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void intializeData(members memarr[],trainers trainarr[]){
for (int i = 0; i < MAXMEMBERS; i++)
    {
        memarr[i].memberUsername = "nv";
        memarr[i].memberPassword= "nv";
        memarr[i].membersfee = 0;
        memarr[i].memberTrain = "nv";
        memarr[i].feestatus = 'n';
    }
for (int i = 0; i < MAXTRAINER; i++)
    {
        trainarr[i].trainerUsername = "nv";
        trainarr[i].trainerPassword = "nv";
        trainarr[i].trainerTime = "nv";
        trainarr[i].trainerDues= 0;
        trainarr[i].paidDues= 0;
    }
}

void initialize(string reqname[][2], int reqfee[], string techname[], string description[])
{
    
    
    for (int i = 0; i < 10; i++)
    {
        techname[i] = "nv";
        description[i] = "nv";
        reqfee[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            reqname[i][j] = "nv";
        }
    }
}
int feePack(int p)
{
    setColor(7);
    string refer;
    if (p == 1)
    {
        return 700;
    }
    else if (p == 2)
    {
        return 1000;
    }
    else if (p == 3)
    {
        return 2000;
    }
    else if (p == 4)
    {
        return 5000;
    }
    else if (p == 5)
    {
        cin.ignore();
        cout << "Please enter your referral (any company name etc.): ";
        getline(cin, refer);
        if (refer == "faizan bhai" || refer.find("coding") != string::npos || refer.find("beginer") != string::npos)
        {
            cout << "You availed an discount of 10 %" << endl;
            return 500;
        }
        else
        {
            cout<<"We are sorry,Your referral is not found..."<<endl;
            cout<<"So you can't avail a discount."<<endl;
            return 800;
        }
    }
}
void addmember(members memarr[], trainers trainarr[], int &mcount) {
    cout << "       ---------------------" << endl;
    cout << "            ADD A MEMBER    " << endl;
    cout << "       ---------------------" << endl;

    if (mcount >= MAXMEMBERS) {
        cout << "Sorry, the space is already full.." << endl;
        return;
    }

    string naam;
    bool flag = true;
    do {
        flag = true;
        cout << "Enter the member name that you want to add: ";
        cin.ignore();
        getline(cin, naam);

        for (int i = 0; i < naam.length(); i++)
                {
                    if (!((naam[i] >= 'A' && naam[i] <= 'Z') || (naam[i] >= 'a' && naam[i] <= 'z') || naam[i] == ' '))
                    {
                        flag = false;
                        cout << "Invalid input. Name should contain only alphabets and spaces.\n";
                        break;
                    }
                }
            } while (!flag);

    memarr[mcount].memberUsername = naam;

    cout << "Enter the ID for the same user: ";
    getline(cin, memarr[mcount].memberPassword);

    char ch;
    cout << "You want to see the packages (Y/N): ";
    cin >> ch;
    ch = toupper(ch);
    if (ch == 'Y') {
        packages();
    }

    int p;
    cout << "Enter the package for that member (1-5): ";
    cin >> p;
    while (p < 1 || p > 5 || cin.fail()) {
        cin.clear();
        cin.ignore(200, '\n');
        cout << "Invalid package, please enter again: ";
        cin >> p;
    }
    memarr[mcount].memberPacakage = p;

    int fee = feePack(p);
    cout << "The fee for that member is $" << fee << endl;
    memarr[mcount].membersfee = fee;

    cout << "Enter fee status (P for paid, U for unpaid): ";
    cin >> ch;
    ch = toupper(ch);
    while (ch != 'P' && ch != 'U') {
        cout << "Invalid input. Enter P for paid or U for unpaid: ";
        cin >> ch;
        ch = toupper(ch);
    }
    memarr[mcount].feestatus = ch;

    char ch1;
    cout << "Do you want to specify its trainer? (Y/N): ";
    cin >> ch1;
    ch1 = toupper(ch1);

    if (ch1 == 'Y') {
        string tname;
        bool found = false;
        cin.ignore();
        while (!found) {
            cout << "Enter its trainer name: ";
            getline(cin, tname);

            for (int i = 0; i < MAXTRAINER; i++) {
                if (tname == trainarr[i].trainerUsername) {
                    memarr[mcount].memberTrain = tname;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Trainer not found. Please try again.\n";
            }
        }
    } else {
        memarr[mcount].memberTrain = "None";
    }

    cout << "Member added successfully!" << endl;
    mcount++;
}
void update(members memarr[], trainers trainarr[]) {
    setColor(7); 
    string user, uppass, upuser, tname;
    int upfee;
    char upch;
    bool msearch = false;

    cout << "       ---------------------" << endl;
    cout << "          UPDATE A MEMBER   " << endl;
    cout << "       ---------------------" << endl;
    cout << "Enter the member name that you want to update: ";
    cin.ignore();
    getline(cin, user);

    for (int i = 0; i < MAXMEMBERS; i++) {
        if (memarr[i].memberUsername == user) {
            msearch = true;
            break;
        }
    }

    if (!msearch) {
        cout << "Member is not found" << endl;
    } else {
        cout << "Enter the updated name: ";
        getline(cin, upuser);

        cout << "Enter its password to update: ";
        getline(cin, uppass);

        cout << "Enter its fees to update: ";
        cin >> upfee;
        while (upfee < 0 || cin.fail()) {
            cin.clear();
            cin.ignore(200, '\n');
            cout << "Invalid input. Enter a valid fee amount: ";
            cin >> upfee;
        }

        cout << "Enter its fee status (P for paid and U for unpaid): ";
        cin.ignore();
        cin.get(upch);
        upch = toupper(upch);
        while (upch != 'P' && upch != 'U') {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Enter its fee status (P for paid and U for unpaid): ";
            cin.get(upch);
            upch = toupper(upch);
        }

        bool found = false;
        char tch;
        cout << "Do you want to update its trainer (Y/N): ";
        cin.ignore();
        cin.get(tch);
        tch = toupper(tch);
        while (tch != 'Y' && tch != 'N') {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Do you want to update its trainer (Y/N): ";
            cin.get(tch);
            tch = toupper(tch);
        }

        if (tch == 'Y') {
            while (!found) {
                cout << "Enter its updated trainer name: ";
                cin.ignore();
                getline(cin, tname);

                for (int i = 0; i < MAXTRAINER; i++) {
                    if (tname == trainarr[i].trainerUsername) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Trainer not found. Please try again." << endl;
                }
            }
        }

        for (int i = 0; i < MAXMEMBERS; i++) {
            if (memarr[i].memberUsername == user) {
                memarr[i].memberUsername = upuser;
                memarr[i].memberPassword = uppass;
                memarr[i].membersfee = upfee;
                memarr[i].feestatus = upch;
                if (tch == 'Y') {
                    memarr[i].memberTrain = tname;
                }
                cout << "Member is updated successfully!!!" << endl;
                break;
            }
        }
    }

    cout << endl << "                  Press any key to continue..";
    getch(); 
}
void deletee(members memarr[], int &mcount) {
    setColor(7); 
    string deluser, delpass;
    bool msearch = false;

    cout << "       ---------------------" << endl;
    cout << "          DELETE A MEMBER   " << endl;
    cout << "       ---------------------" << endl;
    cout << "Enter the member name that you want to delete: ";
    cin.ignore();
    getline(cin, deluser);

    for (int i = 0; i < MAXMEMBERS; i++) {
        if (memarr[i].memberUsername == deluser) {
            msearch = true;
            break;
        }
    }

    if (!msearch) {
        cout << "Member is not found" << endl;
    } else {
        cout << "Enter its password to delete it: ";
        getline(cin, delpass);

        for (int i = 0; i < MAXMEMBERS; i++) {
            if (memarr[i].memberUsername == deluser && memarr[i].memberPassword == delpass) {
                memarr[i].memberUsername = "nv";
                memarr[i].memberPassword = "nv";
                memarr[i].membersfee = 0;
                memarr[i].feestatus = 'n';
                memarr[i].memberTrain = "nv";
                cout << "Member is deleted successfully!!!" << endl;
                mcount--;
                break;
            }
        }
    }

    cout << endl << "                  Press any key to continue..";
    getch(); 
}

void memberlist(members memarr[], int mcount)
{
    setColor(7);
    // system("cls");
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    cout << "                             LIST OF ALL MEMBERS                              " << endl;
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    cout << "               " << left << setw(30) << "UserName" << setw(30) << "Password" << setw(30) << "Fees" << setw(30) << "Status" << endl;
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (memarr[i].memberUsername != "nv" && memarr[i].memberPassword != "nv" && memarr[i].membersfee != 0)
        {
            cout << "               " << left << setw(30) << memarr[i].memberUsername << setw(30) << memarr[i].memberPassword << setw(30) << memarr[i].membersfee << setw(30) << memarr[i].feestatus << endl;
        }
    }
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
bool timecheck(string tm)
{
    if (tm.find("pm") != string::npos && tm.find("-") != string::npos || tm.find("am") != string::npos)
    {
        return true;
    }
    return false;
}
void editrainer(trainers trainarr[], int &tcount) {
    setColor(7); 
    int n;
    cout << "       ---------------------" << endl;
    cout << "            EDIT A TRAINER    " << endl;
    cout << "       ---------------------" << endl;
    cout << endl
         << "              -------------------------------------------------------" << endl
         << left
         << "              |   " << setw(30) << "1.Add.." << setw(30) << "2.Delete..          |" << endl
         << "              |   " << setw(30) << "3.Update.." << "                    |" << endl
         << "              -------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue.." << endl;
    getch(); 
    cout << "\tEnter what you want to do: ";
    cin >> n;
    while ((n > 3 || n < 1) || !cin || cin.eof() || cin.fail()) {
        cout << "\tEnter what you want to do: ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }

    string time;
    if (n == 1) {
        cout << "       ---------------------" << endl;
        cout << "            ADD A TRAINER    " << endl;
        cout << "       ---------------------" << endl;
        string naam;
        int amt = 0, pamt = 0;

        while (tcount < MAXTRAINER) {
            if (trainarr[tcount].trainerUsername == "nv" && trainarr[tcount].trainerPassword == "nv" &&
                trainarr[tcount].trainerDues == 0 && trainarr[tcount].paidDues == 0) {
                bool flag = true;
                do {
                    flag = true;
                    cout << "Enter the trainer name that you want to add: ";
                    cin.ignore();
                    getline(cin, naam);

                    for (size_t i = 0; i < naam.length(); i++) {
                        if (!((naam[i] >= 'A' && naam[i] <= 'Z') || (naam[i] >= 'a' && naam[i] <= 'z') || naam[i] == ' ')) {
                            flag = false;
                            cout << "Invalid input. Name should contain only alphabets and spaces.\n";
                            break;
                        }
                    }
                } while (!flag);
                trainarr[tcount].trainerUsername = naam;

                cout << "Enter the ID for the same trainer: ";
                getline(cin, trainarr[tcount].trainerPassword);
                cout << "Enter the amount that will be paid to them monthly: ";
                cin >> amt;
                while (amt < 0 || !cin || cin.eof() || cin.fail()) {
                    cout << "Enter the amount that will be paid to them monthly: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> amt;
                }
                trainarr[tcount].trainerDues = amt;

                cout << "Enter the amount that is already paid to them: ";
                cin >> pamt;
                while (pamt < 0 || !cin || cin.eof() || cin.fail()) {
                    cout << "Enter the amount that is already paid to them: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> pamt;
                }
                trainarr[tcount].paidDues = pamt;

                cout << "Enter their working hours (e.g., 1pm-5pm): ";
                cin.ignore();
                getline(cin, time);
                while (!timecheck(time)) { 
                    cout << "Invalid hours. Please enter the hours again: ";
                    getline(cin, time);
                }
                trainarr[tcount].trainerTime = time;

                cout << "Trainer added successfully!!!" << endl;
                break;
            }
            tcount++;
        }

        if (tcount >= MAXTRAINER) {
            cout << "Sorry, the space is already full." << endl;
        }

        cout << endl << "                  Press any key to continue..";
        getch();
    } else if (n == 2) {
        string deltrain, delpas;
        bool tsearch = false;

        cout << "       ---------------------" << endl;
        cout << "            DELETE A TRAINER    " << endl;
        cout << "       ---------------------" << endl;
        cout << "Enter the trainer name that you want to delete: ";
        cin.ignore();
        getline(cin, deltrain);
        cout << "Enter their password to delete them: ";
        getline(cin, delpas);

        for (int i = 0; i < MAXTRAINER; i++) {
            if (trainarr[i].trainerUsername == deltrain && trainarr[i].trainerPassword == delpas) {
                trainarr[i].trainerUsername = "nv";
                trainarr[i].trainerPassword = "nv";
                trainarr[i].trainerDues = 0;
                trainarr[i].paidDues = 0;
                trainarr[i].trainerTime = "nv";

                cout << "Trainer deleted successfully!!!" << endl;
                tcount--;
                tsearch = true;
                break;
            }
        }

        if (!tsearch) {
            cout << "Trainer not found." << endl;
        }

        cout << endl << "                  Press any key to continue..";
        getch();
    } else if (n == 3) {
        cout << "       ---------------------" << endl;
        cout << "          UPDATE A TRAINER   " << endl;
        cout << "       ---------------------" << endl;
        string train, uppas, uptrain, uptime;
        int updue, uppaid;
        bool tsearch = false;

        cout << "Enter the trainer name that you want to update: ";
        cin.ignore();
        getline(cin, train);

        cout << "Enter the updated name: ";
        getline(cin, uptrain);
        cout << "Enter their updated password: ";
        getline(cin, uppas);

        cout << "Enter their monthly dues: ";
        cin >> updue;
        while (updue < 0 || !cin || cin.eof() || cin.fail()) {
            cout << "Enter their monthly dues: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> updue;
        }

        cout << "Enter the amount that is already paid to them: ";
        cin >> uppaid;
        while (uppaid < 0 || !cin || cin.eof() || cin.fail()) {
            cout << "Enter the amount that is already paid to them: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> uppaid;
        }

        cout << "Enter their working hours: ";
        cin.ignore();
        getline(cin, uptime);
        while (!timecheck(uptime)) {
            cout << "Invalid hours. Please enter the hours again: ";
            getline(cin, uptime);
        }

        for (int i = 0; i < MAXTRAINER; i++) {
            if (trainarr[i].trainerUsername == train) {
                trainarr[i].trainerUsername = uptrain;
                trainarr[i].trainerPassword = uppas;
                trainarr[i].trainerDues = updue;
                trainarr[i].paidDues = uppaid;
                trainarr[i].trainerTime = uptime;

                cout << "Trainer updated successfully!!!" << endl;
                tsearch = true;
                break;
            }
        }

        if (!tsearch) {
            cout << "Trainer not found." << endl;
        }

        cout << endl << "                  Press any key to continue..";
        getch();
    } else {
        cout << "Invalid input." << endl;
        cout << endl << "                  Press any key to continue..";
        getch();
    }
}
void listtrainer(trainers trainarr[], int tcount)
{
    setColor(7);
    cout << "    ---------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                     LIST OF ALL TRAINERS                                     " << endl;
    cout << "    ---------------------------------------------------------------------------------------------------------" << endl;
    cout << "    " << left << setw(20) << "UserName"
         << setw(20) << "Password(ID)"
         << setw(20) << "Dues"
         << setw(20) << "Timings"
         << endl;
    cout << "    ---------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < MAXTRAINER; i++)
    {
        if (trainarr[i].trainerUsername!= "nv" && trainarr[i].trainerPassword!= "nv" && trainarr[i].trainerTime != "nv" && trainarr[i].trainerDues != 0)
        {
            cout << "    " << left << setw(20) << trainarr[i].trainerUsername
                 << setw(20) << trainarr[i].trainerPassword
                 << setw(20) << trainarr[i].trainerDues
                 << setw(20) << trainarr[i].trainerTime
                 << endl;
        }
    }

    cout << "    ---------------------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void trainerfees()
{
    // system("cls");
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "                                    Dues Info                                       " << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
}
void analytics(int mcount,members memarr[],trainers trainarr[], int tcount)
{
    setColor(7);
    // system("cls");
    int sum = 0, tsum = 0, trainsum = 0;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "                                View Analytics                                               " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "                                    Member                                             " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (memarr[i].feestatus == 'P' || memarr[i].feestatus == 'U')
        {
            tsum += memarr[i].membersfee;
        }
    }
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (memarr[i].feestatus == 'P')
        {
            sum += memarr[i].membersfee;
        }
    }

    for (int j = 0; j <= MAXTRAINER; j++)
    {
        if (trainarr[j].trainerDues != 0)
        {
            trainsum = trainsum + trainarr[j].trainerDues;
        }
    }

    int rem = tsum - sum;
    cout << "--------------------------------------------------------" << endl;
    cout << "| Total members fee for the GYM is: " << setw(10) << tsum << "          |" << endl;
    cout << "| Total paid members fee for the gym: " << setw(10) << sum << "        |" << endl;
    cout << "| The remaining fee for members: " << setw(10) << rem << "             |" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl
         << "---------------------------------------------------" << endl;
    cout << "                     Trainer                            " << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "The fees of all trainers is: " << trainsum << endl;
    int remain = tsum - trainsum;
    if (remain < 0)
    {
        remain = 0;
    }
    cout << "Remaining Amount after paying to the trainer: " << remain;
    system("color 01");
    cout << endl
         << "                  Press any key to continue..";
    getch();
    setColor(7);
}
void packages()
{
    system("color 01");
    cout << "---------------------------------------------------------" << endl;
    cout << "|                 1) Basic Package                      |" << endl;
    cout << "|Access: Limited to off-peak hours (e.g., 9 AM - 3 PM). |" << endl;
    cout << "|Features: Gym access, basic equipment usage.           |" << endl;
    cout << "|Duration: Monthly, Quarterly, Annually.                |" << endl;
    cout << "|Dues:  700 per month                                   |" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "|                   2) Standard Package                          |" << endl;
    cout << "|Access: Full-day access.                                        |" << endl;
    cout << "|Features: Gym access, group fitness classes (yoga, aerobics).   |" << endl;
    cout << "|Duration: Monthly, Quarterly, Annually                          |" << endl;
    cout << "|Dues: 1000 per month                                            |" << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------------" << endl;
    cout << "|                               3) Premium Package                                        |" << endl;
    cout << "|Access: Full-day access with priority bookings                                           |" << endl;
    cout << "|Features: Gym access, group classes, personal trainer sessions (e.g., 2 sessions/month). |" << endl;
    cout << "|Extras: Access to sauna or pool, if available.                                           |" << endl;
    cout << "|Duration: Monthly, Quarterly, Annually.                                                  |" << endl;
    cout << "|Dues:  2000 per month                                                                    |" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|                   4) Family Package                                      |" << endl;
    cout << "|Access: For up to 4 family members                                        |" << endl;
    cout << "|Features: Includes group classes for all members and a shared personal    |" << endl;
    cout << "|trainer session (once per month).                                         |" << endl;
    cout << "|Duration: Monthly, Quarterly, Annually                                    |" << endl;
    cout << "|Dues: 5000 per month                                                      |" << endl;
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------------" << endl;
    cout << "|                   5) Corporate Package                                               |" << endl;
    cout << "|Access: For employees of registered companies.                                        |" << endl;
    cout << "|Features: Discounted rates for group sign-ups (5+ members).                           |" << endl;
    cout << "|Duration: Quarterly, Annually.                                                        |" << endl;
    cout << "|Dues:  Depends on refers                                                              |" << endl;
    cout << "|---------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
int validatereg(string n)
{
    bool flag = true;
    if (n[4] == '-' && n[5] == 'C' && n[6] == 'S' && n[7] == '-')
    {
        for (int i = 0; i < 4; i++)
        {
            if (n[i] < '0' || n[i] > '9')
                return -1;
        }
        for (int i = 8; i < 11; i++)
        {
            if (n[i] < '0' && n[i] > '9')
                return -1;
        }
        return 1;
    }
    return -1;
}
int discount(int f, int mcount)
{
    setColor(7);
    int n, dis = 0;
    char ch, ch1;
    string name, reg, refer;
    // system("cls");
    Sleep(1000);
    cout << "----------------------------------------------------------------" << endl;
    cout << "                    Discount  Offers                            " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "  1) Student Discount            2) Off-Peak Discount           " << endl;
    cout << "  3) Referral Discount           4) Early-Bird Discount         " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Enter what do you want: ";
    cin >> n;

    while (n < 1 || n > 4 || !cin || cin.eof() || cin.fail())
    {
        cout << "Invalid input. Please enter a valid option (1-4): ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }

    if (n == 1)
    {
        cout << "Are you a student of undergrad (Y/N): ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            cout << "Enter your university name: ";
            cin.ignore();
            getline(cin, name);

            if (name.find("UET lahore") != string::npos || name.find("FAST") != string::npos)
            {
                cout << "Enter your Registration Number: ";
                cin >> reg;

                int r = validatereg(reg);
                while (r != 1)
                {
                    cout << "Your Registration Number is not correct, please enter again: ";
                    cin >> reg;
                    r = validatereg(reg);
                }

                if (r == 1)
                {
                    cout<<"Please wait a moment...."<<endl;
                    Sleep(1500);
                    dis = 20;
                    cout<<"--------------------------------------------------------------------"<<endl;
                    cout << "You availed a discount of " << dis << "%!" << endl;
                    cout<<"--------------------------------------------------------------------"<<endl;
                    return (f - (f * (dis / 100.0)));
                }
            }
            else
            {
                cout << "Sorry, your university is not eligible for the discount." << endl;
            }
        }
        else
        {
            cout << "You are not eligible for the student discount." << endl;
        }
    }
    else if (n == 2)
    {
        cout << "Do you want to access the gym during off-peak hours (Y/N): ";
        cin >> ch1;

        if (ch1 == 'Y' || ch1 == 'y')
        {
            char chh;
            cout << "You wnat to access the gym only from 9 AM to 11 AM(Y/N):" << endl;
            cin>>chh;
            if(chh=='Y' || chh=='y'){
            cout<<"Please wait a moment...."<<endl;
            Sleep(1700);
            dis = 15;
            cout<<"--------------------------------------------------------------------"<<endl;
            cout << "You availed a discount of " << dis << "%!" << endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            return (f - (f * (dis / 100.0)));
            }
        }
        else
        {
            cout << "You chose not to access the off-peak discount." << endl;
        }
    }
    else if (n == 3)
    {
        cout << "Do you want to access the referral discount (Y/N): ";
        cin >> ch1;

        if (ch1 == 'Y' || ch1 == 'y')
        {
            cout << "Please enter your referral (e.g., any company name): ";
            cin.ignore();
            getline(cin, refer);

            if (refer == "Faizan bhai" || refer.find("coding") != string::npos || refer.find("beginer") != string::npos)
            {
                dis = 20;
                cout<<"Please wait a moment...."<<endl;
                Sleep(1500);
                cout<<"--------------------------------------------------------------------"<<endl;
                cout << "You availed a discount of " << dis << "%!" << endl;
                cout<<"--------------------------------------------------------------------"<<endl;
                return (f - (f * (dis / 100.0)));
            }
            else
            {
                cout << "Sorry, your referral is not eligible for the discount." << endl;
            }
        }
        else
        {
            cout << "You chose not to avail the referral discount." << endl;
        }
    }
    else if (n == 4)
    {
        cout << "Early bird discount is only available for the first 5 members." << endl;
        cout << "Let us see if you are eligible or not..." << endl;
        cout<<"Please wait a moment...."<<endl;
        Sleep(1500);

        if (mcount < 5)
        {
            dis = 10;
            cout<<endl<<"-------------------------------------------------------------------"<<endl;
            cout << "Congratulations! You got an Early Bird Discount of " << dis << "%!" << endl;
            cout<<"--------------------------------------------------------------------"<<endl;
            return (f - (f * (dis / 100.0)));
        }
        else
        {
            cout << "Sorry, the Early Bird Discount is no longer available." << endl;
        }
    }

    cout << "No discount was applied. The fee remains unchanged." << endl;
    return f;
}

int mailvalidate(string m)
{
    int atpos = m.find("@");
    int dotpos = m.find(".", atpos);
    int pos = m.find("gmail");
    if (atpos != string::npos && dotpos != string::npos && pos != string::npos && atpos < dotpos)
    {
        return 1;
    }
    else
        return -1;
}
void enroll(string reqname[][2], int reqfee[], int &reqcount, int mcount)
{
    setColor(7);
    // system("cls");
    string name, mail;
    int pack, fee;
    char ch, ch1, ch2;
    cout << "-------------------------------------------------------------------------------------" << endl;
    cout << "                          Welcome to the Registration process                        " << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;

    cout << endl
         << "Please enter your full name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Please enter your correct email address: ";
    cin >> mail;
    int a = mailvalidate(mail);
    while (a != 1)
    {
        cin.ignore(100, '\n');
        cout << "your eamil is not correct,please enter again: ";
        cin >> mail;
        a = mailvalidate(mail);
    }
    cout << "You want to see the pacakages (Y/N): ";
    cin.ignore();
    cin.get(ch);
    if (ch == 'Y' || ch == 'y')
    {
        packages();
    }
    else if (ch != 'N' && ch != 'n')
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "You enter wrong character, please enter again: ";
        cin.get(ch);
    }
    cout << endl
         << "Please select your package: ";
    cin >> pack;
    while (pack > 5 || pack < 1 || !cin || cin.eof() || cin.fail())
    {
        cout << "Invaild pacakage, please enter again.. ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> pack;
    }
    if (pack >= 1 && pack <= 5)
    {
        fee = feePack(pack);
        cout << "your dues is " << fee << " montly" << endl;
        if (pack != 5)
        {
            cout << "Do you want to avail any discount offers: (Y/N) ";
            cin.ignore();
            cin >> ch1;
            if (ch1 == 'Y' || ch1 == 'y')
            {
                fee = discount(fee, mcount);
                cout << "your fee after discount is: " << fee << endl;
            }
            else if (ch1 != 'N' && ch1 != 'n')
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid operator";
            }
        }
    }
    else
    {
        cout << "You can avail a discount because your pacakage is already corporative.." << endl;
    }
    cout << "Now to want to submit your request to the admin(Y/N) : ";
    cin >> ch2;
    if (ch2 == 'Y' || ch2 == 'y')
    {
        for (int i = 0; i < 10; i++)
        {
            if (reqname[i][0] == "nv" && reqname[i][1] == "nv" && reqfee[i] == 0)
            {
                reqname[i][0] = name;
                reqname[i][1] = mail;
                reqfee[i] = fee;
                cout << "Please wait a minute.." << endl;
                Sleep(1500);
                cout << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "|       Your request is submitted to the admin.Pleasewait for your approwal.       |" << endl;
                cout << "|       you will get your Username and password(ID) soon (^_^)                     |" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                // reqcount++;
                
                break;
            }
            else if (reqcount >= 10)
            {
                cout << "Too many pending requests, please wait" << endl;
            }
        }
    }
    else if (ch2 == 'N' || ch2 == 'n')
    {
        cout << "As you wish..." << endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void requests(members memarr[], string reqname[][2], int reqfee[], int reqcount, int &mcount)
{
    setColor(7);
    int n;
    char ch;
    // system("cls");
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "                                      View Pending Requests                            " << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << " No.           " << left << setw(30) << "Names" << setw(30) << "Emails" << setw(30) << "Fees" << endl;
    cout << "-------------------------------------------------------------------------------------" << endl;

    for (int j = 0; j < 10; j++) {
        if (reqname[j][0] != "nv" && reqname[j][1] != "nv" && reqfee[j] != 0) {
            cout << j + 1 << "               " << left << setw(30) << reqname[j][0] << setw(30) << reqname[j][1] << setw(30) << reqfee[j] << endl;
        }
    }
    cout << "-------------------------------------------------------------------------------------" << endl;

    cout << endl << "Select the request you want to accept: ";
    cin >> n;

    while (n < 1 || n > 10 || cin.fail() || reqname[n - 1][0] == "nv") {
        cout << "Invalid selection. Try again: ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }

    do {
        cout << "Enter its fee status (P for Paid, U for Unpaid): ";
        cin >> ch;
        ch = toupper(ch);
    } while (ch != 'P' && ch != 'U');

    for (int i = 0; i < MAXMEMBERS; i++) {
        if (memarr[i].memberUsername == "nv" && memarr[i].memberPassword == "nv" && memarr[i].membersfee== 0) {
            memarr[i].memberUsername = reqname[n - 1][0];
            memarr[i].memberPassword = reqname[n - 1][0] + "123";
            memarr[i].membersfee = reqfee[n - 1];
            memarr[i].feestatus = ch;
            mcount++;
            cout << "Member added successfully!" << endl;
            cout << endl
                 << "                  Press any key to continue..";
            getch();
            reqname[n - 1][0] = "nv";
            reqname[n - 1][1] = "nv";
            reqfee[n - 1] = 0;
            return; 
        }
    }

    cout << "Sorry, the space is already full.." << endl;

    cout << endl << "Press any key to continue..";
    getch();
}
void availabletrain(trainers trainarr[], int tcount)
{
    setColor(7);
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                               Available Trainers                                            " << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                    Names                                    Availability        " << endl;
    for (int i = 0; i <= MAXTRAINER; i++)
    {
        if (trainarr[i].trainerUsername  != "nv" && trainarr[i].trainerTime != "nv")
        {
            cout << "                   " << setw(30) << trainarr[i].trainerUsername << "            " << setw(30) << trainarr[i].trainerTime << endl;
        }
    }
        cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void traintech(string techname[], string description[], int &techcount)
{
    setColor(7);
    int n;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                      Fitness Techniques                        " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "       1. Add             2. Update             3. Delete       " << endl;
    cout << "                      4. List all techniques                    " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "Enter your choice: ";
    cin >> n;
    while (n > 4 && n < 1 || !cin || cin.eof() || cin.fail())
    {
        cout << "Enter your choice: ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }

    cin.ignore();

    if (n == 1)
    {
        cout << "ADD A TECHNIQUE>>" << endl;
        if (techcount >= 10)
        {
            cout << "Maximum limit of techniques reached." << endl;
        }
        else
        {
            cout << "Enter the name of the technique: ";
            getline(cin, techname[techcount]);
            cout << "Enter its description: ";
            getline(cin, description[techcount]);
            techcount++;
            cout << "Technique added successfully!" << endl;
        }
    }
    else if (n == 2)
    {
        string name;
        cout << "UPDATE A TECHNIQUE>>" << endl;
        cout << "Enter the name of the technique to update: ";
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < techcount; i++)
        {
            if (name == techname[i])
            {
                cout << "Enter the updated name: ";
                getline(cin, techname[i]);
                cout << "Enter the updated description: ";
                getline(cin, description[i]);
                cout << "Technique updated successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Technique not found." << endl;
        }
    }
    else if (n == 3)
    {
        string name;
        cout << "DELETE A TECHNIQUE>>" << endl;
        cout << "Enter the name of the technique to delete: ";
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < techcount; i++)
        {
            if (name == techname[i])
            {
                techname[i] = "nv";
                description[i] = "nv";
                cout << "Technique deleted successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Technique not found." << endl;
        }
    }
    else if (n == 4)
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "                     List of All Techniques                 " << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << setw(15) << "Technique" << setw(60) << "Description" << endl;
        cout << "------------------------------------------------------------" << endl;
        if(techcount==0){
            cout<<"No techniques are currently added by the trainer."<<endl;
        }
        for (int i = 0; i < techcount; i++)
        {
            if (techname[i] != "nv" && description[i] != "nv")
            {
                cout << setw(15) << techname[i] << setw(60) << description[i] << endl;
            }
        }
        cout << "------------------------------------------------------------" << endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void shedules(trainers trainarr[], int tcount)
{
    setColor(7);
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                               Your shedules                                              " << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                    Names                                    Availability        " << endl;
    for (int i = 0; i <= MAXTRAINER; i++)
    {
        if (trainarr[i].trainerUsername != "nv" && trainarr[i].trainerPassword != "nv" && trainarr[i].trainerTime != "nv" && trainarr[i].trainerDues != 0)
        {
            cout << "                    " << setw(30) << trainarr[i].trainerUsername << "              " << setw(30) << trainarr[i].trainerTime << endl;
        }
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void trainerrdue(trainers trainarr[], int logintrainer)
{
    setColor(7);
    cout << "-------------------------------------" << endl;
    cout << "Your dues for this month is " << trainarr[logintrainer].trainerDues << endl;
    cout << "-------------------------------------" << endl;
    cout << "Amount that is already paid to you: " << trainarr[logintrainer].paidDues << endl;
    cout << "-------------------------------------" << endl;
    cout << "Remaining amount: " << trainarr[logintrainer].trainerDues - trainarr[logintrainer].paidDues<< endl;
    cout << "-------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void memberrdue(members memarr[], int loginmember)
{
    setColor(7);
    cout << "-------------------------------------" << endl;
    cout << "Your fee for this month is " << memarr[loginmember].membersfee << endl;
    cout << "-------------------------------------" << endl;
    cout << "The status of your fee for this month: " << memarr[loginmember].feestatus << endl;
    cout << "-------------------------------------" << endl;
    if (memarr[loginmember].feestatus == 'P')
    {
        cout << "No fee remaining.." << endl;
        cout << "-------------------------------------" << endl;
    }
    else
    {
        cout << "Remaining amount: " << memarr[loginmember].membersfee << endl;
        cout << "-------------------------------------" << endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void changetrainer(members memarr[],trainers trainarr[], int loginmember)
{
    setColor(7);
    cout << "------------------------------------------------" << endl;
    cout << "Your current trainer is: " << memarr[loginmember].memberTrain << endl;
    cout << "------------------------------------------------" << endl;
    char ch;
    string name;
    do
    {
        cout << "Do you want to change your trainer (Y/N): ";
        cin >> ch;
        ch = toupper(ch);
        if (ch != 'Y' && ch != 'N')
        {
            cout << "Invalid input! Please enter 'Y' or 'N'.\n";
        }
    } while (ch != 'Y' && ch != 'N');
    if (ch == 'Y')
    {
        cout << "Enter the name of your new trainer: ";
        getline(cin, name);
        bool found = false;
        if (ch == 'Y')
        {
            cin.ignore();
            while (!found)
            {
                for (int i = 0; i < MAXTRAINER; i++)
                {
                    if (name == trainarr[i].trainerUsername)
                    {
                        memarr[loginmember].memberTrain = name;
                        found = true;
                        cout << "Now your trainer is changed...." << endl;
                        break;
                    }
                }
                if (!found)
                {
                    cout << "trainer is not found";
                }
            }
        }
    }
    else{
        cout<<"As you wish......."<<endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
bool loaduser(members memarr[])
{
    int j = 0;
    ifstream fin;
    fin.open("user.csv");
    if (!fin)
    {
        return false;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, memarr[j].memberUsername, ',');
            getline(fin, memarr[j].memberPassword, ',');
            fin >> memarr[j].membersfee;
            fin.ignore();
            fin.get(memarr[j].feestatus);
            fin.ignore();
            j++;
        }

        fin.close();
        return true;
    }
}
bool saveuser(members memarr[])
{
    ofstream fout;
    fout.open("user.csv");
    if (!fout)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < MAXMEMBERS; i++)
        {
            if (memarr[i].memberUsername != "nv" && memarr[i].memberPassword != "nv")
            {
                fout << memarr[i].memberUsername << "," << memarr[i].memberPassword << "," << memarr[i].membersfee << "," << memarr[i].feestatus << endl;
            }
        }
        fout.close();
        return true;
    }
}
bool loadtrainer(trainers trainarr[])
{
    int j = 0;
    ifstream fin;
    fin.open("trainer.csv");
    if (!fin)
    {
        return false;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, trainarr[j].trainerUsername, ',');
            getline(fin, trainarr[j].trainerPassword, ',');
            getline(fin, trainarr[j].trainerTime, ',');
            fin >> trainarr[j].trainerDues;
            fin.ignore();
            j++;
        }
        fin.close();
        return true;
    }
}
bool savetrainer(trainers trainarr[])
{
    ofstream fout;
    fout.open("trainer.csv");
    if (!fout)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < MAXTRAINER; i++)
        {
            if (trainarr[i].trainerUsername != "nv" && trainarr[i].trainerPassword != "nv" && trainarr[i].trainerTime != "nv" && trainarr[i].trainerDues != 0)
            {
                fout << trainarr[i].trainerUsername << "," << trainarr[i].trainerPassword << "," << trainarr[i].trainerTime << "," << trainarr[i].trainerDues << endl;
            }
        }
        fout.close();
        return true;
    }
}
void intifeedback(string feedback[][4])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            feedback[i][j] = "nv";
        }
    }
}
void feedbackk(string feedback[][4])
{
    setColor(7);
    // system("cls");
    cout << "---------------------------------------------------------" << endl;
    cout << "             WELCOME TO THE FEEDBACK MENU                " << endl;
    cout << "---------------------------------------------------------" << endl;
    string mail, rate;
    for (int i = 0; i < 10; i++)
    {
        if (feedback[i][0] == "nv")
        {
            cout << "Please enter your name: ";
            cin.ignore();
            getline(cin, feedback[i][0]);
            cout << "please enter your email mail:";
            cin >> mail;
            while (mailvalidate(mail) != 1)
            {
                cout << "You entered wrong email.Please correct it:";
                cin >> mail;
            }
            feedback[i][1] = mail;
            cout << "Please write the description: ";
            cin.ignore();
            getline(cin, feedback[i][3]);
            cout << "Now give Rating to our app(0-10):";
            cin >> rate;
            int r = strtoint(rate);
            while (r > 10 || r < 0)
            {
                cout << "please enter correct rating..";
                cin >> rate;
                r = strtoint(rate);
            }
            feedback[i][2] = rate;
            char ch;
            cout << "Are you sure you want to submit the feedback to the admin(Y/N):";
            cin.ignore();
            cin.get(ch);
            if (ch == 'Y' || ch == 'y')
            {
                cout << endl
                     << "-----------------------------------------------" << endl;
                cout << "|   Your responce is submitted, Thank you(^_^) |" << endl;
                cout << "-----------------------------------------------" << endl;
            }
            else if (ch == 'N' || ch == 'n')
            {
                for (int j = 0; j < 4; j++)
                {
                    feedback[i][j] = "nv";
                }
                cout << "Your respone is not submitted to the admin.." << endl;
            }
            break;
        }
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void viewfeedback(string feedback[][4])
{
    setColor(7);
    cout << "-------------------------------------------------------------------" << endl;
    cout << "                            LIST OF ALL FEEDBACKS                  " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Names                      Emails                      Ratings        " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (feedback[i][0] != "nv")
        {
            cout << i + 1 << "." << feedback[i][0] << "                   " << feedback[i][1] << "            " << feedback[i][2] << endl;
            cout << "Description: " << feedback[i][3] << endl;
        }
    }
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
int strtoint(string n)
{
    int a = 0;
    for (char ch : n)
    {
        a = a * 10 + (ch - '0');
    }
    return a;
}
bool loadrequests(string reqname[][2],int reqfee[])
{
    int j = 0;
    ifstream fin;
    fin.open("requests.csv");
    if (!fin)
    {
        return false;
    }
    else
    {
        while (!fin.eof())
        {
            getline(fin, reqname[j][0], ',');
            getline(fin, reqname[j][1], ',');
            fin >> reqfee[j];
            fin.ignore();
            j++;
        }
        fin.close();
        return true;
    }
}
bool saverequests(string reqname[][2], int reqfee[])
{
    ofstream fout;
    fout.open("requests.csv");
    if (!fout)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 10; i++)
        {
            if (reqname[i][0] != "nv" && reqname[i][1] != "nv" && reqfee[i] != 0)
            {
                fout << reqname[i][0] << "," << reqname[i][1] << "," << reqfee[i] << endl;
            }
        }
        fout.close();
        return true;
    }
}