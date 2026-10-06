#pragma once

# include <QWidget>
# include <memory>

namespace   Ui
{
	class	MenuSide;
}

class	MenuSide : public QWidget
{
    Q_OBJECT

    public:

        explicit MenuSide(QWidget *parent = nullptr);
        ~MenuSide();

		void							setActivePlayersBtn(bool value);
		void							setActiveTeamsBtn(bool value);
		void							setActivePoolsBtn(bool value);
		void							setActiveSixteenthBtn(bool value);
		void							setActiveEighthBtn(bool value);
		void							setActiveQuarterBtn(bool value);
		void							setActiveSemiBtn(bool value);
		void							setActiveThirdBtn(bool value);
		void							setActiveFinalBtn(bool value);
		void							setActiveExportBtn(bool value);
		void							setActiveShowBtn(bool value);

    signals:

		void							goToSettings();
		void							goToPlayers();
		void							goToTeams();
		void							goToPools();
		void							goToSixteenth();
		void							goToEighth();
		void							goToQuarter();
		void							goToSemi();
		void							goToThird();
		void							goToFinal();
		void							goToExport();
		void							goToShow();
		void							goToQuit();

    private:

		std::unique_ptr<Ui::MenuSide>	ui;

		void							initMenuSide();
};

