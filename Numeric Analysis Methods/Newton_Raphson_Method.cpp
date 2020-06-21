#include<stdio.h>
#include<cmath>
#include <iostream>
#include<cmath>
#define f(x) x*x*x-(5*x)-7
#define df(x) 3*x*x-5
#include <bits/stdc++.h> 

using namespace std;

//bilgilerimi yazmak icin fonksiyon
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
  cout<<"\t####################### SORU 5 ###########################\n";
  cout<<"\t##########################################################\n\n";
}
//aralikta kok olup olmadiginin kontrolu
void kok_kontrol()
{ 
	double a,b,kontrol;
  	tekrar:

    cout<<"\nDenklemin hangi aralikta koku oldunu gostermek istiyorsunuz?  [a,b]:\n\n";
    cout<<"a:";
	cin>>a;
    cout<<"b:";
    cin>>b;
    
    kontrol=(f(a))*(f(b));
    if(kontrol<=0) {
    	cout<<"\nf("<<a<<").f("<<b<<")<0 oldugu icin bu aralikta en az bir koku vardir.\n";  	
    }
    else if (kontrol>0) {
    	cout<<"\nf("<<a<<").f("<<b<<")>0 oldugu icin bu aralikta koku yoktur, tekrar deneyiniz.\n\n";
        goto tekrar;
    }	
}
main() {
	
	int deger=1;
	double x[deger],epsilon;
	bilgilerim();
	cout<<"5.Soru :\nx^3-5x-7=0 denkleminin [a,b] araliginda bir koku oldugunu gosteriniz.\nBu koke Newton-Raphson Metodu ile Xo alarak Epsilon icin yaklasiniz\n\n";
	//kokun olup olmadiginin kontrolu
    kok_kontrol();
	
	cout<<"\nXo degerini giriniz: ";
	cin>>x[0];
	
	cout<<"Epsilon degerini giriniz: ";
	cin>>epsilon;

	while (deger!=0)
	{
	//Newton-Raphson Metodu Formulu	
	x[deger]=(x[deger-1])-((f(x[deger-1]))/(df(x[deger-1])));
		
		if (fabs((x[deger])-(x[deger-1]))<epsilon) {
		
		    cout<<"\n"<<deger-1<<".iterasyonda bulunan kok "<<"x"<<deger-1<<": "<<setprecision(9)<<x[deger]<<endl<<endl;
			break;
		}
		deger++;	
	}
		system("pause");
		
}
	

	

