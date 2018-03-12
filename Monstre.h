#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include <string>

class Monstre
{
    public:
        Monstre(int vie, int atq, int def, int atqSpe, int defSpe, float vitesse, std::string type, std::string nom);
        virtual ~Monstre();



    protected:
        int _vie, _maxPdv;
        int _attaque;
        int _defense;
        int _atqSpe;
        int _defSpe;
        float _vitesse;
        std::string _type;
        std::string _nom;

    private:
};

#endif // MONSTRE_H
