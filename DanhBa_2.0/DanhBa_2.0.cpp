#include<conio.h>
#include<stdio.h>
#include <iostream>
#include <string.h>
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

void func_addLH(DB &db, int id);
void addLH(DB a[], int id, int n);
void func_editLH(DB &db);
void editLH(DB a[], int id, int n);
int delLH(DB a[], int id, int n);
void search(DB a[], char ten[], int n);
int counter(DB a[], int n);
void sortbyname(DB a[], int n);
void listLH(DB a[], int n);
int docFile(DB a[], char fileName[]);
void ghiFile(DB a[], int n, char fileName[]);
void refresh();
void ngatdong(int n);

int main() {
    int key;
    char fileName[] = "danhba.db";
    DB arrayLH[MAX];
    int soluongLH = 0;
    int idCount = 0;
    
    soluongLH = docFile(arrayLH, fileName);
    idCount = counter (arrayLH, soluongLH);

    while(true) {
        cout << "------------ Ung Dung Danh Ba (Ngon Ngu C) ------------\n";
        cout << "*************************MENU**************************\n";
        cout << "**  1. Hien thi danh sach lien he.                   **\n";
        cout << "**  2. Them lien he.                                 **\n";
        cout << "**  3. Sua thong tin lien he bang ID.                **\n";
        cout << "**  4. Xoa lien he bang ID.                          **\n";
        cout << "**  5. Tim kiem lien he theo ten.                    **\n";
        cout << "**  6. Sap xep lien he theo ten.                     **\n";
        cout << "**  7. Ghi danh sach lien he vao file.               **\n";
        cout << "**  0. Thoat                                         **\n";
        cout << "*******************************************************\n";
        cout << "Nhap tuy chon: ";
        cin >> key;
        switch(key){
            case 1:
            	if(soluongLH > 0){
                    cout << "\n1. Hien thi danh sach lien he.";
                    listLH(arrayLH, soluongLH);
                }else{
                    cout << "\nDanh ba trong!";
                }
                refresh();
                break;
            case 2:
            	cout << "\n2. Them lien he.";
                idCount++;
                addLH(arrayLH, idCount, soluongLH);
                printf("\nThem lien he thanh cong!");
                soluongLH++;
                refresh();
                break;
            case 3:
            	if(soluongLH > 0) {
                    int id;
                    cout << "\n3. Sua thong tin lien he bang ID.";
                    cout << "\n Nhap ID: "; cin >> id;
                    editLH(arrayLH, id, soluongLH);
                }else{
                    cout << "\nDanh ba trong!";
                }
                refresh();
                break;
            case 4:
                if(soluongLH > 0) {
                    int id;
                    cout << "\n4. Xoa lien he bang ID.";
                    cout << "\n Nhap ID: "; cin >> id;
                    if (delLH(arrayLH, id, soluongLH) == 1) {
                        printf("\nlien he co id = %d da bi xoa.", &id);
                        soluongLH--;
                    }
                }else{
                    cout << "\nDanh ba trong!";
                }
                refresh();
                break;
            case 5:
                if(soluongLH > 0) {
                    cout << "\n5. Tim kiem lien he theo ten.";
                    char strTen[30];
                    cout << "\nNhap ten de tim kiem: "; fflush(stdin); gets(strTen);
                    search(arrayLH, strTen, soluongLH);
                }else{
                    cout << "\nDanh ba trong!";
                }
                refresh();
                break;
            case 6:
            	if(soluongLH > 0) {
                    cout << "\n6. Sap xep lien he theo ten.";
                    sortbyname(arrayLH, soluongLH);
                    listLH(arrayLH, soluongLH);
                } else {
                    cout << "\nDanh ba trong!";
                }
                refresh();
                break;
            case 7:
                if(soluongLH > 0){
                    cout << "\n7. Ghi danh sach lien he vao file.";
                    ghiFile(arrayLH, soluongLH, fileName);
                }else{
                    cout << "\nDanh ba trong!";
                }
                printf("\nGhi danh sach lien he vao file %s thanh cong!", fileName);
                refresh();
                break;
            case 0:
                cout << "\nBan da chon thoat chuong trinh!";
                getch();
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nVui long chon chuc nang co trong hop menu.";
                refresh();
                break;
        }
    }
}

void func_addLH(DB &db, int id) {
    cout << "\n Nhap ho: "; fflush(stdin); gets(db.ho);
    cout << " Nhap ten: "; gets(db.ten);
    cout << " Nhap sdt: "; gets(db.sdt);
	cout << " Nhap email: "; gets(db.email);
	cout << " Nhap dia chi: "; gets(db.diachi);
    db.id = id;
}

void addLH(DB a[], int id, int n) {
    ngatdong(40);
    printf("\n Nhap lien he thu %d:", n + 1);
    func_addLH(a[n], id);
    ngatdong(40);
}

void func_editLH(DB &db) {
    cout << "\n Nhap ho: "; fflush(stdin); gets(db.ho);
    cout << " Nhap ten: "; gets(db.ten);
    cout << " Nhap sdt: "; gets(db.sdt);
	cout << " Nhap email: "; gets(db.email);
	cout << " Nhap dia chi: "; gets(db.diachi);
}

void editLH(DB a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            ngatdong(40);
            cout << "\n Cap nhat thong tin lien he co ID = " << id;
            func_editLH(a[i]);
            ngatdong(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n lien he co ID = %d khong ton tai.", id);
    }
}

int delLH(DB a[], int id, int n) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if (a[i].id == id) {
            found = 1;
            ngatdong(40);
            for (int j = i; j < n; j++) {
                a[j] = a[j+1];
            }
            cout << "\n Da xoa SV co ID = " << id;
            ngatdong(40);
            break;
        }
    }
    if (found == 0) {
        printf("\n lien he co ID = %d khong ton tai.", id);
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
    ngatdong(110);
    cout << "\nSTT\tID\tHo\tTen\tSo dien thoai\tEmail\t\t\tDia chi";
    for(int i = 0; i < n; i++) {
        printf("\n%d", i + 1);
        printf("\t%d", a[i].id);
        printf("\t%s", a[i].ho);
        printf("\t%s", a[i].ten);
        printf("\t%s", a[i].sdt);
		printf("\t%s", a[i].email);
		printf("\t%s", a[i].diachi);
    }
    ngatdong(110);
}

void sortbyname(DB a[], int n) {
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

int docFile(DB a[], char fileName[]) {
    FILE * fp;
    int i = 0;
    fp = fopen (fileName, "r");
    cout << "            Dang quet du lieu tu: "; puts(fileName);
    cout << "       ----------------------------------------\n";
    while (fscanf(fp, "%5d%30s%30s%30s%30s%30s\n", &a[i].id, &a[i].ho, &a[i].ten, &a[i].sdt, &a[i].email, &a[i].diachi) != EOF) {
       i++;
       cout << "       -        Bat dau xu ly du lieu         -" << endl;
       cout << "       -             Quet du lieu: " << i << "          -" << endl;
    }
    cout << "       ----------------------------------------\n          So lien he co san trong file la: " << i << endl;
    cout << "\n\n";
    cout << endl;
    fclose (fp);
    return i;
}

void ghiFile(DB a[], int n, char fileName[]) {
    FILE * fp;
    fp = fopen (fileName,"w");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%5d%30s%30s%30s%30s%30s\n", a[i].id, a[i].ho,a[i].ten, a[i].sdt, a[i].email, a[i].diachi);
    }
    fclose (fp);
}

void ngatdong(int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << "_";
    }
    cout << endl;
}

void refresh() {
    cout << "\n\nBam phim bat ky de tiep tuc...";
    getch();
    system("cls");
}
