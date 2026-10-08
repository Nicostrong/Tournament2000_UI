#pragma once

# include <QWidget>
# include <memory>

# include "includes/class/Settings.hpp"
# include "includes/manager/PlayerManager.hpp"

namespace Ui
{
	class	MenuPlayers;
}

class	MenuPlayers : public QWidget
{
		Q_OBJECT

	public:

		explicit MenuPlayers(QWidget *parent = nullptr);
		~MenuPlayers();

		void								setActiveAddPlayerBtn(bool value);
		void								setActiveModifyPlayerBtn(bool value);
		void								setActiveDeletePlayerBtn(bool value);
		void								setActiveImportPlayersBtn(bool value);
		void								setActiveExportPlayersBtn(bool value);
		void								setActiveShowPlayerBtn(bool value);
		void								setActiveShowPlayersListBtn(bool value);
		void								setActiveLaunchTournamentBtn(bool value);


	signals:

		void								onAddPlayer();
		void								onModifyPlayer();
		void								onDeletePlayer();
		void								onImportPlayers();
		void								onExportPlayers();
		void								onShowPlayer();
		void								onShowPlayersList();
		void								onLaunchTournament();

	private:

		std::unique_ptr<Ui::MenuPlayers>	ui;
		std::unique_ptr<PlayerManager>		playerManager;

		void								initMenuPlayers();
		void								connectMenuPlayers();

};

