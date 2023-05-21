#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
#include <cstring>
using namespace std;


class resturantMenu
{
    char mainMenu[100], itemMenu[100];
    int foodPrice;
    int totalPrice=0;

public:
    void addMenu(void);
    void displayMenu(void);
    void choiceQuantity(void);
    void deleted(void);
};

void resturantMenu ::addMenu()
{
    int n;
    ofstream myFile;
    resturantMenu rm;
    myFile.open("samip.txt", ios::out | ios::app);//open file in writing mode and append mode
   do {
        cout << "Enter how many ITEMS you want to add: ";
        if (!(cin >> n)) {
            // If input is invalid, clear the error flag and ignore the input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }
            if (n <= 0) {
        cout << "Invalid input! Please enter a positive number." << endl;
        continue;
    }
        break;
    } while (true);
    cin.ignore(); // Ignore the newline character from previous input
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Main Menu [" << i + 1 << "]: ";
        cin.getline(rm.mainMenu, 100);
        cout << "Enter Item Menu[" << i + 1 << "]: ";
        cin.getline(rm.itemMenu, 100);
           do {
        cout << "Enter the price of food[" << i + 1 << "]: ";
        if (!(cin >> rm.foodPrice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number for food price." << endl;
            continue;
        }
            if (rm.foodPrice <= 0) {
        cout << "Invalid input! Please enter a positive number." << endl;
        continue;
    }
        break;
    } while (true);
        cin.ignore(); // Ignore the newline character from previous input
        myFile.write((char *)&rm, sizeof(rm));

    }
    myFile.close();
}

void resturantMenu ::displayMenu()
{
    resturantMenu rm;
    int counter = 1;
    ifstream readFile;
    readFile.open("samip.txt", ios::in);//open file for reading mode.
    cout<<left<<setw(1)<<"|"<<setw(15)<<"Choice"<<setw(1)<<"|"<<setw(15)<<"Main Menu"<<setw(1)<<"|"<<setw(15)<<"Item Menu"<<setw(1)<<"|"<<setw(15)<<"Food Price"<<endl;
    cout<<"----------------------------------------------------------------------------------------"<<endl;
    while (readFile.read((char *)&rm, sizeof(rm)))
    {
        cout<<left<<setw(1)<<"|"<<setw(15)<<counter<<setw(1)<<"|"<<setw(15)<<rm.mainMenu<<setw(1)<<"|"<<setw(15)<<rm.itemMenu<<setw(1)<<"|"<<setw(15)<<rm.foodPrice<<endl;
        counter++;
    }
     cout<<"----------------------------------------------------------------------------------------"<<endl;
    readFile.close();
}


void resturantMenu ::choiceQuantity()
{
    int choice,quantity;
    char answer;
    totalPrice=0;
    resturantMenu rm;
    ifstream readFile;
    do
    {
        do 
        {
            cout << "Enter choice of food: ";
            if (!(cin >> choice)) 
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Please enter a valid choice." << endl;
                continue;
            }
            if (choice <= 0) 
            {
                cout << "Invalid input! Please enter a positive choice." << endl;
                continue;
            }
        break;
    } while (true);

        readFile.open("samip.txt", ios::in);
        int counter = 1;
        while (readFile.read((char *)&rm, sizeof(rm)))
        {
            if (choice == counter) 
            {
                cout<<rm.mainMenu<<"\t"<<rm.itemMenu<<"\tprice: "<<rm.foodPrice<<endl;
            do 
            {
                cout << "Enter quantity: ";
                if (!(cin >> quantity)) 
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a valid quantity." << endl;
                        continue;
                    }
                if (quantity <= 0) 
                {
                    cout << "Invalid input! Please enter a positive quantity." << endl;
                    continue;
                }
                break;
            } while (true);
            cout<<" Total Price: "<<rm.foodPrice * quantity<<endl;
                totalPrice =totalPrice + rm.foodPrice * quantity;
                break;
            }
            counter++;
        }
        cout<<"Do you need anything?"<<endl;
        cout<<"\t(y/n)"<<endl;
        cin>>answer;
        if (answer == 'y')
        {
            cout << "Add another food items" << endl;
        }
        readFile.close();
    } while (answer=='y');
    cout<<"Grand total: "<<totalPrice<<endl;
}

void resturantMenu ::deleted()
{
    resturantMenu rm;
    ofstream newFile;
    ifstream existedFile;
    int a;
    int choice=1;

            rm.displayMenu();

        do 
        {
            cout<<"Enter a number to deleted item: ";
            if (!(cin >> a)) 
                {
                    // If input is invalid, clear the error flag and ignore the input buffer
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\tInvalid input! Please enter a valid number." << endl;
                    continue;
                }
                    if (a <= 0) 
                    {
                        cout << "\tInvalid input! Please enter a positive number." << endl;
                        continue;
                    }
                    break;
        } while (true);
    newFile.open("Anotherfile.txt",ios::app);
    existedFile.open("samip.txt",ios::in);
    if(!existedFile)
    {
        cout<<"file not found"<<endl;
        exit(0);
    }
    else
    {
        while(existedFile.read((char *)&rm, sizeof(rm)))
        {
            if(a!=choice)
            {
                newFile.write((char *)&rm, sizeof(rm));
            }
            choice++;
        }
    }
    newFile.close(); //close the new file.
    existedFile.close();  //close the old file.
    
    // delete the old file
    remove("samip.txt");

    // rename new file to the older file
    rename("Anotherfile.txt","samip.txt");
    cout << "Item deleted successfully!" << endl;
}

void welcome()
{
    cout << "**********************************************" << endl;
    cout <<"\tHWIC CAFE" << endl;
    cout <<"\tPutalisadka,Kathmandu" << endl;
    cout << "**********************************************" << endl;
    cout << "**********************************************" << endl;

}

void login()
{
    string user,pass;
    string done="false";
    do
    {
        cout<<"Enter the Username and Password"<<endl;
        cout<<"Username: ";
        cin>>user;
        cout<<"Password: ";
        cin>>pass;
        if(user=="bbsksb"&&pass=="bibekbist")
        {
            cout<<"Now you can change"<<endl;
            done=true;
        }
        else
        {
            cout<<"Invalid input"<<endl;
        }
    } while(done=="false");
    

}


int main()
{
    int choice;
    string done = "false";
    resturantMenu rm;
    do
    {
        welcome();
        cout << "\t1. Add menu" << endl;
        cout << "\t2. Menu" << endl;
        cout << "\t3. Delete" << endl;
        do 
        {
            cout << "\tInput the choice here: ";
            if (!(cin >> choice)) 
                {
                    // If input is invalid, clear the error flag and ignore the input buffer
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\tInvalid input! Please enter a valid number." << endl;
                    continue;
                }
                    if (choice <= 0) 
                    {
                        cout << "\tInvalid input! Please enter a positive number." << endl;
                        continue;
                    }
                    break;
        } while (true);
        system("cls");
        switch (choice)
        {
        case 1:
            login();
            rm.addMenu();
            break;
        case 2:
            rm.displayMenu();
            rm.choiceQuantity();
            break;
        case 3:
            login();
            rm.deleted();
            break;
        default:
            cout << "Invalid input!" << endl;
            done = "true";
            break;
        }
    } while (done == "true");
    return 0;
}
