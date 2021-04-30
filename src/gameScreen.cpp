#include "../includes/gameScreen.hpp"

bool tiping = false;
BaseScreen::BaseScreen (QWidget *parent) :QWidget(parent) {

    // setting up the buttons...
    menuButton = new QPushButton( "Main Menu", this );
    menuButton -> setStyleSheet( "border: 1px solid; border-radius:6px; font-size:22px" );

    saveButton = new QPushButton( "Save", this );
    saveButton -> setStyleSheet( "border: 1px solid; border-radius:6px; font-size:22px" );

    loadButton = new QPushButton( "Reload", this );
    loadButton -> setStyleSheet( "border: 1px solid; border-radius:6px; font-size:22px");

    goButton = new QPushButton( "Go", this );
    goButton -> setStyleSheet( "border:1px solid; border-radius: 6px; font-size:22px" );
    
    mainText = new QTextEdit( "Click GO! to proceed.\n", this );
    mainText -> setReadOnly(true);
    mainText -> setStyleSheet("border: 1px solid; border-radius:8px; background-color: palette(base); font-size:24px");

    inputBox = new QTextEdit( "", this );
    inputBox -> setFixedHeight(50);
    inputBox -> setStyleSheet("border: 1px solid; border-radius:8px; background-color: palette(base); font-size:24px");

    auto *grid = new QGridLayout( this );
    grid -> addWidget( menuButton, 0 ,0 );
    grid -> addWidget( saveButton, 0, 1 );
    grid -> addWidget( loadButton, 0, 2 );
    grid -> addWidget(   mainText, 1, 0, 1, 5 );
    grid -> addWidget(   inputBox, 2, 0, 1, 4 );
    grid -> addWidget(   goButton, 2, 4 );
    
    setLayout(grid);
    
    // connection of buttons to ActionEvents
    connect( goButton, &QPushButton::clicked, this, &BaseScreen::OnGoButton);
}   

void BaseScreen::OnGoButton() {
    QString str = "Hello, you clicked a button!";
    // put cursor at the end of the textbox;;;
    if (!tiping) {
        tiping = true;
        slowAppend(str, 100);
        tiping = false;
    }
}

// slowappend has to be multithreaded....
void BaseScreen::slowAppend(const QString &s, const int & speed) {
    // first put cursor at the end of the file...
    QTextCursor curser = mainText -> textCursor();
    curser.movePosition(QTextCursor::End);
    mainText -> setTextCursor(curser);
    
    for (int i = 0; i < s.size(); i++) {
        mainText -> insertPlainText(s[i]);
        qApp->processEvents();
        usleep(MS * speed);
    }
}