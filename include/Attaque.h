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

        std::string GetNom() const {return _nom;};
        float GetPuissance() const {return _puissance;};
        Type GetType() const {return _type;};
        bool IsPhysique() const {return _physique;};

    protected:
        std::string _nom;
        float _puissance;
        int _nbUtilisation;
        Type _type;
        bool _physique;

    private:
};

#endif // ATTAQUE_H
