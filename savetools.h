#ifndef SAVETOOLS_H
#define SAVETOOLS_H

#include <QTextStream>
#include <QFile>
#include <QString>
#include <QVector>
#include <QDir>

//car je n'arrive pas à me servir des QFiles

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void saveFile(QVector <QString> aSauver, QString path);
QVector <QString> getFile (QString path);

bool toBool(QString newBool);
QString convertNormalPathIntoProtected(QString path);
QVector<QString> cutToEndMark(QVector <QString> toCutQVector, QString endMark);
#endif // SAVETOOLS_H
