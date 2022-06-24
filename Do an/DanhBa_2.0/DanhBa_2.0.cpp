// Nam mô a di đà phật

#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#define MAX 100
using namespace std;

struct DanhBa {
    int id;
    char ho[30];
    char ten[30];
    char sdt[30];
    char email[30];
	char diachi[30];
};

typedef DanhBa DB;

// hàm phục vụ chương trình
void func_addLH(DB &db, int id);
void func_editLH(DB &db);
void addLH(DB a[], int id, int n);
void editLH(DB a[], int id, int n);
int delLH(DB a[], int id, int n);
void search(DB a[], char ten[], int n);
void listLH(DB a[], int n);
void listLH_name(DB a[], int n);
int docFile(DB a[], char fileName[]);
void ghiFile(DB a[], int n, char fileName[]);

// hàm tạo form cho chương trình
void refresh();
void taokhuon(int n);
int counter(DB a[], int n);

int main() {
	// khai báo
    DB arrayLH[MAX];
    int select;
    int soluongLH = 0;
	
	// đọc dữ liệu từ file
    char fileName[] = "danhba.db";
    soluongLH = docFile(arrayLH, fileName);
    int idCount = counter(arrayLH, soluongLH);
 
    // Bảng menu chương trình
    while(true) {
        printf("------------ Ung Dung Danh Ba (Ngon Ngu C) ------------\n");
		printf("------------ Coder: doandat943, ngocphuong ------------\n");
        printf("*************************MENU**************************\n");
        printf("**  1. Hien thi danh sach lien he.                   **\n");
        printf("**  2. Them lien he.                                 **\n");
        printf("**  3. Sua thong tin lien he bang ID.                **\n");
        printf("**  4. Xoa lien he bang ID.                          **\n");
        printf("**  5. Tim kiem lien he theo ten.                    **\n");
        printf("**  6. Sap xep lien he theo ten.                     **\n");
        printf("**  7. Ghi danh sach lien he vao file.               **\n");
        printf("**  0. Thoat                                         **\n");
        printf("*******************************************************\n");
        printf("Nhap tuy chon: ");
        scanf("%d",&select);
        switch(select){
            case 1:
            	if(soluongLH > 0){
                    printf("\n1. Hien thi danh sach lien he.");
                    listLH(arrayLH, soluongLH);
                }else{
                    printf("\nDanh ba trong!");
                }
                refresh();
                break;
            case 2:
            	printf("\n2. Them lien he.");
                idCount++;
                addLH(arrayLH, idCount, soluongLH);
                printf("\nThem lien he thanh cong!");
                soluongLH++;
                refresh();
                break;
            case 3:
            	if(soluongLH > 0) {
                    int id;
                    listLH(arrayLH, soluongLH);
                    printf("\n3. Sua thong tin lien he bang ID.\n");
                    printf("\n Nhap ID: "); scanf("%d", &id);
                    editLH(arrayLH, id, soluongLH);
                }else{
                    printf("\nDanh ba trong!");
                }
                refresh();
                break;
            case 4:
                if(soluongLH > 0) {
                    int id;
                    printf("\n4. Xoa lien he bang ID.\n");
                    printf("\n Nhap ID: "); scanf("%d", &id);
                    if (delLH(arrayLH, id, soluongLH) == 1) {
                        printf("\n Lien he co id = %d da bi xoa.", &id);
                        soluongLH--;
                    }
                }else{
                    printf("\nDanh ba trong!");
                }
                refresh();
                break;
            case 5:
                if(soluongLH > 0) {
                    printf("\n5. Tim kiem lien he theo ten.");
                    char strTen[30];
                    printf("\nNhap ten de tim kiem: "); fflush(stdin); gets(strTen);
                    search(arrayLH, strTen, soluongLH);
                }else{
                    printf("\nDanh ba trong!");
                }
                refresh();
                break;
            case 6:
            	if(soluongLH > 0) {
                    printf("\n6. Sap xep lien he theo ten.");
                    listLH_name(arrayLH, soluongLH);
                    listLH(arrayLH, soluongLH);
                } else {
                    printf("\nDanh ba trong!");
                }
                refresh();
                break;
            case 7:
                if(soluongLH > 0){
                    printf("\n7. Ghi danh sach lien he vao file.");
                    ghiFile(arrayLH, soluongLH, fileName);
                }else{
                    printf("\nDanh ba trong!");
                }
                printf("\nGhi danh sach lien he vao file %s thanh cong!", fileName);
                refresh();
                break;
            case 0:
            	int luu;
            	taokhuon(35);
                printf("\n  Ban co muon luu du lieu khong?");
                printf("\n  -  1. Luu du dieu.");
                printf("\n  -  2. Khong luu du lieu.");
                taokhuon(35);
                printf("\n  Nhap tuy chon: ");
                scanf("%d",&luu);
                switch(luu){
                        case 1:
                       	    ghiFile(arrayLH, soluongLH, fileName);
                       	    usleep(1000*1000);
                            printf("\n  Ghi danh sach lien he vao file %s thanh cong!", fileName);
                            break;
                        case 2:
                        	printf("\n  Du lieu chua duoc luu!");
                        	break;
                }
                usleep(1000*500);
                printf("\n\n  --- Cam on ban da su dung ung dung cua chung toi ---\n");
                usleep(1000*500);
                printf("\n  --- Bam phim bat ky de thoat ---\n");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nVui long chon chuc nang co trong hop menu.");
                refresh();
                break;
        }
    }
}

void func_addLH(DB &db, int id) {
    printf("\n Nhap ho: "); fflush(stdin); gets(db.ho);
    printf(" Nhap ten: "); gets(db.ten);
    printf(" Nhap sdt: "); gets(db.sdt);
	printf(" Nhap email: "); gets(db.email);
	printf(" Nhap dia chi: "); gets(db.diachi);
    db.id = id;
}

void func_editLH(DB &db) {
    printf("\n Nhap ho: "); fflush(stdin); gets(db.ho);
    printf(" Nhap ten: "); gets(db.ten);
    printf(" Nhap sdt: "); gets(db.sdt);
	printf(" Nhap email: "); gets(db.email);
	printf(" Nhap dia chi: "); gets(db.diachi);
}

void addLH(DB a[], int id, int n) {
    taokhuon(40);
    printf("\n Nhap lien he thu %d:", n + 1);
    func_addLH(a[n], id);
    taokhuon(40);
}

void editLH(DB a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            taokhuon(40);
            printf("\n Cap nhat thong tin lien he co ID = %d", id);
            func_editLH(a[i]);
            taokhuon(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Lien he co ID = %d khong ton tai.", id);
    }
}

int delLH(DB a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            taokhuon(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            printf("\n Da xoa SV co ID = %d", id);
            taokhuon(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n Lien he co ID = %d khong ton tai.", id);
        return 0;
   } else {
        return 1;
    }
}

void search(DB a[], char ten[], int n) {
    DB arrayFound[MAX];
    char tenSV[30];
    int found = 0;
    for(int i = 0; i < n; i++) {
        strcpy(tenSV, a[i].ten);
        if(strstr(strupr(tenSV), strupr(ten))) {
            arrayFound[found] = a[i];
            found++;
        }
    }
    listLH(arrayFound, found);
}

void listLH(DB a[], int n) {
    taokhuon(90);
    printf("\nSTT\tID\tHo\tTen\tSo dien thoai\tEmail\t\t\tDia chi");
    for(int i = 0; i < n; i++) {
        printf("\n%d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ho);
        printf("\t%s", a[i].ten);
        printf("\t%s", a[i].sdt);
		printf("\t%s", a[i].email);
		printf("\t%s", a[i].diachi);
    }
    taokhuon(90);
}

void listLH_name(DB a[], int n) {
    DB tmp;
    char tenSV1[30];
    char tenSV2[30];
    for(int i = 0;i < n; i++) {
    	strcpy(tenSV1, a[i].ten);
        for(int j = i+1; j < n; j++) {
        	strcpy(tenSV2, a[j].ten);
            if(strcmp(strupr(tenSV1), strupr(tenSV2)) > 0) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

int counter (DB a[], int n) {
    int idMax = 0;
    if (n > 0) {
        idMax = a[0].id;
        for(int i = 0;i < n; i++) {
            if (a[i].id > idMax) {
                idMax = a[i].id;
            }
        }
    }
    return idMax;
}
// %5d%30s%30s%30s%30s%30s\n
int docFile(DB a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    printf("       -        Bat dau xu ly du lieu         -\n");
    usleep(1000*1000);
    printf("            Dang quet du lieu tu: "); puts(fileName);
    usleep(1000*1000);
    printf("       ----------------------------------------\n");
    while (fscanf(fp, "%d%s%s%s%s%s\n", &a[i].id, &a[i].ho, &a[i].ten, &a[i].sdt, &a[i].email, &a[i].diachi) != EOF) {
       i++;
       printf("       -        Da quet thay %d lien he        -\n", i);
       usleep(1000*500);
    }
    printf("       ----------------------------------------\n        So lien he co san trong database la:  %d \n\n", i);
    fclose (fp);
    usleep(1000*500);
    printf(" ");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("B");
    usleep(1000*50);
    printf("a");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("d");
    usleep(1000*50);
    printf("a");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf("g");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("s");
    usleep(1000*50);
    printf("u");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("d");
    usleep(1000*50);
    printf("u");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf("g");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("u");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf("g");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("d");
    usleep(1000*50);
    printf("u");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf("g");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("D");
    usleep(1000*50);
    printf("A");
    usleep(1000*50);
    printf("N");
    usleep(1000*50);
    printf("H");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("B");
    usleep(1000*50);
    printf("A");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("d");
    usleep(1000*50);
    printf("u");
    usleep(1000*50);
    printf("o");
    usleep(1000*50);
    printf("c");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("l");
    usleep(1000*50);
    printf("a");
    usleep(1000*50);
    printf("p");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("t");
    usleep(1000*50);
    printf("r");
    usleep(1000*50);
    printf("i");
    usleep(1000*50);
    printf("n");
    usleep(1000*50);
    printf("h\n            ");
    usleep(1000*200);
    printf("b");
    usleep(1000*50);
    printf("o");
    usleep(1000*50);
    printf("i");
    usleep(1000*50);
    printf(" ");
    usleep(1000*50);
    printf("\"");
    usleep(1000*50);
    printf("Doan Dat va Ngoc Phuong\"\n\n");
    usleep(1000*1000);
    return i;
}

void ghiFile(DB a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%d %s %s %s %s %s\n", a[i].id, a[i].ho,a[i].ten, a[i].sdt, a[i].email, a[i].diachi);
    }
    fclose (fp);
}

void taokhuon(int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("_");
    }
    printf("\n");
}

void refresh() {
    printf("\n\nBam phim bat ky de tiep tuc...");
    getch();
    system("cls");
}
