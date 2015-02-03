#include "dynamicArray.h"
#include <system_error>


DynamicArray::DynamicArray(int _capacite)
{
	if (_capacite < 1) throw std::invalid_argument("Impossible d'avoir une capacité inférieure à 1");
	capacite = _capacite;
	tabElements = new int[_capacite];
	for (int i = 0; i < capacite; i++)
	{
		tabElements[i] = 0;
	}

}

DynamicArray::~DynamicArray()
{
	delete[] tabElements;
}

unsigned int DynamicArray::getCapacite()
{
	return capacite;
}

void DynamicArray::setElement(unsigned int _index, int _valeur)
{
	
	if (_index >= capacite)
	{
		setCapacite(_index + 1);
	}
	tabElements[_index] = _valeur;
}

int DynamicArray::getElement(unsigned int _index)
{ 
	if (_index < 0 || _index > capacite) throw std::out_of_range("hors limite");
	return tabElements[_index];
}

void DynamicArray::setCapacite(unsigned int _capacite)
{
	if (_capacite < 1) throw std::invalid_argument("marche pas");
	int *tempTab = new int[_capacite];
	for (int i = 0; i < _capacite; i++)
	{
		if (i < capacite)
		{
			tempTab[i] = tabElements[i];	
		}
		else
		{
			tempTab[i] = 0;
		}
	}
	capacite = _capacite;
	delete[] tabElements;
	tabElements = tempTab;
}
