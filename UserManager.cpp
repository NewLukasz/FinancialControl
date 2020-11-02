#include "UserManager.h"

void UserManager::userRegister(){
    User user=typeUserData();

    users.push_back(user);

    cout<<"Register completed."<<endl;
    system("pause");
}

User UserManager::typeUserData(){
    system("cls");
    User user;
    user.setId(1);
    string login;
    cout<<"Type login: ";
    cin>>login;
    user.setLogin(login);

    string password;
    cout<<"Type password: ";
    cin>>password;
    user.setPassword(password);

    string name;
    cout<<"Type your name: ";
    cin>>name;
    user.setName(name);

    string surname;
    cout<<"Type your surname: ";
    cin>>surname;
    user.setSurname(surname);

    return user;
}
