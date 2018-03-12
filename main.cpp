#include <iostream>
#include <vector>
#include "Monstre.h"

using namespace std;

int main()
{
    Monstre carapuce(45, 12, 15, 15, 10, 1.0, "eau", "Carapuce"),
            salameche(42, 14, 10, 15, 10, 1.0, "feu", "Salameche");

    vector<Monstre> monstres;
    monstres.push_back(carapuce);
    monstres.push_back(salameche);

    vector<int> nbPotions;
    nbPotions.push_back(1);
    nbPotions.push_back(1);

    int tourMonstre=0;

    while(monstres[0].IsAlive() && monstres[1].IsAlive())
    {
        for(unsigned int i=0;i<monstres.size();i++)
        {
            monstres[i].PrintState();
        }
        cout << endl;

        int choix=0;
        while(choix != 1 && choix != 2)
        {
            cout << "Que doit faire " << monstres[tourMonstre].GetNom() << " ?" << endl;
            cout << "1. Attaquer" << endl << "2. Boire une Potion (" << nbPotions[tourMonstre] << " restantes)" << endl;
            cout << "Votre choix : ";
            cin >> choix;
            if(choix==2 && nbPotions[tourMonstre]<=0)
            {
                cout << endl << "Plus de potions disponibles..." << endl;
                choix=0;
            }
            if(choix!=1 && choix!=2)
            {
                cout << "Choix incorrecte, vous devez faire un autre choix." << endl << endl;
            }
        }

        cout << endl;
        if(choix==1)
        {
            monstres[tourMonstre].attaquer(monstres[(tourMonstre+1)%2]);
        }
        else
        {
            monstres[tourMonstre].boirePotionDeVie(20);
            nbPotions[tourMonstre]--;
        }
        tourMonstre=(tourMonstre+1)%2;
        cout << endl;
    }

    if(!monstres[0].IsAlive())
    {
        cout << monstres[0].GetNom() << " est K.O." << endl;
        cout << monstres[1].GetNom() << " gagne le combat" << endl;
    }
    else if(!monstres[1].IsAlive())
    {
        cout << monstres[1].GetNom() << " est K.O." << endl;
        cout << monstres[0].GetNom() << " gagne le combat" << endl;
    }

    return 0;
}
