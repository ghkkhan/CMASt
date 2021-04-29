#include "../includes/launchScreen.hpp"
#include <QGridLayout>
#include <QMessageBox>
#include <fstream>


Starter::Starter( QWidget *parent) : QWidget(parent) {
    
    // first we setup the title label for the main page...
    title = new QLabel( "Choose My Adventure!", this );
    title -> setStyleSheet( "border:4px dashed; border-radius 3px; font-size:32px" );
    title -> setFixedHeight(80);
    title -> setAlignment(Qt::AlignCenter);

    // setting up the start button
    startBtn = new QPushButton("Start!", this);
    startBtn -> setStyleSheet("border: 1px solid; border-radius:6px; font-size:22px; ");

    // setting up the "entername" label
    lbl = new QLabel( "Enter Name", this );
    lbl -> setStyleSheet("font-size:21px; padding:30px");

    // setting up the Textbox
    name = new QTextEdit("", this);
    name -> setFixedHeight(50);
    name -> setFixedWidth(400);
    name -> setStyleSheet("border: 1px solid; border-radius:10px; background-color: palette(base); font-size:24px");

    auto *grid = new QGridLayout( this );
    grid -> addWidget (title, 0, 1);
    grid -> addWidget( lbl, 1, 0 );
    grid -> addWidget( name, 1, 1 );
    grid -> addWidget( startBtn, 1, 2 );

    setLayout(grid);
    connect( startBtn, &QPushButton::clicked, this, &Starter::OnStartButton);
}

// first checks if this is the first timer or a returnee...
// then begins the game depending...
void Starter::OnStartButton() {

    //@TODO: First get player name from the textbox
    std::string nameText = (name ->toPlainText()).toUtf8().constData();
    //@TODO: Check if player's profile exists...
    std::ifstream fs;
    fs.open ( "./savedata/" + nameText + ".prof" );
    //@TODO: if it exists, tell them that they'll continue where they left off... othewise, ask them to recheck the name and create new profile...
    if ( fs.fail() ) {
        // if the file doesn't exist... this is the players first time logging in...
        // this creates a new save data for this player's checkpoint and gives 
        std::cout << "lol " << nameText << std::endl;
    }
    else {
        // greet the player...
        QMessageBox msg;
        std::string message =   "Hi, " + nameText + ". Welcome back to the program!\nYou will be transfered to your checkpoint momentarily\nIf this is not you, please click \'cancel\' in order to re-enter your name :)";
        msg.setText(QString::fromStdString(message));
        msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        int ret = msg.exec();

        // If OK button is pressed, move on to gamescreen...
        if (ret == QMessageBox::Ok) {
            nameOfPlayer = nameText; // set name of Player in game to the entry by the player...

            // read the file for continuity
            // first line contains 2 numbers, section number and checkpoint number, separated by space.
            fs >> sectionMarker >> checkPointMarker;
            //thats all for the launch screen. just close up.
            fs.close();
            qApp -> quit();
        }
        else {
            // if cancel button was pressed... close dialog and simply wait for next input.
            fs.close();
        }
        // print("This is the story bits\n", 67);
        // return checkpoint;

    }
}