#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

    // 添加定时器
private slots:
    void timerupdate();
private:
    Ui::MainWindow *ui;
    QTimer *time;
};

#endif // MAINWINDOW_H
