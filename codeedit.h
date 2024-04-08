#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QPlainTextEdit>

class Memento
{
private:
    int position;
    QString text;
public:
    Memento(int position, const QString &text);
    int getPosition() const;
    QString getText() const;
};

class CodeEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    CodeEdit(QWidget* parent = nullptr);
    Memento createMemento();
    void restore(Memento m);
};

#endif // CODEEDIT_H
