#include<iostream>
using namespace std;
//interface qst1
class tableau_tri{
	float *tab;
	int taille;
	int nbelts;
public:
	tableau_tri();
	tableau_tri(int );
	tableau_tri(const tableau_tri &);
	~tableau_tri();
	tableau_tri& operator = (const tableau_tri &);
	friend istream& operator >> (istream&,tableau_tri &);
	friend ostream& operator << (ostream&,const tableau_tri &);
    bool operator > (float );
    int frequence (float);
    void supprimer(float);
    tableau_tri operator + (int);
    tableau_tri operator + (const tableau_tri &);
    tableau_tri operator *(float);
    friend tableau_tri operator * (float ,const tableau_tri&);
};
