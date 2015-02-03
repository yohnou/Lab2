#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_


class DynamicArray
{

public:
	DynamicArray(int _capacite = 100);
	~DynamicArray();

	void setElement(unsigned int _index, int _valeur);
	int getElement(unsigned int _index);
	unsigned int getCapacite();
	void setCapacite(unsigned int _capacite);



private:
	int *tabElements;
	unsigned int capacite;

};


#endif //DYNAMICARRAY_H_