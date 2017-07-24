#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionExit_triggered();
    void on_actionSave_triggered();
    void on_actionSave_as_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionSelect_all_triggered();
    void on_actionUndo_action_triggered();
    void on_actionAbout_program_triggered();
    void on_actionHelp_triggered();

private:
    QString pathFile;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
