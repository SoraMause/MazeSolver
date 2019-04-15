#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "mazepainter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_mazeFileLoadButton_clicked();

    void on_pushButton_clicked();

private:
    void init();

    void writeHistoryDate();

    Ui::MainWindow *ui;

    QGraphicsScene scene;

    QString history_string;

    MazePainter *maze_paint;


};

#endif // MAINWINDOW_H
