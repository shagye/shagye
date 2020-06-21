#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class SoruDort
{
public:	
	void bilgilerim();
	void baslat();
	int iterasyon;
	string secenek;
};
void SoruDort::bilgilerim()
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
  cout<<"\t####################### SORU 4 ###########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"4.Soru :\nA matrisinin tersi bilindigine gore v1 degerlerini alarak A matrisinin en kucuk ozdegerinin \nVianello metodu ile iterasyon sayisi sonunda yaklasik degerini bulunuz.\n\n";
}
void SoruDort::baslat()
{
	bilgilerim();	
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout<<"Kac iterasyon sonundaki yaklasik degeri istiyorsunuz? Giriniz ; ";
		cin>>iterasyon;
		float ters_matris[3][3];
		
		cout<<"#########################"<<endl;
		cout<<"#        	   __                 __       __  __		 "<<endl;
		cout<<"#		   |                   |       |    | "<<endl;
		cout<<"#		   |  a11  a12   a13   |       | v1 |    "<<endl;
		cout<<"#    A'nin tersi = |  a21  a22   a23   |   V1 =| v2 |	     "<<endl;
		cout<<"#                  |  a31  a32   a33   |       | v3 |"<<endl;
		cout<<"#		   |_                 _|       |_  _|      "<<endl;
		cout<<"#"<<endl;
		cout<<"#########################"<<endl;
		
		cout<<"Ters matrisi :"<<endl;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<"a"<<i+1<<j+1<<"= ";
				cin>>ters_matris[i][j];
			}	
		}
		float V[3][iterasyon];
		cout<<"V matrisini  :"<<endl;
		
		for(int i=0;i<3;i++){
			cout<<"v"<<i+1<<"= ";
			cin>>V[i][0];	
		}
		float gecici1,gecici2,gecici3;
		for(int i=1;i<=iterasyon;i++){
			
			for(int j=0;j<1;j++){
				
				gecici1=(ters_matris[0][0]*V[0][i-1])+(ters_matris[0][1]*V[1][i-1])+(ters_matris[0][2]*V[2][i-1]);
				gecici2=(ters_matris[1][0]*V[0][i-1])+(ters_matris[1][1]*V[1][i-1])+(ters_matris[1][2]*V[2][i-1]);
				gecici3=(ters_matris[2][0]*V[0][i-1])+(ters_matris[2][1]*V[1][i-1])+(ters_matris[2][2]*V[2][i-1]);
				
				V[j][i]=gecici1/gecici3;
				V[j+1][i]=gecici2/gecici3;
				V[j+2][i]=gecici3/gecici3;	
			}  
		}
		cout<<"\n"<<iterasyon<<". iterasyon sonunda Vianello metodu ile elde edilen yaklasik en kucuk ozdeger;\n";
		cout<<endl<<"Matrisin en buyuk oz degeri = "<<setprecision(9)<<gecici3<<endl;
		cout<<"Matrisin en kucuk oz degeri = "<<setprecision(9)<<1/gecici3<<endl<<endl;
	}
	else if(secenek=="0")
	{
      int iterasyon=3;
      float ters_matris[3][3];	
	  float V[3][iterasyon];
	  ters_matris[0][0]=8;     ters_matris[0][1]=-3;   ters_matris[0][2]=2;
	  ters_matris[1][0]=4;     ters_matris[1][1]=11;   ters_matris[1][2]=-1;
	  ters_matris[2][0]=6;    ters_matris[2][1]=4;    ters_matris[2][2]=12;
	  V[0][0]=0.4706;  V[1][0]=0.5147;  V[2][0]=1;
	  float gecici1,gecici2,gecici3;
		for(int i=1;i<=iterasyon;i++){
			
			for(int j=0;j<1;j++){
				
				gecici1=(ters_matris[0][0]*V[0][i-1])+(ters_matris[0][1]*V[1][i-1])+(ters_matris[0][2]*V[2][i-1]);
				gecici2=(ters_matris[1][0]*V[0][i-1])+(ters_matris[1][1]*V[1][i-1])+(ters_matris[1][2]*V[2][i-1]);
				gecici3=(ters_matris[2][0]*V[0][i-1])+(ters_matris[2][1]*V[1][i-1])+(ters_matris[2][2]*V[2][i-1]);
				V[j][i]=gecici1/gecici3;
				V[j+1][i]=gecici2/gecici3;
				V[j+2][i]=gecici3/gecici3;
			}  
		}
		cout<<"\n"<<iterasyon<<". iterasyon sonunda Vianello metodu ile elde edilen yaklasik ozdegerler ;\n";
		cout<<endl<<"Matrisin en buyuk oz degeri = "<<setprecision(9)<<gecici3<<endl;
		cout<<"Matrisin en kucuk oz degeri = "<<setprecision(9)<<1/gecici3<<endl<<endl;
	  
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
}

main(){
	
	SoruDort program;
	program.baslat();
	
	system("pause");
	
}







