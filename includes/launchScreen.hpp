#pragma once

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <iostream>



class Starter : public QWidget {
    Q_OBJECT // must be used because we'll be building our own "slots"

public:
    Starter (QWidget *parent = nullptr);
    std::string getName() {return nameOfPlayer;}
    int getCheckPoint() {return checkPointMarker;}
    int getSection() {return sectionMarker;}

private slots:
    void OnStartButton();

private:
    QLabel *title;
    QLabel *lbl;
    QTextEdit *name;
    QPushButton *startBtn;
    std::string nameOfPlayer;
    int sectionMarker;
    int checkPointMarker;
};