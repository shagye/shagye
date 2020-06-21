#include <iostream>
#include<cmath>
#include <bits/stdc++.h> 
#define f(x) exp(-x)-(x*x)+1
#define df(x) -exp(-x)-(2*x)

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
  cout<<"\t####################### SORU 6 ###########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
}

void kok_kontrol()
{ 
	double a,b,kontrol;
  	tekrar:
    cout<<"\nDenklemin hangi aralikta koku oldunu gostermek istiyorsunuz?  [a,b]:\n\n";
    cout<<"a:"; cin>>a;
    cout<<"b:"; cin>>b;
    
    kontrol=(f(a))*(f(b));
    if(kontrol<=0) {
    	cout<<"\nf("<<a<<").f("<<b<<")<0 oldugu icin f(x)'in bu aralikta en az bir koku vardir.\n";  	
    }
    else if (kontrol>0) {
    	cout<<"\nf("<<a<<").f("<<b<<")>0 oldugu icin f(x)'in bu aralikta koku yoktur, tekrar deneyiniz.\n\n";
        goto tekrar;
    }	
}

main() {
	
	int deger=1;
	float x[deger],epsilon;
	bilgilerim();
	cout<<"6.Soru :\ne^(-3)-x^(2)+1=0 denkleminin [a,b] araliginda bir koku oldugunu gosteriniz.\nBu koke Von-Misses Metodu ile Xo alarak Epsilon Degeri ile yaklasiniz\n\n";
	kok_kontrol();
	cout<<"Xo degerini giriniz: ";
	cin>>x[0];	
	cout<<"Epsilon degerini giriniz: ";
	cin>>epsilon;
	while(deger!=0)
	{
		//Von Misses Metodu Formul
		x[deger]=(x[deger-1])-((f(x[deger-1]))/(df(x[0])));
		
		if (fabs((x[deger])-(x[deger-1]))<epsilon) 
		{	
			cout<<"\n"<<deger+1<<".iterasyonda bulunan kok "<<"x"<<deger+1<<": "<<setprecision(9)<<x[deger]<<endl<<endl;
		    break;
		}	
		deger++;
	}
	system("pause");	
}
	

	

