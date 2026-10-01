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

