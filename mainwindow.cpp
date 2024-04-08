#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, &MainWindow::makeMemento);
    connect(ui->plainTextEdit, &QPlainTextEdit::cursorPositionChanged, this, &MainWindow::makeMemento);
    connect(ui->undoButton, &QPushButton::clicked, this, &MainWindow::undo);
    connect(ui->redoButton, &QPushButton::clicked, this, &MainWindow::redo);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeMemento()
{
    if(!programSetting)
    {
        if(historyPos < history.size() - 1)
        {
            history = history.sliced(0, historyPos + 1);
        }
        history.append( ((CodeEdit*)(ui->plainTextEdit))->createMemento() );
        historyPos++;
    }
}

void MainWindow::undo()
{
    if(historyPos > 0)
    {
        historyPos--;
        programSetting = true;
        ((CodeEdit*)(ui->plainTextEdit))->restore(history[historyPos]);
        programSetting = false;
    }
}

void MainWindow::redo()
{
    if(historyPos < history.size() - 1)
    {
        historyPos++;
        programSetting = true;
        ((CodeEdit*)(ui->plainTextEdit))->restore(history[historyPos]);
        programSetting = false;
    }
}
