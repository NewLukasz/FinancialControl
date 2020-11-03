#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>
#include "Markup.h"
#include "User.h"
using namespace std;

class XMLFile{
public:
};

class XMLFileWithUsers : public XMLFile{
public:
    void addUserToFile(User user);
};

#endif // XMLFILE_H
