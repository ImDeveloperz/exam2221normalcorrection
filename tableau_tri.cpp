#include<iostream>
#include "tableau_tri.h"
using namespace std;
//question 2
tableau_tri::tableau_tri(){
	taille=0;
	nbelts=0;
	tab=NULL;
}
tableau_tri::tableau_tri(int T){
	taille=T;
	nbelts=0;
	tab=new float(taille);
}
tableau_tri::tableau_tri(const tableau_tri & T){
	taille=T.taille;
	nbelts=T.nbelts;
	tab=new float(taille);
	for(int i=0;i<nbelts;i++)
	      tab[i]=T.tab[i];
}
tableau_tri::~tableau_tri(){
	delete [] tab;
}
//question 3
tableau_tri & tableau_tri::operator = (const tableau_tri & T){
	if(this!=&T){
		delete [] tab;
		taille=T.taille;
		nbelts=T.nbelts;
		tab=new float(taille);
		for(int i=0;i<nbelts;i++)
		    tab[i]=T.tab[i];
	}
	return *this;
}
//question 4
istream& operator >>(istream & in, tableau_tri & T){
	cin>>T.taille;
	cin>>T.nbelts;
	T.tab=new float(T.taille);
	for(int i=0 ; i<T.nbelts ;i++)
	cin>>T.tab[i];
	return in;
}
ostream& operator <<(ostream & os, const tableau_tri & T){
	cout<<"la taille est : "<<T.taille<<endl;
    cout<<"la nombre d'elements est : "<<T.nbelts<<endl;
	for(int i=0 ; i<T.nbelts;i++)
        cout<<"la case num "<<i<<" est : "<<T.tab[i];
     cout<<endl;
	return os; 
}
//question 5
bool tableau_tri::operator >(float T) {
        for(int i=0;i<nbelts && T<=tab[i];i++){
        	if(tab[i]==T) return true;
		}
		return false;
}\
//nb 5 : you can solve this question with my  methode or with using dichotomie algorithm for operator >
//question 6
int tableau_tri::frequence(float T) {
	if(!(*this>T)) return 0;
	int n=0;
	for(int i=0;i<nbelts && tab[i]>=n;i++){
		  if(tab[i]==T) n++;
	}
	return n;
}
//question 7
void tableau_tri::supprimer(float T){
	int n=0;
	for(int i=0;i<nbelts;i++){
		if(tab[i]!=T){
			tab[n]=tab[i];
			n++;
		}
	}
	nbelts-=n;
}
//question 8
tableau_tri tableau_tri::operator +(int T){
	if(nbelts==taille){ // pour ajouter une autre case memoire de type float pour le nouveau element 
		taille++;
		 float tabCopie[taille];
		 for(int i=0; i<nbelts ;i++){
		 	tabCopie[i]=tab[i];
		 }\
		 delete [] tab;
		 tab=new float(taille);
		 tab=tabCopie; //tab va pointer sur tabcopie		 
	}
	//l'ajout du l'element
     nbelts++;
	 int n=taille;
	 for(int i=0; i<nbelts-1 && n==nbelts;i++){
	 	  if(T<=tab[i] && T>=tab[i+1]){
	 	  	     n=i+1;	  	
		   }
		   if(n==i+1){
		   	      for(int j=nbelts;j>n;j++){
		   	      	       tab[j-1]=tab[j-2]; 
					 }
			  tab[n]=T;
		   }
	 }
	 return *this;
}
//2eme +
tableau_tri tableau_tri::operator +(const tableau_tri & T){
	  tableau_tri T1(taille+T.taille);
	  T1.nbelts=nbelts;
	  for(int i=0;i<nbelts;i++){
	  	      T1.tab[i]=tab[i];
	  }
	  for(int i=nbelts;i<T.nbelts;i++){
	  	      T1.tab[i]>T.tab[i-nbelts];
	  }
	return T1;  
}
//question 9
tableau_tri tableau_tri::operator *(float x){
	for(int i=0 ; i<nbelts ;i++){
		tab[i]*=x;
	}
	return *this;
}
tableau_tri operator *(float x,const tableau_tri& T){
	return x*T;
}
