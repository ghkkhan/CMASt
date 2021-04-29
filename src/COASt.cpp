#include "../includes/COASt.hpp"

// @dscrpt: prints the given string s, slowly, acording to the speed passed
// @params:
//          s is a std::string that is meant to be printed
//          speed is a time-measure given in milliseconds
// @return: void
void print(const std::string &s, const int speed) {
    for (size_t i = 0; i < s.size(); i++) {
        std::cout << s[i] << std::flush;
        usleep(MS * speed);
    }
}

// @dscrpt: takes an input string from stdin... ensures it's valid and returns through reference
// @params: no parameters...
// @return: returns the string input from the user
std::string getStr() {
    std::string var = "temp";
    do {
        std::cin >> var;
    } while(var.size() < 1);
    return var;
}


// @dscrpt: gets player's name and check where they should continue from, or start a new...
// @params: recieves a name variable by reference. Content is garbage and meant to be used as a variable to pass back
// @return: returns an integer value used to figure out where the player is in the story.
int greetPlayer(std::string &name) {
    //get player name and greet them
    print("(Enter your name): ", 67);
    name = getStr();

    // check the save data to see if the player is new or returnal.
    std::ifstream fs;
    fs.open ( "./savedata/" + name + ".cpt" );
    if ( fs.fail() ) {
        // if the file doesn't exist... this is the players first time logging in...
        // this creates a new save data for this player's checkpoint and gives 
        std::cout << "lol " << name << std::endl;
    }
    else {
        // greet the player...
        print("(Hi, " + name + ". Welcome back to the program!)", 67);
        usleep(MS * 666);
        print("\n(You will be transered to your checkpoint momentarily", 99);
        print("...)", 444);
        usleep(MS * 900);
        print("\n****************************************************************\n",34);
        usleep(MS * 500);

        // print("This is the story bits\n", 67);
        return checkpoint;

    }
}