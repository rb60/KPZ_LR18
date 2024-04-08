#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "codeedit.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void makeMemento();
    void undo();
    void redo();

private:
    bool programSetting = false;
    QList<Memento> history;
    int historyPos = -1;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
