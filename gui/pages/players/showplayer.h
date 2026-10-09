#pragma once

# include <QWidget>
# include <memory>

namespace	Ui
{
	class	ShowPlayer;
}

class	ShowPlayer : public QWidget
{
	Q_OBJECT

	public:

		explicit ShowPlayer(QWidget *parent = nullptr);
		~ShowPlayer();

	private:

		std::unique_ptr<Ui::ShowPlayer>		ui;

};

