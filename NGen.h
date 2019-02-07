#ifndef NAMEGENERATOR_H_
#define NAMEGENERATOR_H_
#include <vector>
#include <string>
class NGen {
private:
	enum sex {MALE, FEMALE};
	std::vector <std::string> _Bnames;
	std::vector <std::string> _Gnames;
	std::vector <std::string> surnames;
	std::vector <std::string> surname_suffixes;
	int randomNameNumber;
	int randomSurnameNumber;
	int random_SurSuff_Number;
	std::string chosenName;
	std::string chosenSurname;
	bool sex;
public:
	NGen();
	bool _getSex() const { return sex; }
	void pickName();
	void showGeneratedName() const;
	void showAvaibleNames() const;
	int _getRandomNumber() const { return randomNameNumber; }
};

class OrcNames : public NGen {
private:
	std::vector <std::string> _orc_Bnames;
	std::vector <std::string> _orc_Gnames;
	std::vector <std::string> orc_Gprefixes;
	std::vector <std::string> orc_Bprefixes;
	std::vector <std::string> orc_Gsuffixes;
	std::vector <std::string> _orc_variable_Bsuffixes;
	std::string chosenName;
	int randVariableBsuffix;
	int randBPref;
	int randGPref;
	int randGSuff;
	std::string finalName;
	void createName();
	
public:
	OrcNames();
	void showAvaibleNames() const;
	void showGeneratedName() const;
	void pickRandomized();

};

class ElfNames : public NGen {
private:
	std::vector <std::string> _elf_Bnames;
	std::vector <std::string> _elf_Gnames;
	std::vector <std::string> elf_Bsuffixes;
	std::vector <std::string> elf_Gsuffixes;
	std::vector <std::string> elf_surnames;
	std::string chosenName;
	std::string chosenSurname;
	int randBsuff;
	int randGsuff;
	std::string finalName;
	void createName();
public:
	ElfNames();
	void showAvaibleNames() const;
	void pickRandomized();
	void showGeneratedName() const;
};

class DwarfNames : public NGen {
private:
	std::vector <std::string> _dwarf_Bnames;
	std::vector <std::string> _dwarf_Gnames;
	std::vector <std::string> dwarf_Bsuffixes;
	std::vector <std::string> dwarf_Gsuffixes;
	std::vector <std::string> dwarf_surnames;
	std::string chosenName;
	std::string chosenSurname;
	int randBsuff;
	int randGsuff;
	std::string finalName;
	void createName();
public:
	DwarfNames();
	void showAvaibleNames() const;
	void pickRandomized();
	void showGeneratedName() const;
};

#endif
