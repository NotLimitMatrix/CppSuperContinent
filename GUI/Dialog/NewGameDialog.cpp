#include "NewGameDialog.h"

NewGameDialog::NewGameDialog()
{
    setWindowTitle(title);
    submit->setText("开始");
    QObject::connect(submit, &QPushButton::clicked, this, &NewGameDialog::pushButtonSubmit);

    setUi();
}

void NewGameDialog::setUi()
{
    QFormLayout *layout = new QFormLayout(this);

    layout->addRow(QString("帝国名称"), nickname);
    layout->addRow(QString("服务器IP"), host);
    layout->addRow(QString("服务器端口"), port);
    layout->addRow(QString(""), submit);
}

void NewGameDialog::pushButtonSubmit()
{
    close();
}
