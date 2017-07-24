#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "helper.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pathFile = "";

    ui->plainTextEdit->addAction(ui->actionPaste);
    ui->plainTextEdit->addAction(ui->actionCopy);
    ui->plainTextEdit->addAction(ui->actionCut);
    ui->plainTextEdit->setContextMenuPolicy(Qt::ActionsContextMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setEnabled(true);
}

void MainWindow::on_actionOpen_triggered()
{
    pathFile = QFileDialog::getOpenFileName(this, "Open the file", "",
                                            "Txt files (*.txt);;All files (*.*)");

    if(pathFile.isEmpty()) {
        QMessageBox::warning(this, "", "Please select the file !");
        return;
    }

    QFile file(pathFile);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "", " The file hasn't been opened !");
        return;
    }

    if(!ui->plainTextEdit->isEnabled())
        ui->plainTextEdit->setEnabled(true);

    QTextStream str(&file);
    ui->plainTextEdit->setPlainText(str.readAll());
    file.close();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::exit();
}

void MainWindow::on_actionSave_triggered()
{
    if(pathFile.isEmpty())
    {
        on_actionSave_as_triggered();
        return;
    }

    if(!ui->plainTextEdit->isEnabled())
        return;

    QFile file(pathFile);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "", " The file hasn't been created !");
        return;
    }

    QTextStream str(&file);
    str << ui->plainTextEdit->toPlainText();
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;

    pathFile = QFileDialog::getSaveFileName(this, "Save to file", "",
                                            "Txt files (*.txt)");

    QFile file(pathFile);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "", " The file hasn't been created !");
        return;
    }

    QTextStream str(&file);
    str << ui->plainTextEdit->toPlainText();
    file.flush();
    file.close();
}

void MainWindow::on_actionPaste_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;
    ui->plainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;
    ui->plainTextEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;
    ui->plainTextEdit->copy();
}

void MainWindow::on_actionSelect_all_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;
    ui->plainTextEdit->selectAll();
}

void MainWindow::on_actionUndo_action_triggered()
{
    if(!ui->plainTextEdit->isEnabled())
        return;
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionAbout_program_triggered()
{
    QMessageBox::information(this, "Simple Text Editor", "This is simple text editor.");
}

void MainWindow::on_actionHelp_triggered()
{
    Helper *h = new Helper(":/doc/", "index.htm");
    h->show();
}
