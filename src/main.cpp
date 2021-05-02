/*************************************************************
    * 
    * This is the base of the whole operation... Kind of like a timeline. Leads to the rest of the program...
    *
*************************************************************/


#include "../includes/main.hpp"

using namespace std;

Coast profile;

int main(int argc, char *argv[]) {
    profile.setScene(-1);
    QApplication app ( argc, argv );

    Starter window;
    window.resize( 800, 300);
    window.setWindowTitle( "Start Screen" );
    window.show();
    app.exec();

    // Wonderful! At this point, we have the player setup. 
    // Next we launch the game window, and it'll take over with the COASt library working in the background!
    window.hide();
    if (profile.getScene() == -1) {
        return 0;
    }
    BaseScreen gameWindow;
    gameWindow.resize( 1400, 800 );
    gameWindow.setWindowTitle( "Game Screen" );
    gameWindow.show();
    app.exec();
}

