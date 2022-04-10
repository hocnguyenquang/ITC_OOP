#include <iostream.h>
using namespace std;
class Person //lop cha
{
	private:
	//thuoc tinh
		char ten[30];
		int tuoi;
		char diachi[40];
	public:
	//phuong thuc
	
		
		Person(char *ten = "", int tuoi = 0, char *diachi = "")
		{
			strcpy(this ->ten, ten);
			       this ->tuoi = tuoi;
   			strcpy(this ->diachi, diachi);       
		}
		void nhap()
		{
			cout<<"\nNhap ten: ";
			cin.getline(ten, 30);
			cout<<"\nNhap tuoi: ";
			cin>>tuoi;
			fflush(stdin);
			cout<<"\nNhap dia chi: ";
			cin.getline(diachi, 40);
		}
		void xuat()
		{
			cout<<"\nTen: "<<ten<<endl;
			cout<<"\nTuoi: "<<tuoi<<endl;
			cout<<"\nDia chi: "<<diachi<<endl;
		}
		
		int getTuoi()
		{
			return tuoi;
		}
		
  	 	bool operator > (Person &a)
		{
			return (this ->tuoi > a.tuoi());
		}
		
};

class GiaoVien
{
	private:
		char ma[8];
		char khoa[30];
	public:
	
		GiaoVien(){}
		GiaoVien(char *ma = "", char *khoa = "")
		{
			strcpy(this ->ma, ma);
			strcpy(this ->khoa, khoa);
		}
		void nhap()
		{
			cout<<"\nNhap ma: ";
			cin.getline(ma, 8);
			cout<<"\nNhap khoa: ";
			cin.getline(khoa, 30);
		}
		void xuat()
		{
			cout<<"\nMa: "<<ma<<endl;
			cout<<"\nKhoa: "<<khoa<<endl;
		}	
};

class DaiHoc : public virtual Person, public virtual GiaoVien 
{
	private:
		char clb[30];
		char phong[20];
		
	public:
	
		DaiHoc(char *ten = "", int tuoi = 0, char *diachi = "",
		char *ma = "", char *khoa = "",
		char *clb = "", char *phong = "")
		:Person(ten, tuoi, diachi), GiaoVien(ma, khoa)
		{
			strcpy(this ->clb, clb);
			strcpy(this ->phong, phong);
		}
		
		void nhap()
		{
			Person::nhap();
			GiaoVien::nhap();
			cout<<"\nNhap clb: ";
			cin.getline(clb, 30);
			cout<<"\nNhap phong: ";
			cin.getline(phong, 20);
		}
		void xuat()
		{
			Person::xuat();
			GiaoVien::xuat();
			cout<<"\nClb: "<<clb<<endl;
			cout<<"\nPhong: "<<phong<<endl;
		}	
};

int main(int argc, char *argv[])
{

	/*
int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	fflush(stdin);
	Person a[n];
	cout<<"\nNhap nguoi: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i + 1<<": \n";
		a[i].nhap();
	}
	cout<<"\nXuat giao vien: "<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<"\nNguoi thu "<<i + 1<<": \n";
		a[i].xuat();
	}
	//------------------------
	cout<<"\n----------------------------"<<endl;
	int m;
	cout<<"\nNhap so luong giao vien: ";
	cin>>m;
	fflush(stdin);
	GiaoVien b[m];
	cout<<"\nNhap giao vien: "<<endl;
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiao vien thu "<<i + 1<<": \n";
		b[i].nhap();
	}
	cout<<"\nXuat giao vien: "<<endl;
	for(int i = 0; i < m; i++)
	{
		cout<<"\nGiao vien thu "<<i + 1<<": \n";
		b[i].xuat();
	}*/
	int n;
	cout<<"\nNhap n: ";
	cin>>n;
	fflush(stdin);
	Person a[n];
	for(int i = 0; i < n; i++)
	{
		a[i].nhap();
	}
	for(int i = 0; i < n; i++)
	{
		a[i].xuat();
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
		a[i].xuat();
	}
	return 0;
}