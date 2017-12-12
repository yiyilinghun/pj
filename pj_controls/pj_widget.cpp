#include "Precompiled.h"
#include "pj_widget.h"
#include <QtGui/QPainter>
#include <QtGui/QEnterEvent>
#include "pj_loader.h"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMessageBox>

pj_widget::pj_widget(QWidget *parent)
    : QWidget(parent)
{
    //QMessageBox::information(this, u8"提示", u8"这是一个消息框");
    //QWidget* xParent = (QWidget*)this->parent();
    //if (xParent)
    //{
    //    uchar* xData = new uchar[xParent->width()* xParent->height() * sizeof(DWORD)];
    //    QImage* xImage = new QImage(xData, xParent->width(), xParent->height(), QImage::Format::Format_ARGB32);
    //    QPainter xQPainter(xImage);
    //    xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
    //    QPalette* palette = new QPalette();
    //    palette->setBrush(QPalette::ColorRole::Background, QBrush(*xImage));
    //    xParent->setPalette(*palette);
    //}
    //QMessageBox::information(this, u8"提示", u8"构造");
}

uint32_t* g_data = nullptr;
QImage g_Image;
xyTextureInfo g_textureInfo;


void pj_widget::showEvent(QShowEvent *event)
{
    //case Qt::Key_Up:
    //QMessageBox::information(this, u8"0", u8"0");
    //if (event->key() == 'p')
    {
        //QMessageBox::information(this, u8"1", u8"1");

        QPainter xThisQPainter(this);
        QImage::Format::Format_ARGB32;
        if (g_data == nullptr)
        {
            if (!g_pjResManager.pjLoadFile(u8R"(D:\gires3.wdf)", 100))
            {
                return;
            }

            g_textureInfo.resKey = (((uint64_t)100) << 32) + 578293861;
            //g_textureInfo.wasKey = 2904516639;
            std::vector<QBuffer*> xListTexStream;
            if (!g_pjResManager.pjGetWasTextures(g_textureInfo, xListTexStream))
            {
                xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"读取资源失败");
                return;
            }

            if (xListTexStream.size() == 1)
            {
                //g_data = new uint32_t[100 * 100];
                //for (size_t i = 0; i < 100 * 100; i++)
                //{
                //    g_data[i] = 0xFFFF0000;
                //}
                //QMessageBox::information(this, u8"2", u8"2");
                g_Image = QImage((uchar*)xListTexStream[0]->buffer().data_ptr(), g_textureInfo.width, g_textureInfo.height, QImage::Format::Format_ARGB32);


                QPainter xThisQPainter(this);
                //xThisQPainter.drawImage(QPoint(0, 0), g_Image);
                //xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"aaaaaaaaaa");
                //xThisQPainter.drawImage(QPoint(0, 0), g_Image);

                //QWidget* xMainParent = nullptr;
                QWidget* xParent = this->parentWidget()->parentWidget();
                //QMessageBox::information(this, xParent->objectName(), typeid(xParent).name());
                //QMessageBox::information(this, xParent->parentWidget()->objectName(), typeid(xParent->parentWidget()).name());
                //QMessageBox::information(this, u8"3", u8"3");

                //QMessageBox::information(this, xParent->objectName(), xParent->objectName());
                //QMessageBox::information(this, xParent->parentWidget()->objectName(), xParent->parentWidget()->objectName());

                //if (xParent->parentWidget()->isWindowType())
                //{
                //    QMessageBox::information(this, u8"isWindowType", u8"isWindowType");
                //}
                ////do
                ////{
                ////    xParent = this->window();
                //    if (xParent) { xMainParent = xParent; }
                ////} while (xParent);

                if (xParent)
                {
                    xParent->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
                    xParent->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));
                    //xParent = (QWidget*)this->parent();
                    //if (xMainParent)
                    //{
                    //xMainParent->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
                    //xMainParent->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));

                    QPainter xQPainter(&g_Image);
                    xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
                    QPalette* palette = new QPalette();
                    palette->setBrush(QPalette::ColorRole::Background, QBrush(g_Image));
                    xParent->setPalette(*palette);
                    return;
                    //}
                }

            }
            g_data = (uint32_t*)1;
        }

        //char szBuff[1024];
        //sprintf(szBuff, "%d,%d", g_textureInfo.width, g_textureInfo.height);
        //this->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
        //this->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));

        //QMessageBox::information(this, u8"提示", u8"渲染");





        //do
        //{
        //    if (!g_data)
        //    {
        //        QWidget* xParent = (QWidget*)this->parent();
        //        if (xParent)
        //        {
        //            QWidget* xParent = (QWidget*)this->parent();
        //            if (xParent)
        //            {
        //                //xThisQPainter.drawText(QRect(100, 200, 100, 100), Qt::AlignCenter, xParent->objectName());
        //                QPainter xQPainter(&g_Image);
        //                xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
        //                QPalette* palette = new QPalette();
        //                palette->setBrush(QPalette::ColorRole::Background, QBrush(g_Image));
        //                xParent->setPalette(*palette);

        //                xParent->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
        //                xParent->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));
        //            }
        //        }
        //        else
        //        {
        //            break;
        //        }
        //    }
        //    else
        //    {
        //        break;
        //    }
        //    return;

        //} while (False);

        //xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"嗝屁了");

        //for (size_t i = 0; i < 100 * 100; i++)
        //{
        //    g_data[i] = 0xFF00FF00;
        //}
        //delete[] g_data;




        //xQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"widget");

        //if (is_first)
        //{
        //    delete[] g_data;
        //}

        //is_first = false;
    }
}

void
pj_widget::keyPressEvent(QKeyEvent *event)
{
}

void
pj_widget::paintEvent(QPaintEvent *event)
{
    //try
    //{
    //    QPainter xThisQPainter(this);
    //    //xThisQPainter.drawImage(QPoint(0, 0), g_Image);
    //    //xThisQPainter.drawText(QRect(0, 0, 100, 100), Qt::AlignCenter, u8"aaaaaaaaaa");
    //    //xThisQPainter.drawImage(QPoint(0, 0), g_Image);

    //    //QWidget* xMainParent = nullptr;
    //    QWidget* xParent = this->parentWidget();
    //    ////do
    //    ////{
    //    ////    xParent = this->window();
    //    //    if (xParent) { xMainParent = xParent; }
    //    ////} while (xParent);

    //    if (xParent)
    //    {
    //        xParent->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
    //        xParent->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));
    //        xParent = (QWidget*)this->parent();
    //        //if (xMainParent)
    //        //{
    //            //xMainParent->setMinimumSize(QSize(g_textureInfo.width, g_textureInfo.height));
    //            //xMainParent->setMaximumSize(QSize(g_textureInfo.width, g_textureInfo.height));

    //        QPainter xQPainter(&g_Image);
    //        xQPainter.drawText(QRect(10, 10, 300, 300), Qt::AlignCenter, u8"嗝屁了");
    //        QPalette* palette = new QPalette();
    //        palette->setBrush(QPalette::ColorRole::Background, QBrush(g_Image));
    //        xParent->setPalette(*palette);
    //        return;
    //        //}
    //    }
    //}
    //catch (...)
    //{
    //    QMessageBox::information(this, u8"提示", u8"这是一个异常消息框");
    //}
}

