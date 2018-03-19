#include "Attaque.h"

Attaque::Attaque() : _nom("default"), _puissance(0), _type(Last), _physique(true)
{

}

Attaque::Attaque(std::string nom, float puissance, Type type, bool physique) : _nom(nom), _puissance(puissance), _type(type), _physique(physique)
{
    //ctor
}

Attaque::Attaque(const Attaque& a):_nom(a._nom), _puissance(a._puissance), _type(a._type), _physique(a._physique)
{

}

Attaque::~Attaque()
{
    //dtor
}
