#pragma once

# include <QWidget>

# include "includes/class/Settings.hpp"
# include "includes/utils/SettingsChecker.hpp"

namespace	Ui
{
	class	SettingsPage;
}

class	SettingsPage : public QWidget
{
	Q_OBJECT

	public:

		explicit SettingsPage(QWidget *parent = nullptr);
		~SettingsPage();

	signals:

		void								settingsValidated(Settings *settings);
		void								settingsCancelled();
		void								reset();
		void								goToMain();

	private slots:

		void								onResetClicked();
		void								onValidateClicked();
		void								onCancelClicked();
		void								onCheckHasThirdPlaceMatch();


	private:

		std::unique_ptr<Ui::SettingsPage>	ui;

		void								initUI();

		void								initSpinBoxesRanges();

		void								setDefaultValues();

		void								connectSettingsPage();

		void								addNbPoolLst();
		void								addNbPlayerLst();
		void								addNbPlayerPerPoolLst();

};

