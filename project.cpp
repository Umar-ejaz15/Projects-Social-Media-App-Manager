#include <iostream>
using namespace std;
void WellCome()
{
    cout << "Wellcome To Social Media App Maneger";
}
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
        cout<<"Create A Profile"<<endl;
    
        cout<<"Enter Your Email: ";cin>>Email;
        cout<<"Enter Your UserName: ";cin>>userName;
        cout<<"Enter Your Password: ";cin>>Password;

    }
};
class Posts : public Users

{
public:
    string sharePosts;
};

class Messages : public Users
{
};

class Comments : public Users
{
};
int main()
{
    WellCome();
    Users user1;

    return 0;
}