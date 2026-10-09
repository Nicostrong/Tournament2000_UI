#pragma once

# include <QWidget>
# include <memory>

namespace	Ui
{
	class	ModifyPlayer;
}

class	ModifyPlayer : public QWidget
{
	Q_OBJECT

	public:

		explicit ModifyPlayer(QWidget *parent = nullptr);
		~ModifyPlayer();

	private:

		std::unique_ptr<Ui::ModifyPlayer>		ui;

};

