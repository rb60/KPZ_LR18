#include "codeedit.h"

CodeEdit::CodeEdit(QWidget *parent)
    : QPlainTextEdit(parent)
{}

Memento CodeEdit::createMemento()
{
    return Memento(textCursor().position(), toPlainText());
}

void CodeEdit::restore(Memento m)
{
    QTextCursor c = textCursor();
    c.setPosition(m.getPosition());
    setTextCursor(c);
    setPlainText(m.getText());
}

int Memento::getPosition() const
{
    return position;
}

QString Memento::getText() const
{
    return text;
}

Memento::Memento(int position, const QString &text) : position(position),
    text(text)
{}
