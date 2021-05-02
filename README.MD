## Installation instructions

First download the repository and cd into base folder.
Make sure you have Qt installed for your system.

Run the following code to make the QT project
 > qmake -project

This line should create a "ChooseAdv.pro" file in the base directory... Open it and add the following line at the bottom:

```QT += widgets```

At this point, head to terminal and run the following lines: 
> qmake && make

Finally, the executable is made and ready to be run using : ```./ChooseAdv```