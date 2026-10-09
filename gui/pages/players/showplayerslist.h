#pragma once

# include <QWidget>
# include <memory>

namespace	Ui
{
	class	ShowPlayersList;
}

class	ShowPlayersList : public QWidget
{
	Q_OBJECT

	public:

		explicit ShowPlayersList(QWidget *parent = nullptr);
		~ShowPlayersList();

	private:

		std::unique_ptr<Ui::ShowPlayersList>		ui;

};

