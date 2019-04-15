#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

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

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    QString history_string;
};

#endif // MAINWINDOW_H
