#include "form.h"
#include "ui_form.h"
QDir dir;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    watcher = new QFileSystemWatcher;
    watcher->addPath( "D:/WorkSpace/CodeTest/FileSystemWatcher_test/tmp");

    connect( watcher, SIGNAL(directoryChanged(QString)), this, SLOT(onChanged(QString)));


    dir.setFilter(QDir::Files);//设置过滤器
    dir.setNameFilters(QStringList()<<"*.txt");//设置文件名过滤
    this->onChanged("");
}

Form::~Form()
{
    delete ui;
}

void Form::onChanged(QString str)
{
    dir.setPath( str );
    ui->listWidget->clear();
    ui->listWidget->addItems( dir.entryList() );
    ui->listWidget->addItem( "00123.txt");
    ui->listWidget->addItem( "00124.txt");
    ui->listWidget->addItem( "00125.txt");
    ui->listWidget->addItem( "01123.txt");
    ui->listWidget->addItem( "001.txt");

    ui->listWidget->setCurrentItem( ui->listWidget->findItems("1", Qt::MatchContains).at(0) );
}
