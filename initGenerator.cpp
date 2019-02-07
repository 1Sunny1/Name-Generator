#include "pch.h"
#include "NGen.h"
#include <random>
#include <string>
#include <iostream>
thread_local std::mt19937 gen{ std::random_device{}() };
template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}

NGen::NGen() {
	_Bnames = {
		"Oliver", "Jake", "Noah", "James",
		"Jack", "Connor", "Liam", "John",
		"Harry", "Callum", "Mason", "Robert",
		"Jacob", "Jacob", "Jacob", "Michael",
		"Charlie", "Kyle", "William", "William",
		"Thomas", "Joe", "Ethan", "David",
		"George", "Reece", "Michael", "Richard",
		"Oscar", "Rhys", "Mike", "Joseph",
		"James", "Charlie", "James", "Charles",
		"William", "Damian", "Daniel","Thomas"
	};
	_Gnames = {
		"Amelia", "Margaret", "Emma", "Mary",
		"Olivia", "Samantha", "Olivia", "Patricia",
		"Isla",	"Bethany", "Sophia", "Jennifer",
		"Emily", "Elizabeth", "Isabella", "Elizabeth",
		"Poppy", "Joanne", "Ava", "Linda",
		"Ava", "Megan", "Mia",	"Barbara",
		"Isabella",	"Victoria",	"Emily", "Susan",
		"Jessica", "Lauren", "Abigail", "Margaret",
		"Lily",	"Michelle",	"Madison", "Jessica",
		"Sophie", "Tracy", "Charlotte",	"Sarah"
	};
	surnames = {
	"Bu", "Pre", "Shear", "Stan",
	"Sm", "Stam", "Che", "Had",
	"Dukes", "Bu", "Mel", "Bris",
	"Spald", "Thacke", "Ram", "Den",
	"Birken", "Pre", "Beve", "Stam",
	"Pad", "Knot", "Net", "Trol",
	"Town", "Pen", "Cot", "Ast",
	"Atter", "Pay", "Floyd", "Ken",
	"What", "Clin", "Brown", "Hay",
	"Crom", "Clem", "White", "Thorn",
	};
	surname_suffixes = {
		"sh", "scott", "man", "ley",
		"lam", "ster", "per", "yth",
		"ing", "nce", "ton", "tol",
		"ray", "sey", "holm", "head",
		"rly", "pes", "dle", "lope",
		"ny", "send", "den", "ons",
		"well"
	};
	std::cout << "Male of female? (M/F): ";
	char choice;
	std::cin >> choice;
	while (std::strchr("mfMF", choice) == nullptr) {
		std::cout << "Enter m or f: ";
		std::cin >> choice;
	}
	if (!(std::strchr("Mm", choice) == nullptr)) {
		sex = MALE;
		randomNameNumber = random<int>(0, _Bnames.size() -1 );
		randomSurnameNumber = random<int>(0, surnames.size() - 1);
		random_SurSuff_Number = random<int>(0, surname_suffixes.size() - 1);
	}
	else if (!(std::strchr("Ff", choice) == nullptr)) {
		sex = FEMALE;
		randomNameNumber = random<int>(0, _Gnames.size() -1 );
		randomSurnameNumber = random<int>(0, surnames.size() - 1);
		random_SurSuff_Number = random<int>(0, surname_suffixes.size() - 1);
	}
}

void NGen::pickName() {
	if (sex == MALE) {
		chosenName = _Bnames[randomNameNumber];
		chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
		if (surnames[randomSurnameNumber].back() == 'm' && random_SurSuff_Number == 12 || 
			surnames[randomSurnameNumber].back() == 'm' &&random_SurSuff_Number == 16) {
			shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
			std::cout << "\nZAMIANA!\n";
			std::cout << chosenSurname << " na ";
			chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
			std::cout << chosenSurname << "\n";
		}
		if (surnames[randomSurnameNumber].back() == 't' && random_SurSuff_Number == 9) {
			shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
			std::cout << "\nZAMIANA!\n";
			std::cout << chosenSurname << " na ";
			chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
			std::cout << chosenSurname << "\n";
		}
		if (surnames[randomSurnameNumber].back() == 'n' && random_SurSuff_Number == 9) {
			shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
			std::cout << "\nZAMIANA!\n";
			std::cout << chosenSurname << " na ";
			chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
			std::cout << chosenSurname << "\n";
		}


	}
	else {
		chosenName = _Gnames[randomNameNumber];
		chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
	}
}

OrcNames::OrcNames() : NGen() {
	_orc_Bnames = {
	"Keserg", "Bras", "Drom", "Grad",
	"Drol", "Bredk", "Drigd", "Unuz",
	"Murd", "Bakk", "Cosh", "Kolt",
	"Raszh", "Kardok", "Keges","Trigg",
	"Druk", "Azuk", "Bagamul", "Bakh",
	"Baronk", "Ushnar", "Uzul", "Muzgonk",
	"Nag", "Shum", "Zungarg", "Zunlog",
	"Kurog", "Durgob", "Grul", "Mog",
	"Nargi", "Othmash", "Ramolg", "Shelakh",
	"Uzgakh", "Lugulg", "Lugzod", "Skordo"
	};
	_orc_Gnames = {
	"Mursha", "Naz", "Maui", "Nobfang",
	"Duzharm", "Naffurty", "Buzum", "Zoguz",
	"Ta", "Mekslag", "Glugka", "Nazgul",
	"Bugsel", "Mag", "Nazsnaga", "Nubbog",
	"Nubshak", "Magnob", "Gobgul", "Morskab",
	"Skarsnaga", "Grumshak", "Mekbag", "Naruz",
	"Nazarg", "Uzshak", "Brubwort", "Brubsnaga",
	"Skarstuf", "Shakfang", "Urty", "Wazfang",
	"Maggor", "Grumstuf", "Wortshak", "Magslag",
	"Waafang", "Mekarg", "Meksog", "Nubshak"
	};
	orc_Bprefixes = {
	"Kru" ,"Ga", "Kar", "Ka",
	"Gr", "Br", "Ku", "Pa",
	"Dr", "Par" ,"Tr", "Ke"
	};
	_orc_variable_Bsuffixes = {
	"sh", "rok", "ar",
	"ok", "ag", "rak",
	"eg", "ak", "og",
	"od", "pak"
	};
	orc_Gprefixes = {
	"Gach", "Baal", "Roog", "Laag",
	"Lush", "Behr", "Naab", "Oonn",
	"Aash", "Uaad", "Moon", "Haal"
	};
	orc_Gsuffixes = {
	"a", "s",
	"d", "t",
	"k", "o"
	};
}

void OrcNames::createName() {
	if (_getSex() == false) {
		finalName = orc_Bprefixes[randBPref] +
		_orc_variable_Bsuffixes[randVariableBsuffix] + " " + chosenName;
	}
	else
		finalName = orc_Gprefixes[randGPref] + " " + chosenName + orc_Gsuffixes[randGSuff];
}

void OrcNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _orc_Bnames[_getRandomNumber()];
		randBPref = random<int>(0, orc_Bprefixes.size() -1 );
		randVariableBsuffix = random<int>(0, _orc_variable_Bsuffixes.size() - 1);
		createName();
	}
	else {
		chosenName = _orc_Gnames[_getRandomNumber()];
		randGSuff = random<int>(0, orc_Gsuffixes.size()-1);
		randGPref = random<int>(0, orc_Gprefixes.size()-1);
		createName();
	}
}

ElfNames::ElfNames() : NGen() {
	_elf_Bnames = {
	"Aeg", "Aelrind", "Biafynd", "Briare",
	"Celebrimb", "Chathangl", "Darcass", "Dio",
	"Earend", "Eldaern", "Fael", "Foldu",
	"Gae", "Glynk", "Hagdu", "Halafar",
	"Iarmen", "Ilthur", "Jass", "Jhaer",
	"Klaer", "Kyren", "Mithrand", "Legol",
	"Myri", "Napraele", "Nevar", "Orib",
	"Otaehr", "Phaend", "Pirph", "Quae",
	"Raeg", "Rhist", "Seiver", "Silv",
	"Taenar", "Thrandu", "Vaer", "Yhendo"
	};
	_elf_Gnames = {
	"Quael", "Quamar", "Akash", "Axil",
	"Rein", "Braerin", "Rubra", "Blythswan",
	"Shalhe", "Caerthyn", "Sylma", "Ciyrad",
	"Daeall", "Dorea", "Ellani", "Elor",
	"Elwi", "Elys", "Fhaertal", "Filaur",
	"Fildaera", "Fraey", "Gylledh", "Haalij",
	"Hyci", "Iahala", "Jahandr", "Kaed",
	"Kethrylli", "Key", "Laamtor", "Laeann",
	"Maaleshiir", "Maegell", "Nushal", "Nylaathri",
	"Ochyllys", "Oluevaer", "Phelorn", "Phyrr"
	};
	elf_Bsuffixes = {
		"o", "el", "ar", "th",
		"or", "in", "ir", "yn", 
		"rn", "il", "as", "al"
	};
	elf_Gsuffixes = {
	"a", "ys",
	"le", "ss",
	"e", "ae"
	};
	elf_surnames = {
	"Wertamyr", "Gwataur", "Ealodel", "Rololithe",
	"Tathdhen", "Neltholial", "Nallviel", "Matanil",
	"Mithladal", "Kevaglinaeil", "Tanvandal", "Tinurina",
	"Celemirsel", "Aeraeme", "Noroval", "Galarina",
	"Cromelwa", "Yrauelwa", "Cromos", "Yraurina",
	"Nelthalelen", "Celealvathor", "Haeelwa", "Augdhrinta",
	"Haelond", "Dlarmirsyr", "Crommiel", "Telyaial",
	"Bireme", "Nelereian", "Weraldal", "Mithlothsyr",
	"Noroval", "Sharondaerl", "Talyatinu", "Galonloth",
	"Elereme", "Tallothial", "Larenagathar", "Ealonae"
	};
}

void ElfNames::createName() {
	if (_getSex() == false)
		finalName = chosenName + elf_Bsuffixes[randBsuff] + " " + chosenSurname;
	else
		finalName = chosenName + elf_Gsuffixes[randGsuff] + " " + chosenSurname;
}

void ElfNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _elf_Bnames[_getRandomNumber()];
		chosenSurname = elf_surnames[_getRandomNumber()];
		randBsuff = random<int>(0, elf_Bsuffixes.size() - 1);
		createName();
	}
	else {
		chosenName = _elf_Gnames[_getRandomNumber()];
		chosenSurname = elf_surnames[_getRandomNumber()];
		randGsuff = random<int>(0, elf_Gsuffixes.size() - 1);
		createName();
	}
}

DwarfNames::DwarfNames() : NGen() {
	_dwarf_Bnames = {
	"Adku", "Anvar", "Bali", "Bangri",
	"Brynjolvu", "Dagu", "Dai", "Eik",
	"Eilivu", "Fin", "Fjali", "Galthru",
	"Gargro", "Grilme", "Harfu", "Haru",
	"Ingival", "Ith", "Jatmundu", "Just",
	"Kar", "Killi", "Lithr", "Lofa",
	"Melnu", "Mjoth", "Naglu", "Nalskjal",
	"Oilulvu", "Oni", "Patri", "Petru",
	"Ragnu", "Rikki", "Sigvaldu", "Skoft",
	"Thora", "Torru", "Vindal", "Viggskjal"
	};
	_dwarf_Gnames = {
	"Ac", "Alind", "Bamir", "Brynj",
	"Col", "Cadadr", "Dad", "Dagn",
	"Elor", "Ere", "Fad", "Fjol",
	"Gadon", "Gorodr", "Harind", "Henn",
	"Jenk", "Jes", "Kas", "Kelar",
	"Leer", "Link", "Mar", "Mil",
	"Nart", "Narvi", "Obar", "Omair",
	"Quoir", "Ragn", "Ralvin", "Samar",
	"Sigg", "Tand", "Tov", "Urth",
	"Vigdi", "Vis", "Yngv", "Zath"
	};
	dwarf_Bsuffixes = {
	"ic","in","ick","im",
	"al","nar","k", "ed", 
	"ek", "ki", "ad","gar"
	};
	dwarf_Gsuffixes = {
	"a", "ja","i", "y",
	"et", "la", "da", "ia",
	"ta", "va", "is", "ga",
	};
	dwarf_surnames = {
	"Fardbal", "Kolmhad", "Berthdorn", "Burakul",
	"Kolmdukr", "Mamalk", "Yurdugan", "Oral",
	"Darrum", "Korudud", "Gorogdukr", "Ovald",
	"Reikul", "Dunadast", "Burarak", "Yemerek",
	"Fadrak", "Bulthal", "Yamamek",	"Theikver",
	"Mordek", "Drunarak", "Thakrak", "Harkak",
	"Armadrum", "Dunadbal", "Normek", "Nuraest",
	"Torud", "Garkakul", "Harladul", "Zagmek",
	"Koruthec", "Kazaest", "Korukal", "Oval",
	"Bulbakver", "Gararum", "Ruknaduum", "Khazabor"
	};
}

void DwarfNames::createName() {
	if (_getSex() == false)
		finalName = chosenName + dwarf_Bsuffixes[randBsuff] + " " + chosenSurname;
	else
		finalName = chosenName + dwarf_Gsuffixes[randGsuff] + " " + chosenSurname;
}

void DwarfNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _dwarf_Bnames[_getRandomNumber()];
		randBsuff = random<int>(0, dwarf_Bsuffixes.size() - 1);
		chosenSurname = dwarf_surnames[_getRandomNumber()];
		createName();
	}
	else {
		chosenName = _dwarf_Gnames[_getRandomNumber()];
		randBsuff = random<int>(0, dwarf_Gsuffixes.size() - 1);
		chosenSurname = dwarf_surnames[_getRandomNumber()];
		createName();
	}
}


