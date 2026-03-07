# generate_taylor_lut.py
with open("taylor_lut.mem", "w") as f:
    for i in range(4096):
        # 上位12ビットの値
        x_base = 1.0 + i * (2 ** -12)
        
        # y0 = 1 / x_base
        y0 = 1.0 / x_base
        y0_int = int(y0 * (2 ** 23) + 0.5)
        
        # dy = 1 / (x_base ** 2)
        dy = 1.0 / (x_base ** 2)
        dy_int = int(dy * (2 ** 23) + 0.5)
        
        # 24bitの範囲に収めるクリッピング（1.0のとき対策）
        if y0_int > 0x800000: y0_int = 0x800000
        if dy_int > 0x800000: dy_int = 0x800000
        
        # 上位24bitに y0、下位24bitに dy を結合して16進数で出力
        val_48 = (y0_int << 24) | dy_int
        f.write(f"{val_48:012x}\n")

print("taylor_lut.mem generated successfully.")
