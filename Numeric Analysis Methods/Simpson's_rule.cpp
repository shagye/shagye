#include<iostream>
#include<cmath>
#include <bits/stdc++.h>
// fonksiyonun tanimlanmasi
#define f(x) katsayi*(sin(x)/x)
using namespace std;
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
  cout<<"\t####################### SORU 13 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"13.Soru :\nsin(x)/x ifadesinin a,b sinirlarinda integralini N=herhangi bir sayi icin \nSimpson Metodu ile yaklasik olarak hesaplayiniz.\n\n";
  
}

main(){
	float alt_sinir,ust_sinir,h,toplam;
	int N;
	string secenek;
	float katsayi;
	
	bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"(a)[sin(x)/x]fonksiyonunda a katsayisi nedir ? a=";
		cin>>katsayi;
		cout<<"\n";
		cout<<"integral alt sinir degeri nedir?:";cin>>alt_sinir;
		cout<<"integral ust sinir degeri nedir?:";cin>>ust_sinir;
		cout<<"N degerini giriniz:";
		cin>>N;	
	}
	else if(secenek=="0")
	{
		//Ozel Cozum icin soruda verilen katsayilarin tanimlanmasi
		katsayi=1;
		alt_sinir=1.0;   
		ust_sinir=2.0; 
		N=4;		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
	float x[2*N+1];
	x[0]=alt_sinir;
	h= (ust_sinir-alt_sinir)/(2*N);

	for(int deger=1;deger<=2*N+1;deger++){
		x[deger]=x[0]+deger*h;	
	}
	cout<<"\nh(aralik uzunlugu) ="<<h<<endl;
	cout<<"\nFonksiyonun x degerlerine gore sonuclari ;\n\n";
	for(int deger =0;deger<=2*N;deger++){
		printf("f(%.4f) = %.9f\n",x[deger],f(x[deger]));
	}
	cout<<endl;
	for(int deger =0;deger<2*N+1;deger++){
		if(deger == 0 || deger== 2*N){
			toplam += f(x[deger]);
		}
		else if(deger%2 == 0){
			toplam += 2*f(x[deger]);
		}
		else{
			toplam += 4*f(x[deger]);
		}
	}
	cout<<"***************************"<<endl;
	cout<<setprecision(9)<<"Simpson Metodu ile hesaplanan integralin yaklasik degeri ;\nI= "<<setprecision(9)<<(h/3)*toplam;
	cout<<"\n***************************"<<endl;
	system("pause");
}

