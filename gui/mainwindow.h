#pragma once

# include <QMainWindow>
# include <csignal>
# include <memory>

# include "includes/class/Settings.hpp"
# include "includes/manager/PlayerManager.hpp"

QT_BEGIN_NAMESPACE

namespace	Ui
{
	class	MainWindow;
}

QT_END_NAMESPACE

class	MainWindow : public QMainWindow
{
	Q_OBJECT

	public:

		MainWindow(QWidget *parent = nullptr);
		~MainWindow();

	private slots:

		void								onSettingsValidated(Settings *settings);
		void								onSettingsCancelled();

	private:

		std::unique_ptr<Ui::MainWindow>		ui;
		std::unique_ptr<Settings>			settings;
		std::unique_ptr<PlayerManager>		playerManager;

		void								connectMenuSide();
		void								connectSettingsPage();

};
