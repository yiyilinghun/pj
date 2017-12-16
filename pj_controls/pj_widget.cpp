#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>
#include <QtGui/QEnterEvent>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

pj_widget::pj_widget(QWidget *parent)
    : QWidget(parent)
{
    if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
    {
        return;
    }

    uint64_t tempKey = (((uint64_t)100) << 32) + 578293861;
    QVector<QImage*> imageVector;
    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
    {
        return;
    }

    if (imageVector.size() == 1)
    {
        QImage* xImage = imageVector[0];
        QWidget* xParent = this->parentWidget()->parentWidget();
        if (xParent)
        {
            xParent->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
            xParent->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));

            QPainter xQPainter(xImage);
            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
            QPalette palette;
            palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
            xParent->setPalette(palette);
            return;
        }
    }
}



void pj_widget::showEvent(QShowEvent *event)
{
    //QPainter xThisQPainter(this);
    //QImage::Format::Format_ARGB32;
    //if (m_backTextureInfo.resKey == 0)
    //{
    //    if (!pj_GetResManager().pjLoadFile(u8R"(A:\git\pj\res\gires3.wdf)", 100))
    //    {
    //        return;
    //    }

    //    uint64_t tempKey = (((uint64_t)100) << 32) + 578293861;

    //    QVector<QImage*> imageVector;
    //    if (!pj_GetResManager().pjGetWasTextures(tempKey, m_backTextureInfo, imageVector))
    //    {
    //        xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"读取资源失败");
    //        return;
    //    }

    //    if (imageVector.size() == 1)
    //    {
    //        QImage* xImage = imageVector[0];
    //        QWidget* xParent = this->parentWidget()->parentWidget();
    //        if (xParent)
    //        {
    //            xParent->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
    //            xParent->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));

    //            QPainter xQPainter(xImage);
    //            xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
    //            QPalette palette;
    //            palette.setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
    //            xParent->setPalette(palette);
    //            return;
    //        }
    //    }
    //    m_backTextureInfo.resKey = tempKey;
    //}
}

void
pj_widget::keyPressEvent(QKeyEvent *event)
{
}

void
pj_widget::paintEvent(QPaintEvent *event)
{
    ;
}


void
pj_widget::closeEvent(QCloseEvent *event)
{
    QWidget* xParent = this->parentWidget()->parentWidget();
    if (xParent)
    {
        xParent->setPalette(QPalette());
    }
}
