#include "motor.h"
#include <chrono>
#include <thread>


class masina{
protected:
    std::string marca;
    std::string model;
    std::string culoare;
    int nr_locuri;
    std::string cutie_viteza;
    int nr_viteze;
    int viteza_maxima;
    motor Motor;
private:
    void afisare_info(float pozitie,int treapta) const;
public:
    masina(motor&,std::string,std::string,std::string,int,std::string,int,int);
    virtual ~masina();
    motor& getMotor(){return this->Motor;}
    std::string getModel() const {return this->model;}
    std::string getMarca() const{return this->marca;}
    std::string getCuloare() const{return this->culoare;}
    std::string getCutieViteza() const {return this->cutie_viteza;}
    int getNrLocuri() const {return this->nr_locuri;}
    int getNrViteze() const {return this->nr_viteze;}
    int getVitezaMaxima() const {return this->viteza_maxima;}
    virtual void sunet() const;
    void intrecere(const masina &x);
    friend std::ostream& operator<<(std::ostream& os, const masina& m);
    masina& operator=(const masina &other){
        this->marca = other.marca;
        this->model = other.model;
        this->culoare = other.culoare;
        this->nr_locuri = other.nr_locuri;
        this->cutie_viteza = other.cutie_viteza;
        this->nr_viteze = other.nr_viteze;
        this->viteza_maxima = other.viteza_maxima;
        this->Motor = other.Motor;

        return *this;
    }
    int calculare_delay() const;
    virtual void accelereaza(int &treapta_curenta,float &pozitie_curenta, float viteza,int delay) const ;
    void franeaza(int &treapta_curenta,float &pozitie_curenta, float viteza);
};


