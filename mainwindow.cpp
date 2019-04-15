#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    history_string.clear();
    ui->mazeFilePathEdit->setReadOnly(true);
    ui->actionHistory->setReadOnly(true);
    maze_paint = new MazePainter();
    maze_paint->init(&scene);
    ui->graphicsView->setScene(&scene);
}

void MainWindow::on_mazeFileLoadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text File (*.txt);;"));

    if ( !fileName.isEmpty() ){
        QFile file(fileName);
        if ( !file.open(QIODevice::ReadOnly)){
            QMessageBox::critical(this, tr("Error"), tr("This System could not open File"));
            return;
        }
        QFileInfo fileInfo(file);

        ui->mazeFilePathEdit->setText(fileInfo.absoluteFilePath());

        QTextStream stream(&file);

        QDateTime dt = QDateTime::currentDateTime();

        history_string += dt.toString("yyyy/MM/dd");
        history_string += dt.toString(" hh:mm:ss\n");
        history_string += "file load\n" + fileInfo.fileName() + "\n";

        ui->actionHistory->setText(history_string);

        file.close();
    }
}



void MainWindow::on_pushButton_clicked()
{
    maze_paint->draw(&scene);
    ui->graphicsView->setScene(&scene);
}
