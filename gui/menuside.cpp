#include "gui/menuside.h"
#include "gui/ui_menuside.h"

#include <QPushButton>

MenuSide::MenuSide(QWidget *parent): QWidget(parent), ui(std::make_unique<Ui::MenuSide>())
{
    ui->setupUi(this);

	initMenuSide();

    connect(ui->SettingsBtn, &QPushButton::clicked, this, &MenuSide::goToSettings);
    connect(ui->PlayersBtn, &QPushButton::clicked, this, &MenuSide::goToPlayers);
    connect(ui->TeamsBtn, &QPushButton::clicked, this, &MenuSide::goToTeams);
    connect(ui->PoolsBtn, &QPushButton::clicked, this, &MenuSide::goToPools);
    connect(ui->SixteenthBtn, &QPushButton::clicked, this, &MenuSide::goToSixteenth);
    connect(ui->EighthBtn, &QPushButton::clicked, this, &MenuSide::goToEighth);
    connect(ui->QuarterBtn, &QPushButton::clicked, this, &MenuSide::goToQuarter);
    connect(ui->SemiBtn, &QPushButton::clicked, this, &MenuSide::goToSemi);
    connect(ui->ThirdBtn, &QPushButton::clicked, this, &MenuSide::goToThird);
    connect(ui->FinalBtn, &QPushButton::clicked, this, &MenuSide::goToFinal);
    connect(ui->ExportBtn, &QPushButton::clicked, this, &MenuSide::goToExport);
    connect(ui->ShowBtn, &QPushButton::clicked, this, &MenuSide::goToShow);
    connect(ui->QuitBtn, &QPushButton::clicked, this, &MenuSide::goToQuit);

}

MenuSide::~MenuSide() = default;


void		MenuSide::initMenuSide()
{
	ui->SettingsBtn->setEnabled(true);
	ui->PlayersBtn->setEnabled(false);
	ui->TeamsBtn->setEnabled(false);
	ui->PoolsBtn->setEnabled(false);
	ui->SixteenthBtn->setEnabled(false);
	ui->EighthBtn->setEnabled(false);
	ui->QuarterBtn->setEnabled(false);
	ui->SemiBtn->setEnabled(false);
	ui->ThirdBtn->setEnabled(false);
	ui->FinalBtn->setEnabled(false);
	ui->ExportBtn->setEnabled(false);
	ui->ShowBtn->setEnabled(false);
	ui->QuitBtn->setEnabled(true);
}

void		MenuSide::setActivePlayersBtn(bool value)	{	this->ui->PlayersBtn->setEnabled(value);	}
void		MenuSide::setActiveTeamsBtn(bool value)		{	this->ui->TeamsBtn->setEnabled(value);		}
void		MenuSide::setActivePoolsBtn(bool value)		{	this->ui->PoolsBtn->setEnabled(value);		}
void		MenuSide::setActiveSixteenthBtn(bool value)	{	this->ui->SixteenthBtn->setEnabled(value);	}
void		MenuSide::setActiveEighthBtn(bool value)	{	this->ui->EighthBtn->setEnabled(value);		}
void		MenuSide::setActiveQuarterBtn(bool value)	{	this->ui->QuarterBtn->setEnabled(value);	}
void		MenuSide::setActiveSemiBtn(bool value)		{	this->ui->SemiBtn->setEnabled(value);		}
void		MenuSide::setActiveThirdBtn(bool value)		{	this->ui->ThirdBtn->setEnabled(value);		}
void		MenuSide::setActiveFinalBtn(bool value)		{	this->ui->FinalBtn->setEnabled(value);		}
void		MenuSide::setActiveExportBtn(bool value)	{	this->ui->ExportBtn->setEnabled(value);		}
void		MenuSide::setActiveShowBtn(bool value)		{	this->ui->ShowBtn->setEnabled(value);		}