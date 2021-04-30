#pragma once

#include "qtIncludes.hpp"
#include <iostream>
#include <fstream>
#include <QTextStream>
#include <QTextCursor>
#include <unistd.h>


// #include <QTextDocument>

#define MS 1000 // 1000 MicroSeconds in a millisecond.

// bool tiping = false; // global variable, denotes weather there is text being written on the screen.

class BaseScreen : public QWidget {
    Q_OBJECT // must be used because we'll be building our own "slots"

public:
    BaseScreen (QWidget *parent = nullptr);

private slots:
    // void OnMMenuButton();
    // void OnSaveButton();
    // void OnLoadButton();
    void OnGoButton();

private:
    QPushButton * menuButton;
    QPushButton * saveButton;
    QPushButton * loadButton;
    QPushButton * goButton;

    QTextEdit * mainText;
    QTextEdit * inputBox;
    void slowAppend(const QString &, const int &);
};