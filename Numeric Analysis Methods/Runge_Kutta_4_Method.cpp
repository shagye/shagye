#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
// fonksiyon tanimlanmasi
#define f(x,y) katsayi*x*exp(y)
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
  cout<<"\t####################### SORU 16 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"16.Soru :\ndf(x)-x*e^y = 0  yo baslangic deger problemi verilsin\nh degeri icin y(x) degerine 4.basamaktan Runge-Kutta Metodu ile yaklasiniz.\n\n";
}

main()
{
	
    float x[25],y[25],x_bul,h_uzunlugu,N,katsayi;
    string secenek;
    
    bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"df(x)=(a)[x*e^y] fonksiyonunda a katsayisi nedir? :";
		cin>>katsayi;
		cout<<"-------------------------------\n";
    
   		cout<<"y0 baslangic degeri nedir? : ";
   		cin>>y[0];  
    
  	    cout<<"x0 baslangic degeri nedir? : ";
   		cin>>x[0];
    
   		cout<<"h(aralik uzunlugu) degeri nedir? : ";
   		cin>>h_uzunlugu;
    
   		cout<<"y(x) fonksiyonunun hangi x degerine yaklasmak istiyorsunuz ";
   		cin>>x_bul;	
	}
	else if(secenek=="0")
	{
		//Ozel Cozum icin soruda verilen katsayilarin tanimlanmasi
		katsayi=1;
		y[0]=1;
		x[0]=0;
		h_uzunlugu=0.2;
		x_bul=0.6;		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
    N=(x_bul-x[0])/(h_uzunlugu);
	for(int i=1;i<N+1;i++) {
		
		x[i]=x[0]+(i*h_uzunlugu);
	}
	
	float k1,k2,k3,k4;
	
	cout<<"\nHESAPLAMALAR\n";
	for(int i=0;i<N;i++) {
			
			k1=h_uzunlugu*f(x[i],y[i]);
			k2=h_uzunlugu*f((x[i]+h_uzunlugu/2),(y[i]+k1/2));
			k3=h_uzunlugu*f((x[i]+h_uzunlugu/2),(y[i]+k2/2));
			k4=h_uzunlugu*f((x[i]+h_uzunlugu),(y[i]+k3));		
			cout<<setprecision(9)<<endl<<"k1 = "<<k1<<endl<<"k2 = "<<k2<<endl<<"k3 = "<<k3<<endl<<"k4 = "<<k4<<endl;
			
			y[i+1]=y[i]+(k1+2*k2+2*k3+k4)/6;
	
			cout<<setprecision(9)<<endl<<"y"<<i+1<<" = "<<y[i+1]<<endl;
			cout<<"*********************\n";
			
			if(i==N-1)
			{
				//cout<<"\n**************************************************\n";
			    cout<<"Dorduncu Basamaktan Runge-Kutta Metodu ile yaklasim sonucu elde edilen deger ;\n";
			    cout<<"\ny("<<setprecision(4)<<x_bul<<") =";
			    	cout<<setprecision(9)<<" y"<<i+1<<" = "<<y[i+1]<<endl<<endl;
				cout<<"ssds";
			}
		}
	system("pause");
}
	

		
	
	
	
	
	



