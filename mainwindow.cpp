#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "map.h"
#include "view.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    View *view = new View(&scene);
    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}
