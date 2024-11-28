#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;
const int MAXMEMBERS = 100;
const int MAXTRAINER = 15;
//-------------------------------------------------------------------
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
void initialize(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], string reqname[][2], int reqfee[], string techname[], string description[], int paiddues[], string membertrain[]);
void addmember(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string trainerUsername[], string membertrain[], int &mcount);
void update(string memberUsername[], string memberPassword[], int membersfee[], string membertrain[], string trainerUsername[], char feestatus[]);
void deletee(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string membertrain[], int &mcount);
void analytics(int mcount, char feestatus[], int membersfee[], int trainerdues[], int tcount);
void memberlist(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], int mcount);
void listtrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], int tcount);
void editrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], int paiddues[], int &tcount);
void trainerfees();
void packages();
int validatereg(string n);
int discount(int f, int mcount);
int mailvalidate(string m);
void enroll(string reqname[][2], int reqfee[], int &reqcount, int mcount);
void requests(string memberUsername[], string memberPassword[], int membersfee[], string reqname[][2], int reqfee[], int reqcount, int &mcount, char feestatus[]);
void availabletrain(string trainerUsername[], string trainertime[], int tcount);
void traintech(string techname[], string description[], int &techcount);
void shedules(string trainerUsername[], string trainerPassword[], int trainerdues[], string trainertime[], int tcount);
void trainerrdue(int trainerdues[], int paiddues[], int logintrainer);
void memberrdue(int membersfee[], char feestatus[], int loginmember);
void changetrainer(string membertrain[], string trainerUsername[], int loginmember);
bool loaduser(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[]);
bool saveuser(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[]);
bool loadtrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[]);
bool savetrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[]);
void feedbackk(string feedback[][4]);
void intifeedback(string feedback[][4]);
void viewfeedback(string feedback[][4]);
int strtoint(string n);
bool loadrequests(string reqname[][2],int reqfee[]);
bool saverequests(string reqname[][2], int reqfee[]);
//--------------------------------------------------------------------------------------------------------------

int main()
{
    // Declaration of all the arrays..
    string techname[10];
    string description[10];
    string memberUsername[MAXMEMBERS];
    int memberPackages[MAXMEMBERS];
    string memberPassword[MAXMEMBERS];
    string membertrain[MAXMEMBERS];
    char feestatus[MAXMEMBERS];
    string memberMails[MAXMEMBERS];
    int membersfee[MAXMEMBERS];
    string reqname[10][2]; // 2D Array
    int reqfee[10];
    string feedback[10][4];
    string trainerUsername[MAXTRAINER];
    string trainerPassword[MAXTRAINER];
    string trainertime[MAXTRAINER];
    int trainerdues[MAXTRAINER];
    int paiddues[MAXTRAINER];
    initialize(memberUsername, memberPassword, membersfee, feestatus, trainerUsername, trainerPassword, trainertime, trainerdues, reqname, reqfee, techname, description, paiddues, membertrain);
    intifeedback(feedback);
    loaduser(memberUsername, memberPassword, membersfee, feestatus);
    loadtrainer(trainerUsername, trainerPassword, trainertime, trainerdues);
    loadrequests(reqname,reqfee);
    int input, option;
    int logintrainer = 0, loginmember = 0;
    int mcount = 0, tcount = 0, reqcount = 0, techcount = 0;
    string user, pwd;
    string trainuser = "nv", trainpwd = "nv";
    string memuser = "nv", mempwd = "nv";
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
            enter();
            cout << "Enter the username for Admin: ";
            cin >> user;

            cout << "Enter Password for Admin: ";
            cin >> pwd;

            if (user == "1" && pwd == "1")
                loggedInUserType = 1;
            else
                loggedInUserType = -1;
            break;
        case 2:
            enter();
            cout << "Enter the username for trainer: ";
            cin >> trainuser;

            cout << "Enter Password for trainer: ";
            cin >> trainpwd;
            for (int i = 0; i < MAXTRAINER; i++)
            {
                if (trainuser == trainerUsername[i] && trainpwd == trainerPassword[i])
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
            enter();
            cout << "Enter the username for Member: ";
            cin >> memuser;

            cout << "Enter Password for Member: ";
            cin >> mempwd;
            for (int i = 0; i < MAXMEMBERS; i++)
            {
                if (memuser == memberUsername[i] && mempwd == memberPassword[i])
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
                    addmember(memberUsername, memberPassword, membersfee, feestatus, trainerUsername, membertrain, mcount);

                    break;
                case 2:
                    update(memberUsername, memberPassword, membersfee, membertrain, trainerUsername, feestatus);
                    break;
                case 3:
                    deletee(memberUsername, memberPassword, membersfee, feestatus, membertrain, mcount);
                    break;
                case 4:
                    memberlist(memberUsername, memberPassword, membersfee, feestatus, mcount);
                    break;
                case 5:
                    listtrainer(trainerUsername, trainerPassword, trainertime, trainerdues, tcount);
                    break;
                case 6:
                    editrainer(trainerUsername, trainerPassword, trainertime, trainerdues, paiddues, tcount);
                    break;
                case 7:
                    analytics(mcount, feestatus, membersfee, trainerdues, tcount);
                    break;
                case 8:
                    requests(memberUsername, memberPassword, membersfee, reqname, reqfee, reqcount, mcount, feestatus);

                    break;
                case 9:
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

                    shedules(trainerUsername, trainerPassword, trainerdues, trainertime, tcount);
                    break;
                case 2:
                    traintech(techname, description, techcount);
                    break;
                case 3:
                    trainerrdue(trainerdues, paiddues, logintrainer);
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
            member();
            do
            {
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
                    memberrdue(membersfee, feestatus, loginmember);
                    break;
                case 2:
                    changetrainer(membertrain, trainerUsername, loginmember);
                    break;
                case 3:
                    availabletrain(trainerUsername, trainertime, tcount);
                    break;
                case 4:
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
            member();
            membersignup();

            do
            {
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
                    packages();
                    break;
                case 2:
                    availabletrain(trainerUsername, trainertime, tcount);

                    break;
                case 3:
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
    bool a = saveuser(memberUsername, memberPassword, membersfee, feestatus);
    if (a == true)
        cout << "The data of user is stored sucessfully...)" << endl;
    else
        cout << "We r sorry, the data is not stored..";
    bool b = savetrainer(trainerUsername, trainerPassword, trainertime, trainerdues);
    if (b == true)
        cout << "The data of trainer is stored sucessfully...)";
    bool c =saverequests(reqname,reqfee);
    if(c==true)
        cout<<"The data of requests is stored successfully..)";

    return 0;
}
void gymName()
{
    system("color 0C");

    cout << " __  __     __         ______   ______     ______        ______     __  __     __    __    " << endl
         << "/\\ \\ /\\ \\   /\\ \\       /\\__  _\\ /\\  == \\   /\\  __ \\      /\\  ___\\   /\\ \\_\\ \\   /\\ \\-./  \\   " << endl
         << "\\ \\ \\\\_\\ \\  \\ \\ \\____  \\/_/\\ \\/ \\ \\  __<   \\ \\  __ \\     \\ \\ \\__ \\  \\ \\____ \\  \\ \\ \\-./\\ \\  " << endl
         << " \\ \\______\\  \\ \\_____\\    \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\ \\_\\     \\ \\_____\\  \\/______\\  \\ \\_\\ \\ \\_\\ " << endl
         << "  \\/______/   \\/_____/     \\/_/   \\/_/ /_/   \\/_/\\/_/      \\/_____/   \\/_____/   \\/_/  \\/_/ " << endl;

}
void menu()
{
    // system("color 07");
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
    system("color 07");
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
    system("color 07");
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.View Schedules" << setw(25) << "2.Fitness Techniques..              |" << endl
         << "              |   " << setw(25) << "3.Dues Info.." << setw(25) << "0.Logout..                          |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void logindispaly()
{
    system("color 07");
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
    system("color 07");
    cout << endl
         << "              ------------------------------------------------------------------" << endl
         << left
         << "              |   " << setw(25) << "1.Current Packages" << setw(25) << "2.Availaible Trainers..             |" << endl
         << "              |   " << setw(25) << "3.Guidlines to Enroll.." << setw(25) << "0.Logout..                          |" << endl
         << "              ------------------------------------------------------------------" << endl;
}
void enter()
{
    system("color 07");
    system("cls");
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "|                                  Enter Credentials   (^_^)                                      | " << endl;
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}
void admin()
{
    system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Admin (login)                               | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void trainer()
{
    system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Trainer (login)                             |  " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void member()
{
    system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                   Welcome to Member                           | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void memberlogin()
{
    system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                    Member (login)                             | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void membersignup()
{
    system("cls");
    cout << "           ---------------------------------------------------------------------------------" << endl;
    cout << "           |                                    Member (Signup)                             | " << endl;
    cout << "           ---------------------------------------------------------------------------------" << endl;
}
void initialize(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], string reqname[][2], int reqfee[], string techname[], string description[], int paiddues[], string membertrain[])
{
    for (int i = 0; i < MAXMEMBERS; i++)
    {
        memberUsername[i] = "nv";
        memberPassword[i] = "nv";
        membersfee[i] = 0;
        membertrain[i] = "nv";
        feestatus[i] = 'n';
    }
    for (int i = 0; i < MAXTRAINER; i++)
    {
        trainerUsername[i] = "nv";
        trainerPassword[i] = "nv";
        trainertime[i] = "nv";
        trainerdues[i] = 0;
        paiddues[i] = 0;
    }
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
void addmember(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string trainerUsername[], string membertrain[], int &mcount)
{
    cout << "       ---------------------" << endl;
    cout << "            ADD A MEMBER    " << endl;
    cout << "       ---------------------" << endl;
    string tname,naam;
    int p;
    char ch, ch1;
    while (mcount < MAXMEMBERS)
    {
        if (memberUsername[mcount] == "nv" && memberPassword[mcount] == "nv" && membersfee[mcount] == 0)
        {
            bool flag = true;
            do
            {
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
            memberUsername[mcount]=naam;
            cout << "Enter the ID for the same user: ";
            // cin.ignore();
            getline(cin, memberPassword[mcount]);
            cout << "You want to see the pacakages (Y/N): ";
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
            cout << "Enter the pacakage for that member(1-5):";
            cin >> p;
            while (p > 5 && p < 1 || !cin || cin.eof() || cin.fail())
            {
                cout << "Invaild pacakage, please enter again.. ";
                cin.clear();
                cin.ignore(200, '\n');
                cin >> p;
            }
            int fee = feePack(p);
            cout << "The fee for that member is " << fee << endl;
            membersfee[mcount] = fee;
            cout << "Enter its fee status(P for paid and U for unpaid): ";
            cin.ignore();
            cin.get(ch);
            ch = toupper(ch);
            while (ch != 'P' && ch != 'U')
            {
                cin.ignore(100, '\n');
                cout << "Enter its fee status(P for paid and U for unpaid): ";
                cin.get(ch);
                ch = toupper(ch);
            }
            feestatus[mcount] = ch;
            cout << "Do you want to specify its trainer: (Y/N) ";
            cin.ignore();
            cin.get(ch1);
            ch1 = toupper(ch1);
            while (ch1 != 'Y' && ch1 != 'N')
            {
                cin.ignore(100, '\n');
                cout << "Do you want to specify its trainer: (Y/N) ";
                cin.get(ch1);
                ch1 = toupper(ch1);
            }
            int i;
            bool found = false;
            if (ch1 == 'Y')
            {
                cin.ignore();
                while (!found)
                {
                    cout << "Enter its trainer name: ";
                    getline(cin, tname);
                    for (i = 0; i < MAXTRAINER; i++)
                    {
                        if (tname == trainerUsername[i])
                        {
                            membertrain[mcount] = tname;
                            found = true;
                            break;
                        }
                    }
                    if (!found)
                    {
                        cout << "trainer is not found.."<<endl;
                        cout<<"--------------------------"<<endl;
                    }
                }
            }
            cout << "Member added successfully!!!" << endl;
            break;
        }
        mcount++;
    }
    if (mcount >= MAXMEMBERS)
    {
        cout << "Sorry the space is already full.." << endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void update(string memberUsername[], string memberPassword[], int membersfee[], string membertrain[], string trainerUsername[], char feestatus[])
{
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
    for (int i = 0; i < MAXMEMBERS; i++)
    {
        if (memberUsername[i] == user)
        {
            msearch = true;
            break;
        }
    }
    if (!msearch)
    {
        cout << "Member is not found" << endl;
    }
    else
    {
        cout << "enter the updated name: ";
        // cin.ignore();
        getline(cin, upuser);
        cout << "enter its password to update: ";
        // cin.ignore();
        getline(cin, uppass);
        cout << "enter its fees to update: ";
        cin >> upfee;
        while (upfee < 0 || !cin || cin.eof() || cin.fail())
        {
            cout << "enter its fees to update: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> upfee;
        }
        cout << "Enter its fee status(P for paid and U for unpaid): ";
        cin.ignore();
        cin.get(upch);
        upch = toupper(upch);
        while (upch != 'P' && upch != 'U')
        {
            cin.ignore(100, '\n');
            cout << "Enter its fee status(P for paid and U for unpaid): ";
            cin.get(upch);
            upch = toupper(upch);
        }
        bool found = false;
        char tch;
        cout << "Do you want to update its trainer(Y/N): ";
        cin.ignore();
        cin.get(tch);
        tch = toupper(tch);
        while (tch != 'Y' && tch != 'N')
        {
            cin.ignore(100, '\n');
            cout << "Do you want to update its trainer(Y/N): ";
            cin.get(tch);
            tch = toupper(tch);
        }
        if (tch == 'Y')
        {
            while (!found)
            {
                cout << "Enter its updated trainer name: ";
                cin.ignore();
                getline(cin, tname);
                for (int i = 0; i < MAXTRAINER; i++)
                {
                    if (tname == trainerUsername[i])
                    {
                        found = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < MAXMEMBERS; i++)
        {
            if (memberUsername[i] == user)
            {
                memberUsername[i] = upuser;
                memberPassword[i] = uppass;
                membersfee[i] = upfee;
                // membertrain[i]=tname;
                feestatus[i] = upch;
                cout << "Member is updated successfully!!!" << endl;
                msearch = true;
                break;
            }
        }
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void deletee(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], string membertrain[], int &mcount)
{
    string deluser, delpass;
    bool msearch = false;
    cout << "       ---------------------" << endl;
    cout << "          DELETE A MEMBER   " << endl;
    cout << "       ---------------------" << endl;
    cout << "Enter the member name that you want to delete: ";
    cin.ignore();
    getline(cin, deluser);
    for (int i = 0; i < MAXMEMBERS; i++)
    {
        if (memberUsername[i] == deluser)
        {
            msearch = true;
            break;
        }
    }
    if (!msearch)
    {
        cout << "Member is not found" << endl;
    }
    else
    {
        cout << "enter its password to delete it: ";
        // cin.ignore();
        getline(cin, delpass);
        for (int i = 0; i < MAXMEMBERS; i++)
        {
            if (memberUsername[i] == deluser && memberPassword[i] == delpass)
            {
                memberUsername[i] = "nv";
                memberPassword[i] = "nv";
                membersfee[i] = 0;
                feestatus[i] = 'n';
                membertrain[i] = "nv";
                cout << "Member is deleted successfully!!!" << endl;
                mcount--;
                msearch = true;
                break;
            }
        }
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void memberlist(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[], int mcount)
{
    system("cls");
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    cout << "                             LIST OF ALL MEMBERS                              " << endl;
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    cout << "               " << left << setw(30) << "UserName" << setw(30) << "Password" << setw(30) << "Fees" << setw(30) << "Status" << endl;
    cout << "    -----------------------------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (memberUsername[i] != "nv" && memberPassword[i] != "nv" && membersfee[i] != 0)
        {
            cout << "               " << left << setw(30) << memberUsername[i] << setw(30) << memberPassword[i] << setw(30) << membersfee[i] << setw(30) << feestatus[i] << endl;
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
void editrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], int paiddues[], int &tcount)
{
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
    cout << "\tEnter want you want to do: ";
    cin >> n;
    while (n > 3 && n < 1 || !cin || cin.eof() || cin.fail())
    {
        cout << "\tEnter want you want to do: ";
        cin.clear();
        cin.ignore(200, '\n');
        cin >> n;
    }
    string time;
    if (n == 1)
    {
        cout << "       ---------------------" << endl;
        cout << "            ADD A TRAINER    " << endl;
        cout << "       ---------------------" << endl;
        string naam;
        int tcount = 0, amt = 0, pamt = 0;
        while (tcount < MAXTRAINER)
        {
            if (trainerUsername[tcount] == "nv" && trainerPassword[tcount] == "nv" && trainerdues[tcount] == 0 && paiddues[tcount] == 0)
            {
                
                bool flag = true;
                do
                {
                    flag = true; 
                    cout << "Enter the trainer name that you want to add: ";
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
                trainerUsername[tcount]=naam;

                cout << "Enter the ID for the same trainer: ";
                // cin.ignore();
                getline(cin, trainerPassword[tcount]);
                cout << "Enter the amount that will paid to it monthly: " << endl;
                cin >> amt;
                while (amt < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tEnter want you want to do: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> amt;
                }
                trainerdues[tcount] = amt;
                cout << "Enter the amount that is already paid to it: " << endl;
                cin >> pamt;
                while (pamt < 0 || !cin || cin.eof() || cin.fail())
                {
                    cout << "\tEnter want you want to do: ";
                    cin.clear();
                    cin.ignore(200, '\n');
                    cin >> pamt;
                }
                paiddues[tcount] = pamt;
                cout << "Enter its working hours like(1pm-5pm): ";
                cin.ignore();
                cin >> time;
                while (!timecheck(time))
                {
                    cout << "Please enter the hours again..";
                    cin >> time;
                }
                trainertime[tcount] = time;
                cout << "Trainer added successfully!!!" << endl;
                break;
            }
            tcount++;
        }
        if (tcount >= MAXTRAINER)
        {
            cout << "Sorry the space is already full.." << endl;
        }
        cout << endl
             << "                  Press any key to continue..";
        getch();
    }
    else if (n == 2)
    {
        string deltrain, delpas;
        bool tsearch = false;
        cout << "       ---------------------" << endl;
        cout << "            DELETE A TRAINER    " << endl;
        cout << "       ---------------------" << endl;
        cout << "Enter the trainer name that you want to delete: ";
        cin.ignore();
        getline(cin, deltrain);
        cout << "enter its password to delete it: ";
        // cin.ignore();
        getline(cin, delpas);
        for (int i = 0; i < MAXTRAINER; i++)
        {
            if (trainerUsername[i] == deltrain && trainerPassword[i] == delpas)
            {
                trainerUsername[i] = "nv";
                trainerPassword[i] = "nv";
                trainerdues[i] = 0;
                paiddues[i] = 0;
                trainertime[i] = "nv";
                cout << "Trainer is deleted successfully!!!" << endl;
                tcount--;
                tsearch = true;
                break;
            }
        }
        if (!tsearch)
        {
            cout << "Trainer not found>>" << endl;
        }
        cout << endl
             << "                  Press any key to continue..";
        getch();
    }
    else if (n == 3)
    {
        cout << "       ---------------------" << endl;
        cout << "          UPDATE A TRAINER   " << endl;
        cout << "       ---------------------" << endl;
        string train, uppas, uptrain, uptime;
        int updue, uppaid;
        bool tsearch = false;
        cout << "Enter the trainer name that you want to update: ";
        cin.ignore();
        getline(cin, train);
        cout << "enter the updated name: ";
        // cin.ignore();
        getline(cin, uptrain);
        cout << "enter its password to update: ";
        // cin.ignore();
        getline(cin, uppas);
        cout << "Enter the its monthly fees: ";
        cin >> updue;
        while (updue < 0 || !cin || cin.eof() || cin.fail())
        {
            cout << "Enter the its monthly fees: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> updue;
        }
        cout << "Enter the amount that is already paid to it: ";
        cin >> uppaid;
        while (uppaid < 0 || !cin || cin.eof() || cin.fail())
        {
            cout << "Enter the amount that is already paid to it: ";
            cin.clear();
            cin.ignore(200, '\n');
            cin >> uppaid;
        }
        cout << "Enter its working hours: ";
        cin.ignore();
        cin >> uptime;
        while (!timecheck(uptime))
        {
            cout << "Please enter the hours again..";
            cin >> time;
        }

        for (int i = 0; i < MAXTRAINER; i++)
        {
            if (trainerUsername[i] == train)
            {
                trainerUsername[i] = uptrain;
                trainerPassword[i] = uppas;
                trainerdues[i] = updue;
                trainertime[i] = uptime;
                paiddues[i] = uppaid;
                cout << "Trainer is updated successfully!!!" << endl;
                tsearch = true;
                break;
            }
        }
        if (!tsearch)
        {
            cout << "Trainer is not found>>" << endl;
        }
        cout << endl
             << "                  Press any key to continue..";
        getch();
    }
    else
    {
        cout << "Invalid input.." << endl;
        cout << endl
             << "                  Press any key to continue..";
        getch();
    }
}
void listtrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[], int tcount)
{
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
        if (trainerUsername[i] != "nv" && trainerPassword[i] != "nv" && trainertime[i] != "nv" && trainerdues[i] != 0)
        {
            cout << "    " << left << setw(20) << trainerUsername[i]
                 << setw(20) << trainerPassword[i]
                 << setw(20) << trainerdues[i]
                 << setw(20) << trainertime[i]
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
    system("cls");
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "                                    Dues Info                                       " << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
}
void analytics(int mcount, char feestatus[], int membersfee[], int trainerdues[], int tcount)
{
    system("cls");
    int sum = 0, tsum = 0, trainsum = 0;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "                                View Analytics                                               " << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;
    cout << "                                    Member                                             " << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (feestatus[i] == 'P' || feestatus[i] == 'U')
        {
            tsum += membersfee[i];
        }
    }
    for (int i = 0; i <= MAXMEMBERS; i++)
    {
        if (feestatus[i] == 'P')
        {
            sum += membersfee[i];
        }
    }

    for (int j = 0; j <= MAXTRAINER; j++)
    {
        if (trainerdues[j] != 0)
        {
            trainsum = trainsum + trainerdues[j];
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
    system("color 07");
}
void packages()
{
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
    int n, dis = 0;
    char ch, ch1;
    string name, reg, refer;
    system("cls");
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
    system("cls");
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
    while (pack > 5 && pack < 1 || !cin || cin.eof() || cin.fail())
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
void requests(string memberUsername[], string memberPassword[], int membersfee[], string reqname[][2], int reqfee[], int reqcount, int &mcount, char feestatus[]) {
    int n;
    char ch;
    system("cls");
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
        if (memberUsername[i] == "nv" && memberPassword[i] == "nv" && membersfee[i] == 0) {
            memberUsername[i] = reqname[n - 1][0];
            memberPassword[i] = reqname[n - 1][0] + "123";
            membersfee[i] = reqfee[n - 1];
            feestatus[i] = ch;
            mcount++;
            cout << "Member added successfully!" << endl;

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
void availabletrain(string trainerUsername[], string trainertime[], int tcount)
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                               Available Trainers                                            " << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                    Names                                    Availability        " << endl;
    for (int i = 0; i <= MAXTRAINER; i++)
    {
        if (trainerUsername[i] != "nv" && trainertime[i] != "nv")
        {
            cout << "                   " << setw(30) << trainerUsername[i] << "            " << setw(30) << trainertime[i] << endl;
        }
    }
        cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void traintech(string techname[], string description[], int &techcount)
{
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
void shedules(string trainerUsername[], string trainerPassword[], int trainerdues[], string trainertime[], int tcount)
{
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                               Your shedules                                              " << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << "                    Names                                    Availability        " << endl;
    for (int i = 0; i <= MAXTRAINER; i++)
    {
        if (trainerUsername[i] != "nv" && trainerPassword[i] != "nv" && trainertime[i] != "nv" && trainerdues[i] != 0)
        {
            cout << "                    " << setw(30) << trainerUsername[i] << "              " << setw(30) << trainertime[i] << endl;
        }
    }
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void trainerrdue(int trainerdues[], int paiddues[], int logintrainer)
{
    cout << "-------------------------------------" << endl;
    cout << "Your dues for this month is " << trainerdues[logintrainer] << endl;
    cout << "-------------------------------------" << endl;
    cout << "Amount that is already paid to you: " << paiddues[logintrainer] << endl;
    cout << "-------------------------------------" << endl;
    cout << "Remaining amount: " << trainerdues[logintrainer] - paiddues[logintrainer] << endl;
    cout << "-------------------------------------" << endl;
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void memberrdue(int membersfee[], char feestatus[], int loginmember)
{
    cout << "-------------------------------------" << endl;
    cout << "Your fee for this month is " << membersfee[loginmember] << endl;
    cout << "-------------------------------------" << endl;
    cout << "The status of your fee for this month: " << feestatus[loginmember] << endl;
    cout << "-------------------------------------" << endl;
    if (feestatus[loginmember] == 'P')
    {
        cout << "No fee remaining.." << endl;
        cout << "-------------------------------------" << endl;
    }
    else
    {
        cout << "Remaining amount: " << membersfee[loginmember] << endl;
        cout << "-------------------------------------" << endl;
    }
    cout << endl
         << "                  Press any key to continue..";
    getch();
}
void changetrainer(string membertrain[], string trainerUsername[], int loginmember)
{
    cout << "------------------------------------------------" << endl;
    cout << "Your current trainer is: " << membertrain[loginmember] << endl;
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
                cout << "Enter your trainer name: ";
                cin.ignore(100, '\n');
                getline(cin, name);
                for (int i = 0; i < MAXTRAINER; i++)
                {
                    if (name == trainerUsername[i])
                    {
                        membertrain[loginmember] = name;
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
bool loaduser(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[])
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
            getline(fin, memberUsername[j], ',');
            getline(fin, memberPassword[j], ',');
            fin >> membersfee[j];
            fin.ignore();
            fin.get(feestatus[j]);
            fin.ignore();
            j++;
        }

        fin.close();
        return true;
    }
}
bool saveuser(string memberUsername[], string memberPassword[], int membersfee[], char feestatus[])
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
            if (memberUsername[i] != "nv" && memberPassword[i] != "nv")
            {
                fout << memberUsername[i] << "," << memberPassword[i] << "," << membersfee[i] << "," << feestatus[i] << endl;
            }
        }
        fout.close();
        return true;
    }
}
bool loadtrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[])
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
            getline(fin, trainerUsername[j], ',');
            getline(fin, trainerPassword[j], ',');
            getline(fin, trainertime[j], ',');
            fin >> trainerdues[j];
            fin.ignore();
            j++;
        }
        fin.close();
        return true;
    }
}
bool savetrainer(string trainerUsername[], string trainerPassword[], string trainertime[], int trainerdues[])
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
            if (trainerUsername[i] != "nv" && trainerPassword[i] != "nv" && trainertime[i] != "nv" && trainerdues[i] != 0)
            {
                fout << trainerUsername[i] << "," << trainerPassword[i] << "," << trainertime[i] << "," << trainerdues[i] << endl;
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
    system("cls");
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