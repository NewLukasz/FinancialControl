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
