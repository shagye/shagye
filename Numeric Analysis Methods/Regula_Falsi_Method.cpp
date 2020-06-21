#include <iostream>
#include<cmath>
#include <bits/stdc++.h> 
#define f(x) sin(x)-x*exp(-x)

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
  cout<<"\t####################### SORU 7 ###########################\n";
  cout<<"\t##########################################################\n\n";
}

//aralikta kok olup olmadiginin kontrolu
void kok_kontrol()
{ 
	double a,b,kontrol;
  	tekrar:

    cout<<"\nf(x)'in' hangi aralikta koku oldunu gostermek istiyorsunuz?  [a,b]:\n\n";
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
	
	int iterasyon;
	float x[3];
	bilgilerim();
	cout<<"7.Soru :\nsinx-x^(-x) denkleminin [a,b] araliginda bir koku oldugunu gosteriniz.\nBu kokun Xo ve X1 alarak iterasyon degeri sonunda yaklasik degerini Regula-Falsi Metodu ile bulunuz.\n\n";
	kok_kontrol();
	cout<<"X[0] degerini giriniz: ";
	cin>>x[0];
	
	cout<<"X[1] degerini giriniz: ";
	cin>>x[1];
			
	cout<<"\nKac iterasyon sonundaki yaklasik degerini hesaplama istiyorsunuz : ";
	cin>>iterasyon;
		
	for (int deger=1;deger<=iterasyon;deger++) { 
		//Regula Falsi Metodu
		x[2]=(((x[0])*(f(x[1])))-((x[1])*(f(x[0]))))/((f(x[1]))-(f(x[0])));	
		if(f(x[0])*f(x[2])<0){
			// Kok 1,2 araligindaysa
			x[1]= x[2];	
		}
		else {
			//kok 0,2 araligindayhsa
			x[0]= x[2];
		}
    }
		cout<<endl<<iterasyon<<" iterasyon sonucu yaklasik kok x3= "<<setprecision(9)<<x[2]<<endl<<endl;
    system("pause");
}

		

	

