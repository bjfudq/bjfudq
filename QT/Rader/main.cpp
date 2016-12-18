#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // 设置窗口背景颜色
    QPalette p = w.palette();
    p.setColor(QPalette::Window, QColor(0, 0, 0));
    w.setPalette(p);

    w.show();
    return a.exec();
}
