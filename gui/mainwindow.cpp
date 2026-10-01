#include "gui/mainwindow.h"
#include "gui/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	connectMenuSide();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void	MainWindow::connectMenuSide()
{
	connect(ui->menuSide, &MenuSide::goToSettings,	this, [this]() { ui->stackedWidget->setCurrentIndex(0); });
	connect(ui->menuSide, &MenuSide::goToPlayers,	this, [this]() { ui->stackedWidget->setCurrentIndex(1); });
	connect(ui->menuSide, &MenuSide::goToTeams,		this, [this]() { ui->stackedWidget->setCurrentIndex(2); });
	connect(ui->menuSide, &MenuSide::goToPools,		this, [this]() { ui->stackedWidget->setCurrentIndex(3); });
	connect(ui->menuSide, &MenuSide::goToSixteenth,	this, [this]() { ui->stackedWidget->setCurrentIndex(4); });
	connect(ui->menuSide, &MenuSide::goToEighth,	this, [this]() { ui->stackedWidget->setCurrentIndex(5); });
	connect(ui->menuSide, &MenuSide::goToQuarter,	this, [this]() { ui->stackedWidget->setCurrentIndex(6); });
	connect(ui->menuSide, &MenuSide::goToSemi,		this, [this]() { ui->stackedWidget->setCurrentIndex(7); });
	connect(ui->menuSide, &MenuSide::goToThird,		this, [this]() { ui->stackedWidget->setCurrentIndex(8); });
	connect(ui->menuSide, &MenuSide::goToFinal,		this, [this]() { ui->stackedWidget->setCurrentIndex(9); });
	connect(ui->menuSide, &MenuSide::goToExport,	this, [this]() { ui->stackedWidget->setCurrentIndex(10); });
	connect(ui->menuSide, &MenuSide::goToShow,		this, [this]() { ui->stackedWidget->setCurrentIndex(11); });
	connect(ui->menuSide, &MenuSide::goToQuit,		this, &QMainWindow::close);
}