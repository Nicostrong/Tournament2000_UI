#include "gui/mainwindow.h"
#include "gui/ui_mainwindow.h"

#include "gui/pages/settings/settingspage.h"

/****************************************************************************************************/
/*	CONSTRUCTOR																						*/
/****************************************************************************************************/

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);

	connectMenuSide();
	connectSettingsPage();


}

MainWindow::~MainWindow() = default;

/****************************************************************************************************/
/*	PRIVATE METHODES																				*/
/****************************************************************************************************/


/****************************************************************************************************/
/*	SIGNAUX																							*/
/****************************************************************************************************/

void	MainWindow::connectMenuSide()
{
	connect(this->ui->menuSide, &MenuSide::goToSettings,	this, [this]() { ui->PagesZone->setCurrentIndex(1); });
	connect(this->ui->menuSide, &MenuSide::goToPlayers,		this, [this]() { ui->PagesZone->setCurrentIndex(2); });
	connect(this->ui->menuSide, &MenuSide::goToTeams,		this, [this]() { ui->PagesZone->setCurrentIndex(3); });
	connect(this->ui->menuSide, &MenuSide::goToPools,		this, [this]() { ui->PagesZone->setCurrentIndex(4); });
	connect(this->ui->menuSide, &MenuSide::goToSixteenth,	this, [this]() { ui->PagesZone->setCurrentIndex(5); });
	connect(this->ui->menuSide, &MenuSide::goToEighth,		this, [this]() { ui->PagesZone->setCurrentIndex(6); });
	connect(this->ui->menuSide, &MenuSide::goToQuarter,		this, [this]() { ui->PagesZone->setCurrentIndex(7); });
	connect(this->ui->menuSide, &MenuSide::goToSemi,		this, [this]() { ui->PagesZone->setCurrentIndex(8); });
	connect(this->ui->menuSide, &MenuSide::goToThird,		this, [this]() { ui->PagesZone->setCurrentIndex(9); });
	connect(this->ui->menuSide, &MenuSide::goToFinal,		this, [this]() { ui->PagesZone->setCurrentIndex(10); });
	connect(this->ui->menuSide, &MenuSide::goToExport,		this, [this]() { ui->PagesZone->setCurrentIndex(11); });
	connect(this->ui->menuSide, &MenuSide::goToShow,		this, [this]() { ui->PagesZone->setCurrentIndex(12); });
	connect(this->ui->menuSide, &MenuSide::goToQuit,		this, &QMainWindow::close);
}

void		MainWindow::connectSettingsPage()
{
	connect(this->ui->settingsPage, &SettingsPage::settingsValidated, this, &MainWindow::onSettingsValidated);
	connect(this->ui->settingsPage, &SettingsPage::settingsCancelled, this, &MainWindow::onSettingsCancelled);
}

/****************************************************************************************************/
/*	EVENTS																							*/
/****************************************************************************************************/

void		MainWindow::onSettingsValidated(Settings *settings)
{
	this->settings.reset(settings);

	this->ui->menuSide->setActivePlayersBtn(true);
	this->ui->menuSide->setActiveSettingsBtn(false);
	this->ui->PagesZone->setCurrentIndex(0);
}

void		MainWindow::onSettingsCancelled()
{
	this->ui->PagesZone->setCurrentIndex(0);
}
