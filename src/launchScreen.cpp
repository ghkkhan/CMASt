#include "../includes/launchScreen.hpp"

Starter::Starter( QWidget *parent) : QWidget(parent) {
    
    // first we setup the title label for the main page...
    title = new QLabel( "Choose My Adventure!", this );
    title -> setStyleSheet( "border:4px dashed; border-radius:3px; font-size:32px" );
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
    profile.setName(nameText);
    if ( !profile.test() ) { // returns true if person's profile exists...
        std::string message = "Hi, " + nameText + + ". I didn't find you in my list of profiles.\nIf you mistyped your name, please click \'cancel\' in order to re-enter your name :)\nOtherwise please click \'Ok\'";

        int ret = confirmMessage(message); // ret is the button that was pressed...

        if (ret == QMessageBox::Ok) { // if OK was pressed.
            message = "You will now be transfered to the start of this story.";
            ret = confirmMessage(message);
            if (ret == QMessageBox::Ok) {
                profile.create(); // creates a profile file for the new user!          
                qApp -> quit(); // close current window, moving on to the main game screen
            }
        } // else nothing...
    }
    else {
        // greet the player...
        std::string message =   "Hi, " + nameText + ". Welcome back to the program!\nYou will be transfered to your checkpoint momentarily\nIf this is not you, please click \'cancel\' in order to re-enter your name :)";
        int ret = confirmMessage(message);
        if (ret == QMessageBox::Ok) { // If OK button is pressed, move on to gamescreen...
            //thats all for the launch screen. just close up this mini window and go on to main game...
            qApp -> quit();
        } // else do nothing and repeat... 
    }
}

int Starter::confirmMessage(const std::string &message) {
    QMessageBox msg;
    msg.setText(QString::fromStdString(message));
    msg.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    return msg.exec();
}