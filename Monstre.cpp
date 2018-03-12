#include "Monstre.h"

Monstre::Monstre(int vie, int atq, int def, int atqSpe, int defSpe, float vitesse, std::string type, std::string nom):
    _maxPdv(vie), _vie(vie), _attaque(atq), _defense(def), _atqSpe(atqSpe), _defSpe(defSpe), _vitesse(vitesse), _type(type), _nom(nom)
{
    //ctor
}

Monstre::~Monstre()
{
    //dtor
}
