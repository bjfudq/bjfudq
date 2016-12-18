#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "qwindowdefs.h"
#include <time.h>
#include <stdlib.h>
#include <QtCore>
#include <math.h>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 添加定时器
    QTimer *timer=new QTimer(this);  //创建一个定时器
    connect(timer,SIGNAL(timeout()),this,SLOT(timerupdate()));  //关联定时器计满信号和响应的槽函数
    timer->start(1000);  //定时器开始，并设置定时触发槽函数的时间
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);

    // 反走样
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 设置画笔颜色
    painter.setPen(QColor(255, 0, 0));

    // (px, py) 记录中心点坐标，len 记录线段长度
    int px = width() / 2, py = height() / 2, len = width() / 4;

    // 绘制从中心出发的四条直线
    painter.drawLine(QPointF(px, py), QPointF(px, py - len));
    painter.drawLine(QPointF(px, py), QPointF(px, py + len));
    painter.drawLine(QPointF(px, py), QPointF(px + len, py));
    painter.drawLine(QPointF(px, py), QPointF(px - len, py));

    // 绘制同心圆
    painter.drawEllipse(QPoint(px, py), len / 3, len / 3);
    painter.drawEllipse(QPoint(px, py), len / 3 * 2, len / 3 * 2);
    painter.drawEllipse(QPoint(px, py), len, len);

    // 随机生成一个点 S，画一条从中心点到点 S 的红色虚线
    QPen pen(Qt::red, 2, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);  // 设置画笔属性（宽度+颜色等）
    int x = rand() % len, y = rand() % len;
    int sx = rand() % 2, sy = rand() % 2;
    if (sx == 0) x = -x;
    if (sy == 0) y = -y;
    int nx = px + x, ny = py + y;  // 新坐标

    //qDebug() << x << " " << -y << endl;

    painter.setBrush(Qt::red);
    painter.drawRect(nx - 5, ny - 5, 10, 10);
    painter.setPen(pen);
    painter.drawLine(QPointF(px, py), QPointF(nx, ny));

    // 显示系统时间
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    ui->label->setText(str);

    // 计算距离和角度
    double dis = sqrt(x * x + y * y);
    double ang = atan(-y * 1.0 / x) * 180 / acos(-1.0);
    if (ang > 0 && x < 0 && -y < 0) ang = -1 * (180 - ang);
    if (ang < 0 && x < 0 && -y > 0) ang = 180 + ang;

    // 输出距离和角度信息
    painter.drawText(50, 50, "X: " + QString::number(x,10 ,4));
    painter.drawText(50, 100, "Y: " + QString::number(-y,10 ,4));
    painter.drawText(50, 150, "Distance: " + QString::number(dis, 10, 4));
    painter.drawText(50, 200, "Angle: " + QString::number(ang, 10, 4));
}

void MainWindow::timerupdate() {
    update();
}
