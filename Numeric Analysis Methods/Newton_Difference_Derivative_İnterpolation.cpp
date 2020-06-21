#include <iostream>
#include <conio.h>
#include <bits/stdc++.h> 
using namespace std;

class InterpolasyonTurev
{
public:
	void bilgilerim();
	void baslat();
    void hesapla_ileri_Df();
    void hesapla_geri_Df();
    void sonuc_ileri();
    void sonuc_geri();      
    void turBul();
    void GeriFarkTablo();
    void ileriFarkTablo();
private:
    double XX, x[10] , f[10][10] ,P1,delF[10],f1,f2;
    string secenek;
    int n;
    double h,s;

};
//Programin Baslatilmasi
void InterpolasyonTurev::baslat()
{
	bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
    	cout << "Kac adet x degeri gireceksiniz : ";
   		 cin >> n;

   		 cout << endl;
  		  for(int i = 0; i<n; i++ )
   		  {
     		   cout << "Giriniz X[" << i  << "] : ";
       		   cin >> x[i];
   		  }
   	      cout << endl;
   	      for(int j = 0; j<n; j++ )
   		  {
       		cout << "Giriniz F[" << j  << "] : ";
       		cin >> f[0][j];
    	  } 
   		cout << endl;
    	cout << "df(x) fonksiyonunun  hangi degerine yaklasmak istiyorsunuz ? x= ";
        cin >> XX;	
	}
	else if(secenek=="0")
	{
		//soruda verilen katsayilarin tanimlanmasi
		n=4;// kactane x degeri var elimizde 
		x[0]=0.2;   f[0][0]=0.2733;
		x[1]=0.4;	f[0][1]=0.2258;
		x[2]=0.6;	f[0][2]=0.1895;
		x[3]=0.8;	f[0][3]=0.1627;
		XX=0.3; //Bulunacak x degeri		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}
    turBul();
}
//bilgilerin ekrana hazir fonksiyon sekilde yazdirilmasi
void InterpolasyonTurev::bilgilerim()
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
  cout<<"\t####################### SORU 10 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"10.Soru :\nBir f fonksiyonu icin tablo degerleri biliniyor.Newton ileri fark tablosunu olusturunuz.\nAyrica uygun Newton Ileri interpolasyon polinomuna Analitik Yerine Koyma Meetodu\n";
  cout<<"uygulayarak df(x) deki x degerine yaklasiniz."<<endl<<endl;
}
// ilerimi gerimi interpolasyon formulu kullanilacagini buluyor.
void InterpolasyonTurev::turBul()
{
	if (n%2==0)
    {
    	if(XX<x[n/2] && XX>x[n/2-1])
    	{
    		// x degeri tam ortada her ikiside kullanilabilir
    		cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur."<<endl;
    		ileriFarkTablo();
    		sonuc_ileri();
		}
		else if(XX<x[n/2])
		{
			// x degeri yukariya yakin ileri fark interpolasyonu kullanilir
		    cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur."<<endl;	
			ileriFarkTablo();
			sonuc_ileri();
		}
		else 
		
		{
			// x degeri asagiya yakin geri fark interpolasyonu kullanilir
			cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur.\nGeri Fark Interpolasyon Formulu Kullanilacaktir."<<endl;;
			GeriFarkTablo();
			sonuc_geri();
		}
	}
	else if(n%2!=0)
	{
		if(XX<x[n/2])
    	{
    		cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur."<<endl;
    		ileriFarkTablo();
    		sonuc_ileri();
		}
		else if(XX>x[n/2])
		{
			cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur.\nGeri Fark Interpolasyon Formulu Kullanilacaktir."<<endl;;
			GeriFarkTablo();
			sonuc_geri();
		}
		else 
		{
			cout<<"\nGirilen Deger Sonucunda Ileri Fark Tablosu Olusturulmustur."<<endl;
    		ileriFarkTablo();
    		sonuc_ileri();
		}
	}
}
void InterpolasyonTurev::GeriFarkTablo()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j< n-i;j++)
        {
            f[i][j] = (f[i-1][j+1]-f[i-1][j]);
            if(f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] >-0.0000009 && f[i][j]<0)
            {
                    f[i][j] = 0;
            }
        }
    }
    cout << endl;
    cout << "Sn\tXi\t\tf(Xi)\t";
    for(int i = 0; i <n-1;i++)
    {
        cout << "\t"<< i+1 << ".derec\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
         cout <<i+1 <<"\t" << x[i]<< "\t";
        for(int j = 0; j< n-i;j++)
        {
            cout  << "\t" <<f[j][i] << "\t";
        }
        cout << endl;
    }
}
void InterpolasyonTurev::ileriFarkTablo()
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j< n-i;j++)
        {
            f[i][j] = (f[i-1][j+1]-f[i-1][j]);
            if(f[i][j] < 0.0000009 && f[i][j] > 0 || f[i][j] >-0.0000009 && f[i][j]<0)
            {
                    f[i][j] = 0;
            }
        }
    }
    cout << endl;
    cout << "No\tXi\t\tf(Xi)\t";
    for(int i = 0; i <n-1;i++)
    {
        cout << "\t"<< i+1 << ".derec\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
         cout <<i+1 <<"\t" << x[i]<< "\t";
        for(int j = 0; j< n-i;j++)
        {
            cout << "\t" <<setprecision(9)<< f[j][i] << "\t";
        }
        cout << endl;
    }
}
void InterpolasyonTurev::sonuc_ileri()
{
	//S ve H(aralik uzunlugu) bulunmasi
	h = x[1] - x[0];
	s = (XX - x[0])/h;
     for(int i = 1;i<10;i++)
    {
        if(i<n)
         delF[i]=f[i][0];
        else
            delF[i] = 0;
    }
    hesapla_ileri_Df();

    cout <<endl << "df(x) fonksiyonunda x= :" <<XX<<" icin sonuc = "<<setprecision(9)<< f1;
    cout  << endl << endl;
}
void InterpolasyonTurev::sonuc_geri()
{
	//S ve H(aralik uzunlugu) bulunmasi
    h = x[1] - x[0];
    s = (XX - x[n-1])/h;
    for(int i = 1;i<10;i++)
    {
        if(i<n)
         delF[i] = f[i][n-i-1];
        else
            delF[i] = 0;
    }
    hesapla_geri_Df();

    cout <<endl << "df(x) fonksiyonunda x= :" <<XX<<" icin sonuc = "<<setprecision(9)<< f1;
    cout  << endl << endl;
}
void InterpolasyonTurev::hesapla_ileri_Df()
{
	//ileri interpolasyon formulu
    f1 = 1 / h * ( delF[1] + 1/2.0 * (2 * s -1 ) * delF[2] + 1 / (6.0) * (3*s*s - 6 *s +2)*
         delF[3] + 1 /(24.0) *( 4*s*s*s-18*s*s+22*s-6)*delF[4]);
}
void InterpolasyonTurev::hesapla_geri_Df()
{
	//geri interpolasyon formulu (delF ler degisiyor fonksiyonda)
    f1 = 1 / h * ( delF[1] + 1/2.0 * (2 * s +1 ) * delF[2] + 1 / (6.0) * (3*s*s + 6 *s +2)*delF[3]
        + 1 /(24.0) *( 4*s*s*s+18*s*s+22*s+6)*delF[4]);
}
int main()
{
    InterpolasyonTurev program;
    program.baslat();   
    system("pause");
}
