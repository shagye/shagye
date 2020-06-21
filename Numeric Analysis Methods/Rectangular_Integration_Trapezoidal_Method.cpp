#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define f(x) katsayi*exp(-x*x)/3
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
  cout<<"\t####################### SORU 12 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"12.Soru :\ne^(-x^2)/3 ifadesinin a,b sinirlarinda integralini N=herhangi bir sayi icin \nDikdortgen ve Yamuk Metodu ile yaklasik olarak hesaplayiniz.Newton ileri fark tablosunu olusturunuz.\n\n";
  
}


main(){
	int N;
	float h,a,katsayi,x[50];
	string secenek;
	bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"(a)[e^(-x^2)/3]fonksiyonunda a katsayisini giriniz:";
		cin>>katsayi;
		cout<<endl;
	
	
		cout<<"integral alt sinir degeri nedir? ";
		cin>>x[0];
		cout<<"integral ust sinir degeri nedir? ";
		cin>>a;
		cout<<"N degerini girin:";
		cin>>N;	
	}
	else if(secenek=="0")
	{
		//soruda verilen katsayilarin tanimlanmasi
		katsayi=1;
		x[0]=1;   
		a=2;
		N=5;		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
	h = (a-x[0])/N;
	
	for(int i =0;i<=N;i++){
		x[i]=x[0]+i*h;
	}
	float fx[N+1];
	for(int i=0;i<=N;i++){
		fx[i]=f(x[i]);
	}
	
	cout<<"\nh(aralik uzunlugu) ="<<h<<endl;
    cout<<"\nFonksiyonun x degerlerine gore sonuclari ;\n\n";
	for(int deger =0;deger<=N;deger++){
		cout<<"f("<<x[deger]<<")= "<<fx[deger]<<endl;
	}
	float dikdortgen;
	for(int deger=0;deger<N;deger++){
		dikdortgen =dikdortgen+ fx[deger];		
	}
	cout<<setprecision(8)<<"\nDikdorgen Metodu kullanilarak yaklasik integral sonucu I= "<<h*dikdortgen<<endl;
	float yamuk=0;
	for(int deger =0;deger<=N;deger++){
		if(deger==0 || deger==N){
			yamuk+=fx[deger]/2;
		}
		else{
			yamuk+=fx[deger];	
		}	
	}
	cout<<"***************************"<<endl;
	cout<<setprecision(8)<<"Yamuk Metodu kullanilarak yaklasik integral sonucu I= "<<yamuk*h<<endl;
	cout<<"***************************"<<endl;
	system("pause");
	
	
	
}
