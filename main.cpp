#include <iostream>
#include <vector>
#include "Monstre.h"

using namespace std;

///GESTION DES DEGATS EN FONCTION DE L'ATTAQUE ET DU TYPE
///GESTION DU CALCUL DES DEGATS
///GESTION DE LA VITESSE DES MONSTRES
///GESTION DE LA PRECISION


int main()
{
    Monstre carapuce(45, 12, 15, 15, 10, 1.0, "eau", "Carapuce"),
            salameche(42, 14, 10, 15, 10, 1.0, "feu", "Salameche");

    Attaque atqCharge("charge", 25, Normal, true),
            atqEcume("ecume", 60, Eau, false),
            atqPistoletAO("Pistolet a O", 75, Eau, false),
            atqGriffe("griffe", 40, Normal, true),
            atqFlammeche("flammeche", 55, Feu, false),
            atqLanceFlamme("Lance-Flamme", 80, Feu, false);

    vector<Attaque> listAtqCara;
    listAtqCara.push_back(atqCharge);
    listAtqCara.push_back(atqEcume);
    listAtqCara.push_back(atqPistoletAO);
    vector<Attaque> listAtqSala;
    listAtqSala.push_back(atqGriffe);
    listAtqSala.push_back(atqFlammeche);
    listAtqSala.push_back(atqLanceFlamme);
    listAtqSala.push_back(atqCharge);

    carapuce.SetListAttaque(listAtqCara);
    salameche.SetListAttaque(listAtqSala);

    carapuce.PrintAttaque();
    salameche.PrintAttaque();

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
            int indAttaque;
            Attaque atqChoisi;

            while(atqChoisi.GetNom()=="default")
            {
                cout << "Choisissez une Attaque :" << endl;
                monstres[tourMonstre].PrintAttaque();
                cin >> indAttaque;
                atqChoisi=monstres[tourMonstre].GetAttaque(indAttaque-1);
            }

            cout << endl << monstres[tourMonstre].GetNom() << " attaque " << atqChoisi.GetNom() << " !" << endl << endl;

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
