#include "qtIncludes.hpp"
#include "COASt.hpp"

class Starter : public QWidget {
    Q_OBJECT // must be used because we'll be building our own "slots"

public:
    Starter (QWidget *parent = nullptr);
    int confirmMessage(const std::string &); // opens a confirm dialogbox

private slots:
    void OnStartButton();

private:
    QLabel *title;
    QLabel *lbl;
    QTextEdit *name;
    QPushButton *startBtn;
};