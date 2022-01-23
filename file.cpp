#include <iostream>
#include <vector>
#include <string>
#include "boost/filesystem.hpp"

using std::cout; using std::cin;
using std::endl; using std::string;
using boost::filesystem::directory_iterator;

int main() {
    string path = "/Users/theo";

    for (const auto & file : directory_iterator(path))
        cout << file.path() << endl;

    return EXIT_SUCCESS;
}