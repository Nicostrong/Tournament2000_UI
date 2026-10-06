#pragma once

# include <QMainWindow>
# include <csignal>

# include "includes/class/Settings.hpp"

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

		void				onSettingsValidated(const Settings& newSettings);
		void				onSettingsCancelled();

	private:

		Ui::MainWindow		*ui;
		Settings			settings;

		void				connectMenuSide();
		void				connectSettingsPage();

};
