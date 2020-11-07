#include "UserManager.h"

void UserManager::userRegister() {
    User user=typeUserData();
    users.push_back(user);
    xmlFileWithUsers.addUserToFile(user);
    cout<<"Register completed."<<endl;
    system("pause");
}

void UserManager::changeUserPassword(){
    cout<<"Type new password: "<<endl;
    string newPassword;
    newPassword=AccesoryFunctions::getLine();
    for(int i=0;i<users.size();i++){
        if(users[i].getId()==idLoggedInUser){
            users[i].setPassword(newPassword);
        }
    }
    xmlFileWithUsers.deleteFileWithUsers();
    for(int i=0;i<users.size();i++){
        xmlFileWithUsers.addUserToFile(users[i]);
    }
    cout<<endl<<"Password was successfully changed."<<endl;
    system("pause");
}

User UserManager::typeUserData() {
    system("cls");
    User user;
    user.setId(xmlFileWithUsers.getLastUserId());
    string login;
    cout<<"Type login: ";
    login=AccesoryFunctions::getLine();
    while(checkLoginExists(login)){
        cout<<endl<<"Login: "<<login<<" exists. Choose another one."<<endl<<endl;
        cout<<"Type login: ";
        login=AccesoryFunctions::getLine();
    }
    user.setLogin(login);

    string password;
    cout<<"Type password: ";
    password=AccesoryFunctions::getLine();
    user.setPassword(password);

    string name;
    cout<<"Type your name: ";
    name=AccesoryFunctions::getLine();
    user.setName(name);

    string surname;
    cout<<"Type your surname: ";
    surname=AccesoryFunctions::getLine();
    user.setSurname(surname);

    return user;
}

int UserManager::loginUser() {
    string login="", password="";
    system("cls");
    cout<<">>>Login<<<"<<endl;
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
                    idLoggedInUser=users[i].getId();
                    return users[i].getId();
                }
                cout<<endl<<"You typed incorrect password. Attempts left: "<<attempt-1<<"."<<endl;
            }
            cout<<endl<<"You typed incorrect password three times."<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<"User with login: "<<login<<" doesn't exist"<<endl;
    system("pause");
    return 0;
}

bool UserManager::checkLoginExists(string loginForCheck){
    for(int i=0;i<users.size();i++){
        if(users[i].getLogin()==loginForCheck){
            return true;
        }
    }
    return false;
}

int UserManager::logout(){
    idLoggedInUser=0;
    return 0;
}

bool UserManager::checkIfUserIsLogin(){
    if(idLoggedInUser==0){
        return 0;
    }else{
        return 1;
    }
}

int UserManager::getIdLoggedInUser(){
    return idLoggedInUser;
}
