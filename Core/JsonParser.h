#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QFile>
#include <QJsonObject>
#include <QJsonParseError >
class JsonParser
{
    QString jsonPath;

public:
    QJsonObject jsonObject;
    JsonParser();
    JsonParser(QString jPath);
};

#endif // JSONPARSER_H
