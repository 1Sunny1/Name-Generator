#include "pch.h"
#include "NGen.h"
#include <iostream>

void NGen::showGeneratedName() const {
	std::cout << "Your generated name  is: " << chosenName << " " << chosenSurname << "\n";
}

void NGen::showAvaibleNames() const {
	std::cout << "All names avaible:\n\n";
	std::cout << "Male\t\tFemale\n";
	for (int i = 0; i < _Bnames.size(); ++i) 
		std::cout << _Bnames[i] << "\t\t"<< _Gnames[i] << "\n";
	std::cout << "All surnames avaible:\n\n";
	for (int i = 0; i < surnames.size(); ++i) {
		std::cout << surnames[i] << "\t\t";
		if (i % 2 == 1)
			std::cout << std::endl;
	}
}

void OrcNames::showGeneratedName() const {
	std::cout << "Your generated name is: " << finalName << "\n";
}

void OrcNames::showAvaibleNames() const {
	std::cout << "All orc names avaible:\n\n";
	std::cout << "Male\t\tFemale\n";
	for (int i = 0; i < _orc_Bnames.size(); ++i)
		std::cout << _orc_Bnames[i] << "\t\t" << _orc_Gnames[i] << "\n";
}

void ElfNames::showGeneratedName() const {
	std::cout << "Your generated name is: " << finalName << "\n";
}

void ElfNames::showAvaibleNames() const {
	std::cout << "All elven names avaible:\n\n";
	std::cout << "Male\t\tFemale\n";
	for (int i = 0; i < _elf_Bnames.size(); ++i)
		std::cout << _elf_Bnames[i] << "\t\t" << _elf_Gnames[i] << "\n";
}

void DwarfNames::showGeneratedName() const {
	std::cout << "Your generated name is: " << finalName << "\n";
}

void DwarfNames::showAvaibleNames() const {
	std::cout << "All dwarfen names avaible:\n\n";
	std::cout << "Male\t\tFemale\n";
	for (int i = 0; i < _dwarf_Bnames.size(); ++i)
		std::cout << _dwarf_Bnames[i] << "\t\t" << _dwarf_Gnames[i] << "\n";
}
