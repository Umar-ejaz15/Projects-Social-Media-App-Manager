#include <iostream>
using namespace std;

class Users
{
private:
    string Password;

public:
    string Email;
    string userName;
    int phoneNumber;
    void setPassword(string myPass)
    {
        Password = myPass;
    }
    string getPassword()
    {
        return Password;
    }
    Users(string myEmail, string myUserName, int myPhoneNumber, string myPass)
    {
        Password = myPass;
        Email = myEmail;
        userName = myUserName;
        phoneNumber = myPhoneNumber;
        cout << Email << " " << userName << " " << phoneNumber << " " <<getPassword();
    }
};
class Posts:public Users

{
    public: 
    string sharePosts;
};

class Messages:public Users
{
};

class Comments:public Users
{
};
int main()
{
    Users user1("ui737773@gmail.com", "umar", 300812821, "Uma28");
    Users user2("ui737773@gmail.com", "okasha", 300812821, "Uma28");


    return 0;
}