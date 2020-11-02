#include "XMLfile.h"

bool XMLFile::checkFileIsExists(string fileName) {
    string fileNameWithExtension=fileName+".xml";
    return xml.Load(fileNameWithExtension);
}

void XMLFileWithUsers::addUserToFile(User user) {
    if(!checkFileIsExists("users")) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId",user.getId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save("users.xml");
}
