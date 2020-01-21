// Include our custom library
#include "../include/PPM.h"
#include <iostream>
#include <fstream>
#include "ppm.cpp"

int main() {

    PPM myPPM("../textures/test.ppm");
    myPPM.darken();
    myPPM.savePPM("../textures/test_darken.ppm");

    return 0;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        std::cout << "Oops, exactly 2 arguments needed.\n";
        std::cout << "file_path\n";
        return 0;
    }
    
    std::string fileName = argv[1];
    std::string outputFile = "./textures/" + fileName + "_darken.ppm";

    PPM myPPM(argv[1]);
    myPPM.darken();
    myPPM.savePPM(outputFile);
    return 0;
}