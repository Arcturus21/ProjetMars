#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>

typedef enum
{
    Normal,
    Feu,
    Eau,
    Plante,
    Electrique,
    Tenebre,
    Last
}Type;

class Attaque
{
    public:
        Attaque();
        Attaque(std::string nom, float puissance, Type type, bool physique);
        Attaque(const Attaque& a);
        virtual ~Attaque();

        std::string GetNom(){return _nom;};
        float GetPuissance(){return _puissance;};
        Type GetType(){return _type;};
        bool IsPhysique(){return _physique;};

    protected:
        std::string _nom;
        float _puissance;
        int _nbUtilisation;
        Type _type;
        bool _physique;

    private:
};

#endif // ATTAQUE_H
