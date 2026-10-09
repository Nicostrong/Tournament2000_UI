#pragma once

# include <memory>

# include <QWidget>

namespace	Ui
{
	class	PlayersPage;
}

class	PlayersPage : public QWidget
{
		Q_OBJECT

	public:

		explicit PlayersPage(QWidget *parent = nullptr);
		~PlayersPage();

	private:

		std::unique_ptr<Ui::PlayersPage>	ui;

};

