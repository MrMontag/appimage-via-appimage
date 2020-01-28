#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _proc(new QProcess(this))
{
    ui->setupUi(this);
    ui->webWidget->load(QUrl("http://www.qt.io/"));
}

MainWindow::~MainWindow()
{
    delete _proc;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->procEdit->text().isEmpty())
        return;

    _proc->setProgram(ui->procEdit->text());
    _proc->setArguments(ui->argEdit->text().split(" "));
    _proc->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    auto app = QFileDialog::getOpenFileName(this, "Select AppImage");
    ui->procEdit->setText(app);
}
