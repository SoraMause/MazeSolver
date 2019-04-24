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
    delete simulator;
    delete ui;
}

void MainWindow::init()
{
    history_string.clear();
    ui->mazeFilePathEdit->setReadOnly(true);
    ui->actionHistory->setReadOnly(true);
    simulator = new MazeSimulator();
    simulator->maze_paint->init(&scene);
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setStyleSheet("background:#000000");
}

void MainWindow::writeHistoryDate( QString str_data )
{
    QDateTime dt = QDateTime::currentDateTime();

    history_string += dt.toString("yyyy/MM/dd");
    history_string += dt.toString(" hh:mm:ss\n");
    history_string += str_data;

    ui->actionHistory->setText(history_string);
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

        writeHistoryDate( "file load\n" + fileInfo.fileName() + "\n" );

        simulator->loadMaze(&stream, &scene);
        ui->graphicsView->setScene(&scene);

        file.close();
    }
}

void MainWindow::on_drawMaze_clicked()
{
    writeHistoryDate( "Draw Maze Data\n" );
    simulator->drawMaze(&scene);
    ui->graphicsView->setScene(&scene);
}

void MainWindow::on_start_clicked()
{
    writeHistoryDate("simulation start\n");
    simulator->run(&scene);
    ui->graphicsView->setScene(&scene);
    writeHistoryDate("simulation end\n");
}


void MainWindow::on_quitButton_clicked()
{
    qApp->quit();
}
