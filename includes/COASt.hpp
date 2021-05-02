#ifndef PROFILE_MAKER
#define PROFILE_MAKER 1 // makes sure that only one copy of profile exists...
// #pragma once
/*************************************************************
    * 
    * This is the COASt library
    * It will include all the functions that have to read files or write to them. 
    * It is a lite version of the COASt project, also found on github!
    *
*************************************************************/

// includes
#include <iostream>
#include <fstream>
#include <unistd.h>

// defines
#define MS 1000
#define SDLOC "./Data/savedata/"
#define EXT ".prof"

class Coast {
public:

    std::string getName();
    void setName(const std::string &);

    int getScene();
    void setScene(const int &);

    int getCheckpoint();
    void setCheckpoint(const int &);

    // std::string getNextLine();
    // std::string getContinuePoint();

    bool test();
    // int saveState();
    void create();    

    // Files for story, not profile files...
    bool openFile();
    bool closeFile();

private:
    std::ifstream inputFile;
    std::string name;
    int sceneMarker;
    int checkpointMarker;
};
extern Coast profile;
#endif
