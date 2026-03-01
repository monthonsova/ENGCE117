#include <stdio.h>

// ประกาศฟังก์ชัน Knapsack แบบ Backtracking
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x);

int main() {
    // กำหนดจำนวนสิ่งของและความจุกระเป๋า
    int n = 5, wx = 11;
    
    // กำหนดน้ำหนัก (w) และมูลค่า (v) ของสิ่งของ
    int w[5] = { 1, 2, 5, 6, 7 };
    int v[5] = { 1, 6, 18, 22, 28 };
    
    int *x, vx;
    x = new int[n]; // จองหน่วยความจำสำหรับเก็บผลลัพธ์การเลือกสิ่งของ
    
    // เรียกใช้ฟังก์ชันเพื่อหามูลค่าสูงสุด
    vx = KnapsackBT(w, v, n, wx, 0, x);
    
    // แสดงผลลัพธ์มูลค่าที่ได้ และสถานะการเลือกสิ่งของแต่ละชิ้น (ใส่ \n ให้ตรงตาม Test Case)
    printf("Value = %d\n", vx);
    for(int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    
    return 0;
}

// ฟังก์ชันหารูปแบบการเลือกสิ่งของที่ให้มูลค่าสูงสุดด้วยการย้อนรอย (Backtracking)
int KnapsackBT(int *w, int *v, int n, int wx, int i, int *x) {
    // ถ้าพิจารณาสิ่งของครบทุกชิ้นแล้ว ให้สิ้นสุดการทำงานสาขานี้และคืนค่า 0
    if (i == n) {
        return 0;
    }

    // สร้างอาเรย์จำลองเพื่อเก็บสถานะการเลือกของแต่ละทางเลือก
    int *x_exclude = new int[n];
    int *x_include = new int[n];

    for (int j = 0; j < n; j++) {
        x_exclude[j] = 0;
        x_include[j] = 0;
    }

    // ทางเลือกที่ 1: ไม่เลือกสิ่งของชิ้นที่ i
    int val_exclude = KnapsackBT(w, v, n, wx, i + 1, x_exclude);

    // ทางเลือกที่ 2: เลือกสิ่งของชิ้นที่ i (ต้องเช็คก่อนว่าน้ำหนักไม่เกินกระเป๋า)
    int val_include = 0;
    if (wx >= w[i]) {
        val_include = v[i] + KnapsackBT(w, v, n, wx - w[i], i + 1, x_include);
    }

    int max_val = 0;

    // เปรียบเทียบว่าทางเลือกไหนให้มูลค่ารวมมากกว่ากัน
    if (val_include > val_exclude) {
        max_val = val_include;
        // คัดลอกการเลือกของทางเลือกที่ 2 ลงในอาเรย์หลัก
        for (int j = i + 1; j < n; j++) {
            x[j] = x_include[j];
        }
        x[i] = 1; // บันทึกว่าชิ้นปัจจุบันนี้ถูกเลือก
    } else {
        max_val = val_exclude;
        // คัดลอกการไม่เลือกของทางเลือกที่ 1 ลงในอาเรย์หลัก
        for (int j = i + 1; j < n; j++) {
            x[j] = x_exclude[j];
        }
        x[i] = 0; // บันทึกว่าชิ้นปัจจุบันนี้ไม่ถูกเลือก
    }

    // คืนหน่วยความจำเพื่อป้องกัน memory leak (ขยะตกค้างในระบบ)
    delete[] x_exclude;
    delete[] x_include;

    // ส่งคืนมูลค่าที่มากที่สุดที่หาได้ในจุดนี้
    return max_val;
}