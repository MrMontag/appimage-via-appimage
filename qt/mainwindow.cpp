/*
 * This file is part of the GAMS Studio project.
 *
 * Copyright (c) 2020 Alexander Fust
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
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
