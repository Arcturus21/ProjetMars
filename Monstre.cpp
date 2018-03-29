#include "Monstre.h"

using namespace std;

Monstre::Monstre(int vie, int atq, int def, int atqSpe, int defSpe, float vitesse, Type type, std::string nom):
    _vie(vie), _maxPdv(vie), _attaque(atq), _defense(def), _atqSpe(atqSpe), _defSpe(defSpe), _vitesse(vitesse), _type(type), _nom(nom)
{
    //ctor
}

Monstre::~Monstre()
{
    //dtor
}

void Monstre::recevoirDegats(int nbDegats)
{
    cout << _nom << " recoit " << nbDegats << " degats." << endl;
    _vie-=nbDegats;
    if(_vie<0)
        _vie=0;
}

void Monstre::attaquer(Monstre& cible)
{
    cout << _nom << " attaque " << cible._nom << "..." << endl;
    cible.recevoirDegats(_attaque);
}

bool Monstre::attaquer(Monstre& cible, const Attaque& atq)
{
    cout << endl << _nom << " attaque " << atq.GetNom() << " !" << endl;

    int degat=atq.GetPuissance()/10;

    cible.recevoirDegats(degat);

    return true;
}

void Monstre::boirePotionDeVie(int nbSoin)
{
    cout << _nom << " boit une potion et recupere " << nbSoin << " points de vie." << endl;
    _vie+=nbSoin;
    if(_vie>_maxPdv)
        _vie=_maxPdv;
}

Attaque Monstre::GetAttaque(int indAttaque)
{
    if(_listAttaque.size()<=indAttaque)
        return Attaque();
    return _listAttaque[indAttaque];
}

float Monstre::GetDegatAttaque(const Attaque& atq, const Monstre& cible) const
{
    const float ratioDegat = 0.1;
    float degatInfliges=0;
    if(atq.IsPhysique())
    {
        degatInfliges = atq.GetPuissance() * _attaque/cible._defense * Type::GetRapportType(atq.GetType(), cible.GetType()) * ratioDegat;
    }
    else
    {
        degatInfliges = atq.GetPuissance() * _atqSpe/cible._defSpe * Type::GetRapportType(atq.GetType(), cible.GetType()) * ratioDegat;
    }
}

void Monstre::SetListAttaque(std::vector<Attaque> listAttaque)
{
    for(int i=0; i<listAttaque.size(); i++)
    {
        _listAttaque.push_back(listAttaque[i]);
    }
}


void Monstre::PrintAttaque()
{
    for(int i=0;i<4;i++)
    {
        if(i<_listAttaque.size())
        {
            cout << i+1 << ". " << _listAttaque[i].GetNom() << endl;
        }
        else
        {
            cout << i+1 << ". _______" << endl;
        }
    }
}
