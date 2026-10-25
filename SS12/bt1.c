
#include <stdio.h>
#include <string.h>

#define MAX_NV 50

// Cau truc nhan vien
typedef struct {
    int maNV;
    char hoTen[50];
    int soPhutDiMuon;
    float luongCoBan;
} NhanVien;

// Khai bao cac ham
int timTheoMaNV(NhanVien danhSach[], int soLuong, int maNV);
int themNhanVien(NhanVien danhSach[], int soLuong);
void hienThiDanhSach(NhanVien danhSach[], int soLuong);
void capNhatPhutDiMuon(NhanVien danhSach[], int soLuong);
void timKiemNhanVien(NhanVien danhSach[], int soLuong);

// Xoa cac ky tu con lai trong bo dem
void xoaBoDem(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

// Tim nhan vien theo ma
int timTheoMaNV(NhanVien danhSach[], int soLuong, int maNV) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (danhSach[i].maNV == maNV) {
            return i;
        }
    }

    return -1;
}

// Them nhan vien moi
int themNhanVien(NhanVien danhSach[], int soLuong) {
    NhanVien nv;

    if (soLuong >= MAX_NV) {
        printf("Danh sach da day!\n");
        return soLuong;
    }

    printf("Nhap ma nhan vien: ");

    if (scanf("%d", &nv.maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    if (timTheoMaNV(danhSach, soLuong, nv.maNV) != -1) {
        printf("Ma nhan vien da ton tai!\n");
        xoaBoDem();
        return soLuong;
    }

    xoaBoDem();

    printf("Nhap ho ten: ");
    if (fgets(nv.hoTen, sizeof(nv.hoTen), stdin) == NULL) {
        printf("Khong doc duoc ho ten!\n");
        return soLuong;
    }

    nv.hoTen[strcspn(nv.hoTen, "\n")] = '\0';

    if (strlen(nv.hoTen) == 0) {
        printf("Ho ten khong duoc de trong!\n");
        return soLuong;
    }

    printf("Nhap so phut di muon: ");

    if (scanf("%d", &nv.soPhutDiMuon) != 1) {
        printf("So phut khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    if (nv.soPhutDiMuon < 0) {
        printf("So phut di muon khong duoc am!\n");
        xoaBoDem();
        return soLuong;
    }

    printf("Nhap luong co ban: ");

    if (scanf("%f", &nv.luongCoBan) != 1) {
        printf("Luong khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    if (nv.luongCoBan < 0) {
        printf("Luong co ban khong duoc am!\n");
        xoaBoDem();
        return soLuong;
    }

    xoaBoDem();

    danhSach[soLuong] = nv;

    printf("Them nhan vien thanh cong!\n");

    return soLuong + 1;
}

// Hien thi danh sach va tinh luong
void hienThiDanhSach(NhanVien danhSach[], int soLuong) {
    int i;
    int tienPhat;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    printf("\n--- DANH SACH NHAN VIEN ---\n");
    printf("%-8s %-25s %-12s %-15s %-15s\n",
           "Ma NV", "Ho ten", "Phut muon",
           "Luong co ban", "Luong thuc nhan");

    for (i = 0; i < soLuong; i++) {
        if (danhSach[i].soPhutDiMuon > 15) {
            tienPhat = 50000;
        } else {
            tienPhat = 0;
        }

        luongThucNhan = danhSach[i].luongCoBan - tienPhat;

        printf("%-8d %-25s %-12d %-15.0f %-15.0f\n",
               danhSach[i].maNV,
               danhSach[i].hoTen,
               danhSach[i].soPhutDiMuon,
               danhSach[i].luongCoBan,
               luongThucNhan);
    }
}

// Cap nhat so phut di muon
void capNhatPhutDiMuon(NhanVien danhSach[], int soLuong) {
    int maNV;
    int viTri;
    int soPhutMoi;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    printf("Nhap ma NV can cap nhat: ");

    if (scanf("%d", &maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return;
    }

    viTri = timTheoMaNV(danhSach, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        xoaBoDem();
        return;
    }

    printf("Nhap so phut di muon moi: ");

    if (scanf("%d", &soPhutMoi) != 1) {
        printf("So phut khong hop le!\n");
        xoaBoDem();
        return;
    }

    if (soPhutMoi < 0) {
        printf("So phut di muon khong duoc am!\n");
        xoaBoDem();
        return;
    }

    xoaBoDem();

    danhSach[viTri].soPhutDiMuon = soPhutMoi;

    printf("Cap nhat thanh cong!\n");
}

// Tim kiem va hien thi nhan vien
void timKiemNhanVien(NhanVien danhSach[], int soLuong) {
    int maNV;
    int viTri;
    int tienPhat;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("Danh sach nhan vien dang rong!\n");
        return;
    }

    printf("Nhap ma NV can tim: ");

    if (scanf("%d", &maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return;
    }

    xoaBoDem();

    viTri = timTheoMaNV(danhSach, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    if (danhSach[viTri].soPhutDiMuon > 15) {
        tienPhat = 50000;
    } else {
        tienPhat = 0;
    }

    luongThucNhan = danhSach[viTri].luongCoBan - tienPhat;

    printf("\n--- THONG TIN NHAN VIEN ---\n");
    printf("Ma NV: %d\n", danhSach[viTri].maNV);
    printf("Ho ten: %s\n", danhSach[viTri].hoTen);
    printf("So phut di muon: %d\n",
           danhSach[viTri].soPhutDiMuon);
    printf("Luong co ban: %.0f VND\n",
           danhSach[viTri].luongCoBan);
    printf("Tien phat: %d VND\n", tienPhat);
    printf("Luong thuc nhan: %.0f VND\n", luongThucNhan);
}

int main(void) {
    NhanVien danhSach[MAX_NV];
    int soLuong = 0;
    int luaChon;

    do {
        printf("\n===== HE THONG QUAN LY CHAM CONG HRM =====\n");
        printf("1. Them nhan vien moi\n");
        printf("2. Hien thi danh sach va tinh luong\n");
        printf("3. Cap nhat so phut di muon\n");
        printf("4. Tim kiem nhan vien theo ma\n");
        printf("0. Thoat\n");
        printf("==========================================\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Vui long nhap lua chon bang so!\n");
            xoaBoDem();
            luaChon = -1;
            continue;
        }

        xoaBoDem();

        switch (luaChon) {
            case 1:
                soLuong = themNhanVien(danhSach, soLuong);
                break;

            case 2:
                hienThiDanhSach(danhSach, soLuong);
                break;

            case 3:
                capNhatPhutDiMuon(danhSach, soLuong);
                break;

            case 4:
                timKiemNhanVien(danhSach, soLuong);
                break;

            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}