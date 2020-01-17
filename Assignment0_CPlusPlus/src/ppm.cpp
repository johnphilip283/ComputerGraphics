#include "../include/PPM.h"
#include <fstream>

using namespace std;

// Constructor loads a filename with the .ppm extension
PPM::PPM(string fileName) {

    ifstream inFile;

    inFile.open(fileName);
    
    int index = 0;
    string a;
    while (index != 5) {
        inFile >> a;
        cout << a;
        break;
        index++;
    }

        
        // if (index == 2) {
        //     char* line;   // A string object.
        //     getline(inFile, line);
        //     char str[] = line;
        //     char delim = " ";

        //     char* token = strtok(str, " ");
        //     string measurements[] = new string[2];

        //     while (token != NULL) {

        //     }
        // }
        
        

        // if (index == 2) {

        //     char* tok = strtok(line, " ");
        //     char* first = tok;
        //     char* second;

        //     while (tok != NULL) {
        //         second = strtok(NULL, " ");
        //     }

        //     m_PixelData = new unsigned char[];
        // }

        
        // while(getline(inFile,line)){
        //     cout << line << endl;
        // }
        // index++;
    // }
    // TODO:    Load and parse a ppm to get its pixel
    //          data stored properly.
}

// Destructor clears any memory that has been allocated
PPM::~PPM() {
}

// Saves a PPM Image to a new file.
void PPM::savePPM(string outputFileName) {
    // TODO: Save a PPM image to disk
}

// Darken subtracts 50 from each of the red, green
// and blue color components of all of the pixels
// in the PPM. Note that no values may be less than
// 0 in a ppm.
void PPM::darken() {
    
    for (int i = 0; i < m_width; i++) {
        for (int j = 0; j < m_height; j++) {
            int index = (m_width * j * 3) + (i * 3);
            if (m_PixelData[index] - 50 < 0 || m_PixelData[index + 1] - 50 < 0 || m_PixelData[index + 2] - 50 < 0) {
                setPixel(i, j, m_PixelData[index] - 50, m_PixelData[index + 1] - 50, m_PixelData[index + 2] - 50);
            }
        }
    }
}

// Sets a pixel to a specific R,G,B value 
void PPM::setPixel(int x, int y, int R, int G, int B) {
    int index = (m_width * y * 3) + (x * 3);
    m_PixelData[index] = R;
    m_PixelData[index + 1] = G;
    m_PixelData[index + 2] =  B;
}
