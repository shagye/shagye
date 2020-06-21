
#include <iostream> 
#include <bits/stdc++.h> 
using namespace std; 
void turBul();
float x[30], y[30][30];
    int i,n; 
    string secenek;
    float x_degeri;
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
  cout<<"\t####################### SORU 11 ##########################\n";
  cout<<"\t##########################################################\n\n";
  
  cout<<"\t         Ondalikli islemlerde nokta(.) kullanin  \n\n";
  cout<<"11.Soru :\nBir f fonksiyonu icin tablo degerleri biliniyor.Newton ileri fark tablosunu olusturunuz.\nAyrica uygun Newton interpolasyon polinomunu kullanarak f(x) degerine yakinlasiniz.\n\n";
  
}
void ileriFarkTablo()
{
    // ileri fark tablosunun yazilmasi	
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j< n-i;j++)
        {
            y[i][j] = (y[i-1][j+1]-y[i-1][j]);
        }
    }
    cout << endl;
    cout << "Sn\tXi\t\tf(Xi)\t";
    for(int i = 0; i <n-1;i++)
    {
        cout <<"\t"<< i+1 << ".derec\t";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
         cout <<i+1 <<"\t" << x[i]<< "\t";
        for(int j = 0; j< n-i;j++)
        {
            cout << "\t" << y[i][j] << "\t";
        }
        cout << endl;
    }
}
void program_baslat()
{
    //programin baslatilmasi
	bilgilerim();
	bas:
	cout<<"Genel Cozum yapmak icin (1), Ozel Cozum icin (0) yazip enter`a tiklayiniz :";
	cin>>secenek;
	cout<<endl;
    if(secenek=="1")
    {
     cout << "Tabloda Kac tane x degeri var? " << endl;
     cin >> n;
    
   	 cout << "X degerlerini gir: " << endl;
     for(i = 0; i < n ; i++)
        {
    	  cout << "x[" << i << "] = ";
     	  cin >> x[i];
      
    	}
     	cout << "\nf(x) degerlerini gir: " << endl;
     	for(i=0 ; i<n;i++)
     	{
      		cout << "y[" << i <<"] = ";
      		cin >> y[i][0];
	 	}
     
	 cout << "\nf(x) fonksiyonun hangi degerine Newton Ileri Fark Interpolasyonu ile yaklasmak istiyorsun ? \nF(x) fonksiyonundaki x=  " ;
     cin >> x_degeri;	
	}
	else if(secenek=="0")
	{
		//lOzel Cozum l icin soruda verilen katsayilarin tanimlanmasi
		n=4;// kactane x degeri var elimizde 
		x[0]=0.6;   y[0][0]=-0.2607;
		x[1]=0.8;	y[1][0]=0.0207;
		x[2]=1;	    y[2][0]=0.2536;
		x[3]=1.2;	y[3][0]=0.5697;
		x_degeri=0.7; //yaklasilacak x degeri		
	}
	else{
		cout<<" Sadece 1 ve 0 girebilirsiniz tekrar deneyiniz.\n";
		goto bas;
	}	
    turBul(); // ilerimi gerimi interpolasyon formulunun kullanilacagini belirler
}
float ust_ileri_hesapla(float s, int n) 
{ 
	float onceki = s; 
	for (int i = 1; i < n; i++) 
		onceki = onceki * (s - i); 
	return onceki; 
} 
float ust_geri_hesapla(float s, int n) 
{ 
	float onceki = s; 
	for (int i = 1; i < n; i++) 
		onceki = onceki * (s + i); 
	return onceki; 
} 
int faktoriyel(int n) 
{ 
	int f = 1; 
	for (int i = 2; i <= n; i++) 
		f *= i; 
	return f; 
} 
void turBul()
{
	if (n%2==0)
    {
    	if(x_degeri<x[n/2] && x_degeri>x[n/2-1])
    	{
    		goto ilerifark;
		}
		else if(x_degeri<x[n/2])
		{
			ilerifark:
					for (int i = 1; i < n; i++) { 
      				  for (int j = 0; j < n - i; j++) 
         				   y[j][i] = y[j + 1][i - 1] - y[j][i - 1]; 
   					} 
                    cout<< endl<<"Newton Ileri Fark Tablosu "<<endl;
                    ileriFarkTablo();
						float toplam = y[0][0]; 
						float s = (x_degeri - x[0]) / (x[1] - x[0]); 
						for (int i = 1; i < n; i++) { 
							toplam = toplam + (ust_ileri_hesapla(s, i) * y[0][i]) / 
									faktoriyel(i); 
						}
					cout << "\n f(x) fonksiyonunun x=" << x_degeri << " deki yaklasik degeri f("<<x_degeri<<")= "<<setprecision(9)<<
					toplam << endl<<endl; 
					system("pause"); 
		}
		else 
		{
			    gerifark:
   				for (int i = 1; i < n; i++) { 
       				 for (int j = n - 1; j >= i; j--) 
           				 y[j][i] = y[j][i - 1] - y[j - 1][i - 1]; 
    			}   
    			cout << endl << "Newton Geri Fark Tablosu" << endl; 
    			for (int i = 0; i < n; i++) { 
       				 for (int j = 0; j <= i; j++) 
            			 cout << setw(4) << y[i][j]  
               			 << "\t"; 
       					 cout << endl; 
    			} 
    			float toplam = y[n - 1][0]; 
  			    float s = (x_degeri - x[n - 1]) / (x[1] - x[0]); 
   				for (int i = 1; i < n; i++) { 
      				  toplam = toplam + (ust_geri_hesapla(s, i) * y[n - 1][i]) / 
                                     faktoriyel(i); 
   					 } 
                cout << "\n f(x) fonksiyonunun x=" << x_degeri << " deki yaklasik degeri =  "<<setprecision(9)<<
				toplam << endl; 
				system("pause");	
		}
	}
	else if(n%2!=0)
	{
		if(x_degeri<x[n/2])
    	{
    		goto ilerifark;
		}
		else if(x_degeri>x[n/2])
		{
			goto gerifark;
		}
		else 
		{	
	    	goto ilerifark;
		}
	}
}

int main() 
{ 
    program_baslat();
    system("pause");			
} 

