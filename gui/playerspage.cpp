#include "playerspage.h"
#include "ui_playerspage.h"

PlayersPage::PlayersPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::PlayersPage)
{
	ui->setupUi(this);
}

PlayersPage::~PlayersPage()
{
	delete ui;
}
