#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Users
{
private:
    string Password;

protected:
    string Email;

public:
    string userName;

    void setPassword(string myPass)
    {
        Password = myPass;
    }
    string getPassword()
    {
        return Password;
    }

    void createProfile()
    {
        ofstream outFile("userData.txt", ios::app);
        if (!outFile)
        {
            throw "Error opening file for writing";
        }

        cout << "Create Your Profile" << endl;
        cout << "Please sign up:" << endl
             << endl;
        cout << "Enter Your Email: ";
        cin >> Email;
        cout << "Enter Your UserName: ";
        cin >> userName;
        cout << "Enter Your Password: ";
        cin >> Password;

        outFile << Email << " " << userName << " " << Password << endl;
        outFile.close();
        cout << "Your account is created successfully...............!" << endl
             << endl;
    }

    bool logInProfile()
    {
        bool loggedIn = false;
        while (!loggedIn)
        {
            ifstream inFile("userData.txt");
            if (!inFile)
            {
                throw "Error opening file for reading";
            }

            cout << "Login to your Profile" << endl;
            cout << "Please sign in:" << endl
                 << endl;
            cout << "Enter Your Email: ";
            cin >> Email;
            cout << "Enter Your Password: ";
            cin >> Password;

            string fileEmail, fileUserName, filePassword;
            bool found = false;
            while (inFile >> fileEmail >> fileUserName >> filePassword)
            {
                if (fileEmail == Email && filePassword == Password)
                {
                    userName = fileUserName;
                    found = true;
                    loggedIn = true;
                    break;
                }
            }
            inFile.close();

            if (!found)
            {
                cout << "Error: Invalid email or password" << endl;
                char tryAgain;
                cout << "Do you want to try again? (Y/N): ";
                cin >> tryAgain;

                if (tryAgain == 'n' || tryAgain == 'N')
                {
                    cout << "App Closed" << endl;
                    return false;  // Return false to indicate the user chose not to log in again
                }
                else if (tryAgain == 'y' || tryAgain == 'Y')
                {
                    // Loop will continue, prompting the user to log in again
                    continue;
                }
                else
                {
                    cout << "Invalid option. Exiting." << endl;
                    return false;  // Return false to indicate the user chose not to log in again
                }
            }
            else
            {
                cout << "Account successfully logged in!" << endl
                     << endl;
            }
        }
        return true;  // Return true to indicate successful login
    }

    virtual void socialData()
    {
        cout << "Sent Req to your friends:" << endl
             << endl;
        cout << "1. Okasha" << endl;
        cout << "2. Ali" << endl;
        cout << "3. Ahmad" << endl;
        cout << "4. Abdullal" << endl;
        cout << "5. Bilal" << endl;
        cout << "6. Return to previous page" << endl;
        int option;
        cout << "People near you, send them request to get in touch: ";
        cin >> option;
        while (option != 6)
        {
            cout << "Friend req sent to your friend successfully.........." << endl
                 << endl;
            cout << "Choose friend again to send req, or press 6 to return to the previous page: ";
            cin >> option;
        }
    }
};

class Comments : public Users
{
public:
    void addComment()
    {
        string addComment;
        cout << "Add your Comment to the post: ";
        cin.ignore(); // Ignore the newline character left in the input buffer
        getline(cin, addComment);
    }
};

class Posts
{
public:
    string sharePosts;

    Posts()
    {
        cout << "1. View Posts" << endl;
        cout << "2. Upload Posts" << endl;
        cout << "3. Close posts" << endl;
    }

    void PostsData()
    {
        int posts;
        cout << "Press 0 to view posts, Press 1 to upload posts, and press 2 to close posts: " << endl;
        cin >> posts;
        while (posts != 2)
        {
            if (posts == 1)
            {
                cout << "Enter your thoughts: ";
                cin.ignore();
                getline(cin, sharePosts);
                cout << "Your post is shared in feed: " << endl;
                cout << sharePosts << endl;
                cout << "1. View Posts" << endl;
                cout << "2. Upload Posts" << endl;
                cout << "3. Close posts" << endl;
                cout << "Press 0 to view posts, Press 1 to upload posts, and press 2 to close posts: " << endl;
                cin >> posts;
            }
            else if (posts == 0)
            {
                cout << "1. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis" << endl;
                cout << "Published By Ali" << endl
                     << endl;

                cout << "2. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis" << endl;
                cout << "Published By Abdullah" << endl
                     << endl;

                cout << "3. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Donec quam felis" << endl;
                cout << "Published By Ahmad" << endl
                     << endl;

                int choosePosts;
                cout << "If you want to add comments to any post enter the number of the post: ";
                cin >> choosePosts;

                if (choosePosts == 1 || choosePosts == 2 || choosePosts == 3)
                {
                    Comments comment;
                    comment.addComment();
                    cout << "Comment is added" << endl;
                }
                else
                {
                    cout << "Invalid post number." << endl;
                }
                cout << "1. View Posts" << endl;
                cout << "2. Upload Posts" << endl;
                cout << "3. Close posts" << endl;
                cout << "Press 0 to view posts, Press 1 to upload posts, and press 2 to close posts: " << endl;
                cin >> posts;
            }
        }
    }
};

class Messages : public Users
{
public:
    void setEmail(string myEmail)
    {
        Email = myEmail;
    }
    string getEmail()
    {
        return Email;
    }

    void socialData()
    {
        int option = 0;
        while (option != 6)
        {
            cout << "Choose Option to Send messages to your friends" << endl;
            cout << "1. Okasha" << endl;
            cout << "2. Ali" << endl;
            cout << "3. Ahmad" << endl;
            cout << "4. Abdullal" << endl;
            cout << "5. Bilal" << endl;
            cout << "6. Return to previous page" << endl;

            cout << "Select option to send messages to your friends: ";
            cin >> option;
            if (option == 6)
                break;

            string msg;
            cout << "Type message: ";
            cin.ignore();
            getline(cin, msg);

            cout << "Message is sent to your friend successfully............!" << endl
                 << endl;
        }
    }
};

void socialOptions()
{
    int options = 0;
    while (options != 4)
    {
        cout << "\n1. Send request to friends" << endl;
        cout << "2. See Posts" << endl;
        cout << "3. Send message to a friend" << endl;
        cout << "4. Quit" << endl;
        cout << "Choose your option: ";
        cin >> options;

        try
        {
            if (options == 1)
            {
                Users user1;
                user1.socialData();
            }
            else if (options == 2)
            {
                Posts post1;
                post1.PostsData();
            }
            else if (options == 3)
            {
                Messages msg;
                msg.socialData();
            }
            else if (options == 4)
            {
                cout << "App closed" << endl;
            }
            else
            {
                throw "Invalid option, please try again.";
            }
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
}

int main()
{
    cout << "<---- WELCOME TO OUR SOCIAL MEDIA MANAGER ---->" << endl
         << endl;
    int choice;
    Users user1;

    cout << "Enter 0 to login to your Profile" << endl;
    cout << "Enter 1 to Create your Account" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    try
    {
        switch (choice)
        {
        case 0:
            if (user1.logInProfile())
            {
                socialOptions();
            }
            break;
        case 1:
            user1.createProfile();
            cout << "If you want to login press 0, or if you want to close the app enter 1" << endl;
            cin >> choice;

            if (choice == 0)
            {
                if (user1.logInProfile())
                {
                    socialOptions();
                }
            }
            else if (choice == 1)
            {
                cout << "App Closed" << endl;
            }

            break;

        default:
            throw "Error, Please try again.........!";
        }
    }
    catch (const char *e)
    {
        cout << e << endl;
    }

    return 0;
}
