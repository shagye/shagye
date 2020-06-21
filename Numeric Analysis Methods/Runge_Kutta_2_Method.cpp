#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define f(x) a*x*exp(x)

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
  cout<<"\t####################### SORU 15 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"15.Soru :\ndf(x)-x*e^x = 0  yo baslangic deger problemi verilsin\nh degeri icin f(x) degerine Ikinci basamaktan Runge-Kutta Metodu ile yaklasiniz.\n\n";
}

main()
{
    float x[25],y[25],x_bul,h_uzunlugu,N,k1,k2,a;
    string secenek;
    bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"(a)*x*exp(x) fonksiyonunda a katsayisini giriniz:";
		cin>>a;
    
   		cout<<"y0 degeri nedir? : ";
  		cin>>y[0];  
    
  	    cout<<"x0 degeri nedir? : ";
   		cin>>x[0];
    
  	    cout<<"h(aralik uzunlugu) degeri nedir? : ";
  		cin>>h_uzunlugu;
    
   		cout<<"f(x) fonksiyonunun hangi x degerine yaklasmak istiyorsunuz : ";
   		cin>>x_bul;
	}
	else if(secenek=="0")
	{
		//Ozel Cozum icin soruda verilen katsayilarin tanimlanmasi
		
		y[0]=0;
		x[0]=1;
		h_uzunlugu=0.2;
		x_bul=1.4;		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}	

    N=(x_bul-x[0])/(h_uzunlugu);
	for(int i=1;i<N+1;i++) {
		
		x[i]=x[0]+(i*h_uzunlugu);
	}
	for(int i=0;i<N;i++) {
			
			k1=h_uzunlugu*x[i]*exp(x[i]);
			k2=h_uzunlugu*x[i+1]*exp(x[i+1]);
			cout<<"\nn="<<i<<" icin ;\n";
			cout<<setprecision(9)<<endl<<"k1 = "<<k1<<endl<<"k2 = "<<k2<<endl;
			
			y[i+1]=y[i]+(k1+k2)/2;
			
			cout<<setprecision(9)<<"y"<<i+1<<" = "<<y[i+1]<<endl;		
			if(i>N-1){
				cout<<"\n**************************************************\n";
				cout<<"Ikinci basamaktan Runge-Kutta Metodu ile yaklasim sonucu elde edilen deger ;\n";
				cout<<"\ny("<<setprecision(4)<<x_bul<<") = ";
				cout<<setprecision(10)<<"y"<<i+1<<" = "<<y[i+1]<<endl<<endl;	
			}			
	}		
	system("pause");
}
	

		
	
	
	
	
	


