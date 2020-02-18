#ifndef PARSER
#define PARSER

#include <string>
#include <vector>
#include <QtOpenGL>

#include <glm/glm.hpp>

using namespace std;

class Parser {
    public:
        Parser();
        ~Parser();
        void parse(std::string filename);
        vector<float> getVertices();
        vector<float> getNormals();
        vector<unsigned int> getVertexIndices();
        vector<unsigned int> getNormalsIndices();
    private:
        vector<float> verticesList;
        vector<float> normalsList;
        vector<unsigned int> vertexIndices;
        vector<unsigned int> normalIndices;

};

#endif