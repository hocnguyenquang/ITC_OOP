#include <iostream.h>
#include <string.h>
#include <iomanip.h>
using namespace std;
struct Date
{
	int	day , mouth , year;
Date()
{
	day = 1 ;
	mouth = 1;
	year = 2000;
}
};

class PTGT
{
	protected:
	char Ma_pt[10];
	char Hang_sx[35];
	Date date;
	float Gia_chuathue;
	public:
PTGT(char *ma =" " , char *hang = " " , float gia = 0.0)
{
	strcpy(Ma_pt , ma );
	strcpy( Hang_sx , hang );
	Date();
	Gia_chuathue = gia ;
}
~PTGT(){}
void Nhap_PTGT()
{
	fflush(stdin);
	cout << "\nNhap vao ma phuong tien :"; cin.getline(Ma_pt , 11);
	cout << "\nNHAP vao Hang San Xuat :"; cin.getline(Hang_sx ,36);
	cout << "\nNhap vao (Ngay - Thang - Nam ) :"; cin >> date.day >> date.mouth >> date.year;
	cout << "\nNhap gia chua thue :" ; cin >>Gia_chuathue;
}	
void Xuat_TT_PTGG()
{
	cout << setw(10) << Ma_pt
		<< setw(30) << Hang_sx
		<< setw(10) << date.day << "-" << date.mouth << "-" << date.year
		<<"\t"<<setw(15) << size_t(Gia_chuathue);
}

};

class MAYBAY :public PTGT
{
	private:
	char duong_Bay[20];
	int so_chongoi;
	char noi_dk_KD[50];
	public:
	MAYBAY(char *ma =" " , char *hang = " " , float gia = 0.0 , char *dB = " " , int cN= 0
	, char *NDK =" ") :PTGT(ma , hang , gia)
	{
		strcpy( duong_Bay , dB);
		so_chongoi = cN;
		strcpy(noi_dk_KD, NDK);
	}
	~MAYBAY(){}
	friend istream &operator >> (istream &is,MAYBAY &mb)
	{
	mb.PTGT::Nhap_PTGT();
	fflush(stdin);
	cout << "\nNhap Duong Bay la :" ; is .getline(mb.duong_Bay , 21);
	cout << "\nNhap So cho Ngoi la :"; is >> mb.so_chongoi;
	cin.ignore();
	cout << "\nNhap noi Dk Kinh Doanh la :"; is.getline(mb.noi_dk_KD , 51);
	return is ;
	}
	float GiaSau_Thue()
	{
		return Gia_chuathue + (Gia_chuathue * 0.08);
	}
	  bool operator < (int cho_ngoi)
	{
		return (this-> so_chongoi > cho_ngoi);
	}
	friend ostream &operator << (ostream &os,MAYBAY &mb)
	{
		os << "\n";
		mb.PTGT::Xuat_TT_PTGG();
		os << setw(10) << mb.duong_Bay ;
		os << setw(5) << mb.so_chongoi;
		os << setw(40) << mb.noi_dk_KD;
		os << setw(10) << size_t(mb.GiaSau_Thue());
		os << endl;
		return os;
	}
	char *get_NoiDK()
	{
		return noi_dk_KD;
	}
	char *get_Ma()
	{
		return Ma_pt;
	}
	int get_ChoNgoi()
	{
		return so_chongoi;
	}
	char *get_HangSX()
	{
		return Hang_sx;
	}
	float get_giaCT()
	{
		return Gia_chuathue;
	}
};
void swap();

void Sap_Xep(MAYBAY mb[] , int n)
{
	for (int i = 0 ;i < n-1 ;i++)
	{
		for(int j = i+1 ; j< n ; j++)
		{
			if(mb[i].get_giaCT() > mb[j].get_giaCT())
			{
				swap(mb[i], mb[j]);
			}
		}
	}
}

void Menu(MAYBAY mb[] , int n)
{
	int luachon;
	while(true)
	{
	cout << "\n|**************************** Menu ****************************|";
	cout << "\n| 0. Thoat .                                                   |";
	cout << "\n| 1. In ra danh sach may bay da nhap .                         |";
	cout << "\n| 2.Danh sach Mb dang ki kinh doanh tai 'Viet Nam'.            |";
	cout << "\n| 3.Tim ds cac Mb nhap tu ban phim .                           |";
	cout << "\n| 4.Dem so Mb co cho ngoi > 200 .                              |";
	cout << "\n| 5. In ra Ds may hang 'Boeing' tang dan cua gia chua thue .   |";
	cout << "\n|**************************** End *****************************|";
	cout << endl;
	cout << "\nNhap lua chon (0-> 5) :";
	cin >> luachon;
	
	if( luachon == 0)
	{
		break;
	}
	else if( luachon >= 6)
	{
		cout << "\nNhap lai !";
	}
	else if(luachon == 1)
	{
		cout << "\nTHuc hien chuc nang 1 .";
		cout << "\nDanh sach da nhap :";
		for(int i = 0 ;i < n ;i++)
		{
			cout << mb[i];
		}
	}
	else if(luachon == 2)
	{
		cout << "\nTHuc hien chuc nang 2 .";
		cout << "\n May Bay noi dang ky KD tai 'VietNam' : ";
		for(int i = 0 ;i < n ;i++)
		{
			if(strcmpi(mb[i].get_NoiDK() , "Viet Nam")== 0)
			{
				cout << mb[i];
			}
		}	
	}
	else if(luachon == 3)
	{
		cout << "\nTHuc hien chuc nang 3.";
		bool ktra = false;
		char ma_cantim[10];
		cout << "\nNhap ma may bay can tim :";
		fflush(stdin);
		cin.getline(ma_cantim , 11);
		for(int i = 0 ; i< n ;i++)
		{
			if(strcmpi(mb[i].get_Ma() , ma_cantim) == 0)
			{
				ktra = true;
			}
		}
		if( ktra == true)
		{
			cout << "\nMa may bay can tim la :";
			for(int i = 0 ; i< n ;i++)
		{
			if(strcmpi(mb[i].get_Ma() , ma_cantim) == 0)
			{
				cout << mb[i];
			}
		}
		}
		else {
			cout << "\nKhong co ma duoc tim thay trong DS ";
		}
	}
	else if(luachon == 4)
	{
		cout << "\nTHuc hien chuc nang 4 .";
		int dem = 0;
		for(int i =0 ;i < n ;i++)
		{
			if(mb[i] < 200)
			{
				dem ++;
			}
		}
		cout<< "\nSo may bay co cho Ngoi > 200 la :" << dem ;
	}
	
else if(luachon == 5)
	{
		cout << "\nTHuc hien chuc nang 5 .";
	cout << "\nHang may bay 'Boeing' la :";
		for(int i = 0 ;i < n ;i++)
		{
			if(strcmpi(mb[i].get_HangSX() , "Boeing")== 0)
			{	
					Sap_Xep(mb , n);
			}
		}
		cout << "\nDanh sach da duoc sap xep .";
	cout << "\nDanh sach da sap xep hang 'Boeing' theo thu tu tang dan cua Gia Chua Thue";
			for(int i = 0 ;i < n ;i++)
		{
			if(strcmpi(mb[i].get_HangSX() , "Boeing")== 0)
			{
				cout << mb[i];
			}
		}
	}
}
}

void swap(MAYBAY &a , MAYBAY &b)
{
	MAYBAY temp = a ;
	a = b;
	b = temp;		
}
int main()
{
	int n ;
	MAYBAY *mb ;
	do{
		cout << "\nNhap so Luong MAy Bay :"; cin >> n;
		if( n <= 0)
		{
			cout << "\nNhap sai !" << endl;
		}
	}while(n <= 0);
	mb = new MAYBAY [n];
	cout << "\n\t Nhap may bay :";
	for(int i = 0 ; i < n ;i++)
	{
		cout << "\nNhap may bay thu " << i+1 << " :";
		cin >> mb[i];
	}
	Menu(mb , n);
	
	delete[]mb;
	return 0;
}
