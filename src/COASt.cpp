#include "../includes/COASt.hpp"

// Coast profile;

// @dscrpt:
// @params:
// @return:
bool Coast::test() {
    std::ifstream file;
    file.open(SDLOC + name + EXT);
    if (file.fail()) {
        return false;
    }
    file >> sceneMarker >> checkpointMarker;
    file.close();
    return true;
}

void Coast::create() {
    std::fstream file;
    file.open(SDLOC + name + EXT, std::fstream::out);
    file << "0 0" << std::endl;
    sceneMarker = 0;
    checkpointMarker = 0;
    file.close();
}


// GETTERS AND SETTERS
std::string Coast::getName() {
    return name;
}
void Coast::setName(const std::string &name) {
    this -> name = name; 
}
int Coast::getScene() {
    return sceneMarker;
}
void Coast::setScene(const int & sceneMarker) {
    this -> sceneMarker = sceneMarker;
} 
int Coast::getCheckpoint() {
    return checkpointMarker;
}
void Coast::setCheckpoint(const int & checkpointMarker) {
    this -> checkpointMarker = checkpointMarker;
}



// std::string getNextLine();
// std::string getContinuePoint();
// int saveState();

