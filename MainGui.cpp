#include "MainGui.h"

MainGui::MainGui(QWidget *parent)
    : QMainWindow(parent)
{
//    QScreen *screen = QGuiApplication::primaryScreen();
//    QRect displayScreen = screen->availableGeometry();
//    resize(displayScreen.width(), displayScreen.height());
//    setMinimumSize(GUI_WIDTH, GUI_HEIGHT);
//    setMaximumSize(GUI_WIDTH, GUI_HEIGHT);

    setWindowTitle(GUI_TITLE);
    setWindowState(Qt::WindowMaximized);

    qDebug() << this->geometry();

    _displayText.push_back("暂无信息");
}

MainGui::~MainGui()
{
}

//void MainGui::paintEvent(QPaintEvent *event)
void MainGui::paintEvent(QPaintEvent *)
{
    QPainter *painter = new QPainter;
    painter->begin(this);

    _world->draw(painter);
    _zoning->draw(painter);
    _resource_panel->draw(painter);
    _power_panel->draw(painter);
    _research_panel->draw(painter);
    _text_browser->draw(painter, _displayText);

    painter->end();
}

void MainGui::mousePressEvent(QMouseEvent *event)
{
    Qt::MouseButtons b = event->buttons();
    int posX = event->x();
    int posY = event->y();

    display(posX, posY);

    if(b == Qt::LeftButton)
    {

    }

    update();
}

void MainGui::resizeEvent(QResizeEvent *event)
{
    sizeCollecter->setSquare(this->geometry().width(), this->geometry().height());
    qDebug() << this->geometry();
}

void MainGui::display(int px, int py)
{
    int idTemp;
    Block *bTemp = nullptr;
    ZSolt *zTemp = nullptr;

    _displayText.clear();
    _displayText.push_back(QString("Pos(%1,%2)").arg(px).arg(py));

    if(_world->inWorld(px, py))
    {
        idTemp = _world->getIdWithPos(px, py);
        bTemp = _world->getBlockWithId(idTemp);
        setZoning(bTemp->getZoning());
        bTemp->getDisplay(&_displayText);
        _displayText.push_back(QString("地图区域"));
    }

    if(_zoning->inZoning(px, py))
    {
        idTemp = _zoning->getIdWithPos(px, py);
        zTemp = _zoning->getSoltWithId(idTemp);
        zTemp->getDisplay(&_displayText);
        _displayText.push_back(QString("区划区域"));
    }

    if(_resource_panel->inResourcePanel(px, py))
    {
        _displayText.push_back(QString("资源面板"));
    }

    if(_power_panel->inPowerPanel(px, py))
    {
        _displayText.push_back(QString("综合实力面板"));
    }

    if(_research_panel->inResearchPanel(px, py))
    {
        _displayText.push_back(QString("科研面板"));
    }

    if(_text_browser->inTextBrowser(px, py))
    {
        _displayText.push_back(QString("消息面板"));
    }

}
