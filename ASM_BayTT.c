#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include <stdlib.h>//Thieu thu vien se bi canh bao ve ham Exit
void nhapSoNguyen(int *n){
	printf("\nMời bạn nhập 1 số nguyên: "); scanf("%d",n);
}
void nhapSoThapPhan(float *x){
	printf("\nMời bạn nhập 1 số thập phân: ");  scanf("%f",x);
}
int laSoNguyen(float x){
	if(x==(int)x) return 1;
	return 0;
}
int laSoNT(float x){//Hàm sẽ trả về giá trị 0 hoặc 1
	if(x<=1) return 0;
	else { //x là số >=2
		int i=2, nt=1;// nt=1, tạm công nhận x là số nguyên tố
		while(i<x){
			if((int)x%i==0){ //x chia hết cho i nên x không còn là số NT nữa
				nt=0; 
				break; //thoát ra khỏi cấu trúc while
			}
			i++;
		}
		return nt;
	}
}
int laSoCP(float x){
	if(sqrt(x)==(int)sqrt(x)) return 1;
	return 0;
}
int UCLN(int a, int b){
	if (a<0||b<0||(a==0 && b==0)) return 0;
	//return 0 có nghĩa là không có UCLN
	if(a==0||b==0) return a+b;
	else{
		while(a!=b){
			if(a>b) a=a-b;//a-=b;
			else b=b-a; //b-=a;
		}
		return a;//UCLN=b; vi a=b
	}
}
int BCNN(int a, int b){
	if (UCLN(a,b)!=0) return a*b/UCLN(a,b);
}
int main(){
	int luachon; 
	do{
		printf("______________________________________\n");
		printf("|WELCOME TO BAYTT'S ASSIGNMENT COM108|\n");
		printf("________________MENU________________\n");
		printf("1. Chức năng tìm tính nguyên của một số\n");
		printf("2. Chức năng tìm UCLN và BCNN\n");
		printf("3. Chức năng tính tiền quán Karaoke\n");
		printf("4. Chức năng tính tiền điện\n");
		printf("6. Chức năng vay tiền ngân hàng\n");
		printf("8. Coming soon...\n");
		printf("0. Exit\n");
		nhapSoNguyen(&luachon);
		switch(luachon){
			case 1:{
				float x;
				nhapSoThapPhan(&x);
				if(laSoNguyen(x)==1){
					printf("\n%.0f là số nguyên\n",x);
					if (laSoNT(x)) 
						printf("\n%.0f là số Nguyên tố\n",x);
					else {
						printf("\n%.0f KHÔNG là số Nguyên tố\n",x);
						if(laSoCP(x)==1) printf("\n%.0f là số Chính phương\n",x);
						else printf("\n%.0f KHÔNG là số Chính phương\n",x);
					}
				}else printf("\n%.2f là số thập phân\n",x);
				break; //Ket thuc chuc nang 1, thoát ra khỏi cấu trúc switch
			}case 2:{
				int a, b;
				do{
					nhapSoNguyen(&a);
					nhapSoNguyen(&b);
					//if(a<0||b<0||(a==0&&b==0)) printf("\nMoi ban nhap lai");
				}while(a<0||b<0||(a==0&&b==0));
				printf("\nUCLN(%d,%d)= %d\n", a, b, UCLN(a,b));
				printf("\nBCNN(%d,%d)= %d\n", a, b, BCNN(a,b));
				break; //Ket thuc chuc nang 2
			}case 3:{
				int giovao, giora, tg, tien;
				printf("\nMoi ban nhap gio vao hat: "); scanf("%d",&giovao);
				printf("\nMoi ban nhap gio ra: "); scanf("%d",&giora);
				if(giovao<12||giovao>=23||giora<=12||giora>23||giora<=giovao)
					printf("\nBan nhap sai roi!\n");
				else {
					tg=giora-giovao;
					if(tg<=3) tien=150000;//Du ban hat may tieng tui cung tinh 150k
					else tien=150000+(tg-3)*50000*0.7; //giam 30% la khuyen mai 1
					if(giovao>=12 && giovao<=17) //giam 10%  trong gio thap diem la khuyen mai 2
						tien*=0.9; //tien=tien*0.9;
				}
				printf("\nBan hat %d gio, tien= %d\n",tg,tien); 
				break;
				//Ket thuc chuc nang 3
			}case 4:{
				int kwh, tien;
				int b1=1678, b2=1734,b3=2014,b4=2536,b5=2834,b6=2927;
				do{
					printf("\nMoi ban nhap so kwh: "); scanf("%d",&kwh);
				}while(kwh<0);
				if(kwh<=50) { //dien bac 1
					tien=kwh*b1;
					printf("\nGD ban su dung dien B1, so tien= %d\n",tien);					
				}else if(kwh<=100){ //dien bac 2
						tien=50*b1+(kwh-50)*b2;
						printf("\nGD ban su dung dien B2, so tien= %d\n",tien);
					  }else if(kwh<=200){ //dien bac 3
							  	tien=50*b1+50*b2+(kwh-100)*b3;
								printf("\nGD ban su dung dien B3, so tien= %d\n",tien);
					  	    }else if(kwh<=300){ //dien bac 4
						  	    	tien=50*b1+50*b2+100*b3+(kwh-200)*b4;
									printf("\nGD ban su dung dien B4, so tien= %d\n",tien);
							      }else if(kwh<=400){ //dien bac 5
									      	tien=50*b1+50*b2+100*b3+100*b4+(kwh-300)*b5;
											printf("\nGD ban su dung dien B5, so tien= %d\n",tien);
								  		}else { //Dien bac 6
								  				tien=50*b1+50*b2+100*b3+100*b4+100*b5+(kwh-400)*b6;
												printf("\nGD ban su dung dien B6, so tien= %d\n",tien);
										  	}
				break; //Ket thuc chuc nang 4
			}case 6:{//Lai suat co dinh 5%, thoi gian tra no la 12 thang
				printf("Ban vua chon CN6: Vay ngan hang\n");
				int i, tienVay, laiPhaiTra, tienGocTraHangThang, soTienPhaiTra;
				do{
					printf("Moi ban nhap so tien vay: "); scanf("%d",&tienVay);
				}while(tienVay<=0);
				tienGocTraHangThang=tienVay/12;
				printf("Ky han   |");//9 cell
				printf("Lai phai tra   |");//15cell
				printf("Goc phai tra   |");//15cell
				printf("So tien phai tra   |");//19cell
				printf("So tien con lai   |");//18cell
				printf("\n");
				for(i=1; i<=12; i++){
					printf("%6d|", i);
					laiPhaiTra=tienVay*0.05;//laiThang=tienVay*5%
					printf("%15d|", laiPhaiTra);
					printf("%15d|",tienGocTraHangThang);
					soTienPhaiTra=laiPhaiTra+tienGocTraHangThang;
					printf("%19d|",soTienPhaiTra);
					tienVay=tienVay-tienGocTraHangThang;
					printf("%18d|",tienVay);
					printf("\n");
					printf("________________________________________________________________________________\n");
				}
				break; //Ket thuc chuc nang 6
			}case 8:{
				//add 8.2 vào đây
				break; //Ket thuc chuc nang 8
			}case 0:{ //Ket thuc 
				return 0;
			}default: printf("\nYou chose wrong\n"); break;  
		}
		printf("\nPress any number: Come back Menu/Press 0 to Exit: ");	scanf("%d",&luachon);
		if(luachon==0){
			printf("\nSee you again!"); 
			goto ketthuc;
		}
	}while(luachon!=0);
	ketthuc: return 0;
}