#include "gui/menuside.h"
#include "ui_menuside.h"

MenuSide::MenuSide(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MenuSide)
{
    ui->setupUi(this);
}

MenuSide::~MenuSide()
{
    delete ui;
}
