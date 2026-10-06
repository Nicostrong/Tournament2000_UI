#ifndef PLAYERSPAGE_H
#define PLAYERSPAGE_H

#include <QWidget>

namespace Ui
{
class PlayersPage;
}

class PlayersPage : public QWidget
{
		Q_OBJECT

	public:

		explicit PlayersPage(QWidget *parent = nullptr);
		~PlayersPage();

	private:

		Ui::PlayersPage *ui;
};

#endif // PLAYERSPAGE_H
