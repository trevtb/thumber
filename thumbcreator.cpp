#include "thumbcreator.h"

ThumbCreator::ThumbCreator(QObject *parent) : QObject(parent) {
} //endconstructor

QTextStream ThumbCreator::qout(stdout, QIODevice::WriteOnly);

void ThumbCreator::printMsg(const char* msg) {
    qout << currentDateTime().c_str() << msg << endl;
} //endfunction printMsg

const std::string ThumbCreator::currentDateTime() {
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X: ", &tstruct);

    return buf;
} //endfunction currentDateTime

void createThumb(const QString &filename) {
    bool overwrite = true;

    ThumbCreator creat;
    QString msg("Creating Thumb: " + filename);
    creat.printMsg(msg.toStdString().c_str());

    QFile f(filename);
    if (f.size() < 30000) {
        creat.printMsg(QString("File " + filename + " is smaller than 30kb, deleting...").toStdString().c_str());
        QFile::remove(filename);
        return;
    } //endif

    QImageReader reader(filename);
    QImage img = reader.read();
    int w = img.width();
    int h = img.height();

    QImage target1;
    QImage target2;
    QImage target3;

    QString fname(filename);
    QStringList n1 = fname.split(".");
    fname = n1[0];

    if( ! QFile("../thumb_640" + fname + ".jpg").exists() || overwrite) {
        if (w > h) {
            target1 = img.scaledToWidth(640, Qt::SmoothTransformation);
        } else if (h > w) {
            target1 = img.scaledToHeight(640, Qt::SmoothTransformation);
        } else if (h == w) {
            target1 = img.scaled(640, 640, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        } //endif
        target1.save(QString("../thumb_640" + fname + ".jpg").toStdString().c_str(), "JPG", 100);
    } //endif

    if( ! QFile("../thumb_1024" + fname + ".jpg").exists() || overwrite) {
        if (w > h) {
            target2 = img.scaledToWidth(1024, Qt::SmoothTransformation);
        } else if (h > w) {
            target2 = img.scaledToHeight(1024, Qt::SmoothTransformation);
        } else if (h == w) {
            target2 = img.scaled(1024, 1024, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        } //endif
        target2.save(QString("../thumb_1024" + fname + ".jpg").toStdString().c_str(), "JPG", 100);
    } //endif

    if ( ! QFile("../thumb_150" + fname + ".jpg").exists() || overwrite) {
        target3 = img.scaledToHeight(150, Qt::SmoothTransformation);
        target3.save(QString("../thumb_150" + fname + ".jpg").toStdString().c_str(), "JPG", 100);
    } //endif
} //endfunction createThumb

void ThumbCreator::start() {
    int cores = QThread::idealThreadCount();
    bool multicore = true;
    if (cores < 2) {
        multicore = false;
        cores = 1;
    } else {
        QThreadPool::globalInstance()->setMaxThreadCount(cores);
    } //endif

    printMsg("############# THUMBNAIL GENERATOR v0.1 #############");
    printMsg("Starting weapons and defence systems...");
    if (multicore) {
        printMsg(QString("Multiple CPU cores detected: " + QString::number(cores)).toStdString().c_str());
        printMsg("We are going to utilize all of them for image rendering.");
    } else {
        printMsg("Single core CPU, running in small penis mode.");
    } //endif

    QDir myDir("./");
    myDir.setNameFilters(QStringList() << "*.jpg" << "*.jpeg" << "*.png" << "*.JPG" << "*.JPEG" << "*.PNG" << "*.tiff" << "*.TIFF" << "*.tif" << "*.TIF");
    QStringList dircontent = myDir.entryList();
    QList<QString> joblist;

    for (int i=0; i<dircontent.size(); i++) {
        QString filen = dircontent[i];
        bool isconf = filen.contains("_conf", Qt::CaseSensitive);
        bool isthumb = filen.contains("thumb_", Qt::CaseSensitive);

        if (!isconf && !isthumb && multicore) {
            joblist.append(filen);
        } else if (!isconf && !isthumb && !multicore) {
            createThumb(filen);
        } else if (isconf && isthumb) {
            printMsg(QString("STRANGE FILE DETECTED, DELETING: " + filen).toStdString().c_str());
            QFile::remove(filen);
        } //endif
    } //endfor

    if (multicore) {
        QFutureWatcher<void> mywatch;
        QFuture<void> proc = QtConcurrent::map(joblist, createThumb);
        mywatch.setFuture(proc);
        mywatch.waitForFinished();
    } //endif

    printMsg("Thumb generation complete, exiting.");
    exit(0);
} //endfunction start
