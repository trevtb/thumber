#ifndef THUMBCREATOR_H
#define THUMBCREATOR_H

#include <QObject>
#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include <QDir>
#include <QImage>
#include <QFuture>
#include <QFutureWatcher>
#include <QThread>
#include <QImageReader>
#include <ImageMagick/Magick++.h>
#include <QThread>
#include <QtConcurrent/QtConcurrentMap>
#include <QtConcurrent/QtConcurrentRun>

class ThumbCreator : public QObject {
    Q_OBJECT
public:
    explicit ThumbCreator(QObject *parent = 0);

private:
     static QTextStream qout;

public slots:
    void start();
    void printMsg(const char* msg);
    const std::string currentDateTime();
}; //endclass ThumbCreator

#endif // THUMBCREATOR_H
