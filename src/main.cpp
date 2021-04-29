/*************************************************************
    * 
    * This is the base of the whole operation... Kind of like a timeline. Leads to the rest of the program...
    *
*************************************************************/


// #include "../includes/main.hpp"
#include "../includes/launchScreen.hpp"

int main(int argc, char *argv[]) {
    QApplication app ( argc, argv );

    Starter window;
    window.resize( 800, 300);
    window.setWindowTitle( "Start Screen" );
    window.show();
    
    app.exec();

    // Wonderful! At this point, we have the player setup. 
    // We next launch the gameScreen and use the checkpoint data in order to add continuity.
    std::cout << window.getName() << " is at section " << window.getSection() << " and checkpoint "<< window.getCheckPoint()<< std::endl;

    // // first get the name of the user...
    // string name;
    // greetPlayer(name);
    // // int checkpoint = greetPlayer(&name); // gets player's name and acts accordingly...
    
}