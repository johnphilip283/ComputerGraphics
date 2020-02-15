#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <QtOpenGL>

using namespace std;

class Parser {
    public:
        Parser();
        ~Parser();
        void parse(std::string filename);
        GLfloat getVertices();
        GLfloat getColors();
        GLuint getIndices();
    private:
        vector<GLuint> indicesList;
        vector<GLfloat> verticesList;
        vector<GLfloat> colorsList;
};

#endif