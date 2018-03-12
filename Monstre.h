#ifndef MONSTRE_H
#define MONSTRE_H

#include <iostream>
#include <string>

class Monstre
{
    public:
        Monstre(int vie, int atq, int def, int atqSpe, int defSpe, float vitesse, std::string type, std::string nom);
        virtual ~Monstre();

        void recevoirDegats(int nbDegats);
        void attaquer(Monstre& cible);
        void boirePotionDeVie(int nbSoin);

        ///GETTER & SETTER
        bool IsAlive(){return _vie>0;};
        std::string GetNom(){return _nom;};

        ///CONSOLE CONTROL
        void PrintState(){std::cout << _nom << " a " << _vie << "/" << _maxPdv << " pdv." << std::endl;};

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
