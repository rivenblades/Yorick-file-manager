#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphicsfolderitem.h>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

signals:
    void itemClicked(QTreeWidgetItem *,int);
    void itemClicked(QTableWidgetItem *);
private slots:
    void folder_clicked(QTreeWidgetItem *,int);
    void folder_clicked(QTableWidgetItem *);
};

#endif // MAINWINDOW_H
