//
// Created by Nicolas Fordoxcel on 18/08/2026.
//

/****************************************************************************************************/
/*	INCLUDES																						*/
/****************************************************************************************************/

#include <string>
#include <vector>
#include <format>
#include <iomanip>

#include "../../includes/class/Team.hpp"
#include "../../includes/class/Pool.hpp"
#include "../../includes/class/Match.hpp"
#include "../../includes/class/Phase.hpp"
#include "../../includes/class/Player.hpp"
#include "../../includes/class/Settings.hpp"
#include "../../includes/class/Tournament.hpp"

#include "../../includes/utils/Exporter.hpp"
#include "../../includes/utils/PrintUtils.hpp"
#include "../../includes/utils/TablePrinter.hpp"

/****************************************************************************************************/
/*	TYPEDEF																							*/
/****************************************************************************************************/

using				String			=	std::string;
using				cString			=	const std::string&;

using				cSet			=	const Settings&;

using				pPlayer			=	Player*;
using				vpPlayer		=	std::vector<Player*>;
using				cvpPlayer		=	const std::vector<Player*>&;

using				pPool			=	Pool*;
using				cPool			=	const Pool&;
using				cpPool			=	const Pool*;
using				vpPool			=	std::vector<Pool*>;
using				cvpPool			=	const std::vector<Pool*>&;

using				pMatch			=	Match*;
using				cMatch			=	const Match&;
using				cpMatch			=	const Match*;
using				vpMatch			=	std::vector<Match*>;
using				cvpMatch		=	const std::vector<Match*>&;

using				pPhase			=	Phase*;
using				cPhase			=	const Phase&;
using				cpPhase			=	const Phase*;
using				vpPhase			=	std::vector<Phase*>;
using				cvpPhase		=	const std::vector<Phase*>&;

using				pPlayer			=	Player*;
using				cPlayer			=	const Player&;
using				cpPlayer			=	const Player*;
using				vpPlayer			=	std::vector<Player*>;
using				cvpPlayer			=	const std::vector<Player*>&;

using				pTour			=	Tournament*;
using				cTour			=	const Tournament&;
using				cpTour			=	const Tournament*;

/****************************************************************************************************/
/*	CONSTRUCTOR / DESTRUCTOR																		*/
/****************************************************************************************************/

/****************************************************************************************************/
/*	GETTER																							*/
/****************************************************************************************************/

/****************************************************************************************************/
/*	SETTER																							*/
/****************************************************************************************************/

/****************************************************************************************************/
/*	PRIVATE METHOD																					*/
/****************************************************************************************************/

/**
 *	Export les Players au format csv
 */
bool				Exporter::exportPlayersToCSV(cvpPlayer players, cString filename)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	file << "Pseudo,Nom,Prenom,Genre\n";

	for (const Player* p : players)
	{
		if (!p)
			continue;

		file << p->getPseudo() << ","
			 << p->getLastName() << ","
			 << p->getFirstName() << ","
			 << (p->getGenderInt() == Gender::MALE ? "0" : "1") << "\n";
	}

	file.close();
	return (true);
}

bool				Exporter::exportPlayersToTxt(cvpPlayer players, cString filename)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);


	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "LISTE DES PARTICIPANTS");
	PrintUtils::printSeparator(file);

	TablePrinter table;
	table.setHeaders({"ID", "Pseudo", "Nom", "Prenom", "Genre"});

	for (const Player* p : players)
	{
		if (!p)
			continue;

		table.addRow({
			std::to_string(p->getId()),
			p->getPseudo(),
			p->getLastName(),
			p->getFirstName(),
			p->getGenderInt() == Gender::MALE ? "0" : "1"
		});
	}

	table.printTable(file, true);
	file.close();
	return (true);
}

/****************************************************************************************************/
/*	TEAMS EXPORT																					*/
/****************************************************************************************************/

bool				Exporter::exportTeamsToTxt(const std::vector<Team*>& teams, cString filename)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "LISTE DES EQUIPES");
	PrintUtils::printSeparator(file);

	TablePrinter table;

	table.setHeaders({"ID", "Equipe", "Membres", "Pts", "Marques", "Encaisses", "Diff"});

	for (const Team* t : teams)
	{
		if (!t)
			continue;

		String membersStr;
		const auto& members = t->getMembers();

		for (size_t i = 0; i < members.size(); ++i)
		{
			if (members[i])
			{
				if (i > 0)
					membersStr += " & ";
				membersStr += members[i]->getPseudo();
			}
		}

		table.addRow({
			std::to_string(t->getId()),
			t->getName(),
			membersStr,
			std::to_string(t->getPoint()),
			std::to_string(t->getScoreMarked()),
			std::to_string(t->getScoreAgainst()),
			std::to_string(t->getScoreDiff())
		});
	}

	table.printTable(file, true);
	file.close();
	return (true);
}

bool				Exporter::exportTeamsToTxt(const Tournament& tournament, cString filename)
{
	return (exportTeamsToTxt(tournament.getTeams(), filename));
}

/****************************************************************************************************/
/*	MATCHES EXPORT																					*/
/****************************************************************************************************/

bool				Exporter::exportMatchesToTxt(const std::vector<Match*>& matches, cString filename, cString title)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, title);
	PrintUtils::printSeparator(file);

	TablePrinter table;

	table.setHeaders({"Equipe A", "Score A", "Score B", "Equipe B", "Statut", "Vainqueur"});

	for (const Match* m : matches)
	{
		if (!m)
			continue;

		String teamA = m->getTeamA()->getName();
		String teamB = m->getTeamB()->getName();
		String status = m->isFinished() ? "Termine" : "En cours";
		String winner = "N/A";

		if (m->isFinished())
			winner = m->getWinner()->getName();

		table.addRow({
			teamA,
			std::to_string(m->getScoreA()),
			std::to_string(m->getScoreB()),
			teamB,
			status,
			winner
		});
	}

	table.printTable(file, true);
	file.close();
	return (true);
}

/****************************************************************************************************/
/*	PHASE EXPORT																					*/
/****************************************************************************************************/

bool				Exporter::exportPhaseToTxt(const Phase* phase, cString filename)
{
	if (!phase)
		return (false);

	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	PrintUtils::printSeparator(file);

	file << "  PHASE : " << phase->getName() << "\n";
	file << "  Sets a jouer par rencontre : " << phase->getNbSetToPlay() << "\n";
	file << "  Statut : " << (phase->isFinished() ? "Terminee" : "En cours") << "\n";
	
	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "MATCHS DE LA PHASE");
	
	TablePrinter table;

	table.setHeaders({"Equipe A", "Score A", "Score B", "Equipe B", "Statut"});

	for (const Match* m : phase->getMatches())
	{
		if (!m)
			continue;

		table.addRow({
			m->getTeamA()->getName(),
			std::to_string(m->getScoreA()),
			std::to_string(m->getScoreB()),
			m->getTeamB()->getName(),
			m->isFinished() ? "Termine" : "En cours"
		});
	}

	table.printTable(file, true);

	if (phase->isFinished())
	{
		PrintUtils::printTitle(file, "RESULTATS");

		file << "Qualifies / Vainqueurs :\n";

		for (const Team* w : phase->getWinners())
			if (w)
				file << "  - " << w->getName() << "\n";

		file << "\nElimines :\n";

		for (const Team* l : phase->getLosers())
			if (l)
				file << "  - " << l->getName() << "\n";
	}

	file.close();
	return (true);
}

/****************************************************************************************************/
/*	POOL EXPORT																						*/
/****************************************************************************************************/

bool				Exporter::exportPoolToTxt(const Pool* pool, cString filename)
{
	if (!pool)
		return (false);

	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, std::format("POULE : {}", pool->getName()));
	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "CLASSEMENT DES EQUIPES");

	TablePrinter table;

	table.setHeaders({"Rang", "Nom Equipe", "Pts", "Marques", "Encaisses", "Diff"});

	size_t rank = 1;

	for (const Team* t : pool->getTeams())
	{
		if (!t)
			continue;

		table.addRow({
			std::to_string(rank++),
			t->getName(),
			std::to_string(t->getPoint()),
			std::to_string(t->getScoreMarked()),
			std::to_string(t->getScoreAgainst()),
			std::to_string(t->getScoreDiff())
		});
	}

	table.printTable(file, true);


	PrintUtils::printTitle(file, "MATCHS DE LA POULE");

	TablePrinter matchPrinter;

	matchPrinter.setHeaders({"Equipe A", "Score A", "Score B", "Equipe B", "Statut"});

	for (const Match* m : pool->getMatches())
	{
		if (!m)
			continue;

		matchPrinter.addRow({
			m->getTeamA()->getName(),
			std::to_string(m->getScoreA()),
			std::to_string(m->getScoreB()),
			 m->getTeamB()->getName(),
			m->isFinished() ? "Termine" : "En cours"
		});
	}

	matchPrinter.printTable(file, true);

	if (pool->allMatchesFinished())
	{
		file << "\n--- QUALIFIER(S) ---\n";
		for (const Team* q : pool->getQualifiers())
			if (q)
				file << "  - " << q->getName() << "\n";
	}

	file.close();
	return (true);
}

bool				Exporter::exportPoolsToTxt(const std::vector<Pool*>& pools, cString filename)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);


	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "ENSEMBLE DES POULES");
	PrintUtils::printSeparator(file);

	for (const Pool* pool : pools)
	{
		if (!pool)
			continue;

		PrintUtils::printTitle(file, pool->getName());

		TablePrinter teamPrinter;

		teamPrinter.setHeaders({"Rang", "Nom Equipe", "Pts", "Marques", "Encaisses", "Diff"});

		size_t rank = 1;

		for (const Team* t : pool->getTeams())
		{
			if (!t)
				continue;

			teamPrinter.addRow({
				std::to_string(rank++),
				t->getName(),
				std::to_string(t->getPoint()),
				std::to_string(t->getScoreMarked()),
				std::to_string(t->getScoreAgainst()),
				std::to_string(t->getScoreDiff())
			});
		}

		teamPrinter.printTable(file, true);
		file << "\n\n";
	}

	file.close();
	return (true);
}

bool				Exporter::exportPoolsToTxt(const Tournament& tournament, cString filename)
{
	return (exportPoolsToTxt(tournament.getPools(), filename));
}

/****************************************************************************************************/
/*	TOURNAMENT EXPORT																				*/
/****************************************************************************************************/

bool				Exporter::exportTournamentToTxt(const Tournament& tournament, cString filename)
{
	std::ofstream file(filename);

	if (!file.is_open())
		return (false);

	const Settings s = tournament.getSettings();


	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, std::format("RECAPITULATIF DU TOURNOI: {}", s.getName()));
	PrintUtils::printSeparator(file);
	PrintUtils::printTitle(file, "PARAMETRES DU TOURNOI");

	file << "Nombre de participants : " << s.getNbPlayers() << "\n";
	file << "Nombre de poules       : " << s.getNbPools() << "\n";
	file << "Terrains disponibles   : " << s.getNbBadmintonCourt() << "\n";
	file << "Format                 : " << (s.getIsDouble() ? "Double" : "Simple")
		 << " | " << (s.getIsMixed() ? "Mixte" : "Non-mixte") << "\n\n";
	PrintUtils::printTitle(file, "PARTICIPANTS");

	TablePrinter playerPrinter;

	playerPrinter.setHeaders({"ID", "Pseudo", "Nom", "Prenom", "Genre"});

	for (const Player* p : tournament.getPlayers())
	{
		if (!p)
			continue;

		playerPrinter.addRow({
			std::to_string(p->getId()),
			p->getPseudo(),
			p->getLastName(),
			p->getFirstName(),
			p->getGenderStr()
		});
	}

	playerPrinter.printTable(file, true);
	file << "\n\n";

	PrintUtils::printTitle(file, "CLASSEMENT DES POULES");

	for (const Pool* pool : tournament.getPools())
	{
		if (!pool)
			continue;

		file << "[" << pool->getName() << "]\n";

		TablePrinter poolPrinter;

		poolPrinter.setHeaders({"Nom Equipe", "Pts", "Diff"});

		for (const Team* t : pool->getTeams())
		{
			if (!t)
				continue;

			poolPrinter.addRow({
				t->getName(),
				std::to_string(t->getPoint()),
				std::to_string(t->getScoreDiff())
			});
		}

		poolPrinter.printTable(file, true);
		file << "\n";
	}

	auto exportPhaseSection = [&file](const Phase* phase, cString title)
	{
		if (!phase)
			return;

		PrintUtils::printTitle(file, std::format("PHASE: {}", title));

		TablePrinter phasePrinter;

		phasePrinter.setHeaders({"Equipe A", "Score A", "Score B", "Equipe B"});

		for (const Match* m : phase->getMatches())
		{
			if (!m)
				continue;

			phasePrinter.addRow({
				m->getTeamA()->getName(),
				std::to_string(m->getScoreA()),
				std::to_string(m->getScoreB()),
				m->getTeamB()->getName()
			});
		}

		phasePrinter.printTable(file, true);
		file << "\n\n";
	};

	exportPhaseSection(tournament.getSixteenth(), "1/16 DE FINALE");
	exportPhaseSection(tournament.getEighth(), "1/8 DE FINALE");
	exportPhaseSection(tournament.getQuarters(), "QUARTS DE FINALE");
	exportPhaseSection(tournament.getSemis(), "DEMI-FINALES");
	exportPhaseSection(tournament.getThirdPlace(), "PETITE FINALE");
	exportPhaseSection(tournament.getFinal(), "FINALE");

	file.close();
	return (true);
}
