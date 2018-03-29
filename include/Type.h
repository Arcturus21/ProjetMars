#ifndef TYPE_H
#define TYPE_H

#include <iostream>

typedef enum
{
    Normal,
    Feu,
    Eau,
    Plante,
    Electrique,
    Tenebre,
    Last
}EnumType;

class Type
{
    public:
        Type(EnumType indice, std::string nom=""); ///GERER LE NOM AUTOMATIQUEMENT
        virtual ~Type();

        const static float GetRapportType(Type atq, Type cible){return _rapportType[atq.GetIndice()][cible.GetIndice()];};

        EnumType GetIndice()const{return _indice;};
        std::string GetNom()const{return _nom;};

    protected:

    private:
        EnumType _indice;
        std::string _nom;

        static float _rapportType[6][6];
};

#endif // TYPE_H
