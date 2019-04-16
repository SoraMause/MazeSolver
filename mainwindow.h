#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

#include "mazepainter.h"
#include "mazesimulator.h"

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

    void on_drawMaze_clicked();

    void on_start_clicked();



    void on_quitButton_clicked();

private:
    void init();

    void writeHistoryDate(  QString str_data );

    Ui::MainWindow *ui;

    QGraphicsScene scene;

    QString history_string;

    MazeSimulator *simulator;

};

#endif // MAINWINDOW_H
