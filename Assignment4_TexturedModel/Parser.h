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
        void parse(string filename);
        vector<GLfloat> getVertices();
        vector<GLfloat> getNormals();
        vector<GLuint> getVertexIndices();
        vector<GLuint> getNormalsIndices();
        vector<GLfloat> getTextures();
        vector<GLuint> getTextureIndices();
    private:
        vector<GLfloat> verticesList;
        vector<GLfloat> normalsList;
        vector<GLuint> vertexIndices;
        vector<GLuint> normalIndices;
        vector<GLfloat> texturesList;
        vector<GLuint> texturesIndices;
};
#endif
