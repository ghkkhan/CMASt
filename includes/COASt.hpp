/*************************************************************
    * 
    * This is the COASt library
    * It will include all the peripheral functions that are so repetedly used in the program
    * This includes functions from printing lines to reading in input with proper verifications
    * Functions related to file-reading can also be found within.
    *
*************************************************************/

// includes
#include <iostream>
#include <fstream>
#include <unistd.h>

// defines
#define MS 1000

// Function declarations
/***********************************************************/
void print(const std::string &, const int);
std::string getStr();
int greetPlayer(std::string &);