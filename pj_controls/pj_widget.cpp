#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>
#include <QtGui/QEnterEvent>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

pj_widget::pj_widget(QWidget *parent)
    : QWidget(parent)
{
    //QMessageBox::information(this, u8"提示", u8"这是一个消息框");
    //QWidget* xParent = (QWidget*)this->parent();
    //if (xParent)
    //{
    //    uchar* xData = NEW uchar[xParent->width()* xParent->height() * sizeof(DWORD)];
    //    QImage* xImage = NEW QImage(xData, xParent->width(), xParent->height(), QImage::Format::Format_ARGB32);
    //    QPainter xQPainter(xImage);
    //    xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
    //    QPalette* palette = NEW QPalette();
    //    palette->setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
    //    xParent->setPalette(*palette);
    //}
    //QMessageBox::information(this, u8"提示", u8"构造");
}



void pj_widget::showEvent(QShowEvent *event)
{
    QPainter xThisQPainter(this);
    QImage::Format::Format_ARGB32;
    if (m_backTextureInfo.resKey == 0)
    {
        if (!g_pjResManager.pjLoadFile(u8R"(D:\gires3.wdf)", 100))
        {
            return;
        }

        uint64_t tempKey = (((uint64_t)100) << 32) + 578293861;

        std::vector<QBuffer*> xListTexStream;
        if (!g_pjResManager.pjGetWasTextures(tempKey, m_backTextureInfo, xListTexStream))
        {
            xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"读取资源失败");
            return;
        }

        if (xListTexStream.size() == 1)
        {
            QImage* xImage = NEW QImage((uchar*)xListTexStream[0]->buffer().data_ptr(), m_backTextureInfo.width, m_backTextureInfo.height, QImage::Format::Format_ARGB32);
            QWidget* xParent = this->parentWidget()->parentWidget();
            if (xParent)
            {
                xParent->setMinimumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));
                xParent->setMaximumSize(QSize(m_backTextureInfo.width, m_backTextureInfo.height));

                QPainter xQPainter(xImage);
                xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
                QPalette* palette = NEW QPalette();
                palette->setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
                xParent->setPalette(*palette);
                return;
            }
        }
        m_backTextureInfo.resKey = tempKey;
    }
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
