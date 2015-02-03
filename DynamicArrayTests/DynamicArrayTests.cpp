#include "stdafx.h"
#include "CppUnitTest.h"

#include "../DynamicArray/dynamicArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DynamicArrayTests
{
	TEST_CLASS(DynamicArrayTests)
	{
	public:

		/////////////////////////////////////////////////
		// Partie 1  (lab 2)
		/////////////////////////////////////////////////

		TEST_METHOD(la_capacite_par_defaut_d_un_dynamicArray_est_de_100)
		{
			//Arrange
			const int CAPACITE_DEFAUT = 100;
			DynamicArray tableau;

			//Action
			int capacite = tableau.getCapacite();

			//Assert
			Assert::AreEqual(CAPACITE_DEFAUT, capacite);
		}

		TEST_METHOD(la_valeur_par_defaut_des_elements_d_un_dyanmicArray_est_0)
		{
			//Action
			DynamicArray tableau;

			//Assert
			for (int i = 0; i < tableau.getCapacite(); i++)
			{
				Assert::AreEqual(0, tableau.getElement(i));
			}
		}


		TEST_METHOD(setElement_devrait_initialiser_un_element_du_dynamicArray)
		{
			//Arrange
			const int NOUVELLE_VALEUR_ELEMENT = 99;
			const int INDEX_ELEMENT = 1;
			DynamicArray tableau;

			//Action
			tableau.setElement(INDEX_ELEMENT, NOUVELLE_VALEUR_ELEMENT);

			//Assert
			Assert::AreEqual(NOUVELLE_VALEUR_ELEMENT, tableau.getElement(INDEX_ELEMENT));
		}

		TEST_METHOD(augumenter_la_capacite_d_un_dynamicArray_devrait_preserver_le_contenu_deja_present)
		{
			//Arrange
			const int CAPACITE_DEPART = 3;
			const int NOUVELLE_CAPACITE = 5;

			DynamicArray tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, i*i);
			}

			//Action
			tableau.setCapacite(NOUVELLE_CAPACITE);

			//Assert
			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				Assert::AreEqual(int(i*i), tableau.getElement(i));
			}
			for (unsigned int i = CAPACITE_DEPART; i < NOUVELLE_CAPACITE; ++i)
			{
				Assert::AreEqual(0, tableau.getElement(i));
			}
		}

		TEST_METHOD(diminuer_la_capacite_d_un_dynamicArray_devrait_modifier_sa_capacite)
		{
			//Arrange
			const int CAPACITE_DEPART = 5;
			const unsigned int NOUVELLE_CAPACITE = 3;

			DynamicArray tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, i*i);
			}

			//Action
			tableau.setCapacite(NOUVELLE_CAPACITE);

			//Assert
			Assert::AreEqual(NOUVELLE_CAPACITE, tableau.getCapacite());
			for (unsigned int i = 0; i < NOUVELLE_CAPACITE; ++i)
			{
				Assert::AreEqual(int(i*i), tableau.getElement(i));
			}
		}

		TEST_METHOD(ajouter_un_element_au_dela_de_la_capacite_devrait_auto_agrandir_le_dynamicArray)
		{
			//Arrange
			const int CAPACITE_DEPART = 5;
			const int NOUVELLE_ELEMENT = 99;
			const unsigned int INDEX_NOUVEL_ELEMENT = 10;
			DynamicArray tableau(CAPACITE_DEPART);

			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				tableau.setElement(i, i*i);
			}

			//Action
			tableau.setElement(INDEX_NOUVEL_ELEMENT, NOUVELLE_ELEMENT);

			//Assert
			// Est-ce que les anciens éléments sont conservés ?
			for (unsigned int i = 0; i < CAPACITE_DEPART; ++i)
			{
				Assert::AreEqual(int(i*i), tableau.getElement(i));
			}
			// Est-ce que les éléments vides sont initialisés à 0 ?
			for (unsigned int i = CAPACITE_DEPART; i < INDEX_NOUVEL_ELEMENT; ++i)
			{
				Assert::AreEqual(0, tableau.getElement(i));
			}
			// Est-ce que le nouvel élément a été ajouté
			Assert::AreEqual(NOUVELLE_ELEMENT, tableau.getElement(INDEX_NOUVEL_ELEMENT));
			Assert::AreEqual(INDEX_NOUVEL_ELEMENT + 1, tableau.getCapacite());
		}


		TEST_METHOD(creer_un_dynamicArray_d_une_capacite_inferieure_a_1_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;

			//Action
			try
			{
				DynamicArray tableau(0);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}


		TEST_METHOD(acceder_a_un_element_hors_du_tableau_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;
			const int CAPACITE = 5;

			DynamicArray tableau(CAPACITE);

			//Action
			try
			{
				int element = tableau.getElement(CAPACITE + 1);
			}
			catch (std::out_of_range ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		TEST_METHOD(modifier_la_capacite_d_un_dynamicArray_avec_une_valeur_inferieure_a_1_devrait_lancer_une_excpetion)
		{
			//Arrange
			bool exceptionThrown = false;
			DynamicArray tableau;

			//Action
			try
			{
				tableau.setCapacite(0);
			}
			catch (std::invalid_argument ex)
			{
				exceptionThrown = true;
			}

			//Assert
			Assert::IsTrue(exceptionThrown);
		}

		/////////////////////////////////////////////////
		// PARTIE 2 (lab 3)
		/////////////////////////////////////////////////

	//	TEST_METHOD(le_constructeur_de_copie_devrait_copier_tout_le_contenu_d_un_dynamicArray)
	//	{
	//		//Arrange
	//		const int CAPACITE = 5;
	//		DynamicArray tableau1(CAPACITE);

	//		for (unsigned int i = 0; i < CAPACITE; ++i)
	//		{
	//			tableau1.setElement(i, i*i);
	//		}

	//		//Action
	//		DynamicArray tableau2(tableau1);

	//		//Assert
	//		
	//		// AssertDynamicArraysAreEqual est un méthode privée déclarée à la fin de la classe de tests. Enlever les commentaire pour y avoir accès.
	//		AssertDynamicArraysAreEqual(tableau1, tableau2); 

	//	}

	//	TEST_METHOD(l_operateur_egal_devrait_copier_tout_le_contenu_d_un_dynamicArray)
	//	{
	//		//Arrange
	//		const int CAPACITE = 5;
	//		DynamicArray tableau1(CAPACITE);
	//		DynamicArray tableau2;

	//		for (unsigned int i = 0; i < CAPACITE; ++i)
	//		{
	//			tableau1.setElement(i, i*i);
	//		}

	//		//Action
	//		tableau2 = tableau1;


	//		//Assert
	//		AssertDynamicArraysAreEqual(tableau1, tableau2);
	//	}

	//	TEST_METHOD(etant_donne_deux_dynamicArrays_identiques_l_operateur_d_egalite_devrait_retourner_vrai)
	//	{
	//		//Arrange
	//		const int CAPACITE = 5;
	//		DynamicArray tableau1(CAPACITE);

	//		for (unsigned int i = 0; i < CAPACITE; ++i)
	//		{
	//			tableau1.setElement(i, i*i);
	//		}

	//		DynamicArray tableau2(tableau1);

	//		//Action-Assert
	//		Assert::IsTrue(tableau1 == tableau2);
	//	}

	//	TEST_METHOD(etant_donne_deux_dynamicArrays_de_capacite_differente_l_operateur_d_egalite_devrait_retourner_faux)
	//	{
	//		//Arrange
	//		DynamicArray tableau1(2);
	//		DynamicArray tableau2(3);

	//		//Action-Assert
	//		Assert::IsFalse(tableau1 == tableau2);
	//	}

	//	TEST_METHOD(etant_donne_deux_dynamicArrays_de_capacite_egale_mais_de_contenu_different_l_operateur_d_egalite_devrait_retourner_faux)
	//	{
	//		//Arrange
	//		DynamicArray tableau1(2);
	//		DynamicArray tableau2(2);
	//		tableau2.setElement(1, 99);

	//		//Action-Assert
	//		Assert::IsFalse(tableau1 == tableau2);
	//	}


	//	TEST_METHOD(l_operateur_d_addition_devrait_concatener_deux_dynamicArrays_si_differents)
	//	{
	//		//Arrange
	//		const int TABLEAU_1_CAPACITE_DEPART = 3;
	//		const int TABLEAU_2_CAPACITE = 5;

	//		DynamicArray tableau1(TABLEAU_1_CAPACITE_DEPART);
	//		for (unsigned int i = 0; i < TABLEAU_1_CAPACITE_DEPART; ++i)
	//		{
	//			tableau1.setElement(i, i*i);
	//		}
	//		
	//		DynamicArray tableau2(TABLEAU_2_CAPACITE);
	//		for (unsigned int i = 0; i < TABLEAU_2_CAPACITE; ++i)
	//		{
	//			tableau2.setElement(i, i*i*i);
	//		}

	//		//Action
	//		tableau1 += tableau2;

	//		//Assert
	//		Assert::AreEqual(TABLEAU_1_CAPACITE_DEPART + TABLEAU_2_CAPACITE, tableau1.getCapacite());
	//		
	//		//Est-ce que les éléments du tableau 1 sont toujours présents (à partir du début)
	//		for (unsigned int i = 0; i < TABLEAU_1_CAPACITE_DEPART; ++i)
	//		{
	//			Assert::AreEqual(int(i*i), tableau1.getElement(i));
	//		}
	//		
	//		//Est-ce que les éléments du tableau 2 ont été ajoutés à la suite du tableau 1 ?
	//		for (unsigned int i = TABLEAU_1_CAPACITE_DEPART; i < tableau1.getCapacite(); ++i)
	//		{
	//			Assert::AreEqual(tableau2.getElement(i - TABLEAU_1_CAPACITE_DEPART), tableau1.getElement(i));
	//		}
	//	}

	//	TEST_METHOD(l_operateur_d_addition_devrait_ajoueter_le_dynamicArray_a_sa_suite_si_identique)
	//	{
	//		//Arrange
	//		const int TABLEAU_CAPACITE_DEPART = 3;

	//		DynamicArray tableau(TABLEAU_CAPACITE_DEPART);
	//		for (unsigned int i = 0; i < TABLEAU_CAPACITE_DEPART; ++i)
	//		{
	//			tableau.setElement(i, i*i);
	//		}

	//		//Action
	//		tableau += tableau;

	//		//Assert
	//		Assert::AreEqual(TABLEAU_CAPACITE_DEPART * 2, tableau.getCapacite());

	//		for (unsigned int i = 0; i < TABLEAU_CAPACITE_DEPART; ++i)
	//		{
	//			Assert::AreEqual(int(i*i), tableau.getElement(i));
	//		}

	//		for (unsigned int i = TABLEAU_CAPACITE_DEPART; i < tableau.getCapacite(); ++i)
	//		{
	//			int valeurElement = int((i - TABLEAU_CAPACITE_DEPART) * (i - TABLEAU_CAPACITE_DEPART));
	//			Assert::AreEqual(valeurElement, tableau.getElement(i));
	//		}
	//	}


	//private:
	//	void AssertDynamicArraysAreEqual(DynamicArray & dynamicArray1, DynamicArray & dynamicArray2)
	//	{
	//		Assert::AreEqual(dynamicArray1.getCapacite(), dynamicArray2.getCapacite());
	//		for (int i = 0; i < dynamicArray1.getCapacite(); i++)
	//		{
	//			Assert::AreEqual(dynamicArray1.getElement(i), dynamicArray2.getElement(i));
	//		}
	//	}

	};
}