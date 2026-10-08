#include "gui/pages/players/menuplayers.h"
#include "gui/pages/players/ui_menuplayers.h"

#include "./includes/class/Player.hpp"

/****************************************************************************************************/
/*	CONSTRUCTOR																						*/
/****************************************************************************************************/

MenuPlayers::MenuPlayers(QWidget *parent): QWidget(parent), ui(std::make_unique<Ui::MenuPlayers>())
{
	this->ui->setupUi(this);
	//this->playerManager = std::make_unique<PlayerManager>(settings);

	initMenuPlayers();
	connectMenuPlayers();
}

MenuPlayers::~MenuPlayers() = default;

/****************************************************************************************************/
/*	SETTER																							*/
/****************************************************************************************************/

void		MenuPlayers::setActiveAddPlayerBtn(bool value)			{	this->ui->AddPlayerBtn->setEnabled(value);			}
void		MenuPlayers::setActiveModifyPlayerBtn(bool value)		{	this->ui->ModifyPlayerBtn->setEnabled(value);		}
void		MenuPlayers::setActiveDeletePlayerBtn(bool value)		{	this->ui->DeletePlayerBtn->setEnabled(value);		}
void		MenuPlayers::setActiveImportPlayersBtn(bool value)		{	this->ui->ImportPlayersBtn->setEnabled(value);		}
void		MenuPlayers::setActiveExportPlayersBtn(bool value)		{	this->ui->ExportPlayersBtn->setEnabled(value);		}
void		MenuPlayers::setActiveShowPlayerBtn(bool value)			{	this->ui->ShowPlayerBtn->setEnabled(value);			}
void		MenuPlayers::setActiveShowPlayersListBtn(bool value)	{	this->ui->ShowPlayersListBtn->setEnabled(value);	}
void		MenuPlayers::setActiveLaunchTournamentBtn(bool value)	{	this->ui->LaunchTournamentBtn->setEnabled(value);	}

/****************************************************************************************************/
/*	PRIVATE METHODES																				*/
/****************************************************************************************************/

void		MenuPlayers::initMenuPlayers()
{
	this->ui->AddPlayerBtn->setEnabled(true);
	this->ui->ModifyPlayerBtn->setEnabled(false);
	this->ui->DeletePlayerBtn->setEnabled(false);
	this->ui->ImportPlayersBtn->setEnabled(true);
	this->ui->ExportPlayersBtn->setEnabled(false);
	this->ui->ShowPlayerBtn->setEnabled(false);
	this->ui->ShowPlayersListBtn->setEnabled(false);
	this->ui->LaunchTournamentBtn->setEnabled(false);
}

/****************************************************************************************************/
/*	SIGNAUX																							*/
/****************************************************************************************************/

/**
 * Connection des signaux pour rendu dynamique
 */
void		MenuPlayers::connectMenuPlayers()
{
	connect(this->ui->AddPlayerBtn,			&QPushButton::clicked, this, &MenuPlayers::onAddPlayer);
	connect(this->ui->ModifyPlayerBtn,		&QPushButton::clicked, this, &MenuPlayers::onModifyPlayer);
	connect(this->ui->DeletePlayerBtn,		&QPushButton::clicked, this, &MenuPlayers::onDeletePlayer);
	connect(this->ui->ImportPlayersBtn,		&QPushButton::clicked, this, &MenuPlayers::onImportPlayers);
	connect(this->ui->ExportPlayersBtn,		&QPushButton::clicked, this, &MenuPlayers::onExportPlayers);
	connect(this->ui->ShowPlayerBtn,		&QPushButton::clicked, this, &MenuPlayers::onShowPlayer);
	connect(this->ui->ShowPlayersListBtn,	&QPushButton::clicked, this, &MenuPlayers::onShowPlayersList);
	connect(this->ui->LaunchTournamentBtn,	&QPushButton::clicked, this, &MenuPlayers::onLaunchTournament);
}


/****************************************************************************************************/
/*	EVENTS																							*/
/****************************************************************************************************/


/****************************************************************************************************/
/*	PUBLIC METHODES																					*/
/****************************************************************************************************/