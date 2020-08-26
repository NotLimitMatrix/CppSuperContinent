#include "SizeManager.h"

#include<QDesktopWidget>
#include<QApplication>


SizeManager::SizeManager()
{
    QDesktopWidget *desktop = QApplication::desktop();
    width = desktop->width() - 10;
    height = desktop->height() - 100;

    panel_width = (width - height) / 3;
    zoning_square = panel_width * 2 - 2 * dx;
}

QRect SizeManager::getWorldSquare()
{
    return QRect(dx, dx, height, height);
}

QRect SizeManager::getZoningSquare()
{
    return QRect(dx + height, dx, zoning_square, zoning_square);
}

QRect SizeManager::getPanelSquare()
{
    return QRect(dx + height + zoning_square, dx, panel_width, zoning_square);
}

QRect SizeManager::getMessageSquare()
{
    return QRect(dx + height, dx + zoning_square, panel_width * 3 - 60, height - zoning_square);
}
