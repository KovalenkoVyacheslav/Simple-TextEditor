#include "helper.h"
#include "ui_helper.h"

Helper::Helper(const QString& strPath,
               const QString& strFileName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Helper)
{
    ui->setupUi(this);

    connect(ui->prevButton, SIGNAL(clicked()),
            ui->textBrowser, SLOT(backward())
           );
    connect(ui->homeButton, SIGNAL(clicked()),
            ui->textBrowser, SLOT(home())
           );
    connect(ui->nextButton, SIGNAL(clicked()),
            ui->textBrowser, SLOT(forward())
           );
    connect(ui->textBrowser, SIGNAL(backwardAvailable(bool)),
            ui->prevButton, SLOT(setEnabled(bool))
           );
    connect(ui->textBrowser, SIGNAL(forwardAvailable(bool)),
            ui->nextButton, SLOT(setEnabled(bool))
           );

    ui->textBrowser->setSearchPaths(QStringList()  << strPath);
    ui->textBrowser->setSource(strFileName);
}

Helper::~Helper()
{
    delete ui;
}
