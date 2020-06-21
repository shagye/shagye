#include <iostream>
# include <stdio.h>
# include <math.h>
#include <bits/stdc++.h> 
using namespace std; 


//sinif yapisi ile yapma
class SoruBir
{

public:
	//Fonksiyon ve Degiskenleri tanimlama
	void  bilgilerim();
	void  baslat();
	float ust_hesapla(float s,int n);
	float faktoriyel(int n) ;
	float hesap(float a,float n,float x);
	float n,a,x,sonuc,gercek;
};

void SoruBir::bilgilerim()
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
  cout<<"\t####################### SORU 1 ###########################\n";
  cout<<"\t##########################################################\n\n";
}
void SoruBir::baslat()
{
	//Program Acildiginda Gerekli Bilgilerin Yazilmasi ve Alinmasi
	bilgilerim();
	cout<<"1.Soru :\n(1+x)^a acilimini hesaplarken yapilan Mutlak Hata ve Bagil Hatanin Bulunmasi\n\n";
	cout<<"(1+x)^a acilim serisinin ilk kac terimininden faydalanmak istiyorsunuz ? =";
	cin>>n;
	cout<<"\n(1+x)^a ifadesinde kok derecesi nedir? =";
	cin>>a;
	cout<<"\n(1+x)^"<<"(1/"<<a<<")"<<" ifadesinde x degeri nedir? =";
	cin>>x;
	sonuc = hesap(a,n,x);
	gercek=pow((1+x),(1.0/a));
	cout<<"\n("<<1+x<<")^"<<"(1/"<<a<<") hesaplanirken yapilan ;\n\n";
} 
float SoruBir::ust_hesapla(float s, int n) 
{ 
    //kombinasyonun ust satirinin hesaplananmasi
	float onceki = s; 
	for (int i = 1; i < n; i++) 
		onceki = onceki * (s - i); 
	return onceki; 
} 

float SoruBir::faktoriyel(int n) 
{ 
    //faktoriyel hesaplama
	int f = 1; 
	for (int i = 2; i <= n; i++) 
		f *= i; 
	return f; 
}

float SoruBir::hesap(float a,float n,float x)
{
	//formulu uygulama
	float toplam = 1; 
	for (int i = 1; i < n; i++) { 
		toplam = toplam + (ust_hesapla(1.0/a, i) * pow(x,i)/ faktoriyel(i)); 
	} 
	return toplam;
}



main() {
	
	
	SoruBir n; //sinifa ulasma
	n.baslat();//baslat fonksiyonunu calistirma
	
	float mutlakHata=fabs(n.gercek-n.sonuc); //mutlak hata hesaplama
	cout<<"Mutlak Hata = "<<setprecision(9)<<mutlakHata<<endl;
	
	float bagilHata=fabs(mutlakHata/n.gercek);
	cout<<"Bagil Hata = "<<setprecision(9)<<bagilHata<<endl<<endl;//bagil hata hesaplama
	
	system("pause");//fonksiyonun kapanmasini engelleme
	
	
	

}
