#pragma once

#include "qtIncludes.hpp"
#include "COASt.hpp"
#include <QTextCursor>


// #include <QTextDocument>
#define MS 1000 // 1000 MicroSeconds in a millisecond.

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