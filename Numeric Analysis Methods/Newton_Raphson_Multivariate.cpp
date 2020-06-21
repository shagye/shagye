#include<iostream>
#include<cmath>
#include <bits/stdc++.h> 


using namespace std;

#define fxy(x,y) (a1)*(x*x)+(b1)*(y*y)-(c1)
#define gxy(x,y) (a2)*x-(b2)*y-(c2)
#define fx(x) a1*2*x
#define fy(y) b1*2*y
#define gx(x) a2
#define gy(y) (-1)*b2

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
  cout<<"\t####################### SORU 9 ###########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
}

main(){
	int iterasyon;
	float x[iterasyon],y[iterasyon];
	float a1,b1,c1,a2,b2,c2;
	string secenek;
	
	bilgilerim();
	cout<<"9.Soru :\n(a1)x^2+(b1)x^2   =(c1)\n(a2)x+(b2)y =(c2) denklem  sisteminin cozumune iterasyon sayisi (Xo,Yo) degerlerini alarak-\nSistemler icin Newton-Raphson Metodu ile yaklasiniz.\n\n";
	
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;

    if(secenek=="1")
    {
    	cout<<"(a1)x^2+(b1)y^2=(c1) fonksiyonunda a1,b1 ve c1 degerlerini giriniz:\n";
		cout<<"a1:";
		cin>>a1;
		cout<<"b1:";
		cin>>b1;
		cout<<"c1:";
		cin>>c1;
		cout<<"\n";
		cout<<"(a1)x-(b2)y=(c2) fonksiyonunda a2,b2 ve c2 degerlerini giriniz:\n";
		cout<<"a2:";
		cin>>a2;
		cout<<"b2:";
		cin>>b2;
		cout<<"c2:";
		cin>>c2;
		cout<<"\n";
	    
		cout<<"Iterasyon sayisini giriniz : \n";
		cin>>iterasyon;
		x[iterasyon],y[iterasyon];
		
	 	cout<<"\n(Xo,Yo) baslangic degerleri giriniz;\n\n";
	 	
		cout<<"x0 :";
		cin>>x[0];
		cout<<"y0 :";
		cin>>y[0];
	
		
	}
	else if(secenek=="0")
	{
		//soruda verilen katsayilarin tanimlanmasi
		a1=1; b1=1; c1=5;
		a2=1; b2=1; c2=1;
		iterasyon=2;
		x[iterasyon],y[iterasyon];
		x[0]=1.5;
		y[0]=0.5;	
	}
	
	cout<<"\nSONUC"<<endl;
	for(int i=0;i<iterasyon;i++){
	
		float fxy=fxy(x[i],y[i]);
		float gxy=gxy(x[i],y[i]);
		float fx=fx(x[i]);
		float fy=fy(y[i]);
		float gx=gx(x[i]);
		float gy=gy(y[i]);
		
		
		x[i+1] = x[i] - (((fxy*gy)-(gxy*fy))/((fx*gy)-(fy*gx)));
		y[i+1] = y[i] - (((gxy*fx)-(fxy*gx))/((fx*gy)-(fy*gx)));
		
		cout<<"\n";
		cout<<"(x"<<i+1<<",y"<<i+1<<") = ("<<setprecision(10)<<x[i+1]<<","<<setprecision(10)<<y[i+1]<<")\n";
		
		
	}
	
	cout<<"\n"<<iterasyon<<". iterasyon sonunda elde edilen yaklasik kokler ;\n\n(c,d) = (x"<<iterasyon<<",y"<<iterasyon<<") = ("<<setprecision(10)<<x[iterasyon]<<","<<setprecision(10)<<y[iterasyon]<<")\n";
	
	
	system("pause");
	

	
}









