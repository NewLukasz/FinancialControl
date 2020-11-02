#include "UserManager.h"

void UserManager::userRegister() {
    User user=typeUserData();

    users.push_back(user);
    xmlFileWithUsers.addUserToFile(user);
    cout<<"Register completed."<<endl;
    system("pause");
}

User UserManager::typeUserData() {
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

int UserManager::loginUser() {
    string login="", password="";
    system("cls");
    cout<<"Login: ";
    login=AccesoryFunctions::getLine();
    for(int i=0; i<users.size(); i++) {
        if(users[i].getLogin()==login) {
            for(int attempt=3; attempt>0; attempt--) {
                cout<<"Password: ";
                password=AccesoryFunctions::getLine();
                if(password==users[i].getPassword()) {
                    cout<<"Login is succesful"<<endl;
                    system("pause");
                    return users[i].getId();
                }
                cout<<endl<<"You typed incorrect password. Attempts left: "<<attempt-1<<"."<<endl;
            }
        }
        cout<<endl<<"You typed incorrect password three times."<<endl;
        system("pause");
        return 0;
    }
    cout<<"User with login: "<<login<<" doesn't exist"<<endl;
    system("pause");
    return 0;
}
