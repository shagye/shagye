#include<iostream>
#include<cmath>
#include <bits/stdc++.h> 

using namespace std;

#define fxy(x,y) (a1)*x+(b1)*exp(y)-c1
#define gxy(x,y) (a2)*(x*x)+(b2)*(y*y)-c2
#define fx(x,y) 1
#define gy(x,y) 2*y

void bilgilerim()
{

  cout<<"\n\n\t##########################################################\n";
  cout<<"\t>>>>>>                                              <<<<<<\n";
  cout<<"\t>>>>>>        Sayisal Analiz Final Projesi          <<<<<<\n";
  cout<<"\t>>>>>>                                              <<<<<<\n";
  cout<<"\t>>>>>>        : Onur Akbal                          <<<<<<\n";
  cout<<"\t>>>>>>        : 171802074                           <<<<<<\n";
  cout<<"\t>>>>>>        : Doc.Dr Hasan Huseyin Sayan          <<<<<<\n";
  cout<<"\t>>>>>>        : Gazi Universitesi                   <<<<<<\n";
  cout<<"\t>>>>>>                                              <<<<<<\n";
  cout<<"\t##########################################################\n";
  cout<<"\t####################### SORU 8 ###########################\n";
  cout<<"\t##########################################################\n\n";
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
}

main(){
	
	float x[55],y[55],epsilon,a1,b1,c1,a2,b2,c2;
	string secenek;
	bilgilerim();
	cout<<"8.Soru :\n(a1)x+(b1)e^y   =(c1)\n(a2)x^2+(b2)y^2 =(c2) sistemini (Xo,Yo) degerlerini alarak Epsilon icin-\nHizlandirilmis Newton Metodu ile yaklasik olarak cozunuz.\n\n";
	
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;

    if(secenek=="1")
    {
    	cout<<"f(x,y)=(a1)x+(b1)e^y=(c1) fonksiyonunda katsayilari sirasiyla giriniz (a1,b1,c1) degerlerini giriniz:"<<endl;
		cout<<"a1:";
		cin>>a1;
		cout<<"b1:";
		cin>>b1;
		cout<<"c1:";
		cin>>c1;
		cout<<"\n";
		cout<<"g(x,y)=(a2)x^2+(b2)y^2=(c2) fonksiyonunda katsayilari sirasiyla giriniz (a2,b2,c2) degerlerini giriniz:"<<endl;
		cout<<"a2:";
		cin>>a2;
		cout<<"b2:";
		cin>>b2;
		cout<<"c2:";
		cin>>c2;
		cout<<"\n";
		
		cout<<"(Xo,Yo) baslangic degerleri giriniz;\n\n";
	
		cout<<"x0 degerini  giriniz :";
		cin>>x[0];
		cout<<"y0 degerini  giriniz: ";
		cin>>y[0];
		cout<<"\nEpsilon degerini  giriniz: ";
		cin>>epsilon;
	}
	else if(secenek=="0")
	{
		//soruda verilen katsayilarin tanimlanmasi
		a1=1; b1=1; c1=1;
		a2=1; b2=1; c2=4;
		epsilon=0.01;
		x[0]=0.9;
		y[0]=-1.6;	
	}
	cout<<"SONUC ;"<<endl;
	for(int deger =0;;deger++){
		
		x[deger+1] = x[deger]-(fxy(x[deger],y[deger]))/(fx(x[deger],y[deger]));
		y[deger+1] = y[deger]-(gxy(x[deger+1],y[deger]))/(gy(x[deger+1],y[deger]));
		cout<<"\n";
		cout<<"(x"<<deger<<",y"<<deger<<") = ("<<x[deger+1]<<","<<y[deger+1]<<")\n";
	
		if(fabs(x[deger+1]-x[deger]) > fabs(y[deger+1]-y[deger])){
			
			if(fabs(x[deger+1]-x[deger])<epsilon){
				cout<<"\nYaklasim sonucunda elde edilen kok ;\n"<<endl;
				cout<<"(c,d) = (x"<<deger<<",y"<<deger<<") = ("<<setprecision(9)<<x[deger+1]<<","<<setprecision(9)<<y[deger+1]<<")";
				break;
			}
		}
		if(fabs(y[deger+1]-y[deger])>fabs(x[deger+1]-x[deger])){
			
			if(fabs(y[deger+1]-y[deger])<epsilon){
				
				cout<<"(c,d) = (x"<<deger<<",y"<<deger<<") = ("<<setprecision(9)<<x[deger]<<","<<setprecision(9)<<y[deger]<<")";
			break;	
		}	
		}	
	}
	cout<<"\n\n";
	system("pause");	
}
