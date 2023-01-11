#include <iostream>
//#include "tableau_tri.h" c'est pas l'appele de redifiner la classe tableautri att!!
#include "tableau_tri.cpp"
using namespace std;
//Quesion 10
int main() {
	  tableau_tri T(100); //test du constructeur useul
	   cin>>T;
	   cout<<T;
	   T.supprimer(4); 
	   cout<<"T d'apres la suppresion du 4"<<endl;
	   cout<<T;
	    cout<<"T d'apres l ajout du 3"<<endl;
	    T+3;
		cout<<T;
		tableau_tri T1(T); //test du constructeur du copie
		cout<<"la copie est : "<<T1;
		tableau_tri T2(100);
		cin>>T2;
		tableau_tri T3=T1+T2;
		cout<<"la fusion est : "<<T3; 
		T3*3;
		cout <<"apres multiplication par 3"<<T3;
        T3=3*T3;
	   cout <<"apres multiplication par 3"<<T3;
		//kmlo  verification tlkher ...
	return 0;
}
