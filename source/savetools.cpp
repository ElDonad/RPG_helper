#include <savetools.h>

void saveFile(QVector<QString> aSauver, QString path)
{
    string pathString = path.toStdString();
    QVector <int> commentaires;
    vector <string> integrale;

    ifstream lecture (pathString.c_str());

    string currentLine;
    int getCount = 0;
    do
    {
        if (currentLine[0] == '/')
        {
            commentaires.push_back(getCount - 1);
        }
        if (getCount > 0)
        {
        integrale.push_back(currentLine);
        }
        getCount++;
    } while (getline(lecture, currentLine)); // On compte les lignes de commentaire
    lecture.close();

    //On écrit maintenant le fichier recu sans écrire sur les lignes de commentaire

    ofstream ecriture (pathString);

    int currentWriteLine = 0;
    int testWrite = 0;
    string line;
    QString lineQString;

    int writeLoop = 0;
    while (writeLoop < aSauver.size()) //boucle écriture
    {
        bool ecrire = true;
        int stopLoop = commentaires.size();
        int loop = 0;
        while (loop != stopLoop) // boucle vérification de commentaire
        {
            if (testWrite == commentaires[loop])
            {
                ecrire = false;
            }
            loop++;
        }

        if (ecrire == true)
        {
            lineQString = aSauver[currentWriteLine];
            line = lineQString.toStdString();
            ecriture<<line<<endl;
            writeLoop++;
            currentWriteLine++;
        }
        if (ecrire == false)
        {
            ecriture<<integrale[writeLoop]<<endl;
        }

        testWrite++;
    }

}

QVector <QString> getFile(QString path)
{
    string pathString = path.toStdString();
    ifstream fileGet (pathString.c_str());
    QVector <QString> returnQVector;

    int counter = 0;
    string line = "";
    QString lineQString = "";
    do
    {
        char first = line[0];
        if (counter > 0 && first != '/')
        {
            lineQString = QString::fromStdString(line);
            returnQVector.push_back(lineQString);
        }
        counter++;
    }while (getline(fileGet, line));

    return returnQVector;
}

bool toBool(QString newBool)
{
    if (newBool == "0" || newBool == "false")
    {
        return false;
    }
    if (newBool == "1" || newBool == "true")
    {
        return true;
    }
    else
    {
        return false;
    }
}

QString convertNormalPathIntoProtected(QString path)
{
    //QVector <int> slashs;
    int loop = 0;
    while (loop < path)
    {
        if (path[loop] == '/')
        {
            path.insert(loop, '/');

        }
        loop++;
    }
    return path;
}

QVector <QString> cutToEndMark(QVector <QString> toCutQVector,QString endMark)
{
    int toCut = 0;
    while (toCutQVector[toCut] != endMark || toCut != toCutQVector.count())
        toCut++;

    toCutQVector.remove(0,toCut);
    return toCutQVector;
}



