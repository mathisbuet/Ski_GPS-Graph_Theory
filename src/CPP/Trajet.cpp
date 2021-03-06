//
// Created by mathis on 05/04/2021.
//

#include "../Headers/Trajet.h"

//Constructeur

Trajet::Trajet(const int &_num, const std::string &_nom, const std::string &_type,  Sommet *depart,  Sommet *arrivee, const t_mapDuree& matriceDuree)
      :AbstractIdentite(_num,_nom), m_type(_type),m_flot(0)
{
    m_sommets.first=depart;
    m_sommets.second=arrivee;
    setGType();
    m_duree = calculDuree(matriceDuree);
}

Trajet::Trajet(const int& _num, const std::string& _nom, const std::string& _type,  Sommet* depart,  Sommet* arrivee, const float& _duree, const char& DouI)
       :AbstractIdentite(_num,_nom), m_type(_type),m_flot(0),m_duree(_duree),m_gType(DouI)
{
    m_sommets.first=depart;
    m_sommets.second=arrivee;

}

Trajet::Trajet( const std::string &_type)
        :AbstractIdentite(-1,"fake"), m_type(_type)
{
    setGType();
}

//Méthodes
///Sous-programme permettant d'afficher un trajet
void Trajet::affichage(){
    std::cout << "Trajet n'"<<getNum() << ": ";
    print(getNom(),retourneCouleurType());
    std::cout <<" (" << returnNomType();

    std::cout << ") allant du point " <<m_sommets.first->afficheSimple() << " a "  << m_sommets.second->afficheSimple() << std::endl;
}

///Affichage complexe d'un trajet
void Trajet::affichageComplexe(const bool& partant){
    std::cout << "n'"<<getNum() << ": "<<getNom() <<" ("<< returnNomType();

    if(partant)
        std::cout << ") allant a "  << m_sommets.second->getNom() << std::endl;
    else
        std::cout << ") partant de "  << m_sommets.first->getNom() << std::endl;
}

///Retourne la couleur du trajet pour le print selon son type
int Trajet::retourneCouleurType(){
    if(getType().size()==1){

        switch(getType()[0]){
            case 'V':
                return color_dark_green;
                break;
            case 'B':
                return color_dark_blue;
                break;
            case 'R':
                return color_dark_red;
                break;
            case 'N':
                return color_light_gray;
                break;
        }
    }
    if(getType()=="KL")
        return color_pink;
    if(getType()=="SURF")
        return color_cyan;
    if(getType()=="BUS")
        return color_yellow;

    return color_orange;

}

///Sous-programme permettant de retourner le nom complet du type du trajet
std::string Trajet::returnNomType(){

    if(getType().size()==1){

        switch(getType()[0]){
            case 'V':
                return "Piste verte";
                break;
            case 'B':
                return "Piste bleu";
                break;
            case 'R':
                return "Piste rouge";
                break;
            case 'N':
                return "Piste noire";
                break;
        }
    }
    else{
        if(getType()=="KL")
            return "Piste de kilometre lance";
        else if(getType()=="SURF")
            return "Snowpark";
        else if(getType()=="TPH")
            return "Telepherique";
        else if(getType()=="TC")
            return "Telecabine";
        else if(getType()=="TSD")
            return "Telesiege debrayable";
        else if(getType()=="TS")
            return "Telesiege";
        else if(getType()=="TK")
            return "Teleski";
        else if(getType()=="BUS")
            return "Navette";

    }
    return "bug";

}



//Getters & Setters

std::string Trajet::getType() const {
    return m_type;
}

float Trajet::calculDuree(const t_mapDuree& matriceDuree) {
    int depart= m_sommets.first->getAltitude();
    int arrivee= m_sommets.second->getAltitude();

    if(getGType()=='B')
        return matriceDuree.find('B')->second.find(getNom())->second[0];
    else if(getGType()=='D')
        return (float)(matriceDuree.find('D')->second.find(getType())->second[0] * abs(arrivee-depart)) / 100;
    else if(getGType()=='R')
        return (float)(matriceDuree.find('R')->second.find(getType())->second[0] * abs(arrivee-depart)) / 100 + matriceDuree.find('R')->second.find(getType())->second[1];

    return 0;

}

std::pair<Sommet*,Sommet*> Trajet::getSommets() const{
    return m_sommets;
}

void Trajet::setGType(){
    std::string type=getType();

    if(type=="V"||type=="B"||type=="R"||type=="N"||type=="KL"||type=="SURF")
        m_gType='D';
    else if (type[0]=='T')
        m_gType='R';
    else if (type=="BUS")
        m_gType='B';

}

void Trajet::setDuree(float _duree) {
    m_duree = _duree;
}

char Trajet::getGType() const{
    return m_gType;
}

float Trajet::getDuree() const {
    return m_duree;
}

int Trajet::getFlot() const {
    return m_flot;
}

void Trajet::setFlot(const int& _flot) {
    m_flot=_flot;
}
