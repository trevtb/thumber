#include "thumbcreator.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    
    ThumbCreator creator;
    creator.start();

    return a.exec();
} //endfunction main
