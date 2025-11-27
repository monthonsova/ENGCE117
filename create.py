import os

# จำนวน Lab ของแต่ละสัปดาห์ตาม HTML
lab_counts = {
    1: 6,
    2: 4,
    3: 5,
    4: 6,
    5: 2,
    6: 1,
    7: 1,
    8: 1,   # lab 8.0
    9: 1,
    10: 2,
    11: 2,
    12: 2,
    13: 1,
    14: 1,
    15: 1,
    16: 1,  # lab 16.0
    17: 1   # lab 17.0
}

BASE = "ENGCE117"
os.makedirs(BASE, exist_ok=True)

for week in range(1, 18):
    week_folder = os.path.join(BASE, f"Week{week}")
    os.makedirs(week_folder, exist_ok=True)

    labs = lab_counts[week]

    for lab in range(1, labs + 1):
        filepath = os.path.join(week_folder, f"lab{week}_{lab}.c")

        # สร้างเฉพาะถ้ายังไม่มีไฟล์
        if not os.path.exists(filepath):
            with open(filepath, "w", encoding="utf-8") as f:
                f.write("")   # ไฟล์ .c ว่างตามที่ต้องการ

        print(f"✔ Created: {filepath}")

print("\n🎉 สร้างโครงสร้างไฟล์ ENGCE117 ครบแล้ว!")
