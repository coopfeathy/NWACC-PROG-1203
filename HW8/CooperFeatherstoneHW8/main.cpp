#include <string>
#include <iomanip>
#include <iostream>
#include <dirent.h>
#include <vector>

#include "Word.h"
#include "Concordance.h"

using namespace std;

int main() {
    DIR *dir;
    struct dirent *ent;
    vector<string> files = vector<string>();
    string choice;
    string file;

    if ((dir = opendir (".")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            string t = string(ent->d_name);

            if (t.size() >= 4 && t.substr(t.size() - 4, 4) == ".txt") {
                files.emplace_back(ent->d_name);
            }
        }

        closedir(dir);
    } else {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }

    for (auto const f : files) {
        cout << setw(15) << right << f << endl;
    }

    cout << "Select a file by typing the file name: ";
    getline(cin, choice);
    cout << choice << endl;

    for (auto const f : files) {
        if (f == choice) {
            ofstream outfile("concordance_"+choice);
            outfile << Concordance(ifstream(choice)).toString();
            outfile.close();
        }
    }
}
