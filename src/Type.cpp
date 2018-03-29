#include "Type.h"

float Type::_rapportType[][6]={{1,1,1,1,1,0},
                                {1,0.5,0.5,2,1,1},
                                {1,2,0.5,0.5,1,1},
                                {1,0.5,2,0.5,0.5,1},
                                {1,1,2,0.5,0.5,1},
                                {2,1,1,1,0.5,2}};

Type::Type(EnumType indice, std::string nom) : _indice(indice),_nom(nom)
{
    //ctor
}

Type::~Type()
{
    //dtor
}
