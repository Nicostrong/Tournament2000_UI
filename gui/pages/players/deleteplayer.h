#pragma once

# include <QWidget>
# include <memory>

namespace	Ui
{
	class	DeletePlayer;
}

class	DeletePlayer : public QWidget
{
	Q_OBJECT

	public:

		explicit DeletePlayer(QWidget *parent = nullptr);
		~DeletePlayer();

	private:

		std::unique_ptr<Ui::DeletePlayer>		ui;

};

