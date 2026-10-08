#include "gui/pages/settings/settingspage.h"
#include "gui/pages/settings/ui_settingspage.h"

#include "includes/class/Settings.hpp"
#include "includes/utils/SettingsChecker.hpp"

#include "includes/Constantes.hpp"

/****************************************************************************************************/
/*	CONSTRUCTOR																						*/
/****************************************************************************************************/

SettingsPage::SettingsPage(QWidget *parent): QWidget(parent), ui(std::make_unique<Ui::SettingsPage>())
{
	ui->setupUi(this);

	initUI();

	connectSettingsPage();

}

SettingsPage::~SettingsPage() = default;

/****************************************************************************************************/
/*	PRIVATE METHODES																				*/
/****************************************************************************************************/

/**
 * Initialisation de l'interface UI
 */
void		SettingsPage::initUI()
{
	this->ui->TournamentNameEdit->clear();
	this->ui->CommentsAndErrorsLabel->setWordWrap(true);
	this->ui->CommentsAndErrorsLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
	this->ui->CommentsAndErrorsLabel->setText("Ready.");

	initSpinBoxesRanges();

	addNbPlayerLst();
	addNbPoolLst();
	addNbPlayerPerPoolLst();

	setDefaultValues();
}

/**
 * Initialisation des limites des spinBoxes
 */
void		SettingsPage::initSpinBoxesRanges()
{
	this->ui->WinScoreLst->setRange(SCOREMINTOWIN, SCOREMAXTOWIN);
	this->ui->ScoreMaxLst->setRange(SCOREMINTOWIN, SCOREMAXTOWIN);
	this->ui->DeltaScoreLst->setRange(ECARTMIN, ECARTMAX);
	this->ui->NbSetPoolsBox->setRange(NBSETPOOLMIN, NBSETPOOLMAX);
	this->ui->NbSetSixteenthBox->setRange(NBSETSIXTEENTHMIN, NBSETSIXTEENTHMAX);
	this->ui->NbSetEighthBox->setRange(NBSETEIGTHMIN, NBSETEIGTHMAX);
	this->ui->NbSetQuarterBox->setRange(NBSETQUARTERMIN, NBSETQUARTERMAX);
	this->ui->NbSetSemiBox->setRange(NBSETSEMIMIN, NBSETSEMIMAX);
	this->ui->NbSetThirdBox->setRange(NBSETTHIRDMIN, NBSETTHIRDMAX);
	this->ui->NbSetFinalBox->setRange(NBSETFINALMIN, NBSETFINALMAX);
}

/**
 * Initialisation de le liste de choix pour le nombre de players
 */
void		SettingsPage::addNbPlayerLst()
{
	this->ui->NbPlayersLst->clear();

	if (this->ui->SimpleRadio->isChecked())
		for (int nb: allowedNbPlayersSimple)
			this->ui->NbPlayersLst->addItem(QString::number(nb));
	else
		for (int nb: allowedNbPlayersDouble)
			this->ui->NbPlayersLst->addItem(QString::number(nb));
}

/**
 * Initialisation de la liste de choix pour le nombre de pools
 */
void		SettingsPage::addNbPoolLst()
{
	this->ui->NbPoolsLst->clear();

	for (int nb: allowedNbPools)
			this->ui->NbPoolsLst->addItem(QString::number(nb));
}

/**
 * Initialisation de la liste de choix pour le nombre de players/teams par pool
 */
void		SettingsPage::addNbPlayerPerPoolLst()
{
	this->ui->NbPlayersPerPoolsLst->clear();

	for (int nb: allowedNbPlayersOrTeamsPerPools)
		this->ui->NbPlayersPerPoolsLst->addItem(QString::number(nb));
}

/**
 * Set des valeurs par default
 */
void		SettingsPage::setDefaultValues()
{
	this->ui->TournamentNameEdit->setPlaceholderText(TOURNAMENTNAME);

	this->ui->DoubleRadio->setChecked(ISDOUBLE);
	this->ui->SimpleRadio->setChecked(!ISDOUBLE);

	this->ui->MixteRadio->setChecked(ISMIXED);
	this->ui->HommeRadio->setChecked(!ISMIXED);

	this->ui->MultiPlayerTeamCheck->setChecked(PLAYERMULTITEAM);
	this->ui->HasThirdPlaceCheck->setChecked(PLAYTHIRDPLACE);

	addNbPlayerLst();

	this->ui->NbPlayersLst->setCurrentText(QString::number(NBPLAYER));
	this->ui->NbPoolsLst->setCurrentText(QString::number(NBPOOL));
	this->ui->NbPlayersPerPoolsLst->setCurrentText(QString::number(NBPLAYERPERPOOL));

	this->ui->WinScoreLst->setValue(SCOREMIN);
	this->ui->ScoreMaxLst->setValue(SCOREMAX);
	this->ui->DeltaScoreLst->setValue(ECART);

	this->ui->NbSetPoolsBox->setValue(NBSETPOOL);
	this->ui->NbSetSixteenthBox->setValue(NBSETSIXTEENTH);
	this->ui->NbSetEighthBox->setValue(NBSETEIGTH);
	this->ui->NbSetQuarterBox->setValue(NBSETQUARTER);
	this->ui->NbSetSemiBox->setValue(NBSETSEMI);
	this->ui->NbSetFinalBox->setValue(NBSETFINAL);
	this->ui->NbSetThirdBox->setValue(NBSETTHIRD);

	onCheckHasThirdPlaceMatch();
}

/****************************************************************************************************/
/*	PUBLIC METHODES																					*/
/****************************************************************************************************/

/****************************************************************************************************/
/*	SIGNAUX																							*/
/****************************************************************************************************/

/**
 * Connection des signaux pour rendu dynamique
 */
void		SettingsPage::connectSettingsPage()
{
	connect(this->ui->SimpleRadio,			&QRadioButton::toggled,			this, &SettingsPage::addNbPlayerLst);
	connect(this->ui->ValidateBtn,			&QPushButton::clicked,			this, &SettingsPage::onValidateClicked);
	connect(this->ui->CancelBtn,			&QPushButton::clicked,			this, &SettingsPage::onCancelClicked);
	connect(this->ui->ResetBtn,				&QPushButton::clicked,			this, &SettingsPage::onResetClicked);
	connect(this->ui->HasThirdPlaceCheck,	&QCheckBox::checkStateChanged,	this, &SettingsPage::onCheckHasThirdPlaceMatch);
}

/****************************************************************************************************/
/*	EVENTS																							*/
/****************************************************************************************************/

/**
 * Active/desactive le setting du match pour la 3eme place
 */
void		SettingsPage::onCheckHasThirdPlaceMatch()
{
	bool hasThirdPlace = this->ui->HasThirdPlaceCheck->isChecked();

	this->ui->NbSetThirdBox->setEnabled(hasThirdPlace);
	this->ui->NbSetThirdLabel->setEnabled(hasThirdPlace);
}

/**
 * Gestion du reset
 */
void		SettingsPage::onResetClicked()
{
	this->ui->TournamentNameEdit->clear();

	addNbPoolLst();
	addNbPlayerPerPoolLst();

	setDefaultValues();

	this->ui->CommentsAndErrorsLabel->setText("Paramètres réinitialisés avec les valeurs par défaut.");
}

/**
 * Gestion du cancel
 */
void		SettingsPage::onCancelClicked()
{
	emit settingsCancelled();
}

/**
 * Validation des settings
 */
void		SettingsPage::onValidateClicked()
{
	QString tournamentName = this->ui->TournamentNameEdit->text();

	if (tournamentName.isEmpty())
		tournamentName = this->ui->TournamentNameEdit->placeholderText();

	Gender selectedGender = Gender::MIXED;

	if (this->ui->HommeRadio->isChecked())
		selectedGender = Gender::MALE;
	else if (this->ui->FemmeRadio->isChecked())
		selectedGender = Gender::FEMALE;

	auto tempSettings = std::make_unique<Settings>();;

	tempSettings->setName(tournamentName.toStdString());
	tempSettings->setIsDouble(this->ui->DoubleRadio->isChecked());
	tempSettings->setTournamentGender(selectedGender);

	tempSettings->setNbPlayers(this->ui->NbPlayersLst->currentText().toInt());
	tempSettings->setNbPools(this->ui->NbPoolsLst->currentText().toInt());
	tempSettings->setNbPlayerByPool(this->ui->NbPlayersPerPoolsLst->currentText().toInt());

	tempSettings->setAllowMultiTeamPlayers(this->ui->MultiPlayerTeamCheck->isChecked());
	tempSettings->setIsThirdPlaceMatch(this->ui->HasThirdPlaceCheck->isChecked());

	tempSettings->setNbBadmintonCourt(NBTERRAIN);

	tempSettings->setScoreMin(this->ui->WinScoreLst->value());
	tempSettings->setScoreMax(this->ui->ScoreMaxLst->value());
	tempSettings->setDiffPointsToWin(this->ui->DeltaScoreLst->value());

	tempSettings->setNbSetPlayedPools(this->ui->NbSetPoolsBox->value());
	tempSettings->setNbSetPlayedSixteenth(this->ui->NbSetSixteenthBox->value());
	tempSettings->setNbSetPlayedEigth(this->ui->NbSetEighthBox->value());
	tempSettings->setNbSetPlayedQuarters(this->ui->NbSetQuarterBox->value());
	tempSettings->setNbSetPlayedSemis(this->ui->NbSetSemiBox->value());
	tempSettings->setNbSetPlayedFinal(this->ui->NbSetFinalBox->value());

	if (tempSettings->getIsThirdPlaceMatch())
		tempSettings->setNbSetPlayedThirdPlace(this->ui->NbSetThirdBox->value());
	else
		tempSettings->setNbSetPlayedThirdPlace(0);

	vString errors;
	SettingsChecker checker;

	if (checker.isValid(*tempSettings, errors))
	{
		this->ui->CommentsAndErrorsLabel->setStyleSheet("color: green;");
		this->ui->CommentsAndErrorsLabel->setText("Paramètres validés avec succès !");

		emit settingsValidated(tempSettings.release());
	}
	else
	{
		QString errorText = "<b>Erreurs détectées :</b><br>";

		for (const std::string& err : errors)
			errorText += "- " + QString::fromStdString(err) + "<br>";

		this->ui->CommentsAndErrorsLabel->setStyleSheet("color: red;");
		this->ui->CommentsAndErrorsLabel->setText(errorText);
	}
}
