#include "XMLFileWithUsers.h"

void XMLFileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load(fileNameForFileWithUsers);
    if(!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save(fileNameForFileWithUsers);
}

vector <User> XMLFileWithUsers::loadUsersFromFile(){
    vector <User> users;
    User user;
    CMarkup xml;

    bool fileExists=xml.Load(fileNameForFileWithUsers);

    if(!fileExists){
        cout<<"There are no users registered. Start from register."<<endl;
        system("pause");
    }else{
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("UserId");
            user.setId(atoi(xml.GetData().c_str()));
            xml.FindElem("Login");
            user.setLogin(xml.GetData());
            xml.FindElem("Password");
            user.setPassword(xml.GetData());
            xml.FindElem("Name");
            user.setName(xml.GetData());
            xml.FindElem("Surname");
            user.setSurname(xml.GetData());
            xml.OutOfElem();
            users.push_back(user);
        }
    }
    return users;
}

int XMLFileWithUsers::getLastUserId(){
    int lastUserId=1;
    CMarkup xml;

    bool fileExists = xml.Load(fileNameForFileWithUsers);

    if(!fileExists){
        return lastUserId;
    }else{
        xml.FindElem();
        xml.IntoElem();
        while(xml.FindElem("User")){
            xml.IntoElem();
            xml.FindElem("UserId");
            lastUserId=atoi(xml.GetData().c_str());
            xml.OutOfElem();
        }
    }
    return lastUserId+1;
}
