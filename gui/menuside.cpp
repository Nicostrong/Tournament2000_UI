#include "gui/menuside.h"
#include "gui/ui_menuside.h"

#include <QPushButton>

/****************************************************************************************************/
/*	CONSTRUCTOR																						*/
/****************************************************************************************************/

MenuSide::MenuSide(QWidget *parent): QWidget(parent), ui(std::make_unique<Ui::MenuSide>())
{
	this->ui->setupUi(this);

	initMenuSide();
	connectMenuSide();

}

MenuSide::~MenuSide() = default;

/****************************************************************************************************/
/*	SETTER																							*/
/****************************************************************************************************/

void		MenuSide::setActiveSettingsBtn(bool value)	{	this->ui->SettingsBtn->setEnabled(value);	}
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

/****************************************************************************************************/
/*	PRIVATE METHODES																				*/
/****************************************************************************************************/

void		MenuSide::initMenuSide()
{
	this->ui->SettingsBtn->setEnabled(true);
	this->ui->PlayersBtn->setEnabled(false);
	this->ui->TeamsBtn->setEnabled(false);
	this->ui->PoolsBtn->setEnabled(false);
	this->ui->SixteenthBtn->setEnabled(false);
	this->ui->EighthBtn->setEnabled(false);
	this->ui->QuarterBtn->setEnabled(false);
	this->ui->SemiBtn->setEnabled(false);
	this->ui->ThirdBtn->setEnabled(false);
	this->ui->FinalBtn->setEnabled(false);
	this->ui->ExportBtn->setEnabled(false);
	this->ui->ShowBtn->setEnabled(false);
	this->ui->QuitBtn->setEnabled(true);
}

/****************************************************************************************************/
/*	SIGNAUX																							*/
/****************************************************************************************************/

void		MenuSide::connectMenuSide()
{
	connect(this->ui->SettingsBtn, &QPushButton::clicked, this, &MenuSide::goToSettings);
	connect(this->ui->PlayersBtn, &QPushButton::clicked, this, &MenuSide::goToPlayers);
	connect(this->ui->TeamsBtn, &QPushButton::clicked, this, &MenuSide::goToTeams);
	connect(this->ui->PoolsBtn, &QPushButton::clicked, this, &MenuSide::goToPools);
	connect(this->ui->SixteenthBtn, &QPushButton::clicked, this, &MenuSide::goToSixteenth);
	connect(this->ui->EighthBtn, &QPushButton::clicked, this, &MenuSide::goToEighth);
	connect(this->ui->QuarterBtn, &QPushButton::clicked, this, &MenuSide::goToQuarter);
	connect(this->ui->SemiBtn, &QPushButton::clicked, this, &MenuSide::goToSemi);
	connect(this->ui->ThirdBtn, &QPushButton::clicked, this, &MenuSide::goToThird);
	connect(this->ui->FinalBtn, &QPushButton::clicked, this, &MenuSide::goToFinal);
	connect(this->ui->ExportBtn, &QPushButton::clicked, this, &MenuSide::goToExport);
	connect(this->ui->ShowBtn, &QPushButton::clicked, this, &MenuSide::goToShow);
	connect(this->ui->QuitBtn, &QPushButton::clicked, this, &MenuSide::goToQuit);
}

/****************************************************************************************************/
/*	EVENTS																							*/
/****************************************************************************************************/

/****************************************************************************************************/
/*	PUBLIC METHODES																					*/
/****************************************************************************************************/

