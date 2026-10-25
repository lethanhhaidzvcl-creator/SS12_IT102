
#include <stdio.h>
#include <string.h>

#define MAX_NHAN_VIEN 100

typedef struct {
    int maNV;
    char hoTen[50];
    float luongCoBan;
    int phutMuon;
    float soGioOT;
} NhanVien;

/* Khai bao nguyen mau ham */
void hienThiMenu(void);
int timKiemTheoMa(NhanVien ds[], int soLuong, int maNV);
void hienThiDanhSach(NhanVien ds[], int soLuong);
int themNhanVien(NhanVien ds[], int soLuong);
void suaNhanVien(NhanVien ds[], int soLuong);
int xoaNhanVien(NhanVien ds[], int soLuong);

/* Xoa cac ky tu con lai trong bo dem */
void xoaBoDem(void) {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

/* Hien thi menu */
void hienThiMenu(void) {
    printf("\n===== HE THONG QUAN LY NHAN SU HRM =====\n");
    printf("1. Xem danh sach nhan vien va bang luong\n");
    printf("2. Them nhan vien moi\n");
    printf("3. Cap nhat thong tin nhan vien\n");
    printf("4. Xoa nhan vien\n");
    printf("0. Thoat chuong trinh\n");
    printf("========================================\n");
}

/* Tim nhan vien theo ma */
int timKiemTheoMa(NhanVien ds[], int soLuong, int maNV) {
    int i;

    for (i = 0; i < soLuong; i++) {
        if (ds[i].maNV == maNV) {
            return i;
        }
    }

    return -1;
}

/* Hien thi danh sach va bang luong */
void hienThiDanhSach(NhanVien ds[], int soLuong) {
    int i;
    float tienPhat;
    float tienOT;
    float luongThucNhan;

    if (soLuong == 0) {
        printf("\nDanh sach nhan vien dang rong!\n");
        return;
    }

    printf("\n========== DANH SACH NHAN VIEN ==========\n");

    for (i = 0; i < soLuong; i++) {
        tienPhat = (ds[i].phutMuon > 15) ? 50000 : 0;

        tienOT = ds[i].soGioOT
                 * (ds[i].luongCoBan / 160.0)
                 * 1.5;

        luongThucNhan = ds[i].luongCoBan
                        + tienOT - tienPhat;

        printf("\nMa NV: %d\n", ds[i].maNV);
        printf("Ho ten: %s\n", ds[i].hoTen);
        printf("Luong co ban: %.0f VND\n", ds[i].luongCoBan);
        printf("Phut muon: %d\n", ds[i].phutMuon);
        printf("Gio OT: %.2f\n", ds[i].soGioOT);
        printf("Tien phat: %.0f VND\n", tienPhat);
        printf("Tien OT: %.0f VND\n", tienOT);
        printf("Luong thuc nhan: %.0f VND\n", luongThucNhan);
    }

    printf("\nTong so nhan vien: %d\n", soLuong);
}

/* Them nhan vien */
int themNhanVien(NhanVien ds[], int soLuong) {
    NhanVien nv;
    int viTri;

    if (soLuong >= MAX_NHAN_VIEN) {
        printf("\nDanh sach da day!\n");
        return soLuong;
    }

    printf("\n--- THEM NHAN VIEN ---\n");

    printf("Ma NV: ");
    if (scanf("%d", &nv.maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    xoaBoDem();

    if (nv.maNV <= 0) {
        printf("Ma nhan vien phai la so nguyen duong!\n");
        return soLuong;
    }

    viTri = timKiemTheoMa(ds, soLuong, nv.maNV);

    if (viTri != -1) {
        printf("Loi: Ma nhan vien da ton tai!\n");
        return soLuong;
    }

    printf("Ho ten: ");
    if (fgets(nv.hoTen, sizeof(nv.hoTen), stdin) == NULL) {
        printf("Khong doc duoc ho ten!\n");
        return soLuong;
    }

    if (strchr(nv.hoTen, '\n') == NULL) {
        xoaBoDem();
    } else {
        nv.hoTen[strcspn(nv.hoTen, "\n")] = '\0';
    }

    if (strlen(nv.hoTen) == 0) {
        printf("Ho ten khong duoc de trong!\n");
        return soLuong;
    }

    printf("Luong co ban: ");
    if (scanf("%f", &nv.luongCoBan) != 1) {
        printf("Luong khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    printf("Phut di muon: ");
    if (scanf("%d", &nv.phutMuon) != 1) {
        printf("So phut muon khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    printf("So gio OT: ");
    if (scanf("%f", &nv.soGioOT) != 1) {
        printf("So gio OT khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    xoaBoDem();

    if (nv.luongCoBan < 0 || nv.phutMuon < 0 || nv.soGioOT < 0) {
        printf("Luong, phut muon va gio OT khong duoc am!\n");
        return soLuong;
    }

    ds[soLuong] = nv;
    soLuong++;

    printf("Them nhan vien thanh cong!\n");

    return soLuong;
}

/* Sua thong tin nhan vien */
void suaNhanVien(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    float luongMoi;
    int phutMuonMoi;
    float gioOTMoi;

    if (soLuong == 0) {
        printf("\nDanh sach nhan vien dang rong!\n");
        return;
    }

    printf("\n--- CAP NHAT NHAN VIEN ---\n");
    printf("Nhap ma NV can sua: ");

    if (scanf("%d", &maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return;
    }

    xoaBoDem();

    viTri = timKiemTheoMa(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return;
    }

    printf("Luong co ban moi: ");
    if (scanf("%f", &luongMoi) != 1) {
        printf("Luong khong hop le!\n");
        xoaBoDem();
        return;
    }

    printf("So phut di muon moi: ");
    if (scanf("%d", &phutMuonMoi) != 1) {
        printf("So phut muon khong hop le!\n");
        xoaBoDem();
        return;
    }

    printf("So gio OT moi: ");
    if (scanf("%f", &gioOTMoi) != 1) {
        printf("So gio OT khong hop le!\n");
        xoaBoDem();
        return;
    }

    xoaBoDem();

    if (luongMoi < 0 || phutMuonMoi < 0 || gioOTMoi < 0) {
        printf("Thong tin khong duoc la so am!\n");
        return;
    }

    ds[viTri].luongCoBan = luongMoi;
    ds[viTri].phutMuon = phutMuonMoi;
    ds[viTri].soGioOT = gioOTMoi;

    printf("Cap nhat nhan vien thanh cong!\n");
}

/* Xoa nhan vien */
int xoaNhanVien(NhanVien ds[], int soLuong) {
    int maNV;
    int viTri;
    int i;

    if (soLuong == 0) {
        printf("\nDanh sach nhan vien dang rong!\n");
        return soLuong;
    }

    printf("\n--- XOA NHAN VIEN ---\n");
    printf("Ma NV can xoa: ");

    if (scanf("%d", &maNV) != 1) {
        printf("Ma nhan vien khong hop le!\n");
        xoaBoDem();
        return soLuong;
    }

    xoaBoDem();

    viTri = timKiemTheoMa(ds, soLuong, maNV);

    if (viTri == -1) {
        printf("Khong tim thay nhan vien!\n");
        return soLuong;
    }

    for (i = viTri; i < soLuong - 1; i++) {
        ds[i] = ds[i + 1];
    }

    soLuong--;

    printf("Xoa nhan vien thanh cong!\n");

    return soLuong;
}

/* Ham main */
int main(void) {
    NhanVien ds[MAX_NHAN_VIEN];
    int soLuong = 0;
    int luaChon;

    do {
        hienThiMenu();
        printf("Nhap lua chon: ");

        if (scanf("%d", &luaChon) != 1) {
            printf("Lua chon khong hop le!\n");
            xoaBoDem();
            luaChon = -1;
            continue;
        }

        xoaBoDem();

        switch (luaChon) {
            case 1:
                hienThiDanhSach(ds, soLuong);
                break;

            case 2:
                soLuong = themNhanVien(ds, soLuong);
                break;

            case 3:
                suaNhanVien(ds, soLuong);
                break;

            case 4:
                soLuong = xoaNhanVien(ds, soLuong);
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
