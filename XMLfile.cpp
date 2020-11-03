#include "XMLfile.h"

void XMLFileWithUsers::addUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load("users.xml");
    if(!fileExists) {
        cout<<"JESTEM TUTAJ?"<<endl;
        system("pause");
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
    xml.Save("users.xml");
}

