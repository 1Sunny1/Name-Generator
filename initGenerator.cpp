#include "pch.h"
#include "NGen.h"
#include <string>
#include <iostream>
#include <random>

thread_local std::mt19937 gen{ std::random_device{}() };
template<typename T>
T random(T min, T max) {
	return std::uniform_int_distribution<T>{min, max}(gen);
}
void NGen::_shuffleAll() {
	shuffle(_Bnames.begin(), _Bnames.end(), gen);
	shuffle(_Gnames.begin(), _Gnames.end(), gen);
	shuffle(surnames.begin(), surnames.end(), gen);
	shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
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
	_shuffleAll();
	//TODO: add more human examples
	std::cout << "Male of female? (M/F): ";
	char choice;
	std::cin >> choice;
	while (std::strchr("mfMF", choice) == nullptr) {
		std::cout << "Enter m or f: ";
		std::cin >> choice;
	}
	if (!(std::strchr("Mm", choice) == nullptr)) {
		sex = MALE;
		randomNameNumber = random<int>(0, _Bnames.size() - 1);
		randomSurnameNumber = random<int>(0, surnames.size() - 1);
		random_SurSuff_Number = random<int>(0, surname_suffixes.size() - 1);
	}
	if (!(std::strchr("Ff", choice) == nullptr)) {
		sex = FEMALE;
		randomNameNumber = random<int>(0, _Gnames.size() - 1);
		randomSurnameNumber = random<int>(0, surnames.size() - 1);
		random_SurSuff_Number = random<int>(0, surname_suffixes.size() - 1);
	}
}

void NGen::pickName() {
	if (sex == MALE)
		chosenName = _Bnames[randomNameNumber];
	else
		chosenName = _Gnames[randomNameNumber];

	chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
	if (surnames[randomSurnameNumber].back() == 'm' && random_SurSuff_Number == 12 ||
		surnames[randomSurnameNumber].back() == 'm' && random_SurSuff_Number == 16 ||
		surnames[randomSurnameNumber].back() == 'm' && random_SurSuff_Number == 2) {
		shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
		chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
	}
	if (surnames[randomSurnameNumber].back() == 't' && random_SurSuff_Number == 9) {
		shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
		chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
	}
	if (surnames[randomSurnameNumber].back() == 'n' && random_SurSuff_Number == 9) {
		shuffle(surname_suffixes.begin(), surname_suffixes.end(), gen);
		chosenSurname = surnames[randomSurnameNumber] + surname_suffixes[random_SurSuff_Number];
	}
}

void OrcNames::_shuffleAll() {
	shuffle(_orc_Bnames.begin(), _orc_Bnames.end(), gen);
	shuffle(_orc_Gnames.begin(), _orc_Gnames.end(), gen);
	shuffle(orc_Gprefixes.begin(), orc_Gprefixes.end(), gen);
	shuffle(orc_Bprefixes.begin(), orc_Bprefixes.end(), gen);
	shuffle(orc_Bsuffixes.begin(), orc_Bsuffixes.end(), gen);
	shuffle(orc_Gsuffixes.begin(), orc_Gsuffixes.end(), gen);
	shuffle(_orc_variable_Bsuffixes.begin(), _orc_variable_Bsuffixes.end(), gen);
	shuffle(_orc_variable_Gsuffixes.begin(), _orc_variable_Gsuffixes.end(), gen);
}

OrcNames::OrcNames() : NGen() {
	_orc_Bnames = {
	"Kes", "Br", "Dr", "Gr",
	"Dr", "Bre", "Dri", "Un",
	"Mu", "Ba", "Co", "Ko",
	"Ra", "Kar", "Ke","Tri",
	"Dr", "Az", "Baga", "Ba",
	"Baro", "Ush", "Uz", "Muz",
	"Na", "Sh", "Zun", "Zun",
	"Ku", "Dur", "Gr", "Mo",
	"Nar", "Oth", "Ram", "She",
	"Uz", "Lug", "Lug", "Sk"
	};
	orc_Bsuffixes = {
	"erg", "as", "om", "ad", "ag",
	"dk", "gd", "uz", "rd", "kk",
	"sh", "lt", "szh", "dok", "ges",
	"gg", "uk", "mul", "kh", "nk",
	"nar", "ul", "gonk", "um", "g",
	"garg", "log", "rog", "gob", "gi",
	"mash", "olg", "lakh", "do", "or",
	"zod", "ulg", "gakh"
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
	_orc_variable_Gsuffixes = {
	"ch", "al", "og", "ag",
	"nn", "ab", "hr", "sh",
	"ad", "on"
	};
	orc_Gprefixes = {
	"Ga", "Ba", "Ro", "La",
	"Lu", "Be", "Na", "Oo",
	"Aa", "Ua", "Mo", "Ha"
	};
	orc_Gsuffixes = {
	"a", "s",
	"d", "t",
	"k", "o"
	};
	_shuffleAll();
	//TODO: add more orc examples
	
}

void OrcNames::createName() {
	if (_getSex() == false) {
		finalName = orc_Bprefixes[randBPref] +
			_orc_variable_Bsuffixes[randVariableBsuffix] + " " + chosenName + orc_Bsuffixes[_rand_orcBsuff];
		if (_orc_Bnames[_getRandomNumber()].back() == 'k' && _rand_orcBsuff == 5 ||
			_orc_Bnames[_getRandomNumber()].back() == 'k' && _rand_orcBsuff == 18) {
			shuffle(orc_Bsuffixes.begin(), orc_Bsuffixes.end(), gen);
			finalName = orc_Bprefixes[randBPref] +
				_orc_variable_Bsuffixes[randVariableBsuffix] + " " + chosenName + orc_Bsuffixes[_rand_orcBsuff];
		}
		if (_orc_Bnames[_getRandomNumber()] == "Ush" && _rand_orcBsuff == 12) {
			shuffle(orc_Bsuffixes.begin(), orc_Bsuffixes.end(), gen);
			finalName = orc_Bprefixes[randBPref] +
				_orc_variable_Bsuffixes[randVariableBsuffix] + " " + chosenName + orc_Bsuffixes[_rand_orcBsuff];
		}
	}//y2m y2f
	else {
		finalName = orc_Gprefixes[randGPref] +
			_orc_variable_Gsuffixes[randVariableGsuffix] + " " + chosenName + orc_Gsuffixes[randGSuff];
	}
}

void OrcNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _orc_Bnames[_getRandomNumber()];
		randBPref = random<int>(0, orc_Bprefixes.size() - 1);
		randVariableBsuffix = random<int>(0, _orc_variable_Bsuffixes.size() - 1);
		_rand_orcBsuff = random<int>(0, orc_Bsuffixes.size() - 1);
		createName();
	}
	else {
		chosenName = _orc_Gnames[_getRandomNumber()];
		randGSuff = random<int>(0, orc_Gsuffixes.size() - 1);
		randGPref = random<int>(0, orc_Gprefixes.size() - 1);
		randVariableGsuffix = random<int>(0, _orc_variable_Gsuffixes.size() - 1);
		createName();
	}
}

void ElfNames::_shuffleAll() {
	shuffle(_elf_Bnames.begin(), _elf_Bnames.end(), gen);
	shuffle(_elf_Gnames.begin(), _elf_Gnames.end(), gen);
	shuffle(elf_Bsuffixes.begin(), elf_Bsuffixes.end(), gen);
	shuffle(elf_Gsuffixes.begin(), elf_Gsuffixes.end(), gen);
	shuffle(elf_surnames.begin(), elf_surnames.end(), gen);
	shuffle(elf_Bsurnames_suffixes.begin(), elf_Bsurnames_suffixes.end(), gen);
	shuffle(elf_Gsurnames_suffixes.begin(), elf_Gsurnames_suffixes.end(), gen);
}

ElfNames::ElfNames() : NGen() {
	_elf_Bnames = {
	"Aeg", "Aelrind", "Biafynd", "Briare",
	"Celebrimb", "Chathangl", "Darcass", "Dio",
	"Earend", "Eldaern", "Fael", "Foldu", //9
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
		"rn", "il", "as", "al" //8
	};
	elf_Gsuffixes = {
	"a", "ys",
	"le",
	"e", "ae"
	};
	elf_surnames = {
	"Werta", "Gwat", "Ealo", "Rololi",
	"Tathd", "Neltho", "Nall", "Mata", //4
	"Aell", "Kevagli", "Tanva", "Tinu",
	"Celem", "Aera", "Noro", "Gala",
	"Crom", "Yrau", "Cro", "Yrau",
	"Nelt", "Celealva", "Hae", "Augdh", //23
	"Hael", "Dlarmi", "Crom", "Tely",
	"Bir", "Nelere", "Weral", "Mith", //31
	"Noro", "Sharon", "Talya", "Galon",
	"Eler", "Talloth", "Larenaga", "Ealon" //37
	};
	elf_Bsurnames_suffixes = {
	"myr", "aur", "del", "the", "hen", //3
	"lial", "viel", "adal", "naeil", "ndal",
	"irsel", "val", "mos", "len", "hale",
	"thor", "ond", "syr", "miel", "aial",
	"ian", "dal", "daerl", "loth", "thar",
	"ae"
	};
	elf_Gsurnames_suffixes = {
	"rina", "eme", "elwa", "rinta",
	"tinu"
	};
	_shuffleAll();
	//TODO: add more elf examples
}

void ElfNames::createName() {
	if (_getSex() == false) {
		finalName = chosenName + elf_Bsuffixes[randBsuff] + " " +
			chosenSurname + elf_Bsurnames_suffixes[randSurname_Suff];
		if (chosenName.back() == 'd' && randBsuff == 8) {
			shuffle(elf_Bsuffixes.begin(), elf_Bsuffixes.end(), gen);
			finalName = chosenName + elf_Bsuffixes[randBsuff] + " " +
				chosenSurname + elf_Bsurnames_suffixes[randSurname_Suff];
		}

		if (chosenName.back() == 'r' && randBsuff == 8) {
			shuffle(elf_Bsuffixes.begin(), elf_Bsuffixes.end(), gen);
			finalName = chosenName + elf_Bsuffixes[randBsuff] + " " +
				chosenSurname + elf_Bsurnames_suffixes[randSurname_Suff];
		}

		if (chosenName.back() == 'n' && randBsuff == 8) {
			shuffle(elf_Bsuffixes.begin(), elf_Bsuffixes.end(), gen);
			finalName = chosenName + elf_Bsuffixes[randBsuff] + " " +
				chosenSurname + elf_Bsurnames_suffixes[randSurname_Suff];
		}

		if (chosenSurname.back() == 'h' && randSurname_Suff == 3) {
			shuffle(elf_Bsurnames_suffixes.begin(), elf_Bsurnames_suffixes.end(), gen);
			finalName = chosenName + elf_Bsuffixes[randBsuff] + " " +
				chosenSurname + elf_Bsurnames_suffixes[randSurname_Suff];
		}
	}
	else {
		finalName = chosenName + elf_Gsuffixes[randGsuff] + " " + chosenSurname + elf_Gsurnames_suffixes[randSurname_Suff];
	}
}

void ElfNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _elf_Bnames[_getRandomNumber()];
		chosenSurname = elf_surnames[_getRandomNumber()];
		randBsuff = random<int>(0, elf_Bsuffixes.size() - 1);
		randSurname_Suff = random<int>(0, elf_Bsurnames_suffixes.size() - 1);
		createName();
	}
	else {
		chosenName = _elf_Gnames[_getRandomNumber()];
		chosenSurname = elf_surnames[_getRandomNumber()];
		randGsuff = random<int>(0, elf_Gsuffixes.size() - 1);
		randSurname_Suff = random<int>(0, elf_Gsurnames_suffixes.size() - 1);
		createName();
	}
}

void DwarfNames::_shuffleAll() {

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
	"Ragnu", "Rikk", "Sigvaldu", "Skoft",
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
	"Fard", "Kolm", "Berth", "Bura",
	"Kolm", "Mam", "Yurdu", "Or",
	"Dar", "Koru", "Gorog", "Ov",
	"Rei", "Duna", "Bura", "Yeme",
	"Fad", "Bul", "Yama",	"Thei",
	"Mor", "Druna", "Thak", "Har",
	"Arma", "Dunad", "Nor", "Nura",
	"Tor", "Garka", "Harla", "Zag",
	"Koru", "Kaza", "Koru", "Os",
	"Bulba", "Gara", "Ruk", "Khaza"
	};
	dwarf_surSuffs = { 
	"bal", "had", "dorn", "kul", "dukr",
	"alk", "gan", "al", "rum", "dud",
	"ald", "kul", "dast", "rak", "rek",
	"thal", "mek", "kver", "kak", "dek",
	"drum", "est", "ud", "dul", "kal",
	"thec", "duum", "bor"
	};
	_shuffleAll();
	//TODO: add more dwarf examples
}

void DwarfNames::createName() {
	if (_getSex() == false) {
		finalName = chosenName + dwarf_Bsuffixes[randBsuff] + " " +
			chosenSurname + dwarf_surSuffs[rand_surSuff_numb];
		//if (chosenName.back() == 'i' && randBsuff == 8) {
		//	shuffle(dwarf_Bsuffixes.begin(), dwarf_Bsuffixes.end(), gen);
		//	finalName = chosenName + dwarf_Bsuffixes[randBsuff] + " " +
		//		chosenSurname + dwarf_surSuffs[rand_surSuff_numb];
	//	}
	}
	else {
		finalName = chosenName + dwarf_Gsuffixes[randGsuff] + " " + chosenSurname + dwarf_surSuffs[rand_surSuff_numb];
	}
}

void DwarfNames::pickRandomized() {
	if (_getSex() == false) {
		chosenName = _dwarf_Bnames[_getRandomNumber()];
		rand_surSuff_numb = random<int>(0, dwarf_surSuffs.size() - 1);
		randBsuff = random<int>(0, dwarf_Bsuffixes.size() - 1);
		chosenSurname = dwarf_surnames[_getRandomNumber()];
		createName();
	}
	else {
		chosenName = _dwarf_Gnames[_getRandomNumber()];
		randBsuff = random<int>(0, dwarf_Gsuffixes.size() - 1);
		randBsuff = random<int>(0, dwarf_Bsuffixes.size() - 1);
		chosenSurname = dwarf_surnames[_getRandomNumber()];
		createName();
	}
}

