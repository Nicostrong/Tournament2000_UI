#pragma once

# include <QWidget>
# include <memory>

namespace	Ui
{
	class	AddPlayer;
}

class	AddPlayer : public QWidget
{
	Q_OBJECT

	public:

		explicit AddPlayer(QWidget *parent = nullptr);
		~AddPlayer();

	private:

		std::unique_ptr<Ui::AddPlayer>		ui;

};

