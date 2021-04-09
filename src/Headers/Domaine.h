//
// Created by mathis on 05/04/2021.
//

#ifndef SKIPISCINE_DOMAINE_H
#define SKIPISCINE_DOMAINE_H
#include "Sommet.h"
#include "Trajet.h"




class Domaine {
private:
    std::map<int, Sommet*> m_sommets;
    std::map<int, Trajet*> m_trajets;
    int m_ordre; // nombre de sommmets
    int m_taille; // nombre d'arcs
    t_mapDuree m_matriceDuree;
    std::vector<std::pair<std::string,int>> m_vecteurCapacite;


public:
    //Constructeur et destructeur
    Domaine();
    ~Domaine();

    //Méthodes
    void creationSommets(const std::vector<t_chargeSommets>& _som);
    void initialisation(const t_chargeFichier &fCharge);
    void creationTrajets(const std::vector<t_chargeTrajet> &_tra);
    void afficheTrajets(const char& type='N',std::string sommetChoisie="n");
    void afficheSommets(const std::string& sommetChoisie="n");
    bool estNombre(const std::string &str);
    void plusCourtChemin(const bool& estDijkstra,const bool& estOpti,const std::vector<std::pair<std::string,bool>>& optiTrajets, int s0, int sF=-5);

    void affichePlusCourtChemin(const int& s0,const int& sF,  std::map<int,int>& pred,const float& poids,const bool& estOpti,const std::vector<std::pair<std::string,bool>>& optiTrajets,const bool& complexe=true);
    void getPlusCourtCheminRecursif(int i, std::map<int,int> pred, const int& initial,std::vector<int>& listePoints,bool& cheminPossible);
    std::string convertSecondeHeuresMinS(const float& seconde);
    int returnPointId(const std::string &entree);
    bool changementDuree();
    int entreePoint(const std::string &phrase);
    void afficheInfo();

    /***************/

    //Gestion des flots algo Ford
    std::vector<Sommet> bfsFord(const Sommet& _source,std::vector<Sommet>& vecteurPredecesseur);
    std::vector<bool> initialisationMarquage();


    /*************/
    int entrerUnNombrePositif(const std::string &phrase);


    //Getters & Setters
    void setOrdre(int _ordre);
    void setTaille(int _taille);
    int getOrdre() const;
    int getTaille() const;
    t_mapDuree& getMatriceDuree();
    std::vector<std::pair<std::string, int>>& getVecteurCapacite();
    void setVecteurCapacite(const std::pair<std::string,int> _vecteurCapacite);


    bool modifDureeBD(const std::string &categorie);

    std::map<int,int> dijkstraOpti(const int &sInit, std::map<int, float> &poids,const std::vector<std::string>& typeAEnlever = std::vector<std::string>());

    std::map<int,int> parcoursBFSOpti(const int& _num,const std::vector<std::string>& typeAEnlever= std::vector<std::string>());
};


#endif //SKIPISCINE_DOMAINE_H
