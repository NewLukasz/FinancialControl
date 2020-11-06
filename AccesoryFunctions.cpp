#include "AccesoryFunctions.h"

char AccesoryFunctions::getChar() {
    string insertedData = "";
    char sign  = {0};
    cin.sync();
    while (true) {
        getline(cin, insertedData);
        if (insertedData.length() == 1) {
            sign = insertedData[0];
            break;
        }
        cout << "This is not, a single sign. Try again." << endl;
    }
    return sign;
}

string AccesoryFunctions::getLine() {
    cin.sync();
    string dataInsert = "";
    getline(cin, dataInsert);
    return dataInsert;
}

string AccesoryFunctions::convertDoubleToString(double doubleToConvert) {
    ostringstream streamObj;
    streamObj<<doubleToConvert;
    return streamObj.str();
}
