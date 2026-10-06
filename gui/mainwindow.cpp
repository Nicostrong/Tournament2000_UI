#include "gui/mainwindow.h"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connectMenuSide();
	connectSettingsPage();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void	MainWindow::connectMenuSide()
{
	connect(this->ui->menuSide, &MenuSide::goToSettings,	this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
	connect(this->ui->menuSide, &MenuSide::goToPlayers,		this, [this]() { ui->stackedWidget->setCurrentIndex(2); });
	connect(this->ui->menuSide, &MenuSide::goToTeams,		this, [this]() { ui->stackedWidget->setCurrentIndex(3); });
	connect(this->ui->menuSide, &MenuSide::goToPools,		this, [this]() { ui->stackedWidget->setCurrentIndex(4); });
	connect(this->ui->menuSide, &MenuSide::goToSixteenth,	this, [this]() { ui->stackedWidget->setCurrentIndex(5); });
	connect(this->ui->menuSide, &MenuSide::goToEighth,		this, [this]() { ui->stackedWidget->setCurrentIndex(6); });
	connect(this->ui->menuSide, &MenuSide::goToQuarter,		this, [this]() { ui->stackedWidget->setCurrentIndex(7); });
	connect(this->ui->menuSide, &MenuSide::goToSemi,		this, [this]() { ui->stackedWidget->setCurrentIndex(8); });
	connect(this->ui->menuSide, &MenuSide::goToThird,		this, [this]() { ui->stackedWidget->setCurrentIndex(9); });
	connect(this->ui->menuSide, &MenuSide::goToFinal,		this, [this]() { ui->stackedWidget->setCurrentIndex(10); });
	connect(this->ui->menuSide, &MenuSide::goToExport,		this, [this]() { ui->stackedWidget->setCurrentIndex(11); });
	connect(this->ui->menuSide, &MenuSide::goToShow,		this, [this]() { ui->stackedWidget->setCurrentIndex(12); });
	connect(this->ui->menuSide, &MenuSide::goToQuit,		this, &QMainWindow::close);
}

void		MainWindow::connectSettingsPage()
{
	connect(this->ui->settingsPage, &SettingsPage::settingsValidated, this, &MainWindow::onSettingsValidated);
	connect(this->ui->settingsPage, &SettingsPage::settingsCancelled, this, &MainWindow::onSettingsCancelled);
}

void		MainWindow::onSettingsValidated(const Settings& newSettings)
{
	this->settings = newSettings;

	this->ui->menuSide->setActivePlayersBtn(true);
	this->ui->stackedWidget->setCurrentIndex(0);
}

void		MainWindow::onSettingsCancelled()
{
	this->ui->stackedWidget->setCurrentIndex(0);
}