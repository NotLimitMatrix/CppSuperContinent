#include "JsonParser.h"
#include <QMessageBox>
JsonParser::JsonParser()
{
    
}

JsonParser::JsonParser(QString jPath)
{
    QFile file(jPath);
    file.open(QIODevice::ReadOnly, QIODevice::Text);
    QString valueTemp = file.readAll();
    file.close();
    QJsonParseError parserError;
    QJsonDocument document = QJsonDocument::fromJson(valueTemp.toUtf8(), &parserError);
    if (parserError.error != QJsonParseError::NoError) {
        QMessageBox::about(NULL, "提示", "打开文件错误");
    }
    jsonObject = document.object();
}
