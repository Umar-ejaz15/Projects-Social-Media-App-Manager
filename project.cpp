#include <iostream>
using namespace std;

class Users
{
private:
    string Password;

public:
    string Email;
    string userName;

    void setPassword(string myPass)
    {
        Password = myPass;
    }
    string getPassword()
    {
        return Password;
    }

    Users()
    {
        cout << "welcome to our social media manager" << endl;
    }
    void createProfile()
    {
        cout << "Create Your Profile" << endl;
        cout << "Enter Your Email: ";
        cin >> Email;
        cout << "Enter Your UserName: ";
        cin >> userName;
        cout << "Enter Your Password: ";
        cin >> Password;
    }
    void logInProfile()
    {
        cout << "Login to your Profile" << endl;
        cout << "Enter Your Email: ";
        cin >> Email;
        cout << "Enter Your Password: ";
        cin >> Password;
    }
    virtual void randomUsers()
    {
        cout << "Sent Req to your friends" << endl;
        cout << "1. Okasha" << endl;
        cout << "2. Ali" << endl;
        cout << "3. Ahmad" << endl;
        cout << "4. Abdullal" << endl;
        cout << "5. Bilal" << endl;
        cout << "6. return to previous page" << endl;
        int option;
        cout << "People near you, send them request to get in touch:  ";
        cin >> option;
        while (option < 6)
        {
            cout << "Friend req sent to your friend" << endl;

            cout << "choose friend again to send req if you dont want to than press 6 to return to the previous page";
            cin >> option;

            if (option == 6)
            {
                break;
            }
        }
    }
};
class Posts : public Users

{
public:
    string sharePosts;
};

class Messages : public Users
{
public:
    Messages()
    {
        cout << "your username" << userName << endl;
    }
    void randomUsers() override
    {
        cout << "Sent msgs to your friends" << endl;
        cout << "1. Okasha" << endl;
        cout << "2. Ali" << endl;
        cout << "3. Ahmad" << endl;
        cout << "4. Abdullal" << endl;
        cout << "5. Bilal" << endl;
        cout << "6. return to previous page" << endl;
        int option;
        cout << "send msgs to your friends:";
        cin >> option;
        while (option != 6) // Loop until the user chooses to exit
        {
            string yourMsg;
            cout << "Enter Your Msg: ";
            cin >> yourMsg; // Single word message input
            cout << "Msg sent to your friend!" << endl;

            cout << "Choose a friend again to send a message, or press 6 to return to the previous page: ";
            cin >> option;
        }
    }
};

class Comments : public Users
{
};
int main()
{
    int choice;
    Users user1;

    cout << "Enter 0 to login to your Profile" << endl;
    cout << "Enter 1 to Create your Account" << endl;
    cin >> choice;
    if (choice == 0)
    {
        user1.logInProfile();
    }
    else if (choice == 1)
    {
        user1.createProfile();
        cout << "your account is created" << endl;
        cout << "Enter 0 to login" << endl;
        cout << "Enter 1 to quit" << endl;
        cin >> choice;

        if (choice == 0)
        {
            user1.logInProfile();
            int options;
            while (options <= 3)
            {
                cout << "1. Send req to friends" << endl;
                cout << "2. See Posts" << endl;
                cout << "3. Send msg to a friend" << endl;
                cout << "4. quit" << endl;
                cout << "chose your options";
                cin >> options;
                if (options == 1)
                {
                    user1.randomUsers();
                }
                else if (options == 2)
                {
                    /* code */
                }
                else if (options == 3)
                {
                    Messages();
                    Messages msg;
                    msg.randomUsers();
                }
                else
                {
                    cout << "App closed" << endl;
                }
            }
        }
        else
        {
            cout << "App closed" << endl;
        }
    }
    else
    {
        cout << "Error!";
    }

    return 0;
}