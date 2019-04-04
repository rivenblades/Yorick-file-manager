#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>
#include <QDebug>
#include <QDir>

#include <QDirIterator>
#include <QGraphicsItem>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDir myDir("/home/kostas/Documents/cpp/");
    QStringList allFiles = myDir.entryList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);//(QDir::Filter::Files,QDir::SortFlag::NoSort)


    qDebug()<<allFiles;
    int index = 0;
//    for (auto file : allFiles){
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


//QTreeWidgetItem *item1;
    QPixmap thumbnail("/home/kostas/Documents/Qt-projects/Yorick-File_Manager/folder_icon.png");
    thumbnail.scaledToWidth(25);
    thumbnail.scaledToHeight(25);
    ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
       QStringList list1 = myDir.entryList(QDir::AllEntries);
       for (int i = 0; i < list1.size(); i++)
       {
           qDebug() << "Filename " << i << " = " << myDir.filePath(list1.at(i));
           QTreeWidgetItem *item = new QTreeWidgetItem();
           QTableWidgetItem *t_item = new QTableWidgetItem();
           if (index % 2 == 0){
               item->setBackgroundColor(0,QColor(30,30,30));
               t_item->setBackgroundColor(QColor(30,30,30));
           }else{
               item->setBackgroundColor(0,QColor(80,80,80));
               t_item->setBackgroundColor(QColor(80,80,80));
           }
           item->setTextColor(0,Qt::white);

            item->setIcon(0,QIcon(":/folder_icon.png"));
           ui->treeWidget->insertTopLevelItem(index,item);
            //connect(this,SIGNAL(QTreeWidgetItem::itemClicked(item,0)),this,SLOT(this->folder_clicked(myDir.filePath(list1.at(i)))));
            item->setWhatsThis(0,myDir.path());
            item->setText(0,list1.at(i));




            t_item->setTextColor(Qt::white);
            t_item->setText(list1.at(i));
             t_item->setIcon(QIcon(":/folder_icon.png"));
            t_item->setWhatsThis(myDir.path());
            ui->tableWidget->insertRow(ui->tableWidget->rowCount());

             ui->tableWidget->setItem(index,0,t_item);
             //connect(this,SIGNAL(QTreeWidgetItem::itemClicked(item,0)),this,SLOT(this->folder_clicked(myDir.filePath(list1.at(i)))));


           index++;
//item1=item;
       }
       QGraphicsItem *g_item = new GraphicsFolderItem();
      scene->addItem(g_item);
      setWindowTitle("Yorick-File Manager");
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem *,int)),this,SLOT(folder_clicked(QTreeWidgetItem *,int)));
    connect(ui->tableWidget,SIGNAL(itemClicked(QTableWidgetItem *)),this,SLOT(folder_clicked(QTableWidgetItem *)));
      //QString rootDir = dirModel->filePath( myDir );


    //##TODO
    //REMOVE treeWidget
    setCentralWidget(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::folder_clicked(QTreeWidgetItem *item,int c){
    QString name = item->text(c);
    QDir myDir(item->whatsThis(c)+"/"+ name);
    qDebug()<<name;
int index = 0;
  qDebug()<<c;
//ui->treeWidget->clear();
ui->treeWidget->setColumnCount(ui->treeWidget->columnCount() + 1);
    QStringList list1 = myDir.entryList( QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
    for (int i = 0; i < list1.size(); i++)
    {
        qDebug() << "Filename " << i << " = " << myDir.filePath(list1.at(i));
        QTreeWidgetItem *item = new QTreeWidgetItem();
        /*if (index % 2 == 0){
            item->setBackgroundColor(c,QColor(30,30,30));
        }else{
            item->setBackgroundColor(c,QColor(80,80,80));

        }
        item->setWhatsThis(c,myDir.path()+"/");
        item->setTextColor(c,Qt::white);*/
        item->setText(c+1,myDir.path()+"/"+list1.at(i));
        item->setBackgroundColor(c+1,(index)%2==0?QColor(30,30,30):QColor(80,80,80));
         //item->setIcon(0,QIcon(":/folder_icon.png"));
//ui->treeWidget->insertTopLevelItem(c,item);
//         ui->treeWidget->insertTopLevelItem(c+1,item);
        ui->treeWidget->insertTopLevelItem(index,item);
        //ui->treeWidget->addActions()

         //connect(this,SIGNAL(QTreeWidgetItem::itemClicked(item,0)),this,SLOT(this->folder_clicked(myDir.filePath(list1.at(i)))));
        item->setTextColor(c+1,Qt::white);

        //item->setText(c,list1.at(i));
        index++;
//item1=item;
    }

}

void MainWindow::folder_clicked(QTableWidgetItem *item){
    QString name = item->text();
    QDir myDir(item->whatsThis()+"/"+ name);
    qDebug()<<name;
int index = 0;

//ui->treeWidget->clear();
ui->tableWidget->insertColumn(ui->tableWidget->columnCount());
    QStringList list1 = myDir.entryList( QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst);
    for (int i = 0; i < list1.size(); i++)
    {
        qDebug() << "Filename " << i << " = " << myDir.filePath(list1.at(i));
        QTableWidgetItem *item = new QTableWidgetItem();
        if (index % 2 == 0){
            item->setBackgroundColor(QColor(30,30,30));
        }else{
            item->setBackgroundColor(QColor(80,80,80));

        }
        item->setWhatsThis(myDir.path());
        item->setTextColor(Qt::white);
        item->setText(list1.at(i));
        item->setBackgroundColor((index)%2==0?QColor(30,30,30):QColor(80,80,80));
         //item->setIcon(0,QIcon(":/folder_icon.png"));
//ui->treeWidget->insertTopLevelItem(c,item);
//         ui->treeWidget->insertTopLevelItem(c+1,item);

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(index,ui->tableWidget->currentColumn()+1, item);
        //ui->treeWidget->addActions()

         //connect(this,SIGNAL(QTreeWidgetItem::itemClicked(item,0)),this,SLOT(this->folder_clicked(myDir.filePath(list1.at(i)))));


        //item->setText(c,list1.at(i));
        index++;
//item1=item;
    }

}

void itemClicked(QTreeWidgetItem *,int){
    qDebug()<<"clicked()";

}
