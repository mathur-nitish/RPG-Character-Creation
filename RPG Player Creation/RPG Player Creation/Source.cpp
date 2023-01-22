#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

enum Race  {HUMAN,ELF,DWARF,TROLL,ORC};

class Player {
private:
	string name;
	Race race;
	int HP;
	int MP;
public:
	Player(string name, Race race, int hp, int mp) {
		this->name = name;
		this->race = race;
		this->HP = hp;
		this->MP = mp;
	}
	string getName() const {
		return name;
	}
	Race getRace() const {
		return race;
	}
	string whatRace() const {
		string result = "";
		if (race == HUMAN) {
			result = "Human";
			return result;
		}
		else if (race == ELF) {
			result = "Elf";
			return result;
		}
		else if (race == DWARF) {
			result = "DWARF";
			return result;
		}
		else if (race == TROLL) {
			result = "Troll";
			return result;
		}
		else {
			result = "Orc";
			return result;
		};
	}
	int getHitPoints() const {
		return HP;
	}
	int getMagicPoints() const {
		return MP;
	}
	void setName(string name) {
		this->name = name;
	}
	void setRace(Race race) {
		this->race = race;
	}
	void setHitPoints(int hp) {
		this->HP = hp;
	}
	void setMagicPoints(int mp) {
		this->MP = mp;
	}
	virtual void attack() const {

	}


};

class Warrior : public Player {
public:
	Warrior(string name, Race race) : Player(name, race, 200, 0 )
	{}
	void attack() const {
		cout << "I will destroy you with my sword, foul demon!" << endl;
	}
};

class Priest : public Player {
public:
	Priest(string name, Race race) : Player(name, race, 100, 200) 
	{}
	void attack() const {
		cout << "I will assault you with my Holy Wrath!" << endl;
	}
};

class Mage :public Player {
public:
	Mage(string name,Race race):Player(name,race,150,150) {}
	void attack() const {
		cout << "I will crush you with the power of my arcane missiles!" << endl;
	}
};


void printMainMenu();
void printRaceMenu();
Player* createPlayer(string name, int Num, int RaceNum);
void printAll(vector<Player*>PlayerList);
Race getRace(int num);

int main() {
	string playerName;
	int choice;
	int raceNum;
	vector<Player*>PlayerList;
	printMainMenu();
	cin >> choice;
	cin.get();
	while (choice != 0) {
		cout << "Name for you character!" << endl;
		getline(cin, playerName);
		printRaceMenu();
		cin >> raceNum;
		cin.get();
		Player* tempPlayer = createPlayer(playerName, choice, raceNum);
		PlayerList.push_back(tempPlayer);
		
		// Proceed to Create other Character.
		printMainMenu();
		cin >> choice;
		cin.get();
	}

	printAll(PlayerList);

	return 0;
}

void printMainMenu() {
	cout << endl;
	cout << "Which Charater do you want to make?" << endl;
	cout << "\t1 : Warrior" << endl;
	cout << "\t2 : Priest" << endl;
	cout << "\t3 : Mage" << endl;
	cout << "\t0 : Finish Creating Character." << endl;
}

void printRaceMenu() {
	cout << endl;
	cout << "\t1 : Human" << endl;
	cout << "\t2 : ELF" << endl;
	cout << "\t3 : DWARF" << endl;
	cout << "\t4 : TROLL" << endl;
	cout << "\t5 : ORC" << endl;
}

Player* createPlayer(string name, int num, int RaceNum) {
	Player* temp = nullptr;
	Race playerRace = getRace(RaceNum);
	if (num == 1) {
		temp = new Warrior(name, playerRace);
	}
	else if (num == 2) {
		temp = new Priest(name, playerRace);
	}
	else if (num == 3) {
		temp = new Mage(name, playerRace);
	}

	return temp;
}

void printAll(vector<Player*> playerList) {
	for (Player *player : playerList) {
		cout << "I am " << player->getName()
			<< ", the " << player->whatRace();
		cout << " and my attack is : ";
		player->attack();
	}

}

Race getRace(int num) {
	Race race;
	switch (num) {
	case 1:
		race = HUMAN;
		return race;
	case 2:
		race = ELF;
		return race;
	case 3:
		race = DWARF;
		return race;
	case 4:
		race = TROLL;
		return race;
	case 5:
		race = ORC;
		return race;
	default:
		race = HUMAN;
		return race;
	}

	return race = HUMAN;
}

