#include <iostream>
#include <cstring>
using namespace std;
//Clasa de baza
class Zbor
{
protected:
    int id_zbor;
    char* tip_zbor;
    char* destinatie;
    int durata;
    char* data;
    char* ora_plecare;
    char* tip_aeronava;
public:
    //Constructor fara parametrii
    Zbor() : id_zbor(0), tip_zbor(nullptr), destinatie(nullptr), durata(0), data(nullptr), ora_plecare(nullptr), tip_aeronava(nullptr) {}
    //Constructor cu parametrii
    Zbor(int id, const char* tip, const char* dest, int dur, const char* dt, const char* ora, const char* aero)
        : id_zbor(id), tip_zbor(nullptr), destinatie(nullptr), durata(dur), data(nullptr), ora_plecare(nullptr), tip_aeronava(nullptr)
    {

        if (tip != nullptr) {
            tip_zbor = new char[strlen(tip) + 1];
            strcpy(tip_zbor, tip);
        }

        if (dest != nullptr) {
            destinatie = new char[strlen(dest) + 1];
            strcpy(destinatie, dest);
        }

        if (dt != nullptr) {
            data = new char[strlen(dt) + 1];
            strcpy(data, dt);
        }

        if (ora != nullptr) {
            ora_plecare = new char[strlen(ora) + 1];
            strcpy(ora_plecare, ora);
        }

        if (aero != nullptr) {
            tip_aeronava = new char[strlen(aero) + 1];
            strcpy(tip_aeronava, aero);
        }
    }
    //Constructorul de copiere
    Zbor(const Zbor& z)
    {
        this->id_zbor = z.id_zbor;
        this->durata = z.durata;
        //Pentru cele de tip char* alocam memorie daca sunt diferite de nullptr
        if (z.tip_zbor != nullptr) {
            this->tip_zbor = new char[strlen(z.tip_zbor) + 1];
            strcpy(this->tip_zbor, z.tip_zbor);
        }
        else
            this->tip_zbor = nullptr;

        if (z.destinatie != nullptr) {
            this->destinatie = new char[strlen(z.destinatie) + 1];
            strcpy(this->destinatie, z.destinatie);
        }
        else
            this->destinatie = nullptr;

        if (z.data != nullptr) {
            this->data = new char[strlen(z.data) + 1];
            strcpy(this->data, z.data);
        }
        else
            this->data = nullptr;

        if (z.ora_plecare != nullptr) {
            this->ora_plecare = new char[strlen(z.ora_plecare) + 1];
            strcpy(this->ora_plecare, z.ora_plecare);
        }
        else
            this->ora_plecare = nullptr;

        if (z.tip_aeronava != nullptr) {
            this->tip_aeronava = new char[strlen(z.tip_aeronava) + 1];
            strcpy(this->tip_aeronava, z.tip_aeronava);
        }
        else
            this->tip_aeronava = nullptr;
    }
    //Destructor
    ~Zbor()
    {
        delete[] tip_zbor;
        delete[] destinatie;
        delete[] data;
        delete[] ora_plecare;
        delete[] tip_aeronava;
    }
    //Metode de access
    void SetId_zbor(int z1)
    {
        this->id_zbor = z1;
    }
    int GetId_zbor() const
    {
        return this->id_zbor;
    }

    void SetDurata(int d1)
    {
        this->durata = d1;
    }
    int GetDurata()
    {
        return this->durata;
    }

    void SetTip_zbor(const char* tip)
    {
        if (this->tip_zbor != nullptr)
            delete[] this->tip_zbor;
        this->tip_zbor = new char[strlen(tip) + 1];
        strcpy(this->tip_zbor, tip);
    }
    char* GetTip_zbor()
    {
        return this->tip_zbor;
    }
    void SetDestinatie(const char* des)
    {
        if (this->destinatie != nullptr)
            delete[] this->destinatie;
        this->destinatie = new char[strlen(des) + 1];
        strcpy(this->destinatie, des);
    }
    char* GetDestinatie()
    {
        return this->destinatie;
    }
    void SetData(const char* d)
    {
        if (this->data != nullptr)
            delete[] this->data;
        this->data = new char[strlen(d) + 1];
        strcpy(this->data, d);
    }

    char* GetData()
    {
        return this->data;
    }

    void SetOra_plecare(const char* ora)
    {
        if (this->ora_plecare != nullptr)
            delete[] this->ora_plecare;
        this->ora_plecare = new char[strlen(ora) + 1];
        strcpy(this->ora_plecare, ora);
    }

    char* GetOra_plecare()
    {
        return this->ora_plecare;
    }

    void SetTip_aeronova(const char* aero)
    {
        if (this->tip_aeronava != nullptr)
            delete[] this->tip_aeronava;
        this->tip_aeronava = new char[strlen(aero) + 1];
        strcpy(this->tip_aeronava, aero);
    }

    char* GetTip_aeronova()
    {
        return this->tip_aeronava;
    }

    //Supraincarcare operator atribuire
    Zbor& operator = (const Zbor& z)
    {
        this->id_zbor = z.id_zbor;
        this->durata = z.durata;

        if (this->tip_zbor != nullptr)
            delete[] this->tip_zbor;
        this->tip_zbor = new char[strlen(z.tip_zbor) + 1];
        strcpy(this->tip_zbor, z.tip_zbor);

        if (this->destinatie != nullptr)
            delete[] this->destinatie;
        this->destinatie = new char[strlen(z.destinatie) + 1];
        strcpy(this->destinatie, z.destinatie);

        if (this->data != nullptr)
            delete[] this->data;
        this->data = new char[strlen(z.data) + 1];
        strcpy(this->data, z.data);

        if (this->ora_plecare != nullptr)
            delete[] this->ora_plecare;
        this->ora_plecare = new char[strlen(z.ora_plecare) + 1];
        strcpy(this->ora_plecare, z.ora_plecare);

        if (this->tip_aeronava != nullptr)
            delete[] this->tip_aeronava;
        this->tip_aeronava = new char[strlen(z.tip_aeronava) + 1];
        strcpy(this->tip_aeronava, z.tip_aeronava);

        return *this;
    }
    friend istream& operator >> (istream& is, Zbor& x);
    friend ostream& operator<<(ostream& os, const Zbor& x);

};

istream& operator>>(istream& in, Zbor& x)
{
    char buf[20];
    cout << "Introduceti id" << '\n';
    in >> x.id_zbor;

    cout << "Introduceti tipul zborului: " << '\n';
    in >> buf;

    delete[] x.tip_zbor;
    x.tip_zbor = new char[strlen(buf) + 1];
    strcpy(x.tip_zbor, buf);

    cout << "Introduceti destinatia avionului: " << '\n';
    in >> buf;

    delete[] x.destinatie;
    x.destinatie = new char[strlen(buf) + 1];
    strcpy(x.destinatie, buf);

    cout << "Introduceti durata zborului: ";
    in >> x.durata;

    cout << "Introduceti data plecarii: " << '\n';
    in >> buf;

    delete[] x.data;
    x.data = new char[strlen(buf) + 1];
    strcpy(x.data, buf);

    cout << "Introduceti ora plecarii: " << '\n';
    in >> buf;

    delete[] x.ora_plecare;
    x.ora_plecare = new char[strlen(buf) + 1];
    strcpy(x.ora_plecare, buf);

    cout << "Introduceti tipul aeronavei: " << '\n';
    in >> buf;

    delete[] x.tip_aeronava;
    x.tip_aeronava = new char[strlen(buf) + 1];
    strcpy(x.tip_aeronava, buf);

    return in;
}

ostream& operator<<(ostream& os, const Zbor& x)
{
    os << "Id zbor: " << x.id_zbor << '\n';
    os << "Tip zbor: " << x.tip_zbor << '\n';
    os << "Destinatie zbor: " << x.destinatie << '\n';
    os << "Durata zbor: " << x.data << '\n';
    os << "Data zborului: " << x.data << '\n';
    os << "Ora plecarii: " << x.ora_plecare << '\n';
    os << "Tipul aeronavei: " << x.tip_aeronava << '\n';
    os << '\n';
    return os;
}

//Clasa ne va ajuta sa retinem in clasa derivata ZborPasageri un vector cu elemente de tipul Pasager
class Pasager
{
private:
    char* nume;
    int varsta;
    int CNP;
    char* nationalitate;
    int nr_telefon;
    char* loc_avion;
public:
    //Constructor fara parametrii
    Pasager() : nume(nullptr), varsta(0), CNP(0), nationalitate(nullptr), nr_telefon(0), loc_avion(nullptr) {}
    //Constructor cu parametrii
    Pasager(const char* num, int vas, int cp, const char* natio, int nr, const char* loc)
        : nume(nullptr), varsta(vas), CNP(cp), nationalitate(nullptr), nr_telefon(nr), loc_avion(nullptr)
    {

        if (num != nullptr) {
            nume = new char[strlen(num) + 1];
            strcpy(nume, num);
        }

        if (natio != nullptr) {
            nationalitate = new char[strlen(natio) + 1];
            strcpy(nationalitate, natio);
        }

        if (loc != nullptr) {
            loc_avion = new char[strlen(loc) + 1];
            strcpy(loc_avion, loc);
        }

    }
    //Constructorul de copiere
    Pasager(const Pasager& p)
    {
        this->varsta = p.varsta;
        this->CNP = p.CNP;
        this->nr_telefon = p.nr_telefon;
        //Pentru cele de tip char* alocam memorie daca sunt diferite de nullptr
        if (p.nume != nullptr) {
            this->nume = new char[strlen(p.nume) + 1];
            strcpy(this->nume, p.nume);
        }
        else
            this->nume = nullptr;

        if (p.nationalitate != nullptr) {
            this->nationalitate = new char[strlen(p.nationalitate) + 1];
            strcpy(this->nationalitate, p.nationalitate);
        }
        else
            this->nationalitate = nullptr;

        if (p.loc_avion != nullptr) {
            this->loc_avion = new char[strlen(p.loc_avion) + 1];
            strcpy(this->loc_avion, p.loc_avion);
        }
        else
            this->loc_avion = nullptr;

    }
    //Destructor
    ~Pasager()
    {
        delete[] nume;
        delete[] nationalitate;
        delete[] loc_avion;
    }
    //Metode de access
    void SetNume(const char* num)
    {
        if (this->nume != nullptr)
            delete[] this->nume;
        this->nume = new char[strlen(num) + 1];
        strcpy(this->nume, num);
    }
    char* GetNume()
    {
        return this->nume;
    }

    void SetVarsta(int v1)
    {
        this->varsta = v1;
    }
    int GetVarsta()
    {
        return this->varsta;
    }

    void SetCNP(int c1)
    {
        this->CNP = c1;
    }
    int GetCNP()
    {
        return this->CNP;
    }

    void SetNationalitate(const char* nat)
    {
        if (this->nationalitate != nullptr)
            delete[] this->nationalitate;
        this->nationalitate = new char[strlen(nat) + 1];
        strcpy(this->nationalitate, nat);
    }
    char* GetNationalitate()
    {
        return this->nationalitate;
    }

    void SetNr_telefon(int nrt)
    {
        this->nr_telefon = nrt;
    }
    int GetNr_telefon()
    {
        return this->nr_telefon;
    }

    void SetNLoc_avion(const char* loc)
    {
        if (this->loc_avion != nullptr)
            delete[] this->loc_avion;
        this->loc_avion = new char[strlen(loc) + 1];
        strcpy(this->loc_avion, loc);
    }
    char* Getloc_avion()
    {
        return this->loc_avion;
    }
    //Supraincarcare operator atribuire
    Pasager& operator = (const Pasager& p)
    {
        this->varsta = p.varsta;
        this->CNP = p.CNP;
        this->nr_telefon = p.nr_telefon;

        if (this->nume != nullptr)
            delete[] this->nume;
        this->nume = new char[strlen(p.nume) + 1];
        strcpy(this->nume, p.nume);

        if (this->nationalitate != nullptr)
            delete[] this->nationalitate;
        this->nationalitate = new char[strlen(p.nationalitate) + 1];
        strcpy(this->nationalitate, p.nationalitate);

        if (this->loc_avion != nullptr)
            delete[] this->loc_avion;
        this->loc_avion = new char[strlen(p.loc_avion) + 1];
        strcpy(this->loc_avion, p.loc_avion);

        return *this;

    }

    friend istream& operator >> (istream& is, Pasager& y);
    friend ostream& operator<<(ostream& os, const Pasager& y);
};

istream& operator>>(istream& in, Pasager& y)
{
    char buf[20];
    cout << "Introduceti numele pasagerului: " << '\n';
    in >> buf;


    delete[] y.nume;
    y.nume = new char[strlen(buf) + 1];
    strcpy(y.nume, buf);

    cout << "Introduceti varsta pasagerului: " << '\n';
    in >> y.varsta;

    cout << "Introduceti CNP ul pasagerului: " << '\n';
    in >> y.CNP;

    cout << "Introduceti nationalitatea pasagerului: " << '\n';
    in >> buf;


    delete[] y.nationalitate;
    y.nationalitate = new char[strlen(buf) + 1];
    strcpy(y.nationalitate, buf);

    cout << "Introduceti numarul de telefon al pasagerului: " << '\n';
    in >> y.nr_telefon;

    cout << "Introduceti locul din avion al pasageului: " << '\n';
    in >> buf;

    delete[] y.loc_avion;
    y.loc_avion = new char[strlen(buf) + 1];
    strcpy(y.loc_avion, buf);

    return in;

}

ostream& operator<<(ostream& os, const Pasager& y)
{
    os << "Nume pasager: " << y.nume << '\n';
    os << "Varsta pasager: " << y.varsta << '\n';
    os << "CNP pasager: " << y.CNP << '\n';
    os << "Nationalitate pasager: " << y.nationalitate << '\n';
    os << "Numar telefon pasager: " << y.nr_telefon << '\n';
    os << "Loc avion pasager: " << y.loc_avion << '\n';
    os << '\n';

    return os;
}

//Prima clasa derivata din clasa Zbor - ZborPasageri
class ZborPasageri : public Zbor
{
private:
    int nr_pasageri;
    Pasager* pasageri;
    int locuri_disponibile;
    int nr_bagaje;
    int greutate_bagaje;
public:
    //Constructor fara parametrii
    ZborPasageri() :Zbor(), nr_pasageri(0), pasageri(nullptr), locuri_disponibile(0), nr_bagaje(0), greutate_bagaje(0) {}
    //Constructor cu parametrii
    ZborPasageri(Zbor zb, int nr_p, Pasager* p, int loc_disp, int nr_b, int greut_b)
        : Zbor(zb), nr_pasageri(nr_p), locuri_disponibile(loc_disp), nr_bagaje(nr_b), greutate_bagaje(greut_b)
    {
        pasageri = new Pasager[nr_pasageri];

        for (int i = 0; i < nr_pasageri; i++)
            pasageri[i] = p[i];
    }
    //Constructor de copiere
    ZborPasageri(const ZborPasageri& p)
        : Zbor(p), nr_pasageri(p.nr_pasageri), locuri_disponibile(p.locuri_disponibile), nr_bagaje(p.nr_bagaje), greutate_bagaje(p.greutate_bagaje)
    {
        pasageri = new Pasager[nr_pasageri];

        for (int i = 0; i < nr_pasageri; i++)
            pasageri[i] = p.pasageri[i];
    }
    //Destructor
    ~ZborPasageri()
    {
        delete[] pasageri;
    }

    //Metode ce access
    void SetNr_pasageri(int p1)
    {
        this->nr_pasageri = p1;
    }
    int GetVarsta()
    {
        return this->nr_pasageri;
    }

    void setPasageri(const Pasager* p, int nr)
    {
        delete[] this->pasageri;
        pasageri = new Pasager[nr_pasageri];
        for (int i = 0; i < nr_pasageri; i++)
            this->pasageri[i] = p[i];
    }

    Pasager* GetPasageri()
    {
        return this->pasageri;
    }

    void SetLocuri_disponibile(int l1)
    {
        this->locuri_disponibile = l1;
    }

    int GetLocuri_disponibile()
    {
        return this->locuri_disponibile;
    }

    void SetNr_bagaje(int n1)
    {
        this->nr_bagaje = n1;
    }

    int GetNr_bagaje()
    {
        return this->nr_bagaje;
    }

    void SetGreutate_bagaje(int g1)
    {
        this->greutate_bagaje = g1;
    }

    int GetGreutatea_bagaje()
    {
        return this->greutate_bagaje;
    }

    //Supraincarcare operator atribuire
    ZborPasageri& operator = (const ZborPasageri& p1)
    {
        if (this != &p1)
        {
            Zbor::operator=(p1);
            delete[] pasageri;

            this->nr_pasageri = p1.nr_pasageri;
            this->locuri_disponibile = p1.locuri_disponibile;
            this->nr_bagaje = p1.nr_bagaje;
            this->greutate_bagaje = p1.greutate_bagaje;

            pasageri = new Pasager[nr_pasageri];
            for (int i = 0; i < nr_pasageri; i++)
                this->pasageri[i] = p1.pasageri[i];
        }
    }
    friend istream& operator >> (istream& is, ZborPasageri& zb);
    friend ostream& operator<<(ostream& os, const ZborPasageri& zb);
};
istream& operator>>(istream& is, ZborPasageri& zb)
{
    is >> (Zbor&)zb;
    cout << "Introduceti numarul pasagerilor: " << '\n';
    is >> zb.nr_pasageri;

    zb.pasageri = new Pasager[zb.nr_pasageri];
    for (int i = 0; i < zb.nr_pasageri; i++)
    {
        std::cout << "Introduceti datele pentru pasagerul " << i + 1 << ":" << std::endl;
        is >> zb.pasageri[i];
    }

    cout << "Introduceti numarul de locuri disponibile: " << '\n';
    is >> zb.locuri_disponibile;

    cout << "Introduceti numarul de bagaje: " << '\n';
    is >> zb.nr_bagaje;

    cout << "Introduceti greutatea totala a bagajelor: " << '\n';
    is >> zb.greutate_bagaje;

    return is;
}

ostream& operator<<(ostream& os, const ZborPasageri& zb)
{
    os << "-------------------------------------------------\n";
    os << (Zbor&)zb;
    os << "Numar pasageri: " << zb.nr_pasageri << '\n';
    for (int i = 0; i < zb.nr_pasageri; i++)
        os << "Pasager " << i + 1 << ": " << zb.pasageri[i] << '\n';
    os << "Locuri disponibile: " << zb.locuri_disponibile << '\n';
    os << "Numar bagaje: " << zb.nr_bagaje << '\n';
    os << "Greutate bagaje: " << zb.greutate_bagaje << '\n';
    os << "-------------------------------------------------";
    os << '\n';

    return os;
}

//A doua clasa derivata din clasa Zbor - ZborMarfa
class ZborMarfa : public Zbor
{
private:
    char* tip_marfa;
    int greutate_marfa;
    char* caracteristici_speciale;
public:
    //Constructor fara parametri
    ZborMarfa() : Zbor(), tip_marfa(nullptr), greutate_marfa(0), caracteristici_speciale(nullptr) {}
    //Constructor cu parametri
    ZborMarfa(Zbor zb, const char* tm, int gm, const char* cs)
        : Zbor(zb), tip_marfa(nullptr), greutate_marfa(gm), caracteristici_speciale(nullptr)
    {
        if (tm != nullptr)
        {
            tip_marfa = new char[strlen(tm) + 1];
            strcpy(tip_marfa, tm);
        }

        if (cs != nullptr)
        {
            caracteristici_speciale = new char[strlen(cs) + 1];
            strcpy(caracteristici_speciale, cs);
        }
    }
    //Constructor de copiere
    ZborMarfa(const ZborMarfa& zb)
        : Zbor(zb), tip_marfa(nullptr), greutate_marfa(zb.greutate_marfa), caracteristici_speciale(nullptr)
    {
        this->greutate_marfa = zb.greutate_marfa;

        if (zb.tip_marfa != nullptr) {
            this->tip_marfa = new char[strlen(zb.tip_marfa) + 1];
            strcpy(this->tip_marfa, zb.tip_marfa);
        }
        else
            this->tip_marfa = nullptr;

        if (zb.caracteristici_speciale != nullptr) {
            this->caracteristici_speciale = new char[strlen(zb.caracteristici_speciale) + 1];
            strcpy(this->caracteristici_speciale, zb.caracteristici_speciale);
        }
        else
            this->caracteristici_speciale = nullptr;
    }
    // Destructor
    ~ZborMarfa()
    {
        delete[] tip_marfa;
        delete[] caracteristici_speciale;
    }

    //Metode de access
    void SetGreutate_marfa(int g1)
    {
        this->greutate_marfa = g1;
    }
    int GetGreutate_marfa()
    {
        return this->greutate_marfa;
    }

    void SetTip_marfa(const char* tip)
    {
        if (this->tip_marfa != nullptr)
            delete[] this->tip_marfa;
        this->tip_marfa = new char[strlen(tip) + 1];
        strcpy(this->tip_marfa, tip);
    }
    char* GetTip_marfa()
    {
        return this->tip_marfa;
    }

    void SetCaracteristici(const char* car)
    {
        if (this->caracteristici_speciale != nullptr)
            delete[] this->caracteristici_speciale;
        this->caracteristici_speciale = new char[strlen(car) + 1];
        strcpy(this->caracteristici_speciale, car);
    }
    char* GetCaracteristici()
    {
        return this->caracteristici_speciale;
    }
    //Supraincarcare operator atribuire
    ZborMarfa& operator=(const ZborMarfa& zb)
    {
        if (this != &zb)
        {
            Zbor::operator=(zb);
            if (this->tip_marfa != nullptr)
                delete[] this->tip_marfa;
            this->tip_marfa = new char[strlen(zb.tip_marfa) + 1];
            strcpy(this->tip_marfa, zb.tip_marfa);

            this->greutate_marfa = zb.greutate_marfa;

            if (this->caracteristici_speciale != nullptr)
                delete[] this->caracteristici_speciale;
            this->caracteristici_speciale = new char[strlen(zb.caracteristici_speciale) + 1];
            strcpy(this->caracteristici_speciale, zb.caracteristici_speciale);
        }

        return *this;
    }
    friend istream& operator >> (istream& is, ZborMarfa& m);
    friend ostream& operator<<(ostream& os, const ZborMarfa& m);
};

istream& operator>>(istream& is, ZborMarfa& m)
{
    is >> (Zbor&)m;
    char buf[20];
    cout << "Introduceti tipul marfii" << '\n';
    is >> buf;
    delete[] m.tip_marfa;
    m.tip_marfa = new char[strlen(buf) + 1];
    strcpy(m.tip_marfa, buf);

    cout << "Introduceti greutate marfii: " << '\n';
    is >> m.greutate_marfa;

    cout << "Introduceti caracteristicile speciale: " << '\n';
    is >> buf;
    delete[] m.caracteristici_speciale;
    m.caracteristici_speciale = new char[strlen(buf) + 1];
    strcpy(m.caracteristici_speciale, buf);

    return is;
}
ostream& operator<<(ostream& os, const ZborMarfa& m)
{
    os << "-------------------------------------------------\n";
    os << (Zbor&)m;
    os << "Tip_marfa: " << m.tip_marfa << '\n';
    os << "Greutate: " << m.greutate_marfa << '\n';
    os << "Caracteristici speciale marfa" << m.caracteristici_speciale << '\n';
    os << "-------------------------------------------------";
    os << '\n';
    return os;
}

//Clasa va contine un vector de elemente de tipul clasei de baza - Zbor
class Zboruri
{
private:
    Zbor* v;
    int nr_zboruri;
public:
//Constructor fara parametri
    Zboruri() : v(nullptr), nr_zboruri(0) {}

 // Constructor cu parametri
    Zboruri(Zbor* zb, int nr) : nr_zboruri(nr)
    {
        this->v = new Zbor[nr_zboruri];
        for (int i = 0; i < nr_zboruri; i++)
        {
            v[i] = zb[i];
        }
    }
//Constructorul de copiere
    Zboruri(const Zboruri& zb) : nr_zboruri(zb.nr_zboruri) {
        v = new Zbor[nr_zboruri];
        if (zb.v != nullptr) {
            for (int i = 0; i < nr_zboruri; i++) {
                this->v[i] = zb.v[i];
            }
        }
        else {
            this->v = nullptr;
        }

    }
//Destructor
    ~Zboruri()
    {
        delete[] v;
    }
//Supraincarcare operatorului de atribuire
    Zboruri& operator=(const Zboruri& zb) {
        if (this != &zb) {
            delete[] v;

            nr_zboruri = zb.nr_zboruri;
            v = new Zbor[zb.nr_zboruri];
            for (int i = 0; i < zb.nr_zboruri; ++i) {
                v[i] = zb.v[i];
            }
        }
        return *this;
    }

    Zbor* getZbor(int index) const {
        if (index >= 0 && index < nr_zboruri) {
            return &v[index];
        }
        return nullptr;
    }

    int getNrZboruri() const {
        return nr_zboruri;
    }

    friend istream& operator>>(istream& is, Zboruri& zboruri);
    friend ostream& operator<<(ostream& os, const Zboruri& zboruri);

    Zboruri& operator+=(const Zbor& zb) {
        v[nr_zboruri] = zb;
        nr_zboruri++;
        return *this;
    }

    Zboruri& operator-=(const Zbor& zb) {
        for (int i = 0; i < nr_zboruri; i++) {
            if (v[i].GetId_zbor() == zb.GetId_zbor()) {
                for (int j = i; j < nr_zboruri - 1; j++) {
                    v[j] = v[j + 1];
                }
            }
        }
        nr_zboruri--;
        return *this;
    }
};

istream& operator>>(istream& is, Zboruri& zboruri) {
    std::cout << "Introduceti numarul de zboruri: ";
    is >> zboruri.nr_zboruri;

    delete[] zboruri.v;
    zboruri.v = new Zbor[zboruri.nr_zboruri];

    for (int i = 0; i < zboruri.nr_zboruri; ++i) {
        Zbor zbor;
        is >> zbor;
        zboruri.v[i] = zbor;
    }
    return is;
}

ostream& operator<<(ostream& os, const Zboruri& zboruri) {
    os << "-------------------------------------------------\n";
    for (int i = 0; i < zboruri.nr_zboruri; ++i) {
        os << "Zborul " << i + 1 << ":\n";
        os << zboruri.v[i] << "\n";
    }
    os << "-------------------------------------------------\n";
    return os;
}

int main()
{
    Zbor Rom_Angl(1, "Pasager", "Anglia", 3, "12/03/2024", "13:15", "boeing767");
    Zbor China_USA(2, "Marfa", "USA", 12, "15/05/2024", "20:35", "boeing231");
    Pasager p[5];
    Pasager p1("Alex", 19, 832821, "romana", 724723778, "14A");
    Pasager p2("Ioana", 20, 3742323, "romana", 72474328, "19F");
    Pasager p3("Cristi", 17, 7456332, "romana", 783273455, "29B");
    p[0] = p1;
    p[1] = p2;
    p[2] = p3;
    ZborPasageri A(Rom_Angl, 3, p, 40, 4, 200);
    cout << A;
    ZborMarfa B(China_USA, "Cipuri", 2000, "Fragil");
    cout << B;


    Zbor z1(3, "Marfa", "Anglia", 4, "25/07/2024", "12:10", "boeing99");
    Zbor z2(4, "Pasager", "Germania", 4, "30/03/2024", "09:55", "boeing012");
    Zbor z3(5, "Pasager", "Portugalia", 7, "21/01/2024", "19:35", "boeing84");

    Zbor zv[4];
    zv[0] = z1;
    zv[1] = z2;
    zv[2] = z3;

    Zboruri Zb(zv, 3);

    cout << Zb;

    Zb -= z1;

    cout << Zb;

    Zbor znew(6, "Marfa", "Japonia", 10, "09/11/2024", "03:15", "boeing777");

    Zb += znew;
    cout << Zb;
}