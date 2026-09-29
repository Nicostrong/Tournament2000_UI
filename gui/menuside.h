#pragma once

#include <QWidget>

namespace   Ui
{
    class   MenuSide;
}

class   MenuSide : public QWidget
{
    Q_OBJECT

    public:

        explicit MenuSide(QWidget *parent = nullptr);
        ~MenuSide();

    private:

        Ui::MenuSide *ui;
};

