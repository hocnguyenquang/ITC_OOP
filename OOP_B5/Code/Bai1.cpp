#include <iostream.h>
#include <iomanip.h>
using namespace std;
class NGUOI{
	
	private:
		char ht[30];
		char scm[10];
		char gt[4];
		
	public:
		NGUOI(){}
		
		NGUOI(char *ht, char *scm, char *gt)
		{
			strcpy(this ->ht, ht);
			strcpy(this ->scm, scm);
			strcpy(this ->gt, gt);
		}
		
		~NGUOI(){}
		
		void Nhap(){
			fflush(stdin);
			cout<<"\nNhap ho ten: ";
			cin.getline(ht, 30);
			cout<<"\nNhap so chung minh: ";
			cin.getline(scm, 10);
			cout<<"\nNhap gioi tinh: ";
			cin.getline(gt, 4);
		}
		
		void Xuat(){
			cout<<setw(31)<<ht
				<<setw(11)<<scm
				<<setw(10)<<gt;
		}	
};

class HS : public NGUOI{
	private:
		char cn[20];
		float dtk;
		
	public:
		HS(char *ht = "", char *scm = "", char *gt = "", char *cn = "", float dtk = 0.0)
		:NGUOI(ht, scm, gt)
		{
			strcpy(this ->cn, cn);
			       this->dtk=dtk;
		}
		
		~HS(){}
		
		void Nhap(){
			fflush(stdin);
			NGUOI::Nhap();
			cout<<"\nNhap chuyen nganh: ";
			cin.getline(cn, 20);
			cout<<"\nNhap diem tong ket: ";
			do{
				cin>>dtk;
				if(dtk < 0 && dtk > 10){
					cout<<"\nNhap lai diem tong ket!!";
				}
			}while(dtk < 0 && dtk > 10);	
		}
		
		char *xeploai(){
			if(dtk >= 0 && dtk <= 4.9){
				return "Yeu";
			}
			else if(dtk >= 5 && dtk <= 7.9){
				return "Kha";
			}
			else{
				return "Gioi";
			}
		}
		
		bool operator > (const HS &hs){
			return (this ->dtk > hs.dtk);
		}
		
		void Xuat(){
			NGUOI::Xuat();
			cout<<setw(21)<<cn
				<<setw(10)<<dtk<<endl;
		}
		
		float getDTK(){
			return dtk;
		}	
};

void TieuDe1(){
	cout<<setw(31)<<"HO TEN"
		<<setw(11)<<"SCM"
		<<setw(10)<<"GIOI TINH";
}

void TieuDe2(){
	TieuDe1();
	cout<<setw(21)<<"CHUYEN NGANH"
		<<setw(10)<<"DTK"<<endl;
}

int main(int argc, char *argv[])
{
	int n;
	cout<<"\nNhap so luong nguoi: ";
	cin>>n;
	NGUOI *ng = new NGUOI[n];
	//NGUOI ng[n];
	cout<<"\nNhap thong tin danh sach NGUOI: "<<endl;
	for(int i = 0; i < n; i++){
		cout<<"\nNGUOI THU "<<i+1<<": \n";
		ng[i].Nhap();
	}
	cout<<"\nXuat thong tin danh sach NGUOI: "<<endl;
	TieuDe1();
	for(int i = 0; i < n; i++){
		cout<<"\nNGUOI THU "<<i+1<<": \n";
		ng[i].Xuat();
	}
	cout<<endl;
	
	int m;
	cout<<"\nNhap so luong HOC SINH: ";
	cin>>m;
	HS *hs = new HS[m];
	for(int i = 0; i < m; i++){
		cout<<"\nHOC SINH THU "<<i+1<<": \n";
		hs[i].Nhap();
	}
	cout<<"\nDanh sach cac HOC SINH dat loai gioi la: \n";
	TieuDe2();
	for(int i = 0; i < m; i++){
		if(hs[i].xeploai() == "Gioi"){
			cout<<"\nHOC SINH THU "<<i+1<<": \n";
			hs[i].Xuat();
		}
	}
	return 0;
}