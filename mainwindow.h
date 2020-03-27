#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "drawmap.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Create_obstacle_clicked();

    void on_BReset_clicked();

private:
    DrawBlock *Block;
    QGraphicsScene *Map;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
