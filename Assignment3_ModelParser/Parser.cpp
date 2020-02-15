#include "Parser.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> split(const std::string& str, char delim = ' ') {
    
    vector<string> vector;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delim)) {
        vector.push_back(token);
    }

    return vector;
}

Parser::Parser() {

}

Parser::~Parser() {}

void Parser::parse(string fileName) {

    ifstream inFile;
    inFile.open(fileName);
    string line;

    getline(inFile, line);

    cout << line;
}

// GLfloat Parser::getVertices() {

// }


// Glfloat Parser::getColors() {

// }


// Gluint Parser::getIndices() {

// }

// parse the file - void parse(string filename)

// give back vertex data - List<Vertex>();
// colors
// faces