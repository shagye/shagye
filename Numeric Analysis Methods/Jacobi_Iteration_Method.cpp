#include<cmath>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class Soruiki
{
	
public:
	
	void  bilgilerim();
	void  baslat();
	bool kontrol1(float x[3][3]);
	bool kontrol2(float y[3][3]);
    bool kontrol3(float z[3][3]);
    //degiskenler
    float k[3][3];
    int iterasyon;
    string secenek;
    
};
void Soruiki::bilgilerim()
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
  cout<<"\t####################### SORU 2 ###########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";  
  cout<<"2.Soru :\nLineer denklem sisteminin cozumune x0 baslangic degeri icin \nJacobi(basit) Iterasyon Metodu ile Yakinsayin\n\n";
}
bool Soruiki::kontrol1(float x[3][3]){
	bool s1=fabs(x[0][0])>fabs(x[0][1])+fabs(x[0][2]);
	return (s1 == true) ? true : false;
}	
bool Soruiki::kontrol2(float y[3][3]){
    bool s2=fabs(y[1][1])>fabs(y[1][0])+fabs(y[1][2]);
	return (s2 == true) ? true : false;
}
bool Soruiki::kontrol3(float z[3][3]){
    bool s3=fabs(z[2][2])>fabs(z[2][0])+fabs(z[2][1]);
	return (s3 == true) ? true : false;
}

void Soruiki::baslat()
{
	bilgilerim();
	
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	tekrar://domimnant olmadigi zaman buraya gelir
		cout<<"Kac iterasyon sonundaki yaklasik degeri istiyorsunuz? Giriniz ; ";
		cin>>iterasyon;
		
		cout<<"#########################"<<endl;
		cout<<"#       __                 __  __  __   __  __		 "<<endl;
		cout<<"#	|                   |  |    |   |    | "<<endl;
		cout<<"#	|  a11  a12   a13   |  | x1 |   | c1 |    "<<endl;
		cout<<"#	|  a21  a22   a23   | .| x2 |  =| c2 |	     "<<endl;
		cout<<"#       |  a31  a32   a33   |  | x3 |   | c3 |"<<endl;
		cout<<"#	|_                 _|  |_  _|   |_  _|      "<<endl;
		cout<<"#"<<endl;
		cout<<"#########################"<<endl;
		cout<<"\nKatsayilar matrisini giriniz:"<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<"(a"<<i+1<<j+1<<") = ";
				cin>>k[i][j];
			}	
		}
		//dominant olum olmadiginin kontrolu
		if(kontrol1(k)== true && kontrol2(k)==true && kontrol3(k)==true){
		
			goto atla;	
		}
		else {
			cout<<"Katsayilar matrisi kosegensel dominant degildir."<<endl;
			goto tekrar;
		}
		atla:
		float d_matris[3];
		cout<<"\nDeger Matrisini Giriniz.\n";
		for(int i=0;i<3;i++){
		
		cout<<"c"<<i+1<<" = ";
		cin>>d_matris[i];
		
		}
		float x_deger[3][iterasyon];
		cout<<"\nBaslangic Deger Matrisini Giriniz:\n";
		for(int i=0;i<3;i++){
		
		cout<<" X(0)"<<i+1<<" = ";
		cin>>x_deger[i][0];
		}
		for(int i=1;i<=iterasyon;i++){
			x_deger[0][i]=(d_matris[0]-((k[0][1]*x_deger[1][i-1])+(k[0][2]*x_deger[2][i-1])))/k[0][0];
			x_deger[1][i]=(d_matris[1]-((k[1][0]*x_deger[0][i-1])+(k[1][2]*x_deger[2][i-1])))/k[1][1];
			x_deger[2][i]=(d_matris[2]-((k[2][0]*x_deger[0][i-1])+(k[2][1]*x_deger[1][i-1])))/k[2][2];	
		}
		cout<<endl;
		cout<<"\nHESAPLAMALAR\n";
		for(int i =0;i<iterasyon;i++){
			cout<<"x("<<i+1<<")\t"<<setprecision(9)<<x_deger[0][i+1]<<"  "<<x_deger[1][i+1]<<"  "<<x_deger[2][i+1]<<endl;
			
			if(i==iterasyon-1)
			{
				cout<<"\n"<<iterasyon<<". iterasyon sonucunda elde edilen yaklasik Cozum Matrisi;\n\n";
				cout<<"x("<<iterasyon<<");"<<endl;
				cout<<"x1  = "<<setprecision(9)<<x_deger[0][i+1]<<endl;
				cout<<"x2  = "<<setprecision(10)<<x_deger[1][i+1]<<endl;
				cout<<"x3  = "<<setprecision(10)<<x_deger[2][i+1]<<endl<<endl;
			}
		}
	}
	else if(secenek=="0")
	{
		iterasyon=2;
		k[0][0]=5; k[0][1]=1;  k[0][2]=2;
		k[1][0]=2; k[1][1]=-4; k[1][2]=1;
		k[2][0]=1; k[2][1]=-1; k[2][2]=-3;
		float x_deger[3][iterasyon];
		float d_matris[3];
		d_matris[0]=15;  d_matris[1]=11;   d_matris[2]=-6;
		x_deger[0][0]=1.7;	  x_deger[1][0]=-0.5;    x_deger[2][0]=3.3;	
		for(int i=1;i<=iterasyon;i++){
			x_deger[0][i]=(d_matris[0]-((k[0][1]*x_deger[1][i-1])+(k[0][2]*x_deger[2][i-1])))/k[0][0];
			x_deger[1][i]=(d_matris[1]-((k[1][0]*x_deger[0][i-1])+(k[1][2]*x_deger[2][i-1])))/k[1][1];
			x_deger[2][i]=(d_matris[2]-((k[2][0]*x_deger[0][i-1])+(k[2][1]*x_deger[1][i-1])))/k[2][2];	
		}
		cout<<endl;
		cout<<"\nHESAPLAMALAR\n";
		for(int i =0;i<iterasyon;i++){
			cout<<"x("<<i+1<<")\t"<<setprecision(9)<<x_deger[0][i+1]<<"  "<<x_deger[1][i+1]<<"  "<<x_deger[2][i+1]<<endl;
			
			if(i==iterasyon-1)
			{
				cout<<"\n"<<iterasyon<<". iterasyon sonucunda elde edilen yaklasik Cozum Matrisi;\n\n";
				cout<<"x("<<iterasyon<<");"<<endl;
				cout<<"x1  = "<<setprecision(9)<<x_deger[0][i+1]<<endl;
				cout<<"x2  = "<<setprecision(10)<<x_deger[1][i+1]<<endl;
				cout<<"x3  = "<<setprecision(10)<<x_deger[2][i+1]<<endl<<endl;
			}
		}
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
	
}

main(){
	
	Soruiki program;
	program.baslat();	
	system("pause");	
}


   

