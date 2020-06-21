#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
#define f(x,y) katsayi*y*exp(x)
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
  cout<<"\t####################### SORU 14 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"14.Soru :\ndf(x)-f(x)*e^x = 0  yo baslangic deger problemi verilsin\nh degeri icin f(x) degerine Euler Metodu ile yaklasiniz.\n\n";
}

main()
{
	int N;
    float x[25],y[25],x_bul,h;
    string secenek;
    float katsayi;
	bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"(a)[y*e^x] fonksiyonunda a katsayisi nedir? :";
		cin>>katsayi;
	
	    cout<<"y0 baslangic degeri nedir? : ";
     	cin>>y[0];  
    
   	    cout<<"x0 baslangic degeri nedir? : ";
        cin>>x[0];
    
        cout<<"h(aralik uzunlugu) degeri nedir? : ";
        cin>>h;
    
        cout<<"f(x) fonksiyonunun hangi x degerine yaklasmak istiyorsunuz ";
        cin>>x_bul;	
	}
	else if(secenek=="0")
	{
		//Ozel Cozum icin soruda verilen katsayilarin tanimlanmasi
		katsayi=1;
		y[0]=1;
		x[0]=0;
		h=0.2;
		x_bul=0.6;		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}

    N=(x_bul-x[0])/(h);
	
	for(int i=0;i<N;i++) {
		
		x[i+1]=x[0]+((i+1)*h);	
	}
		
	for(int i=0;i<N;i++) {	
		y[i+1]=y[i]+h*f(x[i],y[i]);
		if(i<N-1)
		{
			cout<<"\ny("<<setprecision(4)<<x[i+1]<<") =";
			cout<<setprecision(9)<<" y"<<i+1<<" = "<<y[i+1]<<endl;
		}
		else if(i=N-1){
			cout<<"\n**************************************************\n";
			cout<<"Euler Metodu ile yaklasim sonucu elde edilen deger ;\n";
			cout<<"\ny("<<setprecision(4)<<x_bul<<") =";
			cout<<setprecision(9)<<" y"<<i+1<<" = "<<y[i+1]<<endl<<endl;
		}			
	}
	system("pause");
}
	

		

