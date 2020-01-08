#include <iostream>
#include <bits/stdc++.h>
using namespace std;
ifstream fin("fisier.txt");

class farmacie_abst{
protected:
string nume;
static string proprietar;
public:
static void proprietarnume(){cout<<proprietar;}
farmacie_abst(){nume="";}
farmacie_abst(string denumire){nume=denumire;}
farmacie_abst(const farmacie_abst &ob){nume=ob.nume;}
farmacie_abst& operator =(const farmacie_abst& ob)
{if(this==&ob)
    return *this;
 else
{nume=ob.nume;}
return *this;}

virtual void afisare()=0;
virtual void citire()=0;
virtual ~farmacie_abst(){nume="";}
friend istream& operator>>(istream& ,farmacie_abst&);
};
string farmacie_abst::proprietar="PropX";
istream& operator>>(istream& in,farmacie_abst& ob)
{if (typeid(in)!= typeid(fin)){
cout<<"Numele farmaciei este:"<<endl;
in>>ob.nume;}
else {in>>ob.nume;}
return in;
}



void try_local(int a)
{

try
 {
 if (typeid(a)==typeid(int)) throw a;
 }
 catch(int x)
 {
 cout<<"Exceptie gasita, alocare numar ca nume de farmacie!"<<"\n";
 }

}


class farmacie_online: public farmacie_abst{
protected:
string link;
int nrviz;
float discount;
public:
farmacie_online():farmacie_abst(){nrviz=0;discount=20;}
farmacie_online(string nume):farmacie_abst(nume){nrviz=0;discount=20;}
farmacie_online(const farmacie_online& ob):farmacie_abst(ob){link=ob.link; nrviz=ob.nrviz; discount=ob.discount;}
farmacie_online& operator=(const farmacie_online& ob){ if(this==&ob)return *this;
                                                        else {this->farmacie_abst::operator=(ob);
                                                              link=ob.link;
                                                              nrviz=ob.nrviz;
                                                              discount=ob.discount;
                                                              return *this;}}
farmacie_online(int x){try_local(x);}
void afisare(){cout<<"Numele farmaciei: "<<nume<<endl<<"Link: "<<link<<endl<<"Nr vizitatori: "<<nrviz<<endl<<"Discount: "<<discount<<" %"<<endl;}
void citire(){cout<<"Numele farmaciei: "<<endl;
 cin>>nume;
 cout<<"Link:"<<endl;
 cin>>link;
 cout<<"nrviz:"<<endl;
 cin>>nrviz;
 cout<<"discount:"<<endl;
 cin>>discount;}
friend istream& operator>>(istream& ,farmacie_online&);
friend ostream& operator<<(ostream& ,const farmacie_online&);
int nr_viz(){return nrviz;}
~farmacie_online(){link="";nrviz=0;discount=0;}

};

istream& operator>>(istream& in,farmacie_online& ob)
{if (typeid(in)!= typeid(fin))
 {in>>(farmacie_abst&)ob;
 cout<<"Link:"<<endl;
 in>>ob.link;
 cout<<"nrviz:"<<endl;
 in>>ob.nrviz;
 cout<<"discount:"<<endl;
 in>>ob.discount;
 }
 else {
    in>>(farmacie_abst&)ob;
 in>>ob.link;
 in>>ob.nrviz;
 in>>ob.discount;
 }
return in;
}
ostream& operator<<(ostream& out,const farmacie_online& ob)
{out<<"Datele farmaciei sunt:"<<endl;
 out<<"Numele farmaciei: "<<ob.nume<<endl;
 out<<"Link: ";
 out<<ob.link<<endl;
 out<<"nrviz: ";
 out<<ob.nrviz<<endl;
 out<<"discount: ";
 out<<ob.discount<<" %";
return out;
}


class farmacie_offline:public farmacie_abst{
protected:
int nrang;
float profit;
public:
farmacie_offline():farmacie_abst(){nrang=0;profit=0;}
farmacie_offline(string nume):farmacie_abst(nume){nrang=0;profit=0;}
farmacie_offline(const farmacie_offline& ob):farmacie_abst(ob){nrang=ob.nrang; profit=ob.profit;}
farmacie_offline& operator=(const farmacie_offline& ob){ if(this==&ob)return *this;
                                                        else {this->farmacie_abst::operator=(ob);
                                                              nrang=ob.nrang;
                                                             profit=ob.profit;
                                                              return *this;}}




friend istream& operator>>(istream& ,farmacie_offline&);
friend ostream& operator<<(ostream& ,const farmacie_offline&);
void afisare(){cout<<"Numele farmaciei: "<<nume<<endl<<"Nr ang: "<<nrang<<endl<<"Profit: "<<profit<<endl;}
void citire(){
 cout<<"Numele farmaciei: "<<endl;
 cin>>nume;
 cout<<"Nrang:"<<endl;
 cin>>nrang;
 cout<<"profit:"<<endl;
 cin>>profit;}
~farmacie_offline(){nrang=0;profit=0;}

};

istream& operator>>(istream& in,farmacie_offline& ob)
{if (typeid(in)!= typeid(fin)){
in>>(farmacie_abst&)ob;
 cout<<"Nrang:"<<endl;
 in>>ob.nrang;
 cout<<"profit:"<<endl;
 in>>ob.profit;}
 else {
    in>>(farmacie_abst&)ob;
 in>>ob.nrang;
 in>>ob.profit;
 }
return in;
}
ostream& operator<<(ostream& out,const farmacie_offline& ob)
{out<<"Numele farmaciei este: "<<ob.nume<<endl;
 out<<"Nrang: ";
 out<<ob.nrang<<endl;
 out<<"Profit: ";
 out<<ob.profit;
return out;
}



template <class T>
class gestionareX
{
    vector <T> a;
    int index;
    const int id_lant=120;
public:
    gestionareX(){index=0;}
    void nrtotal_farm(){cout<<index;}
    const void show_id(){cout<<"Id-ul lantului clientului X este:"<<id_lant<<endl;}
    //void adaugarefarm(T);
    void afisare();
gestionareX<T>& operator+=(const farmacie_online);
gestionareX<T>& operator+=(const farmacie_offline);
~gestionareX(){a.clear();}
};


template<class T>
void gestionareX<T>::afisare()
{int aux=index;

   for (auto i = a.begin(); i != a.end(); ++i)
        {cout<<"Indexul farmaciei este: "<<(index-aux+1)<<endl;
        if(typeid(**i)==typeid(farmacie_online))cout<<"Aceasta este farmacie online si are datele:"<<endl;
        else if(typeid(**i)==typeid(farmacie_offline))cout<<"Aceasta este farmacie offline si are datele:"<<endl;
        (*i)->afisare();
        cout<<endl;
        aux--;}



}

template <class T>
gestionareX<T>& gestionareX<T>::operator+=(const farmacie_online ob) {

 a.push_back(new farmacie_online(ob));

 index++;
  return *this;
}
template <class T>
gestionareX<T>& gestionareX<T>::operator+=(const farmacie_offline ob) {

 a.push_back(new farmacie_offline(ob));

 index++;
  return *this;
}


template <>
class gestionareX <farmacie_online> {
vector <farmacie_online> a;
int nrtotalviz;
public:
gestionareX () {nrtotalviz=0;}
void afisarenr(){for(auto i=a.begin();i!=a.end();++i)
                          nrtotalviz=nrtotalviz+i->nr_viz();
                cout<<"Numarul total de vizitatori este: "<<nrtotalviz<<endl;
                          }
void adaugarefarm(farmacie_online ob)
{
a.push_back(ob);
}
gestionareX<farmacie_online>& operator+=(const farmacie_online ob)
{this->adaugarefarm(ob);
  return *this;

}

~gestionareX(){a.clear();}
};



int main()
{//exceptie
    farmacie_online x(1);


//codul este comentat pentru a putea fi luat pe bucati si a fi mai clar

//gestionare farmacii
gestionareX<farmacie_abst*> y;
cout<<"citire fisier";
//cout<<"Cate farmacii offline are clientul?"<<endl;
int nrfof;
fin>>nrfof;
vector <farmacie_offline> fof(nrfof);
for(int i=0;i<nrfof;++i)
{fin>>fof[i];
y+=fof[i];
}


//cout<<"Cate farmacii online are clientul?"<<endl;
int nrfon;
fin>>nrfon;
vector <farmacie_online> fon(nrfon);
for(int i=0;i<nrfon;++i)
{fin>>fon[i];
y+=fon[i];
}
y.afisare();



/*
//Citire,afisare,memorare n obiecte
vector <farmacie_abst*> farm;
cout<<"Cate farmacii are clientul in total:"<<endl;
int nrfarmt;
cin>>nrfarmt;
for(int i=0;i<nrfarmt;++i)
{cout<<"1=farm online"<<endl<<"2=farm offline"<<endl;
int sw;
cin>>sw;
if(sw==1)
{farm.push_back(new farmacie_online());
farm[i]->citire();
}
else if(sw==2)
{farm.push_back(new farmacie_offline());
farm[i]->citire();
}
}
for(int i=0;i<nrfarmt;++i)
    farm[i]->afisare();



//numarul total de vizitatori ai farmaciilor online
gestionareX<farmacie_online> x;

vector <farmacie_online> v;
cout<<"Cate farmacii online sunt ?"<<endl;
int nr;
cin>>nr;

for(int i=0;i<nr;i++)
{farmacie_online aux;
cin>>aux;
v.push_back(aux);
}

for (auto i = v.begin(); i != v.end(); ++i)
x+=(*i);

x.afisarenr();

*/

    return 0;
}
